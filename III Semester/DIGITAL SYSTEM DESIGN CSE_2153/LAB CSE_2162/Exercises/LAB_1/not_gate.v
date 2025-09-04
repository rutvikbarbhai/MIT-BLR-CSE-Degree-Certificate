// Aim: To write Verilog code, truth table, and waveform of a NOT gate

// ---------------- Verilog Code ----------------
module not_gate (a, y);
  input a;
  output y;

  assign y = ~a;
endmodule

// ---------------- Truth Table ----------------
//
//  a | y = ~a
// ---+-------
//  0 |   1
//  1 |   0
//
// ------------------------------------------------
//
// ---------------- Waveform ----------------
//
// When simulated, the waveform will show:
// - y is always the logical inverse of a
// - If a = 0 → y = 1
// - If a = 1 → y = 0
//
// Use a testbench to toggle input a
// and generate the waveform in simulation software
// (e.g., ModelSim, Vivado, Icarus Verilog).
//
