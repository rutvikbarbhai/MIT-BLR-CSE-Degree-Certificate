// Aim: To write Verilog code, truth table, and waveform of a 2-input XOR gate

// ---------------- Verilog Code ----------------
module xor_gate (a, b, y);
  input a, b;
  output y;

  assign y = a ^ b;   // XOR operation
endmodule

// ---------------- Truth Table ----------------
//
//  a | b | y = a ^ b
// ---+---+-----------
//  0 | 0 |     0
//  0 | 1 |     1
//  1 | 0 |     1
//  1 | 1 |     0
//
// ------------------------------------------------
//
// ---------------- Waveform ----------------
//
// When simulated, the waveform will show:
// - y = 1 when a and b are different
// - y = 0 when a and b are the same
//
// Use a testbench to apply all input combinations
// and generate the waveform in simulation software
// (e.g., ModelSim, Vivado, Icarus Verilog).
//
