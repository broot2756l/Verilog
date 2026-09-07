`timescale 1ns/1ps

module acc_flags (
    input  logic       clk,
    input  logic       rst,        // reset to 0
    input  logic       load_acc,   // 1 = capture data_in into ACC this cycle
    input  logic       load_flags, // 1 = capture zero_in/carry_in this cycle
    input  logic [3:0] data_in,    // comes from the ALU (or elsewhere, later)
    input  logic       zero_in,
    input  logic       carry_in,
    output logic [3:0] acc,
    output logic       zero_flag,
    output logic       carry_flag
);

always_ff @(posedge clk) begin  // Always use <= in a always_ff block and use = in a always_comb block

    if(rst) begin
        acc <= 3'b0;
        zero_flag <= 1'b0;
        carry_flag <= 1'b0;
    end else begin
        if(load_acc) begin
            acc <= data_in;
        end
        if(load_flags) begin
            zero_flag <= zero_in;
            carry_flag <= carry_in;
        end
    end

end

endmodule
