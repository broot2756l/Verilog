# RISC-V RV32I Learning Log

Reference design: my 4-bit accumulator CPU in `../CPU/`.
Toolchain: Verilator 5 (`--binary --trace`), GTKWave, pure SV testbenches.

## Where we are
- **Current phase:** Phase 0 – The ISA on paper
- **Current lesson:** 0.1 – RISC-V overview, register file, six instruction formats
- **Next:** Answer Quiz 0.1 → Lesson 0.2 (immediate encoding in detail) → encode/decode exercise

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

**Quiz 0.1:** asked, awaiting answers.

**Mistakes / lessons**
- (none yet)

## Open questions
- (none yet)
