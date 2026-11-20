module UpdateProof(
  input         io_valid,
  input  [63:0] io_counter,
  input  [63:0] io_delta,
  input         io_current,
  input         io_event,
  input         io_retire,
  input         io_reset,
  output        io_equivalent,
  output        io_resetEquivalent,
  output        io_allocationEquivalent,
  output        io_mutationEquivalent
);
  wire [64:0] wide = io_counter + io_delta; // @[EmitUpdate.scala 15:25]
  wire [63:0] _oldCurrentWide_T = io_valid ? io_counter : 64'h0; // @[EmitUpdate.scala 16:27]
  wire [64:0] oldCurrentWide = _oldCurrentWide_T + io_delta; // @[EmitUpdate.scala 16:61]
  wire  _guard_T_1 = |io_delta; // @[EmitUpdate.scala 17:51]
  wire  retiring = ~io_event & io_retire; // @[EmitUpdate.scala 19:28]
  wire [63:0] _oldUpdated_T_3 = _guard_T_1 ? wide[63:0] : io_counter; // @[EmitUpdate.scala 21:8]
  wire [63:0] oldUpdated = io_current ? oldCurrentWide[63:0] : _oldUpdated_T_3; // @[EmitUpdate.scala 20:23]
  wire [63:0] candidateData = io_current & ~io_valid ? io_delta : wide[63:0]; // @[EmitUpdate.scala 22:26]
  wire  _newUpdated_T_1 = io_current | _guard_T_1; // @[AddressBucketUpdate.scala 8:59]
  wire [63:0] newUpdated = _newUpdated_T_1 ? candidateData : io_counter; // @[EmitUpdate.scala 23:23]
  wire  _oldNext_T = io_reset | retiring; // @[EmitUpdate.scala 24:30]
  wire [63:0] _oldNext_T_1 = io_event ? oldUpdated : io_counter; // @[EmitUpdate.scala 24:57]
  wire [63:0] oldNext = io_reset | retiring ? 64'h0 : _oldNext_T_1; // @[EmitUpdate.scala 24:20]
  wire [63:0] _newNext_T_1 = io_event ? newUpdated : io_counter; // @[EmitUpdate.scala 25:57]
  wire [63:0] newNext = _oldNext_T ? 64'h0 : _newNext_T_1; // @[EmitUpdate.scala 25:20]
  wire  _nextValid_T = ~io_reset; // @[EmitUpdate.scala 26:19]
  wire [63:0] mutant = retiring ? 64'h0 : _newNext_T_1; // @[EmitUpdate.scala 27:19]
  wire  _io_equivalent_T = oldNext == newNext; // @[EmitUpdate.scala 28:28]
  assign io_equivalent = oldNext == newNext; // @[EmitUpdate.scala 28:28]
  assign io_resetEquivalent = _nextValid_T | _io_equivalent_T; // @[EmitUpdate.scala 29:35]
  assign io_allocationEquivalent = ~io_current | oldUpdated == newUpdated; // @[EmitUpdate.scala 30:42]
  assign io_mutationEquivalent = oldNext == mutant; // @[EmitUpdate.scala 31:36]
endmodule
