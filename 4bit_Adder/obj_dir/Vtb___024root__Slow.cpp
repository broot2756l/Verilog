// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"

void Vtb___024root___ctor_var_reset(Vtb___024root* vlSelf);

Vtb___024root::Vtb___024root(Vtb__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtb___024root___ctor_var_reset(this);
}

void Vtb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb___024root::~Vtb___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
