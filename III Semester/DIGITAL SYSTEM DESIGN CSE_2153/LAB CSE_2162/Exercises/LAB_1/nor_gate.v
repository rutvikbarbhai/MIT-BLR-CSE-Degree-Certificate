// Aim: To write Verilog code, truth table, and waveform of a 2-input NOR gate

// ---------------- Verilog Code ----------------
module nor_gate (a, b, y);
  input a, b;
  output y;

  assign y = ~(a | b);
endmodule

// ---------------- Truth Table ----------------
//
//  a | b | y = ~(a | b)
// ---+---+-------------
//  0 | 0 |      1
//  0 | 1 |      0
//  1 | 0 |      0
//  1 | 1 |      0
//
// ------------------------------------------------
//
// ---------------- Waveform ----------------
//
// When simulated, the waveform will show:
// - y = 1 only when both a = 0 and b = 0
// - y = 0 for all other input combinations
//
// Use a testbench to apply all input combinations
// and generate the waveform in simulation software
// (e.g., ModelSim, Vivado, Icarus Verilog).
//
