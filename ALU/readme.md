# ALU chip functionalities
- This chip supports functions like ADD(0), SUB(1), AND(2), OR(3), XOR(4), SHR(5), SHL(6), NAND(7), MUL(8), DIV(9), NOR(10) and XNOR(11)
- The (num) represents the operation code to call the respective function
- This module does not support signed operations so if u try to subratact a larger number from a smaller number or add two negative numbers this module wont provide the expected output

# How to run
- I used verilator to run this
- Step 1 -> "verilator -f make.f"
- Step 2 -> ".\obj_dir\Valu_tb" -> This will run it and create a .vcd file for waveform
- Feel free to change the configurations in the .v file or change the testbench to get ur desired input
- I used GTKWave to view the waveform