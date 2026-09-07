# 4-bit CPU in SystemVerilog

A 4-bit CPU built from scratch in SystemVerilog, module by module, as a self-study project during my Electronics and Computer Engineering (ECE) degree — first-year college student, learning digital design and Verilog on my own through HDLBits and projects like this one.

## Overview

- **Architecture:** Accumulator-based, Harvard architecture (separate instruction ROM and data RAM)
- **Datapath width:** 4 bits (ACC, RAM, operands); Instructions are 8 bits (4-bit opcode + 4-bit operand)
- **Control:** A 3-state FSM — `FETCH → EXECUTE → HALT`. Memory reads are combinational, so each instruction only costs 2 clock cycles.
- **Flags:** Zero (Z) and Carry (C), updated by ALU operations and used for conditional jumps

## Modules

| File | Role |
|---|---|
| `alu.sv` | Combinational ALU — add, sub, and, or, xor, not, pass-through |
| `acc_flags.sv` | Accumulator register + Z/C flag register |
| `pc.sv` | Program counter (reset, increment, load) |
| `instr_rom.sv` | 16×8 instruction memory, loaded from a `.hex` file |
| `data_ram.sv` | 16×4 read/write data memory (no reset — matches real hardware) |
| `instr_reg.sv` | Latches the fetched instruction, splits it into opcode/operand |
| `control_unit.sv` | The FSM — decodes each opcode into control signals |
| `cpu_top.sv` | Wires all of the above together |

## Instruction set

| Hex | Mnemonic | Meaning |
|---|---|---|
| 0 | NOP | do nothing |
| 1 | LDA | ACC ← RAM[operand] |
| 2 | LDI | ACC ← operand (immediate) |
| 3 | STA | RAM[operand] ← ACC |
| 4 | ADD | ACC ← ACC + RAM[operand] |
| 5 | SUB | ACC ← ACC − RAM[operand] |
| 6 | ADI | ACC ← ACC + operand |
| 7 | SBI | ACC ← ACC − operand |
| 8 | ANDM | ACC ← ACC & RAM[operand] |
| 9 | ORM | ACC ← ACC \| RAM[operand] |
| A | XORM | ACC ← ACC ^ RAM[operand] |
| B | NOT | ACC ← ~ACC |
| C | JMP | PC ← operand |
| D | JZ | PC ← operand, if Z flag set |
| E | JC | PC ← operand, if C flag set |
| F | HLT | stop |

## Running the tests

```bash
# Verilator
verilator -f cpu_test.f && ./obj_dir/Vcpu_tb
```

## Test programs

| Program | Tests | Expected result |
|---|---|---|
| `prog_add.hex` | LDI, STA, ADD, HLT | ACC = 7 (3 + 4) |
| `prog_loop.hex` | SBI, JZ, JMP — countdown loop | ACC = 0, RAM[14] = 1 |
| `prog_carry.hex` | ADI, JC — carry-triggered branch | ACC = 9 |
| `prog_evenodd.hex` | ANDM, JZ — even/odd check | ACC = 1 (6 is even) |

`cpu_tb.sv` runs all of them and checks the final results with `assert`.

## Notes

- No AND/OR/XOR-immediate exists in this ISA — constants have to be built in RAM first with `LDI` + `STA`.
- Passing a `parameter string` (like the `.hex` filename) through more than one level of module hierarchy doesn't elaborate in Icarus Verilog 12.0, but works fine in Verilator — this project targets Verilator.