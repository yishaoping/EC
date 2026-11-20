// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_ReferenceBank.h"
#include "Vtb__Syms.h"

void Vtb_ReferenceBank___ctor_var_reset(Vtb_ReferenceBank* vlSelf);

Vtb_ReferenceBank::Vtb_ReferenceBank(Vtb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_ReferenceBank___ctor_var_reset(this);
}

void Vtb_ReferenceBank::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_ReferenceBank::~Vtb_ReferenceBank() {
}
