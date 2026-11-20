module EpochArithmetic(
  input  [15:0] io_old,
  input  [15:0] io_refill,
  input  [2:0]  io_enable,
  input  [8:0]  io_index_0,
  input  [8:0]  io_index_1,
  input  [8:0]  io_index_2,
  input  [8:0]  io_observed,
  input         io_synchronousReset,
  output        io_equivalent,
  output        io_mutationEquivalent,
  output        io_wraps,
  output        io_independentWrite
);
  wire  hit_0 = io_enable[0] & io_index_0 == io_observed; // @[Emit.scala 15:45]
  wire  hit_1 = io_enable[1] & io_index_1 == io_observed; // @[Emit.scala 15:45]
  wire  hit_2 = io_enable[2] & io_index_2 == io_observed; // @[Emit.scala 15:45]
  wire [15:0] _original_T_1 = io_old + 16'h1; // @[Emit.scala 17:34]
  wire [15:0] _GEN_0 = hit_0 ? _original_T_1 : io_old; // @[Emit.scala 17:{16,26} 16:27]
  wire [15:0] _GEN_1 = hit_1 ? _original_T_1 : _GEN_0; // @[Emit.scala 18:{16,26}]
  wire [15:0] _GEN_2 = hit_2 ? io_refill : _GEN_1; // @[Emit.scala 19:{16,26}]
  wire [15:0] original = io_synchronousReset ? 16'h0 : _GEN_2; // @[Emit.scala 20:{29,39}]
  wire [15:0] _mutant_T_6 = io_old + 16'h2; // @[Emit.scala 28:12]
  wire [15:0] mutant = ~io_synchronousReset & ~hit_2 & hit_0 & hit_1 ? _mutant_T_6 : original; // @[Emit.scala 27:17]
  wire  _io_wraps_T_4 = io_old != 16'hffff; // @[Emit.scala 31:11]
  wire  _io_wraps_T_5 = io_synchronousReset | hit_2 | ~(hit_0 | hit_1) | _io_wraps_T_4; // @[Emit.scala 30:64]
  wire  _io_independentWrite_T_5 = io_synchronousReset | ~hit_0 | hit_2; // @[Emit.scala 32:55]
  assign io_equivalent = original == original; // @[Emit.scala 25:26]
  assign io_mutationEquivalent = original == mutant; // @[Emit.scala 29:34]
  assign io_wraps = _io_wraps_T_5 | original == 16'h0; // @[Emit.scala 31:22]
  assign io_independentWrite = _io_independentWrite_T_5 | original == _original_T_1; // @[Emit.scala 33:49]
endmodule
