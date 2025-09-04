// Aim: To write Verilog code, truth table, and waveform of a 2-input XNOR gate

// ---------------- Verilog Code ----------------
module xnor_gate (a, b, y);
  input a, b;
  output y;

  assign y = ~(a ^ b);   // XNOR operation
endmodule

// ---------------- Truth Table ----------------
//
//  a | b | y = ~(a ^ b)
// ---+---+-------------
//  0 | 0 |      1
//  0 | 1 |      0
//  1 | 0 |      0
//  1 | 1 |      1
//
// ------------------------------------------------
//
// ---------------- Waveform ----------------
//
// When simulated, the waveform will show:
// - y = 1 when a and b are the same (both 0 or both 1)
// - y = 0 when a and b are different
//
// Use a testbench to apply all input combinations
// and generate the waveform in simulation software
// (e.g., ModelSim, Vivado, Icarus Verilog).
//
