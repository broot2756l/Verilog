# RV32I Quick Reference (Phase 0)

## Big picture
- CPU loop: fetch instruction -> figure out what it means -> do it -> repeat.
- ISA = the rulebook. Microarchitecture = the hardware built to follow it.
- RV32I = base rulebook (32-bit). Extensions are add-ons: M mul/div, A atomics,
  F/D floating point, C short instructions, Zicsr control registers.

## Where data lives
- 32 registers, x0-x31, 32 bits each: small and fast, inside the CPU.
- Memory: huge and slower, outside the register file.
- pc: address of the current instruction. Usually pc + 4 next (each instruction is 4 bytes).
- No accumulator and no flags.
- x0 always reads 0; writes to it vanish.
- Only load/store instructions touch memory. Math uses registers and immediates.

## Register nicknames
zero = x0 | ra = x1 (return address) | sp = x2 (stack pointer)
a0-a7 = x10-x17 (function inputs/outputs)
t0-t6 = scratch (x5-7, x28-31) | s0-s11 = must be preserved (x8-9, x18-27)

## Ports
- Read port = reads 1 register per cycle. Write port = writes 1 register per cycle.
- Register file: 32 registers, 2 read ports, 1 write port.
- Why 2 reads: one instruction can need two source registers at the same time.

## Instruction fields (every instruction is 32 bits)
- opcode [6:0]: what family of instruction
- rd [11:7]: destination register (5 bits = picks 1 of 32)
- funct3 [14:12]: which operation within the family
- rs1 [19:15]: first source register
- rs2 [24:20]: second source register
- funct7 [31:25]: extra operation selector (add vs sub)
- imm: a number stored inside the instruction

## The six formats
```
       31      25 24  20 19  15 14 12 11      7 6     0
R    | funct7    | rs2  | rs1  | f3  | rd      | opcode |  add x5, x6, x7
I    | imm[11:0]        | rs1  | f3  | rd      | opcode |  addi, lw, jalr
S    | imm[11:5] | rs2  | rs1  | f3  | imm[4:0]| opcode |  sw
B    | imm (split)| rs2 | rs1  | f3  | imm     | opcode |  beq, bne
U    | imm[31:12]                    | rd      | opcode |  lui, auipc
J    | imm (scrambled)               | rd      | opcode |  jal
```
| Format | Needs | Example |
|---|---|---|
| R | 2 reads, 1 write | add |
| I | 1 read, 1 write, number | addi, lw |
| S | 2 reads, number | sw |
| B | 2 reads, jump distance | beq |
| U | 1 write, big number | lui |
| J | 1 write, big jump distance | jal |

## Why the layout looks odd
- rs1, rs2 and rd stay in the same bits, so hardware can read registers before decoding finishes.
- S and B need rs2 at [24:20], so their immediate splits around it.
- Immediate sign bit is always inst[31].
- B and J skip imm[0]: jump targets are always even.

## Opcodes
| opcode | Family | Format |
|---|---|---|
| 0110011 | OP | R |
| 0010011 | OP-IMM | I |
| 0000011 | LOAD | I |
| 0100011 | STORE | S |
| 1100011 | BRANCH | B |
| 1101111 | JAL | J |
| 1100111 | JALR | I |
| 0110111 | LUI | U |
| 0010111 | AUIPC | U |

## Handy instructions
| Instruction | Meaning |
|---|---|
| add x5, x6, x7 | x5 = x6 + x7 |
| addi x5, x6, 10 | x5 = x6 + 10 |
| lw x5, 8(x6) | x5 = memory[x6 + 8] |
| sw x5, 8(x6) | memory[x6 + 8] = x5 |
| beq x5, x6, label | if x5 == x6, jump to label |
| bne x5, x6, label | if x5 != x6, jump to label |
| slt x7, x5, x6 | x7 = 1 if x5 < x6, else 0 |
| jal ra, label | ra = return address, then jump |

## Pseudo-instructions (shortcuts that use x0)
nop = addi x0, x0, 0 | mv a0, a1 = addi a0, a1, 0
li a0, 10 = addi a0, x0, 10 | j label = jal x0, label

## Compared with my 4-bit CPU
| 4-bit CPU | RV32I |
|---|---|
| 8-bit instruction | 32-bit instruction |
| 1 register (ACC) | 32 registers |
| ACC is implied | Every register is named |
| Z/C flags + JZ/JC | beq/bne/..., or slt into a register |
| ADD can read RAM | Only lw/sw-style instructions touch memory |
| JMP | j (really jal x0, label) |

## Worked examples
- add x5, x6, x7 = 0000000 00111 00110 000 00101 0110011 = 0x007302B3
- addi a0, x0, 10 = 000000001010 00000 000 01010 0010011 = 0x00A00513
- sw x6, 8(x5) = 0000000 00110 00101 010 01000 0100011 = 0x0062A423
