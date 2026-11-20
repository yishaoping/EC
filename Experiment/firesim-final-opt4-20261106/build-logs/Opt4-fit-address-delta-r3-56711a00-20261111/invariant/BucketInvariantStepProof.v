module BucketInvariantStepProof(
  input         io_valid,
  input  [63:0] io_counter,
  input  [63:0] io_delta,
  input         io_reset,
  input         io_retire,
  input         io_current,
  input         io_nonCurrentUpdate,
  output        io_stepOk
);
  wire  stateInvariant = io_valid | io_counter == 64'h0; // @[EmitDecode.scala 57:33]
  wire  _updateGuard_T_2 = |io_delta; // @[EmitDecode.scala 58:67]
  wire  updateGuard = io_valid | ~io_nonCurrentUpdate | ~(|io_delta); // @[EmitDecode.scala 58:54]
  wire  nextValid = ~io_reset & ~io_retire & (io_valid | io_current); // @[EmitDecode.scala 59:43]
  wire [63:0] _nextCounter_T_1 = io_counter + io_delta; // @[EmitDecode.scala 64:31]
  wire [63:0] _GEN_0 = io_current | io_nonCurrentUpdate & _updateGuard_T_2 ? _nextCounter_T_1 : io_counter; // @[EmitDecode.scala 63:68 64:17 66:17]
  wire [63:0] nextCounter = io_reset | io_retire ? 64'h0 : _GEN_0; // @[EmitDecode.scala 61:32 62:17]
  assign io_stepOk = ~stateInvariant | ~updateGuard | nextValid | nextCounter == 64'h0; // @[EmitDecode.scala 68:61]
endmodule
