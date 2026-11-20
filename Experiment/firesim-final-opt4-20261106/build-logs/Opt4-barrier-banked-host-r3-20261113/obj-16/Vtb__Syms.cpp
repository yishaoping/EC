// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb__pch.h"
#include "Vtb.h"
#include "Vtb___024root.h"
#include "Vtb_GHBarrierBucketBank.h"

// FUNCTIONS
Vtb__Syms::~Vtb__Syms()
{
}

Vtb__Syms::Vtb__Syms(VerilatedContext* contextp, const char* namep, Vtb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0{this, Verilated::catName(namep, "tb.dutCandidate.bucketBanks_0")}
    , TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1{this, Verilated::catName(namep, "tb.dutCandidate.bucketBanks_1")}
    , TOP__tb__DOT__dutCandidate__DOT__bucketBanks_10{this, Verilated::catName(namep, "tb.dutCandidate.bucketBanks_10")}
    , TOP__tb__DOT__dutCandidate__DOT__bucketBanks_11{this, Verilated::catName(namep, "tb.dutCandidate.bucketBanks_11")}
    , TOP__tb__DOT__dutCandidate__DOT__bucketBanks_12{this, Verilated::catName(namep, "tb.dutCandidate.bucketBanks_12")}
    , TOP__tb__DOT__dutCandidate__DOT__bucketBanks_13{this, Verilated::catName(namep, "tb.dutCandidate.bucketBanks_13")}
    , TOP__tb__DOT__dutCandidate__DOT__bucketBanks_14{this, Verilated::catName(namep, "tb.dutCandidate.bucketBanks_14")}
    , TOP__tb__DOT__dutCandidate__DOT__bucketBanks_15{this, Verilated::catName(namep, "tb.dutCandidate.bucketBanks_15")}
    , TOP__tb__DOT__dutCandidate__DOT__bucketBanks_2{this, Verilated::catName(namep, "tb.dutCandidate.bucketBanks_2")}
    , TOP__tb__DOT__dutCandidate__DOT__bucketBanks_3{this, Verilated::catName(namep, "tb.dutCandidate.bucketBanks_3")}
    , TOP__tb__DOT__dutCandidate__DOT__bucketBanks_4{this, Verilated::catName(namep, "tb.dutCandidate.bucketBanks_4")}
    , TOP__tb__DOT__dutCandidate__DOT__bucketBanks_5{this, Verilated::catName(namep, "tb.dutCandidate.bucketBanks_5")}
    , TOP__tb__DOT__dutCandidate__DOT__bucketBanks_6{this, Verilated::catName(namep, "tb.dutCandidate.bucketBanks_6")}
    , TOP__tb__DOT__dutCandidate__DOT__bucketBanks_7{this, Verilated::catName(namep, "tb.dutCandidate.bucketBanks_7")}
    , TOP__tb__DOT__dutCandidate__DOT__bucketBanks_8{this, Verilated::catName(namep, "tb.dutCandidate.bucketBanks_8")}
    , TOP__tb__DOT__dutCandidate__DOT__bucketBanks_9{this, Verilated::catName(namep, "tb.dutCandidate.bucketBanks_9")}
{
        // Check resources
        Verilated::stackCheck(224040);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_0 = &TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0;
    TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_1 = &TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1;
    TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_10 = &TOP__tb__DOT__dutCandidate__DOT__bucketBanks_10;
    TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_11 = &TOP__tb__DOT__dutCandidate__DOT__bucketBanks_11;
    TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_12 = &TOP__tb__DOT__dutCandidate__DOT__bucketBanks_12;
    TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_13 = &TOP__tb__DOT__dutCandidate__DOT__bucketBanks_13;
    TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_14 = &TOP__tb__DOT__dutCandidate__DOT__bucketBanks_14;
    TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_15 = &TOP__tb__DOT__dutCandidate__DOT__bucketBanks_15;
    TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_2 = &TOP__tb__DOT__dutCandidate__DOT__bucketBanks_2;
    TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_3 = &TOP__tb__DOT__dutCandidate__DOT__bucketBanks_3;
    TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_4 = &TOP__tb__DOT__dutCandidate__DOT__bucketBanks_4;
    TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_5 = &TOP__tb__DOT__dutCandidate__DOT__bucketBanks_5;
    TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_6 = &TOP__tb__DOT__dutCandidate__DOT__bucketBanks_6;
    TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_7 = &TOP__tb__DOT__dutCandidate__DOT__bucketBanks_7;
    TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_8 = &TOP__tb__DOT__dutCandidate__DOT__bucketBanks_8;
    TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_9 = &TOP__tb__DOT__dutCandidate__DOT__bucketBanks_9;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0.__Vconfigure(true);
    TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1.__Vconfigure(false);
    TOP__tb__DOT__dutCandidate__DOT__bucketBanks_10.__Vconfigure(false);
    TOP__tb__DOT__dutCandidate__DOT__bucketBanks_11.__Vconfigure(false);
    TOP__tb__DOT__dutCandidate__DOT__bucketBanks_12.__Vconfigure(false);
    TOP__tb__DOT__dutCandidate__DOT__bucketBanks_13.__Vconfigure(false);
    TOP__tb__DOT__dutCandidate__DOT__bucketBanks_14.__Vconfigure(false);
    TOP__tb__DOT__dutCandidate__DOT__bucketBanks_15.__Vconfigure(false);
    TOP__tb__DOT__dutCandidate__DOT__bucketBanks_2.__Vconfigure(false);
    TOP__tb__DOT__dutCandidate__DOT__bucketBanks_3.__Vconfigure(false);
    TOP__tb__DOT__dutCandidate__DOT__bucketBanks_4.__Vconfigure(false);
    TOP__tb__DOT__dutCandidate__DOT__bucketBanks_5.__Vconfigure(false);
    TOP__tb__DOT__dutCandidate__DOT__bucketBanks_6.__Vconfigure(false);
    TOP__tb__DOT__dutCandidate__DOT__bucketBanks_7.__Vconfigure(false);
    TOP__tb__DOT__dutCandidate__DOT__bucketBanks_8.__Vconfigure(false);
    TOP__tb__DOT__dutCandidate__DOT__bucketBanks_9.__Vconfigure(false);
    // Setup scopes
    __Vscope_tb.configure(this, name(), "tb", "tb", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb__check.configure(this, name(), "tb.check", "check", -12, VerilatedScope::SCOPE_OTHER);
}
