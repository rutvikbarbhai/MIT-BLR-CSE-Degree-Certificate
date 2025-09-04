// Aim: To write Verilog code, truth table, and waveform of a 2-input NAND gate

// ---------------- Verilog Code ----------------
module nand_gate (a, b, y);
  input a, b;
  output y;

  assign y = ~(a & b);
endmodule

// ---------------- Truth Table ----------------
//
//  a | b | y = ~(a & b)
// ---+---+-------------
//  0 | 0 |      1
//  0 | 1 |      1
//  1 | 0 |      1
//  1 | 1 |      0
//
// ------------------------------------------------
//
// ---------------- Waveform ----------------
//
// When simulated, the waveform will show:
// - y = 1 for all input combinations except when a = 1 and b = 1
// - y = 0 only when both a and b are 1
//
// Use a testbench to apply all input combinations
// and generate the waveform in simulation software
// (e.g., ModelSim, Vivado, Icarus Verilog).
//
