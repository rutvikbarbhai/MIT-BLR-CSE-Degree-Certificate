// Aim: Implement f = (x1x2x4) + (x1x2x3) + (x1x3x4) + (x2x3x4)

module example4 (x1, x2, x3, x4, f);
    input x1, x2, x3, x4;
    output f;

    assign f = (x1 & x2 & x4) | 
               (x1 & x2 & x3) | 
               (x1 & x3 & x4) | 
               (x2 & x3 & x4);
endmodule
