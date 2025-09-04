// Aim: To write Verilog code, truth table, and waveform 
//      to realize all basic logic gates (NOT, AND, NAND, OR, NOR, XOR, XNOR)

// ---------------- Main Module ----------------
module all_gates (
    input a_in, b_in,
    output not_op, and_op, nand_op, or_op, nor_op, xor_op, xnor_op
);

    // Logic Gate Operations
    assign not_op  = ~a_in;             // NOT gate (on input a only)
    assign and_op  = a_in & b_in;       // AND gate
    assign nand_op = ~(a_in & b_in);    // NAND gate
    assign or_op   = a_in | b_in;       // OR gate
    assign nor_op  = ~(a_in | b_in);    // NOR gate
    assign xor_op  = a_in ^ b_in;       // XOR gate
    assign xnor_op = ~(a_in ^ b_in);    // XNOR gate

endmodule


// ---------------- Truth Table ----------------
//
//  a_in | b_in | not_op | and_op | nand_op | or_op | nor_op | xor_op | xnor_op
// ------+------+--------+--------+---------+-------+--------+--------+---------
//   0   |  0   |   1    |   0    |   1     |   0   |   1    |   0    |   1
//   0   |  1   |   1    |   0    |   1     |   1   |   0    |   1    |   0
//   1   |  0   |   0    |   0    |   1     |   1   |   0    |   1    |   0
//   1   |  1   |   0    |   1    |   0     |   1   |   0    |   0    |   1
//
// ------------------------------------------------


// ---------------- Testbench ----------------
module all_gates_tb;

    // Testbench signals
    reg a_in, b_in;
    wire not_op, and_op, nand_op, or_op, nor_op, xor_op, xnor_op;

    // Instantiate the design under test (DUT)
    all_gates dut (
        .a_in(a_in),
        .b_in(b_in),
        .not_op(not_op),
        .and_op(and_op),
        .nand_op(nand_op),
        .or_op(or_op),
        .nor_op(nor_op),
        .xor_op(xor_op),
        .xnor_op(xnor_op)
    );

    // Stimulus
    initial begin
        $display("a b | not and nand or nor xor xnor");
        $display("-----------------------------------");
        
        a_in=0; b_in=0; #10;
        $display("%b %b |  %b    %b    %b    %b   %b   %b    %b", a_in,b_in,not_op,and_op,nand_op,or_op,nor_op,xor_op,xnor_op);

        a_in=0; b_in=1; #10;
        $display("%b %b |  %b    %b    %b    %b   %b   %b    %b", a_in,b_in,not_op,and_op,nand_op,or_op,nor_op,xor_op,xnor_op);

        a_in=1; b_in=0; #10;
        $display("%b %b |  %b    %b    %b    %b   %b   %b    %b", a_in,b_in,not_op,and_op,nand_op,or_op,nor_op,xor_op,xnor_op);

        a_in=1; b_in=1; #10;
        $display("%b %b |  %b    %b    %b    %b   %b   %b    %b", a_in,b_in,not_op,and_op,nand_op,or_op,nor_op,xor_op,xnor_op);

        $stop;  // End simulation
    end

endmodule
