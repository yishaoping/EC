// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb__pch.h"

//============================================================
// Constructors

Vtb::Vtb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb__Syms(contextp(), _vcname__, this)}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_0{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_0}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_1{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_1}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_2{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_2}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_3{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_3}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_4{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_4}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_5{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_5}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_6{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_6}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_7{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_7}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_8{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_8}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_9{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_9}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_10{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_10}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_11{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_11}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_12{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_12}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_13{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_13}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_14{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_14}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_15{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_15}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_16{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_16}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_17{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_17}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_18{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_18}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_19{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_19}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_20{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_20}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_21{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_21}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_22{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_22}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_23{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_23}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_24{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_24}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_25{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_25}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_26{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_26}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_27{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_27}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_28{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_28}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_29{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_29}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_30{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_30}
    , __PVT__tb__DOT__dutCandidate__DOT__bucketBanks_31{vlSymsp->TOP.__PVT__tb__DOT__dutCandidate__DOT__bucketBanks_31}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb::Vtb(const char* _vcname__)
    : Vtb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb::~Vtb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb___024root___eval_debug_assertions(Vtb___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb___024root___eval_static(Vtb___024root* vlSelf);
void Vtb___024root___eval_initial(Vtb___024root* vlSelf);
void Vtb___024root___eval_settle(Vtb___024root* vlSelf);
void Vtb___024root___eval(Vtb___024root* vlSelf);

void Vtb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb___024root___eval_static(&(vlSymsp->TOP));
        Vtb___024root___eval_initial(&(vlSymsp->TOP));
        Vtb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb___024root___eval_final(Vtb___024root* vlSelf);

VL_ATTR_COLD void Vtb::final() {
    Vtb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb::hierName() const { return vlSymsp->name(); }
const char* Vtb::modelName() const { return "Vtb"; }
unsigned Vtb::threads() const { return 1; }
void Vtb::prepareClone() const { contextp()->prepareClone(); }
void Vtb::atClone() const {
    contextp()->threadPoolpOnClone();
}
