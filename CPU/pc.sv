`timescale 1ns/1ps
module pc (
    input  logic       clk,
    input  logic       rst,       // reset to address 0
    input  logic       inc,       // 1 = PC <= PC + 1 this cycle
    input  logic       load,      // 1 = PC <= load_addr this cycle
    input  logic [3:0] load_addr, // jump target, comes from the instruction operand
    output logic [3:0] pc_out
);

always_ff @(posedge clk) begin
    if(rst) begin
        pc_out <= 4'b0;
    end else begin 
        if(load) begin
            pc_out <= load_addr;
        end else begin
            if(inc) begin
                pc_out <= pc_out + 1;
            end
        end
    end
end

endmodule
