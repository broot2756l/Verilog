`timescale 1ns/1ps
module instr_rom #(
    parameter string MEMFILE = "program.hex"
) (
    input  logic [3:0] addr,
    output logic [7:0] instr
);

    logic [7:0] rom [0:15];   // 16 slots, 8 bits each — this line IS the memory

    initial begin
        $readmemh(MEMFILE, rom);   // load contents once, before simulation starts
    end

    assign instr = rom[addr];   // read is just a lookup, no clock needed

endmodule