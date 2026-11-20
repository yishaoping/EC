module PackageRecoveryState(
  input         clock,
  input         reset,
  input         io_lock,
  output        io_allocate_ready,
  input         io_allocate_valid,
  input  [31:0] io_allocate_bits_sequence,
  input  [31:0] io_allocate_bits_generation,
  input  [63:0] io_allocate_bits_restartPc,
  input  [63:0] io_allocate_bits_architecturalToken,
  input  [63:0] io_allocate_bits_memoryToken,
  output        io_word_ready,
  input         io_word_valid,
  input  [31:0] io_word_bits_sequence,
  input  [31:0] io_word_bits_generation,
  input  [6:0]  io_word_bits_index,
  input  [63:0] io_word_bits_data,
  output        io_seal_ready,
  input         io_seal_valid,
  input  [31:0] io_seal_bits_sequence,
  input  [31:0] io_seal_bits_generation,
  input  [63:0] io_seal_bits_restartPc,
  input  [63:0] io_seal_bits_architecturalToken,
  input  [63:0] io_seal_bits_memoryToken,
  output        io_result_ready,
  input         io_result_valid,
  input  [31:0] io_result_bits_sequence,
  input  [31:0] io_result_bits_generation,
  input         io_result_bits_compared,
  input         io_result_bits_passed,
  output        io_checkpoint_valid,
  output [31:0] io_checkpoint_bits_sequence,
  output [31:0] io_checkpoint_bits_generation,
  output [63:0] io_checkpoint_bits_restartPc,
  output [63:0] io_checkpoint_bits_architecturalToken,
  output [63:0] io_checkpoint_bits_memoryToken,
  input         io_failure_ready,
  output        io_failure_valid,
  output [31:0] io_failure_bits_sequence,
  output [31:0] io_failure_bits_generation,
  output        io_failure_bits_allocated,
  output        io_failure_bits_comparedMismatch,
  output        io_restore_ready,
  input         io_restore_valid,
  input  [31:0] io_restore_bits_checkpoint_sequence,
  input  [31:0] io_restore_bits_checkpoint_generation,
  input  [63:0] io_restore_bits_checkpoint_restartPc,
  input  [63:0] io_restore_bits_checkpoint_architecturalToken,
  input  [63:0] io_restore_bits_checkpoint_memoryToken,
  input  [31:0] io_restore_bits_failedSequence,
  input  [31:0] io_restore_bits_recoveryGeneration,
  input         io_write_ready,
  output        io_write_valid,
  output [31:0] io_write_bits_command_checkpoint_sequence,
  output [31:0] io_write_bits_command_checkpoint_generation,
  output [63:0] io_write_bits_command_checkpoint_restartPc,
  output [63:0] io_write_bits_command_checkpoint_architecturalToken,
  output [63:0] io_write_bits_command_checkpoint_memoryToken,
  output [31:0] io_write_bits_command_failedSequence,
  output [31:0] io_write_bits_command_recoveryGeneration,
  output [6:0]  io_write_bits_index,
  output [63:0] io_write_bits_data,
  input         io_writeCompleted_valid,
  input  [31:0] io_writeCompleted_bits_command_checkpoint_sequence,
  input  [31:0] io_writeCompleted_bits_command_checkpoint_generation,
  input  [63:0] io_writeCompleted_bits_command_checkpoint_restartPc,
  input  [63:0] io_writeCompleted_bits_command_checkpoint_architecturalToken,
  input  [63:0] io_writeCompleted_bits_command_checkpoint_memoryToken,
  input  [31:0] io_writeCompleted_bits_command_failedSequence,
  input  [31:0] io_writeCompleted_bits_command_recoveryGeneration,
  input  [6:0]  io_writeCompleted_bits_index,
  input  [63:0] io_writeCompleted_bits_data,
  output        io_restored_valid,
  output [31:0] io_restored_bits_command_checkpoint_sequence,
  output [31:0] io_restored_bits_command_checkpoint_generation,
  output [63:0] io_restored_bits_command_checkpoint_restartPc,
  output [63:0] io_restored_bits_command_checkpoint_architecturalToken,
  output [63:0] io_restored_bits_command_checkpoint_memoryToken,
  output [31:0] io_restored_bits_command_failedSequence,
  output [31:0] io_restored_bits_command_recoveryGeneration,
  output [63:0] io_restored_bits_retiredPc,
  output        io_restored_bits_allCheckerTasksDrained,
  output        io_rebase_ready,
  input         io_rebase_valid,
  input  [31:0] io_rebase_bits_command_checkpoint_sequence,
  input  [31:0] io_rebase_bits_command_checkpoint_generation,
  input  [63:0] io_rebase_bits_command_checkpoint_restartPc,
  input  [63:0] io_rebase_bits_command_checkpoint_architecturalToken,
  input  [63:0] io_rebase_bits_command_checkpoint_memoryToken,
  input  [31:0] io_rebase_bits_command_failedSequence,
  input  [31:0] io_rebase_bits_command_recoveryGeneration,
  input         io_rebase_bits_pipelineQuiescent,
  input         io_rebase_bits_memoryRestored,
  input         io_rebase_bits_architectureRestored,
  input         io_rebase_bits_checkersInitialized,
  output        io_protocolError,
  output        io_freezeRequested,
  output        io_restoreActive,
  output [2:0]  io_occupancy
);
`ifdef RANDOMIZE_GARBAGE_ASSIGN
  reg [63:0] _RAND_1;
  reg [63:0] _RAND_2;
`endif // RANDOMIZE_GARBAGE_ASSIGN
`ifdef RANDOMIZE_MEM_INIT
  reg [63:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [31:0] _RAND_20;
  reg [31:0] _RAND_21;
  reg [31:0] _RAND_22;
  reg [31:0] _RAND_23;
  reg [31:0] _RAND_24;
  reg [31:0] _RAND_25;
  reg [31:0] _RAND_26;
  reg [31:0] _RAND_27;
  reg [31:0] _RAND_28;
  reg [63:0] _RAND_29;
  reg [63:0] _RAND_30;
  reg [63:0] _RAND_31;
  reg [31:0] _RAND_32;
  reg [31:0] _RAND_33;
  reg [63:0] _RAND_34;
  reg [63:0] _RAND_35;
  reg [63:0] _RAND_36;
  reg [31:0] _RAND_37;
  reg [31:0] _RAND_38;
  reg [63:0] _RAND_39;
  reg [63:0] _RAND_40;
  reg [63:0] _RAND_41;
  reg [31:0] _RAND_42;
  reg [31:0] _RAND_43;
  reg [63:0] _RAND_44;
  reg [63:0] _RAND_45;
  reg [63:0] _RAND_46;
  reg [31:0] _RAND_47;
  reg [31:0] _RAND_48;
  reg [63:0] _RAND_49;
  reg [63:0] _RAND_50;
  reg [63:0] _RAND_51;
  reg [31:0] _RAND_52;
  reg [31:0] _RAND_53;
  reg [63:0] _RAND_54;
  reg [63:0] _RAND_55;
  reg [63:0] _RAND_56;
  reg [31:0] _RAND_57;
  reg [31:0] _RAND_58;
  reg [31:0] _RAND_59;
  reg [31:0] _RAND_60;
  reg [31:0] _RAND_61;
  reg [31:0] _RAND_62;
  reg [31:0] _RAND_63;
  reg [31:0] _RAND_64;
  reg [31:0] _RAND_65;
  reg [31:0] _RAND_66;
  reg [31:0] _RAND_67;
  reg [31:0] _RAND_68;
  reg [31:0] _RAND_69;
  reg [31:0] _RAND_70;
  reg [31:0] _RAND_71;
  reg [31:0] _RAND_72;
  reg [31:0] _RAND_73;
  reg [63:0] _RAND_74;
  reg [63:0] _RAND_75;
  reg [63:0] _RAND_76;
  reg [31:0] _RAND_77;
  reg [31:0] _RAND_78;
  reg [31:0] _RAND_79;
`endif // RANDOMIZE_REG_INIT
  reg [63:0] image [0:575]; // @[PackageRecoveryState.scala 69:18]
  wire  image_io_write_bits_data_MPORT_en; // @[PackageRecoveryState.scala 69:18]
  wire [9:0] image_io_write_bits_data_MPORT_addr; // @[PackageRecoveryState.scala 69:18]
  wire [63:0] image_io_write_bits_data_MPORT_data; // @[PackageRecoveryState.scala 69:18]
  wire  image_legal_MPORT_en; // @[PackageRecoveryState.scala 69:18]
  wire [9:0] image_legal_MPORT_addr; // @[PackageRecoveryState.scala 69:18]
  wire [63:0] image_legal_MPORT_data; // @[PackageRecoveryState.scala 69:18]
  wire [63:0] image_MPORT_data; // @[PackageRecoveryState.scala 69:18]
  wire [9:0] image_MPORT_addr; // @[PackageRecoveryState.scala 69:18]
  wire  image_MPORT_mask; // @[PackageRecoveryState.scala 69:18]
  wire  image_MPORT_en; // @[PackageRecoveryState.scala 69:18]
  reg  valid_0; // @[PackageRecoveryState.scala 64:22]
  reg  valid_1; // @[PackageRecoveryState.scala 64:22]
  reg  valid_2; // @[PackageRecoveryState.scala 64:22]
  reg  valid_3; // @[PackageRecoveryState.scala 64:22]
  reg  valid_4; // @[PackageRecoveryState.scala 64:22]
  reg  valid_5; // @[PackageRecoveryState.scala 64:22]
  reg  sealedImage_0; // @[PackageRecoveryState.scala 65:28]
  reg  sealedImage_1; // @[PackageRecoveryState.scala 65:28]
  reg  sealedImage_2; // @[PackageRecoveryState.scala 65:28]
  reg  sealedImage_3; // @[PackageRecoveryState.scala 65:28]
  reg  sealedImage_4; // @[PackageRecoveryState.scala 65:28]
  reg  sealedImage_5; // @[PackageRecoveryState.scala 65:28]
  reg  resultSeen_0; // @[PackageRecoveryState.scala 66:27]
  reg  resultSeen_1; // @[PackageRecoveryState.scala 66:27]
  reg  resultSeen_2; // @[PackageRecoveryState.scala 66:27]
  reg  resultSeen_3; // @[PackageRecoveryState.scala 66:27]
  reg  resultSeen_4; // @[PackageRecoveryState.scala 66:27]
  reg  resultSeen_5; // @[PackageRecoveryState.scala 66:27]
  reg  passed_0; // @[PackageRecoveryState.scala 67:23]
  reg  passed_1; // @[PackageRecoveryState.scala 67:23]
  reg  passed_2; // @[PackageRecoveryState.scala 67:23]
  reg  passed_3; // @[PackageRecoveryState.scala 67:23]
  reg  passed_4; // @[PackageRecoveryState.scala 67:23]
  reg  passed_5; // @[PackageRecoveryState.scala 67:23]
  reg [31:0] header_0_sequence; // @[PackageRecoveryState.scala 68:19]
  reg [31:0] header_0_generation; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_0_restartPc; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_0_architecturalToken; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_0_memoryToken; // @[PackageRecoveryState.scala 68:19]
  reg [31:0] header_1_sequence; // @[PackageRecoveryState.scala 68:19]
  reg [31:0] header_1_generation; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_1_restartPc; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_1_architecturalToken; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_1_memoryToken; // @[PackageRecoveryState.scala 68:19]
  reg [31:0] header_2_sequence; // @[PackageRecoveryState.scala 68:19]
  reg [31:0] header_2_generation; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_2_restartPc; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_2_architecturalToken; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_2_memoryToken; // @[PackageRecoveryState.scala 68:19]
  reg [31:0] header_3_sequence; // @[PackageRecoveryState.scala 68:19]
  reg [31:0] header_3_generation; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_3_restartPc; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_3_architecturalToken; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_3_memoryToken; // @[PackageRecoveryState.scala 68:19]
  reg [31:0] header_4_sequence; // @[PackageRecoveryState.scala 68:19]
  reg [31:0] header_4_generation; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_4_restartPc; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_4_architecturalToken; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_4_memoryToken; // @[PackageRecoveryState.scala 68:19]
  reg [31:0] header_5_sequence; // @[PackageRecoveryState.scala 68:19]
  reg [31:0] header_5_generation; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_5_restartPc; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_5_architecturalToken; // @[PackageRecoveryState.scala 68:19]
  reg [63:0] header_5_memoryToken; // @[PackageRecoveryState.scala 68:19]
  reg [2:0] safeSlot; // @[PackageRecoveryState.scala 70:25]
  reg [2:0] allocateSlot; // @[PackageRecoveryState.scala 71:29]
  reg [2:0] captureSlot; // @[PackageRecoveryState.scala 72:24]
  reg  capturing; // @[PackageRecoveryState.scala 73:26]
  reg [6:0] captured; // @[PackageRecoveryState.scala 74:25]
  reg  hasAllocated; // @[PackageRecoveryState.scala 75:29]
  reg [31:0] lastSequence; // @[PackageRecoveryState.scala 76:25]
  reg [31:0] generation; // @[PackageRecoveryState.scala 77:23]
  reg  failed; // @[PackageRecoveryState.scala 78:23]
  reg [31:0] failureSequence; // @[PackageRecoveryState.scala 79:28]
  reg  failureReported; // @[PackageRecoveryState.scala 80:32]
  reg  error; // @[PackageRecoveryState.scala 81:22]
  reg  active; // @[PackageRecoveryState.scala 82:23]
  reg  sent; // @[PackageRecoveryState.scala 83:21]
  reg [6:0] index; // @[PackageRecoveryState.scala 84:22]
  reg [31:0] command_checkpoint_sequence; // @[PackageRecoveryState.scala 85:20]
  reg [31:0] command_checkpoint_generation; // @[PackageRecoveryState.scala 85:20]
  reg [63:0] command_checkpoint_restartPc; // @[PackageRecoveryState.scala 85:20]
  reg [63:0] command_checkpoint_architecturalToken; // @[PackageRecoveryState.scala 85:20]
  reg [63:0] command_checkpoint_memoryToken; // @[PackageRecoveryState.scala 85:20]
  reg [31:0] command_failedSequence; // @[PackageRecoveryState.scala 85:20]
  reg [31:0] command_recoveryGeneration; // @[PackageRecoveryState.scala 85:20]
  reg  restoredPendingRebase; // @[PackageRecoveryState.scala 86:38]
  wire  _GEN_1 = 3'h1 == safeSlot ? valid_1 : valid_0; // @[PackageRecoveryState.scala 87:{35,35}]
  wire  _GEN_2 = 3'h2 == safeSlot ? valid_2 : _GEN_1; // @[PackageRecoveryState.scala 87:{35,35}]
  wire  _GEN_3 = 3'h3 == safeSlot ? valid_3 : _GEN_2; // @[PackageRecoveryState.scala 87:{35,35}]
  wire  _GEN_4 = 3'h4 == safeSlot ? valid_4 : _GEN_3; // @[PackageRecoveryState.scala 87:{35,35}]
  wire  _GEN_5 = 3'h5 == safeSlot ? valid_5 : _GEN_4; // @[PackageRecoveryState.scala 87:{35,35}]
  wire  _GEN_7 = 3'h1 == safeSlot ? sealedImage_1 : sealedImage_0; // @[PackageRecoveryState.scala 87:{35,35}]
  wire  _GEN_8 = 3'h2 == safeSlot ? sealedImage_2 : _GEN_7; // @[PackageRecoveryState.scala 87:{35,35}]
  wire  _GEN_9 = 3'h3 == safeSlot ? sealedImage_3 : _GEN_8; // @[PackageRecoveryState.scala 87:{35,35}]
  wire  _GEN_10 = 3'h4 == safeSlot ? sealedImage_4 : _GEN_9; // @[PackageRecoveryState.scala 87:{35,35}]
  wire  _GEN_11 = 3'h5 == safeSlot ? sealedImage_5 : _GEN_10; // @[PackageRecoveryState.scala 87:{35,35}]
  wire  _GEN_13 = 3'h1 == safeSlot ? passed_1 : passed_0; // @[PackageRecoveryState.scala 87:{60,60}]
  wire  _GEN_14 = 3'h2 == safeSlot ? passed_2 : _GEN_13; // @[PackageRecoveryState.scala 87:{60,60}]
  wire  _GEN_15 = 3'h3 == safeSlot ? passed_3 : _GEN_14; // @[PackageRecoveryState.scala 87:{60,60}]
  wire  _GEN_16 = 3'h4 == safeSlot ? passed_4 : _GEN_15; // @[PackageRecoveryState.scala 87:{60,60}]
  wire  _GEN_17 = 3'h5 == safeSlot ? passed_5 : _GEN_16; // @[PackageRecoveryState.scala 87:{60,60}]
  wire  safeValid = _GEN_5 & _GEN_11 & _GEN_17; // @[PackageRecoveryState.scala 87:60]
  wire  locked = io_lock | failed | active | error; // @[PackageRecoveryState.scala 88:44]
  wire [2:0] _successor_T_2 = safeSlot + 3'h1; // @[PackageRecoveryState.scala 63:65]
  wire [2:0] successor = safeSlot == 3'h5 ? 3'h0 : _successor_T_2; // @[PackageRecoveryState.scala 63:36]
  wire  _GEN_19 = 3'h1 == successor ? valid_1 : valid_0; // @[PackageRecoveryState.scala 90:{33,33}]
  wire  _GEN_20 = 3'h2 == successor ? valid_2 : _GEN_19; // @[PackageRecoveryState.scala 90:{33,33}]
  wire  _GEN_21 = 3'h3 == successor ? valid_3 : _GEN_20; // @[PackageRecoveryState.scala 90:{33,33}]
  wire  _GEN_22 = 3'h4 == successor ? valid_4 : _GEN_21; // @[PackageRecoveryState.scala 90:{33,33}]
  wire  _GEN_23 = 3'h5 == successor ? valid_5 : _GEN_22; // @[PackageRecoveryState.scala 90:{33,33}]
  wire  _GEN_25 = 3'h1 == successor ? sealedImage_1 : sealedImage_0; // @[PackageRecoveryState.scala 90:{53,53}]
  wire  _GEN_26 = 3'h2 == successor ? sealedImage_2 : _GEN_25; // @[PackageRecoveryState.scala 90:{53,53}]
  wire  _GEN_27 = 3'h3 == successor ? sealedImage_3 : _GEN_26; // @[PackageRecoveryState.scala 90:{53,53}]
  wire  _GEN_28 = 3'h4 == successor ? sealedImage_4 : _GEN_27; // @[PackageRecoveryState.scala 90:{53,53}]
  wire  _GEN_29 = 3'h5 == successor ? sealedImage_5 : _GEN_28; // @[PackageRecoveryState.scala 90:{53,53}]
  wire  _GEN_31 = 3'h1 == successor ? passed_1 : passed_0; // @[PackageRecoveryState.scala 90:{79,79}]
  wire  _GEN_32 = 3'h2 == successor ? passed_2 : _GEN_31; // @[PackageRecoveryState.scala 90:{79,79}]
  wire  _GEN_33 = 3'h3 == successor ? passed_3 : _GEN_32; // @[PackageRecoveryState.scala 90:{79,79}]
  wire  _GEN_34 = 3'h4 == successor ? passed_4 : _GEN_33; // @[PackageRecoveryState.scala 90:{79,79}]
  wire  _GEN_35 = 3'h5 == successor ? passed_5 : _GEN_34; // @[PackageRecoveryState.scala 90:{79,79}]
  wire  _prefixAdvance_T_2 = safeValid & _GEN_23 & _GEN_29 & _GEN_35; // @[PackageRecoveryState.scala 90:79]
  wire  _prefixAdvance_T_3 = ~failed; // @[PackageRecoveryState.scala 91:27]
  wire [31:0] _GEN_37 = 3'h1 == successor ? header_1_sequence : header_0_sequence; // @[PackageRecoveryState.scala 91:{65,65}]
  wire [31:0] _GEN_38 = 3'h2 == successor ? header_2_sequence : _GEN_37; // @[PackageRecoveryState.scala 91:{65,65}]
  wire [31:0] _GEN_39 = 3'h3 == successor ? header_3_sequence : _GEN_38; // @[PackageRecoveryState.scala 91:{65,65}]
  wire [31:0] _GEN_40 = 3'h4 == successor ? header_4_sequence : _GEN_39; // @[PackageRecoveryState.scala 91:{65,65}]
  wire [31:0] _GEN_41 = 3'h5 == successor ? header_5_sequence : _GEN_40; // @[PackageRecoveryState.scala 91:{65,65}]
  wire  prefixAdvance = _prefixAdvance_T_2 & (~failed | _GEN_41 < failureSequence); // @[PackageRecoveryState.scala 91:23]
  wire  _io_checkpoint_valid_T = ~error; // @[PackageRecoveryState.scala 93:39]
  wire [31:0] _GEN_43 = 3'h1 == safeSlot ? header_1_sequence : header_0_sequence; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [31:0] _GEN_44 = 3'h2 == safeSlot ? header_2_sequence : _GEN_43; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [31:0] _GEN_45 = 3'h3 == safeSlot ? header_3_sequence : _GEN_44; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [31:0] _GEN_46 = 3'h4 == safeSlot ? header_4_sequence : _GEN_45; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [31:0] _GEN_47 = 3'h5 == safeSlot ? header_5_sequence : _GEN_46; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [31:0] _GEN_49 = 3'h1 == safeSlot ? header_1_generation : header_0_generation; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [31:0] _GEN_50 = 3'h2 == safeSlot ? header_2_generation : _GEN_49; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [31:0] _GEN_51 = 3'h3 == safeSlot ? header_3_generation : _GEN_50; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [31:0] _GEN_52 = 3'h4 == safeSlot ? header_4_generation : _GEN_51; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [31:0] _GEN_53 = 3'h5 == safeSlot ? header_5_generation : _GEN_52; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [63:0] _GEN_55 = 3'h1 == safeSlot ? header_1_restartPc : header_0_restartPc; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [63:0] _GEN_56 = 3'h2 == safeSlot ? header_2_restartPc : _GEN_55; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [63:0] _GEN_57 = 3'h3 == safeSlot ? header_3_restartPc : _GEN_56; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [63:0] _GEN_58 = 3'h4 == safeSlot ? header_4_restartPc : _GEN_57; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [63:0] _GEN_59 = 3'h5 == safeSlot ? header_5_restartPc : _GEN_58; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [63:0] _GEN_61 = 3'h1 == safeSlot ? header_1_architecturalToken : header_0_architecturalToken; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [63:0] _GEN_62 = 3'h2 == safeSlot ? header_2_architecturalToken : _GEN_61; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [63:0] _GEN_63 = 3'h3 == safeSlot ? header_3_architecturalToken : _GEN_62; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [63:0] _GEN_64 = 3'h4 == safeSlot ? header_4_architecturalToken : _GEN_63; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [63:0] _GEN_65 = 3'h5 == safeSlot ? header_5_architecturalToken : _GEN_64; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [63:0] _GEN_67 = 3'h1 == safeSlot ? header_1_memoryToken : header_0_memoryToken; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [63:0] _GEN_68 = 3'h2 == safeSlot ? header_2_memoryToken : _GEN_67; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [63:0] _GEN_69 = 3'h3 == safeSlot ? header_3_memoryToken : _GEN_68; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [63:0] _GEN_70 = 3'h4 == safeSlot ? header_4_memoryToken : _GEN_69; // @[PackageRecoveryState.scala 94:{22,22}]
  wire [63:0] _GEN_71 = 3'h5 == safeSlot ? header_5_memoryToken : _GEN_70; // @[PackageRecoveryState.scala 94:{22,22}]
  wire  _io_freezeRequested_T_2 = ~io_result_bits_passed; // @[PackageRecoveryState.scala 97:25]
  wire  _io_freezeRequested_T_3 = io_result_valid & ~io_result_bits_passed; // @[PackageRecoveryState.scala 97:22]
  wire [1:0] _io_occupancy_T = valid_1 + valid_2; // @[Bitwise.scala 51:90]
  wire [1:0] _GEN_480 = {{1'd0}, valid_0}; // @[Bitwise.scala 51:90]
  wire [2:0] _io_occupancy_T_2 = _GEN_480 + _io_occupancy_T; // @[Bitwise.scala 51:90]
  wire [1:0] _io_occupancy_T_4 = valid_4 + valid_5; // @[Bitwise.scala 51:90]
  wire [1:0] _GEN_481 = {{1'd0}, valid_3}; // @[Bitwise.scala 51:90]
  wire [2:0] _io_occupancy_T_6 = _GEN_481 + _io_occupancy_T_4; // @[Bitwise.scala 51:90]
  wire  _io_failure_valid_T = ~failureReported; // @[PackageRecoveryState.scala 103:33]
  wire  _T = io_failure_ready & io_failure_valid; // @[Decoupled.scala 51:35]
  wire  _GEN_72 = _T | failureReported; // @[PackageRecoveryState.scala 108:{26,44} 80:32]
  wire  _io_allocate_ready_T = ~locked; // @[PackageRecoveryState.scala 114:24]
  wire  _GEN_74 = 3'h1 == allocateSlot ? valid_1 : valid_0; // @[PackageRecoveryState.scala 114:{49,49}]
  wire  _GEN_75 = 3'h2 == allocateSlot ? valid_2 : _GEN_74; // @[PackageRecoveryState.scala 114:{49,49}]
  wire  _GEN_76 = 3'h3 == allocateSlot ? valid_3 : _GEN_75; // @[PackageRecoveryState.scala 114:{49,49}]
  wire  _GEN_77 = 3'h4 == allocateSlot ? valid_4 : _GEN_76; // @[PackageRecoveryState.scala 114:{49,49}]
  wire  _GEN_78 = 3'h5 == allocateSlot ? valid_5 : _GEN_77; // @[PackageRecoveryState.scala 114:{49,49}]
  wire  _T_1 = io_allocate_ready & io_allocate_valid; // @[Decoupled.scala 51:35]
  wire [31:0] _legal_T_3 = lastSequence + 32'h1; // @[PackageRecoveryState.scala 117:50]
  wire  _legal_T_4 = io_allocate_bits_sequence == _legal_T_3; // @[PackageRecoveryState.scala 117:33]
  wire  _legal_T_5 = lastSequence != 32'hffffffff & _legal_T_4; // @[PackageRecoveryState.scala 116:66]
  wire  _legal_T_6 = io_allocate_bits_generation == generation; // @[PackageRecoveryState.scala 118:35]
  wire  _legal_T_7 = _legal_T_5 & _legal_T_6; // @[PackageRecoveryState.scala 117:56]
  wire  legal = ~hasAllocated | _legal_T_7; // @[PackageRecoveryState.scala 116:31]
  wire [31:0] _GEN_85 = 3'h0 == allocateSlot ? io_allocate_bits_generation : header_0_generation; // @[PackageRecoveryState.scala 120:{28,28} 68:19]
  wire [31:0] _GEN_86 = 3'h1 == allocateSlot ? io_allocate_bits_generation : header_1_generation; // @[PackageRecoveryState.scala 120:{28,28} 68:19]
  wire [31:0] _GEN_87 = 3'h2 == allocateSlot ? io_allocate_bits_generation : header_2_generation; // @[PackageRecoveryState.scala 120:{28,28} 68:19]
  wire [31:0] _GEN_88 = 3'h3 == allocateSlot ? io_allocate_bits_generation : header_3_generation; // @[PackageRecoveryState.scala 120:{28,28} 68:19]
  wire [31:0] _GEN_89 = 3'h4 == allocateSlot ? io_allocate_bits_generation : header_4_generation; // @[PackageRecoveryState.scala 120:{28,28} 68:19]
  wire [31:0] _GEN_90 = 3'h5 == allocateSlot ? io_allocate_bits_generation : header_5_generation; // @[PackageRecoveryState.scala 120:{28,28} 68:19]
  wire  _GEN_109 = 3'h0 == allocateSlot | valid_0; // @[PackageRecoveryState.scala 121:{27,27} 64:22]
  wire  _GEN_110 = 3'h1 == allocateSlot | valid_1; // @[PackageRecoveryState.scala 121:{27,27} 64:22]
  wire  _GEN_111 = 3'h2 == allocateSlot | valid_2; // @[PackageRecoveryState.scala 121:{27,27} 64:22]
  wire  _GEN_112 = 3'h3 == allocateSlot | valid_3; // @[PackageRecoveryState.scala 121:{27,27} 64:22]
  wire  _GEN_113 = 3'h4 == allocateSlot | valid_4; // @[PackageRecoveryState.scala 121:{27,27} 64:22]
  wire  _GEN_114 = 3'h5 == allocateSlot | valid_5; // @[PackageRecoveryState.scala 121:{27,27} 64:22]
  wire  _GEN_115 = 3'h0 == allocateSlot ? 1'h0 : sealedImage_0; // @[PackageRecoveryState.scala 122:{33,33} 65:28]
  wire  _GEN_116 = 3'h1 == allocateSlot ? 1'h0 : sealedImage_1; // @[PackageRecoveryState.scala 122:{33,33} 65:28]
  wire  _GEN_117 = 3'h2 == allocateSlot ? 1'h0 : sealedImage_2; // @[PackageRecoveryState.scala 122:{33,33} 65:28]
  wire  _GEN_118 = 3'h3 == allocateSlot ? 1'h0 : sealedImage_3; // @[PackageRecoveryState.scala 122:{33,33} 65:28]
  wire  _GEN_119 = 3'h4 == allocateSlot ? 1'h0 : sealedImage_4; // @[PackageRecoveryState.scala 122:{33,33} 65:28]
  wire  _GEN_120 = 3'h5 == allocateSlot ? 1'h0 : sealedImage_5; // @[PackageRecoveryState.scala 122:{33,33} 65:28]
  wire  _GEN_121 = 3'h0 == allocateSlot ? 1'h0 : resultSeen_0; // @[PackageRecoveryState.scala 123:{32,32} 66:27]
  wire  _GEN_122 = 3'h1 == allocateSlot ? 1'h0 : resultSeen_1; // @[PackageRecoveryState.scala 123:{32,32} 66:27]
  wire  _GEN_123 = 3'h2 == allocateSlot ? 1'h0 : resultSeen_2; // @[PackageRecoveryState.scala 123:{32,32} 66:27]
  wire  _GEN_124 = 3'h3 == allocateSlot ? 1'h0 : resultSeen_3; // @[PackageRecoveryState.scala 123:{32,32} 66:27]
  wire  _GEN_125 = 3'h4 == allocateSlot ? 1'h0 : resultSeen_4; // @[PackageRecoveryState.scala 123:{32,32} 66:27]
  wire  _GEN_126 = 3'h5 == allocateSlot ? 1'h0 : resultSeen_5; // @[PackageRecoveryState.scala 123:{32,32} 66:27]
  wire  _GEN_127 = 3'h0 == allocateSlot ? 1'h0 : passed_0; // @[PackageRecoveryState.scala 124:{28,28} 67:23]
  wire  _GEN_128 = 3'h1 == allocateSlot ? 1'h0 : passed_1; // @[PackageRecoveryState.scala 124:{28,28} 67:23]
  wire  _GEN_129 = 3'h2 == allocateSlot ? 1'h0 : passed_2; // @[PackageRecoveryState.scala 124:{28,28} 67:23]
  wire  _GEN_130 = 3'h3 == allocateSlot ? 1'h0 : passed_3; // @[PackageRecoveryState.scala 124:{28,28} 67:23]
  wire  _GEN_131 = 3'h4 == allocateSlot ? 1'h0 : passed_4; // @[PackageRecoveryState.scala 124:{28,28} 67:23]
  wire  _GEN_132 = 3'h5 == allocateSlot ? 1'h0 : passed_5; // @[PackageRecoveryState.scala 124:{28,28} 67:23]
  wire [2:0] _allocateSlot_T_2 = allocateSlot + 3'h1; // @[PackageRecoveryState.scala 63:65]
  wire [2:0] _allocateSlot_T_3 = allocateSlot == 3'h5 ? 3'h0 : _allocateSlot_T_2; // @[PackageRecoveryState.scala 63:36]
  wire  _GEN_133 = ~legal | error; // @[PackageRecoveryState.scala 119:{19,27} 81:22]
  wire [31:0] _GEN_140 = ~legal ? header_0_generation : _GEN_85; // @[PackageRecoveryState.scala 119:19 68:19]
  wire [31:0] _GEN_141 = ~legal ? header_1_generation : _GEN_86; // @[PackageRecoveryState.scala 119:19 68:19]
  wire [31:0] _GEN_142 = ~legal ? header_2_generation : _GEN_87; // @[PackageRecoveryState.scala 119:19 68:19]
  wire [31:0] _GEN_143 = ~legal ? header_3_generation : _GEN_88; // @[PackageRecoveryState.scala 119:19 68:19]
  wire [31:0] _GEN_144 = ~legal ? header_4_generation : _GEN_89; // @[PackageRecoveryState.scala 119:19 68:19]
  wire [31:0] _GEN_145 = ~legal ? header_5_generation : _GEN_90; // @[PackageRecoveryState.scala 119:19 68:19]
  wire  _GEN_164 = ~legal ? valid_0 : _GEN_109; // @[PackageRecoveryState.scala 119:19 64:22]
  wire  _GEN_165 = ~legal ? valid_1 : _GEN_110; // @[PackageRecoveryState.scala 119:19 64:22]
  wire  _GEN_166 = ~legal ? valid_2 : _GEN_111; // @[PackageRecoveryState.scala 119:19 64:22]
  wire  _GEN_167 = ~legal ? valid_3 : _GEN_112; // @[PackageRecoveryState.scala 119:19 64:22]
  wire  _GEN_168 = ~legal ? valid_4 : _GEN_113; // @[PackageRecoveryState.scala 119:19 64:22]
  wire  _GEN_169 = ~legal ? valid_5 : _GEN_114; // @[PackageRecoveryState.scala 119:19 64:22]
  wire  _GEN_170 = ~legal ? sealedImage_0 : _GEN_115; // @[PackageRecoveryState.scala 119:19 65:28]
  wire  _GEN_171 = ~legal ? sealedImage_1 : _GEN_116; // @[PackageRecoveryState.scala 119:19 65:28]
  wire  _GEN_172 = ~legal ? sealedImage_2 : _GEN_117; // @[PackageRecoveryState.scala 119:19 65:28]
  wire  _GEN_173 = ~legal ? sealedImage_3 : _GEN_118; // @[PackageRecoveryState.scala 119:19 65:28]
  wire  _GEN_174 = ~legal ? sealedImage_4 : _GEN_119; // @[PackageRecoveryState.scala 119:19 65:28]
  wire  _GEN_175 = ~legal ? sealedImage_5 : _GEN_120; // @[PackageRecoveryState.scala 119:19 65:28]
  wire  _GEN_176 = ~legal ? resultSeen_0 : _GEN_121; // @[PackageRecoveryState.scala 119:19 66:27]
  wire  _GEN_177 = ~legal ? resultSeen_1 : _GEN_122; // @[PackageRecoveryState.scala 119:19 66:27]
  wire  _GEN_178 = ~legal ? resultSeen_2 : _GEN_123; // @[PackageRecoveryState.scala 119:19 66:27]
  wire  _GEN_179 = ~legal ? resultSeen_3 : _GEN_124; // @[PackageRecoveryState.scala 119:19 66:27]
  wire  _GEN_180 = ~legal ? resultSeen_4 : _GEN_125; // @[PackageRecoveryState.scala 119:19 66:27]
  wire  _GEN_181 = ~legal ? resultSeen_5 : _GEN_126; // @[PackageRecoveryState.scala 119:19 66:27]
  wire  _GEN_182 = ~legal ? passed_0 : _GEN_127; // @[PackageRecoveryState.scala 119:19 67:23]
  wire  _GEN_183 = ~legal ? passed_1 : _GEN_128; // @[PackageRecoveryState.scala 119:19 67:23]
  wire  _GEN_184 = ~legal ? passed_2 : _GEN_129; // @[PackageRecoveryState.scala 119:19 67:23]
  wire  _GEN_185 = ~legal ? passed_3 : _GEN_130; // @[PackageRecoveryState.scala 119:19 67:23]
  wire  _GEN_186 = ~legal ? passed_4 : _GEN_131; // @[PackageRecoveryState.scala 119:19 67:23]
  wire  _GEN_187 = ~legal ? passed_5 : _GEN_132; // @[PackageRecoveryState.scala 119:19 67:23]
  wire [2:0] _GEN_189 = ~legal ? allocateSlot : _allocateSlot_T_3; // @[PackageRecoveryState.scala 119:19 126:20 71:29]
  wire  _GEN_190 = ~legal ? capturing : 1'h1; // @[PackageRecoveryState.scala 119:19 127:17 73:26]
  wire [6:0] _GEN_191 = ~legal ? captured : 7'h0; // @[PackageRecoveryState.scala 119:19 128:16 74:25]
  wire [31:0] _GEN_192 = ~legal ? generation : io_allocate_bits_generation; // @[PackageRecoveryState.scala 119:19 129:18 77:23]
  wire [31:0] _GEN_193 = ~legal ? lastSequence : io_allocate_bits_sequence; // @[PackageRecoveryState.scala 119:19 130:20 76:25]
  wire  _GEN_195 = _T_1 ? _GEN_133 : error; // @[PackageRecoveryState.scala 115:27 81:22]
  wire [31:0] _GEN_202 = _T_1 ? _GEN_140 : header_0_generation; // @[PackageRecoveryState.scala 115:27 68:19]
  wire [31:0] _GEN_203 = _T_1 ? _GEN_141 : header_1_generation; // @[PackageRecoveryState.scala 115:27 68:19]
  wire [31:0] _GEN_204 = _T_1 ? _GEN_142 : header_2_generation; // @[PackageRecoveryState.scala 115:27 68:19]
  wire [31:0] _GEN_205 = _T_1 ? _GEN_143 : header_3_generation; // @[PackageRecoveryState.scala 115:27 68:19]
  wire [31:0] _GEN_206 = _T_1 ? _GEN_144 : header_4_generation; // @[PackageRecoveryState.scala 115:27 68:19]
  wire [31:0] _GEN_207 = _T_1 ? _GEN_145 : header_5_generation; // @[PackageRecoveryState.scala 115:27 68:19]
  wire  _GEN_226 = _T_1 ? _GEN_164 : valid_0; // @[PackageRecoveryState.scala 115:27 64:22]
  wire  _GEN_227 = _T_1 ? _GEN_165 : valid_1; // @[PackageRecoveryState.scala 115:27 64:22]
  wire  _GEN_228 = _T_1 ? _GEN_166 : valid_2; // @[PackageRecoveryState.scala 115:27 64:22]
  wire  _GEN_229 = _T_1 ? _GEN_167 : valid_3; // @[PackageRecoveryState.scala 115:27 64:22]
  wire  _GEN_230 = _T_1 ? _GEN_168 : valid_4; // @[PackageRecoveryState.scala 115:27 64:22]
  wire  _GEN_231 = _T_1 ? _GEN_169 : valid_5; // @[PackageRecoveryState.scala 115:27 64:22]
  wire  _GEN_232 = _T_1 ? _GEN_170 : sealedImage_0; // @[PackageRecoveryState.scala 115:27 65:28]
  wire  _GEN_233 = _T_1 ? _GEN_171 : sealedImage_1; // @[PackageRecoveryState.scala 115:27 65:28]
  wire  _GEN_234 = _T_1 ? _GEN_172 : sealedImage_2; // @[PackageRecoveryState.scala 115:27 65:28]
  wire  _GEN_235 = _T_1 ? _GEN_173 : sealedImage_3; // @[PackageRecoveryState.scala 115:27 65:28]
  wire  _GEN_236 = _T_1 ? _GEN_174 : sealedImage_4; // @[PackageRecoveryState.scala 115:27 65:28]
  wire  _GEN_237 = _T_1 ? _GEN_175 : sealedImage_5; // @[PackageRecoveryState.scala 115:27 65:28]
  wire  _GEN_238 = _T_1 ? _GEN_176 : resultSeen_0; // @[PackageRecoveryState.scala 115:27 66:27]
  wire  _GEN_239 = _T_1 ? _GEN_177 : resultSeen_1; // @[PackageRecoveryState.scala 115:27 66:27]
  wire  _GEN_240 = _T_1 ? _GEN_178 : resultSeen_2; // @[PackageRecoveryState.scala 115:27 66:27]
  wire  _GEN_241 = _T_1 ? _GEN_179 : resultSeen_3; // @[PackageRecoveryState.scala 115:27 66:27]
  wire  _GEN_242 = _T_1 ? _GEN_180 : resultSeen_4; // @[PackageRecoveryState.scala 115:27 66:27]
  wire  _GEN_243 = _T_1 ? _GEN_181 : resultSeen_5; // @[PackageRecoveryState.scala 115:27 66:27]
  wire  _GEN_244 = _T_1 ? _GEN_182 : passed_0; // @[PackageRecoveryState.scala 115:27 67:23]
  wire  _GEN_245 = _T_1 ? _GEN_183 : passed_1; // @[PackageRecoveryState.scala 115:27 67:23]
  wire  _GEN_246 = _T_1 ? _GEN_184 : passed_2; // @[PackageRecoveryState.scala 115:27 67:23]
  wire  _GEN_247 = _T_1 ? _GEN_185 : passed_3; // @[PackageRecoveryState.scala 115:27 67:23]
  wire  _GEN_248 = _T_1 ? _GEN_186 : passed_4; // @[PackageRecoveryState.scala 115:27 67:23]
  wire  _GEN_249 = _T_1 ? _GEN_187 : passed_5; // @[PackageRecoveryState.scala 115:27 67:23]
  wire [2:0] _GEN_251 = _T_1 ? _GEN_189 : allocateSlot; // @[PackageRecoveryState.scala 115:27 71:29]
  wire  _GEN_252 = _T_1 ? _GEN_190 : capturing; // @[PackageRecoveryState.scala 115:27 73:26]
  wire [6:0] _GEN_253 = _T_1 ? _GEN_191 : captured; // @[PackageRecoveryState.scala 115:27 74:25]
  wire [31:0] _GEN_254 = _T_1 ? _GEN_192 : generation; // @[PackageRecoveryState.scala 115:27 77:23]
  wire [31:0] _GEN_255 = _T_1 ? _GEN_193 : lastSequence; // @[PackageRecoveryState.scala 115:27 76:25]
  wire  _io_word_ready_T_1 = capturing & _io_allocate_ready_T; // @[PackageRecoveryState.scala 134:30]
  wire  _T_3 = io_word_ready & io_word_valid; // @[Decoupled.scala 51:35]
  wire [31:0] _GEN_258 = 3'h1 == captureSlot ? header_1_sequence : header_0_sequence; // @[PackageRecoveryState.scala 137:{39,39}]
  wire [31:0] _GEN_259 = 3'h2 == captureSlot ? header_2_sequence : _GEN_258; // @[PackageRecoveryState.scala 137:{39,39}]
  wire [31:0] _GEN_260 = 3'h3 == captureSlot ? header_3_sequence : _GEN_259; // @[PackageRecoveryState.scala 137:{39,39}]
  wire [31:0] _GEN_261 = 3'h4 == captureSlot ? header_4_sequence : _GEN_260; // @[PackageRecoveryState.scala 137:{39,39}]
  wire [31:0] _GEN_262 = 3'h5 == captureSlot ? header_5_sequence : _GEN_261; // @[PackageRecoveryState.scala 137:{39,39}]
  wire [31:0] _GEN_264 = 3'h1 == captureSlot ? header_1_generation : header_0_generation; // @[PackageRecoveryState.scala 138:{31,31}]
  wire [31:0] _GEN_265 = 3'h2 == captureSlot ? header_2_generation : _GEN_264; // @[PackageRecoveryState.scala 138:{31,31}]
  wire [31:0] _GEN_266 = 3'h3 == captureSlot ? header_3_generation : _GEN_265; // @[PackageRecoveryState.scala 138:{31,31}]
  wire [31:0] _GEN_267 = 3'h4 == captureSlot ? header_4_generation : _GEN_266; // @[PackageRecoveryState.scala 138:{31,31}]
  wire [31:0] _GEN_268 = 3'h5 == captureSlot ? header_5_generation : _GEN_267; // @[PackageRecoveryState.scala 138:{31,31}]
  wire  _legal_T_9 = io_word_bits_generation == _GEN_268; // @[PackageRecoveryState.scala 138:31]
  wire  _legal_T_10 = io_word_bits_sequence == _GEN_262 & _legal_T_9; // @[PackageRecoveryState.scala 137:54]
  wire  _legal_T_14 = io_word_bits_data == 64'h0; // @[PackageRecoveryState.scala 139:46]
  wire  _legal_T_15 = captured != 7'h0 | io_word_bits_data == 64'h0; // @[PackageRecoveryState.scala 139:25]
  wire  _legal_T_16 = _legal_T_10 & io_word_bits_index == captured & _legal_T_15; // @[PackageRecoveryState.scala 138:83]
  wire [63:0] _GEN_270 = 3'h1 == captureSlot ? header_1_restartPc : header_0_restartPc; // @[PackageRecoveryState.scala 140:{47,47}]
  wire [63:0] _GEN_271 = 3'h2 == captureSlot ? header_2_restartPc : _GEN_270; // @[PackageRecoveryState.scala 140:{47,47}]
  wire [63:0] _GEN_272 = 3'h3 == captureSlot ? header_3_restartPc : _GEN_271; // @[PackageRecoveryState.scala 140:{47,47}]
  wire [63:0] _GEN_273 = 3'h4 == captureSlot ? header_4_restartPc : _GEN_272; // @[PackageRecoveryState.scala 140:{47,47}]
  wire [63:0] _GEN_274 = 3'h5 == captureSlot ? header_5_restartPc : _GEN_273; // @[PackageRecoveryState.scala 140:{47,47}]
  wire  _legal_T_19 = captured != 7'h40 | io_word_bits_data == _GEN_274; // @[PackageRecoveryState.scala 140:26]
  wire  _legal_T_20 = _legal_T_16 & _legal_T_19; // @[PackageRecoveryState.scala 139:55]
  wire  _legal_T_24 = io_word_bits_data == 64'h1; // @[PackageRecoveryState.scala 142:27]
  wire  _legal_T_25 = captured != 7'h41 | _legal_T_14 | _legal_T_24; // @[PackageRecoveryState.scala 141:55]
  wire  _legal_T_27 = _legal_T_25 | io_word_bits_data == 64'h3; // @[PackageRecoveryState.scala 142:35]
  wire  legal_1 = _legal_T_20 & _legal_T_27; // @[PackageRecoveryState.scala 140:64]
  wire [9:0] _T_5 = captureSlot * 7'h60; // @[PackageRecoveryState.scala 144:25]
  wire [9:0] _GEN_488 = {{3'd0}, captured}; // @[PackageRecoveryState.scala 144:35]
  wire [6:0] _captured_T_1 = captured + 7'h1; // @[PackageRecoveryState.scala 145:28]
  wire  _GEN_275 = ~legal_1 | _GEN_195; // @[PackageRecoveryState.scala 143:{19,27}]
  wire  _GEN_278 = ~legal_1 ? 1'h0 : 1'h1; // @[PackageRecoveryState.scala 143:19 144:12 69:18]
  wire  _GEN_282 = _T_3 ? _GEN_275 : _GEN_195; // @[PackageRecoveryState.scala 135:23]
  wire  _T_8 = io_seal_ready & io_seal_valid; // @[Decoupled.scala 51:35]
  wire [255:0] _T_9 = {io_seal_bits_sequence,io_seal_bits_generation,io_seal_bits_restartPc,
    io_seal_bits_architecturalToken,io_seal_bits_memoryToken}; // @[PackageRecoveryState.scala 150:24]
  wire [63:0] _GEN_290 = 3'h1 == captureSlot ? header_1_architecturalToken : header_0_architecturalToken; // @[PackageRecoveryState.scala 150:{55,55}]
  wire [63:0] _GEN_291 = 3'h2 == captureSlot ? header_2_architecturalToken : _GEN_290; // @[PackageRecoveryState.scala 150:{55,55}]
  wire [63:0] _GEN_292 = 3'h3 == captureSlot ? header_3_architecturalToken : _GEN_291; // @[PackageRecoveryState.scala 150:{55,55}]
  wire [63:0] _GEN_293 = 3'h4 == captureSlot ? header_4_architecturalToken : _GEN_292; // @[PackageRecoveryState.scala 150:{55,55}]
  wire [63:0] _GEN_294 = 3'h5 == captureSlot ? header_5_architecturalToken : _GEN_293; // @[PackageRecoveryState.scala 150:{55,55}]
  wire [63:0] _GEN_296 = 3'h1 == captureSlot ? header_1_memoryToken : header_0_memoryToken; // @[PackageRecoveryState.scala 150:{55,55}]
  wire [63:0] _GEN_297 = 3'h2 == captureSlot ? header_2_memoryToken : _GEN_296; // @[PackageRecoveryState.scala 150:{55,55}]
  wire [63:0] _GEN_298 = 3'h3 == captureSlot ? header_3_memoryToken : _GEN_297; // @[PackageRecoveryState.scala 150:{55,55}]
  wire [63:0] _GEN_299 = 3'h4 == captureSlot ? header_4_memoryToken : _GEN_298; // @[PackageRecoveryState.scala 150:{55,55}]
  wire [63:0] _GEN_300 = 3'h5 == captureSlot ? header_5_memoryToken : _GEN_299; // @[PackageRecoveryState.scala 150:{55,55}]
  wire [255:0] _T_10 = {_GEN_262,_GEN_268,_GEN_274,_GEN_294,_GEN_300}; // @[PackageRecoveryState.scala 150:55]
  wire  _GEN_301 = 3'h0 == captureSlot | _GEN_232; // @[PackageRecoveryState.scala 151:{45,45}]
  wire  _GEN_302 = 3'h1 == captureSlot | _GEN_233; // @[PackageRecoveryState.scala 151:{45,45}]
  wire  _GEN_303 = 3'h2 == captureSlot | _GEN_234; // @[PackageRecoveryState.scala 151:{45,45}]
  wire  _GEN_304 = 3'h3 == captureSlot | _GEN_235; // @[PackageRecoveryState.scala 151:{45,45}]
  wire  _GEN_305 = 3'h4 == captureSlot | _GEN_236; // @[PackageRecoveryState.scala 151:{45,45}]
  wire  _GEN_306 = 3'h5 == captureSlot | _GEN_237; // @[PackageRecoveryState.scala 151:{45,45}]
  wire  _GEN_307 = _T_9 != _T_10 | _GEN_282; // @[PackageRecoveryState.scala 150:{63,71}]
  wire  _GEN_314 = _T_9 != _T_10 & _GEN_252; // @[PackageRecoveryState.scala 150:63 151:66]
  wire  _GEN_315 = _T_8 ? _GEN_307 : _GEN_282; // @[PackageRecoveryState.scala 149:23]
  wire  _GEN_322 = _T_8 ? _GEN_314 : _GEN_252; // @[PackageRecoveryState.scala 149:23]
  wire  _io_result_ready_T_3 = ~active; // @[PackageRecoveryState.scala 154:43]
  wire  _resultMatch_T = header_0_sequence == io_result_bits_sequence; // @[PackageRecoveryState.scala 156:24]
  wire  _resultMatch_T_1 = valid_0 & _resultMatch_T; // @[PackageRecoveryState.scala 155:63]
  wire  _resultMatch_T_2 = header_0_generation == io_result_bits_generation; // @[PackageRecoveryState.scala 157:26]
  wire  _resultMatch_T_3 = _resultMatch_T_1 & _resultMatch_T_2; // @[PackageRecoveryState.scala 156:52]
  wire  resultMatch_0 = _resultMatch_T_3 & ~resultSeen_0; // @[PackageRecoveryState.scala 157:56]
  wire  _resultMatch_T_6 = header_1_sequence == io_result_bits_sequence; // @[PackageRecoveryState.scala 156:24]
  wire  _resultMatch_T_7 = valid_1 & _resultMatch_T_6; // @[PackageRecoveryState.scala 155:63]
  wire  _resultMatch_T_8 = header_1_generation == io_result_bits_generation; // @[PackageRecoveryState.scala 157:26]
  wire  _resultMatch_T_9 = _resultMatch_T_7 & _resultMatch_T_8; // @[PackageRecoveryState.scala 156:52]
  wire  resultMatch_1 = _resultMatch_T_9 & ~resultSeen_1; // @[PackageRecoveryState.scala 157:56]
  wire  _resultMatch_T_12 = header_2_sequence == io_result_bits_sequence; // @[PackageRecoveryState.scala 156:24]
  wire  _resultMatch_T_13 = valid_2 & _resultMatch_T_12; // @[PackageRecoveryState.scala 155:63]
  wire  _resultMatch_T_14 = header_2_generation == io_result_bits_generation; // @[PackageRecoveryState.scala 157:26]
  wire  _resultMatch_T_15 = _resultMatch_T_13 & _resultMatch_T_14; // @[PackageRecoveryState.scala 156:52]
  wire  resultMatch_2 = _resultMatch_T_15 & ~resultSeen_2; // @[PackageRecoveryState.scala 157:56]
  wire  _resultMatch_T_18 = header_3_sequence == io_result_bits_sequence; // @[PackageRecoveryState.scala 156:24]
  wire  _resultMatch_T_19 = valid_3 & _resultMatch_T_18; // @[PackageRecoveryState.scala 155:63]
  wire  _resultMatch_T_20 = header_3_generation == io_result_bits_generation; // @[PackageRecoveryState.scala 157:26]
  wire  _resultMatch_T_21 = _resultMatch_T_19 & _resultMatch_T_20; // @[PackageRecoveryState.scala 156:52]
  wire  resultMatch_3 = _resultMatch_T_21 & ~resultSeen_3; // @[PackageRecoveryState.scala 157:56]
  wire  _resultMatch_T_24 = header_4_sequence == io_result_bits_sequence; // @[PackageRecoveryState.scala 156:24]
  wire  _resultMatch_T_25 = valid_4 & _resultMatch_T_24; // @[PackageRecoveryState.scala 155:63]
  wire  _resultMatch_T_26 = header_4_generation == io_result_bits_generation; // @[PackageRecoveryState.scala 157:26]
  wire  _resultMatch_T_27 = _resultMatch_T_25 & _resultMatch_T_26; // @[PackageRecoveryState.scala 156:52]
  wire  resultMatch_4 = _resultMatch_T_27 & ~resultSeen_4; // @[PackageRecoveryState.scala 157:56]
  wire  _resultMatch_T_30 = header_5_sequence == io_result_bits_sequence; // @[PackageRecoveryState.scala 156:24]
  wire  _resultMatch_T_31 = valid_5 & _resultMatch_T_30; // @[PackageRecoveryState.scala 155:63]
  wire  _resultMatch_T_32 = header_5_generation == io_result_bits_generation; // @[PackageRecoveryState.scala 157:26]
  wire  _resultMatch_T_33 = _resultMatch_T_31 & _resultMatch_T_32; // @[PackageRecoveryState.scala 156:52]
  wire  resultMatch_5 = _resultMatch_T_33 & ~resultSeen_5; // @[PackageRecoveryState.scala 157:56]
  wire  _T_12 = io_result_ready & io_result_valid; // @[Decoupled.scala 51:35]
  wire [1:0] _T_13 = resultMatch_1 + resultMatch_2; // @[Bitwise.scala 51:90]
  wire [1:0] _GEN_495 = {{1'd0}, resultMatch_0}; // @[Bitwise.scala 51:90]
  wire [2:0] _T_15 = _GEN_495 + _T_13; // @[Bitwise.scala 51:90]
  wire [1:0] _T_17 = resultMatch_4 + resultMatch_5; // @[Bitwise.scala 51:90]
  wire [1:0] _GEN_496 = {{1'd0}, resultMatch_3}; // @[Bitwise.scala 51:90]
  wire [2:0] _T_19 = _GEN_496 + _T_17; // @[Bitwise.scala 51:90]
  wire [2:0] _T_21 = _T_15[1:0] + _T_19[1:0]; // @[Bitwise.scala 51:90]
  wire  _GEN_323 = resultMatch_0 | _GEN_238; // @[PackageRecoveryState.scala 162:33 163:27]
  wire  _GEN_325 = resultMatch_1 | _GEN_239; // @[PackageRecoveryState.scala 162:33 163:27]
  wire  _GEN_327 = resultMatch_2 | _GEN_240; // @[PackageRecoveryState.scala 162:33 163:27]
  wire  _GEN_329 = resultMatch_3 | _GEN_241; // @[PackageRecoveryState.scala 162:33 163:27]
  wire  _GEN_331 = resultMatch_4 | _GEN_242; // @[PackageRecoveryState.scala 162:33 163:27]
  wire  _GEN_333 = resultMatch_5 | _GEN_243; // @[PackageRecoveryState.scala 162:33 163:27]
  wire  _GEN_335 = _io_freezeRequested_T_2 | failed; // @[PackageRecoveryState.scala 167:39 168:18 78:23]
  wire  _GEN_337 = _T_21 != 3'h1 | ~io_result_bits_compared | _GEN_315; // @[PackageRecoveryState.scala 159:{70,78}]
  wire  _GEN_350 = _T_21 != 3'h1 | ~io_result_bits_compared ? failed : _GEN_335; // @[PackageRecoveryState.scala 159:70 78:23]
  wire  _GEN_352 = _T_12 ? _GEN_337 : _GEN_315; // @[PackageRecoveryState.scala 158:25]
  wire  _GEN_365 = _T_12 ? _GEN_350 : failed; // @[PackageRecoveryState.scala 158:25 78:23]
  wire  _T_29 = _io_result_ready_T_3 & ~restoredPendingRebase; // @[PackageRecoveryState.scala 173:17]
  wire  _T_35 = ~io_lock | failed; // @[PackageRecoveryState.scala 174:17]
  wire  _T_36 = _io_result_ready_T_3 & ~restoredPendingRebase & _io_checkpoint_valid_T & _io_failure_valid_T & _T_35; // @[PackageRecoveryState.scala 173:73]
  wire  _T_39 = _T_36 & ~io_result_valid & prefixAdvance; // @[PackageRecoveryState.scala 174:48]
  wire [31:0] _T_41 = _GEN_47 + 32'h1; // @[PackageRecoveryState.scala 175:69]
  wire [31:0] _GEN_368 = 3'h1 == successor ? header_1_generation : header_0_generation; // @[PackageRecoveryState.scala 176:{41,41}]
  wire [31:0] _GEN_369 = 3'h2 == successor ? header_2_generation : _GEN_368; // @[PackageRecoveryState.scala 176:{41,41}]
  wire [31:0] _GEN_370 = 3'h3 == successor ? header_3_generation : _GEN_369; // @[PackageRecoveryState.scala 176:{41,41}]
  wire [31:0] _GEN_371 = 3'h4 == successor ? header_4_generation : _GEN_370; // @[PackageRecoveryState.scala 176:{41,41}]
  wire [31:0] _GEN_372 = 3'h5 == successor ? header_5_generation : _GEN_371; // @[PackageRecoveryState.scala 176:{41,41}]
  wire  _GEN_373 = 3'h0 == safeSlot ? 1'h0 : _GEN_226; // @[PackageRecoveryState.scala 177:{21,21}]
  wire  _GEN_374 = 3'h1 == safeSlot ? 1'h0 : _GEN_227; // @[PackageRecoveryState.scala 177:{21,21}]
  wire  _GEN_375 = 3'h2 == safeSlot ? 1'h0 : _GEN_228; // @[PackageRecoveryState.scala 177:{21,21}]
  wire  _GEN_376 = 3'h3 == safeSlot ? 1'h0 : _GEN_229; // @[PackageRecoveryState.scala 177:{21,21}]
  wire  _GEN_377 = 3'h4 == safeSlot ? 1'h0 : _GEN_230; // @[PackageRecoveryState.scala 177:{21,21}]
  wire  _GEN_378 = 3'h5 == safeSlot ? 1'h0 : _GEN_231; // @[PackageRecoveryState.scala 177:{21,21}]
  wire  _GEN_379 = _T_36 & ~io_result_valid & prefixAdvance ? _GEN_373 : _GEN_226; // @[PackageRecoveryState.scala 174:66]
  wire  _GEN_380 = _T_36 & ~io_result_valid & prefixAdvance ? _GEN_374 : _GEN_227; // @[PackageRecoveryState.scala 174:66]
  wire  _GEN_381 = _T_36 & ~io_result_valid & prefixAdvance ? _GEN_375 : _GEN_228; // @[PackageRecoveryState.scala 174:66]
  wire  _GEN_382 = _T_36 & ~io_result_valid & prefixAdvance ? _GEN_376 : _GEN_229; // @[PackageRecoveryState.scala 174:66]
  wire  _GEN_383 = _T_36 & ~io_result_valid & prefixAdvance ? _GEN_377 : _GEN_230; // @[PackageRecoveryState.scala 174:66]
  wire  _GEN_384 = _T_36 & ~io_result_valid & prefixAdvance ? _GEN_378 : _GEN_231; // @[PackageRecoveryState.scala 174:66]
  wire [9:0] _io_write_bits_data_T = safeSlot * 7'h60; // @[PackageRecoveryState.scala 185:40]
  wire [9:0] _GEN_497 = {{3'd0}, index}; // @[PackageRecoveryState.scala 185:50]
  wire  _T_50 = io_restore_ready & io_restore_valid; // @[Decoupled.scala 51:35]
  wire [255:0] _legal_T_30 = {io_restore_bits_checkpoint_sequence,io_restore_bits_checkpoint_generation,
    io_restore_bits_checkpoint_restartPc,io_restore_bits_checkpoint_architecturalToken,
    io_restore_bits_checkpoint_memoryToken}; // @[PackageRecoveryState.scala 189:20]
  wire [255:0] _legal_T_31 = {_GEN_47,_GEN_53,_GEN_59,_GEN_65,_GEN_71}; // @[PackageRecoveryState.scala 189:48]
  wire  _legal_T_32 = _legal_T_30 == _legal_T_31; // @[PackageRecoveryState.scala 189:27]
  wire  _legal_T_33 = io_lock & failed & safeValid & _legal_T_32; // @[PackageRecoveryState.scala 188:48]
  wire  _legal_T_34 = io_restore_bits_failedSequence == failureSequence; // @[PackageRecoveryState.scala 190:24]
  wire  _legal_T_35 = _legal_T_33 & _legal_T_34; // @[PackageRecoveryState.scala 189:55]
  wire  _legal_T_38 = io_restore_bits_checkpoint_generation != 32'hffffffff; // @[PackageRecoveryState.scala 191:31]
  wire  _legal_T_39 = _legal_T_35 & io_restore_bits_failedSequence > io_restore_bits_checkpoint_sequence & _legal_T_38; // @[PackageRecoveryState.scala 190:88]
  wire [31:0] _legal_T_41 = io_restore_bits_checkpoint_generation + 32'h1; // @[PackageRecoveryState.scala 192:56]
  wire  _legal_T_42 = io_restore_bits_recoveryGeneration == _legal_T_41; // @[PackageRecoveryState.scala 192:28]
  wire  legal_2 = _legal_T_39 & _legal_T_42; // @[PackageRecoveryState.scala 191:49]
  wire  _GEN_386 = ~legal_2 | _GEN_352; // @[PackageRecoveryState.scala 193:{19,27}]
  wire [6:0] _GEN_394 = ~legal_2 ? index : 7'h0; // @[PackageRecoveryState.scala 193:19 195:13 84:22]
  wire  _GEN_395 = ~legal_2 ? active : 1'h1; // @[PackageRecoveryState.scala 193:19 196:14 82:23]
  wire  _GEN_396 = ~legal_2 & sent; // @[PackageRecoveryState.scala 193:19 197:12 83:21]
  wire  _GEN_397 = _T_50 ? _GEN_386 : _GEN_352; // @[PackageRecoveryState.scala 186:26]
  wire [6:0] _GEN_405 = _T_50 ? _GEN_394 : index; // @[PackageRecoveryState.scala 186:26 84:22]
  wire  _GEN_406 = _T_50 ? _GEN_395 : active; // @[PackageRecoveryState.scala 186:26 82:23]
  wire  _GEN_407 = _T_50 ? _GEN_396 : sent; // @[PackageRecoveryState.scala 186:26 83:21]
  wire  _T_52 = io_write_ready & io_write_valid; // @[Decoupled.scala 51:35]
  wire  _GEN_408 = _T_52 | _GEN_407; // @[PackageRecoveryState.scala 200:{24,31}]
  wire [319:0] _legal_T_46 = {io_writeCompleted_bits_command_checkpoint_sequence,
    io_writeCompleted_bits_command_checkpoint_generation,io_writeCompleted_bits_command_checkpoint_restartPc,
    io_writeCompleted_bits_command_checkpoint_architecturalToken,io_writeCompleted_bits_command_checkpoint_memoryToken,
    io_writeCompleted_bits_command_failedSequence,io_writeCompleted_bits_command_recoveryGeneration}; // @[PackageRecoveryState.scala 203:38]
  wire [319:0] _legal_T_47 = {command_checkpoint_sequence,command_checkpoint_generation,command_checkpoint_restartPc,
    command_checkpoint_architecturalToken,command_checkpoint_memoryToken,command_failedSequence,
    command_recoveryGeneration}; // @[PackageRecoveryState.scala 203:57]
  wire  _legal_T_48 = _legal_T_46 == _legal_T_47; // @[PackageRecoveryState.scala 203:45]
  wire  _legal_T_49 = active & (sent | _T_52) & _legal_T_48; // @[PackageRecoveryState.scala 202:51]
  wire  _legal_T_50 = io_writeCompleted_bits_index == index; // @[PackageRecoveryState.scala 204:36]
  wire  _legal_T_51 = _legal_T_49 & _legal_T_50; // @[PackageRecoveryState.scala 203:64]
  wire  _legal_T_55 = io_writeCompleted_bits_data == image_legal_MPORT_data; // @[PackageRecoveryState.scala 205:35]
  wire  legal_3 = _legal_T_51 & _legal_T_55; // @[PackageRecoveryState.scala 204:46]
  wire [6:0] _index_T_1 = index + 7'h1; // @[PackageRecoveryState.scala 212:36]
  wire  _GEN_410 = index == 7'h5f | restoredPendingRebase; // @[PackageRecoveryState.scala 208:38 210:31 86:38]
  wire  _GEN_411 = index == 7'h5f & _io_checkpoint_valid_T; // @[PackageRecoveryState.scala 109:21 208:38 211:27]
  wire  _GEN_413 = ~legal_3 | _GEN_397; // @[PackageRecoveryState.scala 206:{19,27}]
  wire  _GEN_414 = ~legal_3 & _GEN_408; // @[PackageRecoveryState.scala 206:19 207:12]
  wire  _GEN_416 = ~legal_3 ? restoredPendingRebase : _GEN_410; // @[PackageRecoveryState.scala 206:19 86:38]
  wire  _GEN_417 = ~legal_3 ? 1'h0 : _GEN_411; // @[PackageRecoveryState.scala 206:19 109:21]
  wire  _GEN_422 = io_writeCompleted_valid ? _GEN_413 : _GEN_397; // @[PackageRecoveryState.scala 201:34]
  wire  _GEN_425 = io_writeCompleted_valid ? _GEN_416 : restoredPendingRebase; // @[PackageRecoveryState.scala 201:34 86:38]
  wire  _T_55 = io_rebase_ready & io_rebase_valid; // @[Decoupled.scala 51:35]
  wire [319:0] _legal_T_56 = {io_rebase_bits_command_checkpoint_sequence,io_rebase_bits_command_checkpoint_generation,
    io_rebase_bits_command_checkpoint_restartPc,io_rebase_bits_command_checkpoint_architecturalToken,
    io_rebase_bits_command_checkpoint_memoryToken,io_rebase_bits_command_failedSequence,
    io_rebase_bits_command_recoveryGeneration}; // @[PackageRecoveryState.scala 217:51]
  wire  _legal_T_60 = io_lock & _legal_T_56 == _legal_T_47 & io_rebase_bits_pipelineQuiescent; // @[PackageRecoveryState.scala 217:77]
  wire  _legal_T_62 = _legal_T_60 & io_rebase_bits_memoryRestored & io_rebase_bits_architectureRestored; // @[PackageRecoveryState.scala 218:73]
  wire  legal_4 = _legal_T_62 & io_rebase_bits_checkersInitialized; // @[PackageRecoveryState.scala 219:43]
  wire  _GEN_440 = ~legal_4 | _GEN_422; // @[PackageRecoveryState.scala 220:{19,27}]
  wire  _GEN_456 = ~legal_4 & _GEN_322; // @[PackageRecoveryState.scala 220:19 226:17]
  wire  _GEN_457 = ~legal_4 & _GEN_365; // @[PackageRecoveryState.scala 220:19 227:14]
  wire  _GEN_458 = ~legal_4 & _GEN_72; // @[PackageRecoveryState.scala 220:19 228:23]
  wire  _GEN_459 = ~legal_4 & _GEN_425; // @[PackageRecoveryState.scala 220:19 229:29]
  wire  _GEN_499 = _T_39 & ~reset; // @[PackageRecoveryState.scala 175:11]
  assign image_io_write_bits_data_MPORT_en = 1'h1;
  assign image_io_write_bits_data_MPORT_addr = _io_write_bits_data_T + _GEN_497;
  `ifndef RANDOMIZE_GARBAGE_ASSIGN
  assign image_io_write_bits_data_MPORT_data = image[image_io_write_bits_data_MPORT_addr]; // @[PackageRecoveryState.scala 69:18]
  `else
  assign image_io_write_bits_data_MPORT_data = image_io_write_bits_data_MPORT_addr >= 10'h240 ? _RAND_1[63:0] :
    image[image_io_write_bits_data_MPORT_addr]; // @[PackageRecoveryState.scala 69:18]
  `endif // RANDOMIZE_GARBAGE_ASSIGN
  assign image_legal_MPORT_en = io_writeCompleted_valid;
  assign image_legal_MPORT_addr = _io_write_bits_data_T + _GEN_497;
  `ifndef RANDOMIZE_GARBAGE_ASSIGN
  assign image_legal_MPORT_data = image[image_legal_MPORT_addr]; // @[PackageRecoveryState.scala 69:18]
  `else
  assign image_legal_MPORT_data = image_legal_MPORT_addr >= 10'h240 ? _RAND_2[63:0] : image[image_legal_MPORT_addr]; // @[PackageRecoveryState.scala 69:18]
  `endif // RANDOMIZE_GARBAGE_ASSIGN
  assign image_MPORT_data = io_word_bits_data;
  assign image_MPORT_addr = _T_5 + _GEN_488;
  assign image_MPORT_mask = 1'h1;
  assign image_MPORT_en = _T_3 & _GEN_278;
  assign io_allocate_ready = ~locked & ~capturing & ~_GEN_78; // @[PackageRecoveryState.scala 114:46]
  assign io_word_ready = capturing & _io_allocate_ready_T & captured < 7'h60; // @[PackageRecoveryState.scala 134:41]
  assign io_seal_ready = _io_word_ready_T_1 & captured == 7'h60; // @[PackageRecoveryState.scala 148:41]
  assign io_result_ready = _io_checkpoint_valid_T & _prefixAdvance_T_3 & ~active; // @[PackageRecoveryState.scala 154:40]
  assign io_checkpoint_valid = safeValid & ~error; // @[PackageRecoveryState.scala 93:36]
  assign io_checkpoint_bits_sequence = 3'h5 == safeSlot ? header_5_sequence : _GEN_46; // @[PackageRecoveryState.scala 94:{22,22}]
  assign io_checkpoint_bits_generation = 3'h5 == safeSlot ? header_5_generation : _GEN_52; // @[PackageRecoveryState.scala 94:{22,22}]
  assign io_checkpoint_bits_restartPc = 3'h5 == safeSlot ? header_5_restartPc : _GEN_58; // @[PackageRecoveryState.scala 94:{22,22}]
  assign io_checkpoint_bits_architecturalToken = 3'h5 == safeSlot ? header_5_architecturalToken : _GEN_64; // @[PackageRecoveryState.scala 94:{22,22}]
  assign io_checkpoint_bits_memoryToken = 3'h5 == safeSlot ? header_5_memoryToken : _GEN_70; // @[PackageRecoveryState.scala 94:{22,22}]
  assign io_failure_valid = failed & ~failureReported & _io_checkpoint_valid_T & ~prefixAdvance; // @[PackageRecoveryState.scala 103:60]
  assign io_failure_bits_sequence = failureSequence; // @[PackageRecoveryState.scala 104:28]
  assign io_failure_bits_generation = generation; // @[PackageRecoveryState.scala 105:30]
  assign io_failure_bits_allocated = 1'h1; // @[PackageRecoveryState.scala 106:29]
  assign io_failure_bits_comparedMismatch = 1'h1; // @[PackageRecoveryState.scala 107:36]
  assign io_restore_ready = _T_29 & _io_checkpoint_valid_T; // @[PackageRecoveryState.scala 181:57]
  assign io_write_valid = active & ~sent & _io_checkpoint_valid_T; // @[PackageRecoveryState.scala 182:37]
  assign io_write_bits_command_checkpoint_sequence = command_checkpoint_sequence; // @[PackageRecoveryState.scala 183:25]
  assign io_write_bits_command_checkpoint_generation = command_checkpoint_generation; // @[PackageRecoveryState.scala 183:25]
  assign io_write_bits_command_checkpoint_restartPc = command_checkpoint_restartPc; // @[PackageRecoveryState.scala 183:25]
  assign io_write_bits_command_checkpoint_architecturalToken = command_checkpoint_architecturalToken; // @[PackageRecoveryState.scala 183:25]
  assign io_write_bits_command_checkpoint_memoryToken = command_checkpoint_memoryToken; // @[PackageRecoveryState.scala 183:25]
  assign io_write_bits_command_failedSequence = command_failedSequence; // @[PackageRecoveryState.scala 183:25]
  assign io_write_bits_command_recoveryGeneration = command_recoveryGeneration; // @[PackageRecoveryState.scala 183:25]
  assign io_write_bits_index = index; // @[PackageRecoveryState.scala 184:23]
  assign io_write_bits_data = image_io_write_bits_data_MPORT_data; // @[PackageRecoveryState.scala 185:22]
  assign io_restored_valid = io_writeCompleted_valid & _GEN_417; // @[PackageRecoveryState.scala 109:21 201:34]
  assign io_restored_bits_command_checkpoint_sequence = command_checkpoint_sequence; // @[PackageRecoveryState.scala 110:28]
  assign io_restored_bits_command_checkpoint_generation = command_checkpoint_generation; // @[PackageRecoveryState.scala 110:28]
  assign io_restored_bits_command_checkpoint_restartPc = command_checkpoint_restartPc; // @[PackageRecoveryState.scala 110:28]
  assign io_restored_bits_command_checkpoint_architecturalToken = command_checkpoint_architecturalToken; // @[PackageRecoveryState.scala 110:28]
  assign io_restored_bits_command_checkpoint_memoryToken = command_checkpoint_memoryToken; // @[PackageRecoveryState.scala 110:28]
  assign io_restored_bits_command_failedSequence = command_failedSequence; // @[PackageRecoveryState.scala 110:28]
  assign io_restored_bits_command_recoveryGeneration = command_recoveryGeneration; // @[PackageRecoveryState.scala 110:28]
  assign io_restored_bits_retiredPc = 64'h0; // @[PackageRecoveryState.scala 111:30]
  assign io_restored_bits_allCheckerTasksDrained = 1'h0; // @[PackageRecoveryState.scala 112:43]
  assign io_rebase_ready = _io_result_ready_T_3 & restoredPendingRebase & _io_checkpoint_valid_T; // @[PackageRecoveryState.scala 215:55]
  assign io_protocolError = error; // @[PackageRecoveryState.scala 95:20]
  assign io_freezeRequested = failed | active | error | _io_freezeRequested_T_3; // @[PackageRecoveryState.scala 96:51]
  assign io_restoreActive = active; // @[PackageRecoveryState.scala 98:20]
  assign io_occupancy = _io_occupancy_T_2[1:0] + _io_occupancy_T_6[1:0]; // @[Bitwise.scala 51:90]
  always @(posedge clock) begin
    if (image_MPORT_en & image_MPORT_mask) begin
      image[image_MPORT_addr] <= image_MPORT_data; // @[PackageRecoveryState.scala 69:18]
    end
    if (reset) begin // @[PackageRecoveryState.scala 64:22]
      valid_0 <= 1'h0; // @[PackageRecoveryState.scala 64:22]
    end else if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 220:19]
        valid_0 <= _GEN_379;
      end else if (safeSlot != 3'h0) begin // @[PackageRecoveryState.scala 221:58]
        valid_0 <= 1'h0; // @[PackageRecoveryState.scala 221:69]
      end else begin
        valid_0 <= _GEN_379;
      end
    end else begin
      valid_0 <= _GEN_379;
    end
    if (reset) begin // @[PackageRecoveryState.scala 64:22]
      valid_1 <= 1'h0; // @[PackageRecoveryState.scala 64:22]
    end else if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 220:19]
        valid_1 <= _GEN_380;
      end else if (safeSlot != 3'h1) begin // @[PackageRecoveryState.scala 221:58]
        valid_1 <= 1'h0; // @[PackageRecoveryState.scala 221:69]
      end else begin
        valid_1 <= _GEN_380;
      end
    end else begin
      valid_1 <= _GEN_380;
    end
    if (reset) begin // @[PackageRecoveryState.scala 64:22]
      valid_2 <= 1'h0; // @[PackageRecoveryState.scala 64:22]
    end else if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 220:19]
        valid_2 <= _GEN_381;
      end else if (safeSlot != 3'h2) begin // @[PackageRecoveryState.scala 221:58]
        valid_2 <= 1'h0; // @[PackageRecoveryState.scala 221:69]
      end else begin
        valid_2 <= _GEN_381;
      end
    end else begin
      valid_2 <= _GEN_381;
    end
    if (reset) begin // @[PackageRecoveryState.scala 64:22]
      valid_3 <= 1'h0; // @[PackageRecoveryState.scala 64:22]
    end else if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 220:19]
        valid_3 <= _GEN_382;
      end else if (safeSlot != 3'h3) begin // @[PackageRecoveryState.scala 221:58]
        valid_3 <= 1'h0; // @[PackageRecoveryState.scala 221:69]
      end else begin
        valid_3 <= _GEN_382;
      end
    end else begin
      valid_3 <= _GEN_382;
    end
    if (reset) begin // @[PackageRecoveryState.scala 64:22]
      valid_4 <= 1'h0; // @[PackageRecoveryState.scala 64:22]
    end else if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 220:19]
        valid_4 <= _GEN_383;
      end else if (safeSlot != 3'h4) begin // @[PackageRecoveryState.scala 221:58]
        valid_4 <= 1'h0; // @[PackageRecoveryState.scala 221:69]
      end else begin
        valid_4 <= _GEN_383;
      end
    end else begin
      valid_4 <= _GEN_383;
    end
    if (reset) begin // @[PackageRecoveryState.scala 64:22]
      valid_5 <= 1'h0; // @[PackageRecoveryState.scala 64:22]
    end else if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 220:19]
        valid_5 <= _GEN_384;
      end else if (safeSlot != 3'h5) begin // @[PackageRecoveryState.scala 221:58]
        valid_5 <= 1'h0; // @[PackageRecoveryState.scala 221:69]
      end else begin
        valid_5 <= _GEN_384;
      end
    end else begin
      valid_5 <= _GEN_384;
    end
    if (reset) begin // @[PackageRecoveryState.scala 65:28]
      sealedImage_0 <= 1'h0; // @[PackageRecoveryState.scala 65:28]
    end else if (_T_8) begin // @[PackageRecoveryState.scala 149:23]
      if (_T_9 != _T_10) begin // @[PackageRecoveryState.scala 150:63]
        sealedImage_0 <= _GEN_232;
      end else begin
        sealedImage_0 <= _GEN_301;
      end
    end else begin
      sealedImage_0 <= _GEN_232;
    end
    if (reset) begin // @[PackageRecoveryState.scala 65:28]
      sealedImage_1 <= 1'h0; // @[PackageRecoveryState.scala 65:28]
    end else if (_T_8) begin // @[PackageRecoveryState.scala 149:23]
      if (_T_9 != _T_10) begin // @[PackageRecoveryState.scala 150:63]
        sealedImage_1 <= _GEN_233;
      end else begin
        sealedImage_1 <= _GEN_302;
      end
    end else begin
      sealedImage_1 <= _GEN_233;
    end
    if (reset) begin // @[PackageRecoveryState.scala 65:28]
      sealedImage_2 <= 1'h0; // @[PackageRecoveryState.scala 65:28]
    end else if (_T_8) begin // @[PackageRecoveryState.scala 149:23]
      if (_T_9 != _T_10) begin // @[PackageRecoveryState.scala 150:63]
        sealedImage_2 <= _GEN_234;
      end else begin
        sealedImage_2 <= _GEN_303;
      end
    end else begin
      sealedImage_2 <= _GEN_234;
    end
    if (reset) begin // @[PackageRecoveryState.scala 65:28]
      sealedImage_3 <= 1'h0; // @[PackageRecoveryState.scala 65:28]
    end else if (_T_8) begin // @[PackageRecoveryState.scala 149:23]
      if (_T_9 != _T_10) begin // @[PackageRecoveryState.scala 150:63]
        sealedImage_3 <= _GEN_235;
      end else begin
        sealedImage_3 <= _GEN_304;
      end
    end else begin
      sealedImage_3 <= _GEN_235;
    end
    if (reset) begin // @[PackageRecoveryState.scala 65:28]
      sealedImage_4 <= 1'h0; // @[PackageRecoveryState.scala 65:28]
    end else if (_T_8) begin // @[PackageRecoveryState.scala 149:23]
      if (_T_9 != _T_10) begin // @[PackageRecoveryState.scala 150:63]
        sealedImage_4 <= _GEN_236;
      end else begin
        sealedImage_4 <= _GEN_305;
      end
    end else begin
      sealedImage_4 <= _GEN_236;
    end
    if (reset) begin // @[PackageRecoveryState.scala 65:28]
      sealedImage_5 <= 1'h0; // @[PackageRecoveryState.scala 65:28]
    end else if (_T_8) begin // @[PackageRecoveryState.scala 149:23]
      if (_T_9 != _T_10) begin // @[PackageRecoveryState.scala 150:63]
        sealedImage_5 <= _GEN_237;
      end else begin
        sealedImage_5 <= _GEN_306;
      end
    end else begin
      sealedImage_5 <= _GEN_237;
    end
    if (reset) begin // @[PackageRecoveryState.scala 66:27]
      resultSeen_0 <= 1'h0; // @[PackageRecoveryState.scala 66:27]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 158:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 159:70]
        resultSeen_0 <= _GEN_238;
      end else begin
        resultSeen_0 <= _GEN_323;
      end
    end else begin
      resultSeen_0 <= _GEN_238;
    end
    if (reset) begin // @[PackageRecoveryState.scala 66:27]
      resultSeen_1 <= 1'h0; // @[PackageRecoveryState.scala 66:27]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 158:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 159:70]
        resultSeen_1 <= _GEN_239;
      end else begin
        resultSeen_1 <= _GEN_325;
      end
    end else begin
      resultSeen_1 <= _GEN_239;
    end
    if (reset) begin // @[PackageRecoveryState.scala 66:27]
      resultSeen_2 <= 1'h0; // @[PackageRecoveryState.scala 66:27]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 158:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 159:70]
        resultSeen_2 <= _GEN_240;
      end else begin
        resultSeen_2 <= _GEN_327;
      end
    end else begin
      resultSeen_2 <= _GEN_240;
    end
    if (reset) begin // @[PackageRecoveryState.scala 66:27]
      resultSeen_3 <= 1'h0; // @[PackageRecoveryState.scala 66:27]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 158:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 159:70]
        resultSeen_3 <= _GEN_241;
      end else begin
        resultSeen_3 <= _GEN_329;
      end
    end else begin
      resultSeen_3 <= _GEN_241;
    end
    if (reset) begin // @[PackageRecoveryState.scala 66:27]
      resultSeen_4 <= 1'h0; // @[PackageRecoveryState.scala 66:27]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 158:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 159:70]
        resultSeen_4 <= _GEN_242;
      end else begin
        resultSeen_4 <= _GEN_331;
      end
    end else begin
      resultSeen_4 <= _GEN_242;
    end
    if (reset) begin // @[PackageRecoveryState.scala 66:27]
      resultSeen_5 <= 1'h0; // @[PackageRecoveryState.scala 66:27]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 158:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 159:70]
        resultSeen_5 <= _GEN_243;
      end else begin
        resultSeen_5 <= _GEN_333;
      end
    end else begin
      resultSeen_5 <= _GEN_243;
    end
    if (reset) begin // @[PackageRecoveryState.scala 67:23]
      passed_0 <= 1'h0; // @[PackageRecoveryState.scala 67:23]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 158:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 159:70]
        passed_0 <= _GEN_244;
      end else if (resultMatch_0) begin // @[PackageRecoveryState.scala 162:33]
        passed_0 <= io_result_bits_passed; // @[PackageRecoveryState.scala 164:23]
      end else begin
        passed_0 <= _GEN_244;
      end
    end else begin
      passed_0 <= _GEN_244;
    end
    if (reset) begin // @[PackageRecoveryState.scala 67:23]
      passed_1 <= 1'h0; // @[PackageRecoveryState.scala 67:23]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 158:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 159:70]
        passed_1 <= _GEN_245;
      end else if (resultMatch_1) begin // @[PackageRecoveryState.scala 162:33]
        passed_1 <= io_result_bits_passed; // @[PackageRecoveryState.scala 164:23]
      end else begin
        passed_1 <= _GEN_245;
      end
    end else begin
      passed_1 <= _GEN_245;
    end
    if (reset) begin // @[PackageRecoveryState.scala 67:23]
      passed_2 <= 1'h0; // @[PackageRecoveryState.scala 67:23]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 158:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 159:70]
        passed_2 <= _GEN_246;
      end else if (resultMatch_2) begin // @[PackageRecoveryState.scala 162:33]
        passed_2 <= io_result_bits_passed; // @[PackageRecoveryState.scala 164:23]
      end else begin
        passed_2 <= _GEN_246;
      end
    end else begin
      passed_2 <= _GEN_246;
    end
    if (reset) begin // @[PackageRecoveryState.scala 67:23]
      passed_3 <= 1'h0; // @[PackageRecoveryState.scala 67:23]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 158:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 159:70]
        passed_3 <= _GEN_247;
      end else if (resultMatch_3) begin // @[PackageRecoveryState.scala 162:33]
        passed_3 <= io_result_bits_passed; // @[PackageRecoveryState.scala 164:23]
      end else begin
        passed_3 <= _GEN_247;
      end
    end else begin
      passed_3 <= _GEN_247;
    end
    if (reset) begin // @[PackageRecoveryState.scala 67:23]
      passed_4 <= 1'h0; // @[PackageRecoveryState.scala 67:23]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 158:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 159:70]
        passed_4 <= _GEN_248;
      end else if (resultMatch_4) begin // @[PackageRecoveryState.scala 162:33]
        passed_4 <= io_result_bits_passed; // @[PackageRecoveryState.scala 164:23]
      end else begin
        passed_4 <= _GEN_248;
      end
    end else begin
      passed_4 <= _GEN_248;
    end
    if (reset) begin // @[PackageRecoveryState.scala 67:23]
      passed_5 <= 1'h0; // @[PackageRecoveryState.scala 67:23]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 158:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 159:70]
        passed_5 <= _GEN_249;
      end else if (resultMatch_5) begin // @[PackageRecoveryState.scala 162:33]
        passed_5 <= io_result_bits_passed; // @[PackageRecoveryState.scala 164:23]
      end else begin
        passed_5 <= _GEN_249;
      end
    end else begin
      passed_5 <= _GEN_249;
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h0 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_0_sequence <= io_allocate_bits_sequence; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 220:19]
        header_0_generation <= _GEN_202;
      end else if (3'h0 == safeSlot) begin // @[PackageRecoveryState.scala 222:35]
        header_0_generation <= command_recoveryGeneration; // @[PackageRecoveryState.scala 222:35]
      end else begin
        header_0_generation <= _GEN_202;
      end
    end else begin
      header_0_generation <= _GEN_202;
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h0 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_0_restartPc <= io_allocate_bits_restartPc; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h0 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_0_architecturalToken <= io_allocate_bits_architecturalToken; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h0 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_0_memoryToken <= io_allocate_bits_memoryToken; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h1 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_1_sequence <= io_allocate_bits_sequence; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 220:19]
        header_1_generation <= _GEN_203;
      end else if (3'h1 == safeSlot) begin // @[PackageRecoveryState.scala 222:35]
        header_1_generation <= command_recoveryGeneration; // @[PackageRecoveryState.scala 222:35]
      end else begin
        header_1_generation <= _GEN_203;
      end
    end else begin
      header_1_generation <= _GEN_203;
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h1 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_1_restartPc <= io_allocate_bits_restartPc; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h1 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_1_architecturalToken <= io_allocate_bits_architecturalToken; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h1 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_1_memoryToken <= io_allocate_bits_memoryToken; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h2 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_2_sequence <= io_allocate_bits_sequence; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 220:19]
        header_2_generation <= _GEN_204;
      end else if (3'h2 == safeSlot) begin // @[PackageRecoveryState.scala 222:35]
        header_2_generation <= command_recoveryGeneration; // @[PackageRecoveryState.scala 222:35]
      end else begin
        header_2_generation <= _GEN_204;
      end
    end else begin
      header_2_generation <= _GEN_204;
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h2 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_2_restartPc <= io_allocate_bits_restartPc; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h2 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_2_architecturalToken <= io_allocate_bits_architecturalToken; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h2 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_2_memoryToken <= io_allocate_bits_memoryToken; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h3 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_3_sequence <= io_allocate_bits_sequence; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 220:19]
        header_3_generation <= _GEN_205;
      end else if (3'h3 == safeSlot) begin // @[PackageRecoveryState.scala 222:35]
        header_3_generation <= command_recoveryGeneration; // @[PackageRecoveryState.scala 222:35]
      end else begin
        header_3_generation <= _GEN_205;
      end
    end else begin
      header_3_generation <= _GEN_205;
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h3 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_3_restartPc <= io_allocate_bits_restartPc; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h3 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_3_architecturalToken <= io_allocate_bits_architecturalToken; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h3 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_3_memoryToken <= io_allocate_bits_memoryToken; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h4 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_4_sequence <= io_allocate_bits_sequence; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 220:19]
        header_4_generation <= _GEN_206;
      end else if (3'h4 == safeSlot) begin // @[PackageRecoveryState.scala 222:35]
        header_4_generation <= command_recoveryGeneration; // @[PackageRecoveryState.scala 222:35]
      end else begin
        header_4_generation <= _GEN_206;
      end
    end else begin
      header_4_generation <= _GEN_206;
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h4 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_4_restartPc <= io_allocate_bits_restartPc; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h4 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_4_architecturalToken <= io_allocate_bits_architecturalToken; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h4 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_4_memoryToken <= io_allocate_bits_memoryToken; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h5 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_5_sequence <= io_allocate_bits_sequence; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 220:19]
        header_5_generation <= _GEN_207;
      end else if (3'h5 == safeSlot) begin // @[PackageRecoveryState.scala 222:35]
        header_5_generation <= command_recoveryGeneration; // @[PackageRecoveryState.scala 222:35]
      end else begin
        header_5_generation <= _GEN_207;
      end
    end else begin
      header_5_generation <= _GEN_207;
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h5 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_5_restartPc <= io_allocate_bits_restartPc; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h5 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_5_architecturalToken <= io_allocate_bits_architecturalToken; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        if (3'h5 == allocateSlot) begin // @[PackageRecoveryState.scala 120:28]
          header_5_memoryToken <= io_allocate_bits_memoryToken; // @[PackageRecoveryState.scala 120:28]
        end
      end
    end
    if (reset) begin // @[PackageRecoveryState.scala 70:25]
      safeSlot <= 3'h0; // @[PackageRecoveryState.scala 70:25]
    end else if (_T_36 & ~io_result_valid & prefixAdvance) begin // @[PackageRecoveryState.scala 174:66]
      if (safeSlot == 3'h5) begin // @[PackageRecoveryState.scala 63:36]
        safeSlot <= 3'h0;
      end else begin
        safeSlot <= _successor_T_2;
      end
    end
    if (reset) begin // @[PackageRecoveryState.scala 71:29]
      allocateSlot <= 3'h0; // @[PackageRecoveryState.scala 71:29]
    end else if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 220:19]
        allocateSlot <= _GEN_251;
      end else if (safeSlot == 3'h5) begin // @[PackageRecoveryState.scala 63:36]
        allocateSlot <= 3'h0;
      end else begin
        allocateSlot <= _successor_T_2;
      end
    end else begin
      allocateSlot <= _GEN_251;
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        captureSlot <= allocateSlot; // @[PackageRecoveryState.scala 125:19]
      end
    end
    if (reset) begin // @[PackageRecoveryState.scala 73:26]
      capturing <= 1'h0; // @[PackageRecoveryState.scala 73:26]
    end else if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      capturing <= _GEN_456;
    end else if (_T_8) begin // @[PackageRecoveryState.scala 149:23]
      capturing <= _GEN_314;
    end else if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      capturing <= _GEN_190;
    end
    if (reset) begin // @[PackageRecoveryState.scala 74:25]
      captured <= 7'h0; // @[PackageRecoveryState.scala 74:25]
    end else if (_T_3) begin // @[PackageRecoveryState.scala 135:23]
      if (~legal_1) begin // @[PackageRecoveryState.scala 143:19]
        captured <= _GEN_253;
      end else begin
        captured <= _captured_T_1; // @[PackageRecoveryState.scala 145:16]
      end
    end else begin
      captured <= _GEN_253;
    end
    if (reset) begin // @[PackageRecoveryState.scala 75:29]
      hasAllocated <= 1'h0; // @[PackageRecoveryState.scala 75:29]
    end else if (_T_1) begin // @[PackageRecoveryState.scala 115:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 119:19]
        hasAllocated <= 1'h1; // @[PackageRecoveryState.scala 131:20]
      end
    end
    if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 220:19]
        lastSequence <= _GEN_255;
      end else begin
        lastSequence <= command_checkpoint_sequence; // @[PackageRecoveryState.scala 224:20]
      end
    end else begin
      lastSequence <= _GEN_255;
    end
    if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 220:19]
        generation <= _GEN_254;
      end else begin
        generation <= command_recoveryGeneration; // @[PackageRecoveryState.scala 223:18]
      end
    end else begin
      generation <= _GEN_254;
    end
    if (reset) begin // @[PackageRecoveryState.scala 78:23]
      failed <= 1'h0; // @[PackageRecoveryState.scala 78:23]
    end else if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      failed <= _GEN_457;
    end else if (_T_12) begin // @[PackageRecoveryState.scala 158:25]
      if (!(_T_21 != 3'h1 | ~io_result_bits_compared)) begin // @[PackageRecoveryState.scala 159:70]
        failed <= _GEN_335;
      end
    end
    if (_T_12) begin // @[PackageRecoveryState.scala 158:25]
      if (!(_T_21 != 3'h1 | ~io_result_bits_compared)) begin // @[PackageRecoveryState.scala 159:70]
        if (_io_freezeRequested_T_2) begin // @[PackageRecoveryState.scala 167:39]
          failureSequence <= io_result_bits_sequence; // @[PackageRecoveryState.scala 169:27]
        end
      end
    end
    if (reset) begin // @[PackageRecoveryState.scala 80:32]
      failureReported <= 1'h0; // @[PackageRecoveryState.scala 80:32]
    end else if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      failureReported <= _GEN_458;
    end else begin
      failureReported <= _GEN_72;
    end
    if (reset) begin // @[PackageRecoveryState.scala 81:22]
      error <= 1'h0; // @[PackageRecoveryState.scala 81:22]
    end else if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      error <= _GEN_440;
    end else if (io_writeCompleted_valid) begin // @[PackageRecoveryState.scala 201:34]
      error <= _GEN_413;
    end else if (_T_50) begin // @[PackageRecoveryState.scala 186:26]
      error <= _GEN_386;
    end else begin
      error <= _GEN_352;
    end
    if (reset) begin // @[PackageRecoveryState.scala 82:23]
      active <= 1'h0; // @[PackageRecoveryState.scala 82:23]
    end else if (io_writeCompleted_valid) begin // @[PackageRecoveryState.scala 201:34]
      if (~legal_3) begin // @[PackageRecoveryState.scala 206:19]
        active <= _GEN_406;
      end else if (index == 7'h5f) begin // @[PackageRecoveryState.scala 208:38]
        active <= 1'h0; // @[PackageRecoveryState.scala 209:16]
      end else begin
        active <= _GEN_406;
      end
    end else begin
      active <= _GEN_406;
    end
    if (reset) begin // @[PackageRecoveryState.scala 83:21]
      sent <= 1'h0; // @[PackageRecoveryState.scala 83:21]
    end else if (io_writeCompleted_valid) begin // @[PackageRecoveryState.scala 201:34]
      sent <= _GEN_414;
    end else begin
      sent <= _GEN_408;
    end
    if (reset) begin // @[PackageRecoveryState.scala 84:22]
      index <= 7'h0; // @[PackageRecoveryState.scala 84:22]
    end else if (io_writeCompleted_valid) begin // @[PackageRecoveryState.scala 201:34]
      if (~legal_3) begin // @[PackageRecoveryState.scala 206:19]
        index <= _GEN_405;
      end else if (index == 7'h5f) begin // @[PackageRecoveryState.scala 208:38]
        index <= _GEN_405;
      end else begin
        index <= _index_T_1; // @[PackageRecoveryState.scala 212:27]
      end
    end else begin
      index <= _GEN_405;
    end
    if (_T_50) begin // @[PackageRecoveryState.scala 186:26]
      if (!(~legal_2)) begin // @[PackageRecoveryState.scala 193:19]
        command_checkpoint_sequence <= io_restore_bits_checkpoint_sequence; // @[PackageRecoveryState.scala 194:15]
      end
    end
    if (_T_50) begin // @[PackageRecoveryState.scala 186:26]
      if (!(~legal_2)) begin // @[PackageRecoveryState.scala 193:19]
        command_checkpoint_generation <= io_restore_bits_checkpoint_generation; // @[PackageRecoveryState.scala 194:15]
      end
    end
    if (_T_50) begin // @[PackageRecoveryState.scala 186:26]
      if (!(~legal_2)) begin // @[PackageRecoveryState.scala 193:19]
        command_checkpoint_restartPc <= io_restore_bits_checkpoint_restartPc; // @[PackageRecoveryState.scala 194:15]
      end
    end
    if (_T_50) begin // @[PackageRecoveryState.scala 186:26]
      if (!(~legal_2)) begin // @[PackageRecoveryState.scala 193:19]
        command_checkpoint_architecturalToken <= io_restore_bits_checkpoint_architecturalToken; // @[PackageRecoveryState.scala 194:15]
      end
    end
    if (_T_50) begin // @[PackageRecoveryState.scala 186:26]
      if (!(~legal_2)) begin // @[PackageRecoveryState.scala 193:19]
        command_checkpoint_memoryToken <= io_restore_bits_checkpoint_memoryToken; // @[PackageRecoveryState.scala 194:15]
      end
    end
    if (_T_50) begin // @[PackageRecoveryState.scala 186:26]
      if (!(~legal_2)) begin // @[PackageRecoveryState.scala 193:19]
        command_failedSequence <= io_restore_bits_failedSequence; // @[PackageRecoveryState.scala 194:15]
      end
    end
    if (_T_50) begin // @[PackageRecoveryState.scala 186:26]
      if (!(~legal_2)) begin // @[PackageRecoveryState.scala 193:19]
        command_recoveryGeneration <= io_restore_bits_recoveryGeneration; // @[PackageRecoveryState.scala 194:15]
      end
    end
    if (reset) begin // @[PackageRecoveryState.scala 86:38]
      restoredPendingRebase <= 1'h0; // @[PackageRecoveryState.scala 86:38]
    end else if (_T_55) begin // @[PackageRecoveryState.scala 216:25]
      restoredPendingRebase <= _GEN_459;
    end else if (io_writeCompleted_valid) begin // @[PackageRecoveryState.scala 201:34]
      if (!(~legal_3)) begin // @[PackageRecoveryState.scala 206:19]
        restoredPendingRebase <= _GEN_410;
      end
    end
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_39 & ~reset & ~(_GEN_41 == _T_41)) begin
          $fwrite(32'h80000002,
            "Assertion failed\n    at PackageRecoveryState.scala:175 assert(header(successor).sequence === header(safeSlot).sequence + 1.U)\n"
            ); // @[PackageRecoveryState.scala 175:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_39 & ~reset & ~(_GEN_41 == _T_41)) begin
          $fatal; // @[PackageRecoveryState.scala 175:11]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_499 & ~(_GEN_372 == _GEN_53)) begin
          $fwrite(32'h80000002,
            "Assertion failed\n    at PackageRecoveryState.scala:176 assert(header(successor).generation === header(safeSlot).generation)\n"
            ); // @[PackageRecoveryState.scala 176:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_499 & ~(_GEN_372 == _GEN_53)) begin
          $fatal; // @[PackageRecoveryState.scala 176:11]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
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
`ifdef RANDOMIZE_GARBAGE_ASSIGN
  _RAND_1 = {2{`RANDOM}};
  _RAND_2 = {2{`RANDOM}};
`endif // RANDOMIZE_GARBAGE_ASSIGN
`ifdef RANDOMIZE_MEM_INIT
  _RAND_0 = {2{`RANDOM}};
  for (initvar = 0; initvar < 576; initvar = initvar+1)
    image[initvar] = _RAND_0[63:0];
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  _RAND_3 = {1{`RANDOM}};
  valid_0 = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  valid_1 = _RAND_4[0:0];
  _RAND_5 = {1{`RANDOM}};
  valid_2 = _RAND_5[0:0];
  _RAND_6 = {1{`RANDOM}};
  valid_3 = _RAND_6[0:0];
  _RAND_7 = {1{`RANDOM}};
  valid_4 = _RAND_7[0:0];
  _RAND_8 = {1{`RANDOM}};
  valid_5 = _RAND_8[0:0];
  _RAND_9 = {1{`RANDOM}};
  sealedImage_0 = _RAND_9[0:0];
  _RAND_10 = {1{`RANDOM}};
  sealedImage_1 = _RAND_10[0:0];
  _RAND_11 = {1{`RANDOM}};
  sealedImage_2 = _RAND_11[0:0];
  _RAND_12 = {1{`RANDOM}};
  sealedImage_3 = _RAND_12[0:0];
  _RAND_13 = {1{`RANDOM}};
  sealedImage_4 = _RAND_13[0:0];
  _RAND_14 = {1{`RANDOM}};
  sealedImage_5 = _RAND_14[0:0];
  _RAND_15 = {1{`RANDOM}};
  resultSeen_0 = _RAND_15[0:0];
  _RAND_16 = {1{`RANDOM}};
  resultSeen_1 = _RAND_16[0:0];
  _RAND_17 = {1{`RANDOM}};
  resultSeen_2 = _RAND_17[0:0];
  _RAND_18 = {1{`RANDOM}};
  resultSeen_3 = _RAND_18[0:0];
  _RAND_19 = {1{`RANDOM}};
  resultSeen_4 = _RAND_19[0:0];
  _RAND_20 = {1{`RANDOM}};
  resultSeen_5 = _RAND_20[0:0];
  _RAND_21 = {1{`RANDOM}};
  passed_0 = _RAND_21[0:0];
  _RAND_22 = {1{`RANDOM}};
  passed_1 = _RAND_22[0:0];
  _RAND_23 = {1{`RANDOM}};
  passed_2 = _RAND_23[0:0];
  _RAND_24 = {1{`RANDOM}};
  passed_3 = _RAND_24[0:0];
  _RAND_25 = {1{`RANDOM}};
  passed_4 = _RAND_25[0:0];
  _RAND_26 = {1{`RANDOM}};
  passed_5 = _RAND_26[0:0];
  _RAND_27 = {1{`RANDOM}};
  header_0_sequence = _RAND_27[31:0];
  _RAND_28 = {1{`RANDOM}};
  header_0_generation = _RAND_28[31:0];
  _RAND_29 = {2{`RANDOM}};
  header_0_restartPc = _RAND_29[63:0];
  _RAND_30 = {2{`RANDOM}};
  header_0_architecturalToken = _RAND_30[63:0];
  _RAND_31 = {2{`RANDOM}};
  header_0_memoryToken = _RAND_31[63:0];
  _RAND_32 = {1{`RANDOM}};
  header_1_sequence = _RAND_32[31:0];
  _RAND_33 = {1{`RANDOM}};
  header_1_generation = _RAND_33[31:0];
  _RAND_34 = {2{`RANDOM}};
  header_1_restartPc = _RAND_34[63:0];
  _RAND_35 = {2{`RANDOM}};
  header_1_architecturalToken = _RAND_35[63:0];
  _RAND_36 = {2{`RANDOM}};
  header_1_memoryToken = _RAND_36[63:0];
  _RAND_37 = {1{`RANDOM}};
  header_2_sequence = _RAND_37[31:0];
  _RAND_38 = {1{`RANDOM}};
  header_2_generation = _RAND_38[31:0];
  _RAND_39 = {2{`RANDOM}};
  header_2_restartPc = _RAND_39[63:0];
  _RAND_40 = {2{`RANDOM}};
  header_2_architecturalToken = _RAND_40[63:0];
  _RAND_41 = {2{`RANDOM}};
  header_2_memoryToken = _RAND_41[63:0];
  _RAND_42 = {1{`RANDOM}};
  header_3_sequence = _RAND_42[31:0];
  _RAND_43 = {1{`RANDOM}};
  header_3_generation = _RAND_43[31:0];
  _RAND_44 = {2{`RANDOM}};
  header_3_restartPc = _RAND_44[63:0];
  _RAND_45 = {2{`RANDOM}};
  header_3_architecturalToken = _RAND_45[63:0];
  _RAND_46 = {2{`RANDOM}};
  header_3_memoryToken = _RAND_46[63:0];
  _RAND_47 = {1{`RANDOM}};
  header_4_sequence = _RAND_47[31:0];
  _RAND_48 = {1{`RANDOM}};
  header_4_generation = _RAND_48[31:0];
  _RAND_49 = {2{`RANDOM}};
  header_4_restartPc = _RAND_49[63:0];
  _RAND_50 = {2{`RANDOM}};
  header_4_architecturalToken = _RAND_50[63:0];
  _RAND_51 = {2{`RANDOM}};
  header_4_memoryToken = _RAND_51[63:0];
  _RAND_52 = {1{`RANDOM}};
  header_5_sequence = _RAND_52[31:0];
  _RAND_53 = {1{`RANDOM}};
  header_5_generation = _RAND_53[31:0];
  _RAND_54 = {2{`RANDOM}};
  header_5_restartPc = _RAND_54[63:0];
  _RAND_55 = {2{`RANDOM}};
  header_5_architecturalToken = _RAND_55[63:0];
  _RAND_56 = {2{`RANDOM}};
  header_5_memoryToken = _RAND_56[63:0];
  _RAND_57 = {1{`RANDOM}};
  safeSlot = _RAND_57[2:0];
  _RAND_58 = {1{`RANDOM}};
  allocateSlot = _RAND_58[2:0];
  _RAND_59 = {1{`RANDOM}};
  captureSlot = _RAND_59[2:0];
  _RAND_60 = {1{`RANDOM}};
  capturing = _RAND_60[0:0];
  _RAND_61 = {1{`RANDOM}};
  captured = _RAND_61[6:0];
  _RAND_62 = {1{`RANDOM}};
  hasAllocated = _RAND_62[0:0];
  _RAND_63 = {1{`RANDOM}};
  lastSequence = _RAND_63[31:0];
  _RAND_64 = {1{`RANDOM}};
  generation = _RAND_64[31:0];
  _RAND_65 = {1{`RANDOM}};
  failed = _RAND_65[0:0];
  _RAND_66 = {1{`RANDOM}};
  failureSequence = _RAND_66[31:0];
  _RAND_67 = {1{`RANDOM}};
  failureReported = _RAND_67[0:0];
  _RAND_68 = {1{`RANDOM}};
  error = _RAND_68[0:0];
  _RAND_69 = {1{`RANDOM}};
  active = _RAND_69[0:0];
  _RAND_70 = {1{`RANDOM}};
  sent = _RAND_70[0:0];
  _RAND_71 = {1{`RANDOM}};
  index = _RAND_71[6:0];
  _RAND_72 = {1{`RANDOM}};
  command_checkpoint_sequence = _RAND_72[31:0];
  _RAND_73 = {1{`RANDOM}};
  command_checkpoint_generation = _RAND_73[31:0];
  _RAND_74 = {2{`RANDOM}};
  command_checkpoint_restartPc = _RAND_74[63:0];
  _RAND_75 = {2{`RANDOM}};
  command_checkpoint_architecturalToken = _RAND_75[63:0];
  _RAND_76 = {2{`RANDOM}};
  command_checkpoint_memoryToken = _RAND_76[63:0];
  _RAND_77 = {1{`RANDOM}};
  command_failedSequence = _RAND_77[31:0];
  _RAND_78 = {1{`RANDOM}};
  command_recoveryGeneration = _RAND_78[31:0];
  _RAND_79 = {1{`RANDOM}};
  restoredPendingRebase = _RAND_79[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
