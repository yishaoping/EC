module AsyncProof(
  input         io_valid,
  input         io_current,
  input         io_processValid,
  input         io_eventEnable,
  input         io_retireReq,
  input         io_resetStats,
  input         io_globalReset,
  input  [63:0] io_oldWord,
  input  [63:0] io_newWord,
  input  [63:0] io_delta,
  output        io_equivalent,
  output        io_overflowEquivalent,
  output        io_nextEquivalent,
  output        io_mutationEquivalent
);
  wire  invariant = ~io_valid | io_oldWord == io_newWord; // @[EmitAsync.scala 20:29]
  wire [63:0] _oldSum_T = io_valid ? io_oldWord : 64'h0; // @[EmitAsync.scala 21:19]
  wire [64:0] oldSum = _oldSum_T + io_delta; // @[EmitAsync.scala 21:51]
  wire [63:0] _newSum_T = io_valid ? io_newWord : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  wire [64:0] newSum = _newSum_T + io_delta; // @[AddressCurrentBucketMemory.scala 28:24]
  wire  event_ = io_processValid & io_eventEnable; // @[EmitAsync.scala 23:31]
  wire  retire = ~io_processValid & io_retireReq & io_valid; // @[EmitAsync.scala 24:49]
  wire  _nextValid_T = ~io_resetStats; // @[EmitAsync.scala 25:19]
  wire  _nextValid_T_5 = event_ & io_current; // @[EmitAsync.scala 26:37]
  wire  _nextValid_T_6 = io_valid & ~retire | event_ & io_current; // @[EmitAsync.scala 26:28]
  wire  nextValid = ~io_resetStats & ~io_globalReset & _nextValid_T_6; // @[EmitAsync.scala 25:53]
  wire [63:0] _oldNext_T_2 = _nextValid_T_5 ? oldSum[63:0] : io_oldWord; // @[EmitAsync.scala 28:29]
  wire [63:0] _oldNext_T_3 = retire ? 64'h0 : _oldNext_T_2; // @[EmitAsync.scala 28:8]
  wire [63:0] oldNext = io_resetStats ? 64'h0 : _oldNext_T_3; // @[EmitAsync.scala 27:20]
  wire  _newNext_T_2 = _nextValid_T_5 & _nextValid_T; // @[EmitAsync.scala 29:41]
  wire [63:0] newNext = _nextValid_T_5 & _nextValid_T ? newSum[63:0] : io_newWord; // @[EmitAsync.scala 29:20]
  wire  _nextEqual_T = ~nextValid; // @[EmitAsync.scala 31:19]
  wire  nextEqual = ~nextValid | oldNext == newNext; // @[EmitAsync.scala 31:30]
  wire  overflowEqual = oldSum[64] == newSum[64]; // @[EmitAsync.scala 32:34]
  wire [64:0] mutantSum = io_newWord + io_delta; // @[EmitAsync.scala 33:30]
  wire [63:0] mutantNext = _newNext_T_2 ? mutantSum[63:0] : io_newWord; // @[EmitAsync.scala 34:23]
  wire  _io_overflowEquivalent_T = ~invariant; // @[EmitAsync.scala 35:28]
  assign io_equivalent = _io_overflowEquivalent_T | invariant & nextEqual & overflowEqual; // @[EmitAsync.scala 37:31]
  assign io_overflowEquivalent = ~invariant | overflowEqual; // @[EmitAsync.scala 35:39]
  assign io_nextEquivalent = _io_overflowEquivalent_T | nextEqual; // @[EmitAsync.scala 36:35]
  assign io_mutationEquivalent = _io_overflowEquivalent_T | (_nextEqual_T | oldNext == mutantNext); // @[EmitAsync.scala 38:39]
endmodule
