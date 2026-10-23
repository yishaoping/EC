// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness__Syms.h"
#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2209(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2209\n"); );
    // Body
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset)) 
                           & (~ ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT___same_cycle_resp_T_1)
                                    ? (7U & ((IData)(1U) 
                                             << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_source)))
                                    : 0U) != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT___io_deq_valid_output) 
                                                & (0U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__d_first_counter_1))) 
                                               & (6U 
                                                  != 
                                                  (7U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0xdU))))
                                               ? (7U 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (3U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                         >> 5U))))
                                               : 0U)) 
                                 | (0U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT___same_cycle_resp_T_1)
                                            ? (7U & 
                                               ((IData)(1U) 
                                                << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_source)))
                                            : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1469: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor: Assertion failed: 'A' and 'D' concurrent, despite minlatency 5 (connected at CrossingHelper.scala:57:150)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1469, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv:1470:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1471: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1471, "");
        }
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset)) 
                           & (~ (((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__inflight)) 
                                  | (0U == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__plusarg_reader__DOT__myplus)) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__watchdog 
                                    < vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__plusarg_reader__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1475: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor: Assertion failed: TileLink timeout expired (connected at CrossingHelper.scala:57:150)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1475, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv:1476:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1477: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1477, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2210(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2210\n"); );
    // Body
    if (VL_UNLIKELY((7U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT___T_2592) 
                            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__inflight_1) 
                              >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1481: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor: Assertion failed: 'C' channel re-used a source ID (connected at CrossingHelper.scala:57:150)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1481, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv:1482:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1483: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1483, "");
        }
    }
    if (VL_UNLIKELY((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT___io_deq_valid_output) 
                        & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__d_first_counter_2))) 
                       & (0xc000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ ((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__inflight_1) 
                                  >> (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                            >> 5U)))) 
                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT___same_cycle_resp_T_3) 
                               & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode)))) 
                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source) 
                                 == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           >> 5U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1487: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at CrossingHelper.scala:57:150)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1487, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv:1488:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1489: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1489, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2211(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2211\n"); );
    // Body
    if (VL_UNLIKELY(((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT___io_deq_valid_output) 
                         & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__d_first_counter_2))) 
                        & (0xc000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                       & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT___same_cycle_resp_T_3) 
                           & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode)))) 
                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source) 
                             == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                       >> 5U))))) & 
                      (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & ((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                 >> 7U)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1493: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor: Assertion failed: 'D' channel contains improper response size (connected at CrossingHelper.scala:57:150)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1493, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv:1494:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1495: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1495, "");
        }
    }
    if (VL_UNLIKELY(((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT___io_deq_valid_output) 
                         & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__d_first_counter_2))) 
                        & (0xc000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                       & (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT___same_cycle_resp_T_3) 
                              & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode)))) 
                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source) 
                                == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                          >> 5U)))))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & ((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                 >> 7U)) != (0x7fU 
                                             & (((0x17U 
                                                  >= 
                                                  (0x18U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 2U)))
                                                  ? 
                                                 (0xffffffU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__inflight_sizes_1 
                                                     >> 
                                                     (0x18U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                         >> 2U))))
                                                  : 0U) 
                                                >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1499: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor: Assertion failed: 'D' channel contains improper response size (connected at CrossingHelper.scala:57:150)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1499, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv:1500:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1501: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1501, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2212(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2212\n"); );
    // Body
    if (VL_UNLIKELY((((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT___io_deq_valid_output) 
                            & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__d_first_counter_2))) 
                           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__c_first_counter_1))) 
                          & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_valid)) 
                         & (0xc000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source) 
                           == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     >> 5U)))) & (~ 
                                                  ((4U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode)) 
                                                   | (5U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode))))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_d_ready)) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT___io_enq_ready_output)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1505: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor: Assertion failed: ready check\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1505, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv:1506:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1507: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1507, "");
        }
    }
    if (VL_UNLIKELY((((0U != (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT___same_cycle_resp_T_3) 
                               & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode))))
                               ? (7U & ((IData)(1U) 
                                        << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source)))
                               : 0U)) & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT___same_cycle_resp_T_3) 
                          & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode))))
                          ? (7U & ((IData)(1U) << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source)))
                          : 0U) == ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT___io_deq_valid_output) 
                                      & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__d_first_counter_2))) 
                                     & (0xc000U == 
                                        (0xe000U & 
                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])))
                                     ? (7U & ((IData)(1U) 
                                              << (3U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 5U))))
                                     : 0U))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1511: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor: Assertion failed: 'C' and 'D' concurrent, despite minlatency 5 (connected at CrossingHelper.scala:57:150)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1511, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv:1512:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1513: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1513, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2213(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2213\n"); );
    // Body
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset)) 
                           & (~ (((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__inflight_1)) 
                                  | (0U == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus)) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__watchdog_1 
                                    < vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__plusarg_reader_1__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1517: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor: Assertion failed: TileLink timeout expired (connected at CrossingHelper.scala:57:150)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1517, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv:1518:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1519: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1519, "");
        }
    }
    if (VL_UNLIKELY((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT___T_2653) 
                        & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__d_first_counter_3))) 
                       & (0x8000U == (0xc000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & ((7U >= (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                      >> 2U))) ? (0xffU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__inflight_2) 
                                                     >> 
                                                     (7U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                         >> 2U))))
                         : 0U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1523: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor: Assertion failed: 'D' channel re-used a sink ID (connected at CrossingHelper.scala:57:150)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1523, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv:1524:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1525: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1525, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2214(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2214\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT___io_enq_ready_output) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_e_valid)) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ ((7U >= (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 2U))) ? 
                           (0xffU & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__d_set) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__inflight_2)) 
                                     >> (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                               >> 2U))))
                            : 0U))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1529: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor: Assertion failed: 'E' channel acknowledged for nothing inflight (connected at CrossingHelper.scala:57:150)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1529, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv:1530:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_57.sv:1531: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.asource.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_57.sv", 1531, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ (((0xdU > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                            & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))) 
                           & (((2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                       >> 0x10U)) | 
                               (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                             >> 0xcU))) 
                              | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                        >> 0x1cU)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:424: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel carries AcquireBlock type which is unexpected using diplomatic parameters (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 424, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:425:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:426: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 426, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2215(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2215\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_source)) 
                             & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))) 
                            & (0xdU > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))) 
                           & (((((((((((0U == ((0x7fffcU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                   >> 0xdU)) 
                                               | (3U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                     >> 0xcU)))) 
                                       | (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                 >> 0xcU))) 
                                      | (1U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                >> 0x10U))) 
                                     | (2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                               >> 0x10U))) 
                                    | (0U == ((0x7fff0U 
                                               & (0x80U 
                                                  ^ 
                                                  (0x7fff0U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                      >> 0xdU)))) 
                                              | (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                    >> 0xcU))))) 
                                   | (0x200U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                 >> 0x10U))) 
                                  | (0x2010U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                 >> 0xcU))) 
                                 | (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                           >> 0x1aU))) 
                                | (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                >> 0xcU))) 
                               | (0x54000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                               >> 0xcU))) 
                              | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                        >> 0x1cU)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:430: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 430, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:431:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:432: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 432, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2216(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2216\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (2U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:436: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 436, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:437:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:438: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 438, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (0xfffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                         & (~ ((0x1aU 
                                                >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:442: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 442, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:443:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:444: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 444, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2217(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2217\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (2U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:448: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel AcquireBlock carries invalid grow param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 448, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:449:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:450: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 450, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0xffU != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_mask))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:454: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 454, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:455:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:456: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 456, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2218(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2218\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ (((0xdU > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                            & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))) 
                           & (((2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                       >> 0x10U)) | 
                               (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                             >> 0xcU))) 
                              | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                        >> 0x1cU)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:460: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel carries AcquirePerm type which is unexpected using diplomatic parameters (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 460, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:461:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:462: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 462, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_source)) 
                             & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))) 
                            & (0xdU > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))) 
                           & (((((((((((0U == ((0x7fffcU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                   >> 0xdU)) 
                                               | (3U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                     >> 0xcU)))) 
                                       | (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                 >> 0xcU))) 
                                      | (1U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                >> 0x10U))) 
                                     | (2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                               >> 0x10U))) 
                                    | (0U == ((0x7fff0U 
                                               & (0x80U 
                                                  ^ 
                                                  (0x7fff0U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                      >> 0xdU)))) 
                                              | (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                    >> 0xcU))))) 
                                   | (0x200U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                 >> 0x10U))) 
                                  | (0x2010U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                 >> 0xcU))) 
                                 | (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                           >> 0x1aU))) 
                                | (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                >> 0xcU))) 
                               | (0x54000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                               >> 0xcU))) 
                              | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                        >> 0x1cU)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:466: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel carries AcquirePerm from a client which does not support Probe (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 466, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:467:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:468: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 468, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2219(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2219\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (2U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:472: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 472, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:473:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:474: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 474, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (0xfffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                         & (~ ((0x1aU 
                                                >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:478: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 478, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:479:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:480: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 480, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2220(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2220\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (2U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:484: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel AcquirePerm carries invalid grow param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 484, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:485:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:486: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 486, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:490: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 490, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:491:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:492: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 492, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2221(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2221\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0xffU != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_mask))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:496: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 496, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:497:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:498: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 498, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0xdU <= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:502: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel carries Get type which master claims it can't emit (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 502, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:503:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:504: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 504, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2222(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2222\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ (((0xdU > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                            & (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                      >> 0xcU))) | 
                           ((7U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                            & ((((((((((0U == ((0x7fffcU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                   >> 0xdU)) 
                                               | (3U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                     >> 0xcU)))) 
                                       | (1U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                 >> 0x10U))) 
                                      | (2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                >> 0x10U))) 
                                     | (0U == ((0x7fff0U 
                                                & (0x80U 
                                                   ^ 
                                                   (0x7fff0U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                       >> 0xdU)))) 
                                               | (0xfU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                     >> 0xcU))))) 
                                    | (0x200U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                  >> 0x10U))) 
                                   | (0x2010U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                  >> 0xcU))) 
                                  | (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                            >> 0x1aU))) 
                                 | (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                 >> 0xcU))) 
                                | (0x54000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                >> 0xcU))) 
                               | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                         >> 0x1cU))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:508: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel carries Get type which slave claims it can't support (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 508, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:509:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:510: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 510, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2223(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2223\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (0xfffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                         & (~ ((0x1aU 
                                                >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:514: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel Get address not aligned to size (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 514, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:515:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:516: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 516, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:520: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel Get carries invalid param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 520, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:521:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:522: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 522, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2224(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2224\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:526: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel Get contains invalid mask (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 526, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:527:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:528: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 528, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2225(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2225\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ ((0xdU > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                           & (((0xdU > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                               & (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                         >> 0xcU))) 
                              | ((7U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                                 & ((((((((0U == ((0x7fffcU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                      >> 0xdU)) 
                                                  | (3U 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                        >> 0xcU)))) 
                                          | (0U == 
                                             ((0x7fff0U 
                                               & (0x80U 
                                                  ^ 
                                                  (0x7fff0U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                      >> 0xdU)))) 
                                              | (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                    >> 0xcU))))) 
                                         | (0x200U 
                                            == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                >> 0x10U))) 
                                        | (0x2010U 
                                           == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                               >> 0xcU))) 
                                       | (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                 >> 0x1aU))) 
                                      | (0x10000U == 
                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                          >> 0xcU))) 
                                     | (0x54000U == 
                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                         >> 0xcU))) 
                                    | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                              >> 0x1cU)))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:532: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel carries PutFull type which is unexpected using diplomatic parameters (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 532, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:533:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:534: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 534, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2226(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2226\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (0xfffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                         & (~ ((0x1aU 
                                                >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:538: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel PutFull address not aligned to size (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 538, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:539:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:540: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 540, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:544: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel PutFull carries invalid param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 544, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:545:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:546: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 546, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2227(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2227\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:550: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel PutFull contains invalid mask (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 550, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:551:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:552: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 552, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2228(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2228\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ ((0xdU > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                           & (((0xdU > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                               & (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                         >> 0xcU))) 
                              | ((7U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                                 & ((((((((0U == ((0x7fffcU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                      >> 0xdU)) 
                                                  | (3U 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                        >> 0xcU)))) 
                                          | (0U == 
                                             ((0x7fff0U 
                                               & (0x80U 
                                                  ^ 
                                                  (0x7fff0U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                      >> 0xdU)))) 
                                              | (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                    >> 0xcU))))) 
                                         | (0x200U 
                                            == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                >> 0x10U))) 
                                        | (0x2010U 
                                           == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                               >> 0xcU))) 
                                       | (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                 >> 0x1aU))) 
                                      | (0x10000U == 
                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                          >> 0xcU))) 
                                     | (0x54000U == 
                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                         >> 0xcU))) 
                                    | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                              >> 0x1cU)))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:556: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel carries PutPartial type which is unexpected using diplomatic parameters (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 556, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:557:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:558: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 558, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2229(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2229\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (0xfffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                         & (~ ((0x1aU 
                                                >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:562: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel PutPartial address not aligned to size (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 562, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:563:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:564: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 564, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:568: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel PutPartial carries invalid param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 568, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:569:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:570: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 570, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2230(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2230\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_mask) 
                               & (~ ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                          & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                      << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                                     & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                 << 6U) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                    << 5U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                           & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                       << 4U) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                          << 3U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                                 & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                             << 2U) 
                                                            | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                                << 1U) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                     & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:574: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel PutPartial contains invalid mask (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 574, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:575:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:576: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 576, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2231(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2231\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ (((0xdU > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                            & (4U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))) 
                           & (((((((((0U == ((0x7fffcU 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                 >> 0xdU)) 
                                             | (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                   >> 0xcU)))) 
                                     | (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                               >> 0xcU))) 
                                    | (0U == ((0x7fff0U 
                                               & (0x80U 
                                                  ^ 
                                                  (0x7fff0U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                      >> 0xdU)))) 
                                              | (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                    >> 0xcU))))) 
                                   | (0x200U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                 >> 0x10U))) 
                                  | (0x2010U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                 >> 0xcU))) 
                                 | (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                           >> 0x1aU))) 
                                | (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                >> 0xcU))) 
                               | (0x54000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                               >> 0xcU))) 
                              | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                        >> 0x1cU)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:580: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel carries Arithmetic type which is unexpected using diplomatic parameters (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 580, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:581:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:582: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 582, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2232(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2232\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (0xfffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                         & (~ ((0x1aU 
                                                >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:586: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 586, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:587:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:588: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 588, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (4U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:592: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel Arithmetic carries invalid opcode param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 592, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:593:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:594: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 594, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2233(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2233\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:598: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 598, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:599:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:600: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 600, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2234(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2234\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ (((0xdU > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                            & (4U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))) 
                           & (((((((((0U == ((0x7fffcU 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                 >> 0xdU)) 
                                             | (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                   >> 0xcU)))) 
                                     | (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                               >> 0xcU))) 
                                    | (0U == ((0x7fff0U 
                                               & (0x80U 
                                                  ^ 
                                                  (0x7fff0U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                      >> 0xdU)))) 
                                              | (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                    >> 0xcU))))) 
                                   | (0x200U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                 >> 0x10U))) 
                                  | (0x2010U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                 >> 0xcU))) 
                                 | (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                           >> 0x1aU))) 
                                | (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                                >> 0xcU))) 
                               | (0x54000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                               >> 0xcU))) 
                              | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                        >> 0x1cU)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:604: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel carries Logical type which is unexpected using diplomatic parameters (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 604, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:605:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:606: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 606, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2235(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2235\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (0xfffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                         & (~ ((0x1aU 
                                                >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:610: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel Logical address not aligned to size (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 610, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:611:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:612: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 612, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_param) 
                        >> 2U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:616: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel Logical carries invalid opcode param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 616, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:617:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:618: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 618, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2236(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2236\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:622: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel Logical contains invalid mask (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 622, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:623:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:624: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 624, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2237(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2237\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ ((0xdU > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                           & (((0xdU > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                               & (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                         >> 0xcU))) 
                              | ((7U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                                 & (((2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                             >> 0x10U)) 
                                     | (0x10000U == 
                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                         >> 0xcU))) 
                                    | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                              >> 0x1cU)))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:628: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel carries Hint type which is unexpected using diplomatic parameters (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 628, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:629:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:630: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 630, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (0xfffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address 
                                         & (~ ((0x1aU 
                                                >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:634: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel Hint address not aligned to size (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 634, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:635:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:636: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 636, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2238(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2238\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_param) 
                                     >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:640: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel Hint carries invalid opcode param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 640, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:641:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:642: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 642, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:646: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'A' channel Hint contains invalid mask (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 646, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:647:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:648: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 648, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2239(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2239\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0xe000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:652: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel has invalid opcode (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 652, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:653:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:654: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 654, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                       & (0xc000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (3U > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                      >> 7U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:658: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel ReleaseAck smaller than a beat (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 658, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:659:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:660: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 660, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2240(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2240\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                       & (0xc000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     >> 0xbU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:664: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel ReleaseeAck carries invalid param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 664, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:665:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:666: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 666, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                       & (0xc000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:670: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel ReleaseAck is corrupt (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 670, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:671:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:672: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 672, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2241(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2241\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                      & (0xc002U == (0xe002U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:676: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel ReleaseAck is denied (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 676, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:677:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:678: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 678, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                       & (0x8000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (3U > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                      >> 7U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:682: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel Grant smaller than a beat (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 682, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:683:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:684: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 684, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2242(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2242\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                      & (0x9800U == (0xf800U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:688: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel Grant carries invalid cap param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 688, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:689:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:690: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 690, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                      & (0x9000U == (0xf800U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:694: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel Grant carries toN param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 694, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:695:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:696: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 696, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2243(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2243\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                       & (0x8000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:700: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel Grant is corrupt (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 700, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:701:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:702: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 702, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                       & (0xa000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (3U > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                      >> 7U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:706: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel GrantData smaller than a beat (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 706, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:707:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:708: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 708, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2244(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2244\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                      & (0xb800U == (0xf800U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:712: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel GrantData carries invalid cap param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 712, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:713:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:714: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 714, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                      & (0xb000U == (0xf800U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:718: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel GrantData carries toN param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 718, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:719:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:720: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 720, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2245(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2245\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                       & (0xa000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                               >> 1U)) | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:724: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel GrantData is denied but not corrupt (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 724, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:725:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:726: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 726, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                       & (0U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     >> 0xbU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:730: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel AccessAck carries invalid param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 730, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:731:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:732: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 732, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2246(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2246\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                       & (0U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:736: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel AccessAck is corrupt (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 736, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:737:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:738: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 738, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                       & (0x2000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     >> 0xbU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:742: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel AccessAckData carries invalid param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 742, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:743:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:744: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 744, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2247(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2247\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                       & (0x2000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                               >> 1U)) | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:748: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel AccessAckData is denied but not corrupt (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 748, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:749:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:750: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 750, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                       & (0x4000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     >> 0xbU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:754: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel HintAck carries invalid param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 754, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:755:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:756: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 756, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2248(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2248\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid) 
                       & (0x4000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:760: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'D' channel HintAck is corrupt (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 760, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:761:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:762: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 762, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0xe0000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:766: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel has invalid opcode (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 766, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:767:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:768: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 768, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2249(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2249\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0xc0000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ (((IData)((0x3000U == (0x7a00U 
                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                            & (0xdU > (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               >> 0xbU)))) 
                           & (((((((((((0U == ((0x7fffcU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0xaU) 
                                                   | (0x3fcU 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                         >> 0x16U)))) 
                                               | (3U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x15U)))) 
                                       | (3U == (0xfffffU 
                                                 & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                     << 0xbU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                       >> 0x15U))))) 
                                      | (1U == (0xffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 7U) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x19U))))) 
                                     | (2U == (0xffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 7U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x19U))))) 
                                    | (0U == ((0x7fff0U 
                                               & (0x80U 
                                                  ^ 
                                                  ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0xaU) 
                                                   | (0x3f0U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                         >> 0x16U))))) 
                                              | (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 0x15U))))) 
                                   | (0x200U == (0xffffU 
                                                 & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                     << 7U) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                       >> 0x19U))))) 
                                  | (0x2010U == (0xfffffU 
                                                 & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                     << 0xbU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                       >> 0x15U))))) 
                                 | (3U == (0x3fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            >> 3U)))) 
                                | (0x10000U == (0xfffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0xbU) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x15U))))) 
                               | (0x54000U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0xbU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x15U))))) 
                              | (8U == (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                >> 5U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:772: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel carries Probe type which is unexpected using diplomatic parameters (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 772, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:773:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:774: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 774, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2250(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2250\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0xc0000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ (((((((((((((3U == (0xfffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                  << 0xbU) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 0x15U)))) 
                                      | (0x2010U == 
                                         (0xfffffU 
                                          & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                              << 0xbU) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 0x15U))))) 
                                     | (4U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0xbU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x15U))))) 
                                    | (0x54000U == 
                                       (0xfffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          << 0xbU) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                            >> 0x15U))))) 
                                   | (3U == (0x3fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                >> 3U)))) 
                                  | (0x200U == (0xffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 7U) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x19U))))) 
                                 | (0U == (0xfffffU 
                                           & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               << 0xbU) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 0x15U))))) 
                                | (1U == (0xffffU & 
                                          ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            << 7U) 
                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0x19U))))) 
                               | (0x100U == (0xfffffU 
                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 0xbU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x15U))))) 
                              | (0x110U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0xbU) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x15U))))) 
                             | (8U == (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               >> 5U)))) 
                            | (0x10000U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0xbU) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x15U))))) 
                           | (2U == (0xffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 7U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x19U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:778: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel Probe carries unmanaged address (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 778, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:779:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:780: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 780, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2251(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2251\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0xc0000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           << 0x17U) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                             >> 9U)) 
                                         & (~ (0x7ffffffU 
                                               & ((IData)(0xfffU) 
                                                  << 
                                                  (0xfU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                      >> 0xbU))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:784: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel Probe address not aligned to size (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 784, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:785:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:786: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 786, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                      & (0xd8000U == (0xf8000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:790: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel Probe carries invalid cap param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 790, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:791:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:792: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 792, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2252(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2252\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0xc0000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                  >> 1U)) != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                                << 7U) 
                                               | (0x3fffff80U 
                                                  & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                                      << 7U) 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                        >> 2U)))) 
                                              | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                                      & (~ 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                          >> 9U)))) 
                                                  << 6U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                      << 5U) 
                                                     | (0xfffffe0U 
                                                        & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                            << 5U) 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                              >> 4U)))) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                            & (~ 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                >> 9U)))) 
                                                        << 4U) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                            << 3U) 
                                                           | (0x3fffff8U 
                                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                                  << 3U) 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                    >> 6U)))) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                      >> 9U)))) 
                                                              << 2U) 
                                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                                  << 1U) 
                                                                 | (0xfffffeU 
                                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                        << 1U) 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                          >> 8U)))) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                      & (~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                          >> 9U))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:796: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel Probe contains invalid mask (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 796, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:797:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:798: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 798, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2253(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2253\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0xc0000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:802: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel Probe is corrupt (connected at HellaCache.scala:269:21)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 802, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:803:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:804: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 804, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                      & (0x80000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:808: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel carries Get type which is unexpected using diplomatic parameters (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 808, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:809:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:810: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 810, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2254(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2254\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0x80000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ (((((((((((((3U == (0xfffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                  << 0xbU) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 0x15U)))) 
                                      | (0x2010U == 
                                         (0xfffffU 
                                          & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                              << 0xbU) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 0x15U))))) 
                                     | (4U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0xbU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x15U))))) 
                                    | (0x54000U == 
                                       (0xfffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          << 0xbU) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                            >> 0x15U))))) 
                                   | (3U == (0x3fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                >> 3U)))) 
                                  | (0x200U == (0xffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 7U) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x19U))))) 
                                 | (0U == (0xfffffU 
                                           & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               << 0xbU) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 0x15U))))) 
                                | (1U == (0xffffU & 
                                          ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            << 7U) 
                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0x19U))))) 
                               | (0x100U == (0xfffffU 
                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 0xbU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x15U))))) 
                              | (0x110U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0xbU) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x15U))))) 
                             | (8U == (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               >> 5U)))) 
                            | (0x10000U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0xbU) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x15U))))) 
                           | (2U == (0xffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 7U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x19U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:814: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel Get carries unmanaged address (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 814, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:815:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:816: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 816, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2255(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2255\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0x80000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           << 0x17U) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                             >> 9U)) 
                                         & (~ (0x7ffffffU 
                                               & ((IData)(0xfffU) 
                                                  << 
                                                  (0xfU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                      >> 0xbU))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:820: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel Get address not aligned to size (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 820, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:821:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:822: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 822, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0x80000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                     >> 0xfU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:826: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel Get carries invalid param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 826, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:827:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:828: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 828, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2256(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2256\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0x80000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                  >> 1U)) != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                                << 7U) 
                                               | (0x3fffff80U 
                                                  & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                                      << 7U) 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                        >> 2U)))) 
                                              | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                                      & (~ 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                          >> 9U)))) 
                                                  << 6U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                      << 5U) 
                                                     | (0xfffffe0U 
                                                        & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                            << 5U) 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                              >> 4U)))) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                            & (~ 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                >> 9U)))) 
                                                        << 4U) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                            << 3U) 
                                                           | (0x3fffff8U 
                                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                                  << 3U) 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                    >> 6U)))) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                      >> 9U)))) 
                                                              << 2U) 
                                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                                  << 1U) 
                                                                 | (0xfffffeU 
                                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                        << 1U) 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                          >> 8U)))) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                      & (~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                          >> 9U))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:832: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel Get contains invalid mask (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 832, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:833:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:834: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 834, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2257(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2257\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0x80000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:838: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel Get is corrupt (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 838, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:839:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:840: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 840, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                      & (0U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:844: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel carries PutFull type which is unexpected using diplomatic parameters (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 844, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:845:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:846: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 846, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2258(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2258\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ (((((((((((((3U == (0xfffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                  << 0xbU) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 0x15U)))) 
                                      | (0x2010U == 
                                         (0xfffffU 
                                          & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                              << 0xbU) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 0x15U))))) 
                                     | (4U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0xbU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x15U))))) 
                                    | (0x54000U == 
                                       (0xfffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          << 0xbU) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                            >> 0x15U))))) 
                                   | (3U == (0x3fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                >> 3U)))) 
                                  | (0x200U == (0xffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 7U) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x19U))))) 
                                 | (0U == (0xfffffU 
                                           & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               << 0xbU) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 0x15U))))) 
                                | (1U == (0xffffU & 
                                          ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            << 7U) 
                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0x19U))))) 
                               | (0x100U == (0xfffffU 
                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 0xbU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x15U))))) 
                              | (0x110U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0xbU) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x15U))))) 
                             | (8U == (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               >> 5U)))) 
                            | (0x10000U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0xbU) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x15U))))) 
                           | (2U == (0xffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 7U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x19U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:850: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel PutFull carries unmanaged address (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 850, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:851:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:852: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 852, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2259(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2259\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           << 0x17U) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                             >> 9U)) 
                                         & (~ (0x7ffffffU 
                                               & ((IData)(0xfffU) 
                                                  << 
                                                  (0xfU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                      >> 0xbU))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:856: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel PutFull address not aligned to size (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 856, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:857:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:858: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 858, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                     >> 0xfU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:862: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel PutFull carries invalid param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 862, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:863:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:864: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 864, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2260(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2260\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                  >> 1U)) != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                                << 7U) 
                                               | (0x3fffff80U 
                                                  & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                                      << 7U) 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                        >> 2U)))) 
                                              | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                                      & (~ 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                          >> 9U)))) 
                                                  << 6U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                      << 5U) 
                                                     | (0xfffffe0U 
                                                        & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                            << 5U) 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                              >> 4U)))) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                            & (~ 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                >> 9U)))) 
                                                        << 4U) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                            << 3U) 
                                                           | (0x3fffff8U 
                                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                                  << 3U) 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                    >> 6U)))) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                      >> 9U)))) 
                                                              << 2U) 
                                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                                  << 1U) 
                                                                 | (0xfffffeU 
                                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                        << 1U) 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                          >> 8U)))) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                      & (~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                          >> 9U))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:868: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel PutFull contains invalid mask (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 868, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:869:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:870: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 870, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2261(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2261\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                      & (0x20000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:874: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel carries PutPartial type which is unexpected using diplomatic parameters (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 874, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:875:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:876: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 876, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0x20000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ (((((((((((((3U == (0xfffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                  << 0xbU) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 0x15U)))) 
                                      | (0x2010U == 
                                         (0xfffffU 
                                          & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                              << 0xbU) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 0x15U))))) 
                                     | (4U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0xbU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x15U))))) 
                                    | (0x54000U == 
                                       (0xfffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          << 0xbU) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                            >> 0x15U))))) 
                                   | (3U == (0x3fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                >> 3U)))) 
                                  | (0x200U == (0xffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 7U) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x19U))))) 
                                 | (0U == (0xfffffU 
                                           & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               << 0xbU) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 0x15U))))) 
                                | (1U == (0xffffU & 
                                          ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            << 7U) 
                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0x19U))))) 
                               | (0x100U == (0xfffffU 
                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 0xbU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x15U))))) 
                              | (0x110U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0xbU) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x15U))))) 
                             | (8U == (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               >> 5U)))) 
                            | (0x10000U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0xbU) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x15U))))) 
                           | (2U == (0xffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 7U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x19U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:880: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel PutPartial carries unmanaged address (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 880, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:881:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:882: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 882, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2262(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2262\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0x20000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           << 0x17U) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                             >> 9U)) 
                                         & (~ (0x7ffffffU 
                                               & ((IData)(0xfffU) 
                                                  << 
                                                  (0xfU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                      >> 0xbU))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:886: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel PutPartial address not aligned to size (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 886, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:887:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:888: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 888, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0x20000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                     >> 0xfU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:892: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel PutPartial carries invalid param (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 892, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:893:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:894: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 894, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2263(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2263\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0x20000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (0xffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                          << 0x1fU) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                            >> 1U)) 
                                        & (~ ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                                << 7U) 
                                               | (0x3fffff80U 
                                                  & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                                      << 7U) 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                        >> 2U)))) 
                                              | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                                      & (~ 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                          >> 9U)))) 
                                                  << 6U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                      << 5U) 
                                                     | (0xfffffe0U 
                                                        & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                            << 5U) 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                              >> 4U)))) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                            & (~ 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                >> 9U)))) 
                                                        << 4U) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                            << 3U) 
                                                           | (0x3fffff8U 
                                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                                  << 3U) 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                    >> 6U)))) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                      >> 9U)))) 
                                                              << 2U) 
                                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                                  << 1U) 
                                                                 | (0xfffffeU 
                                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                        << 1U) 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                          >> 8U)))) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                      & (~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                          >> 9U)))))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:898: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel PutPartial contains invalid mask (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 898, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:899:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:900: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 900, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2264(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2264\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                      & (0x40000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:904: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel carries Arithmetic type unsupported by master (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 904, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:905:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:906: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 906, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0x40000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ (((((((((((((3U == (0xfffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                  << 0xbU) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 0x15U)))) 
                                      | (0x2010U == 
                                         (0xfffffU 
                                          & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                              << 0xbU) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 0x15U))))) 
                                     | (4U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0xbU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x15U))))) 
                                    | (0x54000U == 
                                       (0xfffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          << 0xbU) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                            >> 0x15U))))) 
                                   | (3U == (0x3fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                >> 3U)))) 
                                  | (0x200U == (0xffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 7U) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x19U))))) 
                                 | (0U == (0xfffffU 
                                           & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               << 0xbU) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 0x15U))))) 
                                | (1U == (0xffffU & 
                                          ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            << 7U) 
                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0x19U))))) 
                               | (0x100U == (0xfffffU 
                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 0xbU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x15U))))) 
                              | (0x110U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0xbU) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x15U))))) 
                             | (8U == (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               >> 5U)))) 
                            | (0x10000U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0xbU) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x15U))))) 
                           | (2U == (0xffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 7U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x19U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:910: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel Arithmetic carries unmanaged address (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 910, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:911:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:912: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 912, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2265(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2265\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0x40000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           << 0x17U) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                             >> 9U)) 
                                         & (~ (0x7ffffffU 
                                               & ((IData)(0xfffU) 
                                                  << 
                                                  (0xfU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                      >> 0xbU))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:916: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel Arithmetic address not aligned to size (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 916, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:917:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:918: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 918, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0x40000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                  >> 1U)) != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                                << 7U) 
                                               | (0x3fffff80U 
                                                  & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                                      << 7U) 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                        >> 2U)))) 
                                              | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                                      & (~ 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                          >> 9U)))) 
                                                  << 6U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                      << 5U) 
                                                     | (0xfffffe0U 
                                                        & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                            << 5U) 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                              >> 4U)))) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                            & (~ 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                >> 9U)))) 
                                                        << 4U) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                            << 3U) 
                                                           | (0x3fffff8U 
                                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                                  << 3U) 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                    >> 6U)))) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                      >> 9U)))) 
                                                              << 2U) 
                                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                                  << 1U) 
                                                                 | (0xfffffeU 
                                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                        << 1U) 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                          >> 8U)))) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                      & (~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                          >> 9U))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:922: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel Arithmetic contains invalid mask (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 922, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:923:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:924: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 924, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2266(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2266\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                      & (0x60000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:928: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel carries Logical type unsupported by client (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 928, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:929:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:930: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 930, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0x60000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (~ (((((((((((((3U == (0xfffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                  << 0xbU) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 0x15U)))) 
                                      | (0x2010U == 
                                         (0xfffffU 
                                          & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                              << 0xbU) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 0x15U))))) 
                                     | (4U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 0xbU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x15U))))) 
                                    | (0x54000U == 
                                       (0xfffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          << 0xbU) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                            >> 0x15U))))) 
                                   | (3U == (0x3fU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                >> 3U)))) 
                                  | (0x200U == (0xffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 7U) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x19U))))) 
                                 | (0U == (0xfffffU 
                                           & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               << 0xbU) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 0x15U))))) 
                                | (1U == (0xffffU & 
                                          ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            << 7U) 
                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0x19U))))) 
                               | (0x100U == (0xfffffU 
                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 0xbU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x15U))))) 
                              | (0x110U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0xbU) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x15U))))) 
                             | (8U == (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               >> 5U)))) 
                            | (0x10000U == (0xfffffU 
                                            & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                << 0xbU) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 0x15U))))) 
                           | (2U == (0xffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                 << 7U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0x19U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:934: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel Logical carries unmanaged address (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 934, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:935:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:936: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 936, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__2267(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__2267\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0x60000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           << 0x17U) 
                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                             >> 9U)) 
                                         & (~ (0x7ffffffU 
                                               & ((IData)(0xfffU) 
                                                  << 
                                                  (0xfU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                      >> 0xbU))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:940: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel Logical address not aligned to size (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 940, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:941:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:942: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 942, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid) 
                       & (0x60000U == (0xe0000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                  >> 1U)) != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                                << 7U) 
                                               | (0x3fffff80U 
                                                  & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                                      << 7U) 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                        >> 2U)))) 
                                              | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                                      & (~ 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                          >> 9U)))) 
                                                  << 6U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                      << 5U) 
                                                     | (0xfffffe0U 
                                                        & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                            << 5U) 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                              >> 4U)))) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                            & (~ 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                >> 9U)))) 
                                                        << 4U) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                            << 3U) 
                                                           | (0x3fffff8U 
                                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                                  << 3U) 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                    >> 6U)))) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                      >> 9U)))) 
                                                              << 2U) 
                                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                                  << 1U) 
                                                                 | (0xfffffeU 
                                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                        << 1U) 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                          >> 8U)))) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                      & (~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                          >> 9U))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:946: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor: Assertion failed: 'B' channel Logical contains invalid mask (connected at HellaCache.scala:269:21)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 946, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv:947:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_55.sv:948: Assertion failed in %NTestHarness.chiptop.system.tile_prci_domain_2.tile_reset_domain_tile.tlMasterXbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_55.sv", 948, "");
        }
    }
}
