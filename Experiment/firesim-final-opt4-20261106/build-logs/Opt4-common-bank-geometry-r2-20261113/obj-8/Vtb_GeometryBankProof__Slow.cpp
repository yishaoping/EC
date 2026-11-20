// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_GeometryBankProof.h"
#include "Vtb__Syms.h"

void Vtb_GeometryBankProof___ctor_var_reset(Vtb_GeometryBankProof* vlSelf);

Vtb_GeometryBankProof::Vtb_GeometryBankProof(Vtb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_GeometryBankProof___ctor_var_reset(this);
}

void Vtb_GeometryBankProof::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_GeometryBankProof::~Vtb_GeometryBankProof() {
}
