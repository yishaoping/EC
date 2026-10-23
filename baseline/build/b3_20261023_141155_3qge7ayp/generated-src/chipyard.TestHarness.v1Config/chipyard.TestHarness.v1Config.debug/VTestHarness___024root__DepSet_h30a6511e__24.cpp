// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness__Syms.h"
#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9047(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9047\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:754: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'D' channel HintAck carries invalid param (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 754, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:755:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:756: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 756, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                        >> 0xeU)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:760: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'D' channel HintAck is corrupt (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 760, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:761:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:762: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 762, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9048(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9048\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x2002U == (0x2007U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:766: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'D' channel HintAck is denied (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 766, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:767:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:768: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 768, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__a_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__opcode))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:772: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'A' channel opcode changed within multibeat operation (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 772, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:773:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:774: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 774, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9049(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9049\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__a_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_param) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:778: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'A' channel param changed within multibeat operation (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 778, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:779:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:780: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 780, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__a_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:784: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'A' channel size changed within multibeat operation (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 784, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:785:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:786: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 786, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9050(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9050\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__a_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:790: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'A' channel source changed within multibeat operation (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 790, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:791:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:792: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 792, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__a_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((0x1fffffffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address) 
                        != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__address)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:796: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'A' channel address changed with multibeat operation (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 796, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:797:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:798: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 798, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9051(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9051\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__opcode_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:802: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'D' channel opcode changed within multibeat operation (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 802, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:803:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:804: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 804, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                               >> 3U)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__param_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:808: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'D' channel param changed within multibeat operation (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 808, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:809:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:810: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 810, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9052(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9052\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                               >> 5U)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__size_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:814: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'D' channel size changed within multibeat operation (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 814, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:815:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:816: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 816, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                 >> 8U)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__source_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:820: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'D' channel source changed within multibeat operation (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 820, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:821:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:822: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 822, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9053(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9053\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                               >> 0xcU)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__sink))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:826: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'D' channel sink changed with multibeat operation (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 826, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:827:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:828: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 828, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                               >> 0xdU)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__denied))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:832: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'D' channel denied changed with multibeat operation (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 832, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:833:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:834: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 834, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9054(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9054\n"); );
    // Body
    if (VL_UNLIKELY((0x3ffU & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT___T_662) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__inflight) 
                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:838: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'A' channel re-used a source ID (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 838, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:839:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:840: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 840, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT___T_681) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((9U >= (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                            >> 8U)))
                             ? (0x3ffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__inflight) 
                                          >> (0xfU 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 8U))))
                             : 0U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__same_cycle_resp)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:844: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 844, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:845:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:846: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 846, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9055(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9055\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT___T_681) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__same_cycle_resp)) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode)))))
                                 : 0U)) | ((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode)))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:850: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'D' channel contains improper opcode response (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 850, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:851:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:852: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 852, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9056(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9056\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT___T_681) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__same_cycle_resp)) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size) 
                        != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                  >> 5U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:856: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'D' channel contains improper response size (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 856, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:857:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:858: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 858, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT___T_681) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__same_cycle_resp))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (((0x27ULL 
                                                               >= 
                                                               ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                << 2U))
                                                               ? 
                                                              (0xffffffffffULL 
                                                               & VL_SHIFTR_QQQ(40,40,40, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__inflight_opcodes, 
                                                                               ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                                << 2U)))
                                                               : 0ULL) 
                                                             >> 1U))))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & (IData)(
                                                            (((0x27ULL 
                                                               >= 
                                                               ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                << 2U))
                                                               ? 
                                                              (0xffffffffffULL 
                                                               & VL_SHIFTR_QQQ(40,40,40, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__inflight_opcodes, 
                                                                               ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                                << 2U)))
                                                               : 0ULL) 
                                                             >> 1U)))))))
                                 : 0U)) | ((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & (IData)(
                                                               (((0x27ULL 
                                                                  >= 
                                                                  ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                   << 2U))
                                                                  ? 
                                                                 (0xffffffffffULL 
                                                                  & VL_SHIFTR_QQQ(40,40,40, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__inflight_opcodes, 
                                                                                ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                                << 2U)))
                                                                  : 0ULL) 
                                                                >> 1U))))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & (IData)(
                                                                     (((0x27ULL 
                                                                        >= 
                                                                        ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                         << 2U))
                                                                        ? 
                                                                       (0xffffffffffULL 
                                                                        & VL_SHIFTR_QQQ(40,40,40, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__inflight_opcodes, 
                                                                                ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                                << 2U)))
                                                                        : 0ULL) 
                                                                      >> 1U)))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:862: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'D' channel contains improper opcode response (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 862, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:863:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:864: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 864, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9057(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9057\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT___T_681) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__same_cycle_resp))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                               >> 5U)) != (7U & (IData)(
                                                        (((0x27ULL 
                                                           >= 
                                                           ((QData)((IData)(
                                                                            (0xfU 
                                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                            << 2U))
                                                           ? 
                                                          (0xffffffffffULL 
                                                           & VL_SHIFTR_QQQ(40,40,40, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__inflight_sizes, 
                                                                           ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                            << 2U)))
                                                           : 0ULL) 
                                                         >> 1U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:868: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'D' channel contains improper response size (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 868, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:869:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:870: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 870, "");
        }
    }
    if (VL_UNLIKELY(((((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter_1))) 
                          & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__a_first_counter_1))) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source) 
                           == (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                       >> 8U)))) & 
                       (6U != (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_d_ready)) 
                           | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT__full))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:874: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: ready check\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 874, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:875:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:876: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 876, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9058(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9058\n"); );
    // Body
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT___same_cycle_resp_T_1)
                              ? ((0xfU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source))
                                  ? (0x3ffU & ((IData)(1U) 
                                               << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source)))
                                  : 0U) : 0U) != ((
                                                   ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                                                    & (0U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter_1))) 
                                                   & (6U 
                                                      != 
                                                      (7U 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])))
                                                   ? 
                                                  ((0xfU 
                                                    >= 
                                                    (0xfU 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                        >> 8U)))
                                                    ? 
                                                   (0x3ffU 
                                                    & ((IData)(1U) 
                                                       << 
                                                       (0xfU 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 8U))))
                                                    : 0U)
                                                   : 0U)) 
                           | (0U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT___same_cycle_resp_T_1)
                                      ? ((0xfU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source))
                                          ? (0x3ffU 
                                             & ((IData)(1U) 
                                                << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source)))
                                          : 0U) : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:880: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'A' and 'D' concurrent, despite minlatency 2 (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 880, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:881:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:882: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 882, "");
        }
    }
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ (((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__inflight)) 
                            | (0U == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__plusarg_reader__DOT__myplus)) 
                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__watchdog 
                              < vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__plusarg_reader__DOT__myplus)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:886: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: TileLink timeout expired (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 886, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:887:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:888: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 888, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9059(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9059\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter_2))) 
                      & (6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:892: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 892, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:893:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:894: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 894, "");
        }
    }
    if (VL_UNLIKELY((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                        & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter_2))) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 5U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:898: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor: Assertion failed: 'D' channel contains improper response size (connected at CrossingHelper.scala:30:44)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 898, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv:899:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_78.sv:900: Assertion failed in %NTestHarness.chiptop.system.tsi_domain.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_78.sv", 900, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9095(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9095\n"); );
    // Body
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ (((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_sel_shiftAmount)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_last)) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___dec_T_19))) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_1)))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:270: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:265 assert (!dec || count =/= 0.U)        // underflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 270, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:271:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:272: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 272, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9096(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9096\n"); );
    // Body
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ ((0U == (0xfU & (IData)(
                                                      (0x9876543210ULL 
                                                       >> 
                                                       (0x3fU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source) 
                                                           << 2U)))))) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___inc_T_9))) 
                           | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_1))))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:276: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:266 assert (!inc || count =/= maxCount.U) // overflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 276, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:277:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:278: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 278, "");
        }
    }
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ (((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_sel_shiftAmount)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_last)) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___dec_T_19))) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_2)))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:282: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:265 assert (!dec || count =/= 0.U)        // underflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 282, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:283:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:284: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 284, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9097(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9097\n"); );
    // Body
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ ((1U == (0xfU & (IData)(
                                                      (0x9876543210ULL 
                                                       >> 
                                                       (0x3fU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source) 
                                                           << 2U)))))) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___inc_T_9))) 
                           | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_2))))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:288: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:266 assert (!inc || count =/= maxCount.U) // overflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 288, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:289:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:290: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 290, "");
        }
    }
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ (((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_sel_shiftAmount)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_last)) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___dec_T_19))) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_3)))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:294: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:265 assert (!dec || count =/= 0.U)        // underflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 294, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:295:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:296: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 296, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9098(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9098\n"); );
    // Body
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ ((2U == (0xfU & (IData)(
                                                      (0x9876543210ULL 
                                                       >> 
                                                       (0x3fU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source) 
                                                           << 2U)))))) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___inc_T_9))) 
                           | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_3))))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:300: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:266 assert (!inc || count =/= maxCount.U) // overflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 300, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:301:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:302: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 302, "");
        }
    }
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ (((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_sel_shiftAmount)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_last)) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___dec_T_19))) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_4)))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:306: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:265 assert (!dec || count =/= 0.U)        // underflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 306, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:307:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:308: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 308, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9099(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9099\n"); );
    // Body
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ ((3U == (0xfU & (IData)(
                                                      (0x9876543210ULL 
                                                       >> 
                                                       (0x3fU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source) 
                                                           << 2U)))))) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___inc_T_9))) 
                           | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_4))))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:312: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:266 assert (!inc || count =/= maxCount.U) // overflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 312, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:313:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:314: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 314, "");
        }
    }
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ (((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_sel_shiftAmount)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_last)) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___dec_T_19))) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_5)))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:318: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:265 assert (!dec || count =/= 0.U)        // underflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 318, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:319:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:320: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 320, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9100(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9100\n"); );
    // Body
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ ((4U == (0xfU & (IData)(
                                                      (0x9876543210ULL 
                                                       >> 
                                                       (0x3fU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source) 
                                                           << 2U)))))) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___inc_T_9))) 
                           | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_5))))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:324: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:266 assert (!inc || count =/= maxCount.U) // overflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 324, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:325:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:326: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 326, "");
        }
    }
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ (((5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_sel_shiftAmount)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_last)) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___dec_T_19))) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_6)))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:330: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:265 assert (!dec || count =/= 0.U)        // underflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 330, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:331:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:332: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 332, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9101(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9101\n"); );
    // Body
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ ((5U == (0xfU & (IData)(
                                                      (0x9876543210ULL 
                                                       >> 
                                                       (0x3fU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source) 
                                                           << 2U)))))) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___inc_T_9))) 
                           | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_6))))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:336: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:266 assert (!inc || count =/= maxCount.U) // overflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 336, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:337:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:338: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 338, "");
        }
    }
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ (((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_sel_shiftAmount)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_last)) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___dec_T_19))) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_7)))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:342: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:265 assert (!dec || count =/= 0.U)        // underflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 342, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:343:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:344: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 344, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9102(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9102\n"); );
    // Body
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ ((6U == (0xfU & (IData)(
                                                      (0x9876543210ULL 
                                                       >> 
                                                       (0x3fU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source) 
                                                           << 2U)))))) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___inc_T_9))) 
                           | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_7))))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:348: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:266 assert (!inc || count =/= maxCount.U) // overflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 348, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:349:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:350: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 350, "");
        }
    }
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ (((7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_sel_shiftAmount)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_last)) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___dec_T_19))) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_8)))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:354: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:265 assert (!dec || count =/= 0.U)        // underflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 354, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:355:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:356: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 356, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9103(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9103\n"); );
    // Body
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ ((7U == (0xfU & (IData)(
                                                      (0x9876543210ULL 
                                                       >> 
                                                       (0x3fU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source) 
                                                           << 2U)))))) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___inc_T_9))) 
                           | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_8))))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:360: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:266 assert (!inc || count =/= maxCount.U) // overflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 360, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:361:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:362: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 362, "");
        }
    }
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ (((8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_sel_shiftAmount)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_last)) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___dec_T_19))) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_9)))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:366: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:265 assert (!dec || count =/= 0.U)        // underflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 366, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:367:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:368: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 368, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9104(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9104\n"); );
    // Body
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ ((8U == (0xfU & (IData)(
                                                      (0x9876543210ULL 
                                                       >> 
                                                       (0x3fU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source) 
                                                           << 2U)))))) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___inc_T_9))) 
                           | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_9))))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:372: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:266 assert (!inc || count =/= maxCount.U) // overflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 372, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:373:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:374: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 374, "");
        }
    }
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ (((9U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_sel_shiftAmount)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__d_last)) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___dec_T_19))) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_10)))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:378: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:265 assert (!dec || count =/= 0.U)        // underflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 378, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:379:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:380: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 380, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9105(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9105\n"); );
    // Body
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ ((9U == (0xfU & (IData)(
                                                      (0x9876543210ULL 
                                                       >> 
                                                       (0x3fU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source) 
                                                           << 2U)))))) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___inc_T_9))) 
                           | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__count_10))))))) {
        VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:384: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4: Assertion failed\n    at ToAXI4.scala:266 assert (!inc || count =/= maxCount.U) // overflow\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 384, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv:385:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLToAXI4.sv:386: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.coupler_to_memory_controller_port_named_axi4.tl2axi4\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLToAXI4.sv", 386, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                      & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:280: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel carries AcquireBlock type which is unexpected using diplomatic parameters (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 280, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:281:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:282: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 282, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9106(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9106\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                      & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:286: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 286, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:287:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:288: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 288, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (9U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:292: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel AcquireBlock carries invalid source ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 292, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:293:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:294: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 294, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9107(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9107\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (2U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:298: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 298, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:299:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:300: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 300, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:304: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 304, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:305:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:306: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 306, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9108(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9108\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (2U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:310: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel AcquireBlock carries invalid grow param (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 310, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:311:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:312: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 312, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0xffU != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_mask))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:316: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 316, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:317:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:318: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 318, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9109(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9109\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_0) 
                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[3U] 
                            >> 0xcU)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1) 
                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[3U] 
                                            >> 0x14U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:322: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel AcquireBlock is corrupt (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 322, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:323:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:324: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 324, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                      & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:328: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel carries AcquirePerm type which is unexpected using diplomatic parameters (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 328, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:329:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:330: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 330, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9110(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9110\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                      & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:334: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel carries AcquirePerm from a client which does not support Probe (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 334, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:335:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:336: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 336, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (9U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:340: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel AcquirePerm carries invalid source ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 340, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:341:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:342: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 342, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (2U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:346: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 346, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:347:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:348: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 348, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9111(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9111\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:352: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 352, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:353:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:354: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 354, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (2U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:358: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel AcquirePerm carries invalid grow param (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 358, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:359:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:360: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 360, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9112(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9112\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:364: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 364, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:365:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:366: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 366, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0xffU != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_mask))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:370: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 370, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:371:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:372: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 372, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9113(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9113\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_0) 
                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[3U] 
                            >> 0xcU)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1) 
                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[3U] 
                                            >> 0x14U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:376: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel AcquirePerm is corrupt (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 376, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:377:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:378: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 378, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (9U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:382: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel carries Get type which master claims it can't emit (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 382, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:383:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:384: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 384, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9114(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9114\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ ((7U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size)) 
                           & ((2U == (0x1fffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address 
                                                 >> 0x10U))) 
                              | (0x10000U == (0x1ffffU 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address 
                                                 >> 0xcU))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:388: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel carries Get type which slave claims it can't support (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 388, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:389:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:390: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 390, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (9U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:394: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Get carries invalid source ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 394, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:395:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:396: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 396, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9115(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9115\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:400: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Get address not aligned to size (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 400, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:401:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:402: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 402, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:406: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Get carries invalid param (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 406, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:407:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:408: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 408, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9116(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9116\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:412: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Get contains invalid mask (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 412, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:413:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:414: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 414, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9117(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9117\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_0) 
                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[3U] 
                            >> 0xcU)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1) 
                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[3U] 
                                            >> 0x14U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:418: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Get is corrupt (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 418, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:419:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:420: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 420, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (IData)(((0x10000000U == 
                                    (0x1ffff000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                   & ((0xaU > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source)) 
                                      & (7U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:424: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel carries PutFull type which is unexpected using diplomatic parameters (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 424, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:425:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:426: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 426, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9118(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9118\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (9U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:430: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel PutFull carries invalid source ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 430, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:431:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:432: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 432, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:436: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel PutFull address not aligned to size (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 436, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:437:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:438: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 438, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9119(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9119\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:442: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel PutFull carries invalid param (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 442, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:443:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:444: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 444, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:448: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel PutFull contains invalid mask (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 448, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:449:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:450: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 450, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9120(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9120\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (IData)(((0x10000000U == 
                                    (0x1ffff000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                   & ((0xaU > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source)) 
                                      & (7U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:454: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel carries PutPartial type which is unexpected using diplomatic parameters (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 454, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:455:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:456: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 456, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (9U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:460: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel PutPartial carries invalid source ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 460, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:461:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:462: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 462, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9121(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9121\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:466: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel PutPartial address not aligned to size (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 466, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:467:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:468: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 468, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:472: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel PutPartial carries invalid param (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 472, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:473:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:474: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 474, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9122(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9122\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_mask) 
                               & (~ ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_5) 
                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_5) 
                                          & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                      << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_5) 
                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_5) 
                                                     & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                 << 6U) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_4) 
                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                    << 5U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_4) 
                                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_4) 
                                                           & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                       << 4U) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_3) 
                                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                          << 3U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_3) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_3) 
                                                                 & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                             << 2U) 
                                                            | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_2) 
                                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                                << 1U) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_2) 
                                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_2) 
                                                                     & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:478: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel PutPartial contains invalid mask (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 478, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:479:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:480: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 480, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9123(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9123\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                      & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:484: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel carries Arithmetic type which is unexpected using diplomatic parameters (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 484, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:485:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:486: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 486, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (9U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:490: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Arithmetic carries invalid source ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 490, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:491:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:492: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 492, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9124(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9124\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:496: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 496, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:497:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:498: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 498, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (4U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:502: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Arithmetic carries invalid opcode param (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 502, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:503:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:504: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 504, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9125(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9125\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:508: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 508, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:509:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:510: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 510, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9126(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9126\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                      & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:514: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel carries Logical type which is unexpected using diplomatic parameters (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 514, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:515:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:516: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 516, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (9U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:520: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Logical carries invalid source ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 520, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:521:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:522: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 522, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9127(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9127\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:526: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Logical address not aligned to size (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 526, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:527:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:528: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 528, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_param) 
                        >> 2U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:532: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Logical carries invalid opcode param (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 532, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:533:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:534: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 534, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9128(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9128\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:538: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Logical contains invalid mask (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 538, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:539:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:540: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 540, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9129(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9129\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                      & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:544: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel carries Hint type which is unexpected using diplomatic parameters (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 544, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:545:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:546: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 546, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (9U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:550: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Hint carries invalid source ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 550, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:551:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:552: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 552, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9130(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9130\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:556: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Hint address not aligned to size (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 556, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:557:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:558: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 558, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_param) 
                                     >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:562: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Hint carries invalid opcode param (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 562, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:563:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:564: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 564, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9131(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9131\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:568: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Hint contains invalid mask (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 568, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:569:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:570: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 570, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9132(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9132\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_0) 
                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[3U] 
                            >> 0xcU)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1) 
                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[3U] 
                                            >> 0x14U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:574: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel Hint is corrupt (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 574, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:575:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:576: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 576, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (7U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:580: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel has invalid opcode (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 580, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:581:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:582: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 582, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9133(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9133\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (9U < (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                      >> 8U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:586: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel ReleaseAck carries invalid source ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 586, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:587:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:588: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 588, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (3U > (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                    >> 5U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:592: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel ReleaseAck smaller than a beat (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 592, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:593:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:594: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 594, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9134(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9134\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:598: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel ReleaseeAck carries invalid param (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 598, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:599:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:600: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 600, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                        >> 0xeU)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:604: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel ReleaseAck is corrupt (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 604, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:605:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:606: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 606, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9135(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9135\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x2006U == (0x2007U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:610: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel ReleaseAck is denied (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 610, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:611:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:612: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 612, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (9U < (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                      >> 8U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:616: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel Grant carries invalid source ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 616, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:617:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:618: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 618, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9136(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9136\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:622: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel Grant carries invalid sink ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 622, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:623:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:624: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 624, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (3U > (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                    >> 5U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:628: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel Grant smaller than a beat (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 628, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:629:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:630: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 630, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9137(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9137\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x1cU == (0x1fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:634: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel Grant carries invalid cap param (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 634, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:635:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:636: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 636, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x14U == (0x1fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:640: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel Grant carries toN param (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 640, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:641:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:642: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 642, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9138(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9138\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                        >> 0xeU)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:646: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel Grant is corrupt (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 646, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:647:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:648: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 648, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x2004U == (0x2007U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:652: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel Grant is denied (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 652, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:653:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:654: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 654, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9139(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9139\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (9U < (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                      >> 8U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:658: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel GrantData carries invalid source ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 658, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:659:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:660: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 660, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:664: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel GrantData carries invalid sink ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 664, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:665:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:666: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 666, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9140(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9140\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (3U > (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                    >> 5U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:670: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel GrantData smaller than a beat (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 670, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:671:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:672: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 672, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x1dU == (0x1fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:676: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel GrantData carries invalid cap param (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 676, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:677:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:678: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 678, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9141(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9141\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x15U == (0x1fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:682: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel GrantData carries toN param (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 682, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:683:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:684: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 684, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                               >> 0xdU)) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                            >> 0xeU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:688: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel GrantData is denied but not corrupt (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 688, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:689:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:690: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 690, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9142(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9142\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x2005U == (0x2007U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:694: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel GrantData is denied (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 694, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:695:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:696: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 696, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (9U < (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                      >> 8U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:700: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel AccessAck carries invalid source ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 700, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:701:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:702: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 702, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9143(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9143\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:706: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel AccessAck carries invalid param (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 706, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:707:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:708: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 708, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                        >> 0xeU)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:712: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel AccessAck is corrupt (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 712, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:713:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:714: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 714, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9144(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9144\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x2000U == (0x2007U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:718: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel AccessAck is denied (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 718, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:719:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:720: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 720, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (1U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (9U < (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                      >> 8U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:724: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel AccessAckData carries invalid source ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 724, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:725:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:726: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 726, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9145(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9145\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (1U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:730: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel AccessAckData carries invalid param (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 730, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:731:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:732: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 732, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (1U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                               >> 0xdU)) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                            >> 0xeU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:736: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel AccessAckData is denied but not corrupt (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 736, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:737:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:738: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 738, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9146(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9146\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x2001U == (0x2007U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:742: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel AccessAckData is denied (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 742, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:743:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:744: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 744, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (9U < (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                      >> 8U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:748: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel HintAck carries invalid source ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 748, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:749:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:750: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 750, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9147(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9147\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:754: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel HintAck carries invalid param (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 754, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:755:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:756: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 756, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                        >> 0xeU)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:760: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel HintAck is corrupt (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 760, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:761:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:762: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 762, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9148(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9148\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x2002U == (0x2007U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:766: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel HintAck is denied (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 766, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:767:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:768: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 768, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__a_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__opcode))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:772: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel opcode changed within multibeat operation (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 772, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:773:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:774: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 774, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9149(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9149\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__a_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_param) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:778: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel param changed within multibeat operation (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 778, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:779:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:780: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 780, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__a_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:784: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel size changed within multibeat operation (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 784, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:785:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:786: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 786, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9150(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9150\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__a_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:790: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel source changed within multibeat operation (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 790, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:791:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:792: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 792, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__a_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((0x1fffffffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address) 
                        != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__address)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:796: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel address changed with multibeat operation (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 796, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:797:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:798: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 798, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9151(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9151\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__opcode_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:802: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel opcode changed within multibeat operation (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 802, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:803:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:804: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 804, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                               >> 3U)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__param_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:808: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel param changed within multibeat operation (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 808, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:809:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:810: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 810, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9152(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9152\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                               >> 5U)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__size_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:814: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel size changed within multibeat operation (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 814, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:815:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:816: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 816, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                 >> 8U)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__source_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:820: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel source changed within multibeat operation (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 820, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:821:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:822: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 822, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9153(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9153\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                               >> 0xcU)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__sink))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:826: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel sink changed with multibeat operation (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 826, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:827:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:828: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 828, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                               >> 0xdU)) != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__denied))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:832: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel denied changed with multibeat operation (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 832, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:833:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:834: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 834, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9154(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9154\n"); );
    // Body
    if (VL_UNLIKELY((0x3ffU & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT___T_662) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__inflight) 
                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:838: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'A' channel re-used a source ID (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 838, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:839:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:840: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 840, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT___T_681) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((9U >= (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                            >> 8U)))
                             ? (0x3ffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__inflight) 
                                          >> (0xfU 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 8U))))
                             : 0U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__same_cycle_resp)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:844: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 844, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:845:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:846: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 846, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9155(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9155\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT___T_681) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__same_cycle_resp)) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode)))))
                                 : 0U)) | ((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode)))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:850: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel contains improper opcode response (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 850, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:851:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:852: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 852, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9156(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9156\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT___T_681) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__same_cycle_resp)) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size) 
                        != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                  >> 5U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:856: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel contains improper response size (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 856, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:857:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:858: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 858, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT___T_681) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__same_cycle_resp))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (((0x27ULL 
                                                               >= 
                                                               ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                << 2U))
                                                               ? 
                                                              (0xffffffffffULL 
                                                               & VL_SHIFTR_QQQ(40,40,40, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__inflight_opcodes, 
                                                                               ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                                << 2U)))
                                                               : 0ULL) 
                                                             >> 1U))))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & (IData)(
                                                            (((0x27ULL 
                                                               >= 
                                                               ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                << 2U))
                                                               ? 
                                                              (0xffffffffffULL 
                                                               & VL_SHIFTR_QQQ(40,40,40, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__inflight_opcodes, 
                                                                               ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                                << 2U)))
                                                               : 0ULL) 
                                                             >> 1U)))))))
                                 : 0U)) | ((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & (IData)(
                                                               (((0x27ULL 
                                                                  >= 
                                                                  ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                   << 2U))
                                                                  ? 
                                                                 (0xffffffffffULL 
                                                                  & VL_SHIFTR_QQQ(40,40,40, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__inflight_opcodes, 
                                                                                ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                                << 2U)))
                                                                  : 0ULL) 
                                                                >> 1U))))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & (IData)(
                                                                     (((0x27ULL 
                                                                        >= 
                                                                        ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                         << 2U))
                                                                        ? 
                                                                       (0xffffffffffULL 
                                                                        & VL_SHIFTR_QQQ(40,40,40, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__inflight_opcodes, 
                                                                                ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                                << 2U)))
                                                                        : 0ULL) 
                                                                      >> 1U)))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:862: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel contains improper opcode response (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 862, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:863:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:864: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 864, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9157(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9157\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT___T_681) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__same_cycle_resp))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                               >> 5U)) != (7U & (IData)(
                                                        (((0x27ULL 
                                                           >= 
                                                           ((QData)((IData)(
                                                                            (0xfU 
                                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                            << 2U))
                                                           ? 
                                                          (0xffffffffffULL 
                                                           & VL_SHIFTR_QQQ(40,40,40, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__inflight_sizes, 
                                                                           ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 8U)))) 
                                                                            << 2U)))
                                                           : 0ULL) 
                                                         >> 1U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:868: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: 'D' channel contains improper response size (connected at MemoryBus.scala:47:50)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 868, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:869:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:870: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 870, "");
        }
    }
    if (VL_UNLIKELY(((((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__d_first_counter_1))) 
                          & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__a_first_counter_1))) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_a_valid)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source) 
                           == (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                       >> 8U)))) & 
                       (6U != (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT___subsystem_mbus_xbar_auto_out_1_d_ready)) 
                           | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT__full))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:874: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1: Assertion failed: ready check\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 874, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv:875:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_43.sv:876: Assertion failed in %NTestHarness.chiptop.system.subsystem_mbus.picker.monitor_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_43.sv", 876, "");
        }
    }
}
