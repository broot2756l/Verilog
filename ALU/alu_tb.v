`timescale 1ns / 1ps

module alu_tb;

    reg  [7:0] tb_a;
    reg  [7:0] tb_b;
    reg  [3:0] tb_opcode;         
    wire [15:0] tb_result;        
    wire        tb_zero_flag;
    wire        tb_div_by_zero;   
    
    alu uut (
        .a(tb_a),
        .b(tb_b),
        .sel(tb_opcode),
        .out(tb_result),
        .zero_flag(tb_zero_flag),
        .div_by_zero(tb_div_by_zero)
    );
    
    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(0, alu_tb);
        
        // Test : ADD 
        tb_a = 8'd255;
        tb_b = 8'd255;
        tb_opcode = 4'b0000;
        #10;
        // if (tb_result == 9'd510) begin
        //     $display("Test 1 PASSED: ADD 255 + 255 = %d", tb_result);
        // end else begin
        //     $display("ADD failed");
        // end
        assert (tb_result == 9'd510) else $error("ADD Failed");
        $display("ADD test passed %d + %d = %d", tb_a, tb_b, tb_result);

        // Test : SUB 
        tb_a = 8'd5;
        tb_b = 8'd3;
        tb_opcode = 4'b0001;
        #10;
        assert(tb_result == 8'd2) else $error("SUB failed");
        $display("SUB test passed %d - %d = %d", tb_a, tb_b, tb_result);
        
        // Test : AND (0xFF & 0x0F = 0x0F)
        tb_a = 8'hFF;
        tb_b = 8'h0F;
        tb_opcode = 4'b0010;
        #10;
        assert(tb_result == 8'h0F) else $error("AND failed");
        $display("AND test passed %02x & %02x = %02x", tb_a, tb_b, tb_result);
        
        // Test : OR (0xF0 | 0x0F = 0xFF)
        tb_a = 8'hF0;
        tb_b = 8'h0F;
        tb_opcode = 4'b0011;
        #10;
        assert(tb_result == 8'hFF) else $error("OR failed");
        $display("OR test passed %02x | %02x = %02x", tb_a, tb_b, tb_result);
        
        // Test : XOR (0xAA ^ 0x55 = 0xFF)
        tb_a = 8'hAA;
        tb_b = 8'h55;
        tb_opcode = 4'b0100;
        #10;
        assert(tb_result == 8'hFF) else $error("XOR failed");
        $display("XOR test passed %02x ^ %02x = %02x", tb_a, tb_b, tb_result);
        
        // Test : SHL (0x05 << 1 = 0x0A, no carry)
        tb_a = 8'b00000101;
        tb_opcode = 4'b0101;
        #10;
        assert(tb_result == 8'b00001010) else $error("SHL failed");
        $display("Left shift test passed %02x << 1 = %02x", tb_a, tb_result);
        
        // Test : SHR (0x05 >> 1 = 0x02)
        tb_a = 8'b00000101;
        tb_opcode = 4'b0110;
        #10;
        assert(tb_result == 8'b00000010) else $error("SHR failed");
        $display("Right shift test passed %02x << 1 = %02x", tb_a, tb_result);
        
        // Test : NAND (0xFF & 0x0F = 0x0F, NAND = 0xF0)
        tb_a = 8'hFF;
        tb_b = 8'h0F;
        tb_opcode = 4'b0111;
        #10;
        assert(tb_result == 8'hF0) else $error("NAND failed, expected 0xF0, got 0x%02X", tb_result);
        $display("NAND test passed ~(%02x & %02x) = %02x", tb_a, tb_b, tb_result);
        
        // Test : Zero result (0x00 & 0xFF = 0x00)
        tb_a = 8'h00;
        tb_b = 8'hFF;
        tb_opcode = 4'b0010;  // AND
        #10 // Waiting for 0 flag to set
        assert(tb_zero_flag == 1'b1) else $error("Zero flag failed");
        $display("Zero flag check passed");
        #10;

        // Test : MUL (10 × 12 = 120)
        tb_a = 8'd10;
        tb_b = 8'd12;
        tb_opcode = 4'b1000;
        #10;
        assert(tb_result == 8'd120) else $error("MUL failed: expected 120, got %d", tb_result);
        $display("MUL test passed %d x %d = %d", tb_a, tb_b, tb_result);

        // Test : MUL with overflow (200 × 2 = 400, needs 16-bit)
        tb_a = 8'd200;
        tb_b = 8'd2;
        tb_opcode = 4'b1000;
        #10;
        assert(tb_result == 16'd400) else $error("MUL overflow failed: expected 400, got %d", tb_result);
        $display("MUL overflow test passed %d x %d = %d", tb_a, tb_b, tb_result);

        // Test : MUL max (255 × 255 = 65025)
        tb_a = 8'd255;
        tb_b = 8'd255;
        tb_opcode = 4'b1000;
        #10;
        assert(tb_result == 16'd65025) else $error("MUL max failed: expected 65025, got %d", tb_result);
        $display("MUL max test passed %d x %d = %d", tb_a, tb_b, tb_result);

        // Test : DIV (25 ÷ 4 → Q=6, R=1)
        tb_a = 8'd25;
        tb_b = 8'd4;
        tb_opcode = 4'b1001;
        #10; // Waiting for both flags to set
        // result[7:0] = quotient, result[15:8] = remainder
        assert(tb_result[7:0] == 8'd6) else $error("DIV quotient failed: expected 6, got %d", tb_result[7:0]);
        assert(tb_result[15:8] == 8'd1) else $error("DIV remainder failed: expected 1, got %d", tb_result[15:8]);
        $display("DIV test 1 passed %d / %d = %d*%d + %d", tb_a, tb_b, tb_b, tb_result[7:0], tb_result[15:8]);

        // Test : DIV (100 ÷ 7 → Q=14, R=2)
        tb_a = 8'd100;
        tb_b = 8'd7;
        tb_opcode = 4'b1001;
        #10;
        assert(tb_result[7:0] == 8'd14) else $error("DIV quotient failed");
        assert(tb_result[15:8] == 8'd2) else $error("DIV remainder failed");
        $display("DIV test 2 passed %d / %d = %d*%d + %d", tb_a, tb_b, tb_b, tb_result[7:0], tb_result[15:8]);

        // Test : DIV by zero (should set flag)
        tb_a = 8'd50;
        tb_b = 8'd0;
        tb_opcode = 4'b1001;
        #10;
        assert(tb_div_by_zero == 1'b1) else $error("DIV by zero flag not set");
        $display("DIV by zero flag correctly set");
        $display("Zero flag %d", tb_zero_flag);

        // Test : DIV exact (48 ÷ 6 → Q=8, R=0)
        tb_a = 8'd48;
        tb_b = 8'd6;
        tb_opcode = 4'b1001;
        #10;
        assert(tb_result[7:0] == 8'd8) else $error("DIV quotient failed");
        assert(tb_result[15:8] == 8'd0) else $error("DIV remainder should be 0");
        assert(tb_zero_flag == 1'b0) else $error("Zero flag should be 0 (result is not zero)");
        $display("DIV test 3 passed %d / %d = %d", tb_a, tb_b, tb_result);

        // Test : NOR (0xF0 | 0x0F = 0x00)
        tb_a = 8'hF0;
        tb_b = 8'h0F;
        tb_opcode = 4'b1010;
        #10;
        assert(tb_result == 8'h00) else $error("NOR failed");
        $display("NOR test passed ~(%02x | %02x) = %02x", tb_a, tb_b, tb_result);

        // Test : XNOR (0xAA ^ 0x55 = 0x00)
        tb_a = 8'hAA;
        tb_b = 8'h55;
        tb_opcode = 4'b1011;
        #10;
        assert(tb_result == 8'h00) else $error("XNOR failed");
        $display("XNOR test passed ~(%02x ^ %02x) = %02x", tb_a, tb_b, tb_result);

    end

endmodule
