`timescale 1ns / 1ps

module alu (
    input  [7:0] a,              
    input  [7:0] b,              
    input  [3:0] sel,         
    output reg [15:0] out,             
    output reg    zero_flag,     
    output reg    div_by_zero    
);

always @(*) begin
    div_by_zero = 1'b0;  
    
    case (sel)
        4'b0000: begin  // ADD
            out[8:0] = a + b;
            out[15:9] = 7'b0;
        end
        4'b0001: begin  // SUBTRACT
            out = {8'b0, a} - {8'b0, b};
        end
        4'b0010: begin  // AND
            out = {8'b0, a & b};
        end
        4'b0011: begin  // OR
            out = {8'b0, a | b};
        end
        4'b0100: begin  // XOR
            out = {8'b0, a ^ b};
        end
        4'b0101: begin  // SHL
            out = {8'b0, a << 1};
        end
        4'b0110: begin  // SHR
            out = {8'b0, a >> 1};
        end
        4'b0111: begin  // NAND
            out = {8'b0, ~(a & b)};
        end
        4'b1000: begin  // MUL (8-bit × 8-bit = 16-bit)
            out = a * b;  
        end
        4'b1001: begin  // DIV (A ÷ B = Quotient | Remainder)
            if (b == 8'b0) begin
                out = 16'b0;
                div_by_zero = 1'b1;
            end else begin
                out[15:8] = a % b;  // Remainder in upper byte
                out[7:0] = a / b;   // Quotient in lower byte
                div_by_zero = 1'b0;
            end
        end
        4'b1010: begin // NOR
            out = {8'b0, ~(a|b)};
        end
        4'b1011: begin // XNOR
            out = {8'b0, ~(a^b)};
        end
        default: begin
            out = 16'b0;
        end
    endcase
    
    zero_flag = (out == 16'b0) ? 1'b1 : 1'b0;

end

endmodule
