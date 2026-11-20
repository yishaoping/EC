// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__49(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__49\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<5>/*159:0*/ __Vtemp_8;
    VlWide<5>/*159:0*/ __Vtemp_9;
    VlWide<5>/*159:0*/ __Vtemp_10;
    VlWide<5>/*159:0*/ __Vtemp_11;
    VlWide<5>/*159:0*/ __Vtemp_12;
    IData/*31:0*/ __Vdeeptemp_h8317d69d__0;
    IData/*31:0*/ __Vdeeptemp_h3dcf6d7f__0;
    IData/*31:0*/ __Vdeeptemp_h81314341__0;
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT___buckets_requestCycleSum_T_1 
        = (vlSelfRef.tb__DOT__dutReference__DOT___GEN_1279 
           + vlSelfRef.tb__DOT__io_currentCycle);
    vlSelfRef.tb__DOT__dutReference__DOT___requestCycleSum_T_2 
        = (vlSelfRef.tb__DOT__dutReference__DOT__requestCycleSum 
           + (((QData)((IData)(vlSelfRef.tb__DOT__dutReference__DOT__requestThisCycleWide[1U])) 
               << 0x20U) | (QData)((IData)(vlSelfRef.tb__DOT__dutReference__DOT__requestThisCycleWide[0U]))));
    __Vtemp_2[0U] = vlSelfRef.tb__DOT__dutReference__DOT___resolvedBucketsWide_T_510[0U];
    __Vtemp_2[1U] = vlSelfRef.tb__DOT__dutReference__DOT___resolvedBucketsWide_T_510[1U];
    __Vtemp_2[2U] = vlSelfRef.tb__DOT__dutReference__DOT___resolvedBucketsWide_T_510[2U];
    __Vtemp_5[0U] = ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventImmediate)
                      ? 1U : 0U);
    __Vtemp_5[1U] = 0U;
    __Vtemp_5[2U] = 0U;
    VL_ADD_W(3, __Vtemp_6, __Vtemp_2, __Vtemp_5);
    vlSelfRef.tb__DOT__dutReference__DOT__resolvedThisCycleWide[0U] 
        = __Vtemp_6[0U];
    vlSelfRef.tb__DOT__dutReference__DOT__resolvedThisCycleWide[1U] 
        = __Vtemp_6[1U];
    vlSelfRef.tb__DOT__dutReference__DOT__resolvedThisCycleWide[2U] 
        = (0x1ffU & __Vtemp_6[2U]);
    __Vtemp_8[0U] = (IData)(vlSelfRef.tb__DOT__io_currentCycle);
    __Vtemp_8[1U] = (IData)((vlSelfRef.tb__DOT__io_currentCycle 
                             >> 0x20U));
    __Vtemp_8[2U] = 0U;
    __Vtemp_8[3U] = 0U;
    __Vtemp_8[4U] = 0U;
    __Vtemp_9[0U] = vlSelfRef.tb__DOT__dutReference__DOT___resolvedBucketsWide_T_510[0U];
    __Vtemp_9[1U] = vlSelfRef.tb__DOT__dutReference__DOT___resolvedBucketsWide_T_510[1U];
    __Vtemp_9[2U] = vlSelfRef.tb__DOT__dutReference__DOT___resolvedBucketsWide_T_510[2U];
    __Vtemp_9[3U] = 0U;
    __Vtemp_9[4U] = 0U;
    VL_MUL_W(5, __Vtemp_10, __Vtemp_8, __Vtemp_9);
    __Vtemp_11[0U] = (IData)(vlSelfRef.tb__DOT__dutReference__DOT___requestThisCycleWide_T);
    __Vtemp_11[1U] = (IData)((vlSelfRef.tb__DOT__dutReference__DOT___requestThisCycleWide_T 
                              >> 0x20U));
    __Vtemp_11[2U] = 0U;
    __Vtemp_11[3U] = 0U;
    __Vtemp_11[4U] = 0U;
    VL_ADD_W(5, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[2U] 
        = __Vtemp_12[2U];
    vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[3U] 
        = __Vtemp_12[3U];
    vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[4U] 
        = (0x1ffU & __Vtemp_12[4U]);
    vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1 
        = (1U & ((~ (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_255)) 
                 | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_511)));
    vlSelfRef.tb__DOT__dutReference__DOT___resolved_T_2 
        = (vlSelfRef.tb__DOT__dutReference__DOT__resolved 
           + (((QData)((IData)(vlSelfRef.tb__DOT__dutReference__DOT__resolvedThisCycleWide[1U])) 
               << 0x20U) | (QData)((IData)(vlSelfRef.tb__DOT__dutReference__DOT__resolvedThisCycleWide[0U]))));
    vlSelfRef.tb__DOT__dutReference__DOT___safeCycleSum_T_2 
        = (vlSelfRef.tb__DOT__dutReference__DOT__safeCycleSum 
           + (((QData)((IData)(vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[1U])) 
               << 0x20U) | (QData)((IData)(vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[0U]))));
    __Vdeeptemp_h8317d69d__0 = ((0x76U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_118
                                 : ((0x75U == (0xffU 
                                               & vlSelfRef.tb__DOT__io_event_bits))
                                     ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_117
                                     : ((0x74U == (0xffU 
                                                   & vlSelfRef.tb__DOT__io_event_bits))
                                         ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_116
                                         : ((0x73U 
                                             == (0xffU 
                                                 & vlSelfRef.tb__DOT__io_event_bits))
                                             ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_115
                                             : ((0x72U 
                                                 == 
                                                 (0xffU 
                                                  & vlSelfRef.tb__DOT__io_event_bits))
                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_114
                                                 : 
                                                ((0x71U 
                                                  == 
                                                  (0xffU 
                                                   & vlSelfRef.tb__DOT__io_event_bits))
                                                  ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_113
                                                  : 
                                                 ((0x70U 
                                                   == 
                                                   (0xffU 
                                                    & vlSelfRef.tb__DOT__io_event_bits))
                                                   ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_112
                                                   : 
                                                  ((0x6fU 
                                                    == 
                                                    (0xffU 
                                                     & vlSelfRef.tb__DOT__io_event_bits))
                                                    ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_111
                                                    : 
                                                   ((0x6eU 
                                                     == 
                                                     (0xffU 
                                                      & vlSelfRef.tb__DOT__io_event_bits))
                                                     ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_110
                                                     : 
                                                    ((0x6dU 
                                                      == 
                                                      (0xffU 
                                                       & vlSelfRef.tb__DOT__io_event_bits))
                                                      ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_109
                                                      : 
                                                     ((0x6cU 
                                                       == 
                                                       (0xffU 
                                                        & vlSelfRef.tb__DOT__io_event_bits))
                                                       ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_108
                                                       : 
                                                      ((0x6bU 
                                                        == 
                                                        (0xffU 
                                                         & vlSelfRef.tb__DOT__io_event_bits))
                                                        ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_107
                                                        : 
                                                       ((0x6aU 
                                                         == 
                                                         (0xffU 
                                                          & vlSelfRef.tb__DOT__io_event_bits))
                                                         ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_106
                                                         : 
                                                        ((0x69U 
                                                          == 
                                                          (0xffU 
                                                           & vlSelfRef.tb__DOT__io_event_bits))
                                                          ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_105
                                                          : 
                                                         ((0x68U 
                                                           == 
                                                           (0xffU 
                                                            & vlSelfRef.tb__DOT__io_event_bits))
                                                           ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_104
                                                           : 
                                                          ((0x67U 
                                                            == 
                                                            (0xffU 
                                                             & vlSelfRef.tb__DOT__io_event_bits))
                                                            ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_103
                                                            : 
                                                           ((0x66U 
                                                             == 
                                                             (0xffU 
                                                              & vlSelfRef.tb__DOT__io_event_bits))
                                                             ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_102
                                                             : 
                                                            ((0x65U 
                                                              == 
                                                              (0xffU 
                                                               & vlSelfRef.tb__DOT__io_event_bits))
                                                              ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_101
                                                              : 
                                                             ((0x64U 
                                                               == 
                                                               (0xffU 
                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                               ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_100
                                                               : 
                                                              ((0x63U 
                                                                == 
                                                                (0xffU 
                                                                 & vlSelfRef.tb__DOT__io_event_bits))
                                                                ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_99
                                                                : 
                                                               ((0x62U 
                                                                 == 
                                                                 (0xffU 
                                                                  & vlSelfRef.tb__DOT__io_event_bits))
                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_98
                                                                 : 
                                                                ((0x61U 
                                                                  == 
                                                                  (0xffU 
                                                                   & vlSelfRef.tb__DOT__io_event_bits))
                                                                  ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_97
                                                                  : 
                                                                 ((0x60U 
                                                                   == 
                                                                   (0xffU 
                                                                    & vlSelfRef.tb__DOT__io_event_bits))
                                                                   ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_96
                                                                   : 
                                                                  ((0x5fU 
                                                                    == 
                                                                    (0xffU 
                                                                     & vlSelfRef.tb__DOT__io_event_bits))
                                                                    ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_95
                                                                    : 
                                                                   ((0x5eU 
                                                                     == 
                                                                     (0xffU 
                                                                      & vlSelfRef.tb__DOT__io_event_bits))
                                                                     ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_94
                                                                     : 
                                                                    ((0x5dU 
                                                                      == 
                                                                      (0xffU 
                                                                       & vlSelfRef.tb__DOT__io_event_bits))
                                                                      ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_93
                                                                      : 
                                                                     ((0x5cU 
                                                                       == 
                                                                       (0xffU 
                                                                        & vlSelfRef.tb__DOT__io_event_bits))
                                                                       ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_92
                                                                       : 
                                                                      ((0x5bU 
                                                                        == 
                                                                        (0xffU 
                                                                         & vlSelfRef.tb__DOT__io_event_bits))
                                                                        ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_91
                                                                        : 
                                                                       ((0x5aU 
                                                                         == 
                                                                         (0xffU 
                                                                          & vlSelfRef.tb__DOT__io_event_bits))
                                                                         ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_90
                                                                         : 
                                                                        ((0x59U 
                                                                          == 
                                                                          (0xffU 
                                                                           & vlSelfRef.tb__DOT__io_event_bits))
                                                                          ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_89
                                                                          : 
                                                                         ((0x58U 
                                                                           == 
                                                                           (0xffU 
                                                                            & vlSelfRef.tb__DOT__io_event_bits))
                                                                           ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_88
                                                                           : 
                                                                          ((0x57U 
                                                                            == 
                                                                            (0xffU 
                                                                             & vlSelfRef.tb__DOT__io_event_bits))
                                                                            ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_87
                                                                            : 
                                                                           ((0x56U 
                                                                             == 
                                                                             (0xffU 
                                                                              & vlSelfRef.tb__DOT__io_event_bits))
                                                                             ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_86
                                                                             : 
                                                                            ((0x55U 
                                                                              == 
                                                                              (0xffU 
                                                                               & vlSelfRef.tb__DOT__io_event_bits))
                                                                              ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_85
                                                                              : 
                                                                             ((0x54U 
                                                                               == 
                                                                               (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                               ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_84
                                                                               : 
                                                                              ((0x53U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_83
                                                                                : 
                                                                               ((0x52U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_82
                                                                                 : 
                                                                                ((0x51U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_81
                                                                                 : 
                                                                                ((0x50U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_80
                                                                                 : 
                                                                                ((0x4fU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_79
                                                                                 : 
                                                                                ((0x4eU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_78
                                                                                 : 
                                                                                ((0x4dU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_77
                                                                                 : 
                                                                                ((0x4cU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_76
                                                                                 : 
                                                                                ((0x4bU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_75
                                                                                 : 
                                                                                ((0x4aU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_74
                                                                                 : 
                                                                                ((0x49U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_73
                                                                                 : 
                                                                                ((0x48U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_72
                                                                                 : 
                                                                                ((0x47U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_71
                                                                                 : 
                                                                                ((0x46U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_70
                                                                                 : 
                                                                                ((0x45U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_69
                                                                                 : 
                                                                                ((0x44U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_68
                                                                                 : 
                                                                                ((0x43U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_67
                                                                                 : 
                                                                                ((0x42U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_66
                                                                                 : 
                                                                                ((0x41U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_65
                                                                                 : 
                                                                                ((0x40U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_64
                                                                                 : 
                                                                                ((0x3fU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_63
                                                                                 : 
                                                                                ((0x3eU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_62
                                                                                 : 
                                                                                ((0x3dU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_61
                                                                                 : 
                                                                                ((0x3cU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_60
                                                                                 : 
                                                                                ((0x3bU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_59
                                                                                 : 
                                                                                ((0x3aU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_58
                                                                                 : 
                                                                                ((0x39U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_57
                                                                                 : 
                                                                                ((0x38U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_56
                                                                                 : 
                                                                                ((0x37U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_55
                                                                                 : 
                                                                                ((0x36U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_54
                                                                                 : 
                                                                                ((0x35U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_53
                                                                                 : 
                                                                                ((0x34U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_52
                                                                                 : 
                                                                                ((0x33U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_51
                                                                                 : 
                                                                                ((0x32U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_50
                                                                                 : 
                                                                                ((0x31U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_49
                                                                                 : 
                                                                                ((0x30U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_48
                                                                                 : 
                                                                                ((0x2fU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_47
                                                                                 : 
                                                                                ((0x2eU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_46
                                                                                 : 
                                                                                ((0x2dU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_45
                                                                                 : 
                                                                                ((0x2cU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_44
                                                                                 : 
                                                                                ((0x2bU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_43
                                                                                 : 
                                                                                ((0x2aU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_42
                                                                                 : 
                                                                                ((0x29U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_41
                                                                                 : 
                                                                                ((0x28U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_40
                                                                                 : 
                                                                                ((0x27U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_39
                                                                                 : 
                                                                                ((0x26U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_38
                                                                                 : 
                                                                                ((0x25U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_37
                                                                                 : 
                                                                                ((0x24U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_36
                                                                                 : 
                                                                                ((0x23U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_35
                                                                                 : 
                                                                                ((0x22U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_34
                                                                                 : 
                                                                                ((0x21U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_33
                                                                                 : 
                                                                                ((0x20U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_32
                                                                                 : 
                                                                                ((0x1fU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_31
                                                                                 : 
                                                                                ((0x1eU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_30
                                                                                 : 
                                                                                ((0x1dU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_29
                                                                                 : 
                                                                                ((0x1cU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_28
                                                                                 : 
                                                                                ((0x1bU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_27
                                                                                 : 
                                                                                ((0x1aU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_26
                                                                                 : 
                                                                                ((0x19U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_25
                                                                                 : 
                                                                                ((0x18U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_24
                                                                                 : 
                                                                                ((0x17U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_23
                                                                                 : 
                                                                                ((0x16U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_22
                                                                                 : 
                                                                                ((0x15U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_21
                                                                                 : 
                                                                                ((0x14U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_20
                                                                                 : 
                                                                                ((0x13U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_19
                                                                                 : 
                                                                                ((0x12U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_18
                                                                                 : 
                                                                                ((0x11U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_17
                                                                                 : 
                                                                                ((0x10U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_16
                                                                                 : 
                                                                                ((0xfU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_15
                                                                                 : 
                                                                                ((0xeU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_14
                                                                                 : 
                                                                                ((0xdU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_13
                                                                                 : 
                                                                                ((0xcU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_12
                                                                                 : 
                                                                                ((0xbU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_11
                                                                                 : 
                                                                                ((0xaU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_10
                                                                                 : 
                                                                                ((9U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_9
                                                                                 : 
                                                                                ((8U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_8
                                                                                 : 
                                                                                ((7U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_7
                                                                                 : 
                                                                                ((6U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_6
                                                                                 : 
                                                                                ((5U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_5
                                                                                 : 
                                                                                ((4U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_4
                                                                                 : 
                                                                                ((3U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_3
                                                                                 : 
                                                                                ((2U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_2
                                                                                 : 
                                                                                ((1U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_1
                                                                                 : vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_0))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
    __Vdeeptemp_h81314341__0 = ((0xecU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_236
                                 : ((0xebU == (0xffU 
                                               & vlSelfRef.tb__DOT__io_event_bits))
                                     ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_235
                                     : ((0xeaU == (0xffU 
                                                   & vlSelfRef.tb__DOT__io_event_bits))
                                         ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_234
                                         : ((0xe9U 
                                             == (0xffU 
                                                 & vlSelfRef.tb__DOT__io_event_bits))
                                             ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_233
                                             : ((0xe8U 
                                                 == 
                                                 (0xffU 
                                                  & vlSelfRef.tb__DOT__io_event_bits))
                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_232
                                                 : 
                                                ((0xe7U 
                                                  == 
                                                  (0xffU 
                                                   & vlSelfRef.tb__DOT__io_event_bits))
                                                  ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_231
                                                  : 
                                                 ((0xe6U 
                                                   == 
                                                   (0xffU 
                                                    & vlSelfRef.tb__DOT__io_event_bits))
                                                   ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_230
                                                   : 
                                                  ((0xe5U 
                                                    == 
                                                    (0xffU 
                                                     & vlSelfRef.tb__DOT__io_event_bits))
                                                    ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_229
                                                    : 
                                                   ((0xe4U 
                                                     == 
                                                     (0xffU 
                                                      & vlSelfRef.tb__DOT__io_event_bits))
                                                     ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_228
                                                     : 
                                                    ((0xe3U 
                                                      == 
                                                      (0xffU 
                                                       & vlSelfRef.tb__DOT__io_event_bits))
                                                      ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_227
                                                      : 
                                                     ((0xe2U 
                                                       == 
                                                       (0xffU 
                                                        & vlSelfRef.tb__DOT__io_event_bits))
                                                       ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_226
                                                       : 
                                                      ((0xe1U 
                                                        == 
                                                        (0xffU 
                                                         & vlSelfRef.tb__DOT__io_event_bits))
                                                        ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_225
                                                        : 
                                                       ((0xe0U 
                                                         == 
                                                         (0xffU 
                                                          & vlSelfRef.tb__DOT__io_event_bits))
                                                         ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_224
                                                         : 
                                                        ((0xdfU 
                                                          == 
                                                          (0xffU 
                                                           & vlSelfRef.tb__DOT__io_event_bits))
                                                          ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_223
                                                          : 
                                                         ((0xdeU 
                                                           == 
                                                           (0xffU 
                                                            & vlSelfRef.tb__DOT__io_event_bits))
                                                           ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_222
                                                           : 
                                                          ((0xddU 
                                                            == 
                                                            (0xffU 
                                                             & vlSelfRef.tb__DOT__io_event_bits))
                                                            ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_221
                                                            : 
                                                           ((0xdcU 
                                                             == 
                                                             (0xffU 
                                                              & vlSelfRef.tb__DOT__io_event_bits))
                                                             ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_220
                                                             : 
                                                            ((0xdbU 
                                                              == 
                                                              (0xffU 
                                                               & vlSelfRef.tb__DOT__io_event_bits))
                                                              ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_219
                                                              : 
                                                             ((0xdaU 
                                                               == 
                                                               (0xffU 
                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                               ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_218
                                                               : 
                                                              ((0xd9U 
                                                                == 
                                                                (0xffU 
                                                                 & vlSelfRef.tb__DOT__io_event_bits))
                                                                ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_217
                                                                : 
                                                               ((0xd8U 
                                                                 == 
                                                                 (0xffU 
                                                                  & vlSelfRef.tb__DOT__io_event_bits))
                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_216
                                                                 : 
                                                                ((0xd7U 
                                                                  == 
                                                                  (0xffU 
                                                                   & vlSelfRef.tb__DOT__io_event_bits))
                                                                  ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_215
                                                                  : 
                                                                 ((0xd6U 
                                                                   == 
                                                                   (0xffU 
                                                                    & vlSelfRef.tb__DOT__io_event_bits))
                                                                   ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_214
                                                                   : 
                                                                  ((0xd5U 
                                                                    == 
                                                                    (0xffU 
                                                                     & vlSelfRef.tb__DOT__io_event_bits))
                                                                    ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_213
                                                                    : 
                                                                   ((0xd4U 
                                                                     == 
                                                                     (0xffU 
                                                                      & vlSelfRef.tb__DOT__io_event_bits))
                                                                     ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_212
                                                                     : 
                                                                    ((0xd3U 
                                                                      == 
                                                                      (0xffU 
                                                                       & vlSelfRef.tb__DOT__io_event_bits))
                                                                      ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_211
                                                                      : 
                                                                     ((0xd2U 
                                                                       == 
                                                                       (0xffU 
                                                                        & vlSelfRef.tb__DOT__io_event_bits))
                                                                       ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_210
                                                                       : 
                                                                      ((0xd1U 
                                                                        == 
                                                                        (0xffU 
                                                                         & vlSelfRef.tb__DOT__io_event_bits))
                                                                        ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_209
                                                                        : 
                                                                       ((0xd0U 
                                                                         == 
                                                                         (0xffU 
                                                                          & vlSelfRef.tb__DOT__io_event_bits))
                                                                         ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_208
                                                                         : 
                                                                        ((0xcfU 
                                                                          == 
                                                                          (0xffU 
                                                                           & vlSelfRef.tb__DOT__io_event_bits))
                                                                          ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_207
                                                                          : 
                                                                         ((0xceU 
                                                                           == 
                                                                           (0xffU 
                                                                            & vlSelfRef.tb__DOT__io_event_bits))
                                                                           ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_206
                                                                           : 
                                                                          ((0xcdU 
                                                                            == 
                                                                            (0xffU 
                                                                             & vlSelfRef.tb__DOT__io_event_bits))
                                                                            ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_205
                                                                            : 
                                                                           ((0xccU 
                                                                             == 
                                                                             (0xffU 
                                                                              & vlSelfRef.tb__DOT__io_event_bits))
                                                                             ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_204
                                                                             : 
                                                                            ((0xcbU 
                                                                              == 
                                                                              (0xffU 
                                                                               & vlSelfRef.tb__DOT__io_event_bits))
                                                                              ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_203
                                                                              : 
                                                                             ((0xcaU 
                                                                               == 
                                                                               (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                               ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_202
                                                                               : 
                                                                              ((0xc9U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_201
                                                                                : 
                                                                               ((0xc8U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_200
                                                                                 : 
                                                                                ((0xc7U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_199
                                                                                 : 
                                                                                ((0xc6U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_198
                                                                                 : 
                                                                                ((0xc5U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_197
                                                                                 : 
                                                                                ((0xc4U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_196
                                                                                 : 
                                                                                ((0xc3U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_195
                                                                                 : 
                                                                                ((0xc2U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_194
                                                                                 : 
                                                                                ((0xc1U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_193
                                                                                 : 
                                                                                ((0xc0U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_192
                                                                                 : 
                                                                                ((0xbfU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_191
                                                                                 : 
                                                                                ((0xbeU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_190
                                                                                 : 
                                                                                ((0xbdU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_189
                                                                                 : 
                                                                                ((0xbcU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_188
                                                                                 : 
                                                                                ((0xbbU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_187
                                                                                 : 
                                                                                ((0xbaU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_186
                                                                                 : 
                                                                                ((0xb9U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_185
                                                                                 : 
                                                                                ((0xb8U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_184
                                                                                 : 
                                                                                ((0xb7U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_183
                                                                                 : 
                                                                                ((0xb6U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_182
                                                                                 : 
                                                                                ((0xb5U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_181
                                                                                 : 
                                                                                ((0xb4U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_180
                                                                                 : 
                                                                                ((0xb3U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_179
                                                                                 : 
                                                                                ((0xb2U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_178
                                                                                 : 
                                                                                ((0xb1U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_177
                                                                                 : 
                                                                                ((0xb0U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_176
                                                                                 : 
                                                                                ((0xafU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_175
                                                                                 : 
                                                                                ((0xaeU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_174
                                                                                 : 
                                                                                ((0xadU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_173
                                                                                 : 
                                                                                ((0xacU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_172
                                                                                 : 
                                                                                ((0xabU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_171
                                                                                 : 
                                                                                ((0xaaU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_170
                                                                                 : 
                                                                                ((0xa9U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_169
                                                                                 : 
                                                                                ((0xa8U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_168
                                                                                 : 
                                                                                ((0xa7U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_167
                                                                                 : 
                                                                                ((0xa6U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_166
                                                                                 : 
                                                                                ((0xa5U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_165
                                                                                 : 
                                                                                ((0xa4U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_164
                                                                                 : 
                                                                                ((0xa3U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_163
                                                                                 : 
                                                                                ((0xa2U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_162
                                                                                 : 
                                                                                ((0xa1U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_161
                                                                                 : 
                                                                                ((0xa0U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_160
                                                                                 : 
                                                                                ((0x9fU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_159
                                                                                 : 
                                                                                ((0x9eU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_158
                                                                                 : 
                                                                                ((0x9dU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_157
                                                                                 : 
                                                                                ((0x9cU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_156
                                                                                 : 
                                                                                ((0x9bU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_155
                                                                                 : 
                                                                                ((0x9aU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_154
                                                                                 : 
                                                                                ((0x99U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_153
                                                                                 : 
                                                                                ((0x98U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_152
                                                                                 : 
                                                                                ((0x97U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_151
                                                                                 : 
                                                                                ((0x96U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_150
                                                                                 : 
                                                                                ((0x95U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_149
                                                                                 : 
                                                                                ((0x94U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_148
                                                                                 : 
                                                                                ((0x93U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_147
                                                                                 : 
                                                                                ((0x92U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_146
                                                                                 : 
                                                                                ((0x91U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_145
                                                                                 : 
                                                                                ((0x90U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_144
                                                                                 : 
                                                                                ((0x8fU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_143
                                                                                 : 
                                                                                ((0x8eU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_142
                                                                                 : 
                                                                                ((0x8dU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_141
                                                                                 : 
                                                                                ((0x8cU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_140
                                                                                 : 
                                                                                ((0x8bU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_139
                                                                                 : 
                                                                                ((0x8aU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_138
                                                                                 : 
                                                                                ((0x89U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_137
                                                                                 : 
                                                                                ((0x88U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_136
                                                                                 : 
                                                                                ((0x87U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_135
                                                                                 : 
                                                                                ((0x86U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_134
                                                                                 : 
                                                                                ((0x85U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_133
                                                                                 : 
                                                                                ((0x84U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_132
                                                                                 : 
                                                                                ((0x83U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_131
                                                                                 : 
                                                                                ((0x82U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_130
                                                                                 : 
                                                                                ((0x81U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_129
                                                                                 : 
                                                                                ((0x80U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_128
                                                                                 : 
                                                                                ((0x7fU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_127
                                                                                 : 
                                                                                ((0x7eU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_126
                                                                                 : 
                                                                                ((0x7dU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_125
                                                                                 : 
                                                                                ((0x7cU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_124
                                                                                 : 
                                                                                ((0x7bU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_123
                                                                                 : 
                                                                                ((0x7aU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_122
                                                                                 : 
                                                                                ((0x79U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_121
                                                                                 : 
                                                                                ((0x78U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_120
                                                                                 : 
                                                                                ((0x77U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.tb__DOT__io_event_bits))
                                                                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_119
                                                                                 : __Vdeeptemp_h8317d69d__0))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
    __Vdeeptemp_h3dcf6d7f__0 = ((0xeeU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                                 ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_238
                                 : ((0xedU == (0xffU 
                                               & vlSelfRef.tb__DOT__io_event_bits))
                                     ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_237
                                     : __Vdeeptemp_h81314341__0));
    vlSelfRef.tb__DOT__dutReference__DOT__eventBucketAvailable 
        = ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) 
           | (((0xffU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_255
                : ((0xfeU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_254
                    : ((0xfdU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                        ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_253
                        : ((0xfcU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                            ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_252
                            : ((0xfbU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                                ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_251
                                : ((0xfaU == (0xffU 
                                              & vlSelfRef.tb__DOT__io_event_bits))
                                    ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_250
                                    : ((0xf9U == (0xffU 
                                                  & vlSelfRef.tb__DOT__io_event_bits))
                                        ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_249
                                        : ((0xf8U == 
                                            (0xffU 
                                             & vlSelfRef.tb__DOT__io_event_bits))
                                            ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_248
                                            : ((0xf7U 
                                                == 
                                                (0xffU 
                                                 & vlSelfRef.tb__DOT__io_event_bits))
                                                ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_247
                                                : (
                                                   (0xf6U 
                                                    == 
                                                    (0xffU 
                                                     & vlSelfRef.tb__DOT__io_event_bits))
                                                    ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_246
                                                    : 
                                                   ((0xf5U 
                                                     == 
                                                     (0xffU 
                                                      & vlSelfRef.tb__DOT__io_event_bits))
                                                     ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_245
                                                     : 
                                                    ((0xf4U 
                                                      == 
                                                      (0xffU 
                                                       & vlSelfRef.tb__DOT__io_event_bits))
                                                      ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_244
                                                      : 
                                                     ((0xf3U 
                                                       == 
                                                       (0xffU 
                                                        & vlSelfRef.tb__DOT__io_event_bits))
                                                       ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_243
                                                       : 
                                                      ((0xf2U 
                                                        == 
                                                        (0xffU 
                                                         & vlSelfRef.tb__DOT__io_event_bits))
                                                        ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_242
                                                        : 
                                                       ((0xf1U 
                                                         == 
                                                         (0xffU 
                                                          & vlSelfRef.tb__DOT__io_event_bits))
                                                         ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_241
                                                         : 
                                                        ((0xf0U 
                                                          == 
                                                          (0xffU 
                                                           & vlSelfRef.tb__DOT__io_event_bits))
                                                          ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_240
                                                          : 
                                                         ((0xefU 
                                                           == 
                                                           (0xffU 
                                                            & vlSelfRef.tb__DOT__io_event_bits))
                                                           ? vlSelfRef.tb__DOT__dutReference__DOT__buckets_seq_239
                                                           : __Vdeeptemp_h3dcf6d7f__0))))))))))))))))) 
              == vlSelfRef.tb__DOT__io_event_bits));
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__50(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__50\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*72:0*/ tb__DOT__dutReference__DOT__pendingBeforeResolve;
    VL_ZERO_W(73, tb__DOT__dutReference__DOT__pendingBeforeResolve);
    CData/*0:0*/ tb__DOT__dutReference__DOT___bucketCountOverflow_T_2;
    tb__DOT__dutReference__DOT___bucketCountOverflow_T_2 = 0;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__eventDropped 
        = ((~ (IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventBucketAvailable)) 
           & (IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventNeedsBucket));
    vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted 
        = ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventNeedsBucket) 
           & (IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventBucketAvailable));
    tb__DOT__dutReference__DOT___bucketCountOverflow_T_2 
        = ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) 
           & ((~ (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_511)) 
              & (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_255)));
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dutReference__DOT__pending);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dutReference__DOT__pending 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    tb__DOT__dutReference__DOT__pendingBeforeResolve[0U] 
        = __Vtemp_4[0U];
    tb__DOT__dutReference__DOT__pendingBeforeResolve[1U] 
        = __Vtemp_4[1U];
    tb__DOT__dutReference__DOT__pendingBeforeResolve[2U] 
        = (0x1ffU & __Vtemp_4[2U]);
    __Vtemp_5[0U] = vlSelfRef.tb__DOT__dutReference__DOT___resolvedBucketsWide_T_510[0U];
    __Vtemp_5[1U] = vlSelfRef.tb__DOT__dutReference__DOT___resolvedBucketsWide_T_510[1U];
    __Vtemp_5[2U] = vlSelfRef.tb__DOT__dutReference__DOT___resolvedBucketsWide_T_510[2U];
    vlSelfRef.tb__DOT__dutReference__DOT__pendingUnderflow 
        = VL_GT_W(3, __Vtemp_5, tb__DOT__dutReference__DOT__pendingBeforeResolve);
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dutReference__DOT___resolvedBucketsWide_T_510[0U];
    __Vtemp_7[1U] = vlSelfRef.tb__DOT__dutReference__DOT___resolvedBucketsWide_T_510[1U];
    __Vtemp_7[2U] = vlSelfRef.tb__DOT__dutReference__DOT___resolvedBucketsWide_T_510[2U];
    VL_SUB_W(3, __Vtemp_8, tb__DOT__dutReference__DOT__pendingBeforeResolve, __Vtemp_7);
    vlSelfRef.tb__DOT__dutReference__DOT__pendingNextWide[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dutReference__DOT__pendingNextWide[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dutReference__DOT__pendingNextWide[2U] 
        = (0x1ffU & __Vtemp_8[2U]);
    vlSelfRef.tb__DOT__dutReference__DOT___GEN_5645 
        = ((IData)(vlSelfRef.tb__DOT__io_resetStats) 
           | ((~ ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventDropped) 
                  | (((IData)(tb__DOT__dutReference__DOT___bucketCountOverflow_T_2) 
                      & (0xffffffffffffffffULL == vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)) 
                     | ((((IData)(tb__DOT__dutReference__DOT___bucketCountOverflow_T_2) 
                          & (vlSelfRef.tb__DOT__dutReference__DOT___GEN_1279 
                             > (0xffffffffffffffffULL 
                                - vlSelfRef.tb__DOT__io_currentCycle))) 
                         | ((0U != (0x1ffU & (vlSelfRef.tb__DOT__dutReference__DOT__resolvedThisCycleWide[2U] 
                                              | vlSelfRef.tb__DOT__dutReference__DOT__requestThisCycleWide[2U]))) 
                            | (IData)(((0U != vlSelfRef.tb__DOT__dutReference__DOT__pendingNextWide[2U]) 
                                       | (0U != ((vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[2U] 
                                                  | vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[3U]) 
                                                 | (0x1ffU 
                                                    & vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[4U]))))))) 
                        | ((((IData)(vlSelfRef.tb__DOT__io_event_valid) 
                             & (0xffffffffffffffffULL 
                                == vlSelfRef.tb__DOT__dutReference__DOT__seen)) 
                            | ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventDropped) 
                               & (0xffffffffffffffffULL 
                                  == vlSelfRef.tb__DOT__dutReference__DOT__dropped))) 
                           | ((((0U != ((vlSelfRef.tb__DOT__dutReference__DOT__resolvedThisCycleWide[0U] 
                                         | vlSelfRef.tb__DOT__dutReference__DOT__resolvedThisCycleWide[1U]) 
                                        | vlSelfRef.tb__DOT__dutReference__DOT__resolvedThisCycleWide[2U])) 
                                & (vlSelfRef.tb__DOT__dutReference__DOT__resolved 
                                   > (0xffffffffffffffffULL 
                                      - (((QData)((IData)(
                                                          vlSelfRef.tb__DOT__dutReference__DOT__resolvedThisCycleWide[1U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.tb__DOT__dutReference__DOT__resolvedThisCycleWide[0U])))))) 
                               | ((0U != ((vlSelfRef.tb__DOT__dutReference__DOT__requestThisCycleWide[0U] 
                                           | vlSelfRef.tb__DOT__dutReference__DOT__requestThisCycleWide[1U]) 
                                          | vlSelfRef.tb__DOT__dutReference__DOT__requestThisCycleWide[2U])) 
                                  & (vlSelfRef.tb__DOT__dutReference__DOT__requestCycleSum 
                                     > (0xffffffffffffffffULL 
                                        - (((QData)((IData)(
                                                            vlSelfRef.tb__DOT__dutReference__DOT__requestThisCycleWide[1U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlSelfRef.tb__DOT__dutReference__DOT__requestThisCycleWide[0U]))))))) 
                              | (((0U != ((((vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[0U] 
                                             | vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[1U]) 
                                            | vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[2U]) 
                                           | vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[3U]) 
                                          | vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[4U])) 
                                  & (vlSelfRef.tb__DOT__dutReference__DOT__safeCycleSum 
                                     > (0xffffffffffffffffULL 
                                        - (((QData)((IData)(
                                                            vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[1U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlSelfRef.tb__DOT__dutReference__DOT__safeThisCycleWide[0U])))))) 
                                 | ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__pendingUnderflow) 
                                    | (IData)(vlSelfRef.tb__DOT__io_fatalProtocolError))))))))) 
              & (IData)(vlSelfRef.tb__DOT__dutReference__DOT__statsValid)));
}

void Vtb___024root___timing_resume(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___timing_resume\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb___024root___eval_triggers__act(Vtb___024root* vlSelf);
void Vtb___024root___eval_act(Vtb___024root* vlSelf);

bool Vtb___024root___eval_phase__act(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb___024root___timing_resume(vlSelf);
        Vtb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtb___024root___eval_nba(Vtb___024root* vlSelf);

bool Vtb___024root___eval_phase__nba(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__nba(Vtb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(Vtb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb___024root___eval(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-barrier-banked-host-r1-20261113/tb-16.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-barrier-banked-host-r1-20261113/tb-16.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb___024root___eval_debug_assertions(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
