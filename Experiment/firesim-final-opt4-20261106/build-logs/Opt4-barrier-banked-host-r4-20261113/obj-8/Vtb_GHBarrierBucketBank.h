// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb.h for the primary calling header

#ifndef VERILATED_VTB_GHBARRIERBUCKETBANK_H_
#define VERILATED_VTB_GHBARRIERBUCKETBANK_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_GHBarrierBucketBank final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(io_base,7,0);
        VL_IN8(io_resetStats,0,0);
        VL_IN8(io_event_valid,0,0);
        VL_OUT8(io_eventAvailable,0,0);
        VL_OUT8(io_countOverflow,0,0);
        VL_OUT8(io_cycleOverflow,0,0);
        CData/*0:0*/ __PVT__buckets_valid_0;
        CData/*0:0*/ __PVT__buckets_valid_1;
        CData/*0:0*/ __PVT__buckets_valid_2;
        CData/*0:0*/ __PVT__buckets_valid_3;
        CData/*0:0*/ __PVT__buckets_valid_4;
        CData/*0:0*/ __PVT__buckets_valid_5;
        CData/*0:0*/ __PVT__buckets_valid_6;
        CData/*0:0*/ buckets_valid_7;
        CData/*0:0*/ __PVT__eventNeedsBucket;
        CData/*0:0*/ __PVT__resolving_0;
        CData/*0:0*/ __PVT___canAccept_T_1;
        CData/*0:0*/ __PVT__accepted;
        CData/*0:0*/ __PVT__available_0;
        CData/*0:0*/ __PVT___countOverflow_0_T_2;
        CData/*0:0*/ __PVT___GEN_0;
        CData/*0:0*/ __PVT__resolving_1;
        CData/*0:0*/ __PVT___canAccept_T_4;
        CData/*0:0*/ __PVT__accepted_1;
        CData/*0:0*/ __PVT__available_1;
        CData/*0:0*/ __PVT___countOverflow_1_T_2;
        CData/*0:0*/ __PVT___GEN_15;
        CData/*0:0*/ __PVT__resolving_2;
        CData/*0:0*/ __PVT___canAccept_T_7;
        CData/*0:0*/ __PVT__accepted_2;
        CData/*0:0*/ __PVT__available_2;
        CData/*0:0*/ __PVT___countOverflow_2_T_2;
        CData/*0:0*/ __PVT___GEN_30;
        CData/*0:0*/ __PVT__resolving_3;
        CData/*0:0*/ __PVT___canAccept_T_10;
        CData/*0:0*/ __PVT__accepted_3;
        CData/*0:0*/ __PVT__available_3;
        CData/*0:0*/ __PVT___countOverflow_3_T_2;
        CData/*0:0*/ __PVT___GEN_45;
        CData/*0:0*/ __PVT__resolving_4;
        CData/*0:0*/ __PVT___canAccept_T_13;
        CData/*0:0*/ __PVT__accepted_4;
        CData/*0:0*/ __PVT__available_4;
        CData/*0:0*/ __PVT___countOverflow_4_T_2;
        CData/*0:0*/ __PVT___GEN_60;
        CData/*0:0*/ __PVT__resolving_5;
        CData/*0:0*/ __PVT___canAccept_T_16;
        CData/*0:0*/ __PVT__accepted_5;
        CData/*0:0*/ __PVT__available_5;
        CData/*0:0*/ __PVT___countOverflow_5_T_2;
        CData/*0:0*/ __PVT___GEN_75;
        CData/*0:0*/ __PVT__resolving_6;
        CData/*0:0*/ __PVT___canAccept_T_19;
        CData/*0:0*/ __PVT__accepted_6;
        CData/*0:0*/ __PVT__available_6;
        CData/*0:0*/ __PVT___countOverflow_6_T_2;
        CData/*0:0*/ __PVT___GEN_90;
        CData/*0:0*/ __PVT__resolving_7;
        CData/*0:0*/ __PVT___canAccept_T_22;
        CData/*0:0*/ __PVT__accepted_7;
        CData/*0:0*/ __PVT__available_7;
        CData/*0:0*/ __PVT___countOverflow_7_T_2;
    };
    struct {
        CData/*0:0*/ __PVT___GEN_105;
        VL_OUTW(io_observe_0,160,0,6);
        VL_OUTW(io_observe_1,160,0,6);
        VL_OUTW(io_observe_2,160,0,6);
        VL_OUTW(io_observe_3,160,0,6);
        VL_OUTW(io_observe_4,160,0,6);
        VL_OUTW(io_observe_5,160,0,6);
        VL_OUTW(io_observe_6,160,0,6);
        VL_OUTW(io_observe_7,160,0,6);
        VL_IN(io_event_bits,31,0);
        VL_IN(io_safeWatermark,31,0);
        VL_OUTW(io_resolvedCount,66,0,3);
        VL_OUTW(io_resolvedRequest,66,0,3);
        IData/*31:0*/ __PVT__buckets_seq_0;
        IData/*31:0*/ __PVT__buckets_seq_1;
        IData/*31:0*/ __PVT__buckets_seq_2;
        IData/*31:0*/ __PVT__buckets_seq_3;
        IData/*31:0*/ __PVT__buckets_seq_4;
        IData/*31:0*/ __PVT__buckets_seq_5;
        IData/*31:0*/ __PVT__buckets_seq_6;
        IData/*31:0*/ buckets_seq_7;
        VL_IN64(io_currentCycle,63,0);
        QData/*63:0*/ __PVT__buckets_count_0;
        QData/*63:0*/ __PVT__buckets_count_1;
        QData/*63:0*/ __PVT__buckets_count_2;
        QData/*63:0*/ __PVT__buckets_count_3;
        QData/*63:0*/ __PVT__buckets_count_4;
        QData/*63:0*/ __PVT__buckets_count_5;
        QData/*63:0*/ __PVT__buckets_count_6;
        QData/*63:0*/ buckets_count_7;
        QData/*63:0*/ __PVT__buckets_requestCycleSum_0;
        QData/*63:0*/ __PVT__buckets_requestCycleSum_1;
        QData/*63:0*/ __PVT__buckets_requestCycleSum_2;
        QData/*63:0*/ __PVT__buckets_requestCycleSum_3;
        QData/*63:0*/ __PVT__buckets_requestCycleSum_4;
        QData/*63:0*/ __PVT__buckets_requestCycleSum_5;
        QData/*63:0*/ __PVT__buckets_requestCycleSum_6;
        QData/*63:0*/ buckets_requestCycleSum_7;
        QData/*63:0*/ __PVT___buckets_count_0_T_1;
        QData/*63:0*/ __PVT___buckets_requestCycleSum_0_T_1;
        QData/*63:0*/ __PVT___buckets_count_1_T_1;
        QData/*63:0*/ __PVT___buckets_requestCycleSum_1_T_1;
        QData/*63:0*/ __PVT___buckets_count_2_T_1;
        QData/*63:0*/ __PVT___buckets_requestCycleSum_2_T_1;
        QData/*63:0*/ __PVT___buckets_count_3_T_1;
        QData/*63:0*/ __PVT___buckets_requestCycleSum_3_T_1;
        QData/*63:0*/ __PVT___buckets_count_4_T_1;
        QData/*63:0*/ __PVT___buckets_requestCycleSum_4_T_1;
        QData/*63:0*/ __PVT___buckets_count_5_T_1;
        QData/*63:0*/ __PVT___buckets_requestCycleSum_5_T_1;
        QData/*63:0*/ __PVT___buckets_count_6_T_1;
        QData/*63:0*/ __PVT___buckets_requestCycleSum_6_T_1;
        QData/*63:0*/ __PVT___buckets_count_7_T_1;
        QData/*63:0*/ __PVT___buckets_requestCycleSum_7_T_1;
    };

    // INTERNAL VARIABLES
    Vtb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_GHBarrierBucketBank(Vtb__Syms* symsp, const char* v__name);
    ~Vtb_GHBarrierBucketBank();
    VL_UNCOPYABLE(Vtb_GHBarrierBucketBank);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
