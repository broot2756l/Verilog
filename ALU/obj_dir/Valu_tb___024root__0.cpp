// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu_tb.h for the primary calling header

#include "Valu_tb__pch.h"

VlCoroutine Valu_tb___024root___eval_initial__TOP__Vtiming__0(Valu_tb___024root* vlSelf);

void Valu_tb___024root___eval_initial(Valu_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_initial\n"); );
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Valu_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
}

VlCoroutine Valu_tb___024root___eval_initial__TOP__Vtiming__0(Valu_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("dump.vcd"s);
    vlSymsp->_traceDumpOpen();
    vlSelfRef.alu_tb__DOT__tb_a = 0xffU;
    vlSelfRef.alu_tb__DOT__tb_b = 0xffU;
    vlSelfRef.alu_tb__DOT__tb_opcode = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         29);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((0x01feU != (IData)(vlSelfRef.alu_tb__DOT__tb_result))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:35: Assertion failed in %m: ADD Failed\n",3, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("alu_tb.v", 35, "");
            }
        }
    }
    VL_WRITEF_NX("ADD test passed %d + %d = %d\n",3
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_a
                 , '#',8,(IData)(vlSelfRef.alu_tb__DOT__tb_b)
                 , '#',16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 5U;
    vlSelfRef.alu_tb__DOT__tb_b = 3U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         42);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((2U != (IData)(vlSelfRef.alu_tb__DOT__tb_result))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:43: Assertion failed in %m: SUB failed\n",3, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("alu_tb.v", 43, "");
            }
        }
    }
    VL_WRITEF_NX("SUB test passed %d - %d = %d\n",3
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_a
                 , '#',8,(IData)(vlSelfRef.alu_tb__DOT__tb_b)
                 , '#',16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0xffU;
    vlSelfRef.alu_tb__DOT__tb_b = 0x0fU;
    vlSelfRef.alu_tb__DOT__tb_opcode = 2U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         50);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((0x000fU != (IData)(vlSelfRef.alu_tb__DOT__tb_result))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:51: Assertion failed in %m: AND failed\n",3, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("alu_tb.v", 51, "");
            }
        }
    }
    VL_WRITEF_NX("AND test passed %02x & %02x = %02x\n",3
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_a
                 , '#',8,(IData)(vlSelfRef.alu_tb__DOT__tb_b)
                 , '#',16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0xf0U;
    vlSelfRef.alu_tb__DOT__tb_b = 0x0fU;
    vlSelfRef.alu_tb__DOT__tb_opcode = 3U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         58);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((0x00ffU != (IData)(vlSelfRef.alu_tb__DOT__tb_result))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:59: Assertion failed in %m: OR failed\n",3, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("alu_tb.v", 59, "");
            }
        }
    }
    VL_WRITEF_NX("OR test passed %02x | %02x = %02x\n",3
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_a
                 , '#',8,(IData)(vlSelfRef.alu_tb__DOT__tb_b)
                 , '#',16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0xaaU;
    vlSelfRef.alu_tb__DOT__tb_b = 0x55U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 4U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         66);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((0x00ffU != (IData)(vlSelfRef.alu_tb__DOT__tb_result))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:67: Assertion failed in %m: XOR failed\n",3, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("alu_tb.v", 67, "");
            }
        }
    }
    VL_WRITEF_NX("XOR test passed %02x ^ %02x = %02x\n",3
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_a
                 , '#',8,(IData)(vlSelfRef.alu_tb__DOT__tb_b)
                 , '#',16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 5U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 5U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         73);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((0x000aU != (IData)(vlSelfRef.alu_tb__DOT__tb_result))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:74: Assertion failed in %m: SHL failed\n",3, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("alu_tb.v", 74, "");
            }
        }
    }
    VL_WRITEF_NX("Left shift test passed %02x << 1 = %02x\n",2
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_a
                 , '#',16,(IData)(vlSelfRef.alu_tb__DOT__tb_result));
    vlSelfRef.alu_tb__DOT__tb_a = 5U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 6U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         80);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((2U != (IData)(vlSelfRef.alu_tb__DOT__tb_result))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:81: Assertion failed in %m: SHR failed\n",3, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("alu_tb.v", 81, "");
            }
        }
    }
    VL_WRITEF_NX("Right shift test passed %02x << 1 = %02x\n",2
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_a
                 , '#',16,(IData)(vlSelfRef.alu_tb__DOT__tb_result));
    vlSelfRef.alu_tb__DOT__tb_a = 0xffU;
    vlSelfRef.alu_tb__DOT__tb_b = 0x0fU;
    vlSelfRef.alu_tb__DOT__tb_opcode = 7U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         88);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((0x00f0U != (IData)(vlSelfRef.alu_tb__DOT__tb_result))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:89: Assertion failed in %m: NAND failed, expected 0xF0, got 0x%02x\n",4, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000)
                             , '#',16,(IData)(vlSelfRef.alu_tb__DOT__tb_result));
                VL_STOP_MT("alu_tb.v", 89, "");
            }
        }
    }
    VL_WRITEF_NX("NAND test passed ~(%02x & %02x) = %02x\n",3
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_a
                 , '#',8,(IData)(vlSelfRef.alu_tb__DOT__tb_b)
                 , '#',16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0U;
    vlSelfRef.alu_tb__DOT__tb_b = 0xffU;
    vlSelfRef.alu_tb__DOT__tb_opcode = 2U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         96);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.alu_tb__DOT__tb_zero_flag)))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:97: Assertion failed in %m: Zero flag failed\n",3, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("alu_tb.v", 97, "");
            }
        }
    }
    VL_WRITEF_NX("Zero flag check passed\n",0);
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         99);
    vlSelfRef.alu_tb__DOT__tb_a = 0x0aU;
    vlSelfRef.alu_tb__DOT__tb_b = 0x0cU;
    vlSelfRef.alu_tb__DOT__tb_opcode = 8U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         105);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((0x0078U != (IData)(vlSelfRef.alu_tb__DOT__tb_result))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:106: Assertion failed in %m: MUL failed: expected 120, got %d\n",4, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000)
                             , '#',16,(IData)(vlSelfRef.alu_tb__DOT__tb_result));
                VL_STOP_MT("alu_tb.v", 106, "");
            }
        }
    }
    VL_WRITEF_NX("MUL test passed %d x %d = %d\n",3
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_a
                 , '#',8,(IData)(vlSelfRef.alu_tb__DOT__tb_b)
                 , '#',16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0xc8U;
    vlSelfRef.alu_tb__DOT__tb_b = 2U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 8U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         113);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((0x0190U != (IData)(vlSelfRef.alu_tb__DOT__tb_result))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:114: Assertion failed in %m: MUL overflow failed: expected 400, got %d\n",4, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000)
                             , '#',16,(IData)(vlSelfRef.alu_tb__DOT__tb_result));
                VL_STOP_MT("alu_tb.v", 114, "");
            }
        }
    }
    VL_WRITEF_NX("MUL overflow test passed %d x %d = %d\n",3
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_a
                 , '#',8,(IData)(vlSelfRef.alu_tb__DOT__tb_b)
                 , '#',16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0xffU;
    vlSelfRef.alu_tb__DOT__tb_b = 0xffU;
    vlSelfRef.alu_tb__DOT__tb_opcode = 8U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         121);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((0xfe01U != (IData)(vlSelfRef.alu_tb__DOT__tb_result))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:122: Assertion failed in %m: MUL max failed: expected 65025, got %d\n",4, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000)
                             , '#',16,(IData)(vlSelfRef.alu_tb__DOT__tb_result));
                VL_STOP_MT("alu_tb.v", 122, "");
            }
        }
    }
    VL_WRITEF_NX("MUL max test passed %d x %d = %d\n",3
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_a
                 , '#',8,(IData)(vlSelfRef.alu_tb__DOT__tb_b)
                 , '#',16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0x19U;
    vlSelfRef.alu_tb__DOT__tb_b = 4U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 9U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         129);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((6U != (0x000000ffU & (IData)(vlSelfRef.alu_tb__DOT__tb_result)))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:131: Assertion failed in %m: DIV quotient failed: expected 6, got %d\n",4, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000)
                             , '#',8,(0x000000ffU & (IData)(vlSelfRef.alu_tb__DOT__tb_result)));
                VL_STOP_MT("alu_tb.v", 131, "");
            }
            if (VL_UNLIKELY(((1U != (0x000000ffU & 
                                     ((IData)(vlSelfRef.alu_tb__DOT__tb_result) 
                                      >> 8U)))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:132: Assertion failed in %m: DIV remainder failed: expected 1, got %d\n",4, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000)
                             , '#',8,(0x000000ffU & 
                                      ((IData)(vlSelfRef.alu_tb__DOT__tb_result) 
                                       >> 8U)));
                VL_STOP_MT("alu_tb.v", 132, "");
            }
        }
    }
    VL_WRITEF_NX("DIV test 1 passed %d / %d = %d*%d + %d\n",5
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_a
                 , '#',8,(IData)(vlSelfRef.alu_tb__DOT__tb_b)
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_b
                 , '#',8,(0x000000ffU & (IData)(vlSelfRef.alu_tb__DOT__tb_result))
                 , '#',8,(0x000000ffU & ((IData)(vlSelfRef.alu_tb__DOT__tb_result) 
                                         >> 8U)));
    vlSelfRef.alu_tb__DOT__tb_a = 0x64U;
    vlSelfRef.alu_tb__DOT__tb_b = 7U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 9U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         139);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((0x0eU != (0x000000ffU 
                                        & (IData)(vlSelfRef.alu_tb__DOT__tb_result)))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:140: Assertion failed in %m: DIV quotient failed\n",3, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("alu_tb.v", 140, "");
            }
            if (VL_UNLIKELY(((2U != (0x000000ffU & 
                                     ((IData)(vlSelfRef.alu_tb__DOT__tb_result) 
                                      >> 8U)))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:141: Assertion failed in %m: DIV remainder failed\n",3, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("alu_tb.v", 141, "");
            }
        }
    }
    VL_WRITEF_NX("DIV test 2 passed %d / %d = %d*%d + %d\n",5
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_a
                 , '#',8,(IData)(vlSelfRef.alu_tb__DOT__tb_b)
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_b
                 , '#',8,(0x000000ffU & (IData)(vlSelfRef.alu_tb__DOT__tb_result))
                 , '#',8,(0x000000ffU & ((IData)(vlSelfRef.alu_tb__DOT__tb_result) 
                                         >> 8U)));
    vlSelfRef.alu_tb__DOT__tb_a = 0x32U;
    vlSelfRef.alu_tb__DOT__tb_b = 0U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 9U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         148);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.alu_tb__DOT__tb_div_by_zero)))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:149: Assertion failed in %m: DIV by zero flag not set\n",3, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("alu_tb.v", 149, "");
            }
        }
    }
    VL_WRITEF_NX("DIV by zero flag correctly set\nZero flag %d\n",1
                 , '#',1,vlSelfRef.alu_tb__DOT__tb_zero_flag);
    vlSelfRef.alu_tb__DOT__tb_a = 0x30U;
    vlSelfRef.alu_tb__DOT__tb_b = 6U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 9U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         157);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((8U != (0x000000ffU & (IData)(vlSelfRef.alu_tb__DOT__tb_result)))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:158: Assertion failed in %m: DIV quotient failed\n",3, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("alu_tb.v", 158, "");
            }
            if (VL_UNLIKELY(((0U != (0x000000ffU & 
                                     ((IData)(vlSelfRef.alu_tb__DOT__tb_result) 
                                      >> 8U)))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:159: Assertion failed in %m: DIV remainder should be 0\n",3, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("alu_tb.v", 159, "");
            }
            if (VL_UNLIKELY((vlSelfRef.alu_tb__DOT__tb_zero_flag))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:160: Assertion failed in %m: Zero flag should be 0 (result is not zero)\n",3, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("alu_tb.v", 160, "");
            }
        }
    }
    VL_WRITEF_NX("DIV test 3 passed %d / %d = %d\n",3
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_a
                 , '#',8,(IData)(vlSelfRef.alu_tb__DOT__tb_b)
                 , '#',16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0xf0U;
    vlSelfRef.alu_tb__DOT__tb_b = 0x0fU;
    vlSelfRef.alu_tb__DOT__tb_opcode = 0x0aU;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         167);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.alu_tb__DOT__tb_result))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:168: Assertion failed in %m: NOR failed\n",3, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("alu_tb.v", 168, "");
            }
        }
    }
    VL_WRITEF_NX("NOR test passed ~(%02x | %02x) = %02x\n",3
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_a
                 , '#',8,(IData)(vlSelfRef.alu_tb__DOT__tb_b)
                 , '#',16,vlSelfRef.alu_tb__DOT__tb_result);
    vlSelfRef.alu_tb__DOT__tb_a = 0xaaU;
    vlSelfRef.alu_tb__DOT__tb_b = 0x55U;
    vlSelfRef.alu_tb__DOT__tb_opcode = 0x0bU;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "alu_tb.v", 
                                         175);
    if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_ON, 2, 1)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON, 2, 1)) {
            if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.alu_tb__DOT__tb_result))))) {
                VL_WRITEF_NX("[%0t] %%Error: alu_tb.v:176: Assertion failed in %m: XNOR failed\n",3, 'M',vlSymsp->name(),"alu_tb", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("alu_tb.v", 176, "");
            }
        }
    }
    VL_WRITEF_NX("XNOR test passed ~(%02x ^ %02x) = %02x\n",3
                 , '#',8,vlSelfRef.alu_tb__DOT__tb_a
                 , '#',8,(IData)(vlSelfRef.alu_tb__DOT__tb_b)
                 , '#',16,vlSelfRef.alu_tb__DOT__tb_result);
    co_return;
}

bool Valu_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Valu_tb___024root___act_sequent__TOP__0(Valu_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___act_sequent__TOP__0\n"); );
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.alu_tb__DOT__tb_div_by_zero = 0U;
    if ((8U & (IData)(vlSelfRef.alu_tb__DOT__tb_opcode))) {
        if ((1U & (~ ((IData)(vlSelfRef.alu_tb__DOT__tb_opcode) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.alu_tb__DOT__tb_opcode) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.alu_tb__DOT__tb_opcode))) {
                    vlSelfRef.alu_tb__DOT__tb_div_by_zero 
                        = (0U == (IData)(vlSelfRef.alu_tb__DOT__tb_b));
                }
            }
        }
        vlSelfRef.alu_tb__DOT__tb_result = (0x0000ffffU 
                                            & ((4U 
                                                & (IData)(vlSelfRef.alu_tb__DOT__tb_opcode))
                                                ? 0U
                                                : (
                                                   (2U 
                                                    & (IData)(vlSelfRef.alu_tb__DOT__tb_opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.alu_tb__DOT__tb_opcode))
                                                     ? 
                                                    (0x000000ffU 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.alu_tb__DOT__tb_a) 
                                                         ^ (IData)(vlSelfRef.alu_tb__DOT__tb_b))))
                                                     : 
                                                    (0x000000ffU 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.alu_tb__DOT__tb_a) 
                                                         | (IData)(vlSelfRef.alu_tb__DOT__tb_b)))))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.alu_tb__DOT__tb_opcode))
                                                     ? 
                                                    ((0U 
                                                      == (IData)(vlSelfRef.alu_tb__DOT__tb_b))
                                                      ? 0U
                                                      : 
                                                     ((0x0000ff00U 
                                                       & (VL_MODDIV_III(8, (IData)(vlSelfRef.alu_tb__DOT__tb_a), (IData)(vlSelfRef.alu_tb__DOT__tb_b)) 
                                                          << 8U)) 
                                                      | (0x000000ffU 
                                                         & VL_DIV_III(8, (IData)(vlSelfRef.alu_tb__DOT__tb_a), (IData)(vlSelfRef.alu_tb__DOT__tb_b)))))
                                                     : 
                                                    ((IData)(vlSelfRef.alu_tb__DOT__tb_a) 
                                                     * (IData)(vlSelfRef.alu_tb__DOT__tb_b))))));
    } else {
        vlSelfRef.alu_tb__DOT__tb_result = (0x0000ffffU 
                                            & ((4U 
                                                & (IData)(vlSelfRef.alu_tb__DOT__tb_opcode))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlSelfRef.alu_tb__DOT__tb_opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.alu_tb__DOT__tb_opcode))
                                                     ? 
                                                    (0x000000ffU 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.alu_tb__DOT__tb_a) 
                                                         & (IData)(vlSelfRef.alu_tb__DOT__tb_b))))
                                                     : 
                                                    ((IData)(vlSelfRef.alu_tb__DOT__tb_a) 
                                                     >> 1U))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.alu_tb__DOT__tb_opcode))
                                                     ? 
                                                    (0x000000ffU 
                                                     & ((IData)(vlSelfRef.alu_tb__DOT__tb_a) 
                                                        << 1U))
                                                     : 
                                                    ((IData)(vlSelfRef.alu_tb__DOT__tb_a) 
                                                     ^ (IData)(vlSelfRef.alu_tb__DOT__tb_b))))
                                                : (
                                                   (2U 
                                                    & (IData)(vlSelfRef.alu_tb__DOT__tb_opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.alu_tb__DOT__tb_opcode))
                                                     ? 
                                                    ((IData)(vlSelfRef.alu_tb__DOT__tb_a) 
                                                     | (IData)(vlSelfRef.alu_tb__DOT__tb_b))
                                                     : 
                                                    ((IData)(vlSelfRef.alu_tb__DOT__tb_a) 
                                                     & (IData)(vlSelfRef.alu_tb__DOT__tb_b)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.alu_tb__DOT__tb_opcode))
                                                     ? 
                                                    ((IData)(vlSelfRef.alu_tb__DOT__tb_a) 
                                                     - (IData)(vlSelfRef.alu_tb__DOT__tb_b))
                                                     : 
                                                    (0x000001ffU 
                                                     & ((IData)(vlSelfRef.alu_tb__DOT__tb_a) 
                                                        + (IData)(vlSelfRef.alu_tb__DOT__tb_b)))))));
    }
    vlSelfRef.alu_tb__DOT__tb_zero_flag = (0U == (IData)(vlSelfRef.alu_tb__DOT__tb_result));
}

void Valu_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Valu_tb___024root___eval_phase__act(Valu_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_phase__act\n"); );
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(vlSelfRef.__VdlySched.awaitingCurrentTime()));
    }
    Valu_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Valu_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Valu_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Valu_tb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        {
            // Inlined CFunc: _timing_resume
            if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
                vlSelfRef.__VdlySched.resume();
            }
        }
        {
            // Inlined CFunc: _eval_act
            if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
                Valu_tb___024root___act_sequent__TOP__0(vlSelf);
            }
        }
    }
    return (__VactExecute);
}

bool Valu_tb___024root___eval_phase__inact(Valu_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_phase__inact\n"); );
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("alu_tb.v", 3, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Valu_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Valu_tb___024root___eval_phase__nba(Valu_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_phase__nba\n"); );
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Valu_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Valu_tb___024root___act_sequent__TOP__0(vlSelf);
            }
        }
        Valu_tb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Valu_tb___024root___eval(Valu_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval\n"); );
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Valu_tb___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("alu_tb.v", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("alu_tb.v", 3, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Valu_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("alu_tb.v", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Valu_tb___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Valu_tb___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Valu_tb___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Valu_tb___024root___eval_debug_assertions(Valu_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_tb___024root___eval_debug_assertions\n"); );
    Valu_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
