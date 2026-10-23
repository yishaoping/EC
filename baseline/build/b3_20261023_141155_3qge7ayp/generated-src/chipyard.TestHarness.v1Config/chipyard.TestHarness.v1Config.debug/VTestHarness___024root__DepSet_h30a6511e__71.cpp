// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness__Syms.h"
#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12133(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12133\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT___io_deq_valid_output) 
                       & (0x140000U == (0x1c0000U & 
                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((0U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 9U))) 
                            | (1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            >> 9U)))) 
                           | (2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                           >> 9U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:700: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'A' channel Hint carries invalid source ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 700, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:701:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:702: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 702, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT___io_deq_valid_output) 
                       & (0x140000U == (0x1c0000U & 
                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           << 0x17U) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                             >> 9U)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    >> 0xbU)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                          >> 0xbU))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:706: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'A' channel Hint address not aligned to size (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 706, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:707:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:708: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 708, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12134(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12134\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT___io_deq_valid_output) 
                       & (0x140000U == (0x1c0000U & 
                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                     >> 0x10U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:712: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'A' channel Hint carries invalid opcode param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 712, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:713:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:714: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 714, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT___io_deq_valid_output) 
                       & (0x140000U == (0x1c0000U & 
                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                  >> 1U)) != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__mask_acc_5) 
                                                << 7U) 
                                               | (0x3fffff80U 
                                                  & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__mask_eq_5) 
                                                      << 7U) 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                        >> 2U)))) 
                                              | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__mask_acc_5) 
                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__mask_eq_5) 
                                                      & (~ 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                          >> 9U)))) 
                                                  << 6U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__mask_acc_4) 
                                                      << 5U) 
                                                     | (0xfffffe0U 
                                                        & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__mask_eq_4) 
                                                            << 5U) 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                              >> 4U)))) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__mask_acc_4) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__mask_eq_4) 
                                                            & (~ 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                >> 9U)))) 
                                                        << 4U) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__mask_acc_3) 
                                                            << 3U) 
                                                           | (0x3fffff8U 
                                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__mask_eq_3) 
                                                                  << 3U) 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                    >> 6U)))) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__mask_acc_3) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__mask_eq_3) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                      >> 9U)))) 
                                                              << 2U) 
                                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__mask_acc_2) 
                                                                  << 1U) 
                                                                 | (0xfffffeU 
                                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__mask_eq_2) 
                                                                        << 1U) 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                          >> 8U)))) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__mask_acc_2) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__mask_eq_2) 
                                                                      & (~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                          >> 9U))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:718: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'A' channel Hint contains invalid mask (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 718, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:719:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:720: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 720, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12135(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12135\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT___io_deq_valid_output) 
                       & (0x140000U == (0x1c0000U & 
                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:724: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'A' channel Hint is corrupt (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 724, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:725:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:726: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 726, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:730: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel has invalid opcode (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 730, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:731:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:732: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 732, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12136(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12136\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source)) 
                            | (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))) 
                           | (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:736: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel ReleaseAck carries invalid source ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 736, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:737:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:738: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 738, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (3U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:742: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel ReleaseAck smaller than a beat (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 742, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:743:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:744: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 744, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12137(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12137\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:748: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel ReleaseeAck carries invalid param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 748, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:749:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:750: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 750, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:754: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel ReleaseAck is corrupt (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 754, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:755:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:756: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 756, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12138(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12138\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_denied)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:760: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel ReleaseAck is denied (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 760, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:761:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:762: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 762, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source)) 
                            | (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))) 
                           | (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:766: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel Grant carries invalid source ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 766, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:767:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:768: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 768, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12139(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12139\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (3U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:772: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel Grant smaller than a beat (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 772, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:773:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:774: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 774, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:778: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel Grant carries invalid cap param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 778, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:779:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:780: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 780, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12140(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12140\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:784: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel Grant carries toN param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 784, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:785:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:786: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 786, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:790: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel Grant is corrupt (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 790, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:791:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:792: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 792, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12141(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12141\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source)) 
                            | (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))) 
                           | (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:796: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel GrantData carries invalid source ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 796, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:797:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:798: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 798, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (3U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:802: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel GrantData smaller than a beat (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 802, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:803:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:804: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 804, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12142(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12142\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:808: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel GrantData carries invalid cap param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 808, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:809:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:810: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 810, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:814: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel GrantData carries toN param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 814, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:815:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:816: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 816, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12143(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12143\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_denied)) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_corrupt)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:820: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel GrantData is denied but not corrupt (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 820, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:821:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:822: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 822, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source)) 
                            | (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))) 
                           | (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:826: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel AccessAck carries invalid source ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 826, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:827:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:828: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 828, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12144(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12144\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:832: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel AccessAck carries invalid param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 832, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:833:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:834: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 834, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:838: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel AccessAck is corrupt (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 838, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:839:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:840: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 840, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12145(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12145\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source)) 
                            | (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))) 
                           | (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:844: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel AccessAckData carries invalid source ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 844, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:845:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:846: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 846, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:850: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel AccessAckData carries invalid param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 850, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:851:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:852: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 852, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12146(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12146\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_denied)) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_corrupt)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:856: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel AccessAckData is denied but not corrupt (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 856, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:857:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:858: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 858, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source)) 
                            | (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))) 
                           | (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:862: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel HintAck carries invalid source ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 862, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:863:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:864: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 864, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12147(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12147\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:868: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel HintAck carries invalid param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 868, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:869:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:870: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 870, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:874: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel HintAck is corrupt (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 874, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:875:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:876: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 876, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12148(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12148\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceB__DOT__b_valid) 
                       & (0x1cU == (0x3cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source)))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ ((0U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))) 
                           & (((((((((((0U == ((0x7fffcU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                                   >> 0xdU)) 
                                               | (3U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                                     >> 0xcU)))) 
                                       | (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                                 >> 0xcU))) 
                                      | (1U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                                >> 0x10U))) 
                                     | (2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                               >> 0x10U))) 
                                    | (0U == ((0x7fff0U 
                                               & (0x80U 
                                                  ^ 
                                                  (0x7fff0U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                                      >> 0xdU)))) 
                                              | (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                                    >> 0xcU))))) 
                                   | (0x200U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                                 >> 0x10U))) 
                                  | (0x2010U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                                 >> 0xcU))) 
                                 | (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                           >> 0x1aU))) 
                                | (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                                >> 0xcU))) 
                               | (0x54000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                               >> 0xcU))) 
                              | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                        >> 0x1cU)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:880: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'B' channel carries Probe type which is unexpected using diplomatic parameters (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 880, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:881:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:882: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 882, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12149(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12149\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceB__DOT__b_valid) 
                       & (0x1cU == (0x3cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source)))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((((((((((((3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                              >> 0xcU)) 
                                      | (0x2010U == 
                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                          >> 0xcU))) 
                                     | (4U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                               >> 0xcU))) 
                                    | (0x54000U == 
                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                        >> 0xcU))) 
                                   | (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                             >> 0x1aU))) 
                                  | (0x200U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                                >> 0x10U))) 
                                 | (0U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                           >> 0xcU))) 
                                | (1U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                          >> 0x10U))) 
                               | (0x100U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                             >> 0xcU))) 
                              | (0x110U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                            >> 0xcU))) 
                             | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                       >> 0x1cU))) 
                            | (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                            >> 0xcU))) 
                           | (2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                     >> 0x10U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:886: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'B' channel Probe carries unmanaged address (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 886, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:887:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:888: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 888, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12150(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12150\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceB__DOT__b_valid) 
                       & (0x1cU == (0x3cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source)))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))) 
                          << 1U) | (1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source)))) 
                        != (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:892: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'B' channel Probe carries source that is not first source (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 892, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:893:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:894: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 894, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceB__DOT__b_valid) 
                       & (0x1cU == (0x3cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source)))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (0x3fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:898: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'B' channel Probe address not aligned to size (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 898, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:899:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:900: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 900, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12151(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12151\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceB__DOT__b_valid) 
                       & (0x1cU == (0x3cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source)))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:904: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'B' channel Probe carries invalid cap param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 904, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:905:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:906: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 906, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1000U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((((((((((((3U == (0xfffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                  << 0x13U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 0xdU)))) 
                                      | (0x2010U == 
                                         (0xfffffU 
                                          & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                              << 0x13U) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 0xdU))))) 
                                     | (4U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0x13U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0xdU))))) 
                                    | (0x54000U == 
                                       (0xfffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          << 0x13U) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                            >> 0xdU))))) 
                                   | (3U == (0x3fU 
                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 5U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x1bU))))) 
                                  | (0x200U == (0xffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0xfU) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x11U))))) 
                                 | (0U == (0xfffffU 
                                           & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               << 0x13U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 0xdU))))) 
                                | (1U == (0xffffU & 
                                          ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            << 0xfU) 
                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0x11U))))) 
                               | (0x100U == (0xfffffU 
                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 0x13U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0xdU))))) 
                              | (0x110U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0x13U) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0xdU))))) 
                             | (8U == (0xfU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 3U) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x1dU))))) 
                            | (0x10000U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0x13U) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0xdU))))) 
                           | (2U == (0xffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 0xfU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x11U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:916: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel ProbeAck carries unmanaged address (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 916, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:917:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:918: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 918, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12152(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12152\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1000U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((0U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 1U))) 
                            | (1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            >> 1U)))) 
                           | (2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                           >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:922: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel ProbeAck carries invalid source ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 922, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:923:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:924: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 924, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1000U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (3U > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                      >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:928: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel ProbeAck smaller than a beat (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 928, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:929:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:930: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 930, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12153(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12153\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1000U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           << 0x1fU) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                             >> 1U)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    >> 3U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                          >> 3U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:934: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel ProbeAck address not aligned to size (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 934, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:935:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:936: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 936, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                      & (0x1300U == (0x1f00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:940: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel ProbeAck carries invalid report param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 940, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:941:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:942: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 942, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12154(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12154\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1000U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:946: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel ProbeAck is corrupt (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 946, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:947:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:948: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 948, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1400U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((((((((((((3U == (0xfffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                  << 0x13U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 0xdU)))) 
                                      | (0x2010U == 
                                         (0xfffffU 
                                          & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                              << 0x13U) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 0xdU))))) 
                                     | (4U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0x13U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0xdU))))) 
                                    | (0x54000U == 
                                       (0xfffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          << 0x13U) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                            >> 0xdU))))) 
                                   | (3U == (0x3fU 
                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 5U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x1bU))))) 
                                  | (0x200U == (0xffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0xfU) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x11U))))) 
                                 | (0U == (0xfffffU 
                                           & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               << 0x13U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 0xdU))))) 
                                | (1U == (0xffffU & 
                                          ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            << 0xfU) 
                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0x11U))))) 
                               | (0x100U == (0xfffffU 
                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 0x13U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0xdU))))) 
                              | (0x110U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0x13U) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0xdU))))) 
                             | (8U == (0xfU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 3U) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x1dU))))) 
                            | (0x10000U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0x13U) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0xdU))))) 
                           | (2U == (0xffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 0xfU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x11U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:952: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel ProbeAckData carries unmanaged address (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 952, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:953:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:954: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 954, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12155(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12155\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1400U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((0U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 1U))) 
                            | (1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            >> 1U)))) 
                           | (2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                           >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:958: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel ProbeAckData carries invalid source ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 958, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:959:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:960: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 960, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1400U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (3U > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                      >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:964: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel ProbeAckData smaller than a beat (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 964, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:965:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:966: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 966, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12156(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12156\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1400U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           << 0x1fU) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                             >> 1U)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    >> 3U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                          >> 3U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:970: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel ProbeAckData address not aligned to size (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 970, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:971:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:972: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 972, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                      & (0x1700U == (0x1f00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:976: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel ProbeAckData carries invalid report param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 976, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:977:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:978: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 978, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12157(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12157\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1800U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ ((IData)(((0x30U == (0x78U 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U])) 
                                    & ((0xdU > (0xfU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 3U))) 
                                       & (((0U == (3U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                      >> 1U))) 
                                           | (1U == 
                                              (3U & 
                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                >> 1U)))) 
                                          | (2U == 
                                             (3U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               >> 1U))))))) 
                           & (((2U == (0xffffU & ((
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0xfU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x11U)))) 
                               | (0x10000U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0x13U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0xdU))))) 
                              | (8U == (0xfU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 3U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x1dU)))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:982: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel carries Release type unsupported by manager (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 982, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:983:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:984: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 984, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12158(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12158\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1800U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((IData)((0x30U == (0x7eU 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                            & (0xdU > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               >> 3U)))) 
                           & (((((((((((0U == ((0x7fffcU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0x12U) 
                                                   | (0x3fffcU 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                         >> 0xeU)))) 
                                               | (3U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0xdU)))) 
                                       | (3U == (0xfffffU 
                                                 & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                     << 0x13U) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                       >> 0xdU))))) 
                                      | (1U == (0xffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0xfU) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x11U))))) 
                                     | (2U == (0xffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0xfU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x11U))))) 
                                    | (0U == ((0x7fff0U 
                                               & (0x80U 
                                                  ^ 
                                                  ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0x12U) 
                                                   | (0x3fff0U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                         >> 0xeU))))) 
                                              | (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 0xdU))))) 
                                   | (0x200U == (0xffffU 
                                                 & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                     << 0xfU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                       >> 0x11U))))) 
                                  | (0x2010U == (0xfffffU 
                                                 & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                     << 0x13U) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                       >> 0xdU))))) 
                                 | (3U == (0x3fU & 
                                           ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                             << 5U) 
                                            | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                               >> 0x1bU))))) 
                                | (0x10000U == (0xfffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0x13U) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0xdU))))) 
                               | (0x54000U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0x13U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0xdU))))) 
                              | (8U == (0xfU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 3U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x1dU)))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:988: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel carries Release from a client which does not support Probe (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 988, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:989:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:990: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 990, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12159(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12159\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1800U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((0U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 1U))) 
                            | (1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            >> 1U)))) 
                           | (2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                           >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:994: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel Release carries invalid source ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 994, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:995:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:996: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 996, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1800U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (3U > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                      >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1000: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel Release smaller than a beat (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1000, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1001:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1002: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1002, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12160(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12160\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1800U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           << 0x1fU) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                             >> 1U)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    >> 3U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                          >> 3U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1006: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel Release address not aligned to size (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1006, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1007:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1008: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1008, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                      & (0x1b00U == (0x1f00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1012: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel Release carries invalid report param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1012, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1013:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1014: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1014, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12161(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12161\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1800U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1018: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel Release is corrupt (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1018, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1019:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1020: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1020, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1c00U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ ((IData)(((0x30U == (0x78U 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U])) 
                                    & ((0xdU > (0xfU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 3U))) 
                                       & (((0U == (3U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                      >> 1U))) 
                                           | (1U == 
                                              (3U & 
                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                >> 1U)))) 
                                          | (2U == 
                                             (3U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               >> 1U))))))) 
                           & (((2U == (0xffffU & ((
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0xfU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x11U)))) 
                               | (0x10000U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0x13U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0xdU))))) 
                              | (8U == (0xfU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 3U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x1dU)))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1024: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel carries ReleaseData type unsupported by manager (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1024, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1025:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1026: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1026, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12162(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12162\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1c00U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((IData)((0x30U == (0x7eU 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                            & (0xdU > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               >> 3U)))) 
                           & (((((((((((0U == ((0x7fffcU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0x12U) 
                                                   | (0x3fffcU 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                         >> 0xeU)))) 
                                               | (3U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0xdU)))) 
                                       | (3U == (0xfffffU 
                                                 & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                     << 0x13U) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                       >> 0xdU))))) 
                                      | (1U == (0xffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0xfU) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x11U))))) 
                                     | (2U == (0xffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0xfU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x11U))))) 
                                    | (0U == ((0x7fff0U 
                                               & (0x80U 
                                                  ^ 
                                                  ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0x12U) 
                                                   | (0x3fff0U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                         >> 0xeU))))) 
                                              | (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 0xdU))))) 
                                   | (0x200U == (0xffffU 
                                                 & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                     << 0xfU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                       >> 0x11U))))) 
                                  | (0x2010U == (0xfffffU 
                                                 & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                     << 0x13U) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                       >> 0xdU))))) 
                                 | (3U == (0x3fU & 
                                           ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                             << 5U) 
                                            | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                               >> 0x1bU))))) 
                                | (0x10000U == (0xfffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0x13U) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0xdU))))) 
                               | (0x54000U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0x13U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0xdU))))) 
                              | (8U == (0xfU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 3U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x1dU)))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1030: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel carries Release from a client which does not support Probe (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1030, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1031:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1032: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1032, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12163(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12163\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1c00U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((0U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 1U))) 
                            | (1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            >> 1U)))) 
                           | (2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                           >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1036: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel ReleaseData carries invalid source ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1036, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1037:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1038: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1038, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1c00U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (3U > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                      >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1042: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel ReleaseData smaller than a beat (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1042, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1043:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1044: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1044, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12164(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12164\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x1c00U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           << 0x1fU) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                             >> 1U)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    >> 3U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                          >> 3U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1048: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel ReleaseData address not aligned to size (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1048, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1049:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1050: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1050, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                      & (0x1f00U == (0x1f00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1054: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel ReleaseData carries invalid report param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1054, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1055:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1056: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1056, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12165(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12165\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((((((((((((3U == (0xfffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                  << 0x13U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 0xdU)))) 
                                      | (0x2010U == 
                                         (0xfffffU 
                                          & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                              << 0x13U) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 0xdU))))) 
                                     | (4U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0x13U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0xdU))))) 
                                    | (0x54000U == 
                                       (0xfffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          << 0x13U) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                            >> 0xdU))))) 
                                   | (3U == (0x3fU 
                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 5U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x1bU))))) 
                                  | (0x200U == (0xffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0xfU) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x11U))))) 
                                 | (0U == (0xfffffU 
                                           & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               << 0x13U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 0xdU))))) 
                                | (1U == (0xffffU & 
                                          ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            << 0xfU) 
                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0x11U))))) 
                               | (0x100U == (0xfffffU 
                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 0x13U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0xdU))))) 
                              | (0x110U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0x13U) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0xdU))))) 
                             | (8U == (0xfU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 3U) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x1dU))))) 
                            | (0x10000U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0x13U) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0xdU))))) 
                           | (2U == (0xffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 0xfU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x11U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1060: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel AccessAck carries unmanaged address (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1060, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1061:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1062: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1062, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12166(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12166\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((0U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 1U))) 
                            | (1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            >> 1U)))) 
                           | (2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                           >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1066: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel AccessAck carries invalid source ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1066, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1067:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1068: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1068, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           << 0x1fU) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                             >> 1U)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    >> 3U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                          >> 3U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1072: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel AccessAck address not aligned to size (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1072, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1073:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1074: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1074, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12167(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12167\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                     >> 7U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1078: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel AccessAck carries invalid param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1078, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1079:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1080: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1080, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1084: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel AccessAck is corrupt (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1084, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1085:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1086: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1086, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12168(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12168\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x400U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((((((((((((3U == (0xfffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                  << 0x13U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 0xdU)))) 
                                      | (0x2010U == 
                                         (0xfffffU 
                                          & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                              << 0x13U) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 0xdU))))) 
                                     | (4U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0x13U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0xdU))))) 
                                    | (0x54000U == 
                                       (0xfffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          << 0x13U) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                            >> 0xdU))))) 
                                   | (3U == (0x3fU 
                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 5U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x1bU))))) 
                                  | (0x200U == (0xffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0xfU) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x11U))))) 
                                 | (0U == (0xfffffU 
                                           & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               << 0x13U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 0xdU))))) 
                                | (1U == (0xffffU & 
                                          ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            << 0xfU) 
                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0x11U))))) 
                               | (0x100U == (0xfffffU 
                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 0x13U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0xdU))))) 
                              | (0x110U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0x13U) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0xdU))))) 
                             | (8U == (0xfU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 3U) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x1dU))))) 
                            | (0x10000U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0x13U) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0xdU))))) 
                           | (2U == (0xffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 0xfU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x11U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1090: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel AccessAckData carries unmanaged address (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1090, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1091:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1092: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1092, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12169(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12169\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x400U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((0U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 1U))) 
                            | (1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            >> 1U)))) 
                           | (2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                           >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1096: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel AccessAckData carries invalid source ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1096, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1097:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1098: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1098, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x400U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           << 0x1fU) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                             >> 1U)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    >> 3U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                          >> 3U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1102: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel AccessAckData address not aligned to size (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1102, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1103:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1104: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1104, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12170(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12170\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x400U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                     >> 7U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1108: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel AccessAckData carries invalid param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1108, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1109:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1110: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1110, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x800U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((((((((((((3U == (0xfffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                  << 0x13U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 0xdU)))) 
                                      | (0x2010U == 
                                         (0xfffffU 
                                          & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                              << 0x13U) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 0xdU))))) 
                                     | (4U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0x13U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0xdU))))) 
                                    | (0x54000U == 
                                       (0xfffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          << 0x13U) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                            >> 0xdU))))) 
                                   | (3U == (0x3fU 
                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 5U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x1bU))))) 
                                  | (0x200U == (0xffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0xfU) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x11U))))) 
                                 | (0U == (0xfffffU 
                                           & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               << 0x13U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 0xdU))))) 
                                | (1U == (0xffffU & 
                                          ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            << 0xfU) 
                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0x11U))))) 
                               | (0x100U == (0xfffffU 
                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 0x13U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0xdU))))) 
                              | (0x110U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0x13U) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0xdU))))) 
                             | (8U == (0xfU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 3U) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x1dU))))) 
                            | (0x10000U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0x13U) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0xdU))))) 
                           | (2U == (0xffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 0xfU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x11U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1114: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel HintAck carries unmanaged address (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1114, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1115:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1116: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1116, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12171(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12171\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x800U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((0U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 1U))) 
                            | (1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            >> 1U)))) 
                           | (2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                           >> 1U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1120: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel HintAck carries invalid source ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1120, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1121:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1122: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1122, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x800U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           << 0x1fU) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                             >> 1U)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    >> 3U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                          >> 3U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1126: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel HintAck address not aligned to size (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1126, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1127:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1128: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1128, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12172(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12172\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x800U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                     >> 7U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1132: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel HintAck carries invalid param (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1132, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1133:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1134: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1134, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0x800U == (0x1c00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1138: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel HintAck is corrupt (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1138, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1139:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1140: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1140, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12173(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12173\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT___io_deq_valid_output) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__a_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                               >> 0x12U)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__opcode))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1144: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'A' channel opcode changed within multibeat operation (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1144, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1145:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1146: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1146, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT___io_deq_valid_output) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__a_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                               >> 0xfU)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1150: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'A' channel param changed within multibeat operation (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1150, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1151:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1152: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1152, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12174(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12174\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT___io_deq_valid_output) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__a_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                 >> 0xbU)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1156: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'A' channel size changed within multibeat operation (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1156, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1157:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1158: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1158, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT___io_deq_valid_output) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__a_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                               >> 9U)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1162: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'A' channel source changed within multibeat operation (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1162, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1163:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1164: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1164, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12175(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12175\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT___io_deq_valid_output) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__a_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                          << 0x17U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                       >> 9U)) != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__address)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1168: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'A' channel address changed with multibeat operation (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1168, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1169:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1170: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1170, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__opcode_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1174: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel opcode changed within multibeat operation (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1174, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1175:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1176: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1176, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12176(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12176\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_param) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__param_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1180: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel param changed within multibeat operation (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1180, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1181:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1182: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1182, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_size) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__size_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1186: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel size changed within multibeat operation (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1186, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1187:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1188: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1188, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12177(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12177\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__source_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1192: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel source changed within multibeat operation (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1192, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1193:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1194: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1194, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_sink) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__sink))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1198: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel sink changed with multibeat operation (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1198, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1199:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1200: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1200, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12178(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12178\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_denied) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__denied))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1204: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel denied changed with multibeat operation (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1204, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1205:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1206: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1206, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__c_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                               >> 0xaU)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__opcode_3))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1210: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel opcode changed within multibeat operation (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1210, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1211:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1212: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1212, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12179(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12179\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__c_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                               >> 7U)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__param_3))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1216: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel param changed within multibeat operation (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1216, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1217:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1218: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1218, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__c_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                 >> 3U)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__size_3))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1222: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel size changed within multibeat operation (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1222, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1223:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1224: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1224, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12180(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12180\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__c_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                               >> 1U)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__source_3))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1228: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel source changed within multibeat operation (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1228, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1229:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1230: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1230, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__c_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                          << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                       >> 1U)) != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__address_2)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1234: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel address changed with multibeat operation (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1234, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1235:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1236: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1236, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12181(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12181\n"); );
    // Body
    if (VL_UNLIKELY((7U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___T_2503) 
                            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__inflight) 
                              >> (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                        >> 9U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1240: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'A' channel re-used a source ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1240, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1241:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1242: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1242, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___T_2522) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ ((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__inflight) 
                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__same_cycle_resp)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1246: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1246, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1247:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1248: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1248, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12182(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12182\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___T_2522) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__same_cycle_resp)) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & 
                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                >> 0x12U)))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                     >> 0x12U))))))
                                 : 0U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                        >> 0x12U)))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                              >> 0x12U))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1252: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel contains improper opcode response (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1252, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1253:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1254: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1254, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12183(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12183\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___T_2522) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__same_cycle_resp)) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                 >> 0xbU)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1258: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel contains improper response size (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1258, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1259:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1260: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1260, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___T_2522) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__same_cycle_resp))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & 
                                               (((0xbU 
                                                  >= 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source) 
                                                   << 2U))
                                                  ? 
                                                 (0xfffU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__inflight_opcodes) 
                                                     >> 
                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source) 
                                                      << 2U)))
                                                  : 0U) 
                                                >> 1U)))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & (((0xbU 
                                                       >= 
                                                       ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source) 
                                                        << 2U))
                                                       ? 
                                                      (0xfffU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__inflight_opcodes) 
                                                          >> 
                                                          ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source) 
                                                           << 2U)))
                                                       : 0U) 
                                                     >> 1U))))))
                                 : 0U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & (((0xbU 
                                                          >= 
                                                          ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source) 
                                                           << 2U))
                                                          ? 
                                                         (0xfffU 
                                                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__inflight_opcodes) 
                                                             >> 
                                                             ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source) 
                                                              << 2U)))
                                                          : 0U) 
                                                        >> 1U)))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & (((0xbU 
                                                                >= 
                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source) 
                                                                 << 2U))
                                                                ? 
                                                               (0xfffU 
                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__inflight_opcodes) 
                                                                   >> 
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source) 
                                                                    << 2U)))
                                                                : 0U) 
                                                              >> 1U))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1264: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel contains improper opcode response (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1264, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1265:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1266: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1266, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12184(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12184\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___T_2522) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__same_cycle_resp))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_size) 
                        != (0x7fU & (((0x17U >= ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source) 
                                                 << 3U))
                                       ? (0xffffffU 
                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__inflight_sizes 
                                             >> ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source) 
                                                 << 3U)))
                                       : 0U) >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1270: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel contains improper response size (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1270, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1271:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1272: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1272, "");
        }
    }
    if (VL_UNLIKELY(((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter_1))) 
                          & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__a_first_counter_1))) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT___io_deq_valid_output)) 
                        & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                  >> 9U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))) 
                       & (6U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_d_source__DOT___io_enq_ready_output)) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT___portsAOI_in_2_a_ready_WIRE)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1276: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: ready check\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1276, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1277:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1278: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1278, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12185(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12185\n"); );
    // Body
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset)) 
                           & (~ ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___same_cycle_resp_T_1)
                                    ? (7U & ((IData)(1U) 
                                             << (3U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    >> 9U))))
                                    : 0U) != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                                                & (0U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter_1))) 
                                               & (6U 
                                                  != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode)))
                                               ? (7U 
                                                  & ((IData)(1U) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source)))
                                               : 0U)) 
                                 | (0U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___same_cycle_resp_T_1)
                                            ? (7U & 
                                               ((IData)(1U) 
                                                << 
                                                (3U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    >> 9U))))
                                            : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1282: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'A' and 'D' concurrent, despite minlatency 2 (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1282, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1283:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1284: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1284, "");
        }
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset)) 
                           & (~ (((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__inflight)) 
                                  | (0U == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__plusarg_reader__DOT__myplus)) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__watchdog 
                                    < vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__plusarg_reader__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1288: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: TileLink timeout expired (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1288, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1289:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1290: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1290, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12186(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12186\n"); );
    // Body
    if (VL_UNLIKELY((7U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___T_2592) 
                            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__inflight_1) 
                              >> (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                        >> 1U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1294: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' channel re-used a source ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1294, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1295:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1296: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1296, "");
        }
    }
    if (VL_UNLIKELY((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                        & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter_2))) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ ((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__inflight_1) 
                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))) 
                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___same_cycle_resp_T_3) 
                               & (0x1800U == (0x1800U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                              & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                        >> 1U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1300: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1300, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1301:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1302: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1302, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12187(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12187\n"); );
    // Body
    if (VL_UNLIKELY(((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                         & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter_2))) 
                        & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                       & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___same_cycle_resp_T_3) 
                           & (0x1800U == (0x1800U & 
                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                          & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                    >> 1U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source)))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_size) 
                        != (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                    >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1306: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel contains improper response size (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1306, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1307:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1308: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1308, "");
        }
    }
    if (VL_UNLIKELY(((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                         & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter_2))) 
                        & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                       & (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___same_cycle_resp_T_3) 
                              & (0x1800U == (0x1800U 
                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                             & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                       >> 1U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_size) 
                        != (0x7fU & (((0x17U >= ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source) 
                                                 << 3U))
                                       ? (0xffffffU 
                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__inflight_sizes_1 
                                             >> ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source) 
                                                 << 3U)))
                                       : 0U) >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1312: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel contains improper response size (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1312, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1313:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1314: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1314, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12188(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12188\n"); );
    // Body
    if (VL_UNLIKELY((((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                            & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter_2))) 
                           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__c_first_counter_1))) 
                          & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT___io_deq_valid_output)) 
                         & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                   >> 1U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source))) 
                        & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode))) 
                       & (~ ((4U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                           >> 0xaU))) 
                             | (5U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                             >> 0xaU)))))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_d_source__DOT___io_enq_ready_output)) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_10_ready)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1318: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: ready check\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1318, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1319:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1320: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1320, "");
        }
    }
    if (VL_UNLIKELY((((0U != (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___same_cycle_resp_T_3) 
                               & (0x1800U == (0x1800U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U])))
                               ? (7U & ((IData)(1U) 
                                        << (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                  >> 1U))))
                               : 0U)) & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___same_cycle_resp_T_3) 
                          & (0x1800U == (0x1800U & 
                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U])))
                          ? (7U & ((IData)(1U) << (3U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                      >> 1U))))
                          : 0U) == ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_valid) 
                                      & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter_2))) 
                                     & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode)))
                                     ? (7U & ((IData)(1U) 
                                              << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source)))
                                     : 0U))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1324: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'C' and 'D' concurrent, despite minlatency 2 (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1324, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1325:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1326: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1326, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12189(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12189\n"); );
    // Body
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset)) 
                           & (~ (((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__inflight_1)) 
                                  | (0U == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__plusarg_reader_1__DOT__myplus)) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__watchdog_1 
                                    < vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__plusarg_reader_1__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1330: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: TileLink timeout expired (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1330, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1331:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1332: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1332, "");
        }
    }
    if (VL_UNLIKELY((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___T_2653) 
                        & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter_3))) 
                       & (4U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_opcode)))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & ((7U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_sink))
                         ? (0xffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__inflight_2) 
                                     >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_34_bits_sink)))
                         : 0U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1336: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'D' channel re-used a sink ID (connected at SystemBus.scala:41:96)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1336, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1337:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1338: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1338, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12190(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12190\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_16_ready) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT___io_deq_valid_output)) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ ((7U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg))
                            ? (0xffU & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_set) 
                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__inflight_2)) 
                                        >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg)))
                            : 0U))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1342: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2: Assertion failed: 'E' channel acknowledged for nothing inflight (connected at SystemBus.scala:41:96)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1342, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv:1343:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_8.sv:1344: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.fixer.monitor_2\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_8.sv", 1344, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT___io_deq_valid_output) 
                       & (0x180000U == (0x1c0000U & 
                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ ((IData)(((0x3000U == (0x7800U 
                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U])) 
                                    & ((0xdU > (0xfU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 0xbU))) 
                                       & (((0U == (3U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                      >> 9U))) 
                                           | (1U == 
                                              (3U & 
                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                >> 9U)))) 
                                          | (2U == 
                                             (3U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               >> 9U))))))) 
                           & (((2U == (0xffffU & ((
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 7U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x19U)))) 
                               | (0x10000U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0xbU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x15U))))) 
                              | (8U == (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                >> 5U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_2.sv:430: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.system_bus_xbar.monitor_3: Assertion failed: 'A' channel carries AcquireBlock type which is unexpected using diplomatic parameters (connected at SystemBus.scala:41:55)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_2.sv", 430, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_2.sv:431:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_2.sv:432: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.system_bus_xbar.monitor_3\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_2.sv", 432, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12191(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12191\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT___io_deq_valid_output) 
                       & (0x180000U == (0x1c0000U & 
                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((IData)((0x3000U == (0x7e00U 
                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                            & (0xdU > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               >> 0xbU)))) 
                           & (((((((((((0U == ((0x7fffcU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0xaU) 
                                                   | (0x3fcU 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                         >> 0x16U)))) 
                                               | (3U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x15U)))) 
                                       | (3U == (0xfffffU 
                                                 & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                     << 0xbU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                       >> 0x15U))))) 
                                      | (1U == (0xffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 7U) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x19U))))) 
                                     | (2U == (0xffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 7U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x19U))))) 
                                    | (0U == ((0x7fff0U 
                                               & (0x80U 
                                                  ^ 
                                                  ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0xaU) 
                                                   | (0x3f0U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                         >> 0x16U))))) 
                                              | (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 0x15U))))) 
                                   | (0x200U == (0xffffU 
                                                 & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                     << 7U) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                       >> 0x19U))))) 
                                  | (0x2010U == (0xfffffU 
                                                 & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                     << 0xbU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                       >> 0x15U))))) 
                                 | (3U == (0x3fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            >> 3U)))) 
                                | (0x10000U == (0xfffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0xbU) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x15U))))) 
                               | (0x54000U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0xbU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x15U))))) 
                              | (8U == (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                >> 5U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_2.sv:436: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.system_bus_xbar.monitor_3: Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at SystemBus.scala:41:55)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_2.sv", 436, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_2.sv:437:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_2.sv:438: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.system_bus_xbar.monitor_3\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_2.sv", 438, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12192(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12192\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT___io_deq_valid_output) 
                       & (0x180000U == (0x1c0000U & 
                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (~ (((0U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 9U))) 
                            | (1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            >> 9U)))) 
                           | (2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                           >> 9U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_2.sv:442: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.system_bus_xbar.monitor_3: Assertion failed: 'A' channel AcquireBlock carries invalid source ID (connected at SystemBus.scala:41:55)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_2.sv", 442, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_2.sv:443:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_2.sv:444: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.system_bus_xbar.monitor_3\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_2.sv", 444, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT___io_deq_valid_output) 
                       & (0x180000U == (0x1c0000U & 
                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset))) 
                     & (2U >= (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                       >> 0xbU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_2.sv:448: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.system_bus_xbar.monitor_3: Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at SystemBus.scala:41:55)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_2.sv", 448, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_2.sv:449:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_2.sv:450: Assertion failed in %NTestHarness.chiptop.system.subsystem_sbus.system_bus_xbar.monitor_3\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_2.sv", 450, "");
        }
    }
}
