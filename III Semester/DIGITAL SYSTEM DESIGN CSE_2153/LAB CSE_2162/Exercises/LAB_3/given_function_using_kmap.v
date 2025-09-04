// Aim: To simplify the given function using K-map 
//      and write Verilog code for the simplified expression

// Function: f(x1,x2,x3,x4) = Σm(2,4,5,6,10) + D(12,13,14,15)
// Simplified: f = (x2 & x3) | (x3 & x4)

module example4 (x2, x3, x4, f);
    input x2, x3, x4;
    output f;

    assign f = (x2 & x3) | (x3 & x4);
endmodule
