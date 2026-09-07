`timescale 1ns / 1ps

module alu (
    input  logic [3:0] a,       
    input  logic [3:0] b,       
    input  logic [2:0] op,      
    output logic [3:0] result,  
    output logic       zero,    
    output logic       carry    
);

always_comb begin
    case (op)
        3'b000: begin // ADD
            {carry, result} = a + b;
        end
        3'b001: begin // SUBTRACT
            {carry, result} = a - b;
        end
        3'b010: begin // AND
            result = a & b;
            carry  = 1'b0;
        end
        3'b011: begin // OR
            result = a | b;
            carry  = 1'b0;
        end
        3'b100: begin // XOR
            result = a^b;
            carry  = 1'b0;
        end
        3'b101: begin // NOT
            result = ~a;
            carry  = 1'b0;
        end
        3'b110: begin // pass-through
            result = a;
            carry  = 1'b0;
        end
        default: begin
            result = 4'b0;
            carry  = 1'b0;
        end
    endcase

    zero = (result == 4'b0) ? 1'b1 : 1'b0;

end

endmodule
