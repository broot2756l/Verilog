`timescale 1ns/1ps

module control_unit (
    input  logic       clk,
    input  logic       rst,
    input  logic [3:0] opcode,
    input  logic       zero_flag,
    input  logic       carry_flag,

    output logic       load_ir,
    output logic       pc_inc,
    output logic       pc_load,
    output logic       load_acc,
    output logic       load_flags,
    output logic       ram_we,
    output logic [2:0] alu_op,
    output logic [1:0] alu_a_sel,   // 00 = acc, 01 = ram_data_out, 10 = operand
    output logic       alu_b_sel,   // 0  = ram_data_out, 1 = operand
    output logic       halted
);

    // ---- opcodes ----
    localparam logic [3:0] OP_NOP  = 4'b0000; // No operation
    localparam logic [3:0] OP_LDA  = 4'b0001; // Load accumulator
    localparam logic [3:0] OP_LDI  = 4'b0010; // Load immediate
    localparam logic [3:0] OP_STA  = 4'b0011; // Store accumulator
    localparam logic [3:0] OP_ADD  = 4'b0100; // Add
    localparam logic [3:0] OP_SUB  = 4'b0101; // Subtract
    localparam logic [3:0] OP_ADI  = 4'b0110; // Add immediate
    localparam logic [3:0] OP_SBI  = 4'b0111; // Subtract immediate
    localparam logic [3:0] OP_ANDM = 4'b1000; // AND from memory
    localparam logic [3:0] OP_ORM  = 4'b1001; // OR from memory
    localparam logic [3:0] OP_XORM = 4'b1010; // XOR from memory
    localparam logic [3:0] OP_NOT  = 4'b1011; // NOT
    localparam logic [3:0] OP_JMP  = 4'b1100; // Jump to address
    localparam logic [3:0] OP_JZ   = 4'b1101; // Jump if zero flag
    localparam logic [3:0] OP_JC   = 4'b1110; // Jump if carry flag
    localparam logic [3:0] OP_HLT  = 4'b1111; // Stopping everything

    // ---- alu function codes ----
    localparam logic [2:0] ALU_ADD  = 3'b000;
    localparam logic [2:0] ALU_SUB  = 3'b001;
    localparam logic [2:0] ALU_AND  = 3'b010;
    localparam logic [2:0] ALU_OR   = 3'b011;
    localparam logic [2:0] ALU_XOR  = 3'b100;
    localparam logic [2:0] ALU_NOT  = 3'b101;
    localparam logic [2:0] ALU_PASS = 3'b110;

    // ---- FSM states ----
    typedef enum logic [1:0] { S_FETCH, S_EXECUTE, S_HALT } state_t;
    state_t state, next_state;

    // ---- state register ----
    always_ff @(posedge clk) begin
        if (rst) state <= S_FETCH;
        else     state <= next_state;
    end

    // ---- next-state logic ----
    always_comb begin
        case (state)
            S_FETCH: next_state = S_EXECUTE;
            S_EXECUTE: begin
                if (opcode == OP_HLT) next_state = S_HALT;
                else                  next_state = S_FETCH;
            end
            S_HALT:  next_state = S_HALT;             // stays here forever
            default: next_state = S_FETCH;
        endcase
    end

    always_comb begin
        load_ir    = 1'b0;
        pc_inc     = 1'b0;
        pc_load    = 1'b0;
        load_acc   = 1'b0;
        load_flags = 1'b0;
        ram_we     = 1'b0;
        alu_op     = ALU_PASS;
        alu_a_sel  = 2'b00;
        alu_b_sel  = 1'b0;
        halted     = 1'b0;

        case (state)

            S_FETCH: begin
                load_ir = 1'b1;
                pc_inc  = 1'b1;
            end

            S_EXECUTE: begin
                case (opcode)
                    OP_LDA: begin
                        load_acc  = 1'b1;
                        alu_op    = ALU_PASS;
                        alu_a_sel = 2'b01;      // pass ram_data_out straight through
                    end
                    OP_LDI: begin
                        load_acc  = 1'b1;
                        alu_op    = ALU_PASS;
                        alu_a_sel = 2'b10;      // pass the immediate straight through
                    end
                    OP_STA: begin
                        ram_we = 1'b1;          // acc -> ram[operand], acc itself untouched
                    end
                    OP_ADD: begin
                        load_acc = 1'b1; load_flags = 1'b1;
                        alu_op = ALU_ADD; alu_a_sel = 2'b00; alu_b_sel = 1'b0;
                    end
                    OP_SUB: begin
                        load_acc = 1'b1; load_flags = 1'b1;
                        alu_op = ALU_SUB; alu_a_sel = 2'b00; alu_b_sel = 1'b0;
                    end
                    OP_ADI: begin
                        load_acc = 1'b1; load_flags = 1'b1;
                        alu_op = ALU_ADD; alu_a_sel = 2'b00; alu_b_sel = 1'b1;
                    end
                    OP_SBI: begin
                        load_acc = 1'b1; load_flags = 1'b1;
                        alu_op = ALU_SUB; alu_a_sel = 2'b00; alu_b_sel = 1'b1;
                    end
                    OP_ANDM: begin
                        load_acc = 1'b1; load_flags = 1'b1;
                        alu_op = ALU_AND; alu_a_sel = 2'b00; alu_b_sel = 1'b0;
                    end
                    OP_ORM: begin
                        load_acc = 1'b1; load_flags = 1'b1;
                        alu_op = ALU_OR; alu_a_sel = 2'b00; alu_b_sel = 1'b0;
                    end
                    OP_XORM: begin
                        load_acc = 1'b1; load_flags = 1'b1;
                        alu_op = ALU_XOR; alu_a_sel = 2'b00; alu_b_sel = 1'b0;
                    end
                    OP_NOT: begin
                        load_acc = 1'b1; load_flags = 1'b1;
                        alu_op = ALU_NOT; alu_a_sel = 2'b00;   // b is ignored by ALU for NOT
                    end
                    OP_JMP: begin
                        pc_load = 1'b1;
                    end
                    OP_JZ: begin
                        pc_load = zero_flag;    // only overwrite PC if the flag says so
                    end
                    OP_JC: begin
                        pc_load = carry_flag;
                    end
                    OP_HLT: begin
                        // next_state already routes to S_HALT; nothing to drive here
                    end
                    default: begin
                        // OP_NOP and any undecoded opcode: do nothing this cycle
                    end
                endcase
            end

            S_HALT: begin
                halted = 1'b1;   // every other signal already defaulted to 0/safe above
            end

            default: ;
        endcase
    end

endmodule