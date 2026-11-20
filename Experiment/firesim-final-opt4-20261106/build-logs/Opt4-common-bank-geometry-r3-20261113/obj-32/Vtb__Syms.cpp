// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb__pch.h"
#include "Vtb.h"
#include "Vtb___024root.h"
#include "Vtb_ReferenceBank.h"

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
    , TOP__tb__DOT__dut__DOT__reference_0{this, Verilated::catName(namep, "tb.dut.reference_0")}
    , TOP__tb__DOT__dut__DOT__reference_1{this, Verilated::catName(namep, "tb.dut.reference_1")}
{
        // Check resources
        Verilated::stackCheck(323778);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__tb__DOT__dut__DOT__reference_0 = &TOP__tb__DOT__dut__DOT__reference_0;
    TOP.__PVT__tb__DOT__dut__DOT__reference_1 = &TOP__tb__DOT__dut__DOT__reference_1;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__tb__DOT__dut__DOT__reference_0.__Vconfigure(true);
    TOP__tb__DOT__dut__DOT__reference_1.__Vconfigure(false);
    // Setup scopes
    __Vscope_tb.configure(this, name(), "tb", "tb", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb__check.configure(this, name(), "tb.check", "check", -12, VerilatedScope::SCOPE_OTHER);
}
