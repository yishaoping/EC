module UpdateProof(
  input         io_valid,
  input  [63:0] io_counter,
  input  [63:0] io_delta,
  input         io_current,
  input         io_event,
  input         io_retire,
  input         io_reset,
  output        io_equivalent,
  output        io_invariantStep,
  output        io_currentSumEqual,
  output        io_mutationEquivalent
);
  wire  invariant = io_valid | io_counter == 64'h0; // @[EmitUpdate.scala 14:28]
  wire [64:0] wide = io_counter + io_delta; // @[EmitUpdate.scala 15:25]
  wire [63:0] _oldCurrentWide_T = io_valid ? io_counter : 64'h0; // @[EmitUpdate.scala 16:27]
  wire [64:0] oldCurrentWide = _oldCurrentWide_T + io_delta; // @[EmitUpdate.scala 16:61]
  wire  _guard_T_1 = |io_delta; // @[EmitUpdate.scala 17:51]
  wire  guard = io_valid | io_current | ~(|io_delta); // @[EmitUpdate.scala 17:38]
  wire  commit = io_event & guard & ~wide[64]; // @[EmitUpdate.scala 18:34]
  wire  retiring = ~io_event & io_retire; // @[EmitUpdate.scala 19:28]
  wire [63:0] _oldUpdated_T_3 = _guard_T_1 ? wide[63:0] : io_counter; // @[EmitUpdate.scala 21:8]
  wire [63:0] oldUpdated = io_current ? oldCurrentWide[63:0] : _oldUpdated_T_3; // @[EmitUpdate.scala 20:23]
  wire  _newUpdated_T_1 = io_current | _guard_T_1; // @[AddressBucketUpdate.scala 8:59]
  wire [63:0] newUpdated = _newUpdated_T_1 ? wide[63:0] : io_counter; // @[EmitUpdate.scala 22:23]
  wire  _oldNext_T = io_reset | retiring; // @[EmitUpdate.scala 23:30]
  wire [63:0] _oldNext_T_1 = commit ? oldUpdated : io_counter; // @[EmitUpdate.scala 23:57]
  wire [63:0] oldNext = io_reset | retiring ? 64'h0 : _oldNext_T_1; // @[EmitUpdate.scala 23:20]
  wire [63:0] _newNext_T_1 = commit ? newUpdated : io_counter; // @[EmitUpdate.scala 24:57]
  wire [63:0] newNext = _oldNext_T ? 64'h0 : _newNext_T_1; // @[EmitUpdate.scala 24:20]
  wire  nextValid = ~io_reset & ~retiring & (io_valid | commit & io_current); // @[EmitUpdate.scala 25:42]
  wire [63:0] mutant = retiring ? 64'h0 : _newNext_T_1; // @[EmitUpdate.scala 26:19]
  wire  _io_equivalent_T = ~invariant; // @[EmitUpdate.scala 27:20]
  assign io_equivalent = ~invariant | oldNext == newNext; // @[EmitUpdate.scala 27:31]
  assign io_invariantStep = _io_equivalent_T | nextValid | newNext == 64'h0; // @[EmitUpdate.scala 28:47]
  assign io_currentSumEqual = _io_equivalent_T | wide == oldCurrentWide; // @[EmitUpdate.scala 29:36]
  assign io_mutationEquivalent = _io_equivalent_T | oldNext == mutant; // @[EmitUpdate.scala 30:39]
endmodule
