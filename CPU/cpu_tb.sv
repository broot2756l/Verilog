`timescale 1ns/1ps
module cpu_tb;

    // ---- DUT #1: LDI/STA/ADD/HLT -- computes 3 + 4 ----
    logic clk1 = 0, rst1;
    logic [3:0] acc1;
    logic halted1;
    cpu_top #(.MEMFILE("prog_add.hex")) dut_add (
        .clk(clk1), .rst(rst1), .acc_debug(acc1), .halted(halted1)
    );
    always #5 clk1 = ~clk1;

    // ---- DUT #2: STA/SBI/JZ/JMP/HLT -- a countdown loop ----
    logic clk2 = 0, rst2;
    logic [3:0] acc2;
    logic halted2;
    cpu_top #(.MEMFILE("prog_loop.hex")) dut_loop (
        .clk(clk2), .rst(rst2), .acc_debug(acc2), .halted(halted2)
    );
    always #5 clk2 = ~clk2;

    // ---- DUT #3: LDI/ADI/JC/HLT -- carry-triggered branch ----
    logic clk3 = 0, rst3;
    logic [3:0] acc3;
    logic halted3;
    cpu_top #(.MEMFILE("prog_carry.hex")) dut_carry (
        .clk(clk3), .rst(rst3), .acc_debug(acc3), .halted(halted3)
    );
    always #5 clk3 = ~clk3;

    integer i;

    initial begin
        // ---------------- Program 1: add two numbers ----------------
        rst1 = 1; @(posedge clk1); @(posedge clk1); rst1 = 0;
        for (i = 0; i < 60 && !halted1; i = i + 1) @(posedge clk1);
        #1;
        assert (halted1) else $error("prog_add: never halted");
        assert (acc1 == 4'd7) else $error("prog_add: expected acc=7, got %0d", acc1);
        $display("prog_add   : acc = %0d (expected 7)  halted=%0d", acc1, halted1);

        // ---------------- Program 2: countdown loop ----------------
        rst2 = 1; @(posedge clk2); @(posedge clk2); rst2 = 0;
        for (i = 0; i < 200 && !halted2; i = i + 1) @(posedge clk2);
        #1;
        assert (halted2) else $error("prog_loop: never halted");
        assert (acc2 == 4'd0) else $error("prog_loop: expected acc=0, got %0d", acc2);
        assert (dut_loop.ram_inst.ram[14] == 4'd1)
            else $error("prog_loop: expected ram[14]=1, got %0d", dut_loop.ram_inst.ram[14]);
        $display("prog_loop  : acc = %0d (expected 0), ram[14] = %0d (expected 1)  halted=%0d",
                  acc2, dut_loop.ram_inst.ram[14], halted2);

        // ---------------- Program 3: carry flag branch ----------------
        rst3 = 1; @(posedge clk3); @(posedge clk3); rst3 = 0;
        for (i = 0; i < 60 && !halted3; i = i + 1) @(posedge clk3);
        #1;
        assert (halted3) else $error("prog_carry: never halted");
        assert (acc3 == 4'd9) else $error("prog_carry: expected acc=9 (branch taken), got %0d", acc3);
        $display("prog_carry : acc = %0d (expected 9, proves the JC branch was taken)  halted=%0d",
                  acc3, halted3);

        $display("ALL CPU TESTS DONE");
        $finish;
    end

endmodule