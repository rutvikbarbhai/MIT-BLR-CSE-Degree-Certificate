// Aim: Simplify f(A,B,C,D) using K-map and implement using logic gates
// Expression: f = B'C + B'D + BC'D'

module example7 (a, b, c, d, f);
    input a, b, c, d;   // Note: 'a' is unused since f does not depend on A
    output f;

    assign f = (~b & c) | (~b & d) | (b & ~c & ~d);
endmodule
