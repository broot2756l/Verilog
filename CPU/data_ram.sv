`timescale 1ns/1ps

module data_ram (
    input  logic       clk,
    input  logic       we,        // write-enable
    input  logic [3:0] addr,
    input  logic [3:0] data_in,
    output logic [3:0] data_out
);

    logic [3:0] ram [0:15];   // 16 slots, 4 bits each — same array idea as the ROM

    always_ff @(posedge clk) begin
        if (we) begin
            ram[addr] <= data_in;   // only writes when we==1, otherwise holds automatically
        end
    end

    assign data_out = ram[addr];   // combinational read, same idea as ROM

endmodule