module PackageRecoveryController(
  input         clock,
  input         reset,
  input  [63:0] io_targetCycle,
  input         io_checkpoint_valid,
  input  [31:0] io_checkpoint_bits_sequence,
  input  [31:0] io_checkpoint_bits_generation,
  input  [63:0] io_checkpoint_bits_restartPc,
  input  [63:0] io_checkpoint_bits_architecturalToken,
  input  [63:0] io_checkpoint_bits_memoryToken,
  output        io_failure_ready,
  input         io_failure_valid,
  input  [31:0] io_failure_bits_sequence,
  input  [31:0] io_failure_bits_generation,
  input         io_failure_bits_allocated,
  input         io_failure_bits_comparedMismatch,
  input         io_request_0_ready,
  output        io_request_0_valid,
  output [31:0] io_request_0_bits_checkpoint_sequence,
  output [31:0] io_request_0_bits_checkpoint_generation,
  output [63:0] io_request_0_bits_checkpoint_restartPc,
  output [63:0] io_request_0_bits_checkpoint_architecturalToken,
  output [63:0] io_request_0_bits_checkpoint_memoryToken,
  output [31:0] io_request_0_bits_failedSequence,
  output [31:0] io_request_0_bits_recoveryGeneration,
  input         io_request_1_ready,
  output        io_request_1_valid,
  output [31:0] io_request_1_bits_checkpoint_sequence,
  output [31:0] io_request_1_bits_checkpoint_generation,
  output [63:0] io_request_1_bits_checkpoint_restartPc,
  output [63:0] io_request_1_bits_checkpoint_architecturalToken,
  output [63:0] io_request_1_bits_checkpoint_memoryToken,
  output [31:0] io_request_1_bits_failedSequence,
  output [31:0] io_request_1_bits_recoveryGeneration,
  input         io_request_2_ready,
  output        io_request_2_valid,
  output [31:0] io_request_2_bits_checkpoint_sequence,
  output [31:0] io_request_2_bits_checkpoint_generation,
  output [63:0] io_request_2_bits_checkpoint_restartPc,
  output [63:0] io_request_2_bits_checkpoint_architecturalToken,
  output [63:0] io_request_2_bits_checkpoint_memoryToken,
  output [31:0] io_request_2_bits_failedSequence,
  output [31:0] io_request_2_bits_recoveryGeneration,
  input         io_request_3_ready,
  output        io_request_3_valid,
  output [31:0] io_request_3_bits_checkpoint_sequence,
  output [31:0] io_request_3_bits_checkpoint_generation,
  output [63:0] io_request_3_bits_checkpoint_restartPc,
  output [63:0] io_request_3_bits_checkpoint_architecturalToken,
  output [63:0] io_request_3_bits_checkpoint_memoryToken,
  output [31:0] io_request_3_bits_failedSequence,
  output [31:0] io_request_3_bits_recoveryGeneration,
  input         io_request_4_ready,
  output        io_request_4_valid,
  output [31:0] io_request_4_bits_checkpoint_sequence,
  output [31:0] io_request_4_bits_checkpoint_generation,
  output [63:0] io_request_4_bits_checkpoint_restartPc,
  output [63:0] io_request_4_bits_checkpoint_architecturalToken,
  output [63:0] io_request_4_bits_checkpoint_memoryToken,
  output [31:0] io_request_4_bits_failedSequence,
  output [31:0] io_request_4_bits_recoveryGeneration,
  input         io_request_5_ready,
  output        io_request_5_valid,
  output [31:0] io_request_5_bits_checkpoint_sequence,
  output [31:0] io_request_5_bits_checkpoint_generation,
  output [63:0] io_request_5_bits_checkpoint_restartPc,
  output [63:0] io_request_5_bits_checkpoint_architecturalToken,
  output [63:0] io_request_5_bits_checkpoint_memoryToken,
  output [31:0] io_request_5_bits_failedSequence,
  output [31:0] io_request_5_bits_recoveryGeneration,
  input         io_response_0_valid,
  input  [31:0] io_response_0_bits_command_checkpoint_sequence,
  input  [31:0] io_response_0_bits_command_checkpoint_generation,
  input  [63:0] io_response_0_bits_command_checkpoint_restartPc,
  input  [63:0] io_response_0_bits_command_checkpoint_architecturalToken,
  input  [63:0] io_response_0_bits_command_checkpoint_memoryToken,
  input  [31:0] io_response_0_bits_command_failedSequence,
  input  [31:0] io_response_0_bits_command_recoveryGeneration,
  input  [63:0] io_response_0_bits_retiredPc,
  input         io_response_0_bits_allCheckerTasksDrained,
  input         io_response_1_valid,
  input  [31:0] io_response_1_bits_command_checkpoint_sequence,
  input  [31:0] io_response_1_bits_command_checkpoint_generation,
  input  [63:0] io_response_1_bits_command_checkpoint_restartPc,
  input  [63:0] io_response_1_bits_command_checkpoint_architecturalToken,
  input  [63:0] io_response_1_bits_command_checkpoint_memoryToken,
  input  [31:0] io_response_1_bits_command_failedSequence,
  input  [31:0] io_response_1_bits_command_recoveryGeneration,
  input  [63:0] io_response_1_bits_retiredPc,
  input         io_response_1_bits_allCheckerTasksDrained,
  input         io_response_2_valid,
  input  [31:0] io_response_2_bits_command_checkpoint_sequence,
  input  [31:0] io_response_2_bits_command_checkpoint_generation,
  input  [63:0] io_response_2_bits_command_checkpoint_restartPc,
  input  [63:0] io_response_2_bits_command_checkpoint_architecturalToken,
  input  [63:0] io_response_2_bits_command_checkpoint_memoryToken,
  input  [31:0] io_response_2_bits_command_failedSequence,
  input  [31:0] io_response_2_bits_command_recoveryGeneration,
  input  [63:0] io_response_2_bits_retiredPc,
  input         io_response_2_bits_allCheckerTasksDrained,
  input         io_response_3_valid,
  input  [31:0] io_response_3_bits_command_checkpoint_sequence,
  input  [31:0] io_response_3_bits_command_checkpoint_generation,
  input  [63:0] io_response_3_bits_command_checkpoint_restartPc,
  input  [63:0] io_response_3_bits_command_checkpoint_architecturalToken,
  input  [63:0] io_response_3_bits_command_checkpoint_memoryToken,
  input  [31:0] io_response_3_bits_command_failedSequence,
  input  [31:0] io_response_3_bits_command_recoveryGeneration,
  input  [63:0] io_response_3_bits_retiredPc,
  input         io_response_3_bits_allCheckerTasksDrained,
  input         io_response_4_valid,
  input  [31:0] io_response_4_bits_command_checkpoint_sequence,
  input  [31:0] io_response_4_bits_command_checkpoint_generation,
  input  [63:0] io_response_4_bits_command_checkpoint_restartPc,
  input  [63:0] io_response_4_bits_command_checkpoint_architecturalToken,
  input  [63:0] io_response_4_bits_command_checkpoint_memoryToken,
  input  [31:0] io_response_4_bits_command_failedSequence,
  input  [31:0] io_response_4_bits_command_recoveryGeneration,
  input  [63:0] io_response_4_bits_retiredPc,
  input         io_response_4_bits_allCheckerTasksDrained,
  input         io_response_5_valid,
  input  [31:0] io_response_5_bits_command_checkpoint_sequence,
  input  [31:0] io_response_5_bits_command_checkpoint_generation,
  input  [63:0] io_response_5_bits_command_checkpoint_restartPc,
  input  [63:0] io_response_5_bits_command_checkpoint_architecturalToken,
  input  [63:0] io_response_5_bits_command_checkpoint_memoryToken,
  input  [31:0] io_response_5_bits_command_failedSequence,
  input  [31:0] io_response_5_bits_command_recoveryGeneration,
  input  [63:0] io_response_5_bits_retiredPc,
  input         io_response_5_bits_allCheckerTasksDrained,
  output        io_active,
  output        io_freezeRetirement,
  output        io_freezeNewPackages,
  output        io_protocolError,
  output [2:0]  io_phase,
  output        io_events_0_valid,
  output [3:0]  io_events_0_bits_kind,
  output [63:0] io_events_0_bits_recordSequence,
  output [63:0] io_events_0_bits_targetCycle,
  output [31:0] io_events_0_bits_command_checkpoint_sequence,
  output [31:0] io_events_0_bits_command_checkpoint_generation,
  output [63:0] io_events_0_bits_command_checkpoint_restartPc,
  output [63:0] io_events_0_bits_command_checkpoint_architecturalToken,
  output [63:0] io_events_0_bits_command_checkpoint_memoryToken,
  output [31:0] io_events_0_bits_command_failedSequence,
  output [31:0] io_events_0_bits_command_recoveryGeneration,
  output [63:0] io_events_0_bits_retiredPc,
  output        io_events_0_bits_allCheckerTasksDrained,
  output        io_events_1_valid,
  output [3:0]  io_events_1_bits_kind,
  output [63:0] io_events_1_bits_recordSequence,
  output [63:0] io_events_1_bits_targetCycle,
  output [31:0] io_events_1_bits_command_checkpoint_sequence,
  output [31:0] io_events_1_bits_command_checkpoint_generation,
  output [63:0] io_events_1_bits_command_checkpoint_restartPc,
  output [63:0] io_events_1_bits_command_checkpoint_architecturalToken,
  output [63:0] io_events_1_bits_command_checkpoint_memoryToken,
  output [31:0] io_events_1_bits_command_failedSequence,
  output [31:0] io_events_1_bits_command_recoveryGeneration,
  output [63:0] io_events_1_bits_retiredPc,
  output        io_events_1_bits_allCheckerTasksDrained,
  output        io_events_2_valid,
  output [3:0]  io_events_2_bits_kind,
  output [63:0] io_events_2_bits_recordSequence,
  output [63:0] io_events_2_bits_targetCycle,
  output [31:0] io_events_2_bits_command_checkpoint_sequence,
  output [31:0] io_events_2_bits_command_checkpoint_generation,
  output [63:0] io_events_2_bits_command_checkpoint_restartPc,
  output [63:0] io_events_2_bits_command_checkpoint_architecturalToken,
  output [63:0] io_events_2_bits_command_checkpoint_memoryToken,
  output [31:0] io_events_2_bits_command_failedSequence,
  output [31:0] io_events_2_bits_command_recoveryGeneration,
  output [63:0] io_events_2_bits_retiredPc,
  output        io_events_2_bits_allCheckerTasksDrained,
  output        io_events_3_valid,
  output [3:0]  io_events_3_bits_kind,
  output [63:0] io_events_3_bits_recordSequence,
  output [63:0] io_events_3_bits_targetCycle,
  output [31:0] io_events_3_bits_command_checkpoint_sequence,
  output [31:0] io_events_3_bits_command_checkpoint_generation,
  output [63:0] io_events_3_bits_command_checkpoint_restartPc,
  output [63:0] io_events_3_bits_command_checkpoint_architecturalToken,
  output [63:0] io_events_3_bits_command_checkpoint_memoryToken,
  output [31:0] io_events_3_bits_command_failedSequence,
  output [31:0] io_events_3_bits_command_recoveryGeneration,
  output [63:0] io_events_3_bits_retiredPc,
  output        io_events_3_bits_allCheckerTasksDrained,
  output        io_events_4_valid,
  output [3:0]  io_events_4_bits_kind,
  output [63:0] io_events_4_bits_recordSequence,
  output [63:0] io_events_4_bits_targetCycle,
  output [31:0] io_events_4_bits_command_checkpoint_sequence,
  output [31:0] io_events_4_bits_command_checkpoint_generation,
  output [63:0] io_events_4_bits_command_checkpoint_restartPc,
  output [63:0] io_events_4_bits_command_checkpoint_architecturalToken,
  output [63:0] io_events_4_bits_command_checkpoint_memoryToken,
  output [31:0] io_events_4_bits_command_failedSequence,
  output [31:0] io_events_4_bits_command_recoveryGeneration,
  output [63:0] io_events_4_bits_retiredPc,
  output        io_events_4_bits_allCheckerTasksDrained,
  output        io_events_5_valid,
  output [3:0]  io_events_5_bits_kind,
  output [63:0] io_events_5_bits_recordSequence,
  output [63:0] io_events_5_bits_targetCycle,
  output [31:0] io_events_5_bits_command_checkpoint_sequence,
  output [31:0] io_events_5_bits_command_checkpoint_generation,
  output [63:0] io_events_5_bits_command_checkpoint_restartPc,
  output [63:0] io_events_5_bits_command_checkpoint_architecturalToken,
  output [63:0] io_events_5_bits_command_checkpoint_memoryToken,
  output [31:0] io_events_5_bits_command_failedSequence,
  output [31:0] io_events_5_bits_command_recoveryGeneration,
  output [63:0] io_events_5_bits_retiredPc,
  output        io_events_5_bits_allCheckerTasksDrained,
  output        io_events_6_valid,
  output [3:0]  io_events_6_bits_kind,
  output [63:0] io_events_6_bits_recordSequence,
  output [63:0] io_events_6_bits_targetCycle,
  output [31:0] io_events_6_bits_command_checkpoint_sequence,
  output [31:0] io_events_6_bits_command_checkpoint_generation,
  output [63:0] io_events_6_bits_command_checkpoint_restartPc,
  output [63:0] io_events_6_bits_command_checkpoint_architecturalToken,
  output [63:0] io_events_6_bits_command_checkpoint_memoryToken,
  output [31:0] io_events_6_bits_command_failedSequence,
  output [31:0] io_events_6_bits_command_recoveryGeneration,
  output [63:0] io_events_6_bits_retiredPc,
  output        io_events_6_bits_allCheckerTasksDrained,
  output        io_events_7_valid,
  output [3:0]  io_events_7_bits_kind,
  output [63:0] io_events_7_bits_recordSequence,
  output [63:0] io_events_7_bits_targetCycle,
  output [31:0] io_events_7_bits_command_checkpoint_sequence,
  output [31:0] io_events_7_bits_command_checkpoint_generation,
  output [63:0] io_events_7_bits_command_checkpoint_restartPc,
  output [63:0] io_events_7_bits_command_checkpoint_architecturalToken,
  output [63:0] io_events_7_bits_command_checkpoint_memoryToken,
  output [31:0] io_events_7_bits_command_failedSequence,
  output [31:0] io_events_7_bits_command_recoveryGeneration,
  output [63:0] io_events_7_bits_retiredPc,
  output        io_events_7_bits_allCheckerTasksDrained
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [63:0] _RAND_4;
  reg [63:0] _RAND_5;
  reg [63:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [63:0] _RAND_9;
`endif // RANDOMIZE_REG_INIT
  reg [2:0] state; // @[PackageRecoveryController.scala 79:22]
  reg  sent; // @[PackageRecoveryController.scala 80:21]
  reg [31:0] command_checkpoint_sequence; // @[PackageRecoveryController.scala 81:20]
  reg [31:0] command_checkpoint_generation; // @[PackageRecoveryController.scala 81:20]
  reg [63:0] command_checkpoint_restartPc; // @[PackageRecoveryController.scala 81:20]
  reg [63:0] command_checkpoint_architecturalToken; // @[PackageRecoveryController.scala 81:20]
  reg [63:0] command_checkpoint_memoryToken; // @[PackageRecoveryController.scala 81:20]
  reg [31:0] command_failedSequence; // @[PackageRecoveryController.scala 81:20]
  reg [31:0] command_recoveryGeneration; // @[PackageRecoveryController.scala 81:20]
  reg [63:0] eventSequence; // @[PackageRecoveryController.scala 83:30]
  wire [31:0] acceptedCommand_recoveryGeneration = io_checkpoint_bits_generation + 32'h1; // @[PackageRecoveryController.scala 88:71]
  wire  _io_protocolError_T = state == 3'h7; // @[PackageRecoveryController.scala 92:29]
  wire  _replayExecuting_T = state == 3'h6; // @[PackageRecoveryController.scala 95:31]
  wire  _replayExecuting_T_1 = state == 3'h5; // @[PackageRecoveryController.scala 95:49]
  wire  replayExecuting = state == 3'h6 | state == 3'h5 & sent; // @[PackageRecoveryController.scala 95:39]
  wire  _badResponse_T = state == 3'h1; // @[PackageRecoveryController.scala 139:37]
  wire  _badResponse_T_1 = io_request_0_ready & io_request_0_valid; // @[Decoupled.scala 51:35]
  wire  _badResponse_T_2 = sent | _badResponse_T_1; // @[PackageRecoveryController.scala 140:13]
  wire  _badResponse_T_3 = state == 3'h1 & _badResponse_T_2; // @[PackageRecoveryController.scala 139:51]
  wire [319:0] _badResponse_T_4 = {io_response_0_bits_command_checkpoint_sequence,
    io_response_0_bits_command_checkpoint_generation,io_response_0_bits_command_checkpoint_restartPc,
    io_response_0_bits_command_checkpoint_architecturalToken,io_response_0_bits_command_checkpoint_memoryToken,
    io_response_0_bits_command_failedSequence,io_response_0_bits_command_recoveryGeneration}; // @[PackageRecoveryController.scala 141:35]
  wire [319:0] _badResponse_T_5 = {command_checkpoint_sequence,command_checkpoint_generation,
    command_checkpoint_restartPc,command_checkpoint_architecturalToken,command_checkpoint_memoryToken,
    command_failedSequence,command_recoveryGeneration}; // @[PackageRecoveryController.scala 141:54]
  wire  _badResponse_T_6 = _badResponse_T_4 == _badResponse_T_5; // @[PackageRecoveryController.scala 141:42]
  wire  _badResponse_T_7 = _badResponse_T_3 & _badResponse_T_6; // @[PackageRecoveryController.scala 140:36]
  wire  _badResponse_T_10 = io_response_0_valid & ~_badResponse_T_7; // @[PackageRecoveryController.scala 139:26]
  wire  _badResponse_T_11 = state == 3'h2; // @[PackageRecoveryController.scala 139:37]
  wire  _badResponse_T_12 = io_request_1_ready & io_request_1_valid; // @[Decoupled.scala 51:35]
  wire  _badResponse_T_13 = sent | _badResponse_T_12; // @[PackageRecoveryController.scala 140:13]
  wire  _badResponse_T_14 = state == 3'h2 & _badResponse_T_13; // @[PackageRecoveryController.scala 139:51]
  wire [319:0] _badResponse_T_15 = {io_response_1_bits_command_checkpoint_sequence,
    io_response_1_bits_command_checkpoint_generation,io_response_1_bits_command_checkpoint_restartPc,
    io_response_1_bits_command_checkpoint_architecturalToken,io_response_1_bits_command_checkpoint_memoryToken,
    io_response_1_bits_command_failedSequence,io_response_1_bits_command_recoveryGeneration}; // @[PackageRecoveryController.scala 141:35]
  wire  _badResponse_T_17 = _badResponse_T_15 == _badResponse_T_5; // @[PackageRecoveryController.scala 141:42]
  wire  _badResponse_T_18 = _badResponse_T_14 & _badResponse_T_17; // @[PackageRecoveryController.scala 140:36]
  wire  _badResponse_T_21 = io_response_1_valid & ~_badResponse_T_18; // @[PackageRecoveryController.scala 139:26]
  wire  _badResponse_T_22 = state == 3'h3; // @[PackageRecoveryController.scala 139:37]
  wire  _badResponse_T_23 = io_request_2_ready & io_request_2_valid; // @[Decoupled.scala 51:35]
  wire  _badResponse_T_24 = sent | _badResponse_T_23; // @[PackageRecoveryController.scala 140:13]
  wire  _badResponse_T_25 = state == 3'h3 & _badResponse_T_24; // @[PackageRecoveryController.scala 139:51]
  wire [319:0] _badResponse_T_26 = {io_response_2_bits_command_checkpoint_sequence,
    io_response_2_bits_command_checkpoint_generation,io_response_2_bits_command_checkpoint_restartPc,
    io_response_2_bits_command_checkpoint_architecturalToken,io_response_2_bits_command_checkpoint_memoryToken,
    io_response_2_bits_command_failedSequence,io_response_2_bits_command_recoveryGeneration}; // @[PackageRecoveryController.scala 141:35]
  wire  _badResponse_T_28 = _badResponse_T_26 == _badResponse_T_5; // @[PackageRecoveryController.scala 141:42]
  wire  _badResponse_T_29 = _badResponse_T_25 & _badResponse_T_28; // @[PackageRecoveryController.scala 140:36]
  wire  _badResponse_T_32 = io_response_2_valid & ~_badResponse_T_29; // @[PackageRecoveryController.scala 139:26]
  wire  _badResponse_T_33 = state == 3'h4; // @[PackageRecoveryController.scala 139:37]
  wire  _badResponse_T_34 = io_request_3_ready & io_request_3_valid; // @[Decoupled.scala 51:35]
  wire  _badResponse_T_35 = sent | _badResponse_T_34; // @[PackageRecoveryController.scala 140:13]
  wire  _badResponse_T_36 = state == 3'h4 & _badResponse_T_35; // @[PackageRecoveryController.scala 139:51]
  wire [319:0] _badResponse_T_37 = {io_response_3_bits_command_checkpoint_sequence,
    io_response_3_bits_command_checkpoint_generation,io_response_3_bits_command_checkpoint_restartPc,
    io_response_3_bits_command_checkpoint_architecturalToken,io_response_3_bits_command_checkpoint_memoryToken,
    io_response_3_bits_command_failedSequence,io_response_3_bits_command_recoveryGeneration}; // @[PackageRecoveryController.scala 141:35]
  wire  _badResponse_T_39 = _badResponse_T_37 == _badResponse_T_5; // @[PackageRecoveryController.scala 141:42]
  wire  _badResponse_T_40 = _badResponse_T_36 & _badResponse_T_39; // @[PackageRecoveryController.scala 140:36]
  wire  _badResponse_T_43 = io_response_3_valid & ~_badResponse_T_40; // @[PackageRecoveryController.scala 139:26]
  wire  _badResponse_T_45 = io_request_4_ready & io_request_4_valid; // @[Decoupled.scala 51:35]
  wire  _badResponse_T_46 = sent | _badResponse_T_45; // @[PackageRecoveryController.scala 140:13]
  wire  _badResponse_T_47 = _replayExecuting_T_1 & _badResponse_T_46; // @[PackageRecoveryController.scala 139:51]
  wire [319:0] _badResponse_T_48 = {io_response_4_bits_command_checkpoint_sequence,
    io_response_4_bits_command_checkpoint_generation,io_response_4_bits_command_checkpoint_restartPc,
    io_response_4_bits_command_checkpoint_architecturalToken,io_response_4_bits_command_checkpoint_memoryToken,
    io_response_4_bits_command_failedSequence,io_response_4_bits_command_recoveryGeneration}; // @[PackageRecoveryController.scala 141:35]
  wire  _badResponse_T_50 = _badResponse_T_48 == _badResponse_T_5; // @[PackageRecoveryController.scala 141:42]
  wire  _badResponse_T_51 = _badResponse_T_47 & _badResponse_T_50; // @[PackageRecoveryController.scala 140:36]
  wire  _badResponse_T_52 = io_response_4_bits_retiredPc == command_checkpoint_restartPc; // @[PackageRecoveryController.scala 142:50]
  wire  _badResponse_T_53 = _badResponse_T_51 & _badResponse_T_52; // @[PackageRecoveryController.scala 141:61]
  wire  _badResponse_T_55 = io_response_4_valid & ~_badResponse_T_53; // @[PackageRecoveryController.scala 139:26]
  wire  _badResponse_T_57 = io_request_5_ready & io_request_5_valid; // @[Decoupled.scala 51:35]
  wire  _badResponse_T_58 = sent | _badResponse_T_57; // @[PackageRecoveryController.scala 140:13]
  wire  _badResponse_T_59 = _replayExecuting_T & _badResponse_T_58; // @[PackageRecoveryController.scala 139:51]
  wire [319:0] _badResponse_T_60 = {io_response_5_bits_command_checkpoint_sequence,
    io_response_5_bits_command_checkpoint_generation,io_response_5_bits_command_checkpoint_restartPc,
    io_response_5_bits_command_checkpoint_architecturalToken,io_response_5_bits_command_checkpoint_memoryToken,
    io_response_5_bits_command_failedSequence,io_response_5_bits_command_recoveryGeneration}; // @[PackageRecoveryController.scala 141:35]
  wire  _badResponse_T_62 = _badResponse_T_60 == _badResponse_T_5; // @[PackageRecoveryController.scala 141:42]
  wire  _badResponse_T_63 = _badResponse_T_59 & _badResponse_T_62; // @[PackageRecoveryController.scala 140:36]
  wire  _badResponse_T_64 = _badResponse_T_63 & io_response_5_bits_allCheckerTasksDrained; // @[PackageRecoveryController.scala 141:61]
  wire  _badResponse_T_66 = io_response_5_valid & ~_badResponse_T_64; // @[PackageRecoveryController.scala 139:26]
  wire  badResponse = _badResponse_T_10 | _badResponse_T_21 | _badResponse_T_32 | _badResponse_T_43 | _badResponse_T_55
     | _badResponse_T_66; // @[PackageRecoveryController.scala 144:14]
  wire  _T = io_failure_ready & io_failure_valid; // @[Decoupled.scala 51:35]
  wire  _legal_T_1 = io_checkpoint_valid & io_failure_bits_allocated & io_failure_bits_comparedMismatch; // @[PackageRecoveryController.scala 100:66]
  wire  _legal_T_2 = io_failure_bits_generation == io_checkpoint_bits_generation; // @[PackageRecoveryController.scala 102:34]
  wire  _legal_T_3 = _legal_T_1 & _legal_T_2; // @[PackageRecoveryController.scala 101:40]
  wire  _legal_T_4 = io_failure_bits_sequence > io_checkpoint_bits_sequence; // @[PackageRecoveryController.scala 103:32]
  wire  _legal_T_5 = _legal_T_3 & _legal_T_4; // @[PackageRecoveryController.scala 102:68]
  wire  _legal_T_6 = io_checkpoint_bits_generation != 32'hffffffff; // @[PackageRecoveryController.scala 104:37]
  wire  legal = _legal_T_5 & _legal_T_6; // @[PackageRecoveryController.scala 103:62]
  wire [2:0] _GEN_7 = legal ? 3'h1 : 3'h7; // @[PackageRecoveryController.scala 105:18 107:13 112:13]
  wire  _GEN_8 = legal ? 1'h0 : sent; // @[PackageRecoveryController.scala 105:18 108:12 80:21]
  wire [2:0] _GEN_18 = _T ? _GEN_7 : state; // @[PackageRecoveryController.scala 79:22 99:26]
  wire  _GEN_19 = _T ? _GEN_8 : sent; // @[PackageRecoveryController.scala 80:21 99:26]
  wire  _GEN_20 = _T & legal; // @[PackageRecoveryController.scala 99:26 84:27]
  wire  _GEN_22 = _badResponse_T & _badResponse_T_1 | _GEN_19; // @[PackageRecoveryController.scala 120:{42,49}]
  wire [2:0] _GEN_24 = _badResponse_T_7 ? 3'h2 : 3'h7; // @[PackageRecoveryController.scala 128:36 130:15 133:15]
  wire  _GEN_25 = _badResponse_T_7 ? 1'h0 : _GEN_22; // @[PackageRecoveryController.scala 128:36 131:14]
  wire  _GEN_26 = io_response_0_valid & _badResponse_T_7; // @[PackageRecoveryController.scala 121:33 84:27]
  wire [2:0] _GEN_27 = io_response_0_valid ? _GEN_24 : _GEN_18; // @[PackageRecoveryController.scala 121:33]
  wire  _GEN_28 = io_response_0_valid ? _GEN_25 : _GEN_22; // @[PackageRecoveryController.scala 121:33]
  wire  _GEN_29 = _badResponse_T_11 & _badResponse_T_12 | _GEN_28; // @[PackageRecoveryController.scala 120:{42,49}]
  wire [2:0] _GEN_31 = _badResponse_T_18 ? 3'h3 : 3'h7; // @[PackageRecoveryController.scala 128:36 130:15 133:15]
  wire  _GEN_32 = _badResponse_T_18 ? 1'h0 : _GEN_29; // @[PackageRecoveryController.scala 128:36 131:14]
  wire  _GEN_33 = io_response_1_valid & _badResponse_T_18; // @[PackageRecoveryController.scala 121:33 84:27]
  wire [2:0] _GEN_34 = io_response_1_valid ? _GEN_31 : _GEN_27; // @[PackageRecoveryController.scala 121:33]
  wire  _GEN_35 = io_response_1_valid ? _GEN_32 : _GEN_29; // @[PackageRecoveryController.scala 121:33]
  wire  _GEN_36 = _badResponse_T_22 & _badResponse_T_23 | _GEN_35; // @[PackageRecoveryController.scala 120:{42,49}]
  wire [2:0] _GEN_38 = _badResponse_T_29 ? 3'h4 : 3'h7; // @[PackageRecoveryController.scala 128:36 130:15 133:15]
  wire  _GEN_39 = _badResponse_T_29 ? 1'h0 : _GEN_36; // @[PackageRecoveryController.scala 128:36 131:14]
  wire  _GEN_40 = io_response_2_valid & _badResponse_T_29; // @[PackageRecoveryController.scala 121:33 84:27]
  wire [2:0] _GEN_41 = io_response_2_valid ? _GEN_38 : _GEN_34; // @[PackageRecoveryController.scala 121:33]
  wire  _GEN_42 = io_response_2_valid ? _GEN_39 : _GEN_36; // @[PackageRecoveryController.scala 121:33]
  wire  _GEN_43 = _badResponse_T_33 & _badResponse_T_34 | _GEN_42; // @[PackageRecoveryController.scala 120:{42,49}]
  wire [2:0] _GEN_45 = _badResponse_T_40 ? 3'h5 : 3'h7; // @[PackageRecoveryController.scala 128:36 130:15 133:15]
  wire  _GEN_46 = _badResponse_T_40 ? 1'h0 : _GEN_43; // @[PackageRecoveryController.scala 128:36 131:14]
  wire  _GEN_47 = io_response_3_valid & _badResponse_T_40; // @[PackageRecoveryController.scala 121:33 84:27]
  wire [2:0] _GEN_48 = io_response_3_valid ? _GEN_45 : _GEN_41; // @[PackageRecoveryController.scala 121:33]
  wire  _GEN_49 = io_response_3_valid ? _GEN_46 : _GEN_43; // @[PackageRecoveryController.scala 121:33]
  wire  _GEN_50 = _replayExecuting_T_1 & _badResponse_T_45 | _GEN_49; // @[PackageRecoveryController.scala 120:{42,49}]
  wire [2:0] _GEN_52 = _badResponse_T_53 ? 3'h6 : 3'h7; // @[PackageRecoveryController.scala 128:36 130:15 133:15]
  wire  _GEN_53 = _badResponse_T_53 ? 1'h0 : _GEN_50; // @[PackageRecoveryController.scala 128:36 131:14]
  wire  _GEN_54 = io_response_4_valid & _badResponse_T_53; // @[PackageRecoveryController.scala 121:33 84:27]
  wire  _GEN_56 = io_response_4_valid ? _GEN_53 : _GEN_50; // @[PackageRecoveryController.scala 121:33]
  wire  _GEN_57 = _replayExecuting_T & _badResponse_T_57 | _GEN_56; // @[PackageRecoveryController.scala 120:{42,49}]
  wire  _GEN_61 = io_response_5_valid & _badResponse_T_64; // @[PackageRecoveryController.scala 121:33 84:27]
  wire  eventFire_0 = badResponse | _io_protocolError_T ? 1'h0 : _GEN_20; // @[PackageRecoveryController.scala 145:42 147:41]
  wire  eventFire_2 = badResponse | _io_protocolError_T ? 1'h0 : _GEN_26; // @[PackageRecoveryController.scala 145:42 147:41]
  wire  eventFire_3 = badResponse | _io_protocolError_T ? 1'h0 : _GEN_33; // @[PackageRecoveryController.scala 145:42 147:41]
  wire  eventFire_4 = badResponse | _io_protocolError_T ? 1'h0 : _GEN_40; // @[PackageRecoveryController.scala 145:42 147:41]
  wire  eventFire_5 = badResponse | _io_protocolError_T ? 1'h0 : _GEN_47; // @[PackageRecoveryController.scala 145:42 147:41]
  wire  eventFire_6 = badResponse | _io_protocolError_T ? 1'h0 : _GEN_54; // @[PackageRecoveryController.scala 145:42 147:41]
  wire  eventFire_7 = badResponse | _io_protocolError_T ? 1'h0 : _GEN_61; // @[PackageRecoveryController.scala 145:42 147:41]
  wire [64:0] _io_events_0_bits_recordSequence_T = {{1'd0}, eventSequence}; // @[PackageRecoveryController.scala 157:55]
  wire [63:0] _GEN_74 = {{63'd0}, eventFire_0}; // @[PackageRecoveryController.scala 157:55]
  wire [1:0] _io_events_2_bits_recordSequence_T = eventFire_0 + eventFire_0; // @[Bitwise.scala 51:90]
  wire [63:0] _GEN_75 = {{62'd0}, _io_events_2_bits_recordSequence_T}; // @[PackageRecoveryController.scala 157:55]
  wire [1:0] _io_events_3_bits_recordSequence_T = eventFire_0 + eventFire_2; // @[Bitwise.scala 51:90]
  wire [1:0] _GEN_76 = {{1'd0}, eventFire_0}; // @[Bitwise.scala 51:90]
  wire [2:0] _io_events_3_bits_recordSequence_T_2 = _GEN_76 + _io_events_3_bits_recordSequence_T; // @[Bitwise.scala 51:90]
  wire [63:0] _GEN_77 = {{62'd0}, _io_events_3_bits_recordSequence_T_2[1:0]}; // @[PackageRecoveryController.scala 157:55]
  wire [1:0] _io_events_4_bits_recordSequence_T_2 = eventFire_2 + eventFire_3; // @[Bitwise.scala 51:90]
  wire [2:0] _io_events_4_bits_recordSequence_T_4 = _io_events_2_bits_recordSequence_T +
    _io_events_4_bits_recordSequence_T_2; // @[Bitwise.scala 51:90]
  wire [63:0] _GEN_78 = {{61'd0}, _io_events_4_bits_recordSequence_T_4}; // @[PackageRecoveryController.scala 157:55]
  wire [1:0] _io_events_5_bits_recordSequence_T_2 = eventFire_3 + eventFire_4; // @[Bitwise.scala 51:90]
  wire [1:0] _GEN_79 = {{1'd0}, eventFire_2}; // @[Bitwise.scala 51:90]
  wire [2:0] _io_events_5_bits_recordSequence_T_4 = _GEN_79 + _io_events_5_bits_recordSequence_T_2; // @[Bitwise.scala 51:90]
  wire [2:0] _io_events_5_bits_recordSequence_T_6 = _io_events_2_bits_recordSequence_T +
    _io_events_5_bits_recordSequence_T_4[1:0]; // @[Bitwise.scala 51:90]
  wire [63:0] _GEN_80 = {{61'd0}, _io_events_5_bits_recordSequence_T_6}; // @[PackageRecoveryController.scala 157:55]
  wire [1:0] _io_events_6_bits_recordSequence_T_4 = eventFire_4 + eventFire_5; // @[Bitwise.scala 51:90]
  wire [1:0] _GEN_82 = {{1'd0}, eventFire_3}; // @[Bitwise.scala 51:90]
  wire [2:0] _io_events_6_bits_recordSequence_T_6 = _GEN_82 + _io_events_6_bits_recordSequence_T_4; // @[Bitwise.scala 51:90]
  wire [2:0] _io_events_6_bits_recordSequence_T_8 = _io_events_3_bits_recordSequence_T_2[1:0] +
    _io_events_6_bits_recordSequence_T_6[1:0]; // @[Bitwise.scala 51:90]
  wire [63:0] _GEN_83 = {{61'd0}, _io_events_6_bits_recordSequence_T_8}; // @[PackageRecoveryController.scala 157:55]
  wire [1:0] _io_events_7_bits_recordSequence_T_6 = eventFire_5 + eventFire_6; // @[Bitwise.scala 51:90]
  wire [2:0] _io_events_7_bits_recordSequence_T_8 = _io_events_5_bits_recordSequence_T_2 +
    _io_events_7_bits_recordSequence_T_6; // @[Bitwise.scala 51:90]
  wire [2:0] _GEN_85 = {{1'd0}, _io_events_3_bits_recordSequence_T_2[1:0]}; // @[Bitwise.scala 51:90]
  wire [3:0] _io_events_7_bits_recordSequence_T_10 = _GEN_85 + _io_events_7_bits_recordSequence_T_8; // @[Bitwise.scala 51:90]
  wire [63:0] _GEN_86 = {{61'd0}, _io_events_7_bits_recordSequence_T_10[2:0]}; // @[PackageRecoveryController.scala 157:55]
  wire [7:0] _T_21 = {eventFire_7,eventFire_6,eventFire_5,eventFire_4,eventFire_3,eventFire_2,eventFire_0,eventFire_0}; // @[PackageRecoveryController.scala 160:19]
  wire [1:0] _eventSequence_T_8 = eventFire_6 + eventFire_7; // @[Bitwise.scala 51:90]
  wire [2:0] _eventSequence_T_10 = _io_events_6_bits_recordSequence_T_4 + _eventSequence_T_8; // @[Bitwise.scala 51:90]
  wire [3:0] _eventSequence_T_12 = _io_events_4_bits_recordSequence_T_4 + _eventSequence_T_10; // @[Bitwise.scala 51:90]
  wire [63:0] _GEN_87 = {{60'd0}, _eventSequence_T_12}; // @[PackageRecoveryController.scala 160:64]
  wire [63:0] _eventSequence_T_15 = eventSequence + _GEN_87; // @[PackageRecoveryController.scala 160:64]
  assign io_failure_ready = state == 3'h0; // @[PackageRecoveryController.scala 93:29]
  assign io_request_0_valid = _badResponse_T & ~sent; // @[PackageRecoveryController.scala 118:36]
  assign io_request_0_bits_checkpoint_sequence = command_checkpoint_sequence; // @[PackageRecoveryController.scala 119:24]
  assign io_request_0_bits_checkpoint_generation = command_checkpoint_generation; // @[PackageRecoveryController.scala 119:24]
  assign io_request_0_bits_checkpoint_restartPc = command_checkpoint_restartPc; // @[PackageRecoveryController.scala 119:24]
  assign io_request_0_bits_checkpoint_architecturalToken = command_checkpoint_architecturalToken; // @[PackageRecoveryController.scala 119:24]
  assign io_request_0_bits_checkpoint_memoryToken = command_checkpoint_memoryToken; // @[PackageRecoveryController.scala 119:24]
  assign io_request_0_bits_failedSequence = command_failedSequence; // @[PackageRecoveryController.scala 119:24]
  assign io_request_0_bits_recoveryGeneration = command_recoveryGeneration; // @[PackageRecoveryController.scala 119:24]
  assign io_request_1_valid = _badResponse_T_11 & ~sent; // @[PackageRecoveryController.scala 118:36]
  assign io_request_1_bits_checkpoint_sequence = command_checkpoint_sequence; // @[PackageRecoveryController.scala 119:24]
  assign io_request_1_bits_checkpoint_generation = command_checkpoint_generation; // @[PackageRecoveryController.scala 119:24]
  assign io_request_1_bits_checkpoint_restartPc = command_checkpoint_restartPc; // @[PackageRecoveryController.scala 119:24]
  assign io_request_1_bits_checkpoint_architecturalToken = command_checkpoint_architecturalToken; // @[PackageRecoveryController.scala 119:24]
  assign io_request_1_bits_checkpoint_memoryToken = command_checkpoint_memoryToken; // @[PackageRecoveryController.scala 119:24]
  assign io_request_1_bits_failedSequence = command_failedSequence; // @[PackageRecoveryController.scala 119:24]
  assign io_request_1_bits_recoveryGeneration = command_recoveryGeneration; // @[PackageRecoveryController.scala 119:24]
  assign io_request_2_valid = _badResponse_T_22 & ~sent; // @[PackageRecoveryController.scala 118:36]
  assign io_request_2_bits_checkpoint_sequence = command_checkpoint_sequence; // @[PackageRecoveryController.scala 119:24]
  assign io_request_2_bits_checkpoint_generation = command_checkpoint_generation; // @[PackageRecoveryController.scala 119:24]
  assign io_request_2_bits_checkpoint_restartPc = command_checkpoint_restartPc; // @[PackageRecoveryController.scala 119:24]
  assign io_request_2_bits_checkpoint_architecturalToken = command_checkpoint_architecturalToken; // @[PackageRecoveryController.scala 119:24]
  assign io_request_2_bits_checkpoint_memoryToken = command_checkpoint_memoryToken; // @[PackageRecoveryController.scala 119:24]
  assign io_request_2_bits_failedSequence = command_failedSequence; // @[PackageRecoveryController.scala 119:24]
  assign io_request_2_bits_recoveryGeneration = command_recoveryGeneration; // @[PackageRecoveryController.scala 119:24]
  assign io_request_3_valid = _badResponse_T_33 & ~sent; // @[PackageRecoveryController.scala 118:36]
  assign io_request_3_bits_checkpoint_sequence = command_checkpoint_sequence; // @[PackageRecoveryController.scala 119:24]
  assign io_request_3_bits_checkpoint_generation = command_checkpoint_generation; // @[PackageRecoveryController.scala 119:24]
  assign io_request_3_bits_checkpoint_restartPc = command_checkpoint_restartPc; // @[PackageRecoveryController.scala 119:24]
  assign io_request_3_bits_checkpoint_architecturalToken = command_checkpoint_architecturalToken; // @[PackageRecoveryController.scala 119:24]
  assign io_request_3_bits_checkpoint_memoryToken = command_checkpoint_memoryToken; // @[PackageRecoveryController.scala 119:24]
  assign io_request_3_bits_failedSequence = command_failedSequence; // @[PackageRecoveryController.scala 119:24]
  assign io_request_3_bits_recoveryGeneration = command_recoveryGeneration; // @[PackageRecoveryController.scala 119:24]
  assign io_request_4_valid = _replayExecuting_T_1 & ~sent; // @[PackageRecoveryController.scala 118:36]
  assign io_request_4_bits_checkpoint_sequence = command_checkpoint_sequence; // @[PackageRecoveryController.scala 119:24]
  assign io_request_4_bits_checkpoint_generation = command_checkpoint_generation; // @[PackageRecoveryController.scala 119:24]
  assign io_request_4_bits_checkpoint_restartPc = command_checkpoint_restartPc; // @[PackageRecoveryController.scala 119:24]
  assign io_request_4_bits_checkpoint_architecturalToken = command_checkpoint_architecturalToken; // @[PackageRecoveryController.scala 119:24]
  assign io_request_4_bits_checkpoint_memoryToken = command_checkpoint_memoryToken; // @[PackageRecoveryController.scala 119:24]
  assign io_request_4_bits_failedSequence = command_failedSequence; // @[PackageRecoveryController.scala 119:24]
  assign io_request_4_bits_recoveryGeneration = command_recoveryGeneration; // @[PackageRecoveryController.scala 119:24]
  assign io_request_5_valid = _replayExecuting_T & ~sent; // @[PackageRecoveryController.scala 118:36]
  assign io_request_5_bits_checkpoint_sequence = command_checkpoint_sequence; // @[PackageRecoveryController.scala 119:24]
  assign io_request_5_bits_checkpoint_generation = command_checkpoint_generation; // @[PackageRecoveryController.scala 119:24]
  assign io_request_5_bits_checkpoint_restartPc = command_checkpoint_restartPc; // @[PackageRecoveryController.scala 119:24]
  assign io_request_5_bits_checkpoint_architecturalToken = command_checkpoint_architecturalToken; // @[PackageRecoveryController.scala 119:24]
  assign io_request_5_bits_checkpoint_memoryToken = command_checkpoint_memoryToken; // @[PackageRecoveryController.scala 119:24]
  assign io_request_5_bits_failedSequence = command_failedSequence; // @[PackageRecoveryController.scala 119:24]
  assign io_request_5_bits_recoveryGeneration = command_recoveryGeneration; // @[PackageRecoveryController.scala 119:24]
  assign io_active = state != 3'h0; // @[PackageRecoveryController.scala 90:22]
  assign io_freezeRetirement = io_active & ~replayExecuting | io_failure_valid | badResponse; // @[PackageRecoveryController.scala 96:78]
  assign io_freezeNewPackages = io_freezeRetirement; // @[PackageRecoveryController.scala 97:24]
  assign io_protocolError = state == 3'h7; // @[PackageRecoveryController.scala 92:29]
  assign io_phase = state; // @[PackageRecoveryController.scala 91:12]
  assign io_events_0_valid = badResponse | _io_protocolError_T ? 1'h0 : _GEN_20; // @[PackageRecoveryController.scala 145:42 147:41]
  assign io_events_0_bits_kind = 4'h0; // @[PackageRecoveryController.scala 151:28]
  assign io_events_0_bits_recordSequence = _io_events_0_bits_recordSequence_T[63:0]; // @[PackageRecoveryController.scala 157:55]
  assign io_events_0_bits_targetCycle = io_targetCycle; // @[PackageRecoveryController.scala 152:35]
  assign io_events_0_bits_command_checkpoint_sequence = _T ? io_checkpoint_bits_sequence : command_checkpoint_sequence; // @[PackageRecoveryController.scala 153:37]
  assign io_events_0_bits_command_checkpoint_generation = _T ? io_checkpoint_bits_generation :
    command_checkpoint_generation; // @[PackageRecoveryController.scala 153:37]
  assign io_events_0_bits_command_checkpoint_restartPc = _T ? io_checkpoint_bits_restartPc :
    command_checkpoint_restartPc; // @[PackageRecoveryController.scala 153:37]
  assign io_events_0_bits_command_checkpoint_architecturalToken = _T ? io_checkpoint_bits_architecturalToken :
    command_checkpoint_architecturalToken; // @[PackageRecoveryController.scala 153:37]
  assign io_events_0_bits_command_checkpoint_memoryToken = _T ? io_checkpoint_bits_memoryToken :
    command_checkpoint_memoryToken; // @[PackageRecoveryController.scala 153:37]
  assign io_events_0_bits_command_failedSequence = _T ? io_failure_bits_sequence : command_failedSequence; // @[PackageRecoveryController.scala 153:37]
  assign io_events_0_bits_command_recoveryGeneration = _T ? acceptedCommand_recoveryGeneration :
    command_recoveryGeneration; // @[PackageRecoveryController.scala 153:37]
  assign io_events_0_bits_retiredPc = 64'h0; // @[PackageRecoveryController.scala 154:33]
  assign io_events_0_bits_allCheckerTasksDrained = 1'h0; // @[PackageRecoveryController.scala 155:46]
  assign io_events_1_valid = badResponse | _io_protocolError_T ? 1'h0 : _GEN_20; // @[PackageRecoveryController.scala 145:42 147:41]
  assign io_events_1_bits_kind = 4'h1; // @[PackageRecoveryController.scala 151:28]
  assign io_events_1_bits_recordSequence = eventSequence + _GEN_74; // @[PackageRecoveryController.scala 157:55]
  assign io_events_1_bits_targetCycle = io_targetCycle; // @[PackageRecoveryController.scala 152:35]
  assign io_events_1_bits_command_checkpoint_sequence = _T ? io_checkpoint_bits_sequence : command_checkpoint_sequence; // @[PackageRecoveryController.scala 153:37]
  assign io_events_1_bits_command_checkpoint_generation = _T ? io_checkpoint_bits_generation :
    command_checkpoint_generation; // @[PackageRecoveryController.scala 153:37]
  assign io_events_1_bits_command_checkpoint_restartPc = _T ? io_checkpoint_bits_restartPc :
    command_checkpoint_restartPc; // @[PackageRecoveryController.scala 153:37]
  assign io_events_1_bits_command_checkpoint_architecturalToken = _T ? io_checkpoint_bits_architecturalToken :
    command_checkpoint_architecturalToken; // @[PackageRecoveryController.scala 153:37]
  assign io_events_1_bits_command_checkpoint_memoryToken = _T ? io_checkpoint_bits_memoryToken :
    command_checkpoint_memoryToken; // @[PackageRecoveryController.scala 153:37]
  assign io_events_1_bits_command_failedSequence = _T ? io_failure_bits_sequence : command_failedSequence; // @[PackageRecoveryController.scala 153:37]
  assign io_events_1_bits_command_recoveryGeneration = _T ? acceptedCommand_recoveryGeneration :
    command_recoveryGeneration; // @[PackageRecoveryController.scala 153:37]
  assign io_events_1_bits_retiredPc = 64'h0; // @[PackageRecoveryController.scala 154:33]
  assign io_events_1_bits_allCheckerTasksDrained = 1'h0; // @[PackageRecoveryController.scala 155:46]
  assign io_events_2_valid = badResponse | _io_protocolError_T ? 1'h0 : _GEN_26; // @[PackageRecoveryController.scala 145:42 147:41]
  assign io_events_2_bits_kind = 4'h2; // @[PackageRecoveryController.scala 151:28]
  assign io_events_2_bits_recordSequence = eventSequence + _GEN_75; // @[PackageRecoveryController.scala 157:55]
  assign io_events_2_bits_targetCycle = io_targetCycle; // @[PackageRecoveryController.scala 152:35]
  assign io_events_2_bits_command_checkpoint_sequence = _T ? io_checkpoint_bits_sequence : command_checkpoint_sequence; // @[PackageRecoveryController.scala 153:37]
  assign io_events_2_bits_command_checkpoint_generation = _T ? io_checkpoint_bits_generation :
    command_checkpoint_generation; // @[PackageRecoveryController.scala 153:37]
  assign io_events_2_bits_command_checkpoint_restartPc = _T ? io_checkpoint_bits_restartPc :
    command_checkpoint_restartPc; // @[PackageRecoveryController.scala 153:37]
  assign io_events_2_bits_command_checkpoint_architecturalToken = _T ? io_checkpoint_bits_architecturalToken :
    command_checkpoint_architecturalToken; // @[PackageRecoveryController.scala 153:37]
  assign io_events_2_bits_command_checkpoint_memoryToken = _T ? io_checkpoint_bits_memoryToken :
    command_checkpoint_memoryToken; // @[PackageRecoveryController.scala 153:37]
  assign io_events_2_bits_command_failedSequence = _T ? io_failure_bits_sequence : command_failedSequence; // @[PackageRecoveryController.scala 153:37]
  assign io_events_2_bits_command_recoveryGeneration = _T ? acceptedCommand_recoveryGeneration :
    command_recoveryGeneration; // @[PackageRecoveryController.scala 153:37]
  assign io_events_2_bits_retiredPc = 64'h0; // @[PackageRecoveryController.scala 154:33]
  assign io_events_2_bits_allCheckerTasksDrained = 1'h0; // @[PackageRecoveryController.scala 155:46]
  assign io_events_3_valid = badResponse | _io_protocolError_T ? 1'h0 : _GEN_33; // @[PackageRecoveryController.scala 145:42 147:41]
  assign io_events_3_bits_kind = 4'h3; // @[PackageRecoveryController.scala 151:28]
  assign io_events_3_bits_recordSequence = eventSequence + _GEN_77; // @[PackageRecoveryController.scala 157:55]
  assign io_events_3_bits_targetCycle = io_targetCycle; // @[PackageRecoveryController.scala 152:35]
  assign io_events_3_bits_command_checkpoint_sequence = _T ? io_checkpoint_bits_sequence : command_checkpoint_sequence; // @[PackageRecoveryController.scala 153:37]
  assign io_events_3_bits_command_checkpoint_generation = _T ? io_checkpoint_bits_generation :
    command_checkpoint_generation; // @[PackageRecoveryController.scala 153:37]
  assign io_events_3_bits_command_checkpoint_restartPc = _T ? io_checkpoint_bits_restartPc :
    command_checkpoint_restartPc; // @[PackageRecoveryController.scala 153:37]
  assign io_events_3_bits_command_checkpoint_architecturalToken = _T ? io_checkpoint_bits_architecturalToken :
    command_checkpoint_architecturalToken; // @[PackageRecoveryController.scala 153:37]
  assign io_events_3_bits_command_checkpoint_memoryToken = _T ? io_checkpoint_bits_memoryToken :
    command_checkpoint_memoryToken; // @[PackageRecoveryController.scala 153:37]
  assign io_events_3_bits_command_failedSequence = _T ? io_failure_bits_sequence : command_failedSequence; // @[PackageRecoveryController.scala 153:37]
  assign io_events_3_bits_command_recoveryGeneration = _T ? acceptedCommand_recoveryGeneration :
    command_recoveryGeneration; // @[PackageRecoveryController.scala 153:37]
  assign io_events_3_bits_retiredPc = 64'h0; // @[PackageRecoveryController.scala 154:33]
  assign io_events_3_bits_allCheckerTasksDrained = 1'h0; // @[PackageRecoveryController.scala 155:46]
  assign io_events_4_valid = badResponse | _io_protocolError_T ? 1'h0 : _GEN_40; // @[PackageRecoveryController.scala 145:42 147:41]
  assign io_events_4_bits_kind = 4'h4; // @[PackageRecoveryController.scala 151:28]
  assign io_events_4_bits_recordSequence = eventSequence + _GEN_78; // @[PackageRecoveryController.scala 157:55]
  assign io_events_4_bits_targetCycle = io_targetCycle; // @[PackageRecoveryController.scala 152:35]
  assign io_events_4_bits_command_checkpoint_sequence = _T ? io_checkpoint_bits_sequence : command_checkpoint_sequence; // @[PackageRecoveryController.scala 153:37]
  assign io_events_4_bits_command_checkpoint_generation = _T ? io_checkpoint_bits_generation :
    command_checkpoint_generation; // @[PackageRecoveryController.scala 153:37]
  assign io_events_4_bits_command_checkpoint_restartPc = _T ? io_checkpoint_bits_restartPc :
    command_checkpoint_restartPc; // @[PackageRecoveryController.scala 153:37]
  assign io_events_4_bits_command_checkpoint_architecturalToken = _T ? io_checkpoint_bits_architecturalToken :
    command_checkpoint_architecturalToken; // @[PackageRecoveryController.scala 153:37]
  assign io_events_4_bits_command_checkpoint_memoryToken = _T ? io_checkpoint_bits_memoryToken :
    command_checkpoint_memoryToken; // @[PackageRecoveryController.scala 153:37]
  assign io_events_4_bits_command_failedSequence = _T ? io_failure_bits_sequence : command_failedSequence; // @[PackageRecoveryController.scala 153:37]
  assign io_events_4_bits_command_recoveryGeneration = _T ? acceptedCommand_recoveryGeneration :
    command_recoveryGeneration; // @[PackageRecoveryController.scala 153:37]
  assign io_events_4_bits_retiredPc = 64'h0; // @[PackageRecoveryController.scala 154:33]
  assign io_events_4_bits_allCheckerTasksDrained = 1'h0; // @[PackageRecoveryController.scala 155:46]
  assign io_events_5_valid = badResponse | _io_protocolError_T ? 1'h0 : _GEN_47; // @[PackageRecoveryController.scala 145:42 147:41]
  assign io_events_5_bits_kind = 4'h5; // @[PackageRecoveryController.scala 151:28]
  assign io_events_5_bits_recordSequence = eventSequence + _GEN_80; // @[PackageRecoveryController.scala 157:55]
  assign io_events_5_bits_targetCycle = io_targetCycle; // @[PackageRecoveryController.scala 152:35]
  assign io_events_5_bits_command_checkpoint_sequence = _T ? io_checkpoint_bits_sequence : command_checkpoint_sequence; // @[PackageRecoveryController.scala 153:37]
  assign io_events_5_bits_command_checkpoint_generation = _T ? io_checkpoint_bits_generation :
    command_checkpoint_generation; // @[PackageRecoveryController.scala 153:37]
  assign io_events_5_bits_command_checkpoint_restartPc = _T ? io_checkpoint_bits_restartPc :
    command_checkpoint_restartPc; // @[PackageRecoveryController.scala 153:37]
  assign io_events_5_bits_command_checkpoint_architecturalToken = _T ? io_checkpoint_bits_architecturalToken :
    command_checkpoint_architecturalToken; // @[PackageRecoveryController.scala 153:37]
  assign io_events_5_bits_command_checkpoint_memoryToken = _T ? io_checkpoint_bits_memoryToken :
    command_checkpoint_memoryToken; // @[PackageRecoveryController.scala 153:37]
  assign io_events_5_bits_command_failedSequence = _T ? io_failure_bits_sequence : command_failedSequence; // @[PackageRecoveryController.scala 153:37]
  assign io_events_5_bits_command_recoveryGeneration = _T ? acceptedCommand_recoveryGeneration :
    command_recoveryGeneration; // @[PackageRecoveryController.scala 153:37]
  assign io_events_5_bits_retiredPc = 64'h0; // @[PackageRecoveryController.scala 154:33]
  assign io_events_5_bits_allCheckerTasksDrained = 1'h0; // @[PackageRecoveryController.scala 155:46]
  assign io_events_6_valid = badResponse | _io_protocolError_T ? 1'h0 : _GEN_54; // @[PackageRecoveryController.scala 145:42 147:41]
  assign io_events_6_bits_kind = 4'h6; // @[PackageRecoveryController.scala 151:28]
  assign io_events_6_bits_recordSequence = eventSequence + _GEN_83; // @[PackageRecoveryController.scala 157:55]
  assign io_events_6_bits_targetCycle = io_targetCycle; // @[PackageRecoveryController.scala 152:35]
  assign io_events_6_bits_command_checkpoint_sequence = _T ? io_checkpoint_bits_sequence : command_checkpoint_sequence; // @[PackageRecoveryController.scala 153:37]
  assign io_events_6_bits_command_checkpoint_generation = _T ? io_checkpoint_bits_generation :
    command_checkpoint_generation; // @[PackageRecoveryController.scala 153:37]
  assign io_events_6_bits_command_checkpoint_restartPc = _T ? io_checkpoint_bits_restartPc :
    command_checkpoint_restartPc; // @[PackageRecoveryController.scala 153:37]
  assign io_events_6_bits_command_checkpoint_architecturalToken = _T ? io_checkpoint_bits_architecturalToken :
    command_checkpoint_architecturalToken; // @[PackageRecoveryController.scala 153:37]
  assign io_events_6_bits_command_checkpoint_memoryToken = _T ? io_checkpoint_bits_memoryToken :
    command_checkpoint_memoryToken; // @[PackageRecoveryController.scala 153:37]
  assign io_events_6_bits_command_failedSequence = _T ? io_failure_bits_sequence : command_failedSequence; // @[PackageRecoveryController.scala 153:37]
  assign io_events_6_bits_command_recoveryGeneration = _T ? acceptedCommand_recoveryGeneration :
    command_recoveryGeneration; // @[PackageRecoveryController.scala 153:37]
  assign io_events_6_bits_retiredPc = io_response_4_bits_retiredPc; // @[PackageRecoveryController.scala 154:33]
  assign io_events_6_bits_allCheckerTasksDrained = 1'h0; // @[PackageRecoveryController.scala 155:46]
  assign io_events_7_valid = badResponse | _io_protocolError_T ? 1'h0 : _GEN_61; // @[PackageRecoveryController.scala 145:42 147:41]
  assign io_events_7_bits_kind = 4'h7; // @[PackageRecoveryController.scala 151:28]
  assign io_events_7_bits_recordSequence = eventSequence + _GEN_86; // @[PackageRecoveryController.scala 157:55]
  assign io_events_7_bits_targetCycle = io_targetCycle; // @[PackageRecoveryController.scala 152:35]
  assign io_events_7_bits_command_checkpoint_sequence = _T ? io_checkpoint_bits_sequence : command_checkpoint_sequence; // @[PackageRecoveryController.scala 153:37]
  assign io_events_7_bits_command_checkpoint_generation = _T ? io_checkpoint_bits_generation :
    command_checkpoint_generation; // @[PackageRecoveryController.scala 153:37]
  assign io_events_7_bits_command_checkpoint_restartPc = _T ? io_checkpoint_bits_restartPc :
    command_checkpoint_restartPc; // @[PackageRecoveryController.scala 153:37]
  assign io_events_7_bits_command_checkpoint_architecturalToken = _T ? io_checkpoint_bits_architecturalToken :
    command_checkpoint_architecturalToken; // @[PackageRecoveryController.scala 153:37]
  assign io_events_7_bits_command_checkpoint_memoryToken = _T ? io_checkpoint_bits_memoryToken :
    command_checkpoint_memoryToken; // @[PackageRecoveryController.scala 153:37]
  assign io_events_7_bits_command_failedSequence = _T ? io_failure_bits_sequence : command_failedSequence; // @[PackageRecoveryController.scala 153:37]
  assign io_events_7_bits_command_recoveryGeneration = _T ? acceptedCommand_recoveryGeneration :
    command_recoveryGeneration; // @[PackageRecoveryController.scala 153:37]
  assign io_events_7_bits_retiredPc = 64'h0; // @[PackageRecoveryController.scala 154:33]
  assign io_events_7_bits_allCheckerTasksDrained = io_response_5_bits_allCheckerTasksDrained; // @[PackageRecoveryController.scala 155:46]
  always @(posedge clock) begin
    if (reset) begin // @[PackageRecoveryController.scala 79:22]
      state <= 3'h0; // @[PackageRecoveryController.scala 79:22]
    end else if (badResponse | _io_protocolError_T) begin // @[PackageRecoveryController.scala 145:42]
      state <= 3'h7; // @[PackageRecoveryController.scala 146:11]
    end else if (io_response_5_valid) begin // @[PackageRecoveryController.scala 121:33]
      if (_badResponse_T_64) begin // @[PackageRecoveryController.scala 128:36]
        state <= 3'h0; // @[PackageRecoveryController.scala 130:15]
      end else begin
        state <= 3'h7; // @[PackageRecoveryController.scala 133:15]
      end
    end else if (io_response_4_valid) begin // @[PackageRecoveryController.scala 121:33]
      state <= _GEN_52;
    end else begin
      state <= _GEN_48;
    end
    if (reset) begin // @[PackageRecoveryController.scala 80:21]
      sent <= 1'h0; // @[PackageRecoveryController.scala 80:21]
    end else if (io_response_5_valid) begin // @[PackageRecoveryController.scala 121:33]
      if (_badResponse_T_64) begin // @[PackageRecoveryController.scala 128:36]
        sent <= 1'h0; // @[PackageRecoveryController.scala 131:14]
      end else begin
        sent <= _GEN_57;
      end
    end else begin
      sent <= _GEN_57;
    end
    if (_T) begin // @[PackageRecoveryController.scala 99:26]
      if (legal) begin // @[PackageRecoveryController.scala 105:18]
        command_checkpoint_sequence <= io_checkpoint_bits_sequence; // @[PackageRecoveryController.scala 106:15]
      end
    end
    if (_T) begin // @[PackageRecoveryController.scala 99:26]
      if (legal) begin // @[PackageRecoveryController.scala 105:18]
        command_checkpoint_generation <= io_checkpoint_bits_generation; // @[PackageRecoveryController.scala 106:15]
      end
    end
    if (_T) begin // @[PackageRecoveryController.scala 99:26]
      if (legal) begin // @[PackageRecoveryController.scala 105:18]
        command_checkpoint_restartPc <= io_checkpoint_bits_restartPc; // @[PackageRecoveryController.scala 106:15]
      end
    end
    if (_T) begin // @[PackageRecoveryController.scala 99:26]
      if (legal) begin // @[PackageRecoveryController.scala 105:18]
        command_checkpoint_architecturalToken <= io_checkpoint_bits_architecturalToken; // @[PackageRecoveryController.scala 106:15]
      end
    end
    if (_T) begin // @[PackageRecoveryController.scala 99:26]
      if (legal) begin // @[PackageRecoveryController.scala 105:18]
        command_checkpoint_memoryToken <= io_checkpoint_bits_memoryToken; // @[PackageRecoveryController.scala 106:15]
      end
    end
    if (_T) begin // @[PackageRecoveryController.scala 99:26]
      if (legal) begin // @[PackageRecoveryController.scala 105:18]
        command_failedSequence <= io_failure_bits_sequence; // @[PackageRecoveryController.scala 106:15]
      end
    end
    if (_T) begin // @[PackageRecoveryController.scala 99:26]
      if (legal) begin // @[PackageRecoveryController.scala 105:18]
        command_recoveryGeneration <= acceptedCommand_recoveryGeneration; // @[PackageRecoveryController.scala 106:15]
      end
    end
    if (reset) begin // @[PackageRecoveryController.scala 83:30]
      eventSequence <= 64'h0; // @[PackageRecoveryController.scala 83:30]
    end else if (|_T_21) begin // @[PackageRecoveryController.scala 160:31]
      eventSequence <= _eventSequence_T_15; // @[PackageRecoveryController.scala 160:47]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  state = _RAND_0[2:0];
  _RAND_1 = {1{`RANDOM}};
  sent = _RAND_1[0:0];
  _RAND_2 = {1{`RANDOM}};
  command_checkpoint_sequence = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  command_checkpoint_generation = _RAND_3[31:0];
  _RAND_4 = {2{`RANDOM}};
  command_checkpoint_restartPc = _RAND_4[63:0];
  _RAND_5 = {2{`RANDOM}};
  command_checkpoint_architecturalToken = _RAND_5[63:0];
  _RAND_6 = {2{`RANDOM}};
  command_checkpoint_memoryToken = _RAND_6[63:0];
  _RAND_7 = {1{`RANDOM}};
  command_failedSequence = _RAND_7[31:0];
  _RAND_8 = {1{`RANDOM}};
  command_recoveryGeneration = _RAND_8[31:0];
  _RAND_9 = {2{`RANDOM}};
  eventSequence = _RAND_9[63:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
