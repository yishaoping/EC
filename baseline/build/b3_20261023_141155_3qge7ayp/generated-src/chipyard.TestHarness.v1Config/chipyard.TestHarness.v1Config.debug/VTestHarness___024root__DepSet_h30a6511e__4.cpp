// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness__Syms.h"
#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__274(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__274\n"); );
    // Body
    if (VL_UNLIKELY((0x3ffU & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_598) 
                                & (~ (IData)(vlSelf->reset))) 
                               & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__inflight) 
                                  >> (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                              >> 0xaU))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:838: Assertion failed in %NTestHarness.ram.fragmenter.monitor: Assertion failed: 'A' channel re-used a source ID (connected at SerialAdapter.scala:471:102)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 838, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv:839:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:840: Assertion failed in %NTestHarness.ram.fragmenter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 840, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_617) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (((9U >= (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                            >> 0xbU)))
                             ? (0x3ffU & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__inflight) 
                                          >> (0xfU 
                                              & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 0xbU))))
                             : 0U) | (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__same_cycle_resp)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:844: Assertion failed in %NTestHarness.ram.fragmenter.monitor: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at SerialAdapter.scala:471:102)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 844, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv:845:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:846: Assertion failed in %NTestHarness.ram.fragmenter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 846, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_617) 
                       & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__same_cycle_resp)) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (((7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & 
                                               (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                >> 0x15U)))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                     >> 0x15U))))))
                                 : 0U)) | ((7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                        >> 0x15U)))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                              >> 0x15U))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:850: Assertion failed in %NTestHarness.ram.fragmenter.monitor: Assertion failed: 'D' channel contains improper opcode response (connected at SerialAdapter.scala:471:102)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 850, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv:851:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:852: Assertion failed in %NTestHarness.ram.fragmenter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 852, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__275(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__275\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_617) 
                       & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__same_cycle_resp)) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                               >> 0xeU)) != (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:856: Assertion failed in %NTestHarness.ram.fragmenter.monitor: Assertion failed: 'D' channel contains improper response size (connected at SerialAdapter.scala:471:102)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 856, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv:857:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:858: Assertion failed in %NTestHarness.ram.fragmenter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 858, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_617) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__same_cycle_resp))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (((7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (((0x27ULL 
                                                               >= 
                                                               ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 0xbU)))) 
                                                                << 2U))
                                                               ? 
                                                              (0xffffffffffULL 
                                                               & VL_SHIFTR_QQQ(40,40,40, vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes, 
                                                                               ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 0xbU)))) 
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
                                                                                & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 0xbU)))) 
                                                                << 2U))
                                                               ? 
                                                              (0xffffffffffULL 
                                                               & VL_SHIFTR_QQQ(40,40,40, vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes, 
                                                                               ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 0xbU)))) 
                                                                                << 2U)))
                                                               : 0ULL) 
                                                             >> 1U)))))))
                                 : 0U)) | ((7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
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
                                                                                & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 0xbU)))) 
                                                                   << 2U))
                                                                  ? 
                                                                 (0xffffffffffULL 
                                                                  & VL_SHIFTR_QQQ(40,40,40, vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes, 
                                                                                ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 0xbU)))) 
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
                                                                                & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 0xbU)))) 
                                                                         << 2U))
                                                                        ? 
                                                                       (0xffffffffffULL 
                                                                        & VL_SHIFTR_QQQ(40,40,40, vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes, 
                                                                                ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 0xbU)))) 
                                                                                << 2U)))
                                                                        : 0ULL) 
                                                                      >> 1U)))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:862: Assertion failed in %NTestHarness.ram.fragmenter.monitor: Assertion failed: 'D' channel contains improper opcode response (connected at SerialAdapter.scala:471:102)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 862, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv:863:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:864: Assertion failed in %NTestHarness.ram.fragmenter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 864, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__276(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__276\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_617) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__same_cycle_resp))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_bits_size) 
                        != (7U & (IData)((((0x27ULL 
                                            >= ((QData)((IData)(
                                                                (0xfU 
                                                                 & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                    >> 0xbU)))) 
                                                << 2U))
                                            ? (0xffffffffffULL 
                                               & VL_SHIFTR_QQQ(40,40,40, vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes, 
                                                               ((QData)((IData)(
                                                                                (0xfU 
                                                                                & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 0xbU)))) 
                                                                << 2U)))
                                            : 0ULL) 
                                          >> 1U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:868: Assertion failed in %NTestHarness.ram.fragmenter.monitor: Assertion failed: 'D' channel contains improper response size (connected at SerialAdapter.scala:471:102)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 868, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv:869:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:870: Assertion failed in %NTestHarness.ram.fragmenter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 870, "");
        }
    }
    if (VL_UNLIKELY(((((((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_valid) 
                           & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))) 
                          & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1))) 
                         & (IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_0_a_valid)) 
                        & ((0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                    >> 0xaU)) == (0xfU 
                                                  & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xbU)))) 
                       & (6U != (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_0_d_ready)) 
                           | (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:874: Assertion failed in %NTestHarness.ram.fragmenter.monitor: Assertion failed: ready check\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 874, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv:875:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:876: Assertion failed in %NTestHarness.ram.fragmenter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 876, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__277(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__277\n"); );
    // Body
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->reset)) 
                           & (~ ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___same_cycle_resp_T_1)
                                    ? ((0xfU >= (0xfU 
                                                 & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                    >> 0xaU)))
                                        ? (0x3ffU & 
                                           ((IData)(1U) 
                                            << (0xfU 
                                                & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                   >> 0xaU))))
                                        : 0U) : 0U) 
                                  != ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_valid) 
                                        & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))) 
                                       & (6U != (7U 
                                                 & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])))
                                       ? ((0xfU >= 
                                           (0xfU & 
                                            (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xbU)))
                                           ? (0x3ffU 
                                              & ((IData)(1U) 
                                                 << 
                                                 (0xfU 
                                                  & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xbU))))
                                           : 0U) : 0U)) 
                                 | (0U == ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___same_cycle_resp_T_1)
                                            ? ((0xfU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                    >> 0xaU)))
                                                ? (0x3ffU 
                                                   & ((IData)(1U) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                          >> 0xaU))))
                                                : 0U)
                                            : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:880: Assertion failed in %NTestHarness.ram.fragmenter.monitor: Assertion failed: 'A' and 'D' concurrent, despite minlatency 3 (connected at SerialAdapter.scala:471:102)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 880, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv:881:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:882: Assertion failed in %NTestHarness.ram.fragmenter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 882, "");
        }
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->reset)) 
                           & (~ (((0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__inflight)) 
                                  | (0U == vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__plusarg_reader__DOT__myplus)) 
                                 | (vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__watchdog 
                                    < vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__plusarg_reader__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:886: Assertion failed in %NTestHarness.ram.fragmenter.monitor: Assertion failed: TileLink timeout expired (connected at SerialAdapter.scala:471:102)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 886, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv:887:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:888: Assertion failed in %NTestHarness.ram.fragmenter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 888, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__278(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__278\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2))) 
                      & (6U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:892: Assertion failed in %NTestHarness.ram.fragmenter.monitor: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at SerialAdapter.scala:471:102)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 892, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv:893:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:894: Assertion failed in %NTestHarness.ram.fragmenter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 894, "");
        }
    }
    if (VL_UNLIKELY((((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_valid) 
                        & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2))) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:898: Assertion failed in %NTestHarness.ram.fragmenter.monitor: Assertion failed: 'D' channel contains improper response size (connected at SerialAdapter.scala:471:102)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 898, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv:899:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_87.sv:900: Assertion failed in %NTestHarness.ram.fragmenter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_87.sv", 900, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__279(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__279\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ ((IData)(((0x180U == (0x7c0U 
                                                & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])) 
                                    & (0xdU > (0xfU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 6U))))) 
                           & (((2U == (0xffffU & ((
                                                   vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   << 5U) 
                                                  | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0x1bU)))) 
                               | (0x10000U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   << 9U) 
                                                  | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0x17U))))) 
                              | (8U == (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                >> 7U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:273: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel carries AcquireBlock type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 273, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:274:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:275: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 275, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                      & (6U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:279: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 279, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:280:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:281: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 281, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__280(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__280\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                      & (0x406U == (0x407U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:285: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel AcquireBlock carries invalid source ID (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 285, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:286:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:287: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 287, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (2U >= (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                       >> 6U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:291: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 291, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:292:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:293: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 293, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__281(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__281\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           << 0x15U) 
                                          | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xbU)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 6U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:297: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 297, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:298:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:299: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 299, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (2U < (7U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                    >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:303: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel AcquireBlock carries invalid grow param (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 303, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:304:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:305: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 305, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__282(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__282\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0xffU != (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                           >> 0xbU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:309: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 309, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:310:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:311: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 311, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                        >> 0x13U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:315: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel AcquireBlock is corrupt (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 315, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:316:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:317: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 317, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__283(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__283\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (7U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ ((IData)(((0x180U == (0x7c0U 
                                                & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])) 
                                    & (0xdU > (0xfU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 6U))))) 
                           & (((2U == (0xffffU & ((
                                                   vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   << 5U) 
                                                  | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0x1bU)))) 
                               | (0x10000U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   << 9U) 
                                                  | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0x17U))))) 
                              | (8U == (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                >> 7U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:321: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel carries AcquirePerm type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 321, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:322:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:323: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 323, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                      & (7U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:327: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel carries AcquirePerm from a client which does not support Probe (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 327, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:328:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:329: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 329, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__284(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__284\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                      & (0x407U == (0x407U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:333: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel AcquirePerm carries invalid source ID (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 333, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:334:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:335: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 335, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (7U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (2U >= (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                       >> 6U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:339: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 339, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:340:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:341: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 341, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__285(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__285\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (7U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           << 0x15U) 
                                          | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xbU)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 6U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:345: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 345, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:346:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:347: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 347, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (7U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (2U < (7U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                    >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:351: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel AcquirePerm carries invalid grow param (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 351, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:352:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:353: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 353, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__286(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__286\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                      & (7U == (0x3fU & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:357: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 357, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:358:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:359: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 359, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (7U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0xffU != (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                           >> 0xbU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:363: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 363, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:364:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:365: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 365, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__287(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__287\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (7U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                        >> 0x13U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:369: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel AcquirePerm is corrupt (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 369, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:370:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:371: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 371, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ ((0xdU > (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 6U))) 
                           & (~ (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                 >> 0xaU))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:375: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel carries Get type which master claims it can't emit (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 375, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:376:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:377: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 377, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__288(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__288\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (((0xdU > (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 6U))) 
                            & (3U == (0xfffffU & ((
                                                   vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   << 9U) 
                                                  | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0x17U))))) 
                           | ((7U > (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 6U))) 
                              & ((((((((((0U == ((0x7fffcU 
                                                  & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                      << 8U) 
                                                     | (0xfcU 
                                                        & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0x18U)))) 
                                                 | (3U 
                                                    & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 0x17U)))) 
                                         | (1U == (0xffffU 
                                                   & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                       << 5U) 
                                                      | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                         >> 0x1bU))))) 
                                        | (2U == (0xffffU 
                                                  & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                      << 5U) 
                                                     | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                        >> 0x1bU))))) 
                                       | (0U == ((0x7fff0U 
                                                  & (0x80U 
                                                     ^ 
                                                     ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                       << 8U) 
                                                      | (0xf0U 
                                                         & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0x18U))))) 
                                                 | (0xfU 
                                                    & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 0x17U))))) 
                                      | (0x200U == 
                                         (0xffffU & 
                                          ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                            << 5U) 
                                           | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                              >> 0x1bU))))) 
                                     | (0x2010U == 
                                        (0xfffffU & 
                                         ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                           << 9U) | 
                                          (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           >> 0x17U))))) 
                                    | (3U == (0x3fU 
                                              & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                 >> 5U)))) 
                                   | (0x10000U == (0xfffffU 
                                                   & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                       << 9U) 
                                                      | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                         >> 0x17U))))) 
                                  | (0x54000U == (0xfffffU 
                                                  & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                      << 9U) 
                                                     | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                        >> 0x17U))))) 
                                 | (8U == (0xfU & (
                                                   vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   >> 7U)))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:381: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel carries Get type which slave claims it can't support (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 381, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:382:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:383: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 383, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__289(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__289\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                      & (0x404U == (0x407U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:387: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Get carries invalid source ID (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 387, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:388:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:389: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 389, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           << 0x15U) 
                                          | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xbU)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 6U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:393: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Get address not aligned to size (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 393, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:394:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:395: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 395, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__290(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__290\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                     >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:399: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Get carries invalid param (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 399, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:400:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:401: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 401, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                  >> 0xbU)) != ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_5) 
                                                  << 7U) 
                                                 | (0xfffff80U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_5) 
                                                        << 7U) 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 4U)))) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_5) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_5) 
                                                        & (~ 
                                                           (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0xbU)))) 
                                                    << 6U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_4) 
                                                        << 5U) 
                                                       | (0x3ffffe0U 
                                                          & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_4) 
                                                              << 5U) 
                                                             & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                >> 6U)))) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_4) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_4) 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0xbU)))) 
                                                          << 4U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_3) 
                                                              << 3U) 
                                                             | (0xfffff8U 
                                                                & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_3) 
                                                                    << 3U) 
                                                                   & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 8U)))) 
                                                            | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_3) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_3) 
                                                                    & (~ 
                                                                       (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                        >> 0xbU)))) 
                                                                << 2U) 
                                                               | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_2) 
                                                                    << 1U) 
                                                                   | (0x3ffffeU 
                                                                      & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_2) 
                                                                          << 1U) 
                                                                         & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                            >> 0xaU)))) 
                                                                  | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_2) 
                                                                     | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_2) 
                                                                        & (~ 
                                                                           (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                            >> 0xbU))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:405: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Get contains invalid mask (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 405, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:406:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:407: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 407, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__291(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__291\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                        >> 0x13U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:411: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Get is corrupt (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 411, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:412:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:413: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 413, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (0U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (((0xdU > (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 6U))) 
                            & (~ (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                  >> 0xaU))) & (((0xdU 
                                                  > 
                                                  (0xfU 
                                                   & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 6U))) 
                                                 & (3U 
                                                    == 
                                                    (0xfffffU 
                                                     & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0x17U))))) 
                                                | ((7U 
                                                    > 
                                                    (0xfU 
                                                     & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                        >> 6U))) 
                                                   & ((((((((0U 
                                                             == 
                                                             ((0x7fffcU 
                                                               & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                   << 8U) 
                                                                  | (0xfcU 
                                                                     & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                        >> 0x18U)))) 
                                                              | (3U 
                                                                 & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                    >> 0x17U)))) 
                                                            | (0U 
                                                               == 
                                                               ((0x7fff0U 
                                                                 & (0x80U 
                                                                    ^ 
                                                                    ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                      << 8U) 
                                                                     | (0xf0U 
                                                                        & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                           >> 0x18U))))) 
                                                                | (0xfU 
                                                                   & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0x17U))))) 
                                                           | (0x200U 
                                                              == 
                                                              (0xffffU 
                                                               & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                   << 5U) 
                                                                  | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                     >> 0x1bU))))) 
                                                          | (0x2010U 
                                                             == 
                                                             (0xfffffU 
                                                              & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                  << 9U) 
                                                                 | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                    >> 0x17U))))) 
                                                         | (3U 
                                                            == 
                                                            (0x3fU 
                                                             & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                >> 5U)))) 
                                                        | (0x10000U 
                                                           == 
                                                           (0xfffffU 
                                                            & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0x17U))))) 
                                                       | (0x54000U 
                                                          == 
                                                          (0xfffffU 
                                                           & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                               << 9U) 
                                                              | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0x17U))))) 
                                                      | (8U 
                                                         == 
                                                         (0xfU 
                                                          & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                             >> 7U))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:417: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel carries PutFull type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 417, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:418:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:419: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 419, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__292(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__292\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                      & (0x400U == (0x407U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:423: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel PutFull carries invalid source ID (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 423, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:424:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:425: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 425, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (0U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           << 0x15U) 
                                          | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xbU)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 6U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:429: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel PutFull address not aligned to size (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 429, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:430:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:431: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 431, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__293(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__293\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (0U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                     >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:435: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel PutFull carries invalid param (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 435, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:436:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:437: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 437, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (0U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                  >> 0xbU)) != ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_5) 
                                                  << 7U) 
                                                 | (0xfffff80U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_5) 
                                                        << 7U) 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 4U)))) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_5) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_5) 
                                                        & (~ 
                                                           (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0xbU)))) 
                                                    << 6U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_4) 
                                                        << 5U) 
                                                       | (0x3ffffe0U 
                                                          & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_4) 
                                                              << 5U) 
                                                             & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                >> 6U)))) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_4) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_4) 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0xbU)))) 
                                                          << 4U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_3) 
                                                              << 3U) 
                                                             | (0xfffff8U 
                                                                & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_3) 
                                                                    << 3U) 
                                                                   & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 8U)))) 
                                                            | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_3) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_3) 
                                                                    & (~ 
                                                                       (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                        >> 0xbU)))) 
                                                                << 2U) 
                                                               | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_2) 
                                                                    << 1U) 
                                                                   | (0x3ffffeU 
                                                                      & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_2) 
                                                                          << 1U) 
                                                                         & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                            >> 0xaU)))) 
                                                                  | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_2) 
                                                                     | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_2) 
                                                                        & (~ 
                                                                           (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                            >> 0xbU))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:441: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel PutFull contains invalid mask (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 441, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:442:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:443: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 443, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__294(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__294\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (1U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (((0xdU > (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 6U))) 
                            & (~ (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                  >> 0xaU))) & (((0xdU 
                                                  > 
                                                  (0xfU 
                                                   & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 6U))) 
                                                 & (3U 
                                                    == 
                                                    (0xfffffU 
                                                     & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0x17U))))) 
                                                | ((7U 
                                                    > 
                                                    (0xfU 
                                                     & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                        >> 6U))) 
                                                   & ((((((((0U 
                                                             == 
                                                             ((0x7fffcU 
                                                               & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                   << 8U) 
                                                                  | (0xfcU 
                                                                     & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                        >> 0x18U)))) 
                                                              | (3U 
                                                                 & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                    >> 0x17U)))) 
                                                            | (0U 
                                                               == 
                                                               ((0x7fff0U 
                                                                 & (0x80U 
                                                                    ^ 
                                                                    ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                      << 8U) 
                                                                     | (0xf0U 
                                                                        & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                           >> 0x18U))))) 
                                                                | (0xfU 
                                                                   & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0x17U))))) 
                                                           | (0x200U 
                                                              == 
                                                              (0xffffU 
                                                               & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                   << 5U) 
                                                                  | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                     >> 0x1bU))))) 
                                                          | (0x2010U 
                                                             == 
                                                             (0xfffffU 
                                                              & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                  << 9U) 
                                                                 | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                    >> 0x17U))))) 
                                                         | (3U 
                                                            == 
                                                            (0x3fU 
                                                             & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                >> 5U)))) 
                                                        | (0x10000U 
                                                           == 
                                                           (0xfffffU 
                                                            & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0x17U))))) 
                                                       | (0x54000U 
                                                          == 
                                                          (0xfffffU 
                                                           & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                               << 9U) 
                                                              | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0x17U))))) 
                                                      | (8U 
                                                         == 
                                                         (0xfU 
                                                          & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                             >> 7U))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:447: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel carries PutPartial type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 447, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:448:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:449: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 449, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__295(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__295\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                      & (0x401U == (0x407U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:453: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel PutPartial carries invalid source ID (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 453, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:454:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:455: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 455, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (1U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           << 0x15U) 
                                          | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xbU)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 6U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:459: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel PutPartial address not aligned to size (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 459, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:460:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:461: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 461, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__296(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__296\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (1U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                     >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:465: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel PutPartial carries invalid param (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 465, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:466:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:467: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 467, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (1U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (0xffU & (((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                          << 0x15U) 
                                         | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                            >> 0xbU)) 
                                        & (~ ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_5) 
                                                << 7U) 
                                               | (0xfffff80U 
                                                  & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_5) 
                                                      << 7U) 
                                                     & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                        >> 4U)))) 
                                              | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_5) 
                                                   | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_5) 
                                                      & (~ 
                                                         (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 0xbU)))) 
                                                  << 6U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_4) 
                                                      << 5U) 
                                                     | (0x3ffffe0U 
                                                        & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_4) 
                                                            << 5U) 
                                                           & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                              >> 6U)))) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_4) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_4) 
                                                            & (~ 
                                                               (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                >> 0xbU)))) 
                                                        << 4U) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_3) 
                                                            << 3U) 
                                                           | (0xfffff8U 
                                                              & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_3) 
                                                                  << 3U) 
                                                                 & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                    >> 8U)))) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_3) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_3) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0xbU)))) 
                                                              << 2U) 
                                                             | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_2) 
                                                                  << 1U) 
                                                                 | (0x3ffffeU 
                                                                    & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_2) 
                                                                        << 1U) 
                                                                       & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                          >> 0xaU)))) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_2) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_2) 
                                                                      & (~ 
                                                                         (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                          >> 0xbU)))))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:471: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel PutPartial contains invalid mask (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 471, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:472:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:473: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 473, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__297(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__297\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ ((((0xdU > (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                              >> 6U))) 
                             & (~ (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                   >> 0xaU))) & (4U 
                                                 > 
                                                 (0xfU 
                                                  & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 6U)))) 
                           & (((((((((0U == ((0x7fffcU 
                                              & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  << 8U) 
                                                 | (0xfcU 
                                                    & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 0x18U)))) 
                                             | (3U 
                                                & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0x17U)))) 
                                     | (3U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   << 9U) 
                                                  | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0x17U))))) 
                                    | (0U == ((0x7fff0U 
                                               & (0x80U 
                                                  ^ 
                                                  ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                    << 8U) 
                                                   | (0xf0U 
                                                      & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                         >> 0x18U))))) 
                                              | (0xfU 
                                                 & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0x17U))))) 
                                   | (0x200U == (0xffffU 
                                                 & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                     << 5U) 
                                                    | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 0x1bU))))) 
                                  | (0x2010U == (0xfffffU 
                                                 & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                     << 9U) 
                                                    | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 0x17U))))) 
                                 | (3U == (0x3fU & 
                                           (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                            >> 5U)))) 
                                | (0x10000U == (0xfffffU 
                                                & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                    << 9U) 
                                                   | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0x17U))))) 
                               | (0x54000U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   << 9U) 
                                                  | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0x17U))))) 
                              | (8U == (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                >> 7U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:477: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel carries Arithmetic type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 477, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:478:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:479: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 479, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__298(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__298\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                      & (0x402U == (0x407U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:483: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Arithmetic carries invalid source ID (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 483, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:484:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:485: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 485, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           << 0x15U) 
                                          | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xbU)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 6U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:489: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 489, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:490:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:491: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 491, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__299(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__299\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (4U < (7U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                    >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:495: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Arithmetic carries invalid opcode param (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 495, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:496:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:497: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 497, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                  >> 0xbU)) != ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_5) 
                                                  << 7U) 
                                                 | (0xfffff80U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_5) 
                                                        << 7U) 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 4U)))) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_5) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_5) 
                                                        & (~ 
                                                           (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0xbU)))) 
                                                    << 6U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_4) 
                                                        << 5U) 
                                                       | (0x3ffffe0U 
                                                          & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_4) 
                                                              << 5U) 
                                                             & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                >> 6U)))) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_4) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_4) 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0xbU)))) 
                                                          << 4U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_3) 
                                                              << 3U) 
                                                             | (0xfffff8U 
                                                                & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_3) 
                                                                    << 3U) 
                                                                   & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 8U)))) 
                                                            | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_3) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_3) 
                                                                    & (~ 
                                                                       (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                        >> 0xbU)))) 
                                                                << 2U) 
                                                               | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_2) 
                                                                    << 1U) 
                                                                   | (0x3ffffeU 
                                                                      & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_2) 
                                                                          << 1U) 
                                                                         & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                            >> 0xaU)))) 
                                                                  | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_2) 
                                                                     | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_2) 
                                                                        & (~ 
                                                                           (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                            >> 0xbU))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:501: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 501, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:502:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:503: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 503, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__300(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__300\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (3U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ ((((0xdU > (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                              >> 6U))) 
                             & (~ (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                   >> 0xaU))) & (4U 
                                                 > 
                                                 (0xfU 
                                                  & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 6U)))) 
                           & (((((((((0U == ((0x7fffcU 
                                              & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  << 8U) 
                                                 | (0xfcU 
                                                    & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 0x18U)))) 
                                             | (3U 
                                                & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0x17U)))) 
                                     | (3U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   << 9U) 
                                                  | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0x17U))))) 
                                    | (0U == ((0x7fff0U 
                                               & (0x80U 
                                                  ^ 
                                                  ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                    << 8U) 
                                                   | (0xf0U 
                                                      & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                         >> 0x18U))))) 
                                              | (0xfU 
                                                 & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0x17U))))) 
                                   | (0x200U == (0xffffU 
                                                 & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                     << 5U) 
                                                    | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 0x1bU))))) 
                                  | (0x2010U == (0xfffffU 
                                                 & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                     << 9U) 
                                                    | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 0x17U))))) 
                                 | (3U == (0x3fU & 
                                           (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                            >> 5U)))) 
                                | (0x10000U == (0xfffffU 
                                                & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                    << 9U) 
                                                   | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0x17U))))) 
                               | (0x54000U == (0xfffffU 
                                               & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   << 9U) 
                                                  | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0x17U))))) 
                              | (8U == (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                >> 7U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:507: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel carries Logical type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 507, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:508:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:509: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 509, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__301(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__301\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                      & (0x403U == (0x407U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:513: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Logical carries invalid source ID (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 513, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:514:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:515: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 515, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (3U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           << 0x15U) 
                                          | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xbU)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 6U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:519: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Logical address not aligned to size (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 519, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:520:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:521: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 521, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__302(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__302\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                      & (0x23U == (0x27U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:525: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Logical carries invalid opcode param (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 525, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:526:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:527: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 527, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (3U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                  >> 0xbU)) != ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_5) 
                                                  << 7U) 
                                                 | (0xfffff80U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_5) 
                                                        << 7U) 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 4U)))) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_5) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_5) 
                                                        & (~ 
                                                           (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0xbU)))) 
                                                    << 6U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_4) 
                                                        << 5U) 
                                                       | (0x3ffffe0U 
                                                          & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_4) 
                                                              << 5U) 
                                                             & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                >> 6U)))) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_4) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_4) 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0xbU)))) 
                                                          << 4U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_3) 
                                                              << 3U) 
                                                             | (0xfffff8U 
                                                                & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_3) 
                                                                    << 3U) 
                                                                   & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 8U)))) 
                                                            | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_3) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_3) 
                                                                    & (~ 
                                                                       (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                        >> 0xbU)))) 
                                                                << 2U) 
                                                               | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_2) 
                                                                    << 1U) 
                                                                   | (0x3ffffeU 
                                                                      & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_2) 
                                                                          << 1U) 
                                                                         & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                            >> 0xaU)))) 
                                                                  | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_2) 
                                                                     | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_2) 
                                                                        & (~ 
                                                                           (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                            >> 0xbU))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:531: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Logical contains invalid mask (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 531, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:532:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:533: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 533, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__303(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__303\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (((0xdU > (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 6U))) 
                            & (~ (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                  >> 0xaU))) & (((0xdU 
                                                  > 
                                                  (0xfU 
                                                   & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 6U))) 
                                                 & (3U 
                                                    == 
                                                    (0xfffffU 
                                                     & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0x17U))))) 
                                                | ((7U 
                                                    > 
                                                    (0xfU 
                                                     & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                        >> 6U))) 
                                                   & (((2U 
                                                        == 
                                                        (0xffffU 
                                                         & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                             << 5U) 
                                                            | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                               >> 0x1bU)))) 
                                                       | (0x10000U 
                                                          == 
                                                          (0xfffffU 
                                                           & ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                               << 9U) 
                                                              | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0x17U))))) 
                                                      | (8U 
                                                         == 
                                                         (0xfU 
                                                          & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                             >> 7U))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:537: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel carries Hint type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 537, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:538:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:539: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 539, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__304(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__304\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                      & (0x405U == (0x407U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:543: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Hint carries invalid source ID (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 543, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:544:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:545: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 545, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (0xfffU & (((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           << 0x15U) 
                                          | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xbU)) 
                                         & (~ ((0x1aU 
                                                >= 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))
                                                ? (0x7ffffffU 
                                                   & ((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 6U))))
                                                : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:549: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Hint address not aligned to size (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 549, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:550:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:551: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 551, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__305(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__305\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                     >> 4U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:555: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Hint carries invalid opcode param (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 555, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:556:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:557: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 557, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                  >> 0xbU)) != ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_5) 
                                                  << 7U) 
                                                 | (0xfffff80U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_5) 
                                                        << 7U) 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 4U)))) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_5) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_5) 
                                                        & (~ 
                                                           (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0xbU)))) 
                                                    << 6U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_4) 
                                                        << 5U) 
                                                       | (0x3ffffe0U 
                                                          & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_4) 
                                                              << 5U) 
                                                             & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                >> 6U)))) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_4) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_4) 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0xbU)))) 
                                                          << 4U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_3) 
                                                              << 3U) 
                                                             | (0xfffff8U 
                                                                & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_3) 
                                                                    << 3U) 
                                                                   & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 8U)))) 
                                                            | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_3) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_3) 
                                                                    & (~ 
                                                                       (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                        >> 0xbU)))) 
                                                                << 2U) 
                                                               | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_2) 
                                                                    << 1U) 
                                                                   | (0x3ffffeU 
                                                                      & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_2) 
                                                                          << 1U) 
                                                                         & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                            >> 0xaU)))) 
                                                                  | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_2) 
                                                                     | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_2) 
                                                                        & (~ 
                                                                           (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                            >> 0xbU))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:561: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Hint contains invalid mask (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 561, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:562:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:563: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 563, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__306(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__306\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                        >> 0x13U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:567: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel Hint is corrupt (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 567, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:568:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:569: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 569, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0xe00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:573: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel has invalid opcode (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 573, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:574:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:575: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 575, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                      & (0xc00400U == (0xe00400U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:579: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel ReleaseAck carries invalid source ID (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 579, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:580:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:581: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 581, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__307(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__307\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0xc00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (3U > (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                      >> 0xeU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:585: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel ReleaseAck smaller than a beat (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 585, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:586:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:587: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 587, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0xc00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                     >> 0x12U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:591: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel ReleaseeAck carries invalid param (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 591, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:592:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:593: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 593, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__308(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__308\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0xc00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                        >> 9U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:597: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel ReleaseAck is corrupt (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 597, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:598:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:599: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 599, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0xc00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                        >> 1U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:603: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel ReleaseAck is denied (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 603, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:604:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:605: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 605, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                      & (0x800400U == (0xe00400U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:609: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel Grant carries invalid source ID (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 609, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:610:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:611: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 611, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__309(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__309\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0x800000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (3U > (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                      >> 0xeU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:615: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel Grant smaller than a beat (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 615, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:616:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:617: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 617, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                      & (0x8c0000U == (0xec0000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:621: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel Grant carries invalid cap param (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 621, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:622:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:623: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 623, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__310(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__310\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                      & (0x880000U == (0xec0000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:627: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel Grant carries toN param (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 627, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:628:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:629: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 629, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0x800000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                        >> 9U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:633: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel Grant is corrupt (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 633, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:634:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:635: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 635, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__311(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__311\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                      & (0xa00400U == (0xe00400U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:639: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel GrantData carries invalid source ID (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 639, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:640:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:641: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 641, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0xa00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (3U > (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                      >> 0xeU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:645: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel GrantData smaller than a beat (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 645, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:646:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:647: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 647, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__312(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__312\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                      & (0xac0000U == (0xec0000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:651: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel GrantData carries invalid cap param (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 651, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:652:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:653: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 653, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                      & (0xa80000U == (0xec0000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:657: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel GrantData carries toN param (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 657, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:658:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:659: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 659, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__313(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__313\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0xa00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (IData)((2U != (0x202U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:663: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel GrantData is denied but not corrupt (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 663, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:664:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:665: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 665, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                      & (0x400U == (0xe00400U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:669: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel AccessAck carries invalid source ID (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 669, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:670:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:671: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 671, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__314(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__314\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                     >> 0x12U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:675: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel AccessAck carries invalid param (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 675, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:676:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:677: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 677, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                        >> 9U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:681: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel AccessAck is corrupt (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 681, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:682:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:683: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 683, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__315(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__315\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                      & (0x200400U == (0xe00400U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:687: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel AccessAckData carries invalid source ID (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 687, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:688:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:689: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 689, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0x200000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                     >> 0x12U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:693: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel AccessAckData carries invalid param (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 693, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:694:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:695: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 695, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__316(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__316\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0x200000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (IData)((2U != (0x202U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:699: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel AccessAckData is denied but not corrupt (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 699, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:700:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:701: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 701, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                      & (0x400400U == (0xe00400U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:705: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel HintAck carries invalid source ID (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 705, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:706:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:707: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 707, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__317(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__317\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0x400000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                     >> 0x12U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:711: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel HintAck carries invalid param (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 711, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:712:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:713: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 713, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0x400000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                        >> 9U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:717: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel HintAck is corrupt (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 717, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:718:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:719: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 719, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__318(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__318\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]) 
                        != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__opcode))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:723: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel opcode changed within multibeat operation (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 723, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:724:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:725: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 725, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((7U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                               >> 3U)) != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:729: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel param changed within multibeat operation (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 729, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:730:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:731: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 731, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                 >> 6U)) != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:735: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel size changed within multibeat operation (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 735, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:736:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:737: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 737, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__319(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__319\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((1U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                               >> 0xaU)) != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:741: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel source changed within multibeat operation (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 741, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:742:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:743: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 743, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                          << 0x15U) | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                       >> 0xbU)) != vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__address)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:747: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel address changed with multibeat operation (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 747, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:748:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:749: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 749, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                               >> 0x15U)) != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__opcode_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:753: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel opcode changed within multibeat operation (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 753, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:754:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:755: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 755, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__320(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__320\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((3U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                               >> 0x12U)) != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__param_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:759: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel param changed within multibeat operation (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 759, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:760:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:761: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 761, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                 >> 0xeU)) != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__size_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:765: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel size changed within multibeat operation (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 765, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:766:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:767: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 767, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((1U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                               >> 0xaU)) != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__source_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:771: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel source changed within multibeat operation (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 771, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:772:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:773: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 773, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__321(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__321\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                               >> 2U)) != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__sink))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:777: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel sink changed with multibeat operation (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 777, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:778:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:779: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 779, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((1U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                               >> 1U)) != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__denied))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:783: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel denied changed with multibeat operation (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 783, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:784:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:785: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 785, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1198) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__inflight) 
                        >> (1U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                  >> 0xaU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:789: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' channel re-used a source ID (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 789, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:790:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:791: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 791, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__322(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__322\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1217) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__inflight) 
                            >> (1U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                      >> 0xaU))) | (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__same_cycle_resp)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:795: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 795, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:796:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:797: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 797, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1217) 
                       & (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__same_cycle_resp)) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (((7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                   >> 0x15U)) == ((0x17U 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(3U) 
                                                       * 
                                                       (7U 
                                                        & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))))
                                                   ? 
                                                  (7U 
                                                   & (0x911240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])))))
                                                   : 0U)) 
                           | ((7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                     >> 0x15U)) == 
                              ((0x17U >= (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))))
                                ? (7U & (0x951240U 
                                         >> (0x1fU 
                                             & ((IData)(3U) 
                                                * (7U 
                                                   & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])))))
                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:801: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel contains improper opcode response (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 801, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:802:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:803: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 803, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__323(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__323\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1217) 
                       & (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__same_cycle_resp)) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                 >> 6U)) != (0xfU & 
                                             (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                              >> 0xeU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:807: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel contains improper response size (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 807, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:808:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:809: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 809, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1217) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__same_cycle_resp))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (((7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                   >> 0x15U)) == ((0x17U 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(3U) 
                                                       * 
                                                       (7U 
                                                        & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__inflight_opcodes) 
                                                            >> 
                                                            (4U 
                                                             & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                                >> 8U))) 
                                                           >> 1U)))))
                                                   ? 
                                                  (7U 
                                                   & (0x911240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__inflight_opcodes) 
                                                               >> 
                                                               (4U 
                                                                & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                                   >> 8U))) 
                                                              >> 1U))))))
                                                   : 0U)) 
                           | ((7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                     >> 0x15U)) == 
                              ((0x17U >= (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__inflight_opcodes) 
                                                        >> 
                                                        (4U 
                                                         & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                            >> 8U))) 
                                                       >> 1U)))))
                                ? (7U & (0x951240U 
                                         >> (0x1fU 
                                             & ((IData)(3U) 
                                                * (7U 
                                                   & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__inflight_opcodes) 
                                                       >> 
                                                       (4U 
                                                        & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                           >> 8U))) 
                                                      >> 1U))))))
                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:813: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel contains improper opcode response (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 813, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:814:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:815: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 815, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__324(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__324\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1217) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__same_cycle_resp))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                 >> 0xeU)) != (0x7fU 
                                               & (((7U 
                                                    >= 
                                                    (8U 
                                                     & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                        >> 7U)))
                                                    ? 
                                                   (0xffU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__inflight_sizes) 
                                                       >> 
                                                       (8U 
                                                        & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                           >> 7U))))
                                                    : 0U) 
                                                  >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:819: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel contains improper response size (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 819, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:820:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:821: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 821, "");
        }
    }
    if (VL_UNLIKELY(((((((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                           & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_1))) 
                          & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter_1))) 
                         & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty))) 
                        & ((1U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                  >> 0xaU)) == (1U 
                                                & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                   >> 0xaU)))) 
                       & (6U != (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                       >> 0x15U)))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__full) 
                           | (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___outArb_io_in_4_ready)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:825: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: ready check\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 825, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:826:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:827: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 827, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__325(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__325\n"); );
    // Body
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->reset)) 
                           & (~ ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___same_cycle_resp_T_1) 
                                   & (~ (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 0xaU))) 
                                  != ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                                        & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_1))) 
                                       & (6U != (7U 
                                                 & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                    >> 0x15U)))) 
                                      & (~ (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                            >> 0xaU)))) 
                                 | (~ ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___same_cycle_resp_T_1) 
                                       & (~ (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xaU)))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:831: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'A' and 'D' concurrent, despite minlatency 6 (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 831, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:832:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:833: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 833, "");
        }
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->reset)) 
                           & (~ (((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__inflight)) 
                                  | (0U == vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__plusarg_reader__DOT__myplus)) 
                                 | (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__watchdog 
                                    < vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__plusarg_reader__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:837: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: TileLink timeout expired (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 837, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:838:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:839: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 839, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__326(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__326\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_2))) 
                      & (0xc00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:843: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 843, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:844:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:845: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 845, "");
        }
    }
    if (VL_UNLIKELY((((((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
                        & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_2))) 
                       & (0xc00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                       >> 0xeU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:849: Assertion failed in %NTestHarness.ram.serdesser.monitor: Assertion failed: 'D' channel contains improper response size (connected at SerialAdapter.scala:475:25)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 849, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv:850:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_82.sv:851: Assertion failed in %NTestHarness.ram.serdesser.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_82.sv", 851, "");
        }
    }
}

void VTestHarness___024unit____Vdpiimwrap_jtag_tick_TOP____024unit(CData/*0:0*/ &jtag_TCK, CData/*0:0*/ &jtag_TMS, CData/*0:0*/ &jtag_TDI, CData/*0:0*/ &jtag_TRSTn, CData/*0:0*/ jtag_TDO, IData/*31:0*/ &jtag_tick__Vfuncrtn);

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__352(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__352\n"); );
    // Init
    IData/*31:0*/ __Vfunc_jtag_tick__0__Vfuncout;
    CData/*0:0*/ __Vfunc_jtag_tick__0__jtag_TCK;
    CData/*0:0*/ __Vfunc_jtag_tick__0__jtag_TMS;
    CData/*0:0*/ __Vfunc_jtag_tick__0__jtag_TDI;
    CData/*0:0*/ __Vfunc_jtag_tick__0__jtag_TRSTn;
    // Body
    if (((IData)(vlSelf->reset) | (IData)(vlSelf->TestHarness__DOT__SimJTAG__DOT__r_reset))) {
        vlSelf->TestHarness__DOT__SimJTAG__DOT_____05Fexit = 0U;
        vlSelf->TestHarness__DOT__SimJTAG__DOT_____05Fjtag_TCK 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__SimJTAG__DOT_____05Fjtag_TCK)));
        vlSelf->__Vdly__TestHarness__DOT__SimJTAG__DOT__tickCounterReg = 3U;
        vlSelf->__Vdly__TestHarness__DOT__SimJTAG__DOT__init_done_sticky = 0U;
    } else {
        vlSelf->__Vdly__TestHarness__DOT__SimJTAG__DOT__init_done_sticky 
            = (1U & ((~ (IData)(vlSelf->reset)) | (IData)(vlSelf->TestHarness__DOT__SimJTAG__DOT__init_done_sticky)));
        if ((vlSelf->TestHarness__DOT__plusarg_reader__DOT__myplus 
             & (IData)(vlSelf->TestHarness__DOT__SimJTAG__DOT__init_done_sticky))) {
            if ((0U == vlSelf->TestHarness__DOT__SimJTAG__DOT__tickCounterReg)) {
                VTestHarness___024unit____Vdpiimwrap_jtag_tick_TOP____024unit(__Vfunc_jtag_tick__0__jtag_TCK, __Vfunc_jtag_tick__0__jtag_TMS, __Vfunc_jtag_tick__0__jtag_TDI, __Vfunc_jtag_tick__0__jtag_TRSTn, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__tdoReg), __Vfunc_jtag_tick__0__Vfuncout);
                vlSelf->TestHarness__DOT__SimJTAG__DOT_____05Fjtag_TCK 
                    = __Vfunc_jtag_tick__0__jtag_TCK;
                vlSelf->TestHarness__DOT__SimJTAG__DOT_____05Fjtag_TMS 
                    = __Vfunc_jtag_tick__0__jtag_TMS;
                vlSelf->TestHarness__DOT__SimJTAG__DOT_____05Fjtag_TDI 
                    = __Vfunc_jtag_tick__0__jtag_TDI;
                vlSelf->TestHarness__DOT__SimJTAG__DOT_____05Fjtag_TRSTn 
                    = __Vfunc_jtag_tick__0__jtag_TRSTn;
                vlSelf->TestHarness__DOT__SimJTAG__DOT_____05Fexit 
                    = __Vfunc_jtag_tick__0__Vfuncout;
            }
            vlSelf->__Vdly__TestHarness__DOT__SimJTAG__DOT__tickCounterReg 
                = vlSelf->TestHarness__DOT__SimJTAG__DOT__tickCounterNxt;
        }
    }
}

void VTestHarness___024unit____Vdpiimwrap_serial_tick_TOP____024unit(CData/*0:0*/ serial_out_valid, CData/*0:0*/ &serial_out_ready, IData/*31:0*/ serial_out_bits, CData/*0:0*/ &serial_in_valid, CData/*0:0*/ serial_in_ready, IData/*31:0*/ &serial_in_bits, IData/*31:0*/ &serial_tick__Vfuncrtn);

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__360(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__360\n"); );
    // Init
    IData/*31:0*/ __Vfunc_serial_tick__1__Vfuncout;
    CData/*0:0*/ __Vfunc_serial_tick__1__serial_out_ready;
    CData/*0:0*/ __Vfunc_serial_tick__1__serial_in_valid;
    IData/*31:0*/ __Vfunc_serial_tick__1__serial_in_bits;
    // Body
    if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT___T_1347) 
         & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_counter)))))) {
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__opcode_1 
            = (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]);
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__param_1 
            = (3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                     >> 3U));
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__size_1 
            = (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                       >> 5U));
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__source_1 
            = (1U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                     >> 9U));
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__sink 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                     >> 0xaU));
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__denied 
            = (1U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                     >> 0xdU));
    }
    if (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT___T_1165) {
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__opcode 
            = ((7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state))
                ? 1U : 4U);
    }
    if (vlSelf->reset) {
        vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fin_valid = 0U;
        vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fout_ready = 0U;
        vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fexit = 0U;
        vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fin_valid_reg = 0U;
        vlSelf->__Vdly__TestHarness__DOT__success_exit_sim__DOT_____05Fin_bits_reg = 0U;
        vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fout_ready_reg = 0U;
        vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fexit_reg = 0U;
    } else {
        VTestHarness___024unit____Vdpiimwrap_serial_tick_TOP____024unit(
                                                                        (5U 
                                                                         == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state)), __Vfunc_serial_tick__1__serial_out_ready, 
                                                                        ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx)
                                                                          ? vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__body_1
                                                                          : vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__body_0), __Vfunc_serial_tick__1__serial_in_valid, 
                                                                        ((((0U 
                                                                            == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state)) 
                                                                           | (1U 
                                                                              == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state))) 
                                                                          | (2U 
                                                                             == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state))) 
                                                                         | (6U 
                                                                            == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state))), __Vfunc_serial_tick__1__serial_in_bits, __Vfunc_serial_tick__1__Vfuncout);
        vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fout_ready 
            = __Vfunc_serial_tick__1__serial_out_ready;
        vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fin_valid 
            = __Vfunc_serial_tick__1__serial_in_valid;
        vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fin_bits 
            = __Vfunc_serial_tick__1__serial_in_bits;
        vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fexit 
            = __Vfunc_serial_tick__1__Vfuncout;
        vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fout_ready_reg 
            = vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fout_ready;
        vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fin_valid_reg 
            = vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fin_valid;
        vlSelf->__Vdly__TestHarness__DOT__success_exit_sim__DOT_____05Fin_bits_reg 
            = vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fin_bits;
        vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fexit_reg 
            = vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fexit;
    }
}

void VTestHarness___024unit____Vdpiimwrap_uart_tick_TOP____024unit(CData/*0:0*/ serial_out_valid, CData/*0:0*/ &serial_out_ready, CData/*7:0*/ serial_out_bits, CData/*0:0*/ &serial_in_valid, CData/*0:0*/ serial_in_ready, CData/*7:0*/ &serial_in_bits);

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__365(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__365\n"); );
    // Init
    CData/*0:0*/ __Vtask_uart_tick__5__serial_out_ready;
    CData/*0:0*/ __Vtask_uart_tick__5__serial_in_valid;
    CData/*7:0*/ __Vtask_uart_tick__5__serial_in_bits;
    // Body
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__pulse 
        = (0U == (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__prescaler));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_2 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_counter_2));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_1 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_1));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__d_first_1 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__d_first_counter_1));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_1 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_counter_1));
    if (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__a_fire) {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_address 
            = (0x1fffffffU & ((vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                               << 0x10U) | (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 0x10U)));
    }
    if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__a_fire) 
         & (4U != (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])))) {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_rmw_data 
            = (((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                << 0x2bU) | (((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                              << 0xbU) | ((QData)((IData)(
                                                          vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                          >> 0x15U)));
    }
    if (vlSelf->reset) {
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fin_valid = 0U;
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fout_ready = 0U;
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fuartno = 0U;
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fin_valid_reg = 0U;
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fin_bits_reg = 0U;
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fout_ready_reg = 0U;
    } else {
        VTestHarness___024unit____Vdpiimwrap_uart_tick_TOP____024unit(
                                                                      (1U 
                                                                       & (~ (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__empty))), __Vtask_uart_tick__5__serial_out_ready, 
                                                                      vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__ram_ext__DOT__Memory
                                                                      [vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__deq_ptr_value], __Vtask_uart_tick__5__serial_in_valid, 
                                                                      ((~ (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__full)) 
                                                                       & (7U 
                                                                          > 
                                                                          (((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__full) 
                                                                            << 3U) 
                                                                           | (7U 
                                                                              & ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__enq_ptr_value) 
                                                                                - (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__deq_ptr_value)))))), __Vtask_uart_tick__5__serial_in_bits);
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fout_ready 
            = __Vtask_uart_tick__5__serial_out_ready;
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fin_valid 
            = __Vtask_uart_tick__5__serial_in_valid;
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fin_bits 
            = __Vtask_uart_tick__5__serial_in_bits;
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fout_ready_reg 
            = vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fout_ready;
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fin_valid_reg 
            = vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fin_valid;
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fin_bits_reg 
            = vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fin_bits;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__431(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__431\n"); );
    // Body
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset)) 
                           & (~ (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_chainIn_capture) 
                                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_chainIn_update))) 
                                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_chainIn_capture) 
                                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_chainIn_shift)))) 
                                 & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_chainIn_update) 
                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_chainIn_shift))))))))) {
        VL_WRITEF("[%0t] %%Error: CaptureUpdateChain_1.sv:224: Assertion failed in %NTestHarness.chiptop.system.dtm.dmiAccessChain: Assertion failed\n    at JtagShifter.scala:183 assert(!(io.chainIn.capture && io.chainIn.update)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/CaptureUpdateChain_1.sv", 224, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/CaptureUpdateChain_1.sv:225:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: CaptureUpdateChain_1.sv:226: Assertion failed in %NTestHarness.chiptop.system.dtm.dmiAccessChain\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/CaptureUpdateChain_1.sv", 226, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__432(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__432\n"); );
    // Body
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset)) 
                           & (~ (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dtmInfoChain__io_chainIn_capture) 
                                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dtmInfoChain__io_chainIn_update))) 
                                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dtmInfoChain__io_chainIn_capture) 
                                        & ((0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
                                           & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState)))))) 
                                 & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dtmInfoChain__io_chainIn_update) 
                                       & ((0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
                                          & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState))))))))))) {
        VL_WRITEF("[%0t] %%Error: CaptureUpdateChain.sv:163: Assertion failed in %NTestHarness.chiptop.system.dtm.dtmInfoChain: Assertion failed\n    at JtagShifter.scala:183 assert(!(io.chainIn.capture && io.chainIn.update)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/CaptureUpdateChain.sv", 163, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/CaptureUpdateChain.sv:164:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: CaptureUpdateChain.sv:165: Assertion failed in %NTestHarness.chiptop.system.dtm.dtmInfoChain\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/CaptureUpdateChain.sv", 165, "");
        }
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset)) 
                           & (~ (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__tapIO_idcodeChain__io_chainIn_capture) 
                                      & ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
                                         & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState))))) 
                                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__tapIO_idcodeChain__io_chainIn_capture) 
                                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__tapIO_idcodeChain__io_chainIn_shift)))) 
                                 & (~ (((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
                                        & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState))) 
                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__tapIO_idcodeChain__io_chainIn_shift))))))))) {
        VL_WRITEF("[%0t] %%Error: CaptureChain.sv:187: Assertion failed in %NTestHarness.chiptop.system.dtm.tapIO_idcodeChain: Assertion failed\n    at JtagShifter.scala:117 assert(!(io.chainIn.capture && io.chainIn.update)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/CaptureChain.sv", 187, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/CaptureChain.sv:188:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: CaptureChain.sv:189: Assertion failed in %NTestHarness.chiptop.system.dtm.tapIO_idcodeChain\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/CaptureChain.sv", 189, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__433(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__433\n"); );
    // Body
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset)) 
                           & (~ ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_readys) 
                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__in_d_valid))) 
                                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_readys) 
                                        >> 1U) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_1_a_valid))))))))) {
        VL_WRITEF("[%0t] %%Error: TLXbar_20.sv:152: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmiXbar: Assertion failed\n    at Arbiter.scala:106 assert((prefixOR zip earlyWinner) map { case (p,w) => !p || !w } reduce {_ && _})\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLXbar_20.sv", 152, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLXbar_20.sv:153:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLXbar_20.sv:154: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmiXbar\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLXbar_20.sv", 154, "");
        }
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset)) 
                           & (~ (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__in_d_valid) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_1_a_valid))) 
                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_readys) 
                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__in_d_valid))) 
                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_readys) 
                                     >> 1U) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_1_a_valid)))))))) {
        VL_WRITEF("[%0t] %%Error: TLXbar_20.sv:158: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmiXbar: Assertion failed\n    at Arbiter.scala:108 assert (!earlyValids.reduce(_||_) || earlyWinner.reduce(_||_))\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLXbar_20.sv", 158, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLXbar_20.sv:159:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLXbar_20.sv:160: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmiXbar\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLXbar_20.sv", 160, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__434(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__434\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT___dmiAccessChain_io_update_valid)) 
                      & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__stickyBusyReg) 
                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT___T_11)))) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT___portsAOI_in_0_a_ready_WIRE) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiReqValidReg))))) {
        VL_WRITEF("[%0t] %%Error: DebugTransportModuleJTAG.sv:159: Assertion failed in %NTestHarness.chiptop.system.dtm: Assertion failed: Conflicting updates for dmiReqValidReg, should not happen.\n    at DebugTransport.scala:203 assert(!(dmiReqValidCheck && io.dmi.req.fire()), \"Conflicting updates for dmiReqValidReg, should not happen.\");\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/DebugTransportModuleJTAG.sv", 159, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/DebugTransportModuleJTAG.sv:160:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: DebugTransportModuleJTAG.sv:161: Assertion failed in %NTestHarness.chiptop.system.dtm\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/DebugTransportModuleJTAG.sv", 161, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_1_a_valid) 
                      & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_opcode))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:129: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor: Assertion failed: 'A' channel carries AcquireBlock type which is unexpected using diplomatic parameters (connected at Debug.scala:697:19)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 129, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv:130:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:131: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 131, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__435(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__435\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_1_a_valid) 
                      & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_opcode))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:135: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor: Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at Debug.scala:697:19)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 135, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv:136:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:137: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 137, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_1_a_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset))) 
                     & (0U != (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:141: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor: Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at Debug.scala:697:19)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 141, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv:142:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:143: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 143, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__436(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__436\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_1_a_valid) 
                      & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_opcode))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:147: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor: Assertion failed: 'A' channel carries AcquirePerm type which is unexpected using diplomatic parameters (connected at Debug.scala:697:19)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 147, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv:148:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:149: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 149, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_1_a_valid) 
                      & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_opcode))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:153: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor: Assertion failed: 'A' channel carries AcquirePerm from a client which does not support Probe (connected at Debug.scala:697:19)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 153, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv:154:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:155: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 155, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__437(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__437\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_1_a_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset))) 
                     & (0U != (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:159: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor: Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at Debug.scala:697:19)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 159, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv:160:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:161: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 161, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_1_a_valid) 
                      & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_opcode))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:165: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor: Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at Debug.scala:697:19)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 165, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv:166:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:167: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 167, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__438(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__438\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_1_a_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset))) 
                     & (~ ((0U == ((0xeU & (8U ^ (0x1ffffffeU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address) 
                                                     >> 3U)))) 
                                   | (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address) 
                                            >> 2U)))) 
                           | (0xaU == (0xfU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address) 
                                               >> 3U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:171: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor: Assertion failed: 'A' channel carries Get type which slave claims it can't support (connected at Debug.scala:697:19)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 171, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv:172:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:173: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 173, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_1_a_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_opcode))) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset))) 
                     & (0U != (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:177: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor: Assertion failed: 'A' channel Get address not aligned to size (connected at Debug.scala:697:19)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 177, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv:178:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_70.sv:179: Assertion failed in %NTestHarness.chiptop.system.tlDM.dmOuter.dmOuter.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_70.sv", 179, "");
        }
    }
}
