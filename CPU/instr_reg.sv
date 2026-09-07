module instr_reg (
    input  logic       clk,
    input  logic       rst,
    input  logic        load_ir,   // 1 = capture instr_in this cycle (asserted during FETCH)
    input  logic [7:0]  instr_in,  // straight from instruction ROM
    output logic [3:0]  opcode,    // instr[7:4]
    output logic [3:0]  operand    // instr[3:0]
);
    logic [7:0] ir;

    always_ff @(posedge clk) begin
        if (rst)
            ir <= 8'h00;           
        else if (load_ir)
            ir <= instr_in;
    end

    assign opcode  = ir[7:4];
    assign operand = ir[3:0];

endmodule