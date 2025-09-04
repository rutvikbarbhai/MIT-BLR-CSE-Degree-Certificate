// Aim: To write Verilog code, truth table, and waveform of the given circuit

// ---------------- Verilog Code ----------------
module example2 (x1, x2, x3, f);
  input x1, x2, x3;
  output f;

  assign f = (x1 & x2) | (~x2 & x3);
endmodule

// ---------------- Truth Table ----------------
//
//  x1 | x2 | x3 | f
// ----+----+----+---
//   0 |  0 |  0 | 0
//   0 |  0 |  1 | 1
//   0 |  1 |  0 | 0
//   0 |  1 |  1 | 0
//   1 |  0 |  0 | 0
//   1 |  0 |  1 | 1
//   1 |  1 |  0 | 1
//   1 |  1 |  1 | 1
//
// ------------------------------------------------
//
// ---------------- Waveform ----------------
//
// When simulated, the waveform will show:
// - f = 1 when (x1 & x2) = 1, OR (~x2 & x3) = 1
// - f = 0 for all other combinations.
//
// Use a testbench to apply all input combinations
// and generate the waveform in simulation software
// (e.g., ModelSim, Vivado, Icarus Verilog).
//
