// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB__SYMS_H_
#define VERILATED_VTB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb.h"

// INCLUDE MODULE CLASSES
#include "Vtb___024root.h"
#include "Vtb_GHBarrierBucketBank.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb___024root                  TOP;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_10;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_11;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_12;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_13;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_14;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_15;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_16;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_17;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_18;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_19;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_2;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_20;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_21;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_22;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_23;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_24;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_25;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_26;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_27;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_28;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_29;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_3;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_30;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_31;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_4;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_5;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_6;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_7;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_8;
    Vtb_GHBarrierBucketBank        TOP__tb__DOT__dutCandidate__DOT__bucketBanks_9;

    // SCOPE NAMES
    VerilatedScope __Vscope_tb;
    VerilatedScope __Vscope_tb__check;

    // CONSTRUCTORS
    Vtb__Syms(VerilatedContext* contextp, const char* namep, Vtb* modelp);
    ~Vtb__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
