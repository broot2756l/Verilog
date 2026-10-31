# Phase 0 · Lesson 0.1 — RISC-V Overview, Registers, Instruction Formats

Date: 2026-10-29 · Reference design: my 4-bit accumulator CPU (`../CPU/`)

---

## 1. What RISC-V is

- An **ISA** (Instruction Set Architecture) is the contract between software and hardware:
  which instructions exist, how they are encoded, and what state the programmer can see.
- A **microarchitecture** is one way of building hardware that obeys that contract
  (single-cycle, multi-cycle, pipelined, ...). RISC-V is only the contract.
- My 4-bit CPU had an ISA too: 16 opcodes, ACC, Z/C flags, PC.
- RISC-V: UC Berkeley, 2010. **Open** — anyone can implement it without a license
  (hence open cores like PicoRV32, Ibex, CVA6).
- **Modular**: a small base ISA + optional extensions.

| Name | Adds |
|---|---|
| **RV32I** | Base integer ISA, 32-bit registers, ~40 instructions — *what I am building* |
| M | Multiply / divide |
| A | Atomics (multi-core synchronization) |
| F / D | Single / double-precision floating point |
| C | Compressed 16-bit instructions |
| Zicsr | Control & status register instructions (needed for traps/interrupts) |
| G | Shorthand for IMAFD + Zicsr + Zifencei ("general purpose", what Linux expects) |

A core is named base + extensions, e.g. `RV32IMC`.

---

## 2. Programmer's model & register file

RV32I architectural state: **32 registers `x0`–`x31` (32 bits each) + `pc`.**
No flags. No accumulator.

### Contrast with my 4-bit CPU

| | 4-bit CPU | RV32I |
|---|---|---|
| Working storage | 1 register (ACC) | 32 registers |
| Operand naming | Implicit — `ADD` = ACC ← ACC + mem | Explicit — `add rd, rs1, rs2` |
| Conditions | Z/C flags set by ALU, read by `JZ`/`JC` | No flags. `beq x5, x6, label` compares + branches in one instruction; `slt` writes 0/1 into a register |
| Memory access | ALU ops could read RAM directly (`ADD`, `ANDM`) | **Load/store architecture** — only loads/stores touch memory; ALU sees only registers and immediates |

### Register file ports

Lockers model: the register file is 32 lockers, a read port is a window that shows one locker
at a time, and a write port is a drop slot. 32 registers does not mean 32 ports.

`add x5, x6, x7` reads x6 and x7 in the same cycle and writes x5, so the register file needs
2 read ports and 1 write port. The 4-bit CPU's ACC was one register wired straight to the ALU,
so nothing had to be selected and no read port was needed.

### x0 is hardwired to zero

Reads always return 0; writes are discarded. This gives many **pseudo-instructions** for free:

| Pseudo | Real instruction |
|---|---|
| `mv a0, a1` | `addi a0, a1, 0` |
| `nop` | `addi x0, x0, 0` |
| `li a0, 10` (small) | `addi a0, x0, 10` |
| `j label` | `jal x0, label` (jump, discard return address) |

Hardware consequence: the register file must enforce this rule (Phase 1, first module).

### ABI register names

Hardware treats x1–x31 identically; the **calling convention** assigns roles.

| Register | ABI name | Role | Saved by |
|---|---|---|---|
| x0 | zero | constant 0 | – |
| x1 | ra | return address | caller |
| x2 | sp | stack pointer | callee |
| x3 | gp | global pointer | – |
| x4 | tp | thread pointer | – |
| x5–x7 | t0–t2 | temporaries | caller |
| x8 | s0 / fp | saved / frame pointer | callee |
| x9 | s1 | saved | callee |
| x10–x11 | a0–a1 | args / return values | caller |
| x12–x17 | a2–a7 | args | caller |
| x18–x27 | s2–s11 | saved | callee |
| x28–x31 | t3–t6 | temporaries | caller |

Must know now: `zero`, `ra`, `sp`, `a0–a7`; `t` = scratch, `s` = must be preserved.

---

## 3. The six instruction formats

All RV32I instructions are **32 bits, fixed width**.
(My CPU: 8 bits = `[7:4]` opcode + `[3:0]` operand.)

```
          31        25 24   20 19   15 14  12 11        7 6      0
R-type  | funct7     | rs2   | rs1   |funct3| rd         | opcode |   add  rd, rs1, rs2
I-type  | imm[11:0]          | rs1   |funct3| rd         | opcode |   addi, lw, jalr
S-type  | imm[11:5]  | rs2   | rs1   |funct3| imm[4:0]   | opcode |   sw
B-type  |imm[12|10:5]| rs2   | rs1   |funct3|imm[4:1|11] | opcode |   beq
U-type  | imm[31:12]                        | rd         | opcode |   lui, auipc
J-type  | imm[20|10:1|11|19:12]             | rd         | opcode |   jal
```

### Three key design decisions

1. **rs1 / rs2 / rd are always in the same bit positions.**
   `inst[19:15]` and `inst[24:20]` can go straight into the register file read ports
   *before* decoding finishes. If a format doesn't use rs2, that read is just ignored.
   Decode and register read happen in parallel, which shortens the critical path.
2. **The immediate's sign bit is always `inst[31]`**, in every format, so sign extension
   can also start before decode.
3. **S/B/J "scrambling" is deliberate.**
   - S can't use `[31:20]` like I-type, because rs2 occupies `[24:20]`. So it splits
     the immediate around the register fields, keeping bits in the same positions as I-type.
   - B is S with bits shuffled so most bits still line up with S; J does the same relative to U/I.
   - Result: each immediate bit comes from only a few possible instruction bits, so the
     immediate generator needs only small muxes.
   - B and J don't store `imm[0]`: targets are always even (2-byte aligned, which the
     C extension needs), so the bit would be wasted.

> Ugly for the assembler writer once; cheaper hardware on every instruction.

### Opcode cheat sheet (`inst[6:0]`; `inst[1:0]` = `11` for all 32-bit instructions)

| opcode | Name | Format |
|---|---|---|
| 0110011 | OP (add, sub, and, slt, ...) | R |
| 0010011 | OP-IMM (addi, andi, slli, ...) | I |
| 0000011 | LOAD | I |
| 0100011 | STORE | S |
| 1100011 | BRANCH | B |
| 1101111 | JAL | J |
| 1100111 | JALR | I |
| 0110111 | LUI | U |
| 0010111 | AUIPC | U |

---

## 4. Worked encodings

**`add x5, x6, x7`** — R-type, opcode `0110011`, funct3 `000`, funct7 `0000000`

```
funct7   rs2    rs1    f3   rd     opcode
0000000  00111  00110  000  00101  0110011
→ 0000 0000 0111 0011 0000 0010 1011 0011 = 0x007302B3
```

**`addi x1, x0, 5`** — I-type, opcode `0010011`, funct3 `000`

```
imm[11:0]     rs1    f3   rd     opcode
000000000101  00000  000  00001  0010011
→ 0x00500093
```

Tip: regroup the 32 bits into nibbles **from the right**. That's where most
hand-encoding mistakes happen.

---

## 5. Sources

- RISC-V Unprivileged ISA spec, Ch. 2 "RV32I Base Integer Instruction Set":
  §2.1 programmer's model, §2.2 base instruction formats, §2.3 immediate encoding variants.
  <https://github.com/riscv/riscv-isa-manual/releases>
- ABI register names: RISC-V ELF psABI —
  <https://github.com/riscv-non-isa/riscv-elf-psabi-doc>
- Harris & Harris, *Digital Design and Computer Architecture, RISC-V Edition*:
  Ch. 6 (Architecture) — §6.3 Programming (calling convention), §6.4 Machine Language (formats);
  Appendix B (full encoding table).
