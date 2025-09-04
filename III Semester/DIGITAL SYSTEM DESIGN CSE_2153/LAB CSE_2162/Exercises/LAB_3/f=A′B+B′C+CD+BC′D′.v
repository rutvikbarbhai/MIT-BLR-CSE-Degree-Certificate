// Aim: Implement f(A,B,C,D) = A'B + B' C + C D + B C' D'
// Module + Truth table + Testbench in one file

// ---------------- Module ----------------
module example5 (
    input  a, b, c, d,
    output f
);

    // Implementing: f = (~A & B) | (~B & C) | (C & D) | (B & ~C & ~D)
    assign f = (~a & b) | (~b & c) | (c & d) | (b & ~c & ~d);

endmodule


// ---------------- Truth Table ----------------
//  A B C D | f = A'B + B'C + C D + B C' D'
// -----------------------------------------
//  0 0 0 0 | 0
//  0 0 0 1 | 0
//  0 0 1 0 | 1
//  0 0 1 1 | 1
//  0 1 0 0 | 1
//  0 1 0 1 | 1
//  0 1 1 0 | 1
//  0 1 1 1 | 1
//  1 0 0 0 | 0
//  1 0 0 1 | 0
//  1 0 1 0 | 1
//  1 0 1 1 | 1
//  1 1 0 0 | 1
//  1 1 0 1 | 1
//  1 1 1 0 | 1
//  1 1 1 1 | 1
// -----------------------------------------

// ---------------- Testbench ----------------
module example5_tb;
    reg a, b, c, d;
    wire f;

    // instantiate DUT
    example5 dut (.a(a), .b(b), .c(c), .d(d), .f(f));

    initial begin
        $display("A B C D | f");
        $display("-------------");
        // iterate through all 16 combinations
        integer i;
        for (i = 0; i < 16; i = i + 1) begin
            {a,b,c,d} = i;
            #5; // wait for signals to propagate
            $display("%b %b %b %b | %b", a, b, c, d, f);
        end
        $stop;
    end
endmodule
