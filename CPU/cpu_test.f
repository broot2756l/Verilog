// Source files
alu.sv
acc_flags.sv
pc.sv
instr_rom.sv
instr_reg.sv
data_ram.sv
control_unit.sv
cpu_top.sv
cpu_tb.sv

// Top module
--top-module cpu_tb

// Options
--binary
--trace
--assert
--timing

// Warnings
--Wno-WIDTH
--Wno-UNUSED
--Wno-CASEINCOMPLETE
