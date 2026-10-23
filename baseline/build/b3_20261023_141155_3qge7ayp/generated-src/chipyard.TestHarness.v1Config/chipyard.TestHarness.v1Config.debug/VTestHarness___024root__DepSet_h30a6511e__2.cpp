// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness__Syms.h"
#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__147(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__147\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (3U & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__full)
                                       ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__saved_param)
                                       : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                          >> 0x12U)) 
                                     >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:443: Assertion failed in %NTestHarness.ram.rom.monitor: Assertion failed: 'A' channel Hint carries invalid opcode param (connected at SerialAdapter.scala:472:12)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 443, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv:444:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:445: Assertion failed in %NTestHarness.ram.rom.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 445, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__full)
                          ? 0xffU : (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                                              >> 1U))) 
                        != ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:449: Assertion failed in %NTestHarness.ram.rom.monitor: Assertion failed: 'A' channel Hint contains invalid mask (connected at SerialAdapter.scala:472:12)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 449, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv:450:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:451: Assertion failed in %NTestHarness.ram.rom.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 451, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__148(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__148\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_h038db5e5__0;
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__full)
                         ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__saved_corrupt)
                         : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                            >> 9U))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:455: Assertion failed in %NTestHarness.ram.rom.monitor: Assertion failed: 'A' channel Hint is corrupt (connected at SerialAdapter.scala:472:12)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 455, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv:456:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:457: Assertion failed in %NTestHarness.ram.rom.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 457, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x9fU < (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:461: Assertion failed in %NTestHarness.ram.rom.monitor: Assertion failed: 'D' channel AccessAckData carries invalid source ID (connected at SerialAdapter.scala:472:12)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 461, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv:462:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:463: Assertion failed in %NTestHarness.ram.rom.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 463, "");
        }
    }
    VL_SHIFTR_WWI(160,160,8, __Vtemp_h038db5e5__0, vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__inflight, (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_source));
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__a_first_done) 
                      & (~ (IData)(vlSelf->reset))) 
                     & __Vtemp_h038db5e5__0[0U]))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:467: Assertion failed in %NTestHarness.ram.rom.monitor: Assertion failed: 'A' channel re-used a source ID (connected at SerialAdapter.scala:472:12)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 467, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv:468:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:469: Assertion failed in %NTestHarness.ram.rom.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 469, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__149(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__149\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_h038db5e5__0;
    // Body
    VL_SHIFTR_WWI(160,160,8, __Vtemp_h038db5e5__0, vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__inflight, (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_source));
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (__Vtemp_h038db5e5__0[0U] 
                           | (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:473: Assertion failed in %NTestHarness.ram.rom.monitor: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at SerialAdapter.scala:472:12)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 473, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv:474:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:475: Assertion failed in %NTestHarness.ram.rom.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 475, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ ((1U == ((0x17U >= (0x1fU 
                                              & ((IData)(3U) 
                                                 * (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_opcode))))
                                    ? (7U & (0x911240U 
                                             >> (0x1fU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_opcode)))))
                                    : 0U)) | (1U == 
                                              ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_opcode))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_opcode)))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:479: Assertion failed in %NTestHarness.ram.rom.monitor: Assertion failed: 'D' channel contains improper opcode response (connected at SerialAdapter.scala:472:12)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 479, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv:480:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:481: Assertion failed in %NTestHarness.ram.rom.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 481, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__151(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__151\n"); );
    // Init
    VlWide<20>/*639:0*/ __Vtemp_hcfce361e__0;
    VlWide<20>/*639:0*/ __Vtemp_h219dd05f__0;
    // Body
    VL_EXTEND_WI(638,8, __Vtemp_hcfce361e__0, (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_source));
    __Vtemp_h219dd05f__0[0U] = (__Vtemp_hcfce361e__0[0U] 
                                << 2U);
    __Vtemp_h219dd05f__0[1U] = ((__Vtemp_hcfce361e__0[0U] 
                                 >> 0x1eU) | (__Vtemp_hcfce361e__0[1U] 
                                              << 2U));
    __Vtemp_h219dd05f__0[2U] = ((__Vtemp_hcfce361e__0[1U] 
                                 >> 0x1eU) | (__Vtemp_hcfce361e__0[2U] 
                                              << 2U));
    __Vtemp_h219dd05f__0[3U] = ((__Vtemp_hcfce361e__0[2U] 
                                 >> 0x1eU) | (__Vtemp_hcfce361e__0[3U] 
                                              << 2U));
    __Vtemp_h219dd05f__0[4U] = ((__Vtemp_hcfce361e__0[3U] 
                                 >> 0x1eU) | (__Vtemp_hcfce361e__0[4U] 
                                              << 2U));
    __Vtemp_h219dd05f__0[5U] = ((__Vtemp_hcfce361e__0[4U] 
                                 >> 0x1eU) | (__Vtemp_hcfce361e__0[5U] 
                                              << 2U));
    __Vtemp_h219dd05f__0[6U] = ((__Vtemp_hcfce361e__0[5U] 
                                 >> 0x1eU) | (__Vtemp_hcfce361e__0[6U] 
                                              << 2U));
    __Vtemp_h219dd05f__0[7U] = ((__Vtemp_hcfce361e__0[6U] 
                                 >> 0x1eU) | (__Vtemp_hcfce361e__0[7U] 
                                              << 2U));
    __Vtemp_h219dd05f__0[8U] = ((__Vtemp_hcfce361e__0[7U] 
                                 >> 0x1eU) | (__Vtemp_hcfce361e__0[8U] 
                                              << 2U));
    __Vtemp_h219dd05f__0[9U] = ((__Vtemp_hcfce361e__0[8U] 
                                 >> 0x1eU) | (__Vtemp_hcfce361e__0[9U] 
                                              << 2U));
    __Vtemp_h219dd05f__0[0xaU] = ((__Vtemp_hcfce361e__0[9U] 
                                   >> 0x1eU) | (__Vtemp_hcfce361e__0[0xaU] 
                                                << 2U));
    __Vtemp_h219dd05f__0[0xbU] = ((__Vtemp_hcfce361e__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_hcfce361e__0[0xbU] 
                                                << 2U));
    __Vtemp_h219dd05f__0[0xcU] = ((__Vtemp_hcfce361e__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_hcfce361e__0[0xcU] 
                                                << 2U));
    __Vtemp_h219dd05f__0[0xdU] = ((__Vtemp_hcfce361e__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_hcfce361e__0[0xdU] 
                                                << 2U));
    __Vtemp_h219dd05f__0[0xeU] = ((__Vtemp_hcfce361e__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_hcfce361e__0[0xeU] 
                                                << 2U));
    __Vtemp_h219dd05f__0[0xfU] = ((__Vtemp_hcfce361e__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_hcfce361e__0[0xfU] 
                                                << 2U));
    __Vtemp_h219dd05f__0[0x10U] = ((__Vtemp_hcfce361e__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_hcfce361e__0[0x10U] 
                                                 << 2U));
    __Vtemp_h219dd05f__0[0x11U] = ((__Vtemp_hcfce361e__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_hcfce361e__0[0x11U] 
                                                 << 2U));
    __Vtemp_h219dd05f__0[0x12U] = ((__Vtemp_hcfce361e__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_hcfce361e__0[0x12U] 
                                                 << 2U));
    __Vtemp_h219dd05f__0[0x13U] = ((__Vtemp_hcfce361e__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_hcfce361e__0[0x13U] 
                                                 << 2U));
    if (VL_UNLIKELY((0xfffffffeU & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output) 
                                    & (~ (IData)(vlSelf->reset)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:503: Assertion failed in %NTestHarness.ram.rom.monitor: Assertion failed: ready check\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 503, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv:504:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:505: Assertion failed in %NTestHarness.ram.rom.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 505, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__152(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__152\n"); );
    // Body
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->reset)) 
                           & (~ (((0U == ((((vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__inflight[0U] 
                                             | vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__inflight[1U]) 
                                            | vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__inflight[2U]) 
                                           | vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__inflight[3U]) 
                                          | vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__inflight[4U])) 
                                  | (0U == vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__plusarg_reader__DOT__myplus)) 
                                 | (vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__watchdog 
                                    < vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__plusarg_reader__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:509: Assertion failed in %NTestHarness.ram.rom.monitor: Assertion failed: TileLink timeout expired (connected at SerialAdapter.scala:472:12)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 509, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv:510:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_84.sv:511: Assertion failed in %NTestHarness.ram.rom.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_84.sv", 511, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                      & (6U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:187: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel carries AcquireBlock type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 187, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:188:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:189: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 189, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                      & (6U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:193: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 193, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:194:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:195: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 195, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__153(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__153\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x9fU < (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:199: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel AcquireBlock carries invalid source ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 199, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:200:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:201: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 201, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (IData)((3U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:205: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 205, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:206:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:207: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 207, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address 
                                     & (~ (0x3fU & 
                                           ((IData)(7U) 
                                            << (3U 
                                                & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:211: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 211, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:212:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:213: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 213, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__154(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__154\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (2U < (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                                     ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_param)
                                     : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                        >> 0x12U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:217: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel AcquireBlock carries invalid grow param (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 217, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:218:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:219: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 219, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0xffU != (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_mask))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:223: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 223, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:224:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:225: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 225, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                         ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt)
                         : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                            >> 9U))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:229: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel AcquireBlock is corrupt (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 229, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:230:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:231: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 231, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__155(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__155\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                      & (7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:235: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel carries AcquirePerm type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 235, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:236:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:237: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 237, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                      & (7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:241: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel carries AcquirePerm from a client which does not support Probe (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 241, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:242:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:243: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 243, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x9fU < (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:247: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel AcquirePerm carries invalid source ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 247, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:248:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:249: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 249, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__156(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__156\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (IData)((3U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:253: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 253, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:254:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:255: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 255, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address 
                                     & (~ (0x3fU & 
                                           ((IData)(7U) 
                                            << (3U 
                                                & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:259: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 259, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:260:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:261: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 261, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__157(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__157\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (2U < (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                                     ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_param)
                                     : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                        >> 0x12U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:265: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel AcquirePerm carries invalid grow param (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 265, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:266:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:267: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 267, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U == (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                                      ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_param)
                                      : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                         >> 0x12U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:271: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 271, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:272:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:273: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 273, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__158(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__158\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0xffU != (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_mask))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:277: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 277, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:278:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:279: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 279, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                         ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt)
                         : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                            >> 9U))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:283: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel AcquirePerm is corrupt (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 283, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:284:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:285: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 285, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x9fU < (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:289: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel carries Get type which master claims it can't emit (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 289, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:290:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:291: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 291, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__159(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__159\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x10000U != (0x1ffffU & (vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address 
                                                 >> 0xcU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:295: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel carries Get type which slave claims it can't support (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 295, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:296:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:297: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 297, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x9fU < (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:301: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Get carries invalid source ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 301, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:302:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:303: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 303, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address 
                                     & (~ (0x3fU & 
                                           ((IData)(7U) 
                                            << (3U 
                                                & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:307: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Get address not aligned to size (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 307, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:308:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:309: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 309, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__160(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__160\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                                      ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_param)
                                      : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                         >> 0x12U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:313: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Get carries invalid param (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 313, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:314:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:315: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 315, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:319: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Get contains invalid mask (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 319, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:320:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:321: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 321, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__161(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__161\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                         ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt)
                         : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                            >> 9U))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:325: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Get is corrupt (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 325, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:326:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:327: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 327, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (IData)(((0x10000000U == 
                                    (0x1ffff000U & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                   & (0xa0U > (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:331: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel carries PutFull type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 331, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:332:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:333: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 333, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__162(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__162\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x9fU < (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:337: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel PutFull carries invalid source ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 337, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:338:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:339: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 339, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address 
                                     & (~ (0x3fU & 
                                           ((IData)(7U) 
                                            << (3U 
                                                & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:343: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel PutFull address not aligned to size (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 343, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:344:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:345: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 345, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__163(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__163\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                                      ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_param)
                                      : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                         >> 0x12U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:349: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel PutFull carries invalid param (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 349, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:350:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:351: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 351, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:355: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel PutFull contains invalid mask (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 355, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:356:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:357: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 357, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__164(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__164\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (IData)(((0x10000000U == 
                                    (0x1ffff000U & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                   & (0xa0U > (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:361: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel carries PutPartial type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 361, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:362:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:363: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 363, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x9fU < (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:367: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel PutPartial carries invalid source ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 367, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:368:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:369: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 369, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address 
                                     & (~ (0x3fU & 
                                           ((IData)(7U) 
                                            << (3U 
                                                & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:373: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel PutPartial address not aligned to size (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 373, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:374:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:375: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 375, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__165(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__165\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                                      ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_param)
                                      : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                         >> 0x12U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:379: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel PutPartial carries invalid param (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 379, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:380:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:381: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 381, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != ((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_mask) 
                               & (~ ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                       | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                          & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                      << 7U) | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                                  | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                                     & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                                 << 6U) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                        & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                    << 5U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                        | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                           & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                                       << 4U) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                              & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                          << 3U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                                 & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                                             << 2U) 
                                                            | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                    & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                                << 1U) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                  | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                     & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:385: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel PutPartial contains invalid mask (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 385, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:386:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:387: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 387, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__166(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__166\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                      & (2U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:391: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel carries Arithmetic type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 391, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:392:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:393: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 393, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x9fU < (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:397: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Arithmetic carries invalid source ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 397, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:398:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:399: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 399, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address 
                                     & (~ (0x3fU & 
                                           ((IData)(7U) 
                                            << (3U 
                                                & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:403: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 403, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:404:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:405: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 405, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__167(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__167\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (4U < (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                                     ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_param)
                                     : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                        >> 0x12U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:409: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Arithmetic carries invalid opcode param (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 409, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:410:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:411: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 411, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:415: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 415, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:416:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:417: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 417, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__168(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__168\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                      & (3U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:421: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel carries Logical type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 421, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:422:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:423: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 423, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x9fU < (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:427: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Logical carries invalid source ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 427, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:428:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:429: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 429, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address 
                                     & (~ (0x3fU & 
                                           ((IData)(7U) 
                                            << (3U 
                                                & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:433: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Logical address not aligned to size (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 433, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:434:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:435: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 435, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__169(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__169\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                          ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_param)
                          : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                             >> 0x12U)) >> 2U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:439: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Logical carries invalid opcode param (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 439, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:440:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:441: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 441, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:445: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Logical contains invalid mask (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 445, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:446:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:447: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 447, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__170(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__170\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                      & (5U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:451: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel carries Hint type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 451, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:452:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:453: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 453, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x9fU < (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:457: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Hint carries invalid source ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 457, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:458:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:459: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 459, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address 
                                     & (~ (0x3fU & 
                                           ((IData)(7U) 
                                            << (3U 
                                                & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:463: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Hint address not aligned to size (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 463, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:464:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:465: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 465, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__171(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__171\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (3U & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                                       ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_param)
                                       : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                          >> 0x12U)) 
                                     >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:469: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Hint carries invalid opcode param (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 469, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:470:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:471: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 471, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:475: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Hint contains invalid mask (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 475, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:476:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:477: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 477, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__172(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__172\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                         ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt)
                         : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                            >> 9U))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:481: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel Hint is corrupt (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 481, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:482:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:483: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 483, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (7U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:487: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel has invalid opcode (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 487, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:488:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:489: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 489, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x9fU < (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 7U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:493: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel ReleaseAck carries invalid source ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 493, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:494:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:495: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 495, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__173(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__173\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (3U != (3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 5U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:499: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel ReleaseAck smaller than a beat (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 499, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:500:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:501: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 501, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:505: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel ReleaseeAck carries invalid param (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 505, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:506:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:507: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 507, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__174(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__174\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                        >> 0x11U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:511: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel ReleaseAck is corrupt (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 511, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:512:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:513: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 513, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x10006U == (0x10007U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:517: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel ReleaseAck is denied (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 517, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:518:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:519: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 519, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__175(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__175\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x9fU < (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 7U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:523: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel Grant carries invalid source ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 523, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:524:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:525: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 525, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (4U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:529: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel Grant carries invalid sink ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 529, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:530:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:531: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 531, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (3U != (3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 5U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:535: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel Grant smaller than a beat (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 535, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:536:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:537: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 537, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__176(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__176\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x1cU == (0x1fU & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:541: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel Grant carries invalid cap param (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 541, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:542:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:543: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 543, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x14U == (0x1fU & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:547: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel Grant carries toN param (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 547, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:548:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:549: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 549, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__177(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__177\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (4U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                        >> 0x11U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:553: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel Grant is corrupt (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 553, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:554:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:555: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 555, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x10004U == (0x10007U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:559: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel Grant is denied (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 559, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:560:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:561: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 561, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__178(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__178\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x9fU < (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 7U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:565: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel GrantData carries invalid source ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 565, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:566:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:567: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 567, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (5U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:571: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel GrantData carries invalid sink ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 571, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:572:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:573: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 573, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (3U != (3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 5U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:577: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel GrantData smaller than a beat (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 577, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:578:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:579: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 579, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__179(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__179\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x1dU == (0x1fU & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:583: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel GrantData carries invalid cap param (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 583, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:584:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:585: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 585, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x15U == (0x1fU & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:589: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel GrantData carries toN param (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 589, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:590:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:591: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 591, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__180(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__180\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (5U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ ((~ (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                               >> 0x10U)) | (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                             >> 0x11U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:595: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel GrantData is denied but not corrupt (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 595, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:596:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:597: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 597, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x10005U == (0x10007U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:601: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel GrantData is denied (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 601, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:602:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:603: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 603, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__181(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__181\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x9fU < (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 7U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:607: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel AccessAck carries invalid source ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 607, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:608:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:609: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 609, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:613: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel AccessAck carries invalid param (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 613, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:614:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:615: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 615, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__182(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__182\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (0U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                        >> 0x11U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:619: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel AccessAck is corrupt (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 619, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:620:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:621: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 621, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x10000U == (0x10007U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:625: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel AccessAck is denied (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 625, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:626:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:627: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 627, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__183(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__183\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (1U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x9fU < (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 7U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:631: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel AccessAckData carries invalid source ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 631, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:632:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:633: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 633, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (1U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:637: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel AccessAckData carries invalid param (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 637, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:638:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:639: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 639, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__184(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__184\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (1U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ ((~ (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                               >> 0x10U)) | (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                             >> 0x11U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:643: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel AccessAckData is denied but not corrupt (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 643, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:644:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:645: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 645, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x10001U == (0x10007U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:649: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel AccessAckData is denied (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 649, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:650:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:651: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 651, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__185(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__185\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0x9fU < (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 7U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:655: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel HintAck carries invalid source ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 655, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:656:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:657: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 657, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 3U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:661: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel HintAck carries invalid param (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 661, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:662:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:663: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 663, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__186(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__186\n"); );
    // Body
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (2U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                        >> 0x11U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:667: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel HintAck is corrupt (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 667, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:668:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:669: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 669, "");
        }
    }
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (0x10002U == (0x10007U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:673: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel HintAck is denied (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 673, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:674:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:675: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 675, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__187(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__187\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_hb5f22851__0;
    VlWide<5>/*159:0*/ __Vtemp_hf17a7492__0;
    VlWide<5>/*159:0*/ __Vtemp_h1efe4437__0;
    // Body
    VL_SHIFTR_WWI(160,160,8, __Vtemp_hb5f22851__0, vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__inflight, (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source));
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__a_first_done) 
                      & (~ (IData)(vlSelf->reset))) 
                     & __Vtemp_hb5f22851__0[0U]))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:679: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' channel re-used a source ID (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 679, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:680:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:681: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 681, "");
        }
    }
    VL_EXTEND_WI(160,8, __Vtemp_hf17a7492__0, (0xffU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 7U)));
    VL_SHIFTR_WWW(160,160,160, __Vtemp_h1efe4437__0, vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__inflight, __Vtemp_hf17a7492__0);
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT___T_617) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (__Vtemp_h1efe4437__0[0U] 
                           | (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__same_cycle_resp)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:685: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 685, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:686:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:687: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 687, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT___T_617) 
                       & (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__same_cycle_resp)) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (((7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode)))))
                                 : 0U)) | ((7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode)))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:691: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel contains improper opcode response (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 691, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:692:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:693: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 693, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__188(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__188\n"); );
    // Init
    VlWide<20>/*639:0*/ __Vtemp_hf133203c__0;
    VlWide<20>/*639:0*/ __Vtemp_h781a1a9b__0;
    VlWide<20>/*639:0*/ __Vtemp_h8b0ee2d8__0;
    VlWide<20>/*639:0*/ __Vtemp_hf133203c__1;
    VlWide<20>/*639:0*/ __Vtemp_h559c872e__0;
    VlWide<20>/*639:0*/ __Vtemp_hdfa6a57d__0;
    VlWide<20>/*639:0*/ __Vtemp_hf133203c__2;
    VlWide<20>/*639:0*/ __Vtemp_h80674d83__0;
    VlWide<20>/*639:0*/ __Vtemp_hd6879eff__0;
    VlWide<20>/*639:0*/ __Vtemp_hf133203c__3;
    VlWide<20>/*639:0*/ __Vtemp_ha998d71a__0;
    VlWide<20>/*639:0*/ __Vtemp_hbe20bd22__0;
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT___T_617) 
                       & (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__same_cycle_resp)) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag)) 
                        != (3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                  >> 5U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:697: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel contains improper response size (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 697, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:698:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:699: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 699, "");
        }
    }
    VL_EXTEND_WI(638,8, __Vtemp_hf133203c__0, (0xffU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 7U)));
    __Vtemp_h781a1a9b__0[0U] = (__Vtemp_hf133203c__0[0U] 
                                << 2U);
    __Vtemp_h781a1a9b__0[1U] = ((__Vtemp_hf133203c__0[0U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[1U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[2U] = ((__Vtemp_hf133203c__0[1U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[2U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[3U] = ((__Vtemp_hf133203c__0[2U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[3U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[4U] = ((__Vtemp_hf133203c__0[3U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[4U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[5U] = ((__Vtemp_hf133203c__0[4U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[5U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[6U] = ((__Vtemp_hf133203c__0[5U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[6U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[7U] = ((__Vtemp_hf133203c__0[6U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[7U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[8U] = ((__Vtemp_hf133203c__0[7U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[8U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[9U] = ((__Vtemp_hf133203c__0[8U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[9U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[0xaU] = ((__Vtemp_hf133203c__0[9U] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__0[0xaU] 
                                                << 2U));
    __Vtemp_h781a1a9b__0[0xbU] = ((__Vtemp_hf133203c__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__0[0xbU] 
                                                << 2U));
    __Vtemp_h781a1a9b__0[0xcU] = ((__Vtemp_hf133203c__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__0[0xcU] 
                                                << 2U));
    __Vtemp_h781a1a9b__0[0xdU] = ((__Vtemp_hf133203c__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__0[0xdU] 
                                                << 2U));
    __Vtemp_h781a1a9b__0[0xeU] = ((__Vtemp_hf133203c__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__0[0xeU] 
                                                << 2U));
    __Vtemp_h781a1a9b__0[0xfU] = ((__Vtemp_hf133203c__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__0[0xfU] 
                                                << 2U));
    __Vtemp_h781a1a9b__0[0x10U] = ((__Vtemp_hf133203c__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__0[0x10U] 
                                                 << 2U));
    __Vtemp_h781a1a9b__0[0x11U] = ((__Vtemp_hf133203c__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__0[0x11U] 
                                                 << 2U));
    __Vtemp_h781a1a9b__0[0x12U] = ((__Vtemp_hf133203c__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__0[0x12U] 
                                                 << 2U));
    __Vtemp_h781a1a9b__0[0x13U] = ((__Vtemp_hf133203c__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__0[0x13U] 
                                                 << 2U));
    VL_SHIFTR_WWW(640,640,640, __Vtemp_h8b0ee2d8__0, vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__inflight_opcodes, __Vtemp_h781a1a9b__0);
    VL_EXTEND_WI(638,8, __Vtemp_hf133203c__1, (0xffU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 7U)));
    __Vtemp_h559c872e__0[0U] = (__Vtemp_hf133203c__1[0U] 
                                << 2U);
    __Vtemp_h559c872e__0[1U] = ((__Vtemp_hf133203c__1[0U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__1[1U] 
                                              << 2U));
    __Vtemp_h559c872e__0[2U] = ((__Vtemp_hf133203c__1[1U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__1[2U] 
                                              << 2U));
    __Vtemp_h559c872e__0[3U] = ((__Vtemp_hf133203c__1[2U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__1[3U] 
                                              << 2U));
    __Vtemp_h559c872e__0[4U] = ((__Vtemp_hf133203c__1[3U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__1[4U] 
                                              << 2U));
    __Vtemp_h559c872e__0[5U] = ((__Vtemp_hf133203c__1[4U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__1[5U] 
                                              << 2U));
    __Vtemp_h559c872e__0[6U] = ((__Vtemp_hf133203c__1[5U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__1[6U] 
                                              << 2U));
    __Vtemp_h559c872e__0[7U] = ((__Vtemp_hf133203c__1[6U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__1[7U] 
                                              << 2U));
    __Vtemp_h559c872e__0[8U] = ((__Vtemp_hf133203c__1[7U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__1[8U] 
                                              << 2U));
    __Vtemp_h559c872e__0[9U] = ((__Vtemp_hf133203c__1[8U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__1[9U] 
                                              << 2U));
    __Vtemp_h559c872e__0[0xaU] = ((__Vtemp_hf133203c__1[9U] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__1[0xaU] 
                                                << 2U));
    __Vtemp_h559c872e__0[0xbU] = ((__Vtemp_hf133203c__1[0xaU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__1[0xbU] 
                                                << 2U));
    __Vtemp_h559c872e__0[0xcU] = ((__Vtemp_hf133203c__1[0xbU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__1[0xcU] 
                                                << 2U));
    __Vtemp_h559c872e__0[0xdU] = ((__Vtemp_hf133203c__1[0xcU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__1[0xdU] 
                                                << 2U));
    __Vtemp_h559c872e__0[0xeU] = ((__Vtemp_hf133203c__1[0xdU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__1[0xeU] 
                                                << 2U));
    __Vtemp_h559c872e__0[0xfU] = ((__Vtemp_hf133203c__1[0xeU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__1[0xfU] 
                                                << 2U));
    __Vtemp_h559c872e__0[0x10U] = ((__Vtemp_hf133203c__1[0xfU] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__1[0x10U] 
                                                 << 2U));
    __Vtemp_h559c872e__0[0x11U] = ((__Vtemp_hf133203c__1[0x10U] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__1[0x11U] 
                                                 << 2U));
    __Vtemp_h559c872e__0[0x12U] = ((__Vtemp_hf133203c__1[0x11U] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__1[0x12U] 
                                                 << 2U));
    __Vtemp_h559c872e__0[0x13U] = ((__Vtemp_hf133203c__1[0x12U] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__1[0x13U] 
                                                 << 2U));
    VL_SHIFTR_WWW(640,640,640, __Vtemp_hdfa6a57d__0, vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__inflight_opcodes, __Vtemp_h559c872e__0);
    VL_EXTEND_WI(638,8, __Vtemp_hf133203c__2, (0xffU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 7U)));
    __Vtemp_h80674d83__0[0U] = (__Vtemp_hf133203c__2[0U] 
                                << 2U);
    __Vtemp_h80674d83__0[1U] = ((__Vtemp_hf133203c__2[0U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__2[1U] 
                                              << 2U));
    __Vtemp_h80674d83__0[2U] = ((__Vtemp_hf133203c__2[1U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__2[2U] 
                                              << 2U));
    __Vtemp_h80674d83__0[3U] = ((__Vtemp_hf133203c__2[2U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__2[3U] 
                                              << 2U));
    __Vtemp_h80674d83__0[4U] = ((__Vtemp_hf133203c__2[3U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__2[4U] 
                                              << 2U));
    __Vtemp_h80674d83__0[5U] = ((__Vtemp_hf133203c__2[4U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__2[5U] 
                                              << 2U));
    __Vtemp_h80674d83__0[6U] = ((__Vtemp_hf133203c__2[5U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__2[6U] 
                                              << 2U));
    __Vtemp_h80674d83__0[7U] = ((__Vtemp_hf133203c__2[6U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__2[7U] 
                                              << 2U));
    __Vtemp_h80674d83__0[8U] = ((__Vtemp_hf133203c__2[7U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__2[8U] 
                                              << 2U));
    __Vtemp_h80674d83__0[9U] = ((__Vtemp_hf133203c__2[8U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__2[9U] 
                                              << 2U));
    __Vtemp_h80674d83__0[0xaU] = ((__Vtemp_hf133203c__2[9U] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__2[0xaU] 
                                                << 2U));
    __Vtemp_h80674d83__0[0xbU] = ((__Vtemp_hf133203c__2[0xaU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__2[0xbU] 
                                                << 2U));
    __Vtemp_h80674d83__0[0xcU] = ((__Vtemp_hf133203c__2[0xbU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__2[0xcU] 
                                                << 2U));
    __Vtemp_h80674d83__0[0xdU] = ((__Vtemp_hf133203c__2[0xcU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__2[0xdU] 
                                                << 2U));
    __Vtemp_h80674d83__0[0xeU] = ((__Vtemp_hf133203c__2[0xdU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__2[0xeU] 
                                                << 2U));
    __Vtemp_h80674d83__0[0xfU] = ((__Vtemp_hf133203c__2[0xeU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__2[0xfU] 
                                                << 2U));
    __Vtemp_h80674d83__0[0x10U] = ((__Vtemp_hf133203c__2[0xfU] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__2[0x10U] 
                                                 << 2U));
    __Vtemp_h80674d83__0[0x11U] = ((__Vtemp_hf133203c__2[0x10U] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__2[0x11U] 
                                                 << 2U));
    __Vtemp_h80674d83__0[0x12U] = ((__Vtemp_hf133203c__2[0x11U] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__2[0x12U] 
                                                 << 2U));
    __Vtemp_h80674d83__0[0x13U] = ((__Vtemp_hf133203c__2[0x12U] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__2[0x13U] 
                                                 << 2U));
    VL_SHIFTR_WWW(640,640,640, __Vtemp_hd6879eff__0, vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__inflight_opcodes, __Vtemp_h80674d83__0);
    VL_EXTEND_WI(638,8, __Vtemp_hf133203c__3, (0xffU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 7U)));
    __Vtemp_ha998d71a__0[0U] = (__Vtemp_hf133203c__3[0U] 
                                << 2U);
    __Vtemp_ha998d71a__0[1U] = ((__Vtemp_hf133203c__3[0U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__3[1U] 
                                              << 2U));
    __Vtemp_ha998d71a__0[2U] = ((__Vtemp_hf133203c__3[1U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__3[2U] 
                                              << 2U));
    __Vtemp_ha998d71a__0[3U] = ((__Vtemp_hf133203c__3[2U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__3[3U] 
                                              << 2U));
    __Vtemp_ha998d71a__0[4U] = ((__Vtemp_hf133203c__3[3U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__3[4U] 
                                              << 2U));
    __Vtemp_ha998d71a__0[5U] = ((__Vtemp_hf133203c__3[4U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__3[5U] 
                                              << 2U));
    __Vtemp_ha998d71a__0[6U] = ((__Vtemp_hf133203c__3[5U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__3[6U] 
                                              << 2U));
    __Vtemp_ha998d71a__0[7U] = ((__Vtemp_hf133203c__3[6U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__3[7U] 
                                              << 2U));
    __Vtemp_ha998d71a__0[8U] = ((__Vtemp_hf133203c__3[7U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__3[8U] 
                                              << 2U));
    __Vtemp_ha998d71a__0[9U] = ((__Vtemp_hf133203c__3[8U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__3[9U] 
                                              << 2U));
    __Vtemp_ha998d71a__0[0xaU] = ((__Vtemp_hf133203c__3[9U] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__3[0xaU] 
                                                << 2U));
    __Vtemp_ha998d71a__0[0xbU] = ((__Vtemp_hf133203c__3[0xaU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__3[0xbU] 
                                                << 2U));
    __Vtemp_ha998d71a__0[0xcU] = ((__Vtemp_hf133203c__3[0xbU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__3[0xcU] 
                                                << 2U));
    __Vtemp_ha998d71a__0[0xdU] = ((__Vtemp_hf133203c__3[0xcU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__3[0xdU] 
                                                << 2U));
    __Vtemp_ha998d71a__0[0xeU] = ((__Vtemp_hf133203c__3[0xdU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__3[0xeU] 
                                                << 2U));
    __Vtemp_ha998d71a__0[0xfU] = ((__Vtemp_hf133203c__3[0xeU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__3[0xfU] 
                                                << 2U));
    __Vtemp_ha998d71a__0[0x10U] = ((__Vtemp_hf133203c__3[0xfU] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__3[0x10U] 
                                                 << 2U));
    __Vtemp_ha998d71a__0[0x11U] = ((__Vtemp_hf133203c__3[0x10U] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__3[0x11U] 
                                                 << 2U));
    __Vtemp_ha998d71a__0[0x12U] = ((__Vtemp_hf133203c__3[0x11U] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__3[0x12U] 
                                                 << 2U));
    __Vtemp_ha998d71a__0[0x13U] = ((__Vtemp_hf133203c__3[0x12U] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__3[0x13U] 
                                                 << 2U));
    VL_SHIFTR_WWW(640,640,640, __Vtemp_hbe20bd22__0, vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__inflight_opcodes, __Vtemp_ha998d71a__0);
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT___T_617) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__same_cycle_resp))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (((7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & 
                                               (__Vtemp_h8b0ee2d8__0[0U] 
                                                >> 1U)))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & (__Vtemp_hdfa6a57d__0[0U] 
                                                     >> 1U))))))
                                 : 0U)) | ((7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & (__Vtemp_hd6879eff__0[0U] 
                                                        >> 1U)))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & (__Vtemp_hbe20bd22__0[0U] 
                                                              >> 1U))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:703: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel contains improper opcode response (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 703, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:704:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:705: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 705, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__189(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__189\n"); );
    // Init
    VlWide<20>/*639:0*/ __Vtemp_hf133203c__0;
    VlWide<20>/*639:0*/ __Vtemp_h781a1a9b__0;
    VlWide<20>/*639:0*/ __Vtemp_h7a9cb428__0;
    // Body
    VL_EXTEND_WI(638,8, __Vtemp_hf133203c__0, (0xffU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 7U)));
    __Vtemp_h781a1a9b__0[0U] = (__Vtemp_hf133203c__0[0U] 
                                << 2U);
    __Vtemp_h781a1a9b__0[1U] = ((__Vtemp_hf133203c__0[0U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[1U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[2U] = ((__Vtemp_hf133203c__0[1U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[2U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[3U] = ((__Vtemp_hf133203c__0[2U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[3U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[4U] = ((__Vtemp_hf133203c__0[3U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[4U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[5U] = ((__Vtemp_hf133203c__0[4U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[5U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[6U] = ((__Vtemp_hf133203c__0[5U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[6U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[7U] = ((__Vtemp_hf133203c__0[6U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[7U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[8U] = ((__Vtemp_hf133203c__0[7U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[8U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[9U] = ((__Vtemp_hf133203c__0[8U] 
                                 >> 0x1eU) | (__Vtemp_hf133203c__0[9U] 
                                              << 2U));
    __Vtemp_h781a1a9b__0[0xaU] = ((__Vtemp_hf133203c__0[9U] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__0[0xaU] 
                                                << 2U));
    __Vtemp_h781a1a9b__0[0xbU] = ((__Vtemp_hf133203c__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__0[0xbU] 
                                                << 2U));
    __Vtemp_h781a1a9b__0[0xcU] = ((__Vtemp_hf133203c__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__0[0xcU] 
                                                << 2U));
    __Vtemp_h781a1a9b__0[0xdU] = ((__Vtemp_hf133203c__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__0[0xdU] 
                                                << 2U));
    __Vtemp_h781a1a9b__0[0xeU] = ((__Vtemp_hf133203c__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__0[0xeU] 
                                                << 2U));
    __Vtemp_h781a1a9b__0[0xfU] = ((__Vtemp_hf133203c__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_hf133203c__0[0xfU] 
                                                << 2U));
    __Vtemp_h781a1a9b__0[0x10U] = ((__Vtemp_hf133203c__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__0[0x10U] 
                                                 << 2U));
    __Vtemp_h781a1a9b__0[0x11U] = ((__Vtemp_hf133203c__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__0[0x11U] 
                                                 << 2U));
    __Vtemp_h781a1a9b__0[0x12U] = ((__Vtemp_hf133203c__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__0[0x12U] 
                                                 << 2U));
    __Vtemp_h781a1a9b__0[0x13U] = ((__Vtemp_hf133203c__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_hf133203c__0[0x13U] 
                                                 << 2U));
    VL_SHIFTR_WWW(640,640,640, __Vtemp_h7a9cb428__0, vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__inflight_sizes, __Vtemp_h781a1a9b__0);
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT___T_617) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__same_cycle_resp))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                               >> 5U)) != (7U & (__Vtemp_h7a9cb428__0[0U] 
                                                 >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:709: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel contains improper response size (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 709, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:710:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:711: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 711, "");
        }
    }
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                         & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)) 
                        & ((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source) 
                           == (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 7U)))) & 
                       (6U != (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__x1_d_ready)) 
                           | (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__full))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:715: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: ready check\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 715, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:716:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:717: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 717, "");
        }
    }
}

extern const VlWide<8>/*255:0*/ VTestHarness__ConstPool__CONST_h4e9f510d_0;

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__190(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__190\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_hffaea87a__0;
    VlWide<8>/*255:0*/ __Vtemp_ha0eee9e6__0;
    VlWide<8>/*255:0*/ __Vtemp_hf19c6844__0;
    VlWide<8>/*255:0*/ __Vtemp_h98ae10a8__0;
    VlWide<8>/*255:0*/ __Vtemp_hffaea87a__1;
    VlWide<8>/*255:0*/ __Vtemp_h9c823e80__0;
    // Body
    VL_EXTEND_WI(256,8, __Vtemp_hffaea87a__0, (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source));
    VL_SHIFTL_WWW(256,256,256, __Vtemp_ha0eee9e6__0, VTestHarness__ConstPool__CONST_h4e9f510d_0, __Vtemp_hffaea87a__0);
    VL_EXTEND_WI(256,8, __Vtemp_hf19c6844__0, (0xffU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 7U)));
    VL_SHIFTL_WWW(256,256,256, __Vtemp_h98ae10a8__0, VTestHarness__ConstPool__CONST_h4e9f510d_0, __Vtemp_hf19c6844__0);
    VL_EXTEND_WI(256,8, __Vtemp_hffaea87a__1, (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source));
    VL_SHIFTL_WWW(256,256,256, __Vtemp_h9c823e80__0, VTestHarness__ConstPool__CONST_h4e9f510d_0, __Vtemp_hffaea87a__1);
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->reset)) 
                           & (~ ((0U != (((((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                               ? __Vtemp_ha0eee9e6__0[0U]
                                               : 0U) 
                                             ^ (((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                                                 & (6U 
                                                    != 
                                                    (7U 
                                                     & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])))
                                                 ? 
                                                __Vtemp_h98ae10a8__0[0U]
                                                 : 0U)) 
                                            | (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                                 ? 
                                                __Vtemp_ha0eee9e6__0[1U]
                                                 : 0U) 
                                               ^ ((
                                                   (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                                                   & (6U 
                                                      != 
                                                      (7U 
                                                       & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])))
                                                   ? 
                                                  __Vtemp_h98ae10a8__0[1U]
                                                   : 0U))) 
                                           | (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                                ? __Vtemp_ha0eee9e6__0[2U]
                                                : 0U) 
                                              ^ (((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                                                  & (6U 
                                                     != 
                                                     (7U 
                                                      & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])))
                                                  ? 
                                                 __Vtemp_h98ae10a8__0[2U]
                                                  : 0U))) 
                                          | (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                               ? __Vtemp_ha0eee9e6__0[3U]
                                               : 0U) 
                                             ^ (((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                                                 & (6U 
                                                    != 
                                                    (7U 
                                                     & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])))
                                                 ? 
                                                __Vtemp_h98ae10a8__0[3U]
                                                 : 0U))) 
                                         | (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                              ? __Vtemp_ha0eee9e6__0[4U]
                                              : 0U) 
                                            ^ (((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                                                & (6U 
                                                   != 
                                                   (7U 
                                                    & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])))
                                                ? __Vtemp_h98ae10a8__0[4U]
                                                : 0U)))) 
                                 | (0U == ((((((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                                ? __Vtemp_h9c823e80__0[0U]
                                                : 0U) 
                                              | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                                  ? 
                                                 __Vtemp_h9c823e80__0[1U]
                                                  : 0U)) 
                                             | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                                 ? 
                                                __Vtemp_h9c823e80__0[2U]
                                                 : 0U)) 
                                            | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                                ? __Vtemp_h9c823e80__0[3U]
                                                : 0U)) 
                                           | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                               ? __Vtemp_h9c823e80__0[4U]
                                               : 0U))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:721: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'A' and 'D' concurrent, despite minlatency 3 (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 721, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:722:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:723: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 723, "");
        }
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->reset)) 
                           & (~ (((0U == ((((vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__inflight[0U] 
                                             | vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__inflight[1U]) 
                                            | vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__inflight[2U]) 
                                           | vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__inflight[3U]) 
                                          | vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__inflight[4U])) 
                                  | (0U == vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__plusarg_reader__DOT__myplus)) 
                                 | (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__watchdog 
                                    < vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__plusarg_reader__DOT__myplus))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:727: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: TileLink timeout expired (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 727, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:728:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:729: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 729, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__191(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__191\n"); );
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                      & (6U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:733: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 733, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:734:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:735: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 735, "");
        }
    }
    if (VL_UNLIKELY(((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                       & (6U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 5U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:739: Assertion failed in %NTestHarness.ram.buffer.monitor: Assertion failed: 'D' channel contains improper response size (connected at SerialAdapter.scala:471:45)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 739, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv:740:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_86.sv:741: Assertion failed in %NTestHarness.ram.buffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_86.sv", 741, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                      & (0xc00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:274: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel carries AcquireBlock type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 274, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:275:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:276: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 276, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__192(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__192\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                      & (0xc00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:280: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 280, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:281:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:282: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 282, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0xc00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (9U < (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                      >> 0xaU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:286: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel AcquireBlock carries invalid source ID (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 286, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:287:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:288: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 288, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0xc00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (2U >= (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                     >> 0xeU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:292: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 292, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:293:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:294: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 294, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__193(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__193\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0xc00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address 
                                        & (~ ((0xcU 
                                               >= (7U 
                                                   & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                      >> 0xeU)))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << 
                                                     (7U 
                                                      & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                         >> 0xeU))))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:298: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 298, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:299:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:300: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 300, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0xc00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (2U < (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                    >> 0x12U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:304: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel AcquireBlock carries invalid grow param (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 304, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:305:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:306: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 306, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__194(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__194\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0xc00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0xffU != (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                                           >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:310: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 310, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:311:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:312: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 312, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0xc00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                        >> 9U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:316: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel AcquireBlock is corrupt (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 316, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:317:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:318: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 318, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__195(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__195\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                      & (0xe00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:322: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel carries AcquirePerm type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 322, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:323:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:324: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 324, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                      & (0xe00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:328: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel carries AcquirePerm from a client which does not support Probe (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 328, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:329:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:330: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 330, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0xe00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (9U < (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                      >> 0xaU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:334: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel AcquirePerm carries invalid source ID (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 334, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:335:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:336: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 336, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__196(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__196\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0xe00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (2U >= (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                     >> 0xeU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:340: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 340, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:341:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:342: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 342, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0xe00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address 
                                        & (~ ((0xcU 
                                               >= (7U 
                                                   & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                      >> 0xeU)))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << 
                                                     (7U 
                                                      & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                         >> 0xeU))))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:346: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 346, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:347:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:348: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 348, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__197(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__197\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0xe00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (2U < (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                    >> 0x12U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:352: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel AcquirePerm carries invalid grow param (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 352, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:353:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:354: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 354, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                      & (0xe00000U == (0xfc0000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                     & (~ (IData)(vlSelf->reset))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:358: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 358, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:359:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:360: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 360, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__198(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__198\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0xe00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0xffU != (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                                           >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:364: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 364, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:365:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:366: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 366, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0xe00000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                        >> 9U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:370: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel AcquirePerm is corrupt (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 370, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:371:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:372: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 372, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0x800000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (9U < (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                      >> 0xaU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:376: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel carries Get type which master claims it can't emit (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 376, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:377:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:378: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 378, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__199(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__199\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0x800000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ ((7U != (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                         >> 0xeU))) 
                           & ((2U == (0x1fffU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address 
                                                 >> 0x10U))) 
                              | (0x10000U == (0x1ffffU 
                                              & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address 
                                                 >> 0xcU))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:382: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel carries Get type which slave claims it can't support (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 382, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:383:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:384: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 384, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0x800000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (9U < (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                      >> 0xaU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:388: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel Get carries invalid source ID (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 388, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:389:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:390: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 390, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__200(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__200\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0x800000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address 
                                        & (~ ((0xcU 
                                               >= (7U 
                                                   & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                      >> 0xeU)))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << 
                                                     (7U 
                                                      & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                         >> 0xeU))))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:394: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel Get address not aligned to size (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 394, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:395:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:396: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 396, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0x800000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                     >> 0x12U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:400: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel Get carries invalid param (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 400, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:401:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:402: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 402, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__201(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__201\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0x800000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                                  >> 1U)) != ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_5) 
                                                | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_5) 
                                                   & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)) 
                                               << 7U) 
                                              | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_5) 
                                                   | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_5) 
                                                      & (~ vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address))) 
                                                  << 6U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_4) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_4) 
                                                         & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)) 
                                                     << 5U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_4) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_4) 
                                                            & (~ vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address))) 
                                                        << 4U) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_3) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_3) 
                                                               & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)) 
                                                           << 3U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_3) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_3) 
                                                                  & (~ vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address))) 
                                                              << 2U) 
                                                             | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_2) 
                                                                  | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_2) 
                                                                     & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_2) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_2) 
                                                                      & (~ vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:406: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel Get contains invalid mask (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 406, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:407:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:408: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 408, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__202(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__202\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0x800000U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                        >> 9U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:412: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel Get is corrupt (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 412, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:413:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:414: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 414, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (~ (IData)(((0x10000000U == 
                                    (0x1ffff000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)) 
                                   & ((0xaU > (0xfU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                  >> 0xaU))) 
                                      & (7U != (7U 
                                                & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                   >> 0xeU)))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:418: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel carries PutFull type which is unexpected using diplomatic parameters (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 418, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:419:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:420: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 420, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__203(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__203\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (9U < (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                      >> 0xaU)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:424: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel PutFull carries invalid source ID (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 424, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:425:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:426: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 426, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address 
                                        & (~ ((0xcU 
                                               >= (7U 
                                                   & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                      >> 0xeU)))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << 
                                                     (7U 
                                                      & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                         >> 0xeU))))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:430: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel PutFull address not aligned to size (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 430, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:431:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:432: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 432, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__204(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__204\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & (0U != (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                     >> 0x12U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:436: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel PutFull carries invalid param (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 436, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:437:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:438: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 438, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
                       & (0U == (0xe00000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3))) 
                      & (~ (IData)(vlSelf->reset))) 
                     & ((0xffU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                                  >> 1U)) != ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_5) 
                                                | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_5) 
                                                   & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)) 
                                               << 7U) 
                                              | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_5) 
                                                   | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_5) 
                                                      & (~ vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address))) 
                                                  << 6U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_4) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_4) 
                                                         & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)) 
                                                     << 5U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_4) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_4) 
                                                            & (~ vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address))) 
                                                        << 4U) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_3) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_3) 
                                                               & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)) 
                                                           << 3U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_3) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_3) 
                                                                  & (~ vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address))) 
                                                              << 2U) 
                                                             | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_2) 
                                                                  | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_2) 
                                                                     & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_2) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_2) 
                                                                      & (~ vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:442: Assertion failed in %NTestHarness.ram.xbar.monitor: Assertion failed: 'A' channel PutFull contains invalid mask (connected at SerialAdapter.scala:473:8)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 442, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv:443:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_85.sv:444: Assertion failed in %NTestHarness.ram.xbar.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_85.sv", 444, "");
        }
    }
}
