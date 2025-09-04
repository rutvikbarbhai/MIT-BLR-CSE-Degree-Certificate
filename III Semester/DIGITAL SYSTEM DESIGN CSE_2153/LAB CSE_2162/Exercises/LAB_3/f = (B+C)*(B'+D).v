// Aim: Simplify f(A,B,C,D) = ΠM(0,1,4,6,8,9,12,14)
//       Implement the simplified expression and provide testbench
// Simplified: f = (B + C) * (B' + D)
// Note: f is independent of A

// ---------------- Main Module ----------------
module example2 (
    input  a,    // unused (function independent of A)
    input  b,
    input  c,
    input  d,
    output f
);
    // f = (b OR c) AND ((NOT b) OR d)
    assign f = (b | c) & (~b | d);

endmodule


// ---------------- Truth Table (B,C,D) ----------------
// b c d | (b + c) | (~b + d) | f = (b+c)*(~b + d)
// ------+---------+----------+---------------------
//  0 0 0 |    0    |    1     | 0
//  0 0 1 |    0    |    1     | 0
//  0 1 0 |    1    |    1     | 1
//  0 1 1 |    1    |    1     | 1
//  1 0 0 |    1    |    0     | 0
//  1 0 1 |    1    |    1     | 1
//  1 1 0 |    1    |    0     | 0
//  1 1 1 |    1    |    1     | 1
//
// Because f does not contain A, for each row above f is same
// whether A = 0 or A = 1 (so the full 16-row table is just two copies).

// ---------------- Testbench ----------------
module example2_tb;
    reg  a, b, c, d;
    wire f;

    // Instantiate DUT
    example2 dut (
        .a(a),
        .b(b),
        .c(c),
        .d(d),
        .f(f)
    );

    initial begin
        $display("A B C D | f   (evaluates (B+C) * (~B + D))");
        $display("---------------------------------------");
        integer i;
        for (i = 0; i < 16; i = i + 1) begin
            {a,b,c,d} = i;    // assign 4-bit vector
            #5;               // small delay for signal to settle
            $display("%b %b %b %b | %b", a,b,c,d,f);
        end
        $stop;
    end

    // optional waveform dump for Icarus/GTKWave
    initial begin
        $dumpfile("example2.vcd");
        $dumpvars(0, example2_tb);
    end
endmodule
