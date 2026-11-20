module SequenceProof(
  input         io_valid,
  input         io_current,
  input         io_processValid,
  input         io_eventEnable,
  input         io_retireReq,
  input         io_resetStats,
  input         io_globalReset,
  input  [31:0] io_oldWord,
  input  [31:0] io_newWord,
  input  [31:0] io_sequence,
  output        io_equivalent,
  output        io_nextEquivalent,
  output        io_mutationEquivalent
);
  wire  _invariant_T = ~io_valid; // @[EmitSequence.scala 20:19]
  wire  invariant = ~io_valid | io_oldWord == io_newWord; // @[EmitSequence.scala 20:29]
  wire  event_ = io_processValid & io_eventEnable & io_current; // @[EmitSequence.scala 21:49]
  wire  retire = ~io_processValid & io_retireReq & io_valid; // @[EmitSequence.scala 22:49]
  wire  _nextValid_T = ~io_resetStats; // @[EmitSequence.scala 23:19]
  wire  nextValid = ~io_resetStats & ~io_globalReset & (io_valid & ~retire | event_); // @[EmitSequence.scala 23:53]
  wire [31:0] _oldNext_T = event_ ? io_sequence : io_oldWord; // @[EmitSequence.scala 24:48]
  wire [31:0] oldNext = io_resetStats ? 32'h0 : _oldNext_T; // @[EmitSequence.scala 24:20]
  wire  _newNext_T_1 = event_ & _nextValid_T; // @[EmitSequence.scala 25:27]
  wire [31:0] newNext = event_ & _nextValid_T ? io_sequence : io_newWord; // @[EmitSequence.scala 25:20]
  wire  oldMatch = io_oldWord[31:8] == io_sequence[31:8]; // @[EmitSequence.scala 26:35]
  wire  newMatch = io_newWord[31:8] == io_sequence[31:8]; // @[AddressBucketSequenceMemory.scala 51:44]
  wire  _io_equivalent_T = ~invariant; // @[EmitSequence.scala 28:20]
  wire  _io_nextEquivalent_T_1 = ~nextValid; // @[EmitSequence.scala 29:39]
  wire [31:0] _mutantNext_T_2 = io_sequence ^ 32'h80000000; // @[EmitSequence.scala 30:60]
  wire [31:0] mutantNext = _newNext_T_1 ? _mutantNext_T_2 : io_newWord; // @[EmitSequence.scala 30:23]
  assign io_equivalent = ~invariant | (_invariant_T | oldMatch == newMatch); // @[EmitSequence.scala 28:31]
  assign io_nextEquivalent = _io_equivalent_T | (~nextValid | oldNext == newNext); // @[EmitSequence.scala 29:35]
  assign io_mutationEquivalent = _io_equivalent_T | (_io_nextEquivalent_T_1 | oldNext == mutantNext); // @[EmitSequence.scala 31:39]
endmodule
