// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VTestHarness__Syms.h"


extern const VlWide<32>/*1023:0*/ VTestHarness__ConstPool__CONST_h2ae7f32a_0;
extern const VlWide<2048>/*65535:0*/ VTestHarness__ConstPool__CONST_h5f0e7fd6_0;

void VTestHarness___024root__trace_chg_sub_39(VTestHarness___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root__trace_chg_sub_39\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 114991);
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__0;
    VlWide<4>/*127:0*/ __Vtemp_h9a9a6856__0;
    VlWide<4>/*127:0*/ __Vtemp_hca162495__0;
    VlWide<3>/*95:0*/ __Vtemp_habc10ff6__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__1;
    VlWide<4>/*127:0*/ __Vtemp_h9a9a6856__1;
    VlWide<4>/*127:0*/ __Vtemp_h0ada6192__0;
    VlWide<3>/*95:0*/ __Vtemp_h501dc7fc__0;
    VlWide<4>/*127:0*/ __Vtemp_hc38f14bc__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__2;
    VlWide<4>/*127:0*/ __Vtemp_h9a9a6856__2;
    VlWide<4>/*127:0*/ __Vtemp_h996bff05__0;
    VlWide<3>/*95:0*/ __Vtemp_h79b535d0__0;
    VlWide<4>/*127:0*/ __Vtemp_h8ff4b457__0;
    VlWide<32>/*1023:0*/ __Vtemp_h9ccbbd94__0;
    VlWide<32>/*1023:0*/ __Vtemp_h940f208b__0;
    VlWide<4>/*127:0*/ __Vtemp_hf845382e__0;
    VlWide<8>/*255:0*/ __Vtemp_h70020078__0;
    VlWide<8>/*255:0*/ __Vtemp_hf7f54520__0;
    VlWide<4>/*127:0*/ __Vtemp_hd69b3694__0;
    VlWide<3>/*95:0*/ __Vtemp_h8b172a8e__0;
    VlWide<5>/*159:0*/ __Vtemp_hfa1b71f5__0;
    VlWide<4>/*127:0*/ __Vtemp_h29dd9bbf__0;
    VlWide<7>/*223:0*/ __Vtemp_h18b80426__0;
    VlWide<8>/*255:0*/ __Vtemp_ha5c2367a__0;
    VlWide<9>/*287:0*/ __Vtemp_h75c96048__0;
    VlWide<8>/*255:0*/ __Vtemp_h33641d2a__0;
    VlWide<32>/*1023:0*/ __Vtemp_h8236c4c9__0;
    VlWide<4>/*127:0*/ __Vtemp_h29dd9bbf__1;
    VlWide<7>/*223:0*/ __Vtemp_hf5eb69f0__0;
    VlWide<8>/*255:0*/ __Vtemp_h00ad6230__0;
    VlWide<9>/*287:0*/ __Vtemp_he55365d9__0;
    VlWide<3>/*95:0*/ __Vtemp_h9c1a87ea__0;
    VlWide<3>/*95:0*/ __Vtemp_h5c7c01b8__0;
    VlWide<3>/*95:0*/ __Vtemp_h8b172a8e__1;
    VlWide<5>/*159:0*/ __Vtemp_h35dfed16__0;
    VlWide<3>/*95:0*/ __Vtemp_hd3f6aa17__0;
    VlWide<3>/*95:0*/ __Vtemp_hacea9cd5__0;
    VlWide<4>/*127:0*/ __Vtemp_h3459872b__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x38U])) {
        bufp->chgBit(oldp+0,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__do_enq));
        bufp->chgWData(oldp+1,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data),113);
        bufp->chgCData(oldp+5,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__aFrag),3);
        bufp->chgCData(oldp+6,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__old_gennum1),3);
        bufp->chgBit(oldp+7,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__source_ok));
        bufp->chgBit(oldp+8,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+9,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+10,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+11,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+12,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+13,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+14,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+15,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+16,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+17,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+18,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                   << 7U) | (0x3fff80U 
                                             & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                                 << 7U) 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)))) 
                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                         & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 0x11U)))) 
                                     << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                 << 5U) 
                                                | (0xfffe0U 
                                                   & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                       << 5U) 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                         >> 0xcU)))) 
                                               | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                       & (~ 
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0x11U)))) 
                                                   << 4U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                       << 3U) 
                                                      | (0x3fff8U 
                                                         & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                             << 3U) 
                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                               >> 0xeU)))) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                             & (~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0x11U)))) 
                                                         << 2U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                             << 1U) 
                                                            | (0xfffeU 
                                                               & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                   << 1U) 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                     >> 0x10U)))) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                 & (~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                     >> 0x11U)))))))))))),8);
        __Vtemp_hc961d23f__0[0U] = 1U;
        __Vtemp_hc961d23f__0[1U] = 0U;
        __Vtemp_hc961d23f__0[2U] = 0U;
        __Vtemp_hc961d23f__0[3U] = 0U;
        VL_EXTEND_WI(128,7, __Vtemp_h9a9a6856__0, (0x7fU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU)));
        VL_SHIFTL_WWW(128,128,128, __Vtemp_hca162495__0, __Vtemp_hc961d23f__0, __Vtemp_h9a9a6856__0);
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___same_cycle_resp_T_1) {
            __Vtemp_habc10ff6__0[0U] = __Vtemp_hca162495__0[0U];
            __Vtemp_habc10ff6__0[1U] = __Vtemp_hca162495__0[1U];
            __Vtemp_habc10ff6__0[2U] = (1U & __Vtemp_hca162495__0[2U]);
        } else {
            __Vtemp_habc10ff6__0[0U] = 0U;
            __Vtemp_habc10ff6__0[1U] = 0U;
            __Vtemp_habc10ff6__0[2U] = 0U;
        }
        bufp->chgWData(oldp+19,(__Vtemp_habc10ff6__0),65);
        bufp->chgBit(oldp+22,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+23,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT____Vcellinp__repeater__io_repeat));
        bufp->chgCData(oldp+24,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT___repeater_io_deq_bits_size),3);
        bufp->chgBit(oldp+25,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode))));
        bufp->chgBit(oldp+26,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__source_ok));
        bufp->chgBit(oldp+27,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+28,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+29,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+30,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+31,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+32,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+33,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+34,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+35,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+36,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+37,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_5) 
                                   << 7U) | (0x3fff80U 
                                             & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_5) 
                                                 << 7U) 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)))) 
                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_5) 
                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_eq_5) 
                                         & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 0x11U)))) 
                                     << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__mask_acc_4) 
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
                                                                     >> 0x11U)))))))))))),8);
        bufp->chgBit(oldp+38,((((((((((((((((((0x20U 
                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source)) 
                                              | (IData)(
                                                        ((0U 
                                                          == 
                                                          (0x78U 
                                                           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                                         & (5U 
                                                            > 
                                                            (7U 
                                                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source)))))) 
                                             | (5U 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                            | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                           | (0x1cU 
                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
                                          | (0x1dU 
                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source))) 
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
                               | (0x40U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source)))));
        bufp->chgBit(oldp+39,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+40,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_0_a_valid));
        bufp->chgSData(oldp+41,((0x3fffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 0x11U))),14);
        bufp->chgBit(oldp+42,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_0_d_ready));
        bufp->chgBit(oldp+43,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__requestAIO_0_0));
        bufp->chgBit(oldp+44,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__requestAIO_0_1));
        bufp->chgBit(oldp+45,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__requestAIO_0_2));
        bufp->chgBit(oldp+46,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__requestAIO_0_3));
        bufp->chgBit(oldp+47,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__requestAIO_0_4));
        bufp->chgBit(oldp+48,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__requestAIO_0_5));
        bufp->chgBit(oldp+49,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__requestAIO_0_6));
        bufp->chgBit(oldp+50,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__requestAIO_0_7));
        bufp->chgBit(oldp+51,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__requestAIO_0_8));
        bufp->chgSData(oldp+52,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__readys_valid),9);
        bufp->chgSData(oldp+53,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__readys_readys),9);
        bufp->chgBit(oldp+54,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_0));
        bufp->chgBit(oldp+55,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_1));
        bufp->chgBit(oldp+56,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_2));
        bufp->chgBit(oldp+57,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_3));
        bufp->chgBit(oldp+58,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_4));
        bufp->chgBit(oldp+59,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_5));
        bufp->chgBit(oldp+60,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_6));
        bufp->chgBit(oldp+61,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_0));
        bufp->chgBit(oldp+62,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_1));
        bufp->chgBit(oldp+63,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_2));
        bufp->chgBit(oldp+64,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_3));
        bufp->chgBit(oldp+65,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_4));
        bufp->chgBit(oldp+66,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_5));
        bufp->chgBit(oldp+67,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_6));
        bufp->chgBit(oldp+68,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_7));
        bufp->chgBit(oldp+69,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_8));
        bufp->chgBit(oldp+70,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__winnerQual_0));
        bufp->chgBit(oldp+71,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__winnerQual_1));
        bufp->chgBit(oldp+72,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__winnerQual_2));
        bufp->chgBit(oldp+73,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__winnerQual_3));
        bufp->chgBit(oldp+74,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__winnerQual_4));
        bufp->chgBit(oldp+75,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__winnerQual_5));
        bufp->chgBit(oldp+76,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__winnerQual_6));
        bufp->chgBit(oldp+77,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__winnerQual_7));
        bufp->chgBit(oldp+78,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__winnerQual_8));
        bufp->chgBit(oldp+79,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_0) 
                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_1))));
        bufp->chgBit(oldp+80,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_0) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_1)) 
                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_2))));
        bufp->chgBit(oldp+81,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_0) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_1)) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_2)) 
                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_3))));
        bufp->chgBit(oldp+82,((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_0) 
                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_1)) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_2)) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_3)) 
                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_4))));
        bufp->chgBit(oldp+83,(((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_0) 
                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_1)) 
                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_2)) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_3)) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_4)) 
                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_5))));
        bufp->chgBit(oldp+84,((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_0) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_1)) 
                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_2)) 
                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_3)) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_4)) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_5)) 
                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__earlyWinner_6))));
        bufp->chgBit(oldp+85,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__source_ok));
        bufp->chgBit(oldp+86,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+87,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+88,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+89,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+90,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+91,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+92,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+93,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+94,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+95,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+96,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_5) 
                                   << 7U) | (0x3fff80U 
                                             & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_5) 
                                                 << 7U) 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)))) 
                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_5) 
                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_5) 
                                         & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 0x11U)))) 
                                     << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_4) 
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
                                                                     >> 0x11U)))))))))))),8);
        bufp->chgBit(oldp+97,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+98,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_deq));
        bufp->chgBit(oldp+99,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__source_ok));
        bufp->chgBit(oldp+100,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+101,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+102,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+103,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+104,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+106,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+107,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+110,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                    << 7U) | (0x3fff80U 
                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                                  << 7U) 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                          & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0x11U)))) 
                                      << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                  << 5U) 
                                                 | (0xfffe0U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                        << 5U) 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 0xcU)))) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                        & (~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0x11U)))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                        << 3U) 
                                                       | (0x3fff8U 
                                                          & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                              << 3U) 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                >> 0xeU)))) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0x11U)))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                              << 1U) 
                                                             | (0xfffeU 
                                                                & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                    << 1U) 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0x10U)))) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0x11U)))))))))))),8);
        __Vtemp_hc961d23f__1[0U] = 1U;
        __Vtemp_hc961d23f__1[1U] = 0U;
        __Vtemp_hc961d23f__1[2U] = 0U;
        __Vtemp_hc961d23f__1[3U] = 0U;
        VL_EXTEND_WI(128,7, __Vtemp_h9a9a6856__1, (0x7fU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU)));
        VL_SHIFTL_WWW(128,128,128, __Vtemp_h0ada6192__0, __Vtemp_hc961d23f__1, __Vtemp_h9a9a6856__1);
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___same_cycle_resp_T_1) {
            __Vtemp_h501dc7fc__0[0U] = __Vtemp_h0ada6192__0[0U];
            __Vtemp_h501dc7fc__0[1U] = __Vtemp_h0ada6192__0[1U];
            __Vtemp_h501dc7fc__0[2U] = (1U & __Vtemp_h0ada6192__0[2U]);
        } else {
            __Vtemp_h501dc7fc__0[0U] = 0U;
            __Vtemp_h501dc7fc__0[1U] = 0U;
            __Vtemp_h501dc7fc__0[2U] = 0U;
        }
        bufp->chgWData(oldp+111,(__Vtemp_h501dc7fc__0),65);
        bufp->chgBit(oldp+114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+115,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__do_enq));
        __Vtemp_hc38f14bc__0[0U] = (IData)((((QData)((IData)(
                                                             (0xffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                 >> 0x10U)))) 
                                             << 0x1fU) 
                                            | (QData)((IData)(
                                                              (0x7fffffffU 
                                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])))));
        __Vtemp_hc38f14bc__0[1U] = (((IData)((((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                               << 0x28U) 
                                              | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                  << 8U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                    >> 0x18U)))) 
                                     << 7U) | (IData)(
                                                      ((((QData)((IData)(
                                                                         (0xffU 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                             >> 0x10U)))) 
                                                         << 0x1fU) 
                                                        | (QData)((IData)(
                                                                          (0x7fffffffU 
                                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])))) 
                                                       >> 0x20U)));
        __Vtemp_hc38f14bc__0[2U] = (((IData)((((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                               << 0x28U) 
                                              | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                  << 8U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                    >> 0x18U)))) 
                                     >> 0x19U) | ((IData)(
                                                          ((((QData)((IData)(
                                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                                             << 0x28U) 
                                                            | (((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                                << 8U) 
                                                               | ((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                                  >> 0x18U))) 
                                                           >> 0x20U)) 
                                                  << 7U));
        __Vtemp_hc38f14bc__0[3U] = ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                              >> 0x11U)) 
                                    | ((IData)(((((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                                  << 0x28U) 
                                                 | (((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                     << 8U) 
                                                    | ((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                       >> 0x18U))) 
                                                >> 0x20U)) 
                                       >> 0x19U));
        bufp->chgWData(oldp+116,(__Vtemp_hc38f14bc__0),104);
        bufp->chgBit(oldp+120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__x1_d_ready));
        bufp->chgBit(oldp+121,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output));
        bufp->chgCData(oldp+122,((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))),3);
        bufp->chgCData(oldp+123,((3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__aFrag))),2);
        bufp->chgSData(oldp+124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_source),11);
        bufp->chgCData(oldp+125,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode),3);
        bufp->chgIData(oldp+126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_address),31);
        bufp->chgCData(oldp+127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_mask),8);
        bufp->chgQData(oldp+128,((((QData)((IData)(
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                   << 0x29U) | (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                 << 9U) 
                                                | ((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                   >> 0x17U)))),64);
        bufp->chgBit(oldp+130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_woready_7));
        bufp->chgBit(oldp+131,((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))));
        bufp->chgBit(oldp+132,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__valids_0));
        bufp->chgBit(oldp+133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__valids_1));
        bufp->chgBit(oldp+134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__valids_2));
        bufp->chgBit(oldp+135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__valids_3));
        bufp->chgBit(oldp+136,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__valids_4));
        bufp->chgBit(oldp+137,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__valids_5));
        bufp->chgBit(oldp+138,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__valids_6));
        bufp->chgBit(oldp+139,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__valids_7));
        bufp->chgCData(oldp+140,((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))),3);
        bufp->chgBit(oldp+141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT___portsAOI_in_0_a_ready_WIRE));
        bufp->chgBit(oldp+142,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_valid));
        bufp->chgCData(oldp+143,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_opcode),3);
        bufp->chgCData(oldp+144,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_size),3);
        bufp->chgCData(oldp+145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source),7);
        bufp->chgCData(oldp+146,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+147,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                        >> 3U))),3);
        bufp->chgCData(oldp+148,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                        >> 6U))),3);
        bufp->chgCData(oldp+149,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           >> 9U))),7);
        bufp->chgIData(oldp+150,((0x7fffffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  << 0x10U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0x10U)))),31);
        bufp->chgCData(oldp+151,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                           >> 0xfU))),8);
        bufp->chgBit(oldp+152,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                      >> 0x17U))));
        bufp->chgBit(oldp+153,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq));
        bufp->chgBit(oldp+154,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT__do_deq));
        bufp->chgWData(oldp+155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data),120);
        bufp->chgBit(oldp+159,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__do_deq));
        bufp->chgBit(oldp+160,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__source_ok));
        bufp->chgBit(oldp+161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+162,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+163,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+164,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+165,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+166,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+168,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+169,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+170,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+171,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_acc_5) 
                                    << 7U) | (0x3fff80U 
                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_eq_5) 
                                                  << 7U) 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xaU)))) 
                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_acc_5) 
                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_eq_5) 
                                          & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0x11U)))) 
                                      << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_acc_4) 
                                                  << 5U) 
                                                 | (0xfffe0U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_eq_4) 
                                                        << 5U) 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 0xcU)))) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_eq_4) 
                                                        & (~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0x11U)))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_acc_3) 
                                                        << 3U) 
                                                       | (0x3fff8U 
                                                          & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_eq_3) 
                                                              << 3U) 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                >> 0xeU)))) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_eq_3) 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0x11U)))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_acc_2) 
                                                              << 1U) 
                                                             | (0xfffeU 
                                                                & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_eq_2) 
                                                                    << 1U) 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0x10U)))) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__mask_eq_2) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0x11U)))))))))))),8);
        __Vtemp_hc961d23f__2[0U] = 1U;
        __Vtemp_hc961d23f__2[1U] = 0U;
        __Vtemp_hc961d23f__2[2U] = 0U;
        __Vtemp_hc961d23f__2[3U] = 0U;
        VL_EXTEND_WI(128,7, __Vtemp_h9a9a6856__2, (0x7fU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU)));
        VL_SHIFTL_WWW(128,128,128, __Vtemp_h996bff05__0, __Vtemp_hc961d23f__2, __Vtemp_h9a9a6856__2);
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___same_cycle_resp_T_1) {
            __Vtemp_h79b535d0__0[0U] = __Vtemp_h996bff05__0[0U];
            __Vtemp_h79b535d0__0[1U] = __Vtemp_h996bff05__0[1U];
            __Vtemp_h79b535d0__0[2U] = (1U & __Vtemp_h996bff05__0[2U]);
        } else {
            __Vtemp_h79b535d0__0[0U] = 0U;
            __Vtemp_h79b535d0__0[1U] = 0U;
            __Vtemp_h79b535d0__0[2U] = 0U;
        }
        bufp->chgWData(oldp+172,(__Vtemp_h79b535d0__0),65);
        bufp->chgBit(oldp+175,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__x1_a_q__DOT__do_enq));
        __Vtemp_h8ff4b457__0[0U] = (IData)((((QData)((IData)(
                                                             (0xffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                 >> 0x10U)))) 
                                             << 0x2fU) 
                                            | (((QData)((IData)(
                                                                (0x7fffffffU 
                                                                 & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                     << 0xfU) 
                                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x11U))))) 
                                                << 0x10U) 
                                               | (QData)((IData)(
                                                                 ((0xfe00U 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 1U)) 
                                                                  | (0x1ffU 
                                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])))))));
        __Vtemp_h8ff4b457__0[1U] = (((IData)((((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                               << 0x28U) 
                                              | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                  << 8U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                    >> 0x18U)))) 
                                     << 0x17U) | (IData)(
                                                         ((((QData)((IData)(
                                                                            (0xffU 
                                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                                >> 0x10U)))) 
                                                            << 0x2fU) 
                                                           | (((QData)((IData)(
                                                                               (0x7fffffffU 
                                                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                                << 0xfU) 
                                                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 0x11U))))) 
                                                               << 0x10U) 
                                                              | (QData)((IData)(
                                                                                ((0xfe00U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 1U)) 
                                                                                | (0x1ffU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])))))) 
                                                          >> 0x20U)));
        __Vtemp_h8ff4b457__0[2U] = (((IData)((((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                               << 0x28U) 
                                              | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                  << 8U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                    >> 0x18U)))) 
                                     >> 9U) | ((IData)(
                                                       ((((QData)((IData)(
                                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                                          << 0x28U) 
                                                         | (((QData)((IData)(
                                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                             << 8U) 
                                                            | ((QData)((IData)(
                                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                               >> 0x18U))) 
                                                        >> 0x20U)) 
                                               << 0x17U));
        __Vtemp_h8ff4b457__0[3U] = ((0x800000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                                  >> 1U)) 
                                    | ((IData)(((((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                                  << 0x28U) 
                                                 | (((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                     << 8U) 
                                                    | ((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                       >> 0x18U))) 
                                                >> 0x20U)) 
                                       >> 9U));
        bufp->chgWData(oldp+177,(__Vtemp_h8ff4b457__0),120);
        bufp->chgBit(oldp+181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___out_xbar_auto_out_1_a_valid));
        bufp->chgBit(oldp+182,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___out_xbar_auto_out_1_d_ready));
        bufp->chgBit(oldp+183,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output));
        bufp->chgBit(oldp+184,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__bundleIn_0_d_valid));
        bufp->chgCData(oldp+185,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__bundleIn_0_d_bits_size),3);
        bufp->chgCData(oldp+186,((0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_source) 
                                           >> 4U))),7);
        bufp->chgCData(oldp+187,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__dFirst_size),3);
        bufp->chgBit(oldp+188,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__drop));
        bufp->chgCData(oldp+189,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__aFrag),3);
        bufp->chgCData(oldp+190,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__old_gennum1),3);
        bufp->chgBit(oldp+191,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__source_ok));
        bufp->chgBit(oldp+192,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 6U)))));
        bufp->chgBit(oldp+193,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+194,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+195,((1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 6U)))));
        bufp->chgBit(oldp+196,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+197,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+198,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+199,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+200,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+201,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+202,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+203,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+204,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                    << 7U) | (0x7fff80U 
                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                                  << 7U) 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 9U)))) 
                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                          & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0x10U)))) 
                                      << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                  << 5U) 
                                                 | (0x1fffe0U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                        << 5U) 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 0xbU)))) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                        & (~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0x10U)))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                        << 3U) 
                                                       | (0x7fff8U 
                                                          & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                              << 3U) 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                >> 0xdU)))) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0x10U)))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                              << 1U) 
                                                             | (0x1fffeU 
                                                                & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                    << 1U) 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0xfU)))) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0x10U)))))))))))),8);
        bufp->chgBit(oldp+205,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__source_ok_1));
        bufp->chgBit(oldp+206,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+207,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT____Vcellinp__repeater__io_repeat));
        bufp->chgCData(oldp+208,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT___repeater_io_deq_bits_size),3);
        bufp->chgBit(oldp+209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___out_xbar_auto_out_0_a_valid));
        bufp->chgSData(oldp+210,((0x7fffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0x10U))),15);
        bufp->chgBit(oldp+211,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___out_xbar_auto_out_0_d_ready));
        bufp->chgBit(oldp+212,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__x1_d_ready));
        bufp->chgBit(oldp+213,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output));
        bufp->chgCData(oldp+214,((3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__aFrag))),2);
        bufp->chgSData(oldp+215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___coupler_to_slave_named_bootaddressreg_auto_fragmenter_out_a_bits_source),11);
        bufp->chgBit(oldp+216,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output));
        bufp->chgBit(oldp+217,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__bundleIn_0_d_valid));
        bufp->chgCData(oldp+218,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__bundleIn_0_d_bits_size),3);
        bufp->chgCData(oldp+219,((0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___coupler_to_slave_named_bootaddressreg_auto_fragmenter_out_a_bits_source) 
                                           >> 4U))),7);
        bufp->chgCData(oldp+220,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode),3);
        bufp->chgSData(oldp+221,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___coupler_to_slave_named_bootaddressreg_auto_fragmenter_out_a_bits_address),15);
        bufp->chgCData(oldp+222,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___coupler_to_slave_named_bootaddressreg_auto_fragmenter_out_a_bits_mask),8);
        bufp->chgCData(oldp+223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__dFirst_size),3);
        bufp->chgBit(oldp+224,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__drop));
        bufp->chgCData(oldp+225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__aFrag),3);
        bufp->chgCData(oldp+226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__old_gennum1),3);
        bufp->chgBit(oldp+227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__source_ok));
        bufp->chgBit(oldp+228,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+229,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+230,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+231,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+232,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+233,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+234,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+235,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+236,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+237,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+238,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                    << 7U) | (0x7fff80U 
                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                                  << 7U) 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 9U)))) 
                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                          & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0x10U)))) 
                                      << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                  << 5U) 
                                                 | (0x1fffe0U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                        << 5U) 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 0xbU)))) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                        & (~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0x10U)))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                        << 3U) 
                                                       | (0x7fff8U 
                                                          & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                              << 3U) 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                >> 0xdU)))) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0x10U)))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                              << 1U) 
                                                             | (0x1fffeU 
                                                                & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                    << 1U) 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0xfU)))) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0x10U)))))))))))),8);
        bufp->chgBit(oldp+239,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__source_ok_1));
        bufp->chgBit(oldp+240,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+241,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT____Vcellinp__repeater__io_repeat));
        bufp->chgCData(oldp+242,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT___repeater_io_deq_bits_size),3);
        bufp->chgBit(oldp+243,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_opcode))));
        bufp->chgBit(oldp+244,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__source_ok));
        bufp->chgBit(oldp+245,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+246,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+247,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+248,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+249,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+250,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+251,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+252,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+253,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+254,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+255,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_acc_5) 
                                    << 7U) | (0x7fff80U 
                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_eq_5) 
                                                  << 7U) 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 9U)))) 
                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_acc_5) 
                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_eq_5) 
                                          & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0x10U)))) 
                                      << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_acc_4) 
                                                  << 5U) 
                                                 | (0x1fffe0U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_eq_4) 
                                                        << 5U) 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 0xbU)))) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_eq_4) 
                                                        & (~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0x10U)))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_acc_3) 
                                                        << 3U) 
                                                       | (0x7fff8U 
                                                          & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_eq_3) 
                                                              << 3U) 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                >> 0xdU)))) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_eq_3) 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0x10U)))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_acc_2) 
                                                              << 1U) 
                                                             | (0x1fffeU 
                                                                & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_eq_2) 
                                                                    << 1U) 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0xfU)))) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__mask_eq_2) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0x10U)))))))))))),8);
        bufp->chgBit(oldp+256,((((((((((((((((((0x20U 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source)) 
                                               | (IData)(
                                                         ((0U 
                                                           == 
                                                           (0x78U 
                                                            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source))) 
                                                          & (5U 
                                                             > 
                                                             (7U 
                                                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source)))))) 
                                              | (5U 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source))) 
                                             | (8U 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source))) 
                                            | (0x1cU 
                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source))) 
                                           | (0x1dU 
                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source))) 
                                          | (0x1eU 
                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source))) 
                                         | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source))) 
                                        | (0x19U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source))) 
                                       | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source))) 
                                      | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source))) 
                                     | (0x15U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source))) 
                                    | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source))) 
                                   | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source))) 
                                  | (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source))) 
                                 | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source))) 
                                | (0x40U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__out_9_bits_source)))));
        bufp->chgBit(oldp+257,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+258,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__a_first_done));
        bufp->chgBit(oldp+259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__d_first_done));
        bufp->chgBit(oldp+260,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+263,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+264,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+265,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+266,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+268,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+269,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+270,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+272,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_acc_5) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_eq_5) 
                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___coupler_to_slave_named_bootaddressreg_auto_fragmenter_out_a_bits_address))) 
                                   << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_acc_5) 
                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_eq_5) 
                                                  & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___coupler_to_slave_named_bootaddressreg_auto_fragmenter_out_a_bits_address)))) 
                                              << 6U) 
                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_acc_4) 
                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_eq_4) 
                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___coupler_to_slave_named_bootaddressreg_auto_fragmenter_out_a_bits_address))) 
                                                 << 5U) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_eq_4) 
                                                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___coupler_to_slave_named_bootaddressreg_auto_fragmenter_out_a_bits_address)))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_acc_3) 
                                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_eq_3) 
                                                           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___coupler_to_slave_named_bootaddressreg_auto_fragmenter_out_a_bits_address))) 
                                                       << 3U) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_eq_3) 
                                                              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___coupler_to_slave_named_bootaddressreg_auto_fragmenter_out_a_bits_address)))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_acc_2) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_eq_2) 
                                                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___coupler_to_slave_named_bootaddressreg_auto_fragmenter_out_a_bits_address))) 
                                                             << 1U) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__monitor__DOT__mask_eq_2) 
                                                                  & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___coupler_to_slave_named_bootaddressreg_auto_fragmenter_out_a_bits_address)))))))))))),8);
        bufp->chgCData(oldp+273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__readys_valid),2);
        bufp->chgCData(oldp+274,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__readys_readys),2);
        bufp->chgBit(oldp+275,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__readys_readys) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__bundleIn_0_d_valid))));
        bufp->chgBit(oldp+276,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__readys_readys) 
                                 >> 1U) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__bundleIn_0_d_valid))));
        bufp->chgBit(oldp+277,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__muxStateEarly_0));
        bufp->chgBit(oldp+278,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__muxStateEarly_1));
        bufp->chgBit(oldp+279,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__winnerQual_0));
        bufp->chgBit(oldp+280,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__winnerQual_1));
        bufp->chgBit(oldp+281,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__source_ok));
        bufp->chgBit(oldp+282,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+284,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+285,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+286,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+287,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+288,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+289,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+290,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+291,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+292,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_5) 
                                    << 7U) | (0x7fff80U 
                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_5) 
                                                  << 7U) 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 9U)))) 
                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_5) 
                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_5) 
                                          & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0x10U)))) 
                                      << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_4) 
                                                  << 5U) 
                                                 | (0x1fffe0U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_4) 
                                                        << 5U) 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 0xbU)))) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_4) 
                                                        & (~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0x10U)))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_3) 
                                                        << 3U) 
                                                       | (0x7fff8U 
                                                          & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_3) 
                                                              << 3U) 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                >> 0xdU)))) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_3) 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0x10U)))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_2) 
                                                              << 1U) 
                                                             | (0x1fffeU 
                                                                & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_2) 
                                                                    << 1U) 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0xfU)))) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__mask_eq_2) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0x10U)))))))))))),8);
        bufp->chgBit(oldp+293,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+294,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_1_113));
        bufp->chgBit(oldp+295,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_1_152));
        bufp->chgBit(oldp+296,((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))));
        bufp->chgBit(oldp+297,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartExceptionWrEn));
        bufp->chgBit(oldp+298,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartHaltedWrEn));
        bufp->chgBit(oldp+299,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_1_152) 
                                & (0x3ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT___out_womask_T_260)))));
        bufp->chgCData(oldp+300,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_oindex_1),8);
        bufp->chgBit(oldp+301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_1_71));
        bufp->chgBit(oldp+302,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_1_146));
        bufp->chgBit(oldp+303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_1_31));
        bufp->chgBit(oldp+304,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_1_95));
        bufp->chgBit(oldp+305,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_1_170));
        bufp->chgBit(oldp+306,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_1_122));
        bufp->chgBit(oldp+307,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_1_15));
        bufp->chgBit(oldp+308,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_1_103));
        bufp->chgBit(oldp+309,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_1_55));
        VL_EXTEND_WI(1024,10, __Vtemp_h9ccbbd94__0, 
                     (0x3ffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                 << 8U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                           >> 0x18U))));
        VL_SHIFTL_WWW(1024,1024,1024, __Vtemp_h940f208b__0, VTestHarness__ConstPool__CONST_h2ae7f32a_0, __Vtemp_h9ccbbd94__0);
        bufp->chgWData(oldp+310,(__Vtemp_h940f208b__0),1024);
        bufp->chgBit(oldp+342,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartResumingWrEn));
        bufp->chgBit(oldp+343,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__a_first_done));
        bufp->chgBit(oldp+344,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__d_first_done));
        bufp->chgBit(oldp+345,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+346,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_acc));
        bufp->chgBit(oldp+347,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_acc_1));
        bufp->chgBit(oldp+348,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+349,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_eq_2));
        bufp->chgBit(oldp+350,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_acc_2));
        bufp->chgBit(oldp+351,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_eq_3));
        bufp->chgBit(oldp+352,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_acc_3));
        bufp->chgBit(oldp+353,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_eq_4));
        bufp->chgBit(oldp+354,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_acc_4));
        bufp->chgBit(oldp+355,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_eq_5));
        bufp->chgBit(oldp+356,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_acc_5));
        bufp->chgCData(oldp+357,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_acc_5) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_eq_5) 
                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_debug_fragmenter_out_a_bits_address))) 
                                   << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_acc_5) 
                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_eq_5) 
                                                  & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_debug_fragmenter_out_a_bits_address)))) 
                                              << 6U) 
                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_acc_4) 
                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_eq_4) 
                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_debug_fragmenter_out_a_bits_address))) 
                                                 << 5U) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_eq_4) 
                                                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_debug_fragmenter_out_a_bits_address)))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_acc_3) 
                                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_eq_3) 
                                                           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_debug_fragmenter_out_a_bits_address))) 
                                                       << 3U) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_eq_3) 
                                                              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_debug_fragmenter_out_a_bits_address)))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_acc_2) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_eq_2) 
                                                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_debug_fragmenter_out_a_bits_address))) 
                                                             << 1U) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__mask_eq_2) 
                                                                  & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_debug_fragmenter_out_a_bits_address)))))))))))),8);
        bufp->chgBit(oldp+358,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__out_woready_2));
        bufp->chgBit(oldp+359,((0U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_address 
                                             >> 3U)))));
        bufp->chgBit(oldp+360,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__out_woready_2) 
                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_mask) 
                                    >> 3U)) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                               >> 0x16U))));
        bufp->chgBit(oldp+361,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__ie_rxwm));
        bufp->chgBit(oldp+362,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__ie_txwm));
        bufp->chgBit(oldp+363,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__ip_txwm));
        bufp->chgBit(oldp+364,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__ip_rxwm));
        bufp->chgBit(oldp+365,((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))));
        bufp->chgBit(oldp+366,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__out_woready_10));
        bufp->chgBit(oldp+367,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__out_woready_12));
        bufp->chgBit(oldp+368,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__ip_txwm) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__ie_txwm)) 
                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__ip_rxwm) 
                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__ie_rxwm)))));
        bufp->chgBit(oldp+369,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__a_first_done));
        bufp->chgBit(oldp+370,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__d_first_done));
        bufp->chgBit(oldp+371,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+372,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+373,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+374,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+375,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+376,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+377,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+378,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+379,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+380,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+381,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+382,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+383,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_acc_5) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_eq_5) 
                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_address)) 
                                   << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_acc_5) 
                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_eq_5) 
                                                  & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_address))) 
                                              << 6U) 
                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_acc_4) 
                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_eq_4) 
                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_address)) 
                                                 << 5U) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_eq_4) 
                                                        & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_address))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_acc_3) 
                                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_eq_3) 
                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_address)) 
                                                       << 3U) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_eq_3) 
                                                              & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_address))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_acc_2) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_eq_2) 
                                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_address)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__mask_eq_2) 
                                                                  & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_address))))))))))),8);
        bufp->chgBit(oldp+384,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT___out_wofireMux_T) 
                                  & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))) 
                                 & (0U == (0xff8U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_address))) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_mask) 
                                   >> 4U))));
        bufp->chgBit(oldp+385,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__do_deq));
        bufp->chgBit(oldp+386,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__out_woready_2) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_mask)) 
                                & (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__out_woready_2) 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_mask) 
                                          >> 3U)) & 
                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                       >> 0x16U))))));
        bufp->chgCData(oldp+387,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                           >> 0x17U))),8);
        bufp->chgBit(oldp+388,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__do_enq));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x39U])) {
        bufp->chgCData(oldp+389,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__widx_gray),4);
        bufp->chgBit(oldp+390,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+391,((1U & (IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__widx_gray))));
        bufp->chgBit(oldp+392,((1U & ((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__widx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+393,((1U & ((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__widx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+394,((1U & ((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__widx_gray) 
                                      >> 3U))));
        bufp->chgCData(oldp+395,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__index),3);
        bufp->chgCData(oldp+396,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__widx_incremented),4);
        bufp->chgCData(oldp+397,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__widx),4);
        bufp->chgBit(oldp+398,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+399,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+400,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+401,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+402,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgCData(oldp+403,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx_gray),4);
        bufp->chgBit(oldp+404,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgCData(oldp+405,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx),4);
        bufp->chgBit(oldp+406,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__valid));
        bufp->chgBit(oldp+407,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+408,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+409,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+410,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+411,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+412,((1U & (IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+413,((1U & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+414,((1U & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+415,((1U & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx_gray) 
                                      >> 3U))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x3aU])) {
        bufp->chgBit(oldp+416,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_implicit_clock_reset));
        bufp->chgBit(oldp+417,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset));
        bufp->chgBit(oldp+418,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x3bU])) {
        bufp->chgCData(oldp+419,((7U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                >> 0x34U)))),3);
        bufp->chgCData(oldp+420,((7U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                >> 0x31U)))),3);
        bufp->chgCData(oldp+421,((3U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                >> 0x2fU)))),2);
        bufp->chgBit(oldp+422,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                              >> 0x2eU)))));
        bufp->chgSData(oldp+423,((0x1ffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                    >> 0x25U)))),9);
        bufp->chgCData(oldp+424,((0xfU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                  >> 0x21U)))),4);
        bufp->chgIData(oldp+425,((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                          >> 1U))),32);
        bufp->chgBit(oldp+426,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg))));
        bufp->chgCData(oldp+427,((4U == (7U & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                       >> 0x34U))))),3);
        bufp->chgBit(oldp+428,((0x32U == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+429,((0x17U == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+430,((0x16U == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgCData(oldp+431,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__haltedBitRegs),5);
        bufp->chgBit(oldp+432,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hamaskFull_0));
        bufp->chgBit(oldp+433,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hamaskFull_1));
        bufp->chgBit(oldp+434,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hamaskFull_2));
        bufp->chgBit(oldp+435,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hamaskFull_3));
        bufp->chgBit(oldp+436,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hamaskFull_4));
        bufp->chgBit(oldp+437,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrmaskReg_0));
        bufp->chgBit(oldp+438,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrmaskReg_1));
        bufp->chgBit(oldp+439,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrmaskReg_2));
        bufp->chgBit(oldp+440,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrmaskReg_3));
        bufp->chgBit(oldp+441,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrmaskReg_4));
        bufp->chgBit(oldp+442,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__DMSTATUSRdData_allnonexistent));
        bufp->chgBit(oldp+443,((4U == (7U & (IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                     >> 0x34U))))));
        bufp->chgBit(oldp+444,((4U == (0x3fU & (IData)(
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                        >> 0x27U))))));
        bufp->chgBit(oldp+445,((5U == (0x3fU & (IData)(
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                        >> 0x27U))))));
        bufp->chgBit(oldp+446,((0x20U == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+447,((0x21U == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+448,((0x22U == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+449,((0x23U == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+450,((0x24U == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+451,((0x25U == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+452,((0x26U == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+453,((0x27U == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+454,((0x28U == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+455,((0x29U == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+456,((0x2aU == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+457,((0x2bU == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+458,((0x2cU == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+459,((0x2dU == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+460,((0x2eU == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+461,((0x2fU == (0x3fU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x27U))))));
        bufp->chgBit(oldp+462,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__commandRegBadHaltResume));
        bufp->chgBit(oldp+463,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__goAbstract));
        bufp->chgBit(oldp+464,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+465,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor__DOT__mask_acc_1));
        bufp->chgCData(oldp+466,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor__DOT__mask_acc_1) 
                                    | (0x6000000000ULL 
                                       == (0x6000000000ULL 
                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg))) 
                                   << 3U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor__DOT__mask_acc_1) 
                                               | (0x4000000000ULL 
                                                  == 
                                                  (0x6000000000ULL 
                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg))) 
                                              << 2U) 
                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor__DOT__mask_acc) 
                                                  | (0x2000000000ULL 
                                                     == 
                                                     (0x6000000000ULL 
                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg))) 
                                                 << 1U) 
                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor__DOT__mask_acc) 
                                                   | (0ULL 
                                                      == 
                                                      (0x6000000000ULL 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg))))))),4);
        bufp->chgQData(oldp+467,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),55);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x3cU])) {
        bufp->chgBit(oldp+469,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+470,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+471,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+472,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+473,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+474,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+475,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+476,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+477,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+478,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+479,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+480,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+481,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+482,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+483,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+484,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+485,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+486,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+487,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+488,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+489,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+490,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+491,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+492,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+493,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+494,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+495,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x3dU])) {
        bufp->chgBit(oldp+496,((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction))));
        bufp->chgBit(oldp+497,((0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction))));
        bufp->chgBit(oldp+498,((0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction))));
        bufp->chgCData(oldp+499,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction),5);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x3eU])) {
        bufp->chgBit(oldp+500,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset));
        bufp->chgBit(oldp+501,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset));
        bufp->chgBit(oldp+502,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset));
        bufp->chgBit(oldp+503,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset));
        bufp->chgBit(oldp+504,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__BJL__reset));
        bufp->chgBit(oldp+505,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__BJL__reset));
        bufp->chgBit(oldp+506,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__BJL__reset));
        bufp->chgBit(oldp+507,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT____Vcellinp__sink_valid_0__reset));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x3fU])) {
        bufp->chgCData(oldp+508,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__widx_gray),4);
        bufp->chgBit(oldp+509,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__widx_gray))));
        bufp->chgBit(oldp+510,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+511,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+512,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                      >> 3U))));
        bufp->chgBit(oldp+513,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_d_ready));
        bufp->chgBit(oldp+514,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_e_valid));
        bufp->chgCData(oldp+515,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_incremented),4);
        bufp->chgCData(oldp+516,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx),4);
        bufp->chgBit(oldp+517,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__valid));
        bufp->chgCData(oldp+518,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index),3);
        bufp->chgCData(oldp+519,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_incremented),4);
        bufp->chgCData(oldp+520,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx),4);
        bufp->chgBit(oldp+521,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__valid));
        bufp->chgCData(oldp+522,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__index),3);
        bufp->chgCData(oldp+523,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__d_set),8);
        bufp->chgCData(oldp+524,((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                        ^ (4U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                                 >> 1U))))),3);
        bufp->chgCData(oldp+525,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__widx_incremented),4);
        bufp->chgCData(oldp+526,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__widx),4);
        bufp->chgBit(oldp+527,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_req_ready));
        bufp->chgBit(oldp+528,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_replay_next_output));
        bufp->chgBit(oldp+529,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_io_cpu_perf_grant));
        bufp->chgBit(oldp+530,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_resp_ready));
        bufp->chgBit(oldp+531,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_fpu_valid));
        bufp->chgBit(oldp+532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killx));
        bufp->chgBit(oldp+533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__killm_common));
        bufp->chgBit(oldp+534,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd));
        bufp->chgBit(oldp+535,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__replay_ex));
        bufp->chgBit(oldp+536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__dcache_kill_mem));
        bufp->chgBit(oldp+537,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killm));
        bufp->chgBit(oldp+538,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_stalld));
        bufp->chgBit(oldp+539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_kill));
        bufp->chgBit(oldp+540,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_stalld)))));
        bufp->chgCData(oldp+541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_num_valid_insts_in_pipeline),4);
        bufp->chgBit(oldp+542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__deq_valid_0));
        bufp->chgBit(oldp+543,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__deq_valid_1));
        bufp->chgBit(oldp+544,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT___T_4));
        bufp->chgBit(oldp+545,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT___T_10));
        bufp->chgBit(oldp+546,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT___T_4));
        bufp->chgBit(oldp+547,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT___T_10));
        bufp->chgBit(oldp+548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output));
        bufp->chgBit(oldp+549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s0_req_fire));
        bufp->chgBit(oldp+550,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid));
        bufp->chgBit(oldp+551,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_s1_kill));
        bufp->chgBit(oldp+552,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_b_ready));
        bufp->chgBit(oldp+553,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_d_ready));
        bufp->chgBit(oldp+554,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_req_ready_output));
        bufp->chgBit(oldp+555,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_1_valid));
        bufp->chgBit(oldp+556,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_3_valid));
        bufp->chgBit(oldp+557,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_valid) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_bits_write)))));
        bufp->chgBit(oldp+558,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_valid) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_bits_write))));
        bufp->chgBit(oldp+559,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_bits_write));
        bufp->chgBit(oldp+560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb___05Fgrant_T_2));
        bufp->chgBit(oldp+561,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb___05Fgrant_T_3));
        bufp->chgBit(oldp+562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb___05Fgrant_T_5));
        bufp->chgBit(oldp+563,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_valid));
        bufp->chgBit(oldp+564,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb___05Fgrant_T));
        bufp->chgBit(oldp+565,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb___05Fgrant_T_1));
        bufp->chgBit(oldp+566,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_out_valid));
        bufp->chgBit(oldp+567,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_io_req_valid));
        bufp->chgBit(oldp+568,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_io_sfence_valid));
        bufp->chgQData(oldp+569,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s0_tlb_req_vaddr),40);
        bufp->chgBit(oldp+571,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill));
        bufp->chgBit(oldp+572,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05FT_21));
        bufp->chgBit(oldp+573,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s0_clk_en));
        bufp->chgSData(oldp+574,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_addr),11);
        bufp->chgBit(oldp+575,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_write));
        bufp->chgCData(oldp+576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_way_en),2);
        bufp->chgBit(oldp+577,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_out_valid) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_write)))));
        bufp->chgBit(oldp+578,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_out_valid) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_write))));
        bufp->chgCData(oldp+579,((0xffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_addr) 
                                           >> 3U))),8);
        bufp->chgBit(oldp+580,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_en));
        bufp->chgSData(oldp+581,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask),16);
        bufp->chgBit(oldp+582,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask))));
        bufp->chgBit(oldp+583,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 1U))));
        bufp->chgBit(oldp+584,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 2U))));
        bufp->chgBit(oldp+585,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 3U))));
        bufp->chgBit(oldp+586,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 4U))));
        bufp->chgBit(oldp+587,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 5U))));
        bufp->chgBit(oldp+588,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 6U))));
        bufp->chgBit(oldp+589,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 7U))));
        bufp->chgBit(oldp+590,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 8U))));
        bufp->chgBit(oldp+591,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 9U))));
        bufp->chgBit(oldp+592,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xaU))));
        bufp->chgBit(oldp+593,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xbU))));
        bufp->chgBit(oldp+594,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xcU))));
        bufp->chgBit(oldp+595,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+596,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xeU))));
        bufp->chgBit(oldp+597,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xfU))));
        bufp->chgBit(oldp+598,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_write))));
        bufp->chgBit(oldp+599,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__lfsr_prng__io_increment));
        bufp->chgCData(oldp+600,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_addr),5);
        bufp->chgBit(oldp+601,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_en));
        bufp->chgQData(oldp+602,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wdata),46);
        bufp->chgCData(oldp+604,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wmask),2);
        bufp->chgIData(oldp+605,((0x7fffffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wdata))),23);
        bufp->chgBit(oldp+606,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wmask))));
        bufp->chgIData(oldp+607,((0x7fffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wdata 
                                                       >> 0x17U)))),23);
        bufp->chgBit(oldp+608,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wmask) 
                                      >> 1U))));
        bufp->chgBit(oldp+609,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_bits_write))));
        bufp->chgBit(oldp+610,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_13_valid));
        bufp->chgBit(oldp+611,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_one_beat)))));
        bufp->chgBit(oldp+612,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_1_MPORT_2_en));
        bufp->chgBit(oldp+613,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_0_MPORT_1_en));
        bufp->chgBit(oldp+614,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__tag_array_MPORT_en)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid))));
        bufp->chgBit(oldp+615,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_one_beat));
        bufp->chgBit(oldp+616,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid));
        bufp->chgBit(oldp+617,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__tag_array_MPORT_en));
        bufp->chgSData(oldp+618,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_0__RW0_addr),9);
        bufp->chgBit(oldp+619,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_0__RW0_en));
        bufp->chgBit(oldp+620,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_0__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_0_MPORT_1_en))));
        bufp->chgSData(oldp+621,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_1__RW0_addr),9);
        bufp->chgBit(oldp+622,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_1__RW0_en));
        bufp->chgBit(oldp+623,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_1__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_1_MPORT_2_en))));
        bufp->chgCData(oldp+624,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_addr),6);
        bufp->chgBit(oldp+625,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_en));
        bufp->chgBit(oldp+626,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__tag_array_MPORT_en))));
        bufp->chgCData(oldp+627,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_set),8);
        bufp->chgBit(oldp+628,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_clr));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x40U])) {
        bufp->chgCData(oldp+629,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__widx_gray),4);
        bufp->chgBit(oldp+630,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__widx_gray))));
        bufp->chgBit(oldp+631,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+632,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+633,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                      >> 3U))));
        bufp->chgBit(oldp+634,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_d_ready));
        bufp->chgBit(oldp+635,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_e_valid));
        bufp->chgCData(oldp+636,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_incremented),4);
        bufp->chgCData(oldp+637,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx),4);
        bufp->chgBit(oldp+638,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__valid));
        bufp->chgCData(oldp+639,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index),3);
        bufp->chgCData(oldp+640,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_incremented),4);
        bufp->chgCData(oldp+641,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx),4);
        bufp->chgBit(oldp+642,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__valid));
        bufp->chgCData(oldp+643,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__index),3);
        bufp->chgCData(oldp+644,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__monitor__DOT__d_set),8);
        bufp->chgCData(oldp+645,((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                        ^ (4U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                                 >> 1U))))),3);
        bufp->chgCData(oldp+646,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__widx_incremented),4);
        bufp->chgCData(oldp+647,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__widx),4);
        bufp->chgBit(oldp+648,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_req_ready));
        bufp->chgBit(oldp+649,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_replay_next_output));
        bufp->chgBit(oldp+650,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcache_io_cpu_perf_grant));
        bufp->chgBit(oldp+651,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_imem_resp_ready));
        bufp->chgBit(oldp+652,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_fpu_valid));
        bufp->chgBit(oldp+653,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killx));
        bufp->chgBit(oldp+654,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__killm_common));
        bufp->chgBit(oldp+655,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd));
        bufp->chgBit(oldp+656,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__replay_ex));
        bufp->chgBit(oldp+657,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__dcache_kill_mem));
        bufp->chgBit(oldp+658,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killm));
        bufp->chgBit(oldp+659,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_stalld));
        bufp->chgBit(oldp+660,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_kill));
        bufp->chgBit(oldp+661,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_stalld)))));
        bufp->chgCData(oldp+662,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_num_valid_insts_in_pipeline),4);
        bufp->chgBit(oldp+663,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__deq_valid_0));
        bufp->chgBit(oldp+664,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__deq_valid_1));
        bufp->chgBit(oldp+665,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT___T_4));
        bufp->chgBit(oldp+666,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT___T_10));
        bufp->chgBit(oldp+667,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT___T_4));
        bufp->chgBit(oldp+668,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT___T_10));
        bufp->chgBit(oldp+669,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output));
        bufp->chgBit(oldp+670,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s0_req_fire));
        bufp->chgBit(oldp+671,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid));
        bufp->chgBit(oldp+672,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_s1_kill));
        bufp->chgBit(oldp+673,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_b_ready));
        bufp->chgBit(oldp+674,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_d_ready));
        bufp->chgBit(oldp+675,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_req_ready_output));
        bufp->chgBit(oldp+676,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_1_valid));
        bufp->chgBit(oldp+677,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_3_valid));
        bufp->chgBit(oldp+678,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_valid) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_bits_write)))));
        bufp->chgBit(oldp+679,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_valid) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_bits_write))));
        bufp->chgBit(oldp+680,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_bits_write));
        bufp->chgBit(oldp+681,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb___05Fgrant_T_2));
        bufp->chgBit(oldp+682,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb___05Fgrant_T_3));
        bufp->chgBit(oldp+683,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb___05Fgrant_T_5));
        bufp->chgBit(oldp+684,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_valid));
        bufp->chgBit(oldp+685,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb___05Fgrant_T));
        bufp->chgBit(oldp+686,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb___05Fgrant_T_1));
        bufp->chgBit(oldp+687,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_out_valid));
        bufp->chgBit(oldp+688,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_io_req_valid));
        bufp->chgBit(oldp+689,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_io_sfence_valid));
        bufp->chgQData(oldp+690,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s0_tlb_req_vaddr),40);
        bufp->chgBit(oldp+692,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill));
        bufp->chgBit(oldp+693,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05FT_21));
        bufp->chgBit(oldp+694,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s0_clk_en));
        bufp->chgSData(oldp+695,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_addr),11);
        bufp->chgBit(oldp+696,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_write));
        bufp->chgCData(oldp+697,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_way_en),2);
        bufp->chgBit(oldp+698,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_out_valid) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_write)))));
        bufp->chgBit(oldp+699,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_out_valid) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_write))));
        bufp->chgCData(oldp+700,((0xffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_addr) 
                                           >> 3U))),8);
        bufp->chgBit(oldp+701,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_en));
        bufp->chgSData(oldp+702,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask),16);
        bufp->chgBit(oldp+703,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask))));
        bufp->chgBit(oldp+704,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 1U))));
        bufp->chgBit(oldp+705,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 2U))));
        bufp->chgBit(oldp+706,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 3U))));
        bufp->chgBit(oldp+707,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 4U))));
        bufp->chgBit(oldp+708,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 5U))));
        bufp->chgBit(oldp+709,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 6U))));
        bufp->chgBit(oldp+710,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 7U))));
        bufp->chgBit(oldp+711,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 8U))));
        bufp->chgBit(oldp+712,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 9U))));
        bufp->chgBit(oldp+713,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xaU))));
        bufp->chgBit(oldp+714,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xbU))));
        bufp->chgBit(oldp+715,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xcU))));
        bufp->chgBit(oldp+716,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+717,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xeU))));
        bufp->chgBit(oldp+718,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xfU))));
        bufp->chgBit(oldp+719,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_write))));
        bufp->chgBit(oldp+720,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__lfsr_prng__io_increment));
        bufp->chgCData(oldp+721,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_addr),5);
        bufp->chgBit(oldp+722,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_en));
        bufp->chgQData(oldp+723,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wdata),46);
        bufp->chgCData(oldp+725,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wmask),2);
        bufp->chgIData(oldp+726,((0x7fffffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wdata))),23);
        bufp->chgBit(oldp+727,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wmask))));
        bufp->chgIData(oldp+728,((0x7fffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wdata 
                                                       >> 0x17U)))),23);
        bufp->chgBit(oldp+729,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wmask) 
                                      >> 1U))));
        bufp->chgBit(oldp+730,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_bits_write))));
        bufp->chgBit(oldp+731,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_13_valid));
        bufp->chgBit(oldp+732,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_one_beat)))));
        bufp->chgBit(oldp+733,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_1_MPORT_2_en));
        bufp->chgBit(oldp+734,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_0_MPORT_1_en));
        bufp->chgBit(oldp+735,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__tag_array_MPORT_en)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid))));
        bufp->chgBit(oldp+736,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_one_beat));
        bufp->chgBit(oldp+737,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid));
        bufp->chgBit(oldp+738,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__tag_array_MPORT_en));
        bufp->chgSData(oldp+739,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_0__RW0_addr),9);
        bufp->chgBit(oldp+740,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_0__RW0_en));
        bufp->chgBit(oldp+741,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_0__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_0_MPORT_1_en))));
        bufp->chgSData(oldp+742,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_1__RW0_addr),9);
        bufp->chgBit(oldp+743,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_1__RW0_en));
        bufp->chgBit(oldp+744,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_1__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_1_MPORT_2_en))));
        bufp->chgCData(oldp+745,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_addr),6);
        bufp->chgBit(oldp+746,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_en));
        bufp->chgBit(oldp+747,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__tag_array_MPORT_en))));
        bufp->chgCData(oldp+748,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_set),8);
        bufp->chgBit(oldp+749,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_clr));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x41U])) {
        bufp->chgCData(oldp+750,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__widx_gray),4);
        bufp->chgBit(oldp+751,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__widx_gray))));
        bufp->chgBit(oldp+752,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+753,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+754,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                      >> 3U))));
        bufp->chgBit(oldp+755,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_d_ready));
        bufp->chgBit(oldp+756,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_e_valid));
        bufp->chgCData(oldp+757,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_incremented),4);
        bufp->chgCData(oldp+758,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx),4);
        bufp->chgBit(oldp+759,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__valid));
        bufp->chgCData(oldp+760,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index),3);
        bufp->chgCData(oldp+761,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_incremented),4);
        bufp->chgCData(oldp+762,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx),4);
        bufp->chgBit(oldp+763,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__valid));
        bufp->chgCData(oldp+764,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__index),3);
        bufp->chgCData(oldp+765,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__d_set),8);
        bufp->chgCData(oldp+766,((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                        ^ (4U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                                 >> 1U))))),3);
        bufp->chgCData(oldp+767,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__widx_incremented),4);
        bufp->chgCData(oldp+768,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__widx),4);
        bufp->chgBit(oldp+769,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_req_ready));
        bufp->chgBit(oldp+770,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_replay_next_output));
        bufp->chgBit(oldp+771,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcache_io_cpu_perf_grant));
        bufp->chgBit(oldp+772,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_imem_resp_ready));
        bufp->chgBit(oldp+773,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_fpu_valid));
        bufp->chgBit(oldp+774,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killx));
        bufp->chgBit(oldp+775,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__killm_common));
        bufp->chgBit(oldp+776,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd));
        bufp->chgBit(oldp+777,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__replay_ex));
        bufp->chgBit(oldp+778,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__dcache_kill_mem));
        bufp->chgBit(oldp+779,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killm));
        bufp->chgBit(oldp+780,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_stalld));
        bufp->chgBit(oldp+781,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_kill));
        bufp->chgBit(oldp+782,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_stalld)))));
        bufp->chgCData(oldp+783,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_num_valid_insts_in_pipeline),4);
        bufp->chgBit(oldp+784,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__deq_valid_0));
        bufp->chgBit(oldp+785,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__deq_valid_1));
        bufp->chgBit(oldp+786,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT___T_4));
        bufp->chgBit(oldp+787,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT___T_10));
        bufp->chgBit(oldp+788,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT___T_4));
        bufp->chgBit(oldp+789,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT___T_10));
        bufp->chgBit(oldp+790,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output));
        bufp->chgBit(oldp+791,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s0_req_fire));
        bufp->chgBit(oldp+792,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid));
        bufp->chgBit(oldp+793,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_s1_kill));
        bufp->chgBit(oldp+794,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_b_ready));
        bufp->chgBit(oldp+795,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_d_ready));
        bufp->chgBit(oldp+796,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_req_ready_output));
        bufp->chgBit(oldp+797,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_1_valid));
        bufp->chgBit(oldp+798,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_3_valid));
        bufp->chgBit(oldp+799,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_valid) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_bits_write)))));
        bufp->chgBit(oldp+800,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_valid) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_bits_write))));
        bufp->chgBit(oldp+801,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_bits_write));
        bufp->chgBit(oldp+802,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb___05Fgrant_T_2));
        bufp->chgBit(oldp+803,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb___05Fgrant_T_3));
        bufp->chgBit(oldp+804,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb___05Fgrant_T_5));
        bufp->chgBit(oldp+805,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_valid));
        bufp->chgBit(oldp+806,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb___05Fgrant_T));
        bufp->chgBit(oldp+807,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb___05Fgrant_T_1));
        bufp->chgBit(oldp+808,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_out_valid));
        bufp->chgBit(oldp+809,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_io_req_valid));
        bufp->chgBit(oldp+810,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_io_sfence_valid));
        bufp->chgQData(oldp+811,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s0_tlb_req_vaddr),40);
        bufp->chgBit(oldp+813,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill));
        bufp->chgBit(oldp+814,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05FT_21));
        bufp->chgBit(oldp+815,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s0_clk_en));
        bufp->chgSData(oldp+816,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_addr),11);
        bufp->chgBit(oldp+817,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_write));
        bufp->chgCData(oldp+818,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_way_en),2);
        bufp->chgBit(oldp+819,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_out_valid) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_write)))));
        bufp->chgBit(oldp+820,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_out_valid) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_write))));
        bufp->chgCData(oldp+821,((0xffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_addr) 
                                           >> 3U))),8);
        bufp->chgBit(oldp+822,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_en));
        bufp->chgSData(oldp+823,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask),16);
        bufp->chgBit(oldp+824,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask))));
        bufp->chgBit(oldp+825,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 1U))));
        bufp->chgBit(oldp+826,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 2U))));
        bufp->chgBit(oldp+827,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 3U))));
        bufp->chgBit(oldp+828,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 4U))));
        bufp->chgBit(oldp+829,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 5U))));
        bufp->chgBit(oldp+830,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 6U))));
        bufp->chgBit(oldp+831,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 7U))));
        bufp->chgBit(oldp+832,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 8U))));
        bufp->chgBit(oldp+833,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 9U))));
        bufp->chgBit(oldp+834,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xaU))));
        bufp->chgBit(oldp+835,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xbU))));
        bufp->chgBit(oldp+836,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xcU))));
        bufp->chgBit(oldp+837,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+838,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xeU))));
        bufp->chgBit(oldp+839,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xfU))));
        bufp->chgBit(oldp+840,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_write))));
        bufp->chgBit(oldp+841,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__lfsr_prng__io_increment));
        bufp->chgCData(oldp+842,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_addr),5);
        bufp->chgBit(oldp+843,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_en));
        bufp->chgQData(oldp+844,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wdata),46);
        bufp->chgCData(oldp+846,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wmask),2);
        bufp->chgIData(oldp+847,((0x7fffffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wdata))),23);
        bufp->chgBit(oldp+848,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wmask))));
        bufp->chgIData(oldp+849,((0x7fffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wdata 
                                                       >> 0x17U)))),23);
        bufp->chgBit(oldp+850,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wmask) 
                                      >> 1U))));
        bufp->chgBit(oldp+851,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_bits_write))));
        bufp->chgBit(oldp+852,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_13_valid));
        bufp->chgBit(oldp+853,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_one_beat)))));
        bufp->chgBit(oldp+854,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_1_MPORT_2_en));
        bufp->chgBit(oldp+855,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_0_MPORT_1_en));
        bufp->chgBit(oldp+856,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__tag_array_MPORT_en)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid))));
        bufp->chgBit(oldp+857,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_one_beat));
        bufp->chgBit(oldp+858,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid));
        bufp->chgBit(oldp+859,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__tag_array_MPORT_en));
        bufp->chgSData(oldp+860,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_0__RW0_addr),9);
        bufp->chgBit(oldp+861,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_0__RW0_en));
        bufp->chgBit(oldp+862,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_0__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_0_MPORT_1_en))));
        bufp->chgSData(oldp+863,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_1__RW0_addr),9);
        bufp->chgBit(oldp+864,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_1__RW0_en));
        bufp->chgBit(oldp+865,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_1__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_1_MPORT_2_en))));
        bufp->chgCData(oldp+866,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_addr),6);
        bufp->chgBit(oldp+867,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_en));
        bufp->chgBit(oldp+868,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__tag_array_MPORT_en))));
        bufp->chgCData(oldp+869,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_set),8);
        bufp->chgBit(oldp+870,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_clr));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x42U])) {
        bufp->chgCData(oldp+871,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__widx_gray),4);
        bufp->chgBit(oldp+872,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__widx_gray))));
        bufp->chgBit(oldp+873,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+874,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+875,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                      >> 3U))));
        bufp->chgBit(oldp+876,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_d_ready));
        bufp->chgBit(oldp+877,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_e_valid));
        bufp->chgCData(oldp+878,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_incremented),4);
        bufp->chgCData(oldp+879,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx),4);
        bufp->chgBit(oldp+880,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__valid));
        bufp->chgCData(oldp+881,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index),3);
        bufp->chgCData(oldp+882,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_incremented),4);
        bufp->chgCData(oldp+883,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx),4);
        bufp->chgBit(oldp+884,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__valid));
        bufp->chgCData(oldp+885,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__index),3);
        bufp->chgCData(oldp+886,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__d_set),8);
        bufp->chgCData(oldp+887,((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                        ^ (4U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                                 >> 1U))))),3);
        bufp->chgCData(oldp+888,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__widx_incremented),4);
        bufp->chgCData(oldp+889,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__widx),4);
        bufp->chgBit(oldp+890,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_req_ready));
        bufp->chgBit(oldp+891,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_replay_next_output));
        bufp->chgBit(oldp+892,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___dcache_io_cpu_perf_grant));
        bufp->chgBit(oldp+893,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_imem_resp_ready));
        bufp->chgBit(oldp+894,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_fpu_valid));
        bufp->chgBit(oldp+895,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killx));
        bufp->chgBit(oldp+896,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__killm_common));
        bufp->chgBit(oldp+897,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd));
        bufp->chgBit(oldp+898,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__replay_ex));
        bufp->chgBit(oldp+899,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__dcache_kill_mem));
        bufp->chgBit(oldp+900,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killm));
        bufp->chgBit(oldp+901,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_stalld));
        bufp->chgBit(oldp+902,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_kill));
        bufp->chgBit(oldp+903,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_stalld)))));
        bufp->chgCData(oldp+904,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_num_valid_insts_in_pipeline),4);
        bufp->chgBit(oldp+905,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__deq_valid_0));
        bufp->chgBit(oldp+906,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__deq_valid_1));
        bufp->chgBit(oldp+907,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT___T_4));
        bufp->chgBit(oldp+908,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT___T_10));
        bufp->chgBit(oldp+909,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT___T_4));
        bufp->chgBit(oldp+910,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT___T_10));
        bufp->chgBit(oldp+911,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output));
        bufp->chgBit(oldp+912,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s0_req_fire));
        bufp->chgBit(oldp+913,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_10_valid));
        bufp->chgBit(oldp+914,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_s1_kill));
        bufp->chgBit(oldp+915,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_b_ready));
        bufp->chgBit(oldp+916,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_d_ready));
        bufp->chgBit(oldp+917,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_req_ready_output));
        bufp->chgBit(oldp+918,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_1_valid));
        bufp->chgBit(oldp+919,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_3_valid));
        bufp->chgBit(oldp+920,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_valid) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_bits_write)))));
        bufp->chgBit(oldp+921,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_valid) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_bits_write))));
        bufp->chgBit(oldp+922,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_bits_write));
        bufp->chgBit(oldp+923,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb___05Fgrant_T_2));
        bufp->chgBit(oldp+924,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb___05Fgrant_T_3));
        bufp->chgBit(oldp+925,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb___05Fgrant_T_5));
        bufp->chgBit(oldp+926,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_valid));
        bufp->chgBit(oldp+927,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb___05Fgrant_T));
        bufp->chgBit(oldp+928,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb___05Fgrant_T_1));
        bufp->chgBit(oldp+929,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_out_valid));
        bufp->chgBit(oldp+930,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_io_req_valid));
        bufp->chgBit(oldp+931,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_io_sfence_valid));
        bufp->chgQData(oldp+932,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s0_tlb_req_vaddr),40);
        bufp->chgBit(oldp+934,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill));
        bufp->chgBit(oldp+935,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05FT_21));
        bufp->chgBit(oldp+936,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s0_clk_en));
        bufp->chgSData(oldp+937,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_addr),11);
        bufp->chgBit(oldp+938,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_write));
        bufp->chgCData(oldp+939,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_way_en),2);
        bufp->chgBit(oldp+940,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_out_valid) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_write)))));
        bufp->chgBit(oldp+941,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_out_valid) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_write))));
        bufp->chgCData(oldp+942,((0xffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_addr) 
                                           >> 3U))),8);
        bufp->chgBit(oldp+943,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_en));
        bufp->chgSData(oldp+944,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask),16);
        bufp->chgBit(oldp+945,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask))));
        bufp->chgBit(oldp+946,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 1U))));
        bufp->chgBit(oldp+947,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 2U))));
        bufp->chgBit(oldp+948,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 3U))));
        bufp->chgBit(oldp+949,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 4U))));
        bufp->chgBit(oldp+950,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 5U))));
        bufp->chgBit(oldp+951,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 6U))));
        bufp->chgBit(oldp+952,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 7U))));
        bufp->chgBit(oldp+953,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 8U))));
        bufp->chgBit(oldp+954,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 9U))));
        bufp->chgBit(oldp+955,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xaU))));
        bufp->chgBit(oldp+956,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xbU))));
        bufp->chgBit(oldp+957,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xcU))));
        bufp->chgBit(oldp+958,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+959,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xeU))));
        bufp->chgBit(oldp+960,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_wmask) 
                                      >> 0xfU))));
        bufp->chgBit(oldp+961,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT____Vcellinp__data_arrays_0__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_write))));
        bufp->chgBit(oldp+962,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__lfsr_prng__io_increment));
        bufp->chgCData(oldp+963,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_addr),5);
        bufp->chgBit(oldp+964,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_en));
        bufp->chgQData(oldp+965,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wdata),46);
        bufp->chgCData(oldp+967,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wmask),2);
        bufp->chgIData(oldp+968,((0x7fffffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wdata))),23);
        bufp->chgBit(oldp+969,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wmask))));
        bufp->chgIData(oldp+970,((0x7fffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wdata 
                                                       >> 0x17U)))),23);
        bufp->chgBit(oldp+971,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_wmask) 
                                      >> 1U))));
        bufp->chgBit(oldp+972,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__tag_array__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_out_bits_write))));
        bufp->chgBit(oldp+973,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_13_valid));
        bufp->chgBit(oldp+974,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_one_beat)))));
        bufp->chgBit(oldp+975,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_1_MPORT_2_en));
        bufp->chgBit(oldp+976,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_0_MPORT_1_en));
        bufp->chgBit(oldp+977,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__tag_array_MPORT_en)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid))));
        bufp->chgBit(oldp+978,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_one_beat));
        bufp->chgBit(oldp+979,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid));
        bufp->chgBit(oldp+980,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__tag_array_MPORT_en));
        bufp->chgSData(oldp+981,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_0__RW0_addr),9);
        bufp->chgBit(oldp+982,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_0__RW0_en));
        bufp->chgBit(oldp+983,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_0__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_0_MPORT_1_en))));
        bufp->chgSData(oldp+984,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_1__RW0_addr),9);
        bufp->chgBit(oldp+985,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_1__RW0_en));
        bufp->chgBit(oldp+986,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_1__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_1_MPORT_2_en))));
        bufp->chgCData(oldp+987,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_addr),6);
        bufp->chgBit(oldp+988,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_en));
        bufp->chgBit(oldp+989,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__tag_array_MPORT_en))));
        bufp->chgCData(oldp+990,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_set),8);
        bufp->chgBit(oldp+991,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_clr));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x43U])) {
        bufp->chgQData(oldp+992,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tlDM_auto_dmInner_dmInner_tl_in_d_bits_data),64);
        bufp->chgWData(oldp+994,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT____Vcellinp__ram_ext__W0_data),83);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x44U])) {
        bufp->chgBit(oldp+997,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_0));
        bufp->chgCData(oldp+998,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_4) 
                                   << 4U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_3) 
                                              << 3U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_2) 
                                                 << 2U) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_1) 
                                                    << 1U) 
                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_0)))))),5);
        bufp->chgBit(oldp+999,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_1));
        bufp->chgBit(oldp+1000,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_2));
        bufp->chgBit(oldp+1001,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_3));
        bufp->chgBit(oldp+1002,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__irChain__DOT__regs_4));
        bufp->chgCData(oldp+1003,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__mem_0_opcode),3);
        bufp->chgCData(oldp+1004,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__mem_0_param),3);
        bufp->chgCData(oldp+1005,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__mem_0_size),2);
        bufp->chgBit(oldp+1006,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__mem_0_source));
        bufp->chgSData(oldp+1007,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__mem_0_address),9);
        bufp->chgCData(oldp+1008,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__mem_0_mask),4);
        bufp->chgIData(oldp+1009,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__mem_0_data),32);
        bufp->chgBit(oldp+1010,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__mem_0_corrupt));
        bufp->chgQData(oldp+1011,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__mem_0_opcode)) 
                                    << 0x34U) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__mem_0_param)) 
                                                  << 0x31U) 
                                                 | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__mem_0_size)) 
                                                     << 0x2fU) 
                                                    | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__mem_0_source)) 
                                                        << 0x2eU) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__mem_0_address)) 
                                                           << 0x25U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__mem_0_mask)) 
                                                              << 0x21U) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__mem_0_data)) 
                                                                 << 1U) 
                                                                | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__mem_0_corrupt)))))))))),55);
        bufp->chgCData(oldp+1013,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_opcode),3);
        bufp->chgSData(oldp+1014,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address),9);
        bufp->chgIData(oldp+1015,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_data),32);
        bufp->chgCData(oldp+1016,((0x7fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address))),7);
        bufp->chgCData(oldp+1017,((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_opcode))),3);
        bufp->chgBit(oldp+1018,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_data 
                                       >> 3U))));
        bufp->chgBit(oldp+1019,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_data 
                                       >> 2U))));
        bufp->chgBit(oldp+1020,((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_opcode))));
        VL_EXTEND_WI(128,9, __Vtemp_hf845382e__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address));
        bufp->chgWData(oldp+1021,(__Vtemp_hf845382e__0),128);
        bufp->chgCData(oldp+1025,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_1_bits_opcode),3);
        bufp->chgBit(oldp+1026,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__requestAIO_0_0));
        bufp->chgBit(oldp+1027,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__requestAIO_0_1));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x45U])) {
        bufp->chgIData(oldp+1028,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT___dmInner_auto_dmi_in_d_bits_data),32);
        bufp->chgBit(oldp+1029,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_35));
        bufp->chgBit(oldp+1030,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_7));
        bufp->chgBit(oldp+1031,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_58));
        bufp->chgBit(oldp+1032,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_97));
        bufp->chgBit(oldp+1033,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_27));
        bufp->chgBit(oldp+1034,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_39));
        bufp->chgBit(oldp+1035,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_11));
        bufp->chgBit(oldp+1036,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_101));
        bufp->chgBit(oldp+1037,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_15));
        bufp->chgBit(oldp+1038,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_50));
        bufp->chgBit(oldp+1039,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_46));
        bufp->chgBit(oldp+1040,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_106));
        bufp->chgBit(oldp+1041,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_19));
        bufp->chgBit(oldp+1042,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_86));
        bufp->chgBit(oldp+1043,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_54));
        bufp->chgBit(oldp+1044,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_82));
        bufp->chgBit(oldp+1045,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_42));
        bufp->chgBit(oldp+1046,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_3));
        bufp->chgBit(oldp+1047,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_woready_31));
        bufp->chgBit(oldp+1048,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_35));
        bufp->chgBit(oldp+1049,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_7));
        bufp->chgBit(oldp+1050,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_58));
        bufp->chgBit(oldp+1051,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_97));
        bufp->chgBit(oldp+1052,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_27));
        bufp->chgBit(oldp+1053,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_39));
        bufp->chgBit(oldp+1054,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_11));
        bufp->chgBit(oldp+1055,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_101));
        bufp->chgBit(oldp+1056,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_15));
        bufp->chgBit(oldp+1057,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_50));
        bufp->chgBit(oldp+1058,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_46));
        bufp->chgBit(oldp+1059,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_106));
        bufp->chgBit(oldp+1060,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_19));
        bufp->chgBit(oldp+1061,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_86));
        bufp->chgBit(oldp+1062,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_54));
        bufp->chgBit(oldp+1063,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_82));
        bufp->chgBit(oldp+1064,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_3));
        bufp->chgBit(oldp+1065,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__out_roready_31));
        bufp->chgBit(oldp+1066,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiAbstractDataWrEnMaybe_4));
        bufp->chgBit(oldp+1067,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiAbstractDataWrEnMaybe_5));
        bufp->chgBit(oldp+1068,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiAbstractDataWrEnMaybe_6));
        bufp->chgBit(oldp+1069,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiAbstractDataWrEnMaybe_7));
        bufp->chgBit(oldp+1070,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_56));
        bufp->chgBit(oldp+1071,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_57));
        bufp->chgBit(oldp+1072,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_58));
        bufp->chgBit(oldp+1073,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_59));
        bufp->chgBit(oldp+1074,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_36));
        bufp->chgBit(oldp+1075,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_37));
        bufp->chgBit(oldp+1076,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_38));
        bufp->chgBit(oldp+1077,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_39));
        bufp->chgBit(oldp+1078,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_28));
        bufp->chgBit(oldp+1079,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_29));
        bufp->chgBit(oldp+1080,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_30));
        bufp->chgBit(oldp+1081,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_31));
        bufp->chgBit(oldp+1082,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_12));
        bufp->chgBit(oldp+1083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_13));
        bufp->chgBit(oldp+1084,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_14));
        bufp->chgBit(oldp+1085,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_15));
        bufp->chgBit(oldp+1086,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__haltgroupWrEn));
        bufp->chgBit(oldp+1087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_44));
        bufp->chgBit(oldp+1088,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_45));
        bufp->chgBit(oldp+1089,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_46));
        bufp->chgBit(oldp+1090,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_47));
        bufp->chgBit(oldp+1091,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiAbstractDataWrEnMaybe_0));
        bufp->chgBit(oldp+1092,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiAbstractDataWrEnMaybe_1));
        bufp->chgBit(oldp+1093,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiAbstractDataWrEnMaybe_2));
        bufp->chgBit(oldp+1094,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiAbstractDataWrEnMaybe_3));
        bufp->chgBit(oldp+1095,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_60));
        bufp->chgBit(oldp+1096,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_61));
        bufp->chgBit(oldp+1097,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_62));
        bufp->chgBit(oldp+1098,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_63));
        bufp->chgBit(oldp+1099,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_40));
        bufp->chgBit(oldp+1100,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_41));
        bufp->chgBit(oldp+1101,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_42));
        bufp->chgBit(oldp+1102,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_43));
        bufp->chgBit(oldp+1103,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__autoexecdataWrEnMaybe));
        bufp->chgBit(oldp+1104,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__autoexecprogbufWrEnMaybe));
        bufp->chgBit(oldp+1105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_20));
        bufp->chgBit(oldp+1106,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_21));
        bufp->chgBit(oldp+1107,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_22));
        bufp->chgBit(oldp+1108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_23));
        bufp->chgBit(oldp+1109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_24));
        bufp->chgBit(oldp+1110,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_25));
        bufp->chgBit(oldp+1111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_26));
        bufp->chgBit(oldp+1112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_27));
        bufp->chgBit(oldp+1113,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_4));
        bufp->chgBit(oldp+1114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_5));
        bufp->chgBit(oldp+1115,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_6));
        bufp->chgBit(oldp+1116,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_7));
        bufp->chgBit(oldp+1117,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_52));
        bufp->chgBit(oldp+1118,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_53));
        bufp->chgBit(oldp+1119,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_54));
        bufp->chgBit(oldp+1120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_55));
        bufp->chgBit(oldp+1121,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_0));
        bufp->chgBit(oldp+1122,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_1));
        bufp->chgBit(oldp+1123,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_2));
        bufp->chgBit(oldp+1124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_3));
        bufp->chgBit(oldp+1125,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_8));
        bufp->chgBit(oldp+1126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_9));
        bufp->chgBit(oldp+1127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_10));
        bufp->chgBit(oldp+1128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_11));
        bufp->chgBit(oldp+1129,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__ABSTRACTCSWrEnMaybe));
        bufp->chgBit(oldp+1130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_48));
        bufp->chgBit(oldp+1131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_49));
        bufp->chgBit(oldp+1132,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_50));
        bufp->chgBit(oldp+1133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_51));
        bufp->chgBit(oldp+1134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_32));
        bufp->chgBit(oldp+1135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_33));
        bufp->chgBit(oldp+1136,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_34));
        bufp->chgBit(oldp+1137,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_35));
        bufp->chgBit(oldp+1138,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__COMMANDWrEnMaybe));
        bufp->chgBit(oldp+1139,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_16));
        bufp->chgBit(oldp+1140,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_17));
        bufp->chgBit(oldp+1141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_18));
        bufp->chgBit(oldp+1142,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferWrEnMaybe_19));
        bufp->chgBit(oldp+1143,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiAbstractDataAccessVec_0));
        bufp->chgBit(oldp+1144,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiAbstractDataAccessVec_4));
        bufp->chgBit(oldp+1145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferAccessVec_0));
        bufp->chgBit(oldp+1146,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferAccessVec_4));
        bufp->chgBit(oldp+1147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferAccessVec_8));
        bufp->chgBit(oldp+1148,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferAccessVec_12));
        bufp->chgBit(oldp+1149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferAccessVec_16));
        bufp->chgBit(oldp+1150,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferAccessVec_20));
        bufp->chgBit(oldp+1151,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferAccessVec_24));
        bufp->chgBit(oldp+1152,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferAccessVec_28));
        bufp->chgBit(oldp+1153,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferAccessVec_32));
        bufp->chgBit(oldp+1154,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferAccessVec_36));
        bufp->chgBit(oldp+1155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferAccessVec_40));
        bufp->chgBit(oldp+1156,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferAccessVec_44));
        bufp->chgBit(oldp+1157,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferAccessVec_48));
        bufp->chgBit(oldp+1158,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferAccessVec_52));
        bufp->chgBit(oldp+1159,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferAccessVec_56));
        bufp->chgBit(oldp+1160,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__dmiProgramBufferAccessVec_60));
        bufp->chgBit(oldp+1161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__autoexec));
        bufp->chgBit(oldp+1162,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__COMMANDWrEn));
        bufp->chgBit(oldp+1163,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__valid));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x46U])) {
        bufp->chgBit(oldp+1164,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1165,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1166,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1168,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1169,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1170,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1171,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1172,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1173,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1174,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1175,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1177,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1178,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1180,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x47U])) {
        bufp->chgWData(oldp+1182,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d),116);
        bufp->chgWData(oldp+1186,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d),80);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x48U])) {
        bufp->chgWData(oldp+1189,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d),116);
        bufp->chgWData(oldp+1193,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d),80);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x49U])) {
        bufp->chgWData(oldp+1196,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d),116);
        bufp->chgWData(oldp+1200,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d),80);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x4aU])) {
        bufp->chgWData(oldp+1203,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d),116);
        bufp->chgWData(oldp+1207,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d),80);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x4bU])) {
        bufp->chgBit(oldp+1210,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__out_9_valid));
        bufp->chgCData(oldp+1211,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tlDM_io_dmi_dmi_resp_bits_resp),2);
        bufp->chgBit(oldp+1212,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__busy));
        bufp->chgCData(oldp+1213,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_capture_bits_addr),7);
        bufp->chgIData(oldp+1214,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_capture_bits_data),32);
        bufp->chgCData(oldp+1215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_capture_bits_resp),2);
        bufp->chgBit(oldp+1216,((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState))));
        bufp->chgBit(oldp+1217,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState))));
        bufp->chgBit(oldp+1218,((5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState))));
        bufp->chgBit(oldp+1219,((0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState))));
        bufp->chgBit(oldp+1220,((0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState))));
        bufp->chgBit(oldp+1221,((0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState))));
        bufp->chgBit(oldp+1222,((0xdU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState))));
        bufp->chgCData(oldp+1223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState),4);
        bufp->chgBit(oldp+1224,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiBypass_auto_node_out_out_a_valid));
        bufp->chgBit(oldp+1225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__monitor__DOT__a_set));
        bufp->chgBit(oldp+1226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+1227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__widx_incremented));
        bufp->chgBit(oldp+1228,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_1_a_valid));
        bufp->chgBit(oldp+1229,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_0_a_valid));
        bufp->chgBit(oldp+1230,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__in_d_valid));
        bufp->chgCData(oldp+1231,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__in_d_bits_opcode),3);
        bufp->chgBit(oldp+1232,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_2_valid));
        bufp->chgCData(oldp+1233,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_2_bits_opcode),3);
        bufp->chgCData(oldp+1234,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_2_bits_denied) 
                                   << 1U)),2);
        bufp->chgBit(oldp+1235,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_2_bits_denied));
        bufp->chgBit(oldp+1236,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT___bar_auto_out_0_a_valid));
        bufp->chgBit(oldp+1237,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__in_d_bits_opcode))));
        bufp->chgBit(oldp+1238,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+1239,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__winnerQual_1));
        bufp->chgBit(oldp+1240,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_2_bits_opcode))));
        bufp->chgCData(oldp+1241,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_valid),2);
        bufp->chgCData(oldp+1242,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_readys),2);
        bufp->chgBit(oldp+1243,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_readys) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__in_d_valid))));
        bufp->chgBit(oldp+1244,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__readys_readys) 
                                  >> 1U) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_1_a_valid))));
        bufp->chgBit(oldp+1245,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__muxStateEarly_0));
        bufp->chgBit(oldp+1246,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__muxStateEarly_1));
        bufp->chgCData(oldp+1247,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT____Vcellinp__monitor__io_in_d_bits_opcode),3);
        bufp->chgBit(oldp+1248,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT____Vcellinp__monitor__io_in_d_bits_opcode))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x4cU])) {
        bufp->chgBit(oldp+1249,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT___portsAOI_in_0_a_ready_WIRE));
        bufp->chgBit(oldp+1250,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT___io_dmi_resp_ready_output));
        bufp->chgBit(oldp+1251,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_chainIn_shift));
        bufp->chgBit(oldp+1252,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_chainIn_capture));
        bufp->chgBit(oldp+1253,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dmiAccessChain__io_chainIn_update));
        bufp->chgBit(oldp+1254,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT___dmiAccessChain_io_update_valid));
        bufp->chgBit(oldp+1255,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dtmInfoChain__io_chainIn_capture));
        bufp->chgBit(oldp+1256,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dtmInfoChain__io_chainIn_update));
        bufp->chgBit(oldp+1257,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dtmInfoChain__io_chainIn_capture)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__dtmInfoChain__io_chainIn_update))));
        bufp->chgBit(oldp+1258,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__tapIO_idcodeChain__io_chainIn_shift));
        bufp->chgBit(oldp+1259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT____Vcellinp__tapIO_idcodeChain__io_chainIn_capture));
        bufp->chgBit(oldp+1260,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiBypass_auto_node_out_out_d_ready));
        bufp->chgBit(oldp+1261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_incremented));
        bufp->chgBit(oldp+1262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__valid));
        bufp->chgBit(oldp+1263,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__monitor__DOT__d_first_done));
        bufp->chgBit(oldp+1264,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_1_d_ready));
        bufp->chgBit(oldp+1265,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT___io_innerCtrl_valid_output));
        bufp->chgBit(oldp+1266,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT___io_innerCtrl_bits_resumereq_output));
        bufp->chgSData(oldp+1267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT___io_innerCtrl_bits_hartsel_output),10);
        bufp->chgBit(oldp+1268,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT___io_innerCtrl_bits_ackhavereset_output));
        bufp->chgBit(oldp+1269,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT___io_innerCtrl_bits_hasel_output));
        bufp->chgBit(oldp+1270,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__hamask_0));
        bufp->chgBit(oldp+1271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__hamask_1));
        bufp->chgBit(oldp+1272,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__hamask_2));
        bufp->chgBit(oldp+1273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__hamask_3));
        bufp->chgBit(oldp+1274,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__hamask_4));
        bufp->chgBit(oldp+1275,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__hrmaskNxt_0));
        bufp->chgBit(oldp+1276,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__hrmaskNxt_1));
        bufp->chgBit(oldp+1277,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__hrmaskNxt_2));
        bufp->chgBit(oldp+1278,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__hrmaskNxt_3));
        bufp->chgBit(oldp+1279,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__hrmaskNxt_4));
        bufp->chgBit(oldp+1280,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__out_woready_13));
        bufp->chgBit(oldp+1281,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__out_woready_12));
        bufp->chgBit(oldp+1282,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__monitor__DOT__a_set));
        bufp->chgBit(oldp+1283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__monitor__DOT__d_first_done));
        bufp->chgCData(oldp+1284,((0xfU & (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__monitor__DOT__d_first_done))))),4);
        bufp->chgBit(oldp+1285,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmiXbar_auto_out_0_d_ready));
        bufp->chgBit(oldp+1286,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__in_a_ready));
        bufp->chgBit(oldp+1287,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__in_a_ready));
        bufp->chgBit(oldp+1288,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT___bar_auto_out_0_d_ready));
        bufp->chgBit(oldp+1289,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__done_3));
        bufp->chgCData(oldp+1290,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__next_flight),2);
        bufp->chgBit(oldp+1291,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__monitor__DOT__a_set));
        bufp->chgBit(oldp+1292,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__monitor__DOT__d_first_done));
        bufp->chgBit(oldp+1293,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_1_ready));
        bufp->chgBit(oldp+1294,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__monitor__DOT__a_set));
        bufp->chgBit(oldp+1295,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__monitor__DOT__d_first_done));
        bufp->chgBit(oldp+1296,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__monitor__DOT__d_clr));
        bufp->chgCData(oldp+1297,((0xfU & (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__monitor__DOT__d_clr))))),4);
        bufp->chgBit(oldp+1298,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__latch));
        bufp->chgBit(oldp+1299,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__monitor__DOT__a_set));
        bufp->chgBit(oldp+1300,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__monitor__DOT__d_first_done));
        bufp->chgBit(oldp+1301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__monitor__DOT__d_clr));
        bufp->chgCData(oldp+1302,((0xfU & (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__monitor__DOT__d_clr))))),4);
        bufp->chgBit(oldp+1303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__widx_incremented));
    }
    bufp->chgBit(oldp+1304,(vlSelf->clock));
    bufp->chgBit(oldp+1305,(vlSelf->reset));
    bufp->chgBit(oldp+1306,(vlSelf->io_success));
    bufp->chgBit(oldp+1307,((1U & (~ (IData)(vlSelf->reset)))));
    bufp->chgBit(oldp+1308,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__tdoReg));
    bufp->chgBit(oldp+1309,(vlSelf->TestHarness__DOT__chiptop__DOT__dividerOnlyClockGen__DOT___x1_member_allClocks_subsystem_sbus_0_clock_ClockDivideBy1_clk_out));
    __Vtemp_h70020078__0[0U] = vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_0;
    __Vtemp_h70020078__0[1U] = vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_1;
    __Vtemp_h70020078__0[2U] = vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_2;
    __Vtemp_h70020078__0[3U] = vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_3;
    __Vtemp_h70020078__0[4U] = vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_4;
    __Vtemp_h70020078__0[5U] = vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_5;
    __Vtemp_h70020078__0[6U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_7)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_6))));
    __Vtemp_h70020078__0[7U] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_7)) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_6))) 
                                        >> 0x20U));
    bufp->chgIData(oldp+1310,((((0U == (0x1fU & ((0xe0U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx) 
                                                     << 5U)) 
                                                 ^ 
                                                 (0x80U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx) 
                                                     << 4U)))))
                                 ? 0U : (__Vtemp_h70020078__0[
                                         (((IData)(0x1fU) 
                                           + (0xffU 
                                              & ((0xe0U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx) 
                                                     << 5U)) 
                                                 ^ 
                                                 (0x80U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx) 
                                                     << 4U))))) 
                                          >> 5U)] << 
                                         ((IData)(0x20U) 
                                          - (0x1fU 
                                             & ((0xe0U 
                                                 & ((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx) 
                                                    << 5U)) 
                                                ^ (0x80U 
                                                   & ((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx) 
                                                      << 4U))))))) 
                               | (__Vtemp_h70020078__0[
                                  (7U & ((7U & (IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx)) 
                                         ^ (4U & ((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx) 
                                                  >> 1U))))] 
                                  >> (0x1fU & ((0xe0U 
                                                & ((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx) 
                                                   << 5U)) 
                                               ^ (0x80U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx) 
                                                     << 4U))))))),32);
    __Vtemp_hf7f54520__0[0U] = vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_0;
    __Vtemp_hf7f54520__0[1U] = vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_1;
    __Vtemp_hf7f54520__0[2U] = vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_2;
    __Vtemp_hf7f54520__0[3U] = vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_3;
    __Vtemp_hf7f54520__0[4U] = vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_4;
    __Vtemp_hf7f54520__0[5U] = vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_5;
    __Vtemp_hf7f54520__0[6U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_7)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_6))));
    __Vtemp_hf7f54520__0[7U] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_7)) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_6))) 
                                        >> 0x20U));
    bufp->chgIData(oldp+1311,((((0U == (0x1fU & ((0xe0U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                                     << 5U)) 
                                                 ^ 
                                                 (0x80U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                                     << 4U)))))
                                 ? 0U : (__Vtemp_hf7f54520__0[
                                         (((IData)(0x1fU) 
                                           + (0xffU 
                                              & ((0xe0U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                                     << 5U)) 
                                                 ^ 
                                                 (0x80U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                                     << 4U))))) 
                                          >> 5U)] << 
                                         ((IData)(0x20U) 
                                          - (0x1fU 
                                             & ((0xe0U 
                                                 & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                                    << 5U)) 
                                                ^ (0x80U 
                                                   & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                                      << 4U))))))) 
                               | (__Vtemp_hf7f54520__0[
                                  (7U & ((7U & (IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx)) 
                                         ^ (4U & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                                  >> 1U))))] 
                                  >> (0x1fU & ((0xe0U 
                                                & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                                   << 5U)) 
                                               ^ (0x80U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                                     << 4U))))))),32);
    bufp->chgBit(oldp+1312,(vlSelf->TestHarness__DOT__chiptop__DOT__debug_reset));
    bufp->chgBit(oldp+1313,(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset));
    bufp->chgBit(oldp+1314,(vlSelf->TestHarness__DOT__chiptop__DOT___gated_clock_debug_clock_gate_out));
    bufp->chgBit(oldp+1315,((1U & ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT___io_deq_valid_output)) 
                                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT___io_deq_valid_output))) 
                                    & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT___io_deq_valid_output))) 
                                   & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT___io_deq_valid_output))))));
    bufp->chgBit(oldp+1316,((1U & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_rctrl_0 
                                    >> 5U) & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT___io_deq_valid_output))))));
    bufp->chgBit(oldp+1317,((1U & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_rctrl_1 
                                    >> 5U) & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT___io_deq_valid_output))))));
    bufp->chgBit(oldp+1318,((1U & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_rctrl_2 
                                    >> 5U) & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT___io_deq_valid_output))))));
    bufp->chgBit(oldp+1319,((1U & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_rctrl_3 
                                    >> 5U) & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT___io_deq_valid_output))))));
    bufp->chgBit(oldp+1320,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_4_reset));
    bufp->chgBit(oldp+1321,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_3_reset));
    bufp->chgBit(oldp+1322,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset));
    bufp->chgBit(oldp+1323,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_1_reset));
    __Vtemp_hd69b3694__0[0U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_haltreq) 
                                 << 0x1fU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_hasel) 
                                               << 0x1aU) 
                                              | ((0x70000U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_hartsello) 
                                                     << 0x10U)) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_ndmreset) 
                                                     << 1U) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_dmactive) 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmactiveAck_dmactiveAckSync__DOT__output_chain__DOT__sync_0))))));
    __Vtemp_hd69b3694__0[1U] = 0x112380U;
    __Vtemp_hd69b3694__0[2U] = (IData)((QData)((IData)(
                                                       (0x1fU 
                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__HAMASKReg_maskdata))));
    __Vtemp_hd69b3694__0[3U] = (IData)(((QData)((IData)(
                                                        (0x1fU 
                                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__HAMASKReg_maskdata))) 
                                        >> 0x20U));
    bufp->chgIData(oldp+1324,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__muxStateEarly_0)
                                 ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)
                                     ? 0U : (IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                     >> 1U)))
                                 : 0U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__muxStateEarly_1)
                                           ? ((1U & 
                                               ((8U 
                                                 | ((4U 
                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address)) 
                                                    | ((2U 
                                                        & ((~ 
                                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address) 
                                                             >> 2U)) 
                                                           << 1U)) 
                                                       | (1U 
                                                          & (~ 
                                                             ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address) 
                                                              >> 2U)))))) 
                                                >> 
                                                (3U 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address) 
                                                    >> 3U))))
                                               ? __Vtemp_hd69b3694__0[
                                              (3U & 
                                               ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address) 
                                                >> 3U))]
                                               : 0U)
                                           : 0U))),32);
    bufp->chgBit(oldp+1325,(((0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
                             & (IData)(vlSelf->TestHarness__DOT__SimJTAG__DOT_____05Fjtag_TDI))));
    bufp->chgBit(oldp+1326,(((0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
                             & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState)))));
    bufp->chgBit(oldp+1327,(((0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
                             & (IData)(vlSelf->TestHarness__DOT__SimJTAG__DOT_____05Fjtag_TDI))));
    bufp->chgBit(oldp+1328,(((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction))
                              ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_0)
                              : ((0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction))
                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dtmInfoChain__DOT__regs_0)
                                  : ((0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction))
                                      ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_0)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_bypassChain__DOT__reg_0))))));
    bufp->chgBit(oldp+1329,(((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
                             & (IData)(vlSelf->TestHarness__DOT__SimJTAG__DOT_____05Fjtag_TDI))));
    bufp->chgBit(oldp+1330,(((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__activeInstruction)) 
                             & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_controllerInternal__DOT__stateMachine__DOT__currState)))));
    bufp->chgBit(oldp+1331,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_1_reset)))));
    bufp->chgBit(oldp+1332,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset)))));
    bufp->chgBit(oldp+1333,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_3_reset)))));
    bufp->chgBit(oldp+1334,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_4_reset)))));
    bufp->chgSData(oldp+1335,(((0x23fU >= (0x3ffU & 
                                           ((IData)(9U) 
                                            * ((0x3fU 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__ridx)) 
                                               ^ (0x20U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__ridx) 
                                                     >> 1U))))))
                                ? (0x1ffU & (((0U == 
                                               (0x1fU 
                                                & ((IData)(9U) 
                                                   * 
                                                   ((0x3fU 
                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__ridx)) 
                                                    ^ 
                                                    (0x20U 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__ridx) 
                                                        >> 1U))))))
                                               ? 0U
                                               : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[
                                                  (((IData)(8U) 
                                                    + 
                                                    (0x3ffU 
                                                     & ((IData)(9U) 
                                                        * 
                                                        ((0x3fU 
                                                          & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__ridx)) 
                                                         ^ 
                                                         (0x20U 
                                                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__ridx) 
                                                             >> 1U)))))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(9U) 
                                                       * 
                                                       ((0x3fU 
                                                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__ridx)) 
                                                        ^ 
                                                        (0x20U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__ridx) 
                                                            >> 1U)))))))) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[
                                                (0x1fU 
                                                 & (((IData)(9U) 
                                                     * 
                                                     ((0x3fU 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__ridx)) 
                                                      ^ 
                                                      (0x20U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__ridx) 
                                                          >> 1U)))) 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(9U) 
                                                    * 
                                                    ((0x3fU 
                                                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__ridx)) 
                                                     ^ 
                                                     (0x20U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__ridx) 
                                                         >> 1U))))))))
                                : 0U)),9);
    bufp->chgSData(oldp+1336,(((0x23fU >= (0x3ffU & 
                                           ((IData)(9U) 
                                            * ((0x3fU 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__ridx)) 
                                               ^ (0x20U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__ridx) 
                                                     >> 1U))))))
                                ? (0x1ffU & (((0U == 
                                               (0x1fU 
                                                & ((IData)(9U) 
                                                   * 
                                                   ((0x3fU 
                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__ridx)) 
                                                    ^ 
                                                    (0x20U 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__ridx) 
                                                        >> 1U))))))
                                               ? 0U
                                               : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT___GEN[
                                                  (((IData)(8U) 
                                                    + 
                                                    (0x3ffU 
                                                     & ((IData)(9U) 
                                                        * 
                                                        ((0x3fU 
                                                          & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__ridx)) 
                                                         ^ 
                                                         (0x20U 
                                                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__ridx) 
                                                             >> 1U)))))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(9U) 
                                                       * 
                                                       ((0x3fU 
                                                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__ridx)) 
                                                        ^ 
                                                        (0x20U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__ridx) 
                                                            >> 1U)))))))) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT___GEN[
                                                (0x1fU 
                                                 & (((IData)(9U) 
                                                     * 
                                                     ((0x3fU 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__ridx)) 
                                                      ^ 
                                                      (0x20U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__ridx) 
                                                          >> 1U)))) 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(9U) 
                                                    * 
                                                    ((0x3fU 
                                                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__ridx)) 
                                                     ^ 
                                                     (0x20U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__ridx) 
                                                         >> 1U))))))))
                                : 0U)),9);
    bufp->chgSData(oldp+1337,(((0x23fU >= (0x3ffU & 
                                           ((IData)(9U) 
                                            * ((0x3fU 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__ridx)) 
                                               ^ (0x20U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__ridx) 
                                                     >> 1U))))))
                                ? (0x1ffU & (((0U == 
                                               (0x1fU 
                                                & ((IData)(9U) 
                                                   * 
                                                   ((0x3fU 
                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__ridx)) 
                                                    ^ 
                                                    (0x20U 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__ridx) 
                                                        >> 1U))))))
                                               ? 0U
                                               : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT___GEN[
                                                  (((IData)(8U) 
                                                    + 
                                                    (0x3ffU 
                                                     & ((IData)(9U) 
                                                        * 
                                                        ((0x3fU 
                                                          & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__ridx)) 
                                                         ^ 
                                                         (0x20U 
                                                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__ridx) 
                                                             >> 1U)))))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(9U) 
                                                       * 
                                                       ((0x3fU 
                                                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__ridx)) 
                                                        ^ 
                                                        (0x20U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__ridx) 
                                                            >> 1U)))))))) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT___GEN[
                                                (0x1fU 
                                                 & (((IData)(9U) 
                                                     * 
                                                     ((0x3fU 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__ridx)) 
                                                      ^ 
                                                      (0x20U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__ridx) 
                                                          >> 1U)))) 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(9U) 
                                                    * 
                                                    ((0x3fU 
                                                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__ridx)) 
                                                     ^ 
                                                     (0x20U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__ridx) 
                                                         >> 1U))))))))
                                : 0U)),9);
    bufp->chgSData(oldp+1338,(((0x23fU >= (0x3ffU & 
                                           ((IData)(9U) 
                                            * ((0x3fU 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__ridx)) 
                                               ^ (0x20U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__ridx) 
                                                     >> 1U))))))
                                ? (0x1ffU & (((0U == 
                                               (0x1fU 
                                                & ((IData)(9U) 
                                                   * 
                                                   ((0x3fU 
                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__ridx)) 
                                                    ^ 
                                                    (0x20U 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__ridx) 
                                                        >> 1U))))))
                                               ? 0U
                                               : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT___GEN[
                                                  (((IData)(8U) 
                                                    + 
                                                    (0x3ffU 
                                                     & ((IData)(9U) 
                                                        * 
                                                        ((0x3fU 
                                                          & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__ridx)) 
                                                         ^ 
                                                         (0x20U 
                                                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__ridx) 
                                                             >> 1U)))))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(9U) 
                                                       * 
                                                       ((0x3fU 
                                                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__ridx)) 
                                                        ^ 
                                                        (0x20U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__ridx) 
                                                            >> 1U)))))))) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT___GEN[
                                                (0x1fU 
                                                 & (((IData)(9U) 
                                                     * 
                                                     ((0x3fU 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__ridx)) 
                                                      ^ 
                                                      (0x20U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__ridx) 
                                                          >> 1U)))) 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(9U) 
                                                    * 
                                                    ((0x3fU 
                                                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__ridx)) 
                                                     ^ 
                                                     (0x20U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__ridx) 
                                                         >> 1U))))))))
                                : 0U)),9);
    bufp->chgBit(oldp+1339,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__intsource__DOT__reg_0__DOT__reg_0));
    bufp->chgBit(oldp+1340,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__intsource__DOT__reg_0__DOT__reg_0) 
                             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__gateways_gateway__DOT__inFlight)))));
    VL_EXTEND_WI(66,1, __Vtemp_h8b172a8e__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_4__DOT__reg_0));
    __Vtemp_hfa1b71f5__0[0U] = (IData)((((QData)((IData)(
                                                         ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_1__DOT__reg_0) 
                                                          << 0x1fU))) 
                                         << 1U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_0__DOT__reg_0))));
    __Vtemp_hfa1b71f5__0[1U] = (((IData)((((QData)((IData)(
                                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_3__DOT__reg_0) 
                                                            << 0x1fU))) 
                                           << 1U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_2__DOT__reg_0)))) 
                                 << 1U) | (IData)((
                                                   (((QData)((IData)(
                                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_1__DOT__reg_0) 
                                                                      << 0x1fU))) 
                                                     << 1U) 
                                                    | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_0__DOT__reg_0))) 
                                                   >> 0x20U)));
    __Vtemp_hfa1b71f5__0[2U] = (((IData)((((QData)((IData)(
                                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_3__DOT__reg_0) 
                                                            << 0x1fU))) 
                                           << 1U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_2__DOT__reg_0)))) 
                                 >> 0x1fU) | ((__Vtemp_h8b172a8e__0[0U] 
                                               << 2U) 
                                              | ((IData)(
                                                         ((((QData)((IData)(
                                                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_3__DOT__reg_0) 
                                                                             << 0x1fU))) 
                                                            << 1U) 
                                                           | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_2__DOT__reg_0))) 
                                                          >> 0x20U)) 
                                                 << 1U)));
    __Vtemp_hfa1b71f5__0[3U] = (((1U & (__Vtemp_h8b172a8e__0[0U] 
                                        >> 0x1eU)) 
                                 | ((IData)(((((QData)((IData)(
                                                               ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_3__DOT__reg_0) 
                                                                << 0x1fU))) 
                                               << 1U) 
                                              | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_2__DOT__reg_0))) 
                                             >> 0x20U)) 
                                    >> 0x1fU)) | ((2U 
                                                   & (__Vtemp_h8b172a8e__0[0U] 
                                                      >> 0x1eU)) 
                                                  | (__Vtemp_h8b172a8e__0[1U] 
                                                     << 2U)));
    __Vtemp_hfa1b71f5__0[4U] = ((1U & (__Vtemp_h8b172a8e__0[1U] 
                                       >> 0x1eU)) | 
                                ((2U & (__Vtemp_h8b172a8e__0[1U] 
                                        >> 0x1eU)) 
                                 | (__Vtemp_h8b172a8e__0[2U] 
                                    << 2U)));
    bufp->chgQData(oldp+1341,(((1U & ((8U | (7U & (- (IData)(
                                                             (0U 
                                                              == 
                                                              (0x7fU 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0x18U))))))) 
                                      >> (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0x16U))))
                                ? ((0x83U >= (0xffU 
                                              & ((IData)(0x21U) 
                                                 * 
                                                 (3U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0x16U)))))
                                    ? (0x1ffffffffULL 
                                       & (((QData)((IData)(
                                                           __Vtemp_hfa1b71f5__0[
                                                           (((IData)(0x20U) 
                                                             + 
                                                             (0xffU 
                                                              & ((IData)(0x21U) 
                                                                 * 
                                                                 (3U 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                     >> 0x16U))))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(0x21U) 
                                                    * 
                                                    (3U 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                        >> 0x16U)))))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x21U) 
                                                       * 
                                                       (3U 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0x16U))))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(0x21U) 
                                                   * 
                                                   (3U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 0x16U)))))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_hfa1b71f5__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0xffU 
                                                                     & ((IData)(0x21U) 
                                                                        * 
                                                                        (3U 
                                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                            >> 0x16U))))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x21U) 
                                                       * 
                                                       (3U 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0x16U))))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_hfa1b71f5__0[
                                                                (7U 
                                                                 & (((IData)(0x21U) 
                                                                     * 
                                                                     (3U 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                         >> 0x16U))) 
                                                                    >> 5U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(0x21U) 
                                                    * 
                                                    (3U 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                        >> 0x16U))))))))
                                    : 0ULL) : 0ULL)),64);
    VL_EXTEND_WQ(99,33, __Vtemp_h29dd9bbf__0, (((QData)((IData)(
                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_11__DOT__reg_0) 
                                                                 << 0x1fU))) 
                                                << 1U) 
                                               | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_10__DOT__reg_0))));
    __Vtemp_h18b80426__0[3U] = (((1U & ((IData)((((QData)((IData)(
                                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_9__DOT__reg_0) 
                                                                   << 0x1fU))) 
                                                  << 1U) 
                                                 | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_8__DOT__reg_0)))) 
                                        >> 0x1eU)) 
                                 | ((IData)(((((QData)((IData)(
                                                               ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_7__DOT__reg_0) 
                                                                << 0x1fU))) 
                                               << 1U) 
                                              | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_6__DOT__reg_0))) 
                                             >> 0x20U)) 
                                    >> 0x1fU)) | ((2U 
                                                   & ((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_9__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                << 1U) 
                                                               | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_8__DOT__reg_0)))) 
                                                      >> 0x1eU)) 
                                                  | ((__Vtemp_h29dd9bbf__0[0U] 
                                                      << 3U) 
                                                     | ((IData)(
                                                                ((((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_9__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                   << 1U) 
                                                                  | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_8__DOT__reg_0))) 
                                                                 >> 0x20U)) 
                                                        << 2U))));
    __Vtemp_h18b80426__0[4U] = ((1U & ((__Vtemp_h29dd9bbf__0[0U] 
                                        >> 0x1dU) | 
                                       ((IData)(((((QData)((IData)(
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_9__DOT__reg_0) 
                                                                    << 0x1fU))) 
                                                   << 1U) 
                                                  | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_8__DOT__reg_0))) 
                                                 >> 0x20U)) 
                                        >> 0x1eU))) 
                                | ((2U & ((__Vtemp_h29dd9bbf__0[0U] 
                                           >> 0x1dU) 
                                          | ((IData)(
                                                     ((((QData)((IData)(
                                                                        ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_9__DOT__reg_0) 
                                                                         << 0x1fU))) 
                                                        << 1U) 
                                                       | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_8__DOT__reg_0))) 
                                                      >> 0x20U)) 
                                             >> 0x1eU))) 
                                   | ((4U & (__Vtemp_h29dd9bbf__0[0U] 
                                             >> 0x1dU)) 
                                      | (__Vtemp_h29dd9bbf__0[1U] 
                                         << 3U))));
    __Vtemp_ha5c2367a__0[3U] = (((1U & ((IData)((((QData)((IData)(
                                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_7__DOT__reg_0) 
                                                                   << 0x1fU))) 
                                                  << 1U) 
                                                 | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_6__DOT__reg_0)))) 
                                        >> 0x1eU)) 
                                 | ((IData)(((((QData)((IData)(
                                                               ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_5__DOT__reg_0) 
                                                                << 0x1fU))) 
                                               << 1U) 
                                              | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_4__DOT__reg_0))) 
                                             >> 0x20U)) 
                                    >> 0x1fU)) | ((2U 
                                                   & ((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_7__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                << 1U) 
                                                               | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_6__DOT__reg_0)))) 
                                                      >> 0x1eU)) 
                                                  | (((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_9__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                << 1U) 
                                                               | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_8__DOT__reg_0)))) 
                                                      << 3U) 
                                                     | ((IData)(
                                                                ((((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_7__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                   << 1U) 
                                                                  | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_6__DOT__reg_0))) 
                                                                 >> 0x20U)) 
                                                        << 2U))));
    __Vtemp_ha5c2367a__0[7U] = ((1U & (__Vtemp_h29dd9bbf__0[2U] 
                                       >> 0x1cU)) | 
                                ((2U & (__Vtemp_h29dd9bbf__0[2U] 
                                        >> 0x1cU)) 
                                 | ((4U & (__Vtemp_h29dd9bbf__0[2U] 
                                           >> 0x1cU)) 
                                    | ((8U & (__Vtemp_h29dd9bbf__0[2U] 
                                              >> 0x1cU)) 
                                       | (__Vtemp_h29dd9bbf__0[3U] 
                                          << 4U)))));
    __Vtemp_h75c96048__0[0U] = (IData)((((QData)((IData)(
                                                         ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_1__DOT__reg_0) 
                                                          << 0x1fU))) 
                                         << 1U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_0__DOT__reg_0))));
    __Vtemp_h75c96048__0[1U] = (((IData)((((QData)((IData)(
                                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_3__DOT__reg_0) 
                                                            << 0x1fU))) 
                                           << 1U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_2__DOT__reg_0)))) 
                                 << 1U) | (IData)((
                                                   (((QData)((IData)(
                                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_1__DOT__reg_0) 
                                                                      << 0x1fU))) 
                                                     << 1U) 
                                                    | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_0__DOT__reg_0))) 
                                                   >> 0x20U)));
    __Vtemp_h75c96048__0[2U] = (((IData)((((QData)((IData)(
                                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_3__DOT__reg_0) 
                                                            << 0x1fU))) 
                                           << 1U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_2__DOT__reg_0)))) 
                                 >> 0x1fU) | (((IData)(
                                                       (((QData)((IData)(
                                                                         ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_5__DOT__reg_0) 
                                                                          << 0x1fU))) 
                                                         << 1U) 
                                                        | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_4__DOT__reg_0)))) 
                                               << 2U) 
                                              | ((IData)(
                                                         ((((QData)((IData)(
                                                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_3__DOT__reg_0) 
                                                                             << 0x1fU))) 
                                                            << 1U) 
                                                           | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_2__DOT__reg_0))) 
                                                          >> 0x20U)) 
                                                 << 1U)));
    __Vtemp_h75c96048__0[3U] = (((1U & ((IData)((((QData)((IData)(
                                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_5__DOT__reg_0) 
                                                                   << 0x1fU))) 
                                                  << 1U) 
                                                 | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_4__DOT__reg_0)))) 
                                        >> 0x1eU)) 
                                 | ((IData)(((((QData)((IData)(
                                                               ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_3__DOT__reg_0) 
                                                                << 0x1fU))) 
                                               << 1U) 
                                              | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_2__DOT__reg_0))) 
                                             >> 0x20U)) 
                                    >> 0x1fU)) | ((2U 
                                                   & ((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_5__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                << 1U) 
                                                               | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_4__DOT__reg_0)))) 
                                                      >> 0x1eU)) 
                                                  | (((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_7__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                << 1U) 
                                                               | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_6__DOT__reg_0)))) 
                                                      << 3U) 
                                                     | ((IData)(
                                                                ((((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_5__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                   << 1U) 
                                                                  | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_4__DOT__reg_0))) 
                                                                 >> 0x20U)) 
                                                        << 2U))));
    __Vtemp_h75c96048__0[4U] = ((1U & (((IData)((((QData)((IData)(
                                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_7__DOT__reg_0) 
                                                                   << 0x1fU))) 
                                                  << 1U) 
                                                 | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_6__DOT__reg_0)))) 
                                        >> 0x1dU) | 
                                       ((IData)(((((QData)((IData)(
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_5__DOT__reg_0) 
                                                                    << 0x1fU))) 
                                                   << 1U) 
                                                  | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_4__DOT__reg_0))) 
                                                 >> 0x20U)) 
                                        >> 0x1eU))) 
                                | (__Vtemp_ha5c2367a__0[3U] 
                                   << 1U));
    __Vtemp_h75c96048__0[5U] = ((__Vtemp_ha5c2367a__0[3U] 
                                 >> 0x1fU) | ((2U & 
                                               ((0xeU 
                                                 & ((IData)(
                                                            (((QData)((IData)(
                                                                              ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_9__DOT__reg_0) 
                                                                               << 0x1fU))) 
                                                              << 1U) 
                                                             | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_8__DOT__reg_0)))) 
                                                    >> 0x1cU)) 
                                                | (6U 
                                                   & ((IData)(
                                                              ((((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_7__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                 << 1U) 
                                                                | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_6__DOT__reg_0))) 
                                                               >> 0x20U)) 
                                                      >> 0x1dU)))) 
                                              | (__Vtemp_h18b80426__0[3U] 
                                                 << 2U)));
    __Vtemp_h75c96048__0[6U] = ((1U & (__Vtemp_h18b80426__0[3U] 
                                       >> 0x1eU)) | 
                                ((2U & (__Vtemp_h18b80426__0[3U] 
                                        >> 0x1eU)) 
                                 | (__Vtemp_h18b80426__0[4U] 
                                    << 2U)));
    __Vtemp_h75c96048__0[7U] = ((1U & (__Vtemp_h18b80426__0[4U] 
                                       >> 0x1eU)) | 
                                ((2U & (__Vtemp_h18b80426__0[4U] 
                                        >> 0x1eU)) 
                                 | ((4U & (__Vtemp_h29dd9bbf__0[1U] 
                                           >> 0x1bU)) 
                                    | ((8U & (__Vtemp_h29dd9bbf__0[1U] 
                                              >> 0x1bU)) 
                                       | ((0x10U & 
                                           (__Vtemp_h29dd9bbf__0[1U] 
                                            >> 0x1bU)) 
                                          | (__Vtemp_h29dd9bbf__0[2U] 
                                             << 5U))))));
    __Vtemp_h75c96048__0[8U] = ((1U & (__Vtemp_h29dd9bbf__0[2U] 
                                       >> 0x1bU)) | 
                                (__Vtemp_ha5c2367a__0[7U] 
                                 << 1U));
    bufp->chgQData(oldp+1343,(((1U & ((0xc0U | (0x3fU 
                                                & (- (IData)(
                                                             (0U 
                                                              == 
                                                              (0x3fU 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0x19U))))))) 
                                      >> (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0x16U))))
                                ? ((0x107U >= (0x1ffU 
                                               & ((IData)(0x21U) 
                                                  * 
                                                  (7U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0x16U)))))
                                    ? (0x1ffffffffULL 
                                       & (((QData)((IData)(
                                                           __Vtemp_h75c96048__0[
                                                           (((IData)(0x20U) 
                                                             + 
                                                             (0x1ffU 
                                                              & ((IData)(0x21U) 
                                                                 * 
                                                                 (7U 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                     >> 0x16U))))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(0x21U) 
                                                    * 
                                                    (7U 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                        >> 0x16U)))))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x21U) 
                                                       * 
                                                       (7U 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0x16U))))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(0x21U) 
                                                   * 
                                                   (7U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 0x16U)))))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_h75c96048__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & ((IData)(0x21U) 
                                                                        * 
                                                                        (7U 
                                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                            >> 0x16U))))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x21U) 
                                                       * 
                                                       (7U 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0x16U))))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_h75c96048__0[
                                                                (0xfU 
                                                                 & (((IData)(0x21U) 
                                                                     * 
                                                                     (7U 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                         >> 0x16U))) 
                                                                    >> 5U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(0x21U) 
                                                    * 
                                                    (7U 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                        >> 0x16U))))))))
                                    : 0ULL) : 0ULL)),64);
    bufp->chgBit(oldp+1345,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_2__DOT__reg_0));
    bufp->chgBit(oldp+1346,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_3__DOT__reg_0));
    bufp->chgBit(oldp+1347,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_4__DOT__reg_0));
    bufp->chgBit(oldp+1348,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_5__DOT__reg_0));
    bufp->chgBit(oldp+1349,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__x1_member_allClocks_tileClockGroup_tile_1_clock_cg__DOT__en_latched));
    bufp->chgBit(oldp+1350,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__x1_member_allClocks_tileClockGroup_tile_2_clock_cg__DOT__en_latched));
    bufp->chgBit(oldp+1351,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__x1_member_allClocks_tileClockGroup_tile_3_clock_cg__DOT__en_latched));
    bufp->chgBit(oldp+1352,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__x1_member_allClocks_tileClockGroup_tile_4_clock_cg__DOT__en_latched));
    VL_EXTEND_WQ(256,64, __Vtemp_h33641d2a__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_4);
    __Vtemp_h8236c4c9__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_0;
    __Vtemp_h8236c4c9__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_1;
    __Vtemp_h8236c4c9__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_2;
    __Vtemp_h8236c4c9__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_3;
    __Vtemp_h8236c4c9__0[4U] = (IData)((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_4)));
    __Vtemp_h8236c4c9__0[5U] = (IData)(((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_4)) 
                                        >> 0x20U));
    __Vtemp_h8236c4c9__0[6U] = 0U;
    __Vtemp_h8236c4c9__0[7U] = 0U;
    __Vtemp_h8236c4c9__0[8U] = 0U;
    __Vtemp_h8236c4c9__0[9U] = 0U;
    __Vtemp_h8236c4c9__0[0xaU] = 0U;
    __Vtemp_h8236c4c9__0[0xbU] = 0U;
    __Vtemp_h8236c4c9__0[0xcU] = 0U;
    __Vtemp_h8236c4c9__0[0xdU] = 0U;
    __Vtemp_h8236c4c9__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0);
    __Vtemp_h8236c4c9__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                          >> 0x20U));
    __Vtemp_h8236c4c9__0[0x10U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_0);
    __Vtemp_h8236c4c9__0[0x11U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_0 
                                           >> 0x20U));
    __Vtemp_h8236c4c9__0[0x12U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_1);
    __Vtemp_h8236c4c9__0[0x13U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_1 
                                           >> 0x20U));
    __Vtemp_h8236c4c9__0[0x14U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_2);
    __Vtemp_h8236c4c9__0[0x15U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_2 
                                           >> 0x20U));
    __Vtemp_h8236c4c9__0[0x16U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_3);
    __Vtemp_h8236c4c9__0[0x17U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_3 
                                           >> 0x20U));
    __Vtemp_h8236c4c9__0[0x18U] = __Vtemp_h33641d2a__0[0U];
    __Vtemp_h8236c4c9__0[0x19U] = __Vtemp_h33641d2a__0[1U];
    __Vtemp_h8236c4c9__0[0x1aU] = __Vtemp_h33641d2a__0[2U];
    __Vtemp_h8236c4c9__0[0x1bU] = __Vtemp_h33641d2a__0[3U];
    __Vtemp_h8236c4c9__0[0x1cU] = __Vtemp_h33641d2a__0[4U];
    __Vtemp_h8236c4c9__0[0x1dU] = __Vtemp_h33641d2a__0[5U];
    __Vtemp_h8236c4c9__0[0x1eU] = __Vtemp_h33641d2a__0[6U];
    __Vtemp_h8236c4c9__0[0x1fU] = __Vtemp_h33641d2a__0[7U];
    bufp->chgQData(oldp+1353,(((((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_0)
                                        ? (((QData)((IData)(
                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                            << 0x2eU) 
                                           | (((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                               << 0xeU) 
                                              | ((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                 >> 0x12U)))
                                        : 0ULL) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_1)
                                                    ? 
                                                   (((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                                                     [0U][2U])) 
                                                     << 0x2cU) 
                                                    | (((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                                                        [0U][1U])) 
                                                        << 0xcU) 
                                                       | ((QData)((IData)(
                                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                                                          [0U][0U])) 
                                                          >> 0x14U)))
                                                    : 0ULL)) 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_2)
                                         ? (((QData)((IData)(
                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                             << 0x2fU) 
                                            | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                << 0xfU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                  >> 0x11U)))
                                         : 0ULL)) | 
                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_3)
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___plicDomainWrapper_auto_plic_in_d_bits_data
                                      : 0ULL)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_4)
                                                   ? 
                                                  ((1U 
                                                    & ((0xe078U 
                                                        | (((0U 
                                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT___GEN)) 
                                                            << 0xcU) 
                                                           | (((0U 
                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT___GEN)) 
                                                               << 0xbU) 
                                                              | (((0U 
                                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT___GEN)) 
                                                                  << 0xaU) 
                                                                 | (((0U 
                                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT___GEN)) 
                                                                     << 9U) 
                                                                    | (((0U 
                                                                         == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT___GEN)) 
                                                                        << 8U) 
                                                                       | (((IData)(
                                                                                (0x1ffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT___GEN))) 
                                                                           << 7U) 
                                                                          | (7U 
                                                                             & (- (IData)(
                                                                                (0U 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT___GEN)))))))))))) 
                                                       >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex)))
                                                    ? 
                                                   (((QData)((IData)(
                                                                     __Vtemp_h8236c4c9__0[
                                                                     (((IData)(0x3fU) 
                                                                       + 
                                                                       (0x3ffU 
                                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex) 
                                                                           << 6U))) 
                                                                      >> 5U)])) 
                                                     << 
                                                     ((0U 
                                                       == 
                                                       (0x1fU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex) 
                                                           << 6U)))
                                                       ? 0x20U
                                                       : 
                                                      ((IData)(0x40U) 
                                                       - 
                                                       (0x1fU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex) 
                                                           << 6U))))) 
                                                    | (((0U 
                                                         == 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex) 
                                                             << 6U)))
                                                         ? 0ULL
                                                         : 
                                                        ((QData)((IData)(
                                                                         __Vtemp_h8236c4c9__0[
                                                                         (((IData)(0x1fU) 
                                                                           + 
                                                                           (0x3ffU 
                                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex) 
                                                                               << 6U))) 
                                                                          >> 5U)])) 
                                                         << 
                                                         ((IData)(0x20U) 
                                                          - 
                                                          (0x1fU 
                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex) 
                                                              << 6U))))) 
                                                       | ((QData)((IData)(
                                                                          __Vtemp_h8236c4c9__0[
                                                                          (0x1eU 
                                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex) 
                                                                              << 1U))])) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex) 
                                                              << 6U)))))
                                                    : 0ULL)
                                                   : 0ULL)) 
                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_5)
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tlDM_auto_dmInner_dmInner_tl_in_d_bits_data
                                      : 0ULL)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_6)
                                                   ? 
                                                  ((0U 
                                                    != 
                                                    (7U 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_address 
                                                        >> 0xdU)))
                                                    ? 0ULL
                                                    : 
                                                   (((QData)((IData)(
                                                                     VTestHarness__ConstPool__CONST_h5f0e7fd6_0[
                                                                     (((IData)(0x3fU) 
                                                                       + 
                                                                       (0xffc0U 
                                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_address 
                                                                           << 3U))) 
                                                                      >> 5U)])) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      VTestHarness__ConstPool__CONST_h5f0e7fd6_0[
                                                                      (0x7feU 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_address 
                                                                          >> 2U))]))))
                                                   : 0ULL)) 
                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_7)
                                    ? (((QData)((IData)(
                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                        << 0x2cU) | 
                                       (((QData)((IData)(
                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                         << 0xcU) | 
                                        ((QData)((IData)(
                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                         >> 0x14U)))
                                    : 0ULL)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__muxStateEarly_8)
                                                 ? 
                                                (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                                  << 0x2cU) 
                                                 | (((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                     << 0xcU) 
                                                    | ((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                       >> 0x14U)))
                                                 : 0ULL))),64);
    VL_EXTEND_WQ(99,33, __Vtemp_h29dd9bbf__1, (((QData)((IData)(
                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_11__DOT__reg_0) 
                                                                 << 0x1fU))) 
                                                << 1U) 
                                               | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_10__DOT__reg_0))));
    __Vtemp_hf5eb69f0__0[3U] = (((1U & ((IData)((((QData)((IData)(
                                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_9__DOT__reg_0) 
                                                                   << 0x1fU))) 
                                                  << 1U) 
                                                 | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_8__DOT__reg_0)))) 
                                        >> 0x1eU)) 
                                 | ((IData)(((((QData)((IData)(
                                                               ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_7__DOT__reg_0) 
                                                                << 0x1fU))) 
                                               << 1U) 
                                              | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_6__DOT__reg_0))) 
                                             >> 0x20U)) 
                                    >> 0x1fU)) | ((2U 
                                                   & ((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_9__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                << 1U) 
                                                               | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_8__DOT__reg_0)))) 
                                                      >> 0x1eU)) 
                                                  | ((__Vtemp_h29dd9bbf__1[0U] 
                                                      << 3U) 
                                                     | ((IData)(
                                                                ((((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_9__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                   << 1U) 
                                                                  | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_8__DOT__reg_0))) 
                                                                 >> 0x20U)) 
                                                        << 2U))));
    __Vtemp_hf5eb69f0__0[4U] = ((1U & ((__Vtemp_h29dd9bbf__1[0U] 
                                        >> 0x1dU) | 
                                       ((IData)(((((QData)((IData)(
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_9__DOT__reg_0) 
                                                                    << 0x1fU))) 
                                                   << 1U) 
                                                  | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_8__DOT__reg_0))) 
                                                 >> 0x20U)) 
                                        >> 0x1eU))) 
                                | ((2U & ((__Vtemp_h29dd9bbf__1[0U] 
                                           >> 0x1dU) 
                                          | ((IData)(
                                                     ((((QData)((IData)(
                                                                        ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_9__DOT__reg_0) 
                                                                         << 0x1fU))) 
                                                        << 1U) 
                                                       | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_8__DOT__reg_0))) 
                                                      >> 0x20U)) 
                                             >> 0x1eU))) 
                                   | ((4U & (__Vtemp_h29dd9bbf__1[0U] 
                                             >> 0x1dU)) 
                                      | (__Vtemp_h29dd9bbf__1[1U] 
                                         << 3U))));
    __Vtemp_h00ad6230__0[3U] = (((1U & ((IData)((((QData)((IData)(
                                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_7__DOT__reg_0) 
                                                                   << 0x1fU))) 
                                                  << 1U) 
                                                 | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_6__DOT__reg_0)))) 
                                        >> 0x1eU)) 
                                 | ((IData)(((((QData)((IData)(
                                                               ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_5__DOT__reg_0) 
                                                                << 0x1fU))) 
                                               << 1U) 
                                              | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_4__DOT__reg_0))) 
                                             >> 0x20U)) 
                                    >> 0x1fU)) | ((2U 
                                                   & ((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_7__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                << 1U) 
                                                               | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_6__DOT__reg_0)))) 
                                                      >> 0x1eU)) 
                                                  | (((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_9__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                << 1U) 
                                                               | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_8__DOT__reg_0)))) 
                                                      << 3U) 
                                                     | ((IData)(
                                                                ((((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_7__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                   << 1U) 
                                                                  | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_6__DOT__reg_0))) 
                                                                 >> 0x20U)) 
                                                        << 2U))));
    __Vtemp_h00ad6230__0[7U] = ((1U & (__Vtemp_h29dd9bbf__1[2U] 
                                       >> 0x1cU)) | 
                                ((2U & (__Vtemp_h29dd9bbf__1[2U] 
                                        >> 0x1cU)) 
                                 | ((4U & (__Vtemp_h29dd9bbf__1[2U] 
                                           >> 0x1cU)) 
                                    | ((8U & (__Vtemp_h29dd9bbf__1[2U] 
                                              >> 0x1cU)) 
                                       | (__Vtemp_h29dd9bbf__1[3U] 
                                          << 4U)))));
    __Vtemp_he55365d9__0[0U] = (IData)((((QData)((IData)(
                                                         ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_1__DOT__reg_0) 
                                                          << 0x1fU))) 
                                         << 1U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_0__DOT__reg_0))));
    __Vtemp_he55365d9__0[1U] = (((IData)((((QData)((IData)(
                                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_3__DOT__reg_0) 
                                                            << 0x1fU))) 
                                           << 1U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_2__DOT__reg_0)))) 
                                 << 1U) | (IData)((
                                                   (((QData)((IData)(
                                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_1__DOT__reg_0) 
                                                                      << 0x1fU))) 
                                                     << 1U) 
                                                    | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_0__DOT__reg_0))) 
                                                   >> 0x20U)));
    __Vtemp_he55365d9__0[2U] = (((IData)((((QData)((IData)(
                                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_3__DOT__reg_0) 
                                                            << 0x1fU))) 
                                           << 1U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_2__DOT__reg_0)))) 
                                 >> 0x1fU) | (((IData)(
                                                       (((QData)((IData)(
                                                                         ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_5__DOT__reg_0) 
                                                                          << 0x1fU))) 
                                                         << 1U) 
                                                        | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_4__DOT__reg_0)))) 
                                               << 2U) 
                                              | ((IData)(
                                                         ((((QData)((IData)(
                                                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_3__DOT__reg_0) 
                                                                             << 0x1fU))) 
                                                            << 1U) 
                                                           | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_2__DOT__reg_0))) 
                                                          >> 0x20U)) 
                                                 << 1U)));
    __Vtemp_he55365d9__0[3U] = (((1U & ((IData)((((QData)((IData)(
                                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_5__DOT__reg_0) 
                                                                   << 0x1fU))) 
                                                  << 1U) 
                                                 | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_4__DOT__reg_0)))) 
                                        >> 0x1eU)) 
                                 | ((IData)(((((QData)((IData)(
                                                               ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_3__DOT__reg_0) 
                                                                << 0x1fU))) 
                                               << 1U) 
                                              | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_2__DOT__reg_0))) 
                                             >> 0x20U)) 
                                    >> 0x1fU)) | ((2U 
                                                   & ((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_5__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                << 1U) 
                                                               | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_4__DOT__reg_0)))) 
                                                      >> 0x1eU)) 
                                                  | (((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_7__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                << 1U) 
                                                               | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_6__DOT__reg_0)))) 
                                                      << 3U) 
                                                     | ((IData)(
                                                                ((((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_5__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                   << 1U) 
                                                                  | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_4__DOT__reg_0))) 
                                                                 >> 0x20U)) 
                                                        << 2U))));
    __Vtemp_he55365d9__0[4U] = ((1U & (((IData)((((QData)((IData)(
                                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_7__DOT__reg_0) 
                                                                   << 0x1fU))) 
                                                  << 1U) 
                                                 | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_6__DOT__reg_0)))) 
                                        >> 0x1dU) | 
                                       ((IData)(((((QData)((IData)(
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_5__DOT__reg_0) 
                                                                    << 0x1fU))) 
                                                   << 1U) 
                                                  | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_4__DOT__reg_0))) 
                                                 >> 0x20U)) 
                                        >> 0x1eU))) 
                                | (__Vtemp_h00ad6230__0[3U] 
                                   << 1U));
    __Vtemp_he55365d9__0[5U] = ((__Vtemp_h00ad6230__0[3U] 
                                 >> 0x1fU) | ((2U & 
                                               ((0xeU 
                                                 & ((IData)(
                                                            (((QData)((IData)(
                                                                              ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_9__DOT__reg_0) 
                                                                               << 0x1fU))) 
                                                              << 1U) 
                                                             | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_8__DOT__reg_0)))) 
                                                    >> 0x1cU)) 
                                                | (6U 
                                                   & ((IData)(
                                                              ((((QData)((IData)(
                                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_7__DOT__reg_0) 
                                                                                << 0x1fU))) 
                                                                 << 1U) 
                                                                | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_6__DOT__reg_0))) 
                                                               >> 0x20U)) 
                                                      >> 0x1dU)))) 
                                              | (__Vtemp_hf5eb69f0__0[3U] 
                                                 << 2U)));
    __Vtemp_he55365d9__0[6U] = ((1U & (__Vtemp_hf5eb69f0__0[3U] 
                                       >> 0x1eU)) | 
                                ((2U & (__Vtemp_hf5eb69f0__0[3U] 
                                        >> 0x1eU)) 
                                 | (__Vtemp_hf5eb69f0__0[4U] 
                                    << 2U)));
    __Vtemp_he55365d9__0[7U] = ((1U & (__Vtemp_hf5eb69f0__0[4U] 
                                       >> 0x1eU)) | 
                                ((2U & (__Vtemp_hf5eb69f0__0[4U] 
                                        >> 0x1eU)) 
                                 | ((4U & (__Vtemp_h29dd9bbf__1[1U] 
                                           >> 0x1bU)) 
                                    | ((8U & (__Vtemp_h29dd9bbf__1[1U] 
                                              >> 0x1bU)) 
                                       | ((0x10U & 
                                           (__Vtemp_h29dd9bbf__1[1U] 
                                            >> 0x1bU)) 
                                          | (__Vtemp_h29dd9bbf__1[2U] 
                                             << 5U))))));
    __Vtemp_he55365d9__0[8U] = ((1U & (__Vtemp_h29dd9bbf__1[2U] 
                                       >> 0x1bU)) | 
                                (__Vtemp_h00ad6230__0[7U] 
                                 << 1U));
    VL_EXTEND_WQ(65,33, __Vtemp_h9c1a87ea__0, ((1U 
                                                & ((0xc0U 
                                                    | (0x3fU 
                                                       & (- (IData)(
                                                                    (0U 
                                                                     == 
                                                                     (0x3fU 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                         >> 0x19U))))))) 
                                                   >> 
                                                   (7U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 0x16U))))
                                                ? (
                                                   (0x107U 
                                                    >= 
                                                    (0x1ffU 
                                                     & ((IData)(0x21U) 
                                                        * 
                                                        (7U 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0x16U)))))
                                                    ? 
                                                   (0x1ffffffffULL 
                                                    & (((QData)((IData)(
                                                                        __Vtemp_he55365d9__0[
                                                                        (((IData)(0x20U) 
                                                                          + 
                                                                          (0x1ffU 
                                                                           & ((IData)(0x21U) 
                                                                              * 
                                                                              (7U 
                                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 0x16U))))) 
                                                                         >> 5U)])) 
                                                        << 
                                                        ((0U 
                                                          == 
                                                          (0x1fU 
                                                           & ((IData)(0x21U) 
                                                              * 
                                                              (7U 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0x16U)))))
                                                          ? 0x20U
                                                          : 
                                                         ((IData)(0x40U) 
                                                          - 
                                                          (0x1fU 
                                                           & ((IData)(0x21U) 
                                                              * 
                                                              (7U 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0x16U))))))) 
                                                       | (((0U 
                                                            == 
                                                            (0x1fU 
                                                             & ((IData)(0x21U) 
                                                                * 
                                                                (7U 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                    >> 0x16U)))))
                                                            ? 0ULL
                                                            : 
                                                           ((QData)((IData)(
                                                                            __Vtemp_he55365d9__0[
                                                                            (((IData)(0x1fU) 
                                                                              + 
                                                                              (0x1ffU 
                                                                               & ((IData)(0x21U) 
                                                                                * 
                                                                                (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 0x16U))))) 
                                                                             >> 5U)])) 
                                                            << 
                                                            ((IData)(0x20U) 
                                                             - 
                                                             (0x1fU 
                                                              & ((IData)(0x21U) 
                                                                 * 
                                                                 (7U 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                     >> 0x16U))))))) 
                                                          | ((QData)((IData)(
                                                                             __Vtemp_he55365d9__0[
                                                                             (0xfU 
                                                                              & (((IData)(0x21U) 
                                                                                * 
                                                                                (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 0x16U))) 
                                                                                >> 5U))])) 
                                                             >> 
                                                             (0x1fU 
                                                              & ((IData)(0x21U) 
                                                                 * 
                                                                 (7U 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                     >> 0x16U))))))))
                                                    : 0ULL)
                                                : 0ULL));
    __Vtemp_h5c7c01b8__0[0U] = ((__Vtemp_h9c1a87ea__0[0U] 
                                 << 0x14U) | ((0x3ff80U 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 1U)) 
                                              | ((0x60U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 1U)) 
                                                 | (4U 
                                                    == 
                                                    (7U 
                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])))));
    __Vtemp_h5c7c01b8__0[1U] = ((__Vtemp_h9c1a87ea__0[0U] 
                                 >> 0xcU) | (__Vtemp_h9c1a87ea__0[1U] 
                                             << 0x14U));
    __Vtemp_h5c7c01b8__0[2U] = ((__Vtemp_h9c1a87ea__0[1U] 
                                 >> 0xcU) | (__Vtemp_h9c1a87ea__0[2U] 
                                             << 0x14U));
    bufp->chgWData(oldp+1355,(__Vtemp_h5c7c01b8__0),85);
    VL_EXTEND_WI(66,1, __Vtemp_h8b172a8e__1, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_4__DOT__reg_0));
    __Vtemp_h35dfed16__0[0U] = (IData)((((QData)((IData)(
                                                         ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_1__DOT__reg_0) 
                                                          << 0x1fU))) 
                                         << 1U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_0__DOT__reg_0))));
    __Vtemp_h35dfed16__0[1U] = (((IData)((((QData)((IData)(
                                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_3__DOT__reg_0) 
                                                            << 0x1fU))) 
                                           << 1U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_2__DOT__reg_0)))) 
                                 << 1U) | (IData)((
                                                   (((QData)((IData)(
                                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_1__DOT__reg_0) 
                                                                      << 0x1fU))) 
                                                     << 1U) 
                                                    | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_0__DOT__reg_0))) 
                                                   >> 0x20U)));
    __Vtemp_h35dfed16__0[2U] = (((IData)((((QData)((IData)(
                                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_3__DOT__reg_0) 
                                                            << 0x1fU))) 
                                           << 1U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_2__DOT__reg_0)))) 
                                 >> 0x1fU) | ((__Vtemp_h8b172a8e__1[0U] 
                                               << 2U) 
                                              | ((IData)(
                                                         ((((QData)((IData)(
                                                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_3__DOT__reg_0) 
                                                                             << 0x1fU))) 
                                                            << 1U) 
                                                           | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_2__DOT__reg_0))) 
                                                          >> 0x20U)) 
                                                 << 1U)));
    __Vtemp_h35dfed16__0[3U] = (((1U & (__Vtemp_h8b172a8e__1[0U] 
                                        >> 0x1eU)) 
                                 | ((IData)(((((QData)((IData)(
                                                               ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_3__DOT__reg_0) 
                                                                << 0x1fU))) 
                                               << 1U) 
                                              | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_2__DOT__reg_0))) 
                                             >> 0x20U)) 
                                    >> 0x1fU)) | ((2U 
                                                   & (__Vtemp_h8b172a8e__1[0U] 
                                                      >> 0x1eU)) 
                                                  | (__Vtemp_h8b172a8e__1[1U] 
                                                     << 2U)));
    __Vtemp_h35dfed16__0[4U] = ((1U & (__Vtemp_h8b172a8e__1[1U] 
                                       >> 0x1eU)) | 
                                ((2U & (__Vtemp_h8b172a8e__1[1U] 
                                        >> 0x1eU)) 
                                 | (__Vtemp_h8b172a8e__1[2U] 
                                    << 2U)));
    VL_EXTEND_WQ(65,33, __Vtemp_hd3f6aa17__0, ((1U 
                                                & ((8U 
                                                    | (7U 
                                                       & (- (IData)(
                                                                    (0U 
                                                                     == 
                                                                     (0x7fU 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                         >> 0x18U))))))) 
                                                   >> 
                                                   (3U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 0x16U))))
                                                ? (
                                                   (0x83U 
                                                    >= 
                                                    (0xffU 
                                                     & ((IData)(0x21U) 
                                                        * 
                                                        (3U 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0x16U)))))
                                                    ? 
                                                   (0x1ffffffffULL 
                                                    & (((QData)((IData)(
                                                                        __Vtemp_h35dfed16__0[
                                                                        (((IData)(0x20U) 
                                                                          + 
                                                                          (0xffU 
                                                                           & ((IData)(0x21U) 
                                                                              * 
                                                                              (3U 
                                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 0x16U))))) 
                                                                         >> 5U)])) 
                                                        << 
                                                        ((0U 
                                                          == 
                                                          (0x1fU 
                                                           & ((IData)(0x21U) 
                                                              * 
                                                              (3U 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0x16U)))))
                                                          ? 0x20U
                                                          : 
                                                         ((IData)(0x40U) 
                                                          - 
                                                          (0x1fU 
                                                           & ((IData)(0x21U) 
                                                              * 
                                                              (3U 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0x16U))))))) 
                                                       | (((0U 
                                                            == 
                                                            (0x1fU 
                                                             & ((IData)(0x21U) 
                                                                * 
                                                                (3U 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                    >> 0x16U)))))
                                                            ? 0ULL
                                                            : 
                                                           ((QData)((IData)(
                                                                            __Vtemp_h35dfed16__0[
                                                                            (((IData)(0x1fU) 
                                                                              + 
                                                                              (0xffU 
                                                                               & ((IData)(0x21U) 
                                                                                * 
                                                                                (3U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 0x16U))))) 
                                                                             >> 5U)])) 
                                                            << 
                                                            ((IData)(0x20U) 
                                                             - 
                                                             (0x1fU 
                                                              & ((IData)(0x21U) 
                                                                 * 
                                                                 (3U 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                     >> 0x16U))))))) 
                                                          | ((QData)((IData)(
                                                                             __Vtemp_h35dfed16__0[
                                                                             (7U 
                                                                              & (((IData)(0x21U) 
                                                                                * 
                                                                                (3U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 0x16U))) 
                                                                                >> 5U))])) 
                                                             >> 
                                                             (0x1fU 
                                                              & ((IData)(0x21U) 
                                                                 * 
                                                                 (3U 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                     >> 0x16U))))))))
                                                    : 0ULL)
                                                : 0ULL));
    __Vtemp_hacea9cd5__0[0U] = ((__Vtemp_hd3f6aa17__0[0U] 
                                 << 0x14U) | ((0x3ff80U 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 1U)) 
                                              | ((0x60U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 1U)) 
                                                 | (4U 
                                                    == 
                                                    (7U 
                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])))));
    __Vtemp_hacea9cd5__0[1U] = ((__Vtemp_hd3f6aa17__0[0U] 
                                 >> 0xcU) | (__Vtemp_hd3f6aa17__0[1U] 
                                             << 0x14U));
    __Vtemp_hacea9cd5__0[2U] = ((__Vtemp_hd3f6aa17__0[1U] 
                                 >> 0xcU) | (__Vtemp_hd3f6aa17__0[2U] 
                                             << 0x14U));
    bufp->chgWData(oldp+1358,(__Vtemp_hacea9cd5__0),85);
    bufp->chgCData(oldp+1361,(((0x17U >= (0x1fU & ((IData)(3U) 
                                                   * 
                                                   ((7U 
                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__ridx)) 
                                                    ^ 
                                                    (4U 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__ridx) 
                                                        >> 1U))))))
                                ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_7_sink) 
                                           << 0x15U) 
                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_6_sink) 
                                              << 0x12U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_5_sink) 
                                                 << 0xfU) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_4_sink) 
                                                    << 0xcU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_3_sink) 
                                                       << 9U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_2_sink) 
                                                          << 6U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_1_sink) 
                                                             << 3U) 
                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_0_sink)))))))) 
                                         >> (0x1fU 
                                             & ((IData)(3U) 
                                                * (
                                                   (7U 
                                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__ridx)) 
                                                   ^ 
                                                   (4U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__ridx) 
                                                       >> 1U)))))))
                                : 0U)),3);
    bufp->chgCData(oldp+1362,(((0x17U >= (0x1fU & ((IData)(3U) 
                                                   * 
                                                   ((7U 
                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__ridx)) 
                                                    ^ 
                                                    (4U 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__ridx) 
                                                        >> 1U))))))
                                ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__mem_7_sink) 
                                           << 0x15U) 
                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__mem_6_sink) 
                                              << 0x12U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__mem_5_sink) 
                                                 << 0xfU) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__mem_4_sink) 
                                                    << 0xcU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__mem_3_sink) 
                                                       << 9U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__mem_2_sink) 
                                                          << 6U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__mem_1_sink) 
                                                             << 3U) 
                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__mem_0_sink)))))))) 
                                         >> (0x1fU 
                                             & ((IData)(3U) 
                                                * (
                                                   (7U 
                                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__ridx)) 
                                                   ^ 
                                                   (4U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__ridx) 
                                                       >> 1U)))))))
                                : 0U)),3);
    bufp->chgCData(oldp+1363,(((0x17U >= (0x1fU & ((IData)(3U) 
                                                   * 
                                                   ((7U 
                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__ridx)) 
                                                    ^ 
                                                    (4U 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__ridx) 
                                                        >> 1U))))))
                                ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__mem_7_sink) 
                                           << 0x15U) 
                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__mem_6_sink) 
                                              << 0x12U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__mem_5_sink) 
                                                 << 0xfU) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__mem_4_sink) 
                                                    << 0xcU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__mem_3_sink) 
                                                       << 9U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__mem_2_sink) 
                                                          << 6U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__mem_1_sink) 
                                                             << 3U) 
                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__mem_0_sink)))))))) 
                                         >> (0x1fU 
                                             & ((IData)(3U) 
                                                * (
                                                   (7U 
                                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__ridx)) 
                                                   ^ 
                                                   (4U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__ridx) 
                                                       >> 1U)))))))
                                : 0U)),3);
    bufp->chgCData(oldp+1364,(((0x17U >= (0x1fU & ((IData)(3U) 
                                                   * 
                                                   ((7U 
                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__ridx)) 
                                                    ^ 
                                                    (4U 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__ridx) 
                                                        >> 1U))))))
                                ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__mem_7_sink) 
                                           << 0x15U) 
                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__mem_6_sink) 
                                              << 0x12U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__mem_5_sink) 
                                                 << 0xfU) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__mem_4_sink) 
                                                    << 0xcU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__mem_3_sink) 
                                                       << 9U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__mem_2_sink) 
                                                          << 6U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__mem_1_sink) 
                                                             << 3U) 
                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__mem_0_sink)))))))) 
                                         >> (0x1fU 
                                             & ((IData)(3U) 
                                                * (
                                                   (7U 
                                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__ridx)) 
                                                   ^ 
                                                   (4U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__ridx) 
                                                       >> 1U)))))))
                                : 0U)),3);
    bufp->chgBit(oldp+1365,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset)) 
                                   & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___deq_valids_T_7))))));
    bufp->chgBit(oldp+1366,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset)) 
                                   & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___deq_valids_T_7) 
                                         >> 1U))))));
    bufp->chgBit(oldp+1367,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset)) 
                                   & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___deq_valids_T_7) 
                                         >> 2U))))));
    bufp->chgBit(oldp+1368,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset) 
                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_clear))));
    bufp->chgBit(oldp+1369,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT___same_cycle_resp_T_3) 
                              & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode)))) 
                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source) 
                                == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                          >> 5U))))));
    bufp->chgBit(oldp+1370,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__killm_common) 
                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div_io_kill_REG)) 
                             | ((((~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode)) 
                                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)))) 
                                  & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killm))) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_div)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___icsl_io_if_overtaking_next_cycle)))));
    bufp->chgBit(oldp+1371,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)) 
                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output)) 
                             & (((3U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__inflight)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__empty)) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcIF__DOT____Vcellinp__replayq__io_nack_valid))))));
    bufp->chgIData(oldp+1372,(((((0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1))
                                  ? 3U : (((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1)) 
                                           | (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1)))
                                           ? 2U : (1U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1)))) 
                                << 0x15U) | (0x1fffffU 
                                             & (IData)(
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr 
                                                        >> 0xbU))))),23);
    bufp->chgSData(oldp+1373,(((0x7c0U & (((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr 
                                                    >> 6U)) 
                                           << 6U) | 
                                          (0xffffffc0U 
                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_15) 
                                              << 3U)))) 
                               | (0x38U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_15) 
                                           << 3U)))),11);
    bufp->chgBit(oldp+1374,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_13_valid) 
                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                 >> 1U) | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))));
    bufp->chgBit(oldp+1375,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_1_reset) 
                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb))));
    bufp->chgBit(oldp+1376,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_1_MPORT_2_en)) 
                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid)) 
                             & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___io_cpu_npc_output 
                                        >> 2U)))));
    bufp->chgBit(oldp+1377,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_0_MPORT_1_en)) 
                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid)) 
                             & (~ (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___io_cpu_npc_output 
                                           >> 2U))))));
    bufp->chgCData(oldp+1378,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_nack_output) 
                                & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT__s2_id)))
                                ? 1U : (7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_valid)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_11)
                                               : ((0x17U 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(3U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state))))
                                                   ? 
                                                  ((0x100U 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state) 
                                                        << 0x12U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state) 
                                                           << 0xfU) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_ae_ld_output)
                                                                ? 0U
                                                                : 5U) 
                                                              << 0xcU) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state) 
                                                                 << 9U) 
                                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pte_cache_hit)
                                                                      ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state)
                                                                      : 
                                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_req_ready_output)
                                                                       ? 2U
                                                                       : 1U)) 
                                                                    << 3U) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___T_141)
                                                                       ? 
                                                                      (1U 
                                                                       & ((1U 
                                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_state)) 
                                                                          | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__tlb__io_kill))))
                                                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state)))))))) 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(3U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state))))
                                                   : 0U))))),3);
    bufp->chgBit(oldp+1379,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT___same_cycle_resp_T_3) 
                              & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode)))) 
                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source) 
                                == (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                          >> 5U))))));
    bufp->chgBit(oldp+1380,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT___same_cycle_resp_T_3) 
                              & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode)))) 
                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source) 
                                == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                          >> 5U))))));
    bufp->chgBit(oldp+1381,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__killm_common) 
                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__div_io_kill_REG)) 
                             | ((((~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode)) 
                                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)))) 
                                  & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killm))) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_div)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT___icsl_io_if_overtaking_next_cycle)))));
    bufp->chgBit(oldp+1382,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)) 
                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output)) 
                             & (((3U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__inflight)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__empty)) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcIF__DOT____Vcellinp__replayq__io_nack_valid))))));
    bufp->chgIData(oldp+1383,(((((0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1))
                                  ? 3U : (((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1)) 
                                           | (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1)))
                                           ? 2U : (1U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1)))) 
                                << 0x15U) | (0x1fffffU 
                                             & (IData)(
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr 
                                                        >> 0xbU))))),23);
    bufp->chgSData(oldp+1384,(((0x7c0U & (((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr 
                                                    >> 6U)) 
                                           << 6U) | 
                                          (0xffffffc0U 
                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_15) 
                                              << 3U)))) 
                               | (0x38U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_15) 
                                           << 3U)))),11);
    bufp->chgBit(oldp+1385,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_13_valid) 
                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                 >> 1U) | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))));
    bufp->chgBit(oldp+1386,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_2_reset) 
                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb))));
    bufp->chgBit(oldp+1387,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_1_MPORT_2_en)) 
                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid)) 
                             & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT___io_cpu_npc_output 
                                        >> 2U)))));
    bufp->chgBit(oldp+1388,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_0_MPORT_1_en)) 
                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid)) 
                             & (~ (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT___io_cpu_npc_output 
                                           >> 2U))))));
    bufp->chgCData(oldp+1389,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_nack_output) 
                                & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT__s2_id)))
                                ? 1U : (7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_valid)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_11)
                                               : ((0x17U 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(3U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state))))
                                                   ? 
                                                  ((0x100U 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state) 
                                                        << 0x12U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state) 
                                                           << 0xfU) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_ae_ld_output)
                                                                ? 0U
                                                                : 5U) 
                                                              << 0xcU) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state) 
                                                                 << 9U) 
                                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pte_cache_hit)
                                                                      ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state)
                                                                      : 
                                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_req_ready_output)
                                                                       ? 2U
                                                                       : 1U)) 
                                                                    << 3U) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___T_141)
                                                                       ? 
                                                                      (1U 
                                                                       & ((1U 
                                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_state)) 
                                                                          | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__tlb__io_kill))))
                                                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state)))))))) 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(3U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state))))
                                                   : 0U))))),3);
    bufp->chgBit(oldp+1390,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT___same_cycle_resp_T_3) 
                              & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode)))) 
                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source) 
                                == (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                          >> 5U))))));
    bufp->chgBit(oldp+1391,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__monitor__DOT___same_cycle_resp_T_3) 
                              & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode)))) 
                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source) 
                                == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                          >> 5U))))));
    bufp->chgBit(oldp+1392,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__killm_common) 
                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div_io_kill_REG)) 
                             | ((((~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode)) 
                                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)))) 
                                  & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killm))) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_div)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___icsl_io_if_overtaking_next_cycle)))));
    bufp->chgBit(oldp+1393,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)) 
                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output)) 
                             & (((3U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__inflight)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__empty)) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT____Vcellinp__replayq__io_nack_valid))))));
    bufp->chgIData(oldp+1394,(((((0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1))
                                  ? 3U : (((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1)) 
                                           | (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1)))
                                           ? 2U : (1U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1)))) 
                                << 0x15U) | (0x1fffffU 
                                             & (IData)(
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr 
                                                        >> 0xbU))))),23);
    bufp->chgSData(oldp+1395,(((0x7c0U & (((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr 
                                                    >> 6U)) 
                                           << 6U) | 
                                          (0xffffffc0U 
                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_15) 
                                              << 3U)))) 
                               | (0x38U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_15) 
                                           << 3U)))),11);
    bufp->chgBit(oldp+1396,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_13_valid) 
                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                 >> 1U) | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))));
    bufp->chgBit(oldp+1397,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_3_reset) 
                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb))));
    bufp->chgBit(oldp+1398,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_1_MPORT_2_en)) 
                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid)) 
                             & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___io_cpu_npc_output 
                                        >> 2U)))));
    bufp->chgBit(oldp+1399,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_0_MPORT_1_en)) 
                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid)) 
                             & (~ (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___io_cpu_npc_output 
                                           >> 2U))))));
    bufp->chgCData(oldp+1400,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_nack_output) 
                                & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT__s2_id)))
                                ? 1U : (7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_valid)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_11)
                                               : ((0x17U 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(3U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state))))
                                                   ? 
                                                  ((0x100U 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state) 
                                                        << 0x12U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state) 
                                                           << 0xfU) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_ae_ld_output)
                                                                ? 0U
                                                                : 5U) 
                                                              << 0xcU) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state) 
                                                                 << 9U) 
                                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pte_cache_hit)
                                                                      ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state)
                                                                      : 
                                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_req_ready_output)
                                                                       ? 2U
                                                                       : 1U)) 
                                                                    << 3U) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___T_141)
                                                                       ? 
                                                                      (1U 
                                                                       & ((1U 
                                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_state)) 
                                                                          | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__tlb__io_kill))))
                                                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state)))))))) 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(3U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state))))
                                                   : 0U))))),3);
    bufp->chgBit(oldp+1401,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT___same_cycle_resp_T_3) 
                              & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode)))) 
                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source) 
                                == (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                          >> 5U))))));
    bufp->chgBit(oldp+1402,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT___same_cycle_resp_T_3) 
                              & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode)))) 
                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source) 
                                == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                          >> 5U))))));
    bufp->chgBit(oldp+1403,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__killm_common) 
                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div_io_kill_REG)) 
                             | ((((~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode)) 
                                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)))) 
                                  & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killm))) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_div)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___icsl_io_if_overtaking_next_cycle)))));
    bufp->chgBit(oldp+1404,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)) 
                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output)) 
                             & (((3U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__inflight)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__empty)) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT____Vcellinp__replayq__io_nack_valid))))));
    bufp->chgIData(oldp+1405,(((((0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1))
                                  ? 3U : (((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1)) 
                                           | (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1)))
                                           ? 2U : (1U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1)))) 
                                << 0x15U) | (0x1fffffU 
                                             & (IData)(
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr 
                                                        >> 0xbU))))),23);
    bufp->chgSData(oldp+1406,(((0x7c0U & (((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr 
                                                    >> 6U)) 
                                           << 6U) | 
                                          (0xffffffc0U 
                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_15) 
                                              << 3U)))) 
                               | (0x38U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_15) 
                                           << 3U)))),11);
    bufp->chgBit(oldp+1407,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_13_valid) 
                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                 >> 1U) | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))));
    bufp->chgBit(oldp+1408,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_4_reset) 
                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb))));
    bufp->chgBit(oldp+1409,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_1_MPORT_2_en)) 
                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid)) 
                             & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___io_cpu_npc_output 
                                        >> 2U)))));
    bufp->chgBit(oldp+1410,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__data_arrays_0_MPORT_1_en)) 
                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid)) 
                             & (~ (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___io_cpu_npc_output 
                                           >> 2U))))));
    bufp->chgCData(oldp+1411,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_nack_output) 
                                & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT__s2_id)))
                                ? 1U : (7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_valid)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_11)
                                               : ((0x17U 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(3U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state))))
                                                   ? 
                                                  ((0x100U 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state) 
                                                        << 0x12U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state) 
                                                           << 0xfU) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_ae_ld_output)
                                                                ? 0U
                                                                : 5U) 
                                                              << 0xcU) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state) 
                                                                 << 9U) 
                                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pte_cache_hit)
                                                                      ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state)
                                                                      : 
                                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_req_ready_output)
                                                                       ? 2U
                                                                       : 1U)) 
                                                                    << 3U) 
                                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___T_141)
                                                                       ? 
                                                                      (1U 
                                                                       & ((1U 
                                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_state)) 
                                                                          | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__tlb__io_kill))))
                                                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state)))))))) 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(3U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state))))
                                                   : 0U))))),3);
    bufp->chgBit(oldp+1412,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT___same_cycle_resp_T_3) 
                              & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode)))) 
                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source) 
                                == (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                          >> 5U))))));
    bufp->chgBit(oldp+1413,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT___system_debug_systemjtag_reset_catcher_io_sync_reset)))));
    bufp->chgBit(oldp+1414,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__debug_reset)))));
    bufp->chgBit(oldp+1415,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset));
    __Vtemp_h3459872b__0[0U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_haltreq) 
                                 << 0x1fU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_hasel) 
                                               << 0x1aU) 
                                              | ((0x70000U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_hartsello) 
                                                     << 0x10U)) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_ndmreset) 
                                                     << 1U) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_dmactive) 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmactiveAck_dmactiveAckSync__DOT__output_chain__DOT__sync_0))))));
    __Vtemp_h3459872b__0[1U] = 0x112380U;
    __Vtemp_h3459872b__0[2U] = (IData)((QData)((IData)(
                                                       (0x1fU 
                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__HAMASKReg_maskdata))));
    __Vtemp_h3459872b__0[3U] = (IData)(((QData)((IData)(
                                                        (0x1fU 
                                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__HAMASKReg_maskdata))) 
                                        >> 0x20U));
    bufp->chgIData(oldp+1416,(((1U & ((8U | ((4U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address)) 
                                             | ((2U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address) 
                                                      >> 2U)) 
                                                    << 1U)) 
                                                | (1U 
                                                   & (~ 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address) 
                                                       >> 2U)))))) 
                                      >> (3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address) 
                                                >> 3U))))
                                ? __Vtemp_h3459872b__0[
                               (3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT___dmi2tl_auto_out_a_bits_address) 
                                      >> 3U))] : 0U)),32);
    bufp->chgBit(oldp+1417,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__muxStateEarly_0) 
                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)
                                 ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_2_bits_denied)
                                 : (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                            >> 0x21U))))));
    bufp->chgBit(oldp+1418,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__muxStateEarly_0) 
                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)
                                 ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_2_bits_denied) 
                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_1_bits_opcode))
                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg)))));
    bufp->chgCData(oldp+1419,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)
                                ? 0U : (3U & (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                      >> 0x26U))))),2);
    bufp->chgCData(oldp+1420,((3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)
                                      ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_2_bits_denied) 
                                         << 1U) : (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                           >> 0x24U))))),2);
    bufp->chgBit(oldp+1421,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)
                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_2_bits_denied)
                                    : (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                               >> 0x21U))))));
    bufp->chgIData(oldp+1422,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)
                                ? 0U : (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                >> 1U)))),32);
    bufp->chgBit(oldp+1423,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)
                                    ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_2_bits_denied) 
                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_1_bits_opcode))
                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg)))));
    bufp->chgBit(oldp+1424,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_2_bits_denied) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_1_bits_opcode))));
    bufp->chgCData(oldp+1425,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__muxStateEarly_0)
                                ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)
                                    ? 0U : (3U & (IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                          >> 0x26U))))
                                : 0U)),2);
    bufp->chgCData(oldp+1426,((3U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__muxStateEarly_0)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__error__DOT__out_2_bits_denied) 
                                              << 1U)
                                           : (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                                      >> 0x24U)))
                                       : 0U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiXbar__DOT__muxStateEarly_1) 
                                                << 1U)))),2);
    bufp->chgBit(oldp+1427,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__restore));
    bufp->chgCData(oldp+1428,((((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__full) 
                                << 3U) | (7U & ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__enq_ptr_value) 
                                                - (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__deq_ptr_value))))),4);
    bufp->chgBit(oldp+1429,(((~ (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__full)) 
                             & (7U > (((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__full) 
                                       << 3U) | (7U 
                                                 & ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__enq_ptr_value) 
                                                    - (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__deq_ptr_value))))))));
    bufp->chgBit(oldp+1430,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__restore));
}
