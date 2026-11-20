module ResultWordProof(
  input  [7:0]  io_set,
  input         io_way,
  input  [7:0]  io_writeSet,
  input         io_writeWay,
  input  [63:0] io_oldWord,
  input  [63:0] io_newWord,
  input  [63:0] io_data,
  input         io_enable,
  input         io_reset,
  output        io_indexEquivalent,
  output        io_nextEquivalent,
  output        io_mutantEquivalent
);
  wire  refHit = io_set == io_writeSet & io_way == io_writeWay; // @[Emit.scala 35:35]
  wire [8:0] _newHit_T = {io_set,io_way}; // @[Cat.scala 33:92]
  wire [8:0] _newHit_T_1 = {io_writeSet,io_writeWay}; // @[Cat.scala 33:92]
  wire  newHit = _newHit_T == _newHit_T_1; // @[Emit.scala 36:60]
  wire [63:0] oldNext = io_enable & refHit ? io_data : io_oldWord; // @[Emit.scala 38:18]
  wire  _newNext_T = io_enable & newHit; // @[Emit.scala 39:29]
  wire [63:0] newNext = io_enable & newHit ? io_data : io_newWord; // @[Emit.scala 39:18]
  wire  _io_nextEquivalent_T = io_oldWord != io_newWord; // @[Emit.scala 40:34]
  wire [63:0] _mutant_T_1 = io_data ^ 64'h8000000000000000; // @[Emit.scala 41:46]
  wire [63:0] mutant = _newNext_T ? _mutant_T_1 : io_newWord; // @[Emit.scala 41:17]
  assign io_indexEquivalent = refHit == newHit; // @[Emit.scala 37:31]
  assign io_nextEquivalent = io_oldWord != io_newWord | oldNext == newNext; // @[Emit.scala 40:48]
  assign io_mutantEquivalent = _io_nextEquivalent_T | oldNext == mutant; // @[Emit.scala 42:50]
endmodule
