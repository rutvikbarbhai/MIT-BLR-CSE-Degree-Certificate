// Aim: To write Verilog code, truth table, and waveform of a 2-input OR gate

// ---------------- Verilog Code ----------------
module or_gate (a, b, y);
  input a, b;
  output y;

  assign y = a | b;
endmodule

// ---------------- Truth Table ----------------
//
//  a | b | y = a | b
// ---+---+----------
//  0 | 0 |    0
//  0 | 1 |    1
//  1 | 0 |    1
//  1 | 1 |    1
//
// ------------------------------------------------
//
// ---------------- Waveform ----------------
//
// When simulated, the waveform will show:
// - y = 1 when either a = 1 or b = 1 (or both)
// - y = 0 only when both a = 0 and b = 0.
//
// Use a testbench to apply all input combinations
// and generate the waveform in simulation software
// (e.g., ModelSim, Vivado, Icarus Verilog).
//
