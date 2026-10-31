# RISC-V RV32I Learning Log

Reference design: my 4-bit accumulator CPU in `../CPU/`.
Toolchain: Verilator 5 (`--binary --trace`), GTKWave, pure SV testbenches.

## Where we are
- **Current phase:** Phase 0 – The ISA on paper
- **Current lesson:** 0.1 – RISC-V overview, register file, six instruction formats
- **Next:** Lesson 0.2 (immediate encoding in detail) → encode/decode exercise

## Phases
| Phase | Topic | Status |
|---|---|---|
| 0 | ISA on paper | in progress |
| 1 | Building blocks (regfile, ALU, immgen) | – |
| 2 | Single-cycle RV32I core | – |
| 3 | Verification | – |
| 4 | Multi-cycle core (optional) | – |
| 5 | 5-stage pipeline | – |
| 6 | Beyond the base core | – |

## Sessions

### 2026-10-29 — Session 1
**Covered**
- What RISC-V is; base ISA vs. extensions (I, M, A, F, D, C, Zicsr, G).
- RV32I programmer's model: x0–x31, x0 hardwired to 0, pc; ABI names.
- Six formats R/I/S/B/U/J; fixed rd/rs1/rs2 positions; sign bit always inst[31].
- Worked encodings: `add x5,x6,x7` = 0x007302B3, `addi x1,x0,5` = 0x00500093.

**Notes:** [docs/phase0_lesson01_isa_overview.md](docs/phase0_lesson01_isa_overview.md)

**Quick reference:** [docs/phase0_quick_reference.md](docs/phase0_quick_reference.md)

**Mistakes / lessons**
- Confused *number of registers* (32) with *number of read ports* (registers read
  simultaneously). Also counted only `x5` as an operand. `add x5,x6,x7` has three register
  operands: rd = x5 (written), rs1 = x6 and rs2 = x7 (read).
  → The "lockers + windows" analogy made this click.

## Open questions
- (none yet)
