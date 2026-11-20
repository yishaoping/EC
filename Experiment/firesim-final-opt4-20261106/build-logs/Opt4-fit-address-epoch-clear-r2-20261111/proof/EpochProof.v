module EpochProof(
  input         io_valid,
  input         io_processValid,
  input         io_eventEnable,
  input         io_current,
  input         io_retireReq,
  input         io_reset,
  input  [63:0] io_oldCounters_0,
  input  [63:0] io_oldCounters_1,
  input  [63:0] io_oldCounters_2,
  input  [63:0] io_oldCounters_3,
  input  [63:0] io_oldCounters_4,
  input  [63:0] io_newCounters_0,
  input  [63:0] io_newCounters_1,
  input  [63:0] io_newCounters_2,
  input  [63:0] io_newCounters_3,
  input  [63:0] io_newCounters_4,
  input  [12:0] io_delta_0,
  input  [12:0] io_delta_1,
  input  [12:0] io_delta_2,
  input  [12:0] io_delta_3,
  input  [12:0] io_delta_4,
  output        io_stepOk,
  output        io_observableEqual,
  output        io_oldOverflow,
  output        io_newOverflow,
  output        io_commitEqual,
  output        io_nextObservableEqual,
  output        io_unguardedInvalidOverflow
);
  wire [63:0] oldBase_0 = io_valid ? io_oldCounters_0 : 64'h0; // @[EmitEpoch.scala 28:8]
  wire [63:0] oldBase_1 = io_valid ? io_oldCounters_1 : 64'h0; // @[EmitEpoch.scala 28:8]
  wire [63:0] oldBase_2 = io_valid ? io_oldCounters_2 : 64'h0; // @[EmitEpoch.scala 28:8]
  wire [63:0] oldBase_3 = io_valid ? io_oldCounters_3 : 64'h0; // @[EmitEpoch.scala 28:8]
  wire [63:0] oldBase_4 = io_valid ? io_oldCounters_4 : 64'h0; // @[EmitEpoch.scala 28:8]
  wire [63:0] newBase_0 = io_valid ? io_newCounters_0 : 64'h0; // @[EmitEpoch.scala 30:8]
  wire [63:0] newBase_1 = io_valid ? io_newCounters_1 : 64'h0; // @[EmitEpoch.scala 30:8]
  wire [63:0] newBase_2 = io_valid ? io_newCounters_2 : 64'h0; // @[EmitEpoch.scala 30:8]
  wire [63:0] newBase_3 = io_valid ? io_newCounters_3 : 64'h0; // @[EmitEpoch.scala 30:8]
  wire [63:0] newBase_4 = io_valid ? io_newCounters_4 : 64'h0; // @[EmitEpoch.scala 30:8]
  wire [63:0] _oldSums_T = {{51'd0}, io_delta_0}; // @[EmitEpoch.scala 31:75]
  wire [64:0] oldSums_0 = oldBase_0 + _oldSums_T; // @[EmitEpoch.scala 31:57]
  wire [63:0] _oldSums_T_2 = {{51'd0}, io_delta_1}; // @[EmitEpoch.scala 31:75]
  wire [64:0] oldSums_1 = oldBase_1 + _oldSums_T_2; // @[EmitEpoch.scala 31:57]
  wire [63:0] _oldSums_T_4 = {{51'd0}, io_delta_2}; // @[EmitEpoch.scala 31:75]
  wire [64:0] oldSums_2 = oldBase_2 + _oldSums_T_4; // @[EmitEpoch.scala 31:57]
  wire [63:0] _oldSums_T_6 = {{51'd0}, io_delta_3}; // @[EmitEpoch.scala 31:75]
  wire [64:0] oldSums_3 = oldBase_3 + _oldSums_T_6; // @[EmitEpoch.scala 31:57]
  wire [63:0] _oldSums_T_8 = {{51'd0}, io_delta_4}; // @[EmitEpoch.scala 31:75]
  wire [64:0] oldSums_4 = oldBase_4 + _oldSums_T_8; // @[EmitEpoch.scala 31:57]
  wire [64:0] newSums_0 = newBase_0 + _oldSums_T; // @[EmitEpoch.scala 32:57]
  wire [64:0] newSums_1 = newBase_1 + _oldSums_T_2; // @[EmitEpoch.scala 32:57]
  wire [64:0] newSums_2 = newBase_2 + _oldSums_T_4; // @[EmitEpoch.scala 32:57]
  wire [64:0] newSums_3 = newBase_3 + _oldSums_T_6; // @[EmitEpoch.scala 32:57]
  wire [64:0] newSums_4 = newBase_4 + _oldSums_T_8; // @[EmitEpoch.scala 32:57]
  wire  anyDelta = |io_delta_0 | |io_delta_1 | |io_delta_2 | |io_delta_3 | |io_delta_4; // @[EmitEpoch.scala 33:47]
  wire  structuralOk = io_current | io_valid | ~anyDelta; // @[EmitEpoch.scala 34:45]
  wire  oldOverflow = oldSums_0[64] | oldSums_1[64] | oldSums_2[64] | oldSums_3[64] | oldSums_4[64]; // @[EmitEpoch.scala 35:49]
  wire  newOverflow = io_valid & (newSums_0[64] | newSums_1[64] | newSums_2[64] | newSums_3[64] | newSums_4[64]); // @[EmitEpoch.scala 38:30]
  wire  _commit_T = ~io_reset; // @[EmitEpoch.scala 39:16]
  wire  _commit_T_3 = ~io_reset & io_processValid & io_eventEnable & structuralOk; // @[EmitEpoch.scala 39:63]
  wire  commit = ~io_reset & io_processValid & io_eventEnable & structuralOk & ~oldOverflow; // @[EmitEpoch.scala 39:79]
  wire  retire = _commit_T & ~io_processValid & io_retireReq & io_valid; // @[EmitEpoch.scala 40:62]
  wire  nextValid = _commit_T & (io_valid & ~retire | commit & io_current); // @[EmitEpoch.scala 41:29]
  wire  _oldNext_T_1 = commit & (io_current | anyDelta); // @[EmitEpoch.scala 44:16]
  wire [63:0] _oldNext_T_3 = retire ? 64'h0 : io_oldCounters_0; // @[EmitEpoch.scala 45:10]
  wire [63:0] _oldNext_T_4 = commit & (io_current | anyDelta) ? oldSums_0[63:0] : _oldNext_T_3; // @[EmitEpoch.scala 44:8]
  wire [63:0] oldNext_0 = io_reset ? 64'h0 : _oldNext_T_4; // @[EmitEpoch.scala 43:49]
  wire [63:0] _oldNext_T_9 = retire ? 64'h0 : io_oldCounters_1; // @[EmitEpoch.scala 45:10]
  wire [63:0] _oldNext_T_10 = commit & (io_current | anyDelta) ? oldSums_1[63:0] : _oldNext_T_9; // @[EmitEpoch.scala 44:8]
  wire [63:0] oldNext_1 = io_reset ? 64'h0 : _oldNext_T_10; // @[EmitEpoch.scala 43:49]
  wire [63:0] _oldNext_T_15 = retire ? 64'h0 : io_oldCounters_2; // @[EmitEpoch.scala 45:10]
  wire [63:0] _oldNext_T_16 = commit & (io_current | anyDelta) ? oldSums_2[63:0] : _oldNext_T_15; // @[EmitEpoch.scala 44:8]
  wire [63:0] oldNext_2 = io_reset ? 64'h0 : _oldNext_T_16; // @[EmitEpoch.scala 43:49]
  wire [63:0] _oldNext_T_21 = retire ? 64'h0 : io_oldCounters_3; // @[EmitEpoch.scala 45:10]
  wire [63:0] _oldNext_T_22 = commit & (io_current | anyDelta) ? oldSums_3[63:0] : _oldNext_T_21; // @[EmitEpoch.scala 44:8]
  wire [63:0] oldNext_3 = io_reset ? 64'h0 : _oldNext_T_22; // @[EmitEpoch.scala 43:49]
  wire [63:0] _oldNext_T_27 = retire ? 64'h0 : io_oldCounters_4; // @[EmitEpoch.scala 45:10]
  wire [63:0] _oldNext_T_28 = commit & (io_current | anyDelta) ? oldSums_4[63:0] : _oldNext_T_27; // @[EmitEpoch.scala 44:8]
  wire [63:0] oldNext_4 = io_reset ? 64'h0 : _oldNext_T_28; // @[EmitEpoch.scala 43:49]
  wire [63:0] newNext_0 = _oldNext_T_1 ? newSums_0[63:0] : io_newCounters_0; // @[EmitEpoch.scala 49:8]
  wire [63:0] newNext_1 = _oldNext_T_1 ? newSums_1[63:0] : io_newCounters_1; // @[EmitEpoch.scala 49:8]
  wire [63:0] newNext_2 = _oldNext_T_1 ? newSums_2[63:0] : io_newCounters_2; // @[EmitEpoch.scala 49:8]
  wire [63:0] newNext_3 = _oldNext_T_1 ? newSums_3[63:0] : io_newCounters_3; // @[EmitEpoch.scala 49:8]
  wire [63:0] newNext_4 = _oldNext_T_1 ? newSums_4[63:0] : io_newCounters_4; // @[EmitEpoch.scala 49:8]
  wire  _invariant_T = ~io_valid; // @[EmitEpoch.scala 50:19]
  wire [319:0] _invariant_T_1 = {io_oldCounters_4,io_oldCounters_3,io_oldCounters_2,io_oldCounters_1,io_oldCounters_0}; // @[EmitEpoch.scala 50:47]
  wire [319:0] _invariant_T_2 = {io_newCounters_4,io_newCounters_3,io_newCounters_2,io_newCounters_1,io_newCounters_0}; // @[EmitEpoch.scala 50:73]
  wire  invariant = ~io_valid | _invariant_T_1 == _invariant_T_2; // @[EmitEpoch.scala 50:29]
  wire  _observableEqual_T_2 = oldBase_0 == newBase_0; // @[EmitEpoch.scala 52:43]
  wire  _observableEqual_T_5 = oldBase_1 == newBase_1; // @[EmitEpoch.scala 52:43]
  wire  _observableEqual_T_8 = oldBase_2 == newBase_2; // @[EmitEpoch.scala 52:43]
  wire  _observableEqual_T_11 = oldBase_3 == newBase_3; // @[EmitEpoch.scala 52:43]
  wire  _observableEqual_T_14 = oldBase_4 == newBase_4; // @[EmitEpoch.scala 52:43]
  wire [4:0] _observableEqual_T_15 = {_observableEqual_T_14,_observableEqual_T_11,_observableEqual_T_8,
    _observableEqual_T_5,_observableEqual_T_2}; // @[EmitEpoch.scala 53:47]
  wire  observableEqual = &_observableEqual_T_15; // @[EmitEpoch.scala 53:54]
  wire [319:0] _nextObservableEqual_T_1 = {oldNext_4,oldNext_3,oldNext_2,oldNext_1,oldNext_0}; // @[EmitEpoch.scala 54:51]
  wire [319:0] _nextObservableEqual_T_2 = {newNext_4,newNext_3,newNext_2,newNext_1,newNext_0}; // @[EmitEpoch.scala 54:70]
  wire  nextObservableEqual = ~nextValid | _nextObservableEqual_T_1 == _nextObservableEqual_T_2; // @[EmitEpoch.scala 54:40]
  wire  _io_commitEqual_T_5 = _commit_T_3 & ~newOverflow; // @[EmitEpoch.scala 60:69]
  wire  _io_stepOk_T_3 = observableEqual & oldOverflow == newOverflow & io_commitEqual; // @[EmitEpoch.scala 62:78]
  wire  _io_stepOk_T_4 = _io_stepOk_T_3 & nextObservableEqual; // @[EmitEpoch.scala 63:20]
  wire [64:0] _io_unguardedInvalidOverflow_T_5 = io_newCounters_0 + _oldSums_T; // @[EmitEpoch.scala 66:26]
  wire [64:0] _io_unguardedInvalidOverflow_T_8 = io_newCounters_1 + _oldSums_T_2; // @[EmitEpoch.scala 66:26]
  wire [64:0] _io_unguardedInvalidOverflow_T_11 = io_newCounters_2 + _oldSums_T_4; // @[EmitEpoch.scala 66:26]
  wire [64:0] _io_unguardedInvalidOverflow_T_14 = io_newCounters_3 + _oldSums_T_6; // @[EmitEpoch.scala 66:26]
  wire [64:0] _io_unguardedInvalidOverflow_T_17 = io_newCounters_4 + _oldSums_T_8; // @[EmitEpoch.scala 66:26]
  wire [4:0] _io_unguardedInvalidOverflow_T_19 = {_io_unguardedInvalidOverflow_T_17[64],
    _io_unguardedInvalidOverflow_T_14[64],_io_unguardedInvalidOverflow_T_11[64],_io_unguardedInvalidOverflow_T_8[64],
    _io_unguardedInvalidOverflow_T_5[64]}; // @[EmitEpoch.scala 66:56]
  wire  _io_unguardedInvalidOverflow_T_20 = |_io_unguardedInvalidOverflow_T_19; // @[EmitEpoch.scala 66:63]
  assign io_stepOk = ~invariant | _io_stepOk_T_4; // @[EmitEpoch.scala 62:27]
  assign io_observableEqual = &_observableEqual_T_15; // @[EmitEpoch.scala 53:54]
  assign io_oldOverflow = oldSums_0[64] | oldSums_1[64] | oldSums_2[64] | oldSums_3[64] | oldSums_4[64]; // @[EmitEpoch.scala 35:49]
  assign io_newOverflow = io_valid & (newSums_0[64] | newSums_1[64] | newSums_2[64] | newSums_3[64] | newSums_4[64]); // @[EmitEpoch.scala 38:30]
  assign io_commitEqual = commit == _io_commitEqual_T_5; // @[EmitEpoch.scala 59:28]
  assign io_nextObservableEqual = ~nextValid | _nextObservableEqual_T_1 == _nextObservableEqual_T_2; // @[EmitEpoch.scala 54:40]
  assign io_unguardedInvalidOverflow = _invariant_T & ~io_current & anyDelta & _io_unguardedInvalidOverflow_T_20; // @[EmitEpoch.scala 64:71]
endmodule
