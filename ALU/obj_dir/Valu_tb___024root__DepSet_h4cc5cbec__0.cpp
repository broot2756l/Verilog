// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu_tb.h for the primary calling header

#include "Valu_tb__pch.h"
#include "Valu_tb__Syms.h"
#include "Valu_tb___024root.h"

VL_INLINE_OPT VlCoroutine Valu_tb___024root___eval_initial__TOP__Vtiming__0(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile(std::string{"dump.vcd"});
    vlSymsp->_traceDumpOpen();
    vlSelfRef.alu_tb__DOT__tb_a = 0xffU;
    vlSelfRef.alu_tb__DOT__tb_b = 0xffU;
    vlSelfRef.alu_tb__DOT__tb_opcode = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         29);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((0x1feU != (IData)(vlSelfRef.alu_tb__DOT__tb_result)))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:35: Assertion failed in %Nalu_tb: ADD Failed\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("alu_tb.v", 35, "");
        }
    }
    VL_WRITEF_NX("ADD test passed %3# + %3# = %5#\n",0,
                 8,vlSelfRef.alu_tb__DOT__tb_a,8,(IData)(vlSelfRef.alu_tb__DOT__tb_b),
                 16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 5U;
    vlSelfRef.alu_tb__DOT__tb_b = 3U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         42);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((2U != (IData)(vlSelfRef.alu_tb__DOT__tb_result)))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:43: Assertion failed in %Nalu_tb: SUB failed\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("alu_tb.v", 43, "");
        }
    }
    VL_WRITEF_NX("SUB test passed %3# - %3# = %5#\n",0,
                 8,vlSelfRef.alu_tb__DOT__tb_a,8,(IData)(vlSelfRef.alu_tb__DOT__tb_b),
                 16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0xffU;
    vlSelfRef.alu_tb__DOT__tb_b = 0xfU;
    vlSelfRef.alu_tb__DOT__tb_opcode = 2U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         50);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((0xfU != (IData)(vlSelfRef.alu_tb__DOT__tb_result)))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:51: Assertion failed in %Nalu_tb: AND failed\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("alu_tb.v", 51, "");
        }
    }
    VL_WRITEF_NX("AND test passed %02x & %02x = %02x\n",0,
                 8,vlSelfRef.alu_tb__DOT__tb_a,8,(IData)(vlSelfRef.alu_tb__DOT__tb_b),
                 16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0xf0U;
    vlSelfRef.alu_tb__DOT__tb_b = 0xfU;
    vlSelfRef.alu_tb__DOT__tb_opcode = 3U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         58);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((0xffU != (IData)(vlSelfRef.alu_tb__DOT__tb_result)))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:59: Assertion failed in %Nalu_tb: OR failed\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("alu_tb.v", 59, "");
        }
    }
    VL_WRITEF_NX("OR test passed %02x | %02x = %02x\n",0,
                 8,vlSelfRef.alu_tb__DOT__tb_a,8,(IData)(vlSelfRef.alu_tb__DOT__tb_b),
                 16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0xaaU;
    vlSelfRef.alu_tb__DOT__tb_b = 0x55U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 4U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         66);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((0xffU != (IData)(vlSelfRef.alu_tb__DOT__tb_result)))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:67: Assertion failed in %Nalu_tb: XOR failed\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("alu_tb.v", 67, "");
        }
    }
    VL_WRITEF_NX("XOR test passed %02x ^ %02x = %02x\n",0,
                 8,vlSelfRef.alu_tb__DOT__tb_a,8,(IData)(vlSelfRef.alu_tb__DOT__tb_b),
                 16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 5U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 5U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         73);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((0xaU != (IData)(vlSelfRef.alu_tb__DOT__tb_result)))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:74: Assertion failed in %Nalu_tb: SHL failed\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("alu_tb.v", 74, "");
        }
    }
    VL_WRITEF_NX("Left shift test passed %02x << 1 = %02x\n",0,
                 8,vlSelfRef.alu_tb__DOT__tb_a,16,(IData)(vlSelfRef.alu_tb__DOT__tb_result));
    vlSelfRef.alu_tb__DOT__tb_a = 5U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 6U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         80);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((2U != (IData)(vlSelfRef.alu_tb__DOT__tb_result)))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:81: Assertion failed in %Nalu_tb: SHR failed\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("alu_tb.v", 81, "");
        }
    }
    VL_WRITEF_NX("Right shift test passed %02x << 1 = %02x\n",0,
                 8,vlSelfRef.alu_tb__DOT__tb_a,16,(IData)(vlSelfRef.alu_tb__DOT__tb_result));
    vlSelfRef.alu_tb__DOT__tb_a = 0xffU;
    vlSelfRef.alu_tb__DOT__tb_b = 0xfU;
    vlSelfRef.alu_tb__DOT__tb_opcode = 7U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         88);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((0xf0U != (IData)(vlSelfRef.alu_tb__DOT__tb_result)))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:89: Assertion failed in %Nalu_tb: NAND failed, expected 0xF0, got 0x%02x\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name(),16,(IData)(vlSelfRef.alu_tb__DOT__tb_result));
            VL_STOP_MT("alu_tb.v", 89, "");
        }
    }
    VL_WRITEF_NX("NAND test passed ~(%02x & %02x) = %02x\n",0,
                 8,vlSelfRef.alu_tb__DOT__tb_a,8,(IData)(vlSelfRef.alu_tb__DOT__tb_b),
                 16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0U;
    vlSelfRef.alu_tb__DOT__tb_b = 0xffU;
    vlSelfRef.alu_tb__DOT__tb_opcode = 2U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         96);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelfRef.alu_tb__DOT__tb_zero_flag))))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:97: Assertion failed in %Nalu_tb: Zero flag failed\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("alu_tb.v", 97, "");
        }
    }
    VL_WRITEF_NX("Zero flag check passed\n",0);
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         99);
    vlSelfRef.alu_tb__DOT__tb_a = 0xaU;
    vlSelfRef.alu_tb__DOT__tb_b = 0xcU;
    vlSelfRef.alu_tb__DOT__tb_opcode = 8U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         105);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((0x78U != (IData)(vlSelfRef.alu_tb__DOT__tb_result)))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:106: Assertion failed in %Nalu_tb: MUL failed: expected 120, got %5#\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name(),16,(IData)(vlSelfRef.alu_tb__DOT__tb_result));
            VL_STOP_MT("alu_tb.v", 106, "");
        }
    }
    VL_WRITEF_NX("MUL test passed %3# x %3# = %5#\n",0,
                 8,vlSelfRef.alu_tb__DOT__tb_a,8,(IData)(vlSelfRef.alu_tb__DOT__tb_b),
                 16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0xc8U;
    vlSelfRef.alu_tb__DOT__tb_b = 2U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 8U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         113);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((0x190U != (IData)(vlSelfRef.alu_tb__DOT__tb_result)))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:114: Assertion failed in %Nalu_tb: MUL overflow failed: expected 400, got %5#\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name(),16,(IData)(vlSelfRef.alu_tb__DOT__tb_result));
            VL_STOP_MT("alu_tb.v", 114, "");
        }
    }
    VL_WRITEF_NX("MUL overflow test passed %3# x %3# = %5#\n",0,
                 8,vlSelfRef.alu_tb__DOT__tb_a,8,(IData)(vlSelfRef.alu_tb__DOT__tb_b),
                 16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0xffU;
    vlSelfRef.alu_tb__DOT__tb_b = 0xffU;
    vlSelfRef.alu_tb__DOT__tb_opcode = 8U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         121);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((0xfe01U != (IData)(vlSelfRef.alu_tb__DOT__tb_result)))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:122: Assertion failed in %Nalu_tb: MUL max failed: expected 65025, got %5#\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name(),16,(IData)(vlSelfRef.alu_tb__DOT__tb_result));
            VL_STOP_MT("alu_tb.v", 122, "");
        }
    }
    VL_WRITEF_NX("MUL max test passed %3# x %3# = %5#\n",0,
                 8,vlSelfRef.alu_tb__DOT__tb_a,8,(IData)(vlSelfRef.alu_tb__DOT__tb_b),
                 16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0x19U;
    vlSelfRef.alu_tb__DOT__tb_b = 4U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 9U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         129);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((6U != (0xffU & (IData)(vlSelfRef.alu_tb__DOT__tb_result))))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:131: Assertion failed in %Nalu_tb: DIV quotient failed: expected 6, got %3#\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name(),8,(0xffU 
                                               & (IData)(vlSelfRef.alu_tb__DOT__tb_result)));
            VL_STOP_MT("alu_tb.v", 131, "");
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((1U != (0xffU & ((IData)(vlSelfRef.alu_tb__DOT__tb_result) 
                                         >> 8U))))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:132: Assertion failed in %Nalu_tb: DIV remainder failed: expected 1, got %3#\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name(),8,(0xffU 
                                               & ((IData)(vlSelfRef.alu_tb__DOT__tb_result) 
                                                  >> 8U)));
            VL_STOP_MT("alu_tb.v", 132, "");
        }
    }
    VL_WRITEF_NX("DIV test 1 passed %3# / %3# = %3#*%3# + %3#\n",0,
                 8,vlSelfRef.alu_tb__DOT__tb_a,8,(IData)(vlSelfRef.alu_tb__DOT__tb_b),
                 8,vlSelfRef.alu_tb__DOT__tb_b,8,(0xffU 
                                                  & (IData)(vlSelfRef.alu_tb__DOT__tb_result)),
                 8,(0xffU & ((IData)(vlSelfRef.alu_tb__DOT__tb_result) 
                             >> 8U)));
    vlSelfRef.alu_tb__DOT__tb_a = 0x64U;
    vlSelfRef.alu_tb__DOT__tb_b = 7U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 9U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         139);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((0xeU != (0xffU & (IData)(vlSelfRef.alu_tb__DOT__tb_result))))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:140: Assertion failed in %Nalu_tb: DIV quotient failed\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("alu_tb.v", 140, "");
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((2U != (0xffU & ((IData)(vlSelfRef.alu_tb__DOT__tb_result) 
                                         >> 8U))))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:141: Assertion failed in %Nalu_tb: DIV remainder failed\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("alu_tb.v", 141, "");
        }
    }
    VL_WRITEF_NX("DIV test 2 passed %3# / %3# = %3#*%3# + %3#\n",0,
                 8,vlSelfRef.alu_tb__DOT__tb_a,8,(IData)(vlSelfRef.alu_tb__DOT__tb_b),
                 8,vlSelfRef.alu_tb__DOT__tb_b,8,(0xffU 
                                                  & (IData)(vlSelfRef.alu_tb__DOT__tb_result)),
                 8,(0xffU & ((IData)(vlSelfRef.alu_tb__DOT__tb_result) 
                             >> 8U)));
    vlSelfRef.alu_tb__DOT__tb_a = 0x32U;
    vlSelfRef.alu_tb__DOT__tb_b = 0U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 9U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         148);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelfRef.alu_tb__DOT__tb_div_by_zero))))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:149: Assertion failed in %Nalu_tb: DIV by zero flag not set\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("alu_tb.v", 149, "");
        }
    }
    VL_WRITEF_NX("DIV by zero flag correctly set\nZero flag %1#\n",0,
                 1,vlSelfRef.alu_tb__DOT__tb_zero_flag);
    vlSelfRef.alu_tb__DOT__tb_a = 0x30U;
    vlSelfRef.alu_tb__DOT__tb_b = 6U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 9U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         157);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((8U != (0xffU & (IData)(vlSelfRef.alu_tb__DOT__tb_result))))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:158: Assertion failed in %Nalu_tb: DIV quotient failed\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("alu_tb.v", 158, "");
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((0U != (0xffU & ((IData)(vlSelfRef.alu_tb__DOT__tb_result) 
                                         >> 8U))))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:159: Assertion failed in %Nalu_tb: DIV remainder should be 0\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("alu_tb.v", 159, "");
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY(vlSelfRef.alu_tb__DOT__tb_zero_flag)) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:160: Assertion failed in %Nalu_tb: Zero flag should be 0 (result is not zero)\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("alu_tb.v", 160, "");
        }
    }
    VL_WRITEF_NX("DIV test 3 passed %3# / %3# = %5#\n",0,
                 8,vlSelfRef.alu_tb__DOT__tb_a,8,(IData)(vlSelfRef.alu_tb__DOT__tb_b),
                 16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0xf0U;
    vlSelfRef.alu_tb__DOT__tb_b = 0xfU;
    vlSelfRef.alu_tb__DOT__tb_opcode = 0xaU;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         167);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((0U != (IData)(vlSelfRef.alu_tb__DOT__tb_result)))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:168: Assertion failed in %Nalu_tb: NOR failed\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("alu_tb.v", 168, "");
        }
    }
    VL_WRITEF_NX("NOR test passed ~(%02x | %02x) = %02x\n",0,
                 8,vlSelfRef.alu_tb__DOT__tb_a,8,(IData)(vlSelfRef.alu_tb__DOT__tb_b),
                 16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0xaaU;
    vlSelfRef.alu_tb__DOT__tb_b = 0x55U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 0xbU;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "alu_tb.v", 
                                         175);
    if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
        if (VL_UNLIKELY((0U != (IData)(vlSelfRef.alu_tb__DOT__tb_result)))) {
            VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:176: Assertion failed in %Nalu_tb: XNOR failed\n",0,
                         64,VL_TIME_UNITED_Q(1000),
                         -9,vlSymsp->name());
            VL_STOP_MT("alu_tb.v", 176, "");
        }
    }
    VL_WRITEF_NX("XNOR test passed ~(%02x ^ %02x) = %02x\n",0,
                 8,vlSelfRef.alu_tb__DOT__tb_a,8,(IData)(vlSelfRef.alu_tb__DOT__tb_b),
                 16,vlSelfRef.alu_tb__DOT__tb_result);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu_tb___024root___dump_triggers__act(Valu_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Valu_tb___024root___eval_triggers__act(Valu_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, vlSelfRef.__VdlySched.awaitingCurrentTime());
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Valu_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
