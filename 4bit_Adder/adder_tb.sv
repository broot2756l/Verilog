module tb;
    reg [3:0] a, b;
    wire [4:0] sum;

    assign a = 4'b1111; // a = 15
    assign b = 4'b0001; // b = 1

    adder_4 test_adder(
        .a(a),
        .b(b),
        .sum(sum)
    );

    initial begin
        #1000;
        $display("a = %b, b = %b, sum = %b", a, b, sum);
        $dumpfile("dump.vcd");
        $dumpvars(0, tb);
        #1000;
        $finish;
    end

endmodule
