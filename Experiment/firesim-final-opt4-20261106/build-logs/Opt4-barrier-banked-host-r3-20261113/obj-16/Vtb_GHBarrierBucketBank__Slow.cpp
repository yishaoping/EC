// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_GHBarrierBucketBank.h"
#include "Vtb__Syms.h"

void Vtb_GHBarrierBucketBank___ctor_var_reset(Vtb_GHBarrierBucketBank* vlSelf);

Vtb_GHBarrierBucketBank::Vtb_GHBarrierBucketBank(Vtb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_GHBarrierBucketBank___ctor_var_reset(this);
}

void Vtb_GHBarrierBucketBank::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_GHBarrierBucketBank::~Vtb_GHBarrierBucketBank() {
}
