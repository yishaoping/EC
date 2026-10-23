// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness__Syms.h"
#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10765(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10765\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ ((((0xdU > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                              >> 6U))) 
                             & (((((((((((((((((0x20U 
                                                == 
                                                (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU))) 
                                               | ((~ (IData)(
                                                             (0U 
                                                              != 
                                                              (0xfU 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0xdU))))) 
                                                  & (5U 
                                                     > 
                                                     (7U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                         >> 0xaU))))) 
                                              | (5U 
                                                 == 
                                                 (0x7fU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                             | (8U 
                                                == 
                                                (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                            | (0x1cU 
                                               == (0x7fU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU)))) 
                                           | (0x1dU 
                                              == (0x7fU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                          | (0x1eU 
                                             == (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                         | (0x18U == 
                                            (0x7fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0xaU)))) 
                                        | (0x19U == 
                                           (0x7fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xaU)))) 
                                       | (0x1aU == 
                                          (0x7fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 0xaU)))) 
                                      | (0x14U == (0x7fU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU)))) 
                                     | (0x15U == (0x7fU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                    | (0x16U == (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                   | (0x10U == (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)))) 
                                  | (0x11U == (0x7fU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0xaU)))) 
                                 | (0x12U == (0x7fU 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 0xaU)))) 
                                | (0x40U == (0x7fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0xaU))))) 
                            & (4U > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 6U)))) 
                           & (((3U == (0x7ffffU & (
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                    << 3U) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0x1dU)))) 
                               | (4U == (0x7ffffU & 
                                         ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                           << 3U) | 
                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           >> 0x1dU))))) 
                              | (0x54000U == (0x7ffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  << 3U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0x1dU)))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:500: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel carries Arithmetic type which is unexpected using diplomatic parameters (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 500, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:501:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:502: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 502, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10766(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10766\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:506: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel Arithmetic carries invalid source ID (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 506, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:507:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:508: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 508, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           << 0xfU) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0x11U)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 6U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:512: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 512, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:513:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:514: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 514, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10767(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10767\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (4U < (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                    >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:518: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel Arithmetic carries invalid opcode param (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 518, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:519:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:520: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 520, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                  >> 0x10U)) != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_5) 
                                                   << 7U) 
                                                  | (0x3fff80U 
                                                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_5) 
                                                         << 7U) 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0xaU)))) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_5) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_5) 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                             >> 0x11U)))) 
                                                     << 6U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_4) 
                                                         << 5U) 
                                                        | (0xfffe0U 
                                                           & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_4) 
                                                               << 5U) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0xcU)))) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_4) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_4) 
                                                               & (~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                   >> 0x11U)))) 
                                                           << 4U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_3) 
                                                               << 3U) 
                                                              | (0x3fff8U 
                                                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_3) 
                                                                     << 3U) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0xeU)))) 
                                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_3) 
                                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_3) 
                                                                     & (~ 
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                         >> 0x11U)))) 
                                                                 << 2U) 
                                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_2) 
                                                                     << 1U) 
                                                                    | (0xfffeU 
                                                                       & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_2) 
                                                                           << 1U) 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                             >> 0x10U)))) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_2) 
                                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_2) 
                                                                         & (~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                             >> 0x11U))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:524: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 524, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:525:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:526: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 526, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10768(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10768\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (3U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ ((((0xdU > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                              >> 6U))) 
                             & (((((((((((((((((0x20U 
                                                == 
                                                (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU))) 
                                               | ((~ (IData)(
                                                             (0U 
                                                              != 
                                                              (0xfU 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0xdU))))) 
                                                  & (5U 
                                                     > 
                                                     (7U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                         >> 0xaU))))) 
                                              | (5U 
                                                 == 
                                                 (0x7fU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                             | (8U 
                                                == 
                                                (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                            | (0x1cU 
                                               == (0x7fU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU)))) 
                                           | (0x1dU 
                                              == (0x7fU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                          | (0x1eU 
                                             == (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                         | (0x18U == 
                                            (0x7fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0xaU)))) 
                                        | (0x19U == 
                                           (0x7fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xaU)))) 
                                       | (0x1aU == 
                                          (0x7fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 0xaU)))) 
                                      | (0x14U == (0x7fU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU)))) 
                                     | (0x15U == (0x7fU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                    | (0x16U == (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                   | (0x10U == (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)))) 
                                  | (0x11U == (0x7fU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0xaU)))) 
                                 | (0x12U == (0x7fU 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 0xaU)))) 
                                | (0x40U == (0x7fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0xaU))))) 
                            & (4U > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 6U)))) 
                           & (((3U == (0x7ffffU & (
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                    << 3U) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0x1dU)))) 
                               | (4U == (0x7ffffU & 
                                         ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                           << 3U) | 
                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           >> 0x1dU))))) 
                              | (0x54000U == (0x7ffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  << 3U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0x1dU)))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:530: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel carries Logical type which is unexpected using diplomatic parameters (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 530, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:531:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:532: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 532, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10769(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10769\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (3U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:536: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel Logical carries invalid source ID (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 536, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:537:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:538: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 538, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (3U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           << 0xfU) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0x11U)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 6U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:542: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel Logical address not aligned to size (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 542, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:543:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:544: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 544, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10770(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10770\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                      & (0x23U == (0x27U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:548: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel Logical carries invalid opcode param (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 548, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:549:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:550: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 550, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (3U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                  >> 0x10U)) != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_5) 
                                                   << 7U) 
                                                  | (0x3fff80U 
                                                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_5) 
                                                         << 7U) 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0xaU)))) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_5) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_5) 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                             >> 0x11U)))) 
                                                     << 6U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_4) 
                                                         << 5U) 
                                                        | (0xfffe0U 
                                                           & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_4) 
                                                               << 5U) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0xcU)))) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_4) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_4) 
                                                               & (~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                   >> 0x11U)))) 
                                                           << 4U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_3) 
                                                               << 3U) 
                                                              | (0x3fff8U 
                                                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_3) 
                                                                     << 3U) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0xeU)))) 
                                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_3) 
                                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_3) 
                                                                     & (~ 
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                         >> 0x11U)))) 
                                                                 << 2U) 
                                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_2) 
                                                                     << 1U) 
                                                                    | (0xfffeU 
                                                                       & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_2) 
                                                                           << 1U) 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                             >> 0x10U)))) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_2) 
                                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_2) 
                                                                         & (~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                             >> 0x11U))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:554: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel Logical contains invalid mask (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 554, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:555:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:556: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 556, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10771(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10771\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (((0xdU > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 6U))) 
                            & (((((((((((((((((0x20U 
                                               == (0x7fU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU))) 
                                              | ((~ (IData)(
                                                            (0U 
                                                             != 
                                                             (0xfU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0xdU))))) 
                                                 & (5U 
                                                    > 
                                                    (7U 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                        >> 0xaU))))) 
                                             | (5U 
                                                == 
                                                (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                            | (8U == 
                                               (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)))) 
                                           | (0x1cU 
                                              == (0x7fU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                          | (0x1dU 
                                             == (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                         | (0x1eU == 
                                            (0x7fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0xaU)))) 
                                        | (0x18U == 
                                           (0x7fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xaU)))) 
                                       | (0x19U == 
                                          (0x7fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 0xaU)))) 
                                      | (0x1aU == (0x7fU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU)))) 
                                     | (0x14U == (0x7fU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                    | (0x15U == (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                   | (0x16U == (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)))) 
                                  | (0x10U == (0x7fU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0xaU)))) 
                                 | (0x11U == (0x7fU 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 0xaU)))) 
                                | (0x12U == (0x7fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0xaU)))) 
                               | (0x40U == (0x7fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xaU))))) 
                           & (3U == (0x7ffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  << 3U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0x1dU))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:560: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel carries Hint type which is unexpected using diplomatic parameters (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 560, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:561:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:562: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 562, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10772(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10772\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:566: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel Hint carries invalid source ID (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 566, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:567:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:568: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 568, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           << 0xfU) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0x11U)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 6U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:572: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel Hint address not aligned to size (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 572, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:573:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:574: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 574, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10773(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10773\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                     >> 4U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:578: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel Hint carries invalid opcode param (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 578, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:579:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:580: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 580, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                  >> 0x10U)) != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_5) 
                                                   << 7U) 
                                                  | (0x3fff80U 
                                                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_5) 
                                                         << 7U) 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0xaU)))) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_5) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_5) 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                             >> 0x11U)))) 
                                                     << 6U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_4) 
                                                         << 5U) 
                                                        | (0xfffe0U 
                                                           & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_4) 
                                                               << 5U) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0xcU)))) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_4) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_4) 
                                                               & (~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                   >> 0x11U)))) 
                                                           << 4U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_3) 
                                                               << 3U) 
                                                              | (0x3fff8U 
                                                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_3) 
                                                                     << 3U) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0xeU)))) 
                                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_3) 
                                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_3) 
                                                                     & (~ 
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                         >> 0x11U)))) 
                                                                 << 2U) 
                                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_2) 
                                                                     << 1U) 
                                                                    | (0xfffeU 
                                                                       & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_2) 
                                                                           << 1U) 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                             >> 0x10U)))) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_2) 
                                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_2) 
                                                                         & (~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                             >> 0x11U))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:584: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel Hint contains invalid mask (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 584, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:585:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:586: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 586, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10774(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10774\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                        >> 0x18U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:590: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel Hint is corrupt (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 590, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:591:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:592: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 592, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:596: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel has invalid opcode (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 596, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:597:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:598: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 598, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10775(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10775\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (((((((((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source)) 
                                          | (IData)(
                                                    ((0U 
                                                      == 
                                                      (0x78U 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                                     & (5U 
                                                        > 
                                                        (7U 
                                                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source)))))) 
                                         | (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                        | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                       | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                      | (0x1dU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                     | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                    | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                   | (0x19U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                  | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                 | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                | (0x15U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                               | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                              | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                             | (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                            | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                           | (0x40U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:602: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel ReleaseAck carries invalid source ID (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 602, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:603:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:604: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 604, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10776(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10776\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (3U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:608: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel ReleaseAck smaller than a beat (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 608, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:609:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:610: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 610, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:614: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel ReleaseeAck carries invalid param (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 614, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:615:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:616: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 616, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10777(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10777\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_0) 
                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                               >> 0x12U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_1) 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                                [0U][2U] 
                                                >> 0x14U))) 
                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_2) 
                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                >> 0x11U))) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_7) 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                                  >> 0x14U))) 
                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_8) 
                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                              >> 0x14U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:620: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel ReleaseAck is corrupt (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 620, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:621:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:622: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 622, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_denied)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:626: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel ReleaseAck is denied (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 626, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:627:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:628: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 628, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10778(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10778\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (((((((((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source)) 
                                          | (IData)(
                                                    ((0U 
                                                      == 
                                                      (0x78U 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                                     & (5U 
                                                        > 
                                                        (7U 
                                                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source)))))) 
                                         | (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                        | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                       | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                      | (0x1dU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                     | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                    | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                   | (0x19U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                  | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                 | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                | (0x15U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                               | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                              | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                             | (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                            | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                           | (0x40U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:632: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel Grant carries invalid source ID (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 632, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:633:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:634: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 634, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10779(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10779\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                      & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:638: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel Grant carries invalid sink ID (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 638, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:639:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:640: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 640, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (3U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:644: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel Grant smaller than a beat (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 644, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:645:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:646: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 646, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10780(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10780\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:650: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel Grant carries invalid cap param (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 650, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:651:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:652: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 652, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:656: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel Grant carries toN param (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 656, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:657:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:658: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 658, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10781(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10781\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_0) 
                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                               >> 0x12U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_1) 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                                [0U][2U] 
                                                >> 0x14U))) 
                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_2) 
                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                >> 0x11U))) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_7) 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                                  >> 0x14U))) 
                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_8) 
                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                              >> 0x14U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:662: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel Grant is corrupt (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 662, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:663:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:664: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 664, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (((((((((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source)) 
                                          | (IData)(
                                                    ((0U 
                                                      == 
                                                      (0x78U 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                                     & (5U 
                                                        > 
                                                        (7U 
                                                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source)))))) 
                                         | (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                        | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                       | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                      | (0x1dU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                     | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                    | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                   | (0x19U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                  | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                 | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                | (0x15U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                               | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                              | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                             | (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                            | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                           | (0x40U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:668: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel GrantData carries invalid source ID (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 668, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:669:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:670: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 670, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10782(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10782\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                      & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:674: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel GrantData carries invalid sink ID (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 674, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:675:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:676: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 676, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (3U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:680: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel GrantData smaller than a beat (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 680, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:681:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:682: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 682, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10783(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10783\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:686: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel GrantData carries invalid cap param (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 686, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:687:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:688: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 688, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:692: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel GrantData carries toN param (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 692, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:693:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:694: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 694, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10784(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10784\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_denied)) 
                           | ((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_0) 
                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                     >> 0x12U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_1) 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                                      [0U][2U] 
                                                      >> 0x14U))) 
                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_2) 
                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                      >> 0x11U))) | 
                               ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_7) 
                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                   >> 0x14U))) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_8) 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                                     >> 0x14U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:698: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel GrantData is denied but not corrupt (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 698, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:699:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:700: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 700, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (((((((((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source)) 
                                          | (IData)(
                                                    ((0U 
                                                      == 
                                                      (0x78U 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                                     & (5U 
                                                        > 
                                                        (7U 
                                                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source)))))) 
                                         | (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                        | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                       | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                      | (0x1dU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                     | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                    | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                   | (0x19U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                  | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                 | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                | (0x15U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                               | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                              | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                             | (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                            | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                           | (0x40U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:704: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel AccessAck carries invalid source ID (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 704, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:705:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:706: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 706, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10785(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10785\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:710: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel AccessAck carries invalid param (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 710, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:711:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:712: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 712, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_0) 
                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                               >> 0x12U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_1) 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                                [0U][2U] 
                                                >> 0x14U))) 
                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_2) 
                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                >> 0x11U))) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_7) 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                                  >> 0x14U))) 
                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_8) 
                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                              >> 0x14U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:716: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel AccessAck is corrupt (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 716, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:717:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:718: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 718, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10786(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10786\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (((((((((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source)) 
                                          | (IData)(
                                                    ((0U 
                                                      == 
                                                      (0x78U 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                                     & (5U 
                                                        > 
                                                        (7U 
                                                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source)))))) 
                                         | (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                        | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                       | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                      | (0x1dU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                     | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                    | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                   | (0x19U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                  | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                 | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                | (0x15U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                               | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                              | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                             | (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                            | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                           | (0x40U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:722: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel AccessAckData carries invalid source ID (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 722, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:723:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:724: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 724, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10787(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10787\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:728: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel AccessAckData carries invalid param (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 728, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:729:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:730: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 730, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_denied)) 
                           | ((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_0) 
                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                     >> 0x12U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_1) 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                                      [0U][2U] 
                                                      >> 0x14U))) 
                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_2) 
                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                      >> 0x11U))) | 
                               ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_7) 
                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                   >> 0x14U))) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_8) 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                                     >> 0x14U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:734: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel AccessAckData is denied but not corrupt (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 734, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:735:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:736: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 736, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10788(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10788\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (((((((((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source)) 
                                          | (IData)(
                                                    ((0U 
                                                      == 
                                                      (0x78U 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                                     & (5U 
                                                        > 
                                                        (7U 
                                                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source)))))) 
                                         | (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                        | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                       | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                      | (0x1dU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                     | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                    | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                   | (0x19U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                  | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                 | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                | (0x15U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                               | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                              | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                             | (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                            | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                           | (0x40U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:740: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel HintAck carries invalid source ID (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 740, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:741:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:742: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 742, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10789(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10789\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:746: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel HintAck carries invalid param (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 746, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:747:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:748: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 748, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_0) 
                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                               >> 0x12U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_1) 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                                [0U][2U] 
                                                >> 0x14U))) 
                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_2) 
                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                >> 0x11U))) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_7) 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                                  >> 0x14U))) 
                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_8) 
                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                              >> 0x14U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:752: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel HintAck is corrupt (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 752, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:753:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:754: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 754, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10790(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10790\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__a_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__opcode))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:758: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel opcode changed within multibeat operation (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 758, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:759:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:760: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 760, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__a_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                               >> 3U)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:764: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel param changed within multibeat operation (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 764, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:765:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:766: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 766, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10791(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10791\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__a_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                 >> 6U)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:770: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel size changed within multibeat operation (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 770, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:771:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:772: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 772, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__a_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                  >> 0xaU)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:776: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel source changed within multibeat operation (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 776, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:777:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:778: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 778, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10792(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10792\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__a_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((0x7fffffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                         << 0xfU) | 
                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 0x11U))) 
                        != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__address)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:782: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel address changed with multibeat operation (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 782, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:783:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:784: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 784, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__opcode_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:788: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel opcode changed within multibeat operation (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 788, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:789:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:790: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 790, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10793(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10793\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_param) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__param_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:794: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel param changed within multibeat operation (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 794, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:795:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:796: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 796, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_size) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__size_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:800: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel size changed within multibeat operation (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 800, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:801:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:802: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 802, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10794(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10794\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__source_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:806: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel source changed within multibeat operation (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 806, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:807:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:808: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 808, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_sink) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__sink))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:812: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel sink changed with multibeat operation (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 812, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:813:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:814: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 814, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10795(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10795\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h322d424c__0;
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_denied) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__denied))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:818: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel denied changed with multibeat operation (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 818, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:819:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:820: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 820, "");
        }
    }
    VL_SHIFTR_WWI(65,65,7, __Vtemp_h322d424c__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight, 
                  (0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                            >> 0xaU)));
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & __Vtemp_h322d424c__0[0U]))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:824: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'A' channel re-used a source ID (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 824, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:825:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:826: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 826, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10796(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10796\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_ha24139ba__0;
    VlWide<3>/*95:0*/ __Vtemp_h6cbbe5e1__0;
    // Body
    VL_EXTEND_WI(65,7, __Vtemp_ha24139ba__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source));
    VL_SHIFTR_WWW(65,65,65, __Vtemp_h6cbbe5e1__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight, __Vtemp_ha24139ba__0);
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1603) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (__Vtemp_h6cbbe5e1__0[0U] 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__same_cycle_resp)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:830: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 830, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:831:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:832: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 832, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1603) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__same_cycle_resp)) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & 
                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])))))
                                 : 0U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:836: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel contains improper opcode response (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 836, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:837:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:838: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 838, "");
        }
    }
}

extern const VlWide<9>/*287:0*/ VTestHarness__ConstPool__CONST_h52851b57_0;

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10797(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10797\n"); );
    // Init
    VlWide<9>/*287:0*/ __Vtemp_ha2597aee__0;
    VlWide<9>/*287:0*/ __Vtemp_ha10fb1e8__0;
    VlWide<9>/*287:0*/ __Vtemp_h50b642bb__0;
    VlWide<9>/*287:0*/ __Vtemp_ha2597aee__1;
    VlWide<9>/*287:0*/ __Vtemp_h9bc5258d__0;
    VlWide<9>/*287:0*/ __Vtemp_h90c56910__0;
    VlWide<9>/*287:0*/ __Vtemp_ha2597aee__2;
    VlWide<9>/*287:0*/ __Vtemp_hec45974b__0;
    VlWide<9>/*287:0*/ __Vtemp_h11b31c94__0;
    VlWide<9>/*287:0*/ __Vtemp_ha2597aee__3;
    VlWide<9>/*287:0*/ __Vtemp_h8d13807f__0;
    VlWide<9>/*287:0*/ __Vtemp_hade0c29d__0;
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1603) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__same_cycle_resp)) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                 >> 6U)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:842: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel contains improper response size (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 842, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:843:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:844: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 844, "");
        }
    }
    VL_EXTEND_WI(258,7, __Vtemp_ha2597aee__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source));
    __Vtemp_ha10fb1e8__0[0U] = (__Vtemp_ha2597aee__0[0U] 
                                << 2U);
    __Vtemp_ha10fb1e8__0[1U] = ((__Vtemp_ha2597aee__0[0U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__0[1U] 
                                              << 2U));
    __Vtemp_ha10fb1e8__0[2U] = ((__Vtemp_ha2597aee__0[1U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__0[2U] 
                                              << 2U));
    __Vtemp_ha10fb1e8__0[3U] = ((__Vtemp_ha2597aee__0[2U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__0[3U] 
                                              << 2U));
    __Vtemp_ha10fb1e8__0[4U] = ((__Vtemp_ha2597aee__0[3U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__0[4U] 
                                              << 2U));
    __Vtemp_ha10fb1e8__0[5U] = ((__Vtemp_ha2597aee__0[4U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__0[5U] 
                                              << 2U));
    __Vtemp_ha10fb1e8__0[6U] = ((__Vtemp_ha2597aee__0[5U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__0[6U] 
                                              << 2U));
    __Vtemp_ha10fb1e8__0[7U] = ((__Vtemp_ha2597aee__0[6U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__0[7U] 
                                              << 2U));
    __Vtemp_ha10fb1e8__0[8U] = ((__Vtemp_ha2597aee__0[7U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__0[8U] 
                                              << 2U));
    VL_SHIFTR_WWW(260,260,260, __Vtemp_h50b642bb__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes, __Vtemp_ha10fb1e8__0);
    VL_EXTEND_WI(258,7, __Vtemp_ha2597aee__1, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source));
    __Vtemp_h9bc5258d__0[0U] = (__Vtemp_ha2597aee__1[0U] 
                                << 2U);
    __Vtemp_h9bc5258d__0[1U] = ((__Vtemp_ha2597aee__1[0U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__1[1U] 
                                              << 2U));
    __Vtemp_h9bc5258d__0[2U] = ((__Vtemp_ha2597aee__1[1U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__1[2U] 
                                              << 2U));
    __Vtemp_h9bc5258d__0[3U] = ((__Vtemp_ha2597aee__1[2U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__1[3U] 
                                              << 2U));
    __Vtemp_h9bc5258d__0[4U] = ((__Vtemp_ha2597aee__1[3U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__1[4U] 
                                              << 2U));
    __Vtemp_h9bc5258d__0[5U] = ((__Vtemp_ha2597aee__1[4U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__1[5U] 
                                              << 2U));
    __Vtemp_h9bc5258d__0[6U] = ((__Vtemp_ha2597aee__1[5U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__1[6U] 
                                              << 2U));
    __Vtemp_h9bc5258d__0[7U] = ((__Vtemp_ha2597aee__1[6U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__1[7U] 
                                              << 2U));
    __Vtemp_h9bc5258d__0[8U] = ((__Vtemp_ha2597aee__1[7U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__1[8U] 
                                              << 2U));
    VL_SHIFTR_WWW(260,260,260, __Vtemp_h90c56910__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes, __Vtemp_h9bc5258d__0);
    VL_EXTEND_WI(258,7, __Vtemp_ha2597aee__2, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source));
    __Vtemp_hec45974b__0[0U] = (__Vtemp_ha2597aee__2[0U] 
                                << 2U);
    __Vtemp_hec45974b__0[1U] = ((__Vtemp_ha2597aee__2[0U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__2[1U] 
                                              << 2U));
    __Vtemp_hec45974b__0[2U] = ((__Vtemp_ha2597aee__2[1U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__2[2U] 
                                              << 2U));
    __Vtemp_hec45974b__0[3U] = ((__Vtemp_ha2597aee__2[2U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__2[3U] 
                                              << 2U));
    __Vtemp_hec45974b__0[4U] = ((__Vtemp_ha2597aee__2[3U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__2[4U] 
                                              << 2U));
    __Vtemp_hec45974b__0[5U] = ((__Vtemp_ha2597aee__2[4U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__2[5U] 
                                              << 2U));
    __Vtemp_hec45974b__0[6U] = ((__Vtemp_ha2597aee__2[5U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__2[6U] 
                                              << 2U));
    __Vtemp_hec45974b__0[7U] = ((__Vtemp_ha2597aee__2[6U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__2[7U] 
                                              << 2U));
    __Vtemp_hec45974b__0[8U] = ((__Vtemp_ha2597aee__2[7U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__2[8U] 
                                              << 2U));
    VL_SHIFTR_WWW(260,260,260, __Vtemp_h11b31c94__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes, __Vtemp_hec45974b__0);
    VL_EXTEND_WI(258,7, __Vtemp_ha2597aee__3, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source));
    __Vtemp_h8d13807f__0[0U] = (__Vtemp_ha2597aee__3[0U] 
                                << 2U);
    __Vtemp_h8d13807f__0[1U] = ((__Vtemp_ha2597aee__3[0U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__3[1U] 
                                              << 2U));
    __Vtemp_h8d13807f__0[2U] = ((__Vtemp_ha2597aee__3[1U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__3[2U] 
                                              << 2U));
    __Vtemp_h8d13807f__0[3U] = ((__Vtemp_ha2597aee__3[2U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__3[3U] 
                                              << 2U));
    __Vtemp_h8d13807f__0[4U] = ((__Vtemp_ha2597aee__3[3U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__3[4U] 
                                              << 2U));
    __Vtemp_h8d13807f__0[5U] = ((__Vtemp_ha2597aee__3[4U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__3[5U] 
                                              << 2U));
    __Vtemp_h8d13807f__0[6U] = ((__Vtemp_ha2597aee__3[5U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__3[6U] 
                                              << 2U));
    __Vtemp_h8d13807f__0[7U] = ((__Vtemp_ha2597aee__3[6U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__3[7U] 
                                              << 2U));
    __Vtemp_h8d13807f__0[8U] = ((__Vtemp_ha2597aee__3[7U] 
                                 >> 0x1eU) | (__Vtemp_ha2597aee__3[8U] 
                                              << 2U));
    VL_SHIFTR_WWW(260,260,260, __Vtemp_hade0c29d__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes, __Vtemp_h8d13807f__0);
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1603) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__same_cycle_resp))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & 
                                               ((VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
                                                 & __Vtemp_h50b642bb__0[0U]) 
                                                >> 1U)))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & ((VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
                                                      & __Vtemp_h90c56910__0[0U]) 
                                                     >> 1U))))))
                                 : 0U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & ((VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
                                                         & __Vtemp_h11b31c94__0[0U]) 
                                                        >> 1U)))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & ((VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
                                                               & __Vtemp_hade0c29d__0[0U]) 
                                                              >> 1U))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:848: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel contains improper opcode response (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 848, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:849:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:850: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 850, "");
        }
    }
}

extern const VlWide<17>/*543:0*/ VTestHarness__ConstPool__CONST_h00a540f1_0;

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10798(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10798\n"); );
    // Init
    VlWide<17>/*543:0*/ __Vtemp_ha249d9de__0;
    VlWide<17>/*543:0*/ __Vtemp_h4604f902__0;
    VlWide<17>/*543:0*/ __Vtemp_hb7682c11__0;
    // Body
    VL_EXTEND_WI(517,7, __Vtemp_ha249d9de__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source));
    __Vtemp_h4604f902__0[0U] = (__Vtemp_ha249d9de__0[0U] 
                                << 3U);
    __Vtemp_h4604f902__0[1U] = ((__Vtemp_ha249d9de__0[0U] 
                                 >> 0x1dU) | (__Vtemp_ha249d9de__0[1U] 
                                              << 3U));
    __Vtemp_h4604f902__0[2U] = ((__Vtemp_ha249d9de__0[1U] 
                                 >> 0x1dU) | (__Vtemp_ha249d9de__0[2U] 
                                              << 3U));
    __Vtemp_h4604f902__0[3U] = ((__Vtemp_ha249d9de__0[2U] 
                                 >> 0x1dU) | (__Vtemp_ha249d9de__0[3U] 
                                              << 3U));
    __Vtemp_h4604f902__0[4U] = ((__Vtemp_ha249d9de__0[3U] 
                                 >> 0x1dU) | (__Vtemp_ha249d9de__0[4U] 
                                              << 3U));
    __Vtemp_h4604f902__0[5U] = ((__Vtemp_ha249d9de__0[4U] 
                                 >> 0x1dU) | (__Vtemp_ha249d9de__0[5U] 
                                              << 3U));
    __Vtemp_h4604f902__0[6U] = ((__Vtemp_ha249d9de__0[5U] 
                                 >> 0x1dU) | (__Vtemp_ha249d9de__0[6U] 
                                              << 3U));
    __Vtemp_h4604f902__0[7U] = ((__Vtemp_ha249d9de__0[6U] 
                                 >> 0x1dU) | (__Vtemp_ha249d9de__0[7U] 
                                              << 3U));
    __Vtemp_h4604f902__0[8U] = ((__Vtemp_ha249d9de__0[7U] 
                                 >> 0x1dU) | (__Vtemp_ha249d9de__0[8U] 
                                              << 3U));
    __Vtemp_h4604f902__0[9U] = ((__Vtemp_ha249d9de__0[8U] 
                                 >> 0x1dU) | (__Vtemp_ha249d9de__0[9U] 
                                              << 3U));
    __Vtemp_h4604f902__0[0xaU] = ((__Vtemp_ha249d9de__0[9U] 
                                   >> 0x1dU) | (__Vtemp_ha249d9de__0[0xaU] 
                                                << 3U));
    __Vtemp_h4604f902__0[0xbU] = ((__Vtemp_ha249d9de__0[0xaU] 
                                   >> 0x1dU) | (__Vtemp_ha249d9de__0[0xbU] 
                                                << 3U));
    __Vtemp_h4604f902__0[0xcU] = ((__Vtemp_ha249d9de__0[0xbU] 
                                   >> 0x1dU) | (__Vtemp_ha249d9de__0[0xcU] 
                                                << 3U));
    __Vtemp_h4604f902__0[0xdU] = ((__Vtemp_ha249d9de__0[0xcU] 
                                   >> 0x1dU) | (__Vtemp_ha249d9de__0[0xdU] 
                                                << 3U));
    __Vtemp_h4604f902__0[0xeU] = ((__Vtemp_ha249d9de__0[0xdU] 
                                   >> 0x1dU) | (__Vtemp_ha249d9de__0[0xeU] 
                                                << 3U));
    __Vtemp_h4604f902__0[0xfU] = ((__Vtemp_ha249d9de__0[0xeU] 
                                   >> 0x1dU) | (__Vtemp_ha249d9de__0[0xfU] 
                                                << 3U));
    __Vtemp_h4604f902__0[0x10U] = ((__Vtemp_ha249d9de__0[0xfU] 
                                    >> 0x1dU) | (__Vtemp_ha249d9de__0[0x10U] 
                                                 << 3U));
    VL_SHIFTR_WWW(520,520,520, __Vtemp_hb7682c11__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes, __Vtemp_h4604f902__0);
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1603) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__same_cycle_resp))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_size) 
                        != (0x7fU & ((VTestHarness__ConstPool__CONST_h00a540f1_0[0U] 
                                      & __Vtemp_hb7682c11__0[0U]) 
                                     >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:854: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel contains improper response size (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 854, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:855:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:856: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 856, "");
        }
    }
    if (VL_UNLIKELY(((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_1))) 
                          & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__a_first_counter_1))) 
                         & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty))) 
                        & ((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                     >> 0xaU)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                       & (6U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT___portsAOI_in_0_a_ready_WIRE)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:860: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: ready check\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 860, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:861:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:862: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 862, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10799(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10799\n"); );
    // Body
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)) 
                           & (~ (((0U == ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight[0U] 
                                           | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight[1U]) 
                                          | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight[2U])) 
                                  | (0U == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__plusarg_reader__DOT__myplus)) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__watchdog 
                                    < vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__plusarg_reader__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:866: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: TileLink timeout expired (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 866, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:867:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:868: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 868, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_2))) 
                      & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:872: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 872, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:873:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:874: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 874, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10800(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10800\n"); );
    // Body
    if (VL_UNLIKELY((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid) 
                        & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_2))) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:878: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor: Assertion failed: 'D' channel contains improper response size (connected at PeripheryBus.scala:54:7)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 878, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv:879:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_22.sv:880: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.fixer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_22.sv", 880, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                      & (6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:296: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel carries AcquireBlock type which is unexpected using diplomatic parameters (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 296, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:297:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:298: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 298, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10801(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10801\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (((IData)(((0x180U == (0x3c0U 
                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])) 
                                     & ((((((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0xfU 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0xdU))))) 
                                            & (5U > 
                                               (7U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)))) 
                                           | (0x1cU 
                                              == (0x7fU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                          | (0x18U 
                                             == (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                         | (0x14U == 
                                            (0x7fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0xaU)))) 
                                        | (0x10U == 
                                           (0x7fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xaU)))))) 
                            & (0xdU > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 6U)))) 
                           & ((((((((0U == ((0x3fffcU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                << 2U)) 
                                            | (3U & 
                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0x1dU)))) 
                                    | (3U == (0x7ffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  << 3U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0x1dU))))) 
                                   | (1U == (0x7fffU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                >> 1U)))) 
                                  | (0U == ((0x3fff0U 
                                             & (0x80U 
                                                ^ (0xfffffff0U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                      << 2U)))) 
                                            | (0xfU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   << 3U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0x1dU)))))) 
                                 | (0x200U == (0x7fffU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  >> 1U)))) 
                                | (0x2010U == (0x7ffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   << 3U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0x1dU))))) 
                               | (3U == (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  >> 0xbU)))) 
                              | (0x54000U == (0x7ffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  << 3U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0x1dU)))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:302: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 302, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:303:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:304: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 304, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10802(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10802\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:308: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel AcquireBlock carries invalid source ID (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 308, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:309:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:310: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 310, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (2U >= (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                       >> 6U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:314: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 314, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:315:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:316: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 316, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10803(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10803\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           << 0xfU) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0x11U)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 6U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:320: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 320, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:321:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:322: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 322, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (2U < (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                    >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:326: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel AcquireBlock carries invalid grow param (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 326, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:327:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:328: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 328, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10804(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10804\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0xffU != (0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                           >> 0x10U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:332: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 332, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:333:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:334: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 334, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                        >> 0x18U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:338: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel AcquireBlock is corrupt (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 338, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:339:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:340: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 340, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10805(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10805\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                      & (7U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:344: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel carries AcquirePerm type which is unexpected using diplomatic parameters (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 344, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:345:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:346: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 346, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (7U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (((IData)(((0x180U == (0x3c0U 
                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])) 
                                     & ((((((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0xfU 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0xdU))))) 
                                            & (5U > 
                                               (7U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)))) 
                                           | (0x1cU 
                                              == (0x7fU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                          | (0x18U 
                                             == (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                         | (0x14U == 
                                            (0x7fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0xaU)))) 
                                        | (0x10U == 
                                           (0x7fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xaU)))))) 
                            & (0xdU > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 6U)))) 
                           & ((((((((0U == ((0x3fffcU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                << 2U)) 
                                            | (3U & 
                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0x1dU)))) 
                                    | (3U == (0x7ffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  << 3U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0x1dU))))) 
                                   | (1U == (0x7fffU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                >> 1U)))) 
                                  | (0U == ((0x3fff0U 
                                             & (0x80U 
                                                ^ (0xfffffff0U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                      << 2U)))) 
                                            | (0xfU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   << 3U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0x1dU)))))) 
                                 | (0x200U == (0x7fffU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  >> 1U)))) 
                                | (0x2010U == (0x7ffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   << 3U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0x1dU))))) 
                               | (3U == (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  >> 0xbU)))) 
                              | (0x54000U == (0x7ffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  << 3U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0x1dU)))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:350: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel carries AcquirePerm from a client which does not support Probe (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 350, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:351:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:352: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 352, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10806(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10806\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (7U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:356: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel AcquirePerm carries invalid source ID (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 356, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:357:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:358: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 358, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (7U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (2U >= (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                       >> 6U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:362: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 362, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:363:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:364: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 364, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10807(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10807\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (7U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           << 0xfU) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0x11U)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 6U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:368: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 368, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:369:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:370: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 370, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (7U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (2U < (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                    >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:374: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel AcquirePerm carries invalid grow param (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 374, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:375:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:376: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 376, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10808(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10808\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                      & (7U == (0x3fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:380: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 380, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:381:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:382: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 382, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (7U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0xffU != (0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                           >> 0x10U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:386: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 386, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:387:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:388: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 388, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10809(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10809\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (7U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                        >> 0x18U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:392: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel AcquirePerm is corrupt (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 392, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:393:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:394: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 394, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ ((0xdU > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 6U))) 
                           & (((((((((((((((((0x20U 
                                              == (0x7fU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU))) 
                                             | ((~ (IData)(
                                                           (0U 
                                                            != 
                                                            (0xfU 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                >> 0xdU))))) 
                                                & (5U 
                                                   > 
                                                   (7U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 0xaU))))) 
                                            | (5U == 
                                               (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)))) 
                                           | (8U == 
                                              (0x7fU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0xaU)))) 
                                          | (0x1cU 
                                             == (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                         | (0x1dU == 
                                            (0x7fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0xaU)))) 
                                        | (0x1eU == 
                                           (0x7fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xaU)))) 
                                       | (0x18U == 
                                          (0x7fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 0xaU)))) 
                                      | (0x19U == (0x7fU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU)))) 
                                     | (0x1aU == (0x7fU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                    | (0x14U == (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                   | (0x15U == (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)))) 
                                  | (0x16U == (0x7fU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0xaU)))) 
                                 | (0x10U == (0x7fU 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 0xaU)))) 
                                | (0x11U == (0x7fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0xaU)))) 
                               | (0x12U == (0x7fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xaU)))) 
                              | (0x40U == (0x7fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 0xaU))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:398: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel carries Get type which master claims it can't emit (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 398, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:399:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:400: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 400, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10810(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10810\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (((0xdU > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 6U))) 
                            & (3U == (0x7ffffU & ((
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   << 3U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0x1dU))))) 
                           | ((7U > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 6U))) 
                              & (((((((0U == ((0x3fffcU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  << 2U)) 
                                              | (3U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0x1dU)))) 
                                      | (1U == (0x7fffU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   >> 1U)))) 
                                     | (0U == ((0x3fff0U 
                                                & (0x80U 
                                                   ^ 
                                                   (0xfffffff0U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                       << 2U)))) 
                                               | (0xfU 
                                                  & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                      << 3U) 
                                                     | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                        >> 0x1dU)))))) 
                                    | (0x200U == (0x7fffU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                     >> 1U)))) 
                                   | (0x2010U == (0x7ffffU 
                                                  & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                      << 3U) 
                                                     | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                        >> 0x1dU))))) 
                                  | (3U == (0x1fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                             >> 0xbU)))) 
                                 | (0x54000U == (0x7ffffU 
                                                 & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                     << 3U) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 0x1dU))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:404: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel carries Get type which slave claims it can't support (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 404, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:405:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:406: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 406, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10811(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10811\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:410: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel Get carries invalid source ID (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 410, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:411:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:412: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 412, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           << 0xfU) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0x11U)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 6U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:416: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel Get address not aligned to size (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 416, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:417:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:418: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 418, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10812(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10812\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                     >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:422: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel Get carries invalid param (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 422, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:423:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:424: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 424, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                  >> 0x10U)) != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_5) 
                                                   << 7U) 
                                                  | (0x3fff80U 
                                                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_5) 
                                                         << 7U) 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0xaU)))) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_5) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_5) 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                             >> 0x11U)))) 
                                                     << 6U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_4) 
                                                         << 5U) 
                                                        | (0xfffe0U 
                                                           & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_4) 
                                                               << 5U) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0xcU)))) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_4) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_4) 
                                                               & (~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                   >> 0x11U)))) 
                                                           << 4U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_3) 
                                                               << 3U) 
                                                              | (0x3fff8U 
                                                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_3) 
                                                                     << 3U) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0xeU)))) 
                                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_3) 
                                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_3) 
                                                                     & (~ 
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                         >> 0x11U)))) 
                                                                 << 2U) 
                                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_2) 
                                                                     << 1U) 
                                                                    | (0xfffeU 
                                                                       & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_2) 
                                                                           << 1U) 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                             >> 0x10U)))) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_2) 
                                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_2) 
                                                                         & (~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                             >> 0x11U))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:428: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel Get contains invalid mask (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 428, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:429:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:430: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 430, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10813(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10813\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                        >> 0x18U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:434: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel Get is corrupt (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 434, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:435:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:436: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 436, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (0U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (((0xdU > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 6U))) 
                            & (((((((((((((((((0x20U 
                                               == (0x7fU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU))) 
                                              | ((~ (IData)(
                                                            (0U 
                                                             != 
                                                             (0xfU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0xdU))))) 
                                                 & (5U 
                                                    > 
                                                    (7U 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                        >> 0xaU))))) 
                                             | (5U 
                                                == 
                                                (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                            | (8U == 
                                               (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)))) 
                                           | (0x1cU 
                                              == (0x7fU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                          | (0x1dU 
                                             == (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                         | (0x1eU == 
                                            (0x7fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0xaU)))) 
                                        | (0x18U == 
                                           (0x7fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xaU)))) 
                                       | (0x19U == 
                                          (0x7fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 0xaU)))) 
                                      | (0x1aU == (0x7fU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU)))) 
                                     | (0x14U == (0x7fU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                    | (0x15U == (0x7fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                   | (0x16U == (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)))) 
                                  | (0x10U == (0x7fU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0xaU)))) 
                                 | (0x11U == (0x7fU 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 0xaU)))) 
                                | (0x12U == (0x7fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0xaU)))) 
                               | (0x40U == (0x7fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xaU))))) 
                           & (((0xdU > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 6U))) 
                               & (3U == (0x7ffffU & 
                                         ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                           << 3U) | 
                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           >> 0x1dU))))) 
                              | ((7U > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 6U))) 
                                 & ((((((0U == ((0x3fffcU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                    << 2U)) 
                                                | (3U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0x1dU)))) 
                                        | (0U == ((0x3fff0U 
                                                   & (0x80U 
                                                      ^ 
                                                      (0xfffffff0U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                          << 2U)))) 
                                                  | (0xfU 
                                                     & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                         << 3U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0x1dU)))))) 
                                       | (0x200U == 
                                          (0x7fffU 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                              >> 1U)))) 
                                      | (0x2010U == 
                                         (0x7ffffU 
                                          & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                              << 3U) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0x1dU))))) 
                                     | (3U == (0x1fU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  >> 0xbU)))) 
                                    | (0x54000U == 
                                       (0x7ffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                          << 3U) | 
                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                          >> 0x1dU)))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:440: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel carries PutFull type which is unexpected using diplomatic parameters (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 440, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:441:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:442: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 442, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10814(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10814\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (0U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__source_ok))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:446: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel PutFull carries invalid source ID (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 446, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:447:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:448: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 448, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (0U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           << 0xfU) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0x11U)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 6U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:452: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel PutFull address not aligned to size (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 452, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:453:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:454: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 454, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10815(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10815\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (0U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                     >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:458: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel PutFull carries invalid param (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 458, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:459:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:460: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 460, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
                       & (0U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                  >> 0x10U)) != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_5) 
                                                   << 7U) 
                                                  | (0x3fff80U 
                                                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_5) 
                                                         << 7U) 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0xaU)))) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_5) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_5) 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                             >> 0x11U)))) 
                                                     << 6U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_4) 
                                                         << 5U) 
                                                        | (0xfffe0U 
                                                           & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_4) 
                                                               << 5U) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0xcU)))) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_4) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_4) 
                                                               & (~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                   >> 0x11U)))) 
                                                           << 4U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_3) 
                                                               << 3U) 
                                                              | (0x3fff8U 
                                                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_3) 
                                                                     << 3U) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0xeU)))) 
                                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_3) 
                                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_3) 
                                                                     & (~ 
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                         >> 0x11U)))) 
                                                                 << 2U) 
                                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_2) 
                                                                     << 1U) 
                                                                    | (0xfffeU 
                                                                       & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_2) 
                                                                           << 1U) 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                             >> 0x10U)))) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_2) 
                                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_2) 
                                                                         & (~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                             >> 0x11U))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:464: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor: Assertion failed: 'A' channel PutFull contains invalid mask (connected at PeripheryBus.scala:53:7)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 464, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv:465:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_25.sv:466: Assertion failed in %NTestHarness.chiptop.system.subsystem_cbus.out_xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_25.sv", 466, "");
        }
    }
}
