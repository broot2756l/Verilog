module cpu_top #(
    parameter string MEMFILE = "program.hex"
) (
    input  logic       clk,
    input  logic       rst,
    output logic [3:0] acc_debug,     // exposed purely so a testbench can check results
    output logic       halted
);

    // ---- inter-module wires ----
    logic [3:0] pc_out;
    logic [7:0] rom_instr;
    logic [3:0] opcode, operand;

    logic       load_ir, pc_inc, pc_load, load_acc, load_flags, ram_we;
    logic [2:0] alu_op;
    logic [1:0] alu_a_sel;
    logic       alu_b_sel;

    logic [3:0] ram_data_out;
    logic [3:0] acc, alu_a, alu_b, alu_result;
    logic       alu_zero, alu_carry, zero_flag, carry_flag;

    // ---- fetch spine ----
    pc pc_inst (
        .clk(clk), .rst(rst),
        .inc(pc_inc), .load(pc_load), .load_addr(operand),
        .pc_out(pc_out)
    );

    instr_rom #(.MEMFILE(MEMFILE)) rom_inst (
        .addr(pc_out), .instr(rom_instr)
    );

    instr_reg ir_inst (
        .clk(clk), .rst(rst),
        .load_ir(load_ir), .instr_in(rom_instr),
        .opcode(opcode), .operand(operand)
    );

    // ---- control ----
    control_unit cu_inst (
        .clk(clk), .rst(rst),
        .opcode(opcode), .zero_flag(zero_flag), .carry_flag(carry_flag),
        .load_ir(load_ir), .pc_inc(pc_inc), .pc_load(pc_load),
        .load_acc(load_acc), .load_flags(load_flags), .ram_we(ram_we),
        .alu_op(alu_op), .alu_a_sel(alu_a_sel), .alu_b_sel(alu_b_sel),
        .halted(halted)
    );

    // ---- datapath muxes: which values actually feed the ALU this cycle ----
    // These two selects are the "instruction decode" part of the design --
    // the control unit above only decides *when* things happen; this decides
    // *which wire* the ALU listens to for a given opcode.
    always_comb begin
        case (alu_a_sel)
            2'b00:   alu_a = acc;            // most arithmetic/logic ops
            2'b01:   alu_a = ram_data_out;   // LDA
            2'b10:   alu_a = operand;        // LDI
            default: alu_a = acc;
        endcase
        alu_b = alu_b_sel ? operand : ram_data_out;  // 1=immediate (ADI/SBI), 0=memory operand
    end

    // ---- execute ----
    alu alu_inst (
        .a(alu_a), .b(alu_b), .op(alu_op),
        .result(alu_result), .zero(alu_zero), .carry(alu_carry)
    );

    acc_flags acc_inst (
        .clk(clk), .rst(rst),
        .load_acc(load_acc), .load_flags(load_flags),
        .data_in(alu_result), .zero_in(alu_zero), .carry_in(alu_carry),
        .acc(acc), .zero_flag(zero_flag), .carry_flag(carry_flag)
    );

    data_ram ram_inst (
        .clk(clk), .we(ram_we),
        .addr(operand), .data_in(acc),
        .data_out(ram_data_out)
    );

    assign acc_debug = acc;

endmodule