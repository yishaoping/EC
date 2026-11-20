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
  input  [63:0] io_rebase_bits_retiredPc,
  input         io_rebase_bits_allCheckerTasksDrained,
  output        io_protocolError,
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
  reg [63:0] image [0:575]; // @[PackageRecoveryState.scala 68:18]
  wire  image_io_write_bits_data_MPORT_en; // @[PackageRecoveryState.scala 68:18]
  wire [9:0] image_io_write_bits_data_MPORT_addr; // @[PackageRecoveryState.scala 68:18]
  wire [63:0] image_io_write_bits_data_MPORT_data; // @[PackageRecoveryState.scala 68:18]
  wire  image_legal_MPORT_en; // @[PackageRecoveryState.scala 68:18]
  wire [9:0] image_legal_MPORT_addr; // @[PackageRecoveryState.scala 68:18]
  wire [63:0] image_legal_MPORT_data; // @[PackageRecoveryState.scala 68:18]
  wire [63:0] image_MPORT_data; // @[PackageRecoveryState.scala 68:18]
  wire [9:0] image_MPORT_addr; // @[PackageRecoveryState.scala 68:18]
  wire  image_MPORT_mask; // @[PackageRecoveryState.scala 68:18]
  wire  image_MPORT_en; // @[PackageRecoveryState.scala 68:18]
  reg  valid_0; // @[PackageRecoveryState.scala 63:22]
  reg  valid_1; // @[PackageRecoveryState.scala 63:22]
  reg  valid_2; // @[PackageRecoveryState.scala 63:22]
  reg  valid_3; // @[PackageRecoveryState.scala 63:22]
  reg  valid_4; // @[PackageRecoveryState.scala 63:22]
  reg  valid_5; // @[PackageRecoveryState.scala 63:22]
  reg  sealedImage_0; // @[PackageRecoveryState.scala 64:28]
  reg  sealedImage_1; // @[PackageRecoveryState.scala 64:28]
  reg  sealedImage_2; // @[PackageRecoveryState.scala 64:28]
  reg  sealedImage_3; // @[PackageRecoveryState.scala 64:28]
  reg  sealedImage_4; // @[PackageRecoveryState.scala 64:28]
  reg  sealedImage_5; // @[PackageRecoveryState.scala 64:28]
  reg  resultSeen_0; // @[PackageRecoveryState.scala 65:27]
  reg  resultSeen_1; // @[PackageRecoveryState.scala 65:27]
  reg  resultSeen_2; // @[PackageRecoveryState.scala 65:27]
  reg  resultSeen_3; // @[PackageRecoveryState.scala 65:27]
  reg  resultSeen_4; // @[PackageRecoveryState.scala 65:27]
  reg  resultSeen_5; // @[PackageRecoveryState.scala 65:27]
  reg  passed_0; // @[PackageRecoveryState.scala 66:23]
  reg  passed_1; // @[PackageRecoveryState.scala 66:23]
  reg  passed_2; // @[PackageRecoveryState.scala 66:23]
  reg  passed_3; // @[PackageRecoveryState.scala 66:23]
  reg  passed_4; // @[PackageRecoveryState.scala 66:23]
  reg  passed_5; // @[PackageRecoveryState.scala 66:23]
  reg [31:0] header_0_sequence; // @[PackageRecoveryState.scala 67:19]
  reg [31:0] header_0_generation; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_0_restartPc; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_0_architecturalToken; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_0_memoryToken; // @[PackageRecoveryState.scala 67:19]
  reg [31:0] header_1_sequence; // @[PackageRecoveryState.scala 67:19]
  reg [31:0] header_1_generation; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_1_restartPc; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_1_architecturalToken; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_1_memoryToken; // @[PackageRecoveryState.scala 67:19]
  reg [31:0] header_2_sequence; // @[PackageRecoveryState.scala 67:19]
  reg [31:0] header_2_generation; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_2_restartPc; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_2_architecturalToken; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_2_memoryToken; // @[PackageRecoveryState.scala 67:19]
  reg [31:0] header_3_sequence; // @[PackageRecoveryState.scala 67:19]
  reg [31:0] header_3_generation; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_3_restartPc; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_3_architecturalToken; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_3_memoryToken; // @[PackageRecoveryState.scala 67:19]
  reg [31:0] header_4_sequence; // @[PackageRecoveryState.scala 67:19]
  reg [31:0] header_4_generation; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_4_restartPc; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_4_architecturalToken; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_4_memoryToken; // @[PackageRecoveryState.scala 67:19]
  reg [31:0] header_5_sequence; // @[PackageRecoveryState.scala 67:19]
  reg [31:0] header_5_generation; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_5_restartPc; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_5_architecturalToken; // @[PackageRecoveryState.scala 67:19]
  reg [63:0] header_5_memoryToken; // @[PackageRecoveryState.scala 67:19]
  reg [2:0] safeSlot; // @[PackageRecoveryState.scala 69:25]
  reg [2:0] allocateSlot; // @[PackageRecoveryState.scala 70:29]
  reg [2:0] captureSlot; // @[PackageRecoveryState.scala 71:24]
  reg  capturing; // @[PackageRecoveryState.scala 72:26]
  reg [6:0] captured; // @[PackageRecoveryState.scala 73:25]
  reg  hasAllocated; // @[PackageRecoveryState.scala 74:29]
  reg [31:0] lastSequence; // @[PackageRecoveryState.scala 75:25]
  reg [31:0] generation; // @[PackageRecoveryState.scala 76:23]
  reg  failed; // @[PackageRecoveryState.scala 77:23]
  reg [31:0] failureSequence; // @[PackageRecoveryState.scala 78:28]
  reg  failureReported; // @[PackageRecoveryState.scala 79:32]
  reg  error; // @[PackageRecoveryState.scala 80:22]
  reg  active; // @[PackageRecoveryState.scala 81:23]
  reg  sent; // @[PackageRecoveryState.scala 82:21]
  reg [6:0] index; // @[PackageRecoveryState.scala 83:22]
  reg [31:0] command_checkpoint_sequence; // @[PackageRecoveryState.scala 84:20]
  reg [31:0] command_checkpoint_generation; // @[PackageRecoveryState.scala 84:20]
  reg [63:0] command_checkpoint_restartPc; // @[PackageRecoveryState.scala 84:20]
  reg [63:0] command_checkpoint_architecturalToken; // @[PackageRecoveryState.scala 84:20]
  reg [63:0] command_checkpoint_memoryToken; // @[PackageRecoveryState.scala 84:20]
  reg [31:0] command_failedSequence; // @[PackageRecoveryState.scala 84:20]
  reg [31:0] command_recoveryGeneration; // @[PackageRecoveryState.scala 84:20]
  reg  restoredPendingRebase; // @[PackageRecoveryState.scala 85:38]
  wire  _GEN_1 = 3'h1 == safeSlot ? valid_1 : valid_0; // @[PackageRecoveryState.scala 86:{35,35}]
  wire  _GEN_2 = 3'h2 == safeSlot ? valid_2 : _GEN_1; // @[PackageRecoveryState.scala 86:{35,35}]
  wire  _GEN_3 = 3'h3 == safeSlot ? valid_3 : _GEN_2; // @[PackageRecoveryState.scala 86:{35,35}]
  wire  _GEN_4 = 3'h4 == safeSlot ? valid_4 : _GEN_3; // @[PackageRecoveryState.scala 86:{35,35}]
  wire  _GEN_5 = 3'h5 == safeSlot ? valid_5 : _GEN_4; // @[PackageRecoveryState.scala 86:{35,35}]
  wire  _GEN_7 = 3'h1 == safeSlot ? sealedImage_1 : sealedImage_0; // @[PackageRecoveryState.scala 86:{35,35}]
  wire  _GEN_8 = 3'h2 == safeSlot ? sealedImage_2 : _GEN_7; // @[PackageRecoveryState.scala 86:{35,35}]
  wire  _GEN_9 = 3'h3 == safeSlot ? sealedImage_3 : _GEN_8; // @[PackageRecoveryState.scala 86:{35,35}]
  wire  _GEN_10 = 3'h4 == safeSlot ? sealedImage_4 : _GEN_9; // @[PackageRecoveryState.scala 86:{35,35}]
  wire  _GEN_11 = 3'h5 == safeSlot ? sealedImage_5 : _GEN_10; // @[PackageRecoveryState.scala 86:{35,35}]
  wire  _GEN_13 = 3'h1 == safeSlot ? passed_1 : passed_0; // @[PackageRecoveryState.scala 86:{60,60}]
  wire  _GEN_14 = 3'h2 == safeSlot ? passed_2 : _GEN_13; // @[PackageRecoveryState.scala 86:{60,60}]
  wire  _GEN_15 = 3'h3 == safeSlot ? passed_3 : _GEN_14; // @[PackageRecoveryState.scala 86:{60,60}]
  wire  _GEN_16 = 3'h4 == safeSlot ? passed_4 : _GEN_15; // @[PackageRecoveryState.scala 86:{60,60}]
  wire  _GEN_17 = 3'h5 == safeSlot ? passed_5 : _GEN_16; // @[PackageRecoveryState.scala 86:{60,60}]
  wire  safeValid = _GEN_5 & _GEN_11 & _GEN_17; // @[PackageRecoveryState.scala 86:60]
  wire  locked = io_lock | failed | active | error; // @[PackageRecoveryState.scala 87:44]
  wire  _io_checkpoint_valid_T = ~error; // @[PackageRecoveryState.scala 89:39]
  wire [31:0] _GEN_19 = 3'h1 == safeSlot ? header_1_sequence : header_0_sequence; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [31:0] _GEN_20 = 3'h2 == safeSlot ? header_2_sequence : _GEN_19; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [31:0] _GEN_21 = 3'h3 == safeSlot ? header_3_sequence : _GEN_20; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [31:0] _GEN_22 = 3'h4 == safeSlot ? header_4_sequence : _GEN_21; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [31:0] _GEN_23 = 3'h5 == safeSlot ? header_5_sequence : _GEN_22; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [31:0] _GEN_25 = 3'h1 == safeSlot ? header_1_generation : header_0_generation; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [31:0] _GEN_26 = 3'h2 == safeSlot ? header_2_generation : _GEN_25; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [31:0] _GEN_27 = 3'h3 == safeSlot ? header_3_generation : _GEN_26; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [31:0] _GEN_28 = 3'h4 == safeSlot ? header_4_generation : _GEN_27; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [31:0] _GEN_29 = 3'h5 == safeSlot ? header_5_generation : _GEN_28; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [63:0] _GEN_31 = 3'h1 == safeSlot ? header_1_restartPc : header_0_restartPc; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [63:0] _GEN_32 = 3'h2 == safeSlot ? header_2_restartPc : _GEN_31; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [63:0] _GEN_33 = 3'h3 == safeSlot ? header_3_restartPc : _GEN_32; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [63:0] _GEN_34 = 3'h4 == safeSlot ? header_4_restartPc : _GEN_33; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [63:0] _GEN_35 = 3'h5 == safeSlot ? header_5_restartPc : _GEN_34; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [63:0] _GEN_37 = 3'h1 == safeSlot ? header_1_architecturalToken : header_0_architecturalToken; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [63:0] _GEN_38 = 3'h2 == safeSlot ? header_2_architecturalToken : _GEN_37; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [63:0] _GEN_39 = 3'h3 == safeSlot ? header_3_architecturalToken : _GEN_38; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [63:0] _GEN_40 = 3'h4 == safeSlot ? header_4_architecturalToken : _GEN_39; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [63:0] _GEN_41 = 3'h5 == safeSlot ? header_5_architecturalToken : _GEN_40; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [63:0] _GEN_43 = 3'h1 == safeSlot ? header_1_memoryToken : header_0_memoryToken; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [63:0] _GEN_44 = 3'h2 == safeSlot ? header_2_memoryToken : _GEN_43; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [63:0] _GEN_45 = 3'h3 == safeSlot ? header_3_memoryToken : _GEN_44; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [63:0] _GEN_46 = 3'h4 == safeSlot ? header_4_memoryToken : _GEN_45; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [63:0] _GEN_47 = 3'h5 == safeSlot ? header_5_memoryToken : _GEN_46; // @[PackageRecoveryState.scala 90:{22,22}]
  wire [1:0] _io_occupancy_T = valid_1 + valid_2; // @[Bitwise.scala 51:90]
  wire [1:0] _GEN_480 = {{1'd0}, valid_0}; // @[Bitwise.scala 51:90]
  wire [2:0] _io_occupancy_T_2 = _GEN_480 + _io_occupancy_T; // @[Bitwise.scala 51:90]
  wire [1:0] _io_occupancy_T_4 = valid_4 + valid_5; // @[Bitwise.scala 51:90]
  wire [1:0] _GEN_481 = {{1'd0}, valid_3}; // @[Bitwise.scala 51:90]
  wire [2:0] _io_occupancy_T_6 = _GEN_481 + _io_occupancy_T_4; // @[Bitwise.scala 51:90]
  wire  _T = io_failure_ready & io_failure_valid; // @[Decoupled.scala 51:35]
  wire  _GEN_48 = _T | failureReported; // @[PackageRecoveryState.scala 99:26 79:32 99:44]
  wire  _io_allocate_ready_T = ~locked; // @[PackageRecoveryState.scala 105:24]
  wire  _GEN_50 = 3'h1 == allocateSlot ? valid_1 : valid_0; // @[PackageRecoveryState.scala 105:{49,49}]
  wire  _GEN_51 = 3'h2 == allocateSlot ? valid_2 : _GEN_50; // @[PackageRecoveryState.scala 105:{49,49}]
  wire  _GEN_52 = 3'h3 == allocateSlot ? valid_3 : _GEN_51; // @[PackageRecoveryState.scala 105:{49,49}]
  wire  _GEN_53 = 3'h4 == allocateSlot ? valid_4 : _GEN_52; // @[PackageRecoveryState.scala 105:{49,49}]
  wire  _GEN_54 = 3'h5 == allocateSlot ? valid_5 : _GEN_53; // @[PackageRecoveryState.scala 105:{49,49}]
  wire  _T_1 = io_allocate_ready & io_allocate_valid; // @[Decoupled.scala 51:35]
  wire [31:0] _legal_T_3 = lastSequence + 32'h1; // @[PackageRecoveryState.scala 108:50]
  wire  _legal_T_4 = io_allocate_bits_sequence == _legal_T_3; // @[PackageRecoveryState.scala 108:33]
  wire  _legal_T_5 = lastSequence != 32'hffffffff & _legal_T_4; // @[PackageRecoveryState.scala 107:66]
  wire  _legal_T_6 = io_allocate_bits_generation == generation; // @[PackageRecoveryState.scala 109:35]
  wire  _legal_T_7 = _legal_T_5 & _legal_T_6; // @[PackageRecoveryState.scala 108:56]
  wire  legal = ~hasAllocated | _legal_T_7; // @[PackageRecoveryState.scala 107:31]
  wire [31:0] _GEN_61 = 3'h0 == allocateSlot ? io_allocate_bits_generation : header_0_generation; // @[PackageRecoveryState.scala 111:{28,28} 67:19]
  wire [31:0] _GEN_62 = 3'h1 == allocateSlot ? io_allocate_bits_generation : header_1_generation; // @[PackageRecoveryState.scala 111:{28,28} 67:19]
  wire [31:0] _GEN_63 = 3'h2 == allocateSlot ? io_allocate_bits_generation : header_2_generation; // @[PackageRecoveryState.scala 111:{28,28} 67:19]
  wire [31:0] _GEN_64 = 3'h3 == allocateSlot ? io_allocate_bits_generation : header_3_generation; // @[PackageRecoveryState.scala 111:{28,28} 67:19]
  wire [31:0] _GEN_65 = 3'h4 == allocateSlot ? io_allocate_bits_generation : header_4_generation; // @[PackageRecoveryState.scala 111:{28,28} 67:19]
  wire [31:0] _GEN_66 = 3'h5 == allocateSlot ? io_allocate_bits_generation : header_5_generation; // @[PackageRecoveryState.scala 111:{28,28} 67:19]
  wire  _GEN_85 = 3'h0 == allocateSlot | valid_0; // @[PackageRecoveryState.scala 112:{27,27} 63:22]
  wire  _GEN_86 = 3'h1 == allocateSlot | valid_1; // @[PackageRecoveryState.scala 112:{27,27} 63:22]
  wire  _GEN_87 = 3'h2 == allocateSlot | valid_2; // @[PackageRecoveryState.scala 112:{27,27} 63:22]
  wire  _GEN_88 = 3'h3 == allocateSlot | valid_3; // @[PackageRecoveryState.scala 112:{27,27} 63:22]
  wire  _GEN_89 = 3'h4 == allocateSlot | valid_4; // @[PackageRecoveryState.scala 112:{27,27} 63:22]
  wire  _GEN_90 = 3'h5 == allocateSlot | valid_5; // @[PackageRecoveryState.scala 112:{27,27} 63:22]
  wire  _GEN_91 = 3'h0 == allocateSlot ? 1'h0 : sealedImage_0; // @[PackageRecoveryState.scala 113:{33,33} 64:28]
  wire  _GEN_92 = 3'h1 == allocateSlot ? 1'h0 : sealedImage_1; // @[PackageRecoveryState.scala 113:{33,33} 64:28]
  wire  _GEN_93 = 3'h2 == allocateSlot ? 1'h0 : sealedImage_2; // @[PackageRecoveryState.scala 113:{33,33} 64:28]
  wire  _GEN_94 = 3'h3 == allocateSlot ? 1'h0 : sealedImage_3; // @[PackageRecoveryState.scala 113:{33,33} 64:28]
  wire  _GEN_95 = 3'h4 == allocateSlot ? 1'h0 : sealedImage_4; // @[PackageRecoveryState.scala 113:{33,33} 64:28]
  wire  _GEN_96 = 3'h5 == allocateSlot ? 1'h0 : sealedImage_5; // @[PackageRecoveryState.scala 113:{33,33} 64:28]
  wire  _GEN_97 = 3'h0 == allocateSlot ? 1'h0 : resultSeen_0; // @[PackageRecoveryState.scala 114:{32,32} 65:27]
  wire  _GEN_98 = 3'h1 == allocateSlot ? 1'h0 : resultSeen_1; // @[PackageRecoveryState.scala 114:{32,32} 65:27]
  wire  _GEN_99 = 3'h2 == allocateSlot ? 1'h0 : resultSeen_2; // @[PackageRecoveryState.scala 114:{32,32} 65:27]
  wire  _GEN_100 = 3'h3 == allocateSlot ? 1'h0 : resultSeen_3; // @[PackageRecoveryState.scala 114:{32,32} 65:27]
  wire  _GEN_101 = 3'h4 == allocateSlot ? 1'h0 : resultSeen_4; // @[PackageRecoveryState.scala 114:{32,32} 65:27]
  wire  _GEN_102 = 3'h5 == allocateSlot ? 1'h0 : resultSeen_5; // @[PackageRecoveryState.scala 114:{32,32} 65:27]
  wire  _GEN_103 = 3'h0 == allocateSlot ? 1'h0 : passed_0; // @[PackageRecoveryState.scala 115:{28,28} 66:23]
  wire  _GEN_104 = 3'h1 == allocateSlot ? 1'h0 : passed_1; // @[PackageRecoveryState.scala 115:{28,28} 66:23]
  wire  _GEN_105 = 3'h2 == allocateSlot ? 1'h0 : passed_2; // @[PackageRecoveryState.scala 115:{28,28} 66:23]
  wire  _GEN_106 = 3'h3 == allocateSlot ? 1'h0 : passed_3; // @[PackageRecoveryState.scala 115:{28,28} 66:23]
  wire  _GEN_107 = 3'h4 == allocateSlot ? 1'h0 : passed_4; // @[PackageRecoveryState.scala 115:{28,28} 66:23]
  wire  _GEN_108 = 3'h5 == allocateSlot ? 1'h0 : passed_5; // @[PackageRecoveryState.scala 115:{28,28} 66:23]
  wire [2:0] _allocateSlot_T_2 = allocateSlot + 3'h1; // @[PackageRecoveryState.scala 62:65]
  wire [2:0] _allocateSlot_T_3 = allocateSlot == 3'h5 ? 3'h0 : _allocateSlot_T_2; // @[PackageRecoveryState.scala 62:36]
  wire  _GEN_109 = ~legal | error; // @[PackageRecoveryState.scala 110:{19,27} 80:22]
  wire [31:0] _GEN_116 = ~legal ? header_0_generation : _GEN_61; // @[PackageRecoveryState.scala 110:19 67:19]
  wire [31:0] _GEN_117 = ~legal ? header_1_generation : _GEN_62; // @[PackageRecoveryState.scala 110:19 67:19]
  wire [31:0] _GEN_118 = ~legal ? header_2_generation : _GEN_63; // @[PackageRecoveryState.scala 110:19 67:19]
  wire [31:0] _GEN_119 = ~legal ? header_3_generation : _GEN_64; // @[PackageRecoveryState.scala 110:19 67:19]
  wire [31:0] _GEN_120 = ~legal ? header_4_generation : _GEN_65; // @[PackageRecoveryState.scala 110:19 67:19]
  wire [31:0] _GEN_121 = ~legal ? header_5_generation : _GEN_66; // @[PackageRecoveryState.scala 110:19 67:19]
  wire  _GEN_140 = ~legal ? valid_0 : _GEN_85; // @[PackageRecoveryState.scala 110:19 63:22]
  wire  _GEN_141 = ~legal ? valid_1 : _GEN_86; // @[PackageRecoveryState.scala 110:19 63:22]
  wire  _GEN_142 = ~legal ? valid_2 : _GEN_87; // @[PackageRecoveryState.scala 110:19 63:22]
  wire  _GEN_143 = ~legal ? valid_3 : _GEN_88; // @[PackageRecoveryState.scala 110:19 63:22]
  wire  _GEN_144 = ~legal ? valid_4 : _GEN_89; // @[PackageRecoveryState.scala 110:19 63:22]
  wire  _GEN_145 = ~legal ? valid_5 : _GEN_90; // @[PackageRecoveryState.scala 110:19 63:22]
  wire  _GEN_146 = ~legal ? sealedImage_0 : _GEN_91; // @[PackageRecoveryState.scala 110:19 64:28]
  wire  _GEN_147 = ~legal ? sealedImage_1 : _GEN_92; // @[PackageRecoveryState.scala 110:19 64:28]
  wire  _GEN_148 = ~legal ? sealedImage_2 : _GEN_93; // @[PackageRecoveryState.scala 110:19 64:28]
  wire  _GEN_149 = ~legal ? sealedImage_3 : _GEN_94; // @[PackageRecoveryState.scala 110:19 64:28]
  wire  _GEN_150 = ~legal ? sealedImage_4 : _GEN_95; // @[PackageRecoveryState.scala 110:19 64:28]
  wire  _GEN_151 = ~legal ? sealedImage_5 : _GEN_96; // @[PackageRecoveryState.scala 110:19 64:28]
  wire  _GEN_152 = ~legal ? resultSeen_0 : _GEN_97; // @[PackageRecoveryState.scala 110:19 65:27]
  wire  _GEN_153 = ~legal ? resultSeen_1 : _GEN_98; // @[PackageRecoveryState.scala 110:19 65:27]
  wire  _GEN_154 = ~legal ? resultSeen_2 : _GEN_99; // @[PackageRecoveryState.scala 110:19 65:27]
  wire  _GEN_155 = ~legal ? resultSeen_3 : _GEN_100; // @[PackageRecoveryState.scala 110:19 65:27]
  wire  _GEN_156 = ~legal ? resultSeen_4 : _GEN_101; // @[PackageRecoveryState.scala 110:19 65:27]
  wire  _GEN_157 = ~legal ? resultSeen_5 : _GEN_102; // @[PackageRecoveryState.scala 110:19 65:27]
  wire  _GEN_158 = ~legal ? passed_0 : _GEN_103; // @[PackageRecoveryState.scala 110:19 66:23]
  wire  _GEN_159 = ~legal ? passed_1 : _GEN_104; // @[PackageRecoveryState.scala 110:19 66:23]
  wire  _GEN_160 = ~legal ? passed_2 : _GEN_105; // @[PackageRecoveryState.scala 110:19 66:23]
  wire  _GEN_161 = ~legal ? passed_3 : _GEN_106; // @[PackageRecoveryState.scala 110:19 66:23]
  wire  _GEN_162 = ~legal ? passed_4 : _GEN_107; // @[PackageRecoveryState.scala 110:19 66:23]
  wire  _GEN_163 = ~legal ? passed_5 : _GEN_108; // @[PackageRecoveryState.scala 110:19 66:23]
  wire [2:0] _GEN_165 = ~legal ? allocateSlot : _allocateSlot_T_3; // @[PackageRecoveryState.scala 110:19 117:20 70:29]
  wire  _GEN_166 = ~legal ? capturing : 1'h1; // @[PackageRecoveryState.scala 110:19 118:17 72:26]
  wire [6:0] _GEN_167 = ~legal ? captured : 7'h0; // @[PackageRecoveryState.scala 110:19 119:16 73:25]
  wire [31:0] _GEN_168 = ~legal ? generation : io_allocate_bits_generation; // @[PackageRecoveryState.scala 110:19 120:18 76:23]
  wire [31:0] _GEN_169 = ~legal ? lastSequence : io_allocate_bits_sequence; // @[PackageRecoveryState.scala 110:19 121:20 75:25]
  wire  _GEN_171 = _T_1 ? _GEN_109 : error; // @[PackageRecoveryState.scala 106:27 80:22]
  wire [31:0] _GEN_178 = _T_1 ? _GEN_116 : header_0_generation; // @[PackageRecoveryState.scala 106:27 67:19]
  wire [31:0] _GEN_179 = _T_1 ? _GEN_117 : header_1_generation; // @[PackageRecoveryState.scala 106:27 67:19]
  wire [31:0] _GEN_180 = _T_1 ? _GEN_118 : header_2_generation; // @[PackageRecoveryState.scala 106:27 67:19]
  wire [31:0] _GEN_181 = _T_1 ? _GEN_119 : header_3_generation; // @[PackageRecoveryState.scala 106:27 67:19]
  wire [31:0] _GEN_182 = _T_1 ? _GEN_120 : header_4_generation; // @[PackageRecoveryState.scala 106:27 67:19]
  wire [31:0] _GEN_183 = _T_1 ? _GEN_121 : header_5_generation; // @[PackageRecoveryState.scala 106:27 67:19]
  wire  _GEN_202 = _T_1 ? _GEN_140 : valid_0; // @[PackageRecoveryState.scala 106:27 63:22]
  wire  _GEN_203 = _T_1 ? _GEN_141 : valid_1; // @[PackageRecoveryState.scala 106:27 63:22]
  wire  _GEN_204 = _T_1 ? _GEN_142 : valid_2; // @[PackageRecoveryState.scala 106:27 63:22]
  wire  _GEN_205 = _T_1 ? _GEN_143 : valid_3; // @[PackageRecoveryState.scala 106:27 63:22]
  wire  _GEN_206 = _T_1 ? _GEN_144 : valid_4; // @[PackageRecoveryState.scala 106:27 63:22]
  wire  _GEN_207 = _T_1 ? _GEN_145 : valid_5; // @[PackageRecoveryState.scala 106:27 63:22]
  wire  _GEN_208 = _T_1 ? _GEN_146 : sealedImage_0; // @[PackageRecoveryState.scala 106:27 64:28]
  wire  _GEN_209 = _T_1 ? _GEN_147 : sealedImage_1; // @[PackageRecoveryState.scala 106:27 64:28]
  wire  _GEN_210 = _T_1 ? _GEN_148 : sealedImage_2; // @[PackageRecoveryState.scala 106:27 64:28]
  wire  _GEN_211 = _T_1 ? _GEN_149 : sealedImage_3; // @[PackageRecoveryState.scala 106:27 64:28]
  wire  _GEN_212 = _T_1 ? _GEN_150 : sealedImage_4; // @[PackageRecoveryState.scala 106:27 64:28]
  wire  _GEN_213 = _T_1 ? _GEN_151 : sealedImage_5; // @[PackageRecoveryState.scala 106:27 64:28]
  wire  _GEN_214 = _T_1 ? _GEN_152 : resultSeen_0; // @[PackageRecoveryState.scala 106:27 65:27]
  wire  _GEN_215 = _T_1 ? _GEN_153 : resultSeen_1; // @[PackageRecoveryState.scala 106:27 65:27]
  wire  _GEN_216 = _T_1 ? _GEN_154 : resultSeen_2; // @[PackageRecoveryState.scala 106:27 65:27]
  wire  _GEN_217 = _T_1 ? _GEN_155 : resultSeen_3; // @[PackageRecoveryState.scala 106:27 65:27]
  wire  _GEN_218 = _T_1 ? _GEN_156 : resultSeen_4; // @[PackageRecoveryState.scala 106:27 65:27]
  wire  _GEN_219 = _T_1 ? _GEN_157 : resultSeen_5; // @[PackageRecoveryState.scala 106:27 65:27]
  wire  _GEN_220 = _T_1 ? _GEN_158 : passed_0; // @[PackageRecoveryState.scala 106:27 66:23]
  wire  _GEN_221 = _T_1 ? _GEN_159 : passed_1; // @[PackageRecoveryState.scala 106:27 66:23]
  wire  _GEN_222 = _T_1 ? _GEN_160 : passed_2; // @[PackageRecoveryState.scala 106:27 66:23]
  wire  _GEN_223 = _T_1 ? _GEN_161 : passed_3; // @[PackageRecoveryState.scala 106:27 66:23]
  wire  _GEN_224 = _T_1 ? _GEN_162 : passed_4; // @[PackageRecoveryState.scala 106:27 66:23]
  wire  _GEN_225 = _T_1 ? _GEN_163 : passed_5; // @[PackageRecoveryState.scala 106:27 66:23]
  wire [2:0] _GEN_227 = _T_1 ? _GEN_165 : allocateSlot; // @[PackageRecoveryState.scala 106:27 70:29]
  wire  _GEN_228 = _T_1 ? _GEN_166 : capturing; // @[PackageRecoveryState.scala 106:27 72:26]
  wire [6:0] _GEN_229 = _T_1 ? _GEN_167 : captured; // @[PackageRecoveryState.scala 106:27 73:25]
  wire [31:0] _GEN_230 = _T_1 ? _GEN_168 : generation; // @[PackageRecoveryState.scala 106:27 76:23]
  wire [31:0] _GEN_231 = _T_1 ? _GEN_169 : lastSequence; // @[PackageRecoveryState.scala 106:27 75:25]
  wire  _io_word_ready_T_1 = capturing & _io_allocate_ready_T; // @[PackageRecoveryState.scala 125:30]
  wire  _T_3 = io_word_ready & io_word_valid; // @[Decoupled.scala 51:35]
  wire [31:0] _GEN_234 = 3'h1 == captureSlot ? header_1_sequence : header_0_sequence; // @[PackageRecoveryState.scala 128:{39,39}]
  wire [31:0] _GEN_235 = 3'h2 == captureSlot ? header_2_sequence : _GEN_234; // @[PackageRecoveryState.scala 128:{39,39}]
  wire [31:0] _GEN_236 = 3'h3 == captureSlot ? header_3_sequence : _GEN_235; // @[PackageRecoveryState.scala 128:{39,39}]
  wire [31:0] _GEN_237 = 3'h4 == captureSlot ? header_4_sequence : _GEN_236; // @[PackageRecoveryState.scala 128:{39,39}]
  wire [31:0] _GEN_238 = 3'h5 == captureSlot ? header_5_sequence : _GEN_237; // @[PackageRecoveryState.scala 128:{39,39}]
  wire [31:0] _GEN_240 = 3'h1 == captureSlot ? header_1_generation : header_0_generation; // @[PackageRecoveryState.scala 129:{31,31}]
  wire [31:0] _GEN_241 = 3'h2 == captureSlot ? header_2_generation : _GEN_240; // @[PackageRecoveryState.scala 129:{31,31}]
  wire [31:0] _GEN_242 = 3'h3 == captureSlot ? header_3_generation : _GEN_241; // @[PackageRecoveryState.scala 129:{31,31}]
  wire [31:0] _GEN_243 = 3'h4 == captureSlot ? header_4_generation : _GEN_242; // @[PackageRecoveryState.scala 129:{31,31}]
  wire [31:0] _GEN_244 = 3'h5 == captureSlot ? header_5_generation : _GEN_243; // @[PackageRecoveryState.scala 129:{31,31}]
  wire  _legal_T_9 = io_word_bits_generation == _GEN_244; // @[PackageRecoveryState.scala 129:31]
  wire  _legal_T_10 = io_word_bits_sequence == _GEN_238 & _legal_T_9; // @[PackageRecoveryState.scala 128:54]
  wire  _legal_T_14 = io_word_bits_data == 64'h0; // @[PackageRecoveryState.scala 130:46]
  wire  _legal_T_15 = captured != 7'h0 | io_word_bits_data == 64'h0; // @[PackageRecoveryState.scala 130:25]
  wire  _legal_T_16 = _legal_T_10 & io_word_bits_index == captured & _legal_T_15; // @[PackageRecoveryState.scala 129:83]
  wire [63:0] _GEN_246 = 3'h1 == captureSlot ? header_1_restartPc : header_0_restartPc; // @[PackageRecoveryState.scala 131:{47,47}]
  wire [63:0] _GEN_247 = 3'h2 == captureSlot ? header_2_restartPc : _GEN_246; // @[PackageRecoveryState.scala 131:{47,47}]
  wire [63:0] _GEN_248 = 3'h3 == captureSlot ? header_3_restartPc : _GEN_247; // @[PackageRecoveryState.scala 131:{47,47}]
  wire [63:0] _GEN_249 = 3'h4 == captureSlot ? header_4_restartPc : _GEN_248; // @[PackageRecoveryState.scala 131:{47,47}]
  wire [63:0] _GEN_250 = 3'h5 == captureSlot ? header_5_restartPc : _GEN_249; // @[PackageRecoveryState.scala 131:{47,47}]
  wire  _legal_T_19 = captured != 7'h40 | io_word_bits_data == _GEN_250; // @[PackageRecoveryState.scala 131:26]
  wire  _legal_T_20 = _legal_T_16 & _legal_T_19; // @[PackageRecoveryState.scala 130:55]
  wire  _legal_T_24 = io_word_bits_data == 64'h1; // @[PackageRecoveryState.scala 133:27]
  wire  _legal_T_25 = captured != 7'h41 | _legal_T_14 | _legal_T_24; // @[PackageRecoveryState.scala 132:55]
  wire  _legal_T_27 = _legal_T_25 | io_word_bits_data == 64'h3; // @[PackageRecoveryState.scala 133:35]
  wire  legal_1 = _legal_T_20 & _legal_T_27; // @[PackageRecoveryState.scala 131:64]
  wire [9:0] _T_5 = captureSlot * 7'h60; // @[PackageRecoveryState.scala 135:25]
  wire [9:0] _GEN_488 = {{3'd0}, captured}; // @[PackageRecoveryState.scala 135:35]
  wire [6:0] _captured_T_1 = captured + 7'h1; // @[PackageRecoveryState.scala 136:28]
  wire  _GEN_251 = ~legal_1 | _GEN_171; // @[PackageRecoveryState.scala 134:{19,27}]
  wire  _GEN_254 = ~legal_1 ? 1'h0 : 1'h1; // @[PackageRecoveryState.scala 134:19 135:12 68:18]
  wire  _GEN_258 = _T_3 ? _GEN_251 : _GEN_171; // @[PackageRecoveryState.scala 126:23]
  wire  _T_8 = io_seal_ready & io_seal_valid; // @[Decoupled.scala 51:35]
  wire [255:0] _T_9 = {io_seal_bits_sequence,io_seal_bits_generation,io_seal_bits_restartPc,
    io_seal_bits_architecturalToken,io_seal_bits_memoryToken}; // @[PackageRecoveryState.scala 141:24]
  wire [63:0] _GEN_266 = 3'h1 == captureSlot ? header_1_architecturalToken : header_0_architecturalToken; // @[PackageRecoveryState.scala 141:{55,55}]
  wire [63:0] _GEN_267 = 3'h2 == captureSlot ? header_2_architecturalToken : _GEN_266; // @[PackageRecoveryState.scala 141:{55,55}]
  wire [63:0] _GEN_268 = 3'h3 == captureSlot ? header_3_architecturalToken : _GEN_267; // @[PackageRecoveryState.scala 141:{55,55}]
  wire [63:0] _GEN_269 = 3'h4 == captureSlot ? header_4_architecturalToken : _GEN_268; // @[PackageRecoveryState.scala 141:{55,55}]
  wire [63:0] _GEN_270 = 3'h5 == captureSlot ? header_5_architecturalToken : _GEN_269; // @[PackageRecoveryState.scala 141:{55,55}]
  wire [63:0] _GEN_272 = 3'h1 == captureSlot ? header_1_memoryToken : header_0_memoryToken; // @[PackageRecoveryState.scala 141:{55,55}]
  wire [63:0] _GEN_273 = 3'h2 == captureSlot ? header_2_memoryToken : _GEN_272; // @[PackageRecoveryState.scala 141:{55,55}]
  wire [63:0] _GEN_274 = 3'h3 == captureSlot ? header_3_memoryToken : _GEN_273; // @[PackageRecoveryState.scala 141:{55,55}]
  wire [63:0] _GEN_275 = 3'h4 == captureSlot ? header_4_memoryToken : _GEN_274; // @[PackageRecoveryState.scala 141:{55,55}]
  wire [63:0] _GEN_276 = 3'h5 == captureSlot ? header_5_memoryToken : _GEN_275; // @[PackageRecoveryState.scala 141:{55,55}]
  wire [255:0] _T_10 = {_GEN_238,_GEN_244,_GEN_250,_GEN_270,_GEN_276}; // @[PackageRecoveryState.scala 141:55]
  wire  _GEN_277 = 3'h0 == captureSlot | _GEN_208; // @[PackageRecoveryState.scala 142:{45,45}]
  wire  _GEN_278 = 3'h1 == captureSlot | _GEN_209; // @[PackageRecoveryState.scala 142:{45,45}]
  wire  _GEN_279 = 3'h2 == captureSlot | _GEN_210; // @[PackageRecoveryState.scala 142:{45,45}]
  wire  _GEN_280 = 3'h3 == captureSlot | _GEN_211; // @[PackageRecoveryState.scala 142:{45,45}]
  wire  _GEN_281 = 3'h4 == captureSlot | _GEN_212; // @[PackageRecoveryState.scala 142:{45,45}]
  wire  _GEN_282 = 3'h5 == captureSlot | _GEN_213; // @[PackageRecoveryState.scala 142:{45,45}]
  wire  _GEN_283 = _T_9 != _T_10 | _GEN_258; // @[PackageRecoveryState.scala 141:{63,71}]
  wire  _GEN_290 = _T_9 != _T_10 & _GEN_228; // @[PackageRecoveryState.scala 141:63 142:66]
  wire  _GEN_291 = _T_8 ? _GEN_283 : _GEN_258; // @[PackageRecoveryState.scala 140:23]
  wire  _GEN_298 = _T_8 ? _GEN_290 : _GEN_228; // @[PackageRecoveryState.scala 140:23]
  wire  _io_result_ready_T_3 = ~active; // @[PackageRecoveryState.scala 145:43]
  wire  _resultMatch_T = header_0_sequence == io_result_bits_sequence; // @[PackageRecoveryState.scala 147:24]
  wire  _resultMatch_T_1 = valid_0 & _resultMatch_T; // @[PackageRecoveryState.scala 146:63]
  wire  _resultMatch_T_2 = header_0_generation == io_result_bits_generation; // @[PackageRecoveryState.scala 148:26]
  wire  _resultMatch_T_3 = _resultMatch_T_1 & _resultMatch_T_2; // @[PackageRecoveryState.scala 147:52]
  wire  resultMatch_0 = _resultMatch_T_3 & ~resultSeen_0; // @[PackageRecoveryState.scala 148:56]
  wire  _resultMatch_T_6 = header_1_sequence == io_result_bits_sequence; // @[PackageRecoveryState.scala 147:24]
  wire  _resultMatch_T_7 = valid_1 & _resultMatch_T_6; // @[PackageRecoveryState.scala 146:63]
  wire  _resultMatch_T_8 = header_1_generation == io_result_bits_generation; // @[PackageRecoveryState.scala 148:26]
  wire  _resultMatch_T_9 = _resultMatch_T_7 & _resultMatch_T_8; // @[PackageRecoveryState.scala 147:52]
  wire  resultMatch_1 = _resultMatch_T_9 & ~resultSeen_1; // @[PackageRecoveryState.scala 148:56]
  wire  _resultMatch_T_12 = header_2_sequence == io_result_bits_sequence; // @[PackageRecoveryState.scala 147:24]
  wire  _resultMatch_T_13 = valid_2 & _resultMatch_T_12; // @[PackageRecoveryState.scala 146:63]
  wire  _resultMatch_T_14 = header_2_generation == io_result_bits_generation; // @[PackageRecoveryState.scala 148:26]
  wire  _resultMatch_T_15 = _resultMatch_T_13 & _resultMatch_T_14; // @[PackageRecoveryState.scala 147:52]
  wire  resultMatch_2 = _resultMatch_T_15 & ~resultSeen_2; // @[PackageRecoveryState.scala 148:56]
  wire  _resultMatch_T_18 = header_3_sequence == io_result_bits_sequence; // @[PackageRecoveryState.scala 147:24]
  wire  _resultMatch_T_19 = valid_3 & _resultMatch_T_18; // @[PackageRecoveryState.scala 146:63]
  wire  _resultMatch_T_20 = header_3_generation == io_result_bits_generation; // @[PackageRecoveryState.scala 148:26]
  wire  _resultMatch_T_21 = _resultMatch_T_19 & _resultMatch_T_20; // @[PackageRecoveryState.scala 147:52]
  wire  resultMatch_3 = _resultMatch_T_21 & ~resultSeen_3; // @[PackageRecoveryState.scala 148:56]
  wire  _resultMatch_T_24 = header_4_sequence == io_result_bits_sequence; // @[PackageRecoveryState.scala 147:24]
  wire  _resultMatch_T_25 = valid_4 & _resultMatch_T_24; // @[PackageRecoveryState.scala 146:63]
  wire  _resultMatch_T_26 = header_4_generation == io_result_bits_generation; // @[PackageRecoveryState.scala 148:26]
  wire  _resultMatch_T_27 = _resultMatch_T_25 & _resultMatch_T_26; // @[PackageRecoveryState.scala 147:52]
  wire  resultMatch_4 = _resultMatch_T_27 & ~resultSeen_4; // @[PackageRecoveryState.scala 148:56]
  wire  _resultMatch_T_30 = header_5_sequence == io_result_bits_sequence; // @[PackageRecoveryState.scala 147:24]
  wire  _resultMatch_T_31 = valid_5 & _resultMatch_T_30; // @[PackageRecoveryState.scala 146:63]
  wire  _resultMatch_T_32 = header_5_generation == io_result_bits_generation; // @[PackageRecoveryState.scala 148:26]
  wire  _resultMatch_T_33 = _resultMatch_T_31 & _resultMatch_T_32; // @[PackageRecoveryState.scala 147:52]
  wire  resultMatch_5 = _resultMatch_T_33 & ~resultSeen_5; // @[PackageRecoveryState.scala 148:56]
  wire  _T_12 = io_result_ready & io_result_valid; // @[Decoupled.scala 51:35]
  wire [1:0] _T_13 = resultMatch_1 + resultMatch_2; // @[Bitwise.scala 51:90]
  wire [1:0] _GEN_495 = {{1'd0}, resultMatch_0}; // @[Bitwise.scala 51:90]
  wire [2:0] _T_15 = _GEN_495 + _T_13; // @[Bitwise.scala 51:90]
  wire [1:0] _T_17 = resultMatch_4 + resultMatch_5; // @[Bitwise.scala 51:90]
  wire [1:0] _GEN_496 = {{1'd0}, resultMatch_3}; // @[Bitwise.scala 51:90]
  wire [2:0] _T_19 = _GEN_496 + _T_17; // @[Bitwise.scala 51:90]
  wire [2:0] _T_21 = _T_15[1:0] + _T_19[1:0]; // @[Bitwise.scala 51:90]
  wire  _GEN_299 = resultMatch_0 | _GEN_214; // @[PackageRecoveryState.scala 153:33 154:27]
  wire  _GEN_301 = resultMatch_1 | _GEN_215; // @[PackageRecoveryState.scala 153:33 154:27]
  wire  _GEN_303 = resultMatch_2 | _GEN_216; // @[PackageRecoveryState.scala 153:33 154:27]
  wire  _GEN_305 = resultMatch_3 | _GEN_217; // @[PackageRecoveryState.scala 153:33 154:27]
  wire  _GEN_307 = resultMatch_4 | _GEN_218; // @[PackageRecoveryState.scala 153:33 154:27]
  wire  _GEN_309 = resultMatch_5 | _GEN_219; // @[PackageRecoveryState.scala 153:33 154:27]
  wire  _GEN_311 = ~io_result_bits_passed | failed; // @[PackageRecoveryState.scala 158:39 159:18 77:23]
  wire  _GEN_313 = _T_21 != 3'h1 | ~io_result_bits_compared | _GEN_291; // @[PackageRecoveryState.scala 150:{70,78}]
  wire  _GEN_326 = _T_21 != 3'h1 | ~io_result_bits_compared ? failed : _GEN_311; // @[PackageRecoveryState.scala 150:70 77:23]
  wire  _GEN_328 = _T_12 ? _GEN_313 : _GEN_291; // @[PackageRecoveryState.scala 149:25]
  wire  _GEN_341 = _T_12 ? _GEN_326 : failed; // @[PackageRecoveryState.scala 149:25 77:23]
  wire [2:0] _successor_T_2 = safeSlot + 3'h1; // @[PackageRecoveryState.scala 62:65]
  wire [2:0] successor = safeSlot == 3'h5 ? 3'h0 : _successor_T_2; // @[PackageRecoveryState.scala 62:36]
  wire  _GEN_344 = 3'h1 == successor ? valid_1 : valid_0; // @[PackageRecoveryState.scala 165:{50,50}]
  wire  _GEN_345 = 3'h2 == successor ? valid_2 : _GEN_344; // @[PackageRecoveryState.scala 165:{50,50}]
  wire  _GEN_346 = 3'h3 == successor ? valid_3 : _GEN_345; // @[PackageRecoveryState.scala 165:{50,50}]
  wire  _GEN_347 = 3'h4 == successor ? valid_4 : _GEN_346; // @[PackageRecoveryState.scala 165:{50,50}]
  wire  _GEN_348 = 3'h5 == successor ? valid_5 : _GEN_347; // @[PackageRecoveryState.scala 165:{50,50}]
  wire  _T_31 = _io_allocate_ready_T & ~io_result_valid & safeValid & _GEN_348; // @[PackageRecoveryState.scala 165:50]
  wire  _GEN_350 = 3'h1 == successor ? sealedImage_1 : sealedImage_0; // @[PackageRecoveryState.scala 166:{24,24}]
  wire  _GEN_351 = 3'h2 == successor ? sealedImage_2 : _GEN_350; // @[PackageRecoveryState.scala 166:{24,24}]
  wire  _GEN_352 = 3'h3 == successor ? sealedImage_3 : _GEN_351; // @[PackageRecoveryState.scala 166:{24,24}]
  wire  _GEN_353 = 3'h4 == successor ? sealedImage_4 : _GEN_352; // @[PackageRecoveryState.scala 166:{24,24}]
  wire  _GEN_354 = 3'h5 == successor ? sealedImage_5 : _GEN_353; // @[PackageRecoveryState.scala 166:{24,24}]
  wire  _GEN_356 = 3'h1 == successor ? passed_1 : passed_0; // @[PackageRecoveryState.scala 166:{50,50}]
  wire  _GEN_357 = 3'h2 == successor ? passed_2 : _GEN_356; // @[PackageRecoveryState.scala 166:{50,50}]
  wire  _GEN_358 = 3'h3 == successor ? passed_3 : _GEN_357; // @[PackageRecoveryState.scala 166:{50,50}]
  wire  _GEN_359 = 3'h4 == successor ? passed_4 : _GEN_358; // @[PackageRecoveryState.scala 166:{50,50}]
  wire  _GEN_360 = 3'h5 == successor ? passed_5 : _GEN_359; // @[PackageRecoveryState.scala 166:{50,50}]
  wire  _T_33 = _T_31 & _GEN_354 & _GEN_360; // @[PackageRecoveryState.scala 166:50]
  wire [31:0] _T_35 = _GEN_23 + 32'h1; // @[PackageRecoveryState.scala 167:69]
  wire [31:0] _GEN_362 = 3'h1 == successor ? header_1_sequence : header_0_sequence; // @[PackageRecoveryState.scala 167:{39,39}]
  wire [31:0] _GEN_363 = 3'h2 == successor ? header_2_sequence : _GEN_362; // @[PackageRecoveryState.scala 167:{39,39}]
  wire [31:0] _GEN_364 = 3'h3 == successor ? header_3_sequence : _GEN_363; // @[PackageRecoveryState.scala 167:{39,39}]
  wire [31:0] _GEN_365 = 3'h4 == successor ? header_4_sequence : _GEN_364; // @[PackageRecoveryState.scala 167:{39,39}]
  wire [31:0] _GEN_366 = 3'h5 == successor ? header_5_sequence : _GEN_365; // @[PackageRecoveryState.scala 167:{39,39}]
  wire [31:0] _GEN_368 = 3'h1 == successor ? header_1_generation : header_0_generation; // @[PackageRecoveryState.scala 168:{41,41}]
  wire [31:0] _GEN_369 = 3'h2 == successor ? header_2_generation : _GEN_368; // @[PackageRecoveryState.scala 168:{41,41}]
  wire [31:0] _GEN_370 = 3'h3 == successor ? header_3_generation : _GEN_369; // @[PackageRecoveryState.scala 168:{41,41}]
  wire [31:0] _GEN_371 = 3'h4 == successor ? header_4_generation : _GEN_370; // @[PackageRecoveryState.scala 168:{41,41}]
  wire [31:0] _GEN_372 = 3'h5 == successor ? header_5_generation : _GEN_371; // @[PackageRecoveryState.scala 168:{41,41}]
  wire  _GEN_373 = 3'h0 == safeSlot ? 1'h0 : _GEN_202; // @[PackageRecoveryState.scala 169:{21,21}]
  wire  _GEN_374 = 3'h1 == safeSlot ? 1'h0 : _GEN_203; // @[PackageRecoveryState.scala 169:{21,21}]
  wire  _GEN_375 = 3'h2 == safeSlot ? 1'h0 : _GEN_204; // @[PackageRecoveryState.scala 169:{21,21}]
  wire  _GEN_376 = 3'h3 == safeSlot ? 1'h0 : _GEN_205; // @[PackageRecoveryState.scala 169:{21,21}]
  wire  _GEN_377 = 3'h4 == safeSlot ? 1'h0 : _GEN_206; // @[PackageRecoveryState.scala 169:{21,21}]
  wire  _GEN_378 = 3'h5 == safeSlot ? 1'h0 : _GEN_207; // @[PackageRecoveryState.scala 169:{21,21}]
  wire  _GEN_379 = _T_31 & _GEN_354 & _GEN_360 ? _GEN_373 : _GEN_202; // @[PackageRecoveryState.scala 166:72]
  wire  _GEN_380 = _T_31 & _GEN_354 & _GEN_360 ? _GEN_374 : _GEN_203; // @[PackageRecoveryState.scala 166:72]
  wire  _GEN_381 = _T_31 & _GEN_354 & _GEN_360 ? _GEN_375 : _GEN_204; // @[PackageRecoveryState.scala 166:72]
  wire  _GEN_382 = _T_31 & _GEN_354 & _GEN_360 ? _GEN_376 : _GEN_205; // @[PackageRecoveryState.scala 166:72]
  wire  _GEN_383 = _T_31 & _GEN_354 & _GEN_360 ? _GEN_377 : _GEN_206; // @[PackageRecoveryState.scala 166:72]
  wire  _GEN_384 = _T_31 & _GEN_354 & _GEN_360 ? _GEN_378 : _GEN_207; // @[PackageRecoveryState.scala 166:72]
  wire [9:0] _io_write_bits_data_T = safeSlot * 7'h60; // @[PackageRecoveryState.scala 177:40]
  wire [9:0] _GEN_497 = {{3'd0}, index}; // @[PackageRecoveryState.scala 177:50]
  wire  _T_44 = io_restore_ready & io_restore_valid; // @[Decoupled.scala 51:35]
  wire [255:0] _legal_T_30 = {io_restore_bits_checkpoint_sequence,io_restore_bits_checkpoint_generation,
    io_restore_bits_checkpoint_restartPc,io_restore_bits_checkpoint_architecturalToken,
    io_restore_bits_checkpoint_memoryToken}; // @[PackageRecoveryState.scala 181:20]
  wire [255:0] _legal_T_31 = {_GEN_23,_GEN_29,_GEN_35,_GEN_41,_GEN_47}; // @[PackageRecoveryState.scala 181:48]
  wire  _legal_T_32 = _legal_T_30 == _legal_T_31; // @[PackageRecoveryState.scala 181:27]
  wire  _legal_T_33 = io_lock & failed & safeValid & _legal_T_32; // @[PackageRecoveryState.scala 180:48]
  wire  _legal_T_34 = io_restore_bits_failedSequence == failureSequence; // @[PackageRecoveryState.scala 182:24]
  wire  _legal_T_35 = _legal_T_33 & _legal_T_34; // @[PackageRecoveryState.scala 181:55]
  wire  _legal_T_38 = io_restore_bits_checkpoint_generation != 32'hffffffff; // @[PackageRecoveryState.scala 183:31]
  wire  _legal_T_39 = _legal_T_35 & io_restore_bits_failedSequence > io_restore_bits_checkpoint_sequence & _legal_T_38; // @[PackageRecoveryState.scala 182:88]
  wire [31:0] _legal_T_41 = io_restore_bits_checkpoint_generation + 32'h1; // @[PackageRecoveryState.scala 184:56]
  wire  _legal_T_42 = io_restore_bits_recoveryGeneration == _legal_T_41; // @[PackageRecoveryState.scala 184:28]
  wire  legal_2 = _legal_T_39 & _legal_T_42; // @[PackageRecoveryState.scala 183:49]
  wire  _GEN_386 = ~legal_2 | _GEN_328; // @[PackageRecoveryState.scala 185:{19,27}]
  wire [6:0] _GEN_394 = ~legal_2 ? index : 7'h0; // @[PackageRecoveryState.scala 185:19 187:13 83:22]
  wire  _GEN_395 = ~legal_2 ? active : 1'h1; // @[PackageRecoveryState.scala 185:19 188:14 81:23]
  wire  _GEN_396 = ~legal_2 & sent; // @[PackageRecoveryState.scala 185:19 189:12 82:21]
  wire  _GEN_397 = _T_44 ? _GEN_386 : _GEN_328; // @[PackageRecoveryState.scala 178:26]
  wire [6:0] _GEN_405 = _T_44 ? _GEN_394 : index; // @[PackageRecoveryState.scala 178:26 83:22]
  wire  _GEN_406 = _T_44 ? _GEN_395 : active; // @[PackageRecoveryState.scala 178:26 81:23]
  wire  _GEN_407 = _T_44 ? _GEN_396 : sent; // @[PackageRecoveryState.scala 178:26 82:21]
  wire  _T_46 = io_write_ready & io_write_valid; // @[Decoupled.scala 51:35]
  wire  _GEN_408 = _T_46 | _GEN_407; // @[PackageRecoveryState.scala 192:{24,31}]
  wire [319:0] _legal_T_46 = {io_writeCompleted_bits_command_checkpoint_sequence,
    io_writeCompleted_bits_command_checkpoint_generation,io_writeCompleted_bits_command_checkpoint_restartPc,
    io_writeCompleted_bits_command_checkpoint_architecturalToken,io_writeCompleted_bits_command_checkpoint_memoryToken,
    io_writeCompleted_bits_command_failedSequence,io_writeCompleted_bits_command_recoveryGeneration}; // @[PackageRecoveryState.scala 195:38]
  wire [319:0] _legal_T_47 = {command_checkpoint_sequence,command_checkpoint_generation,command_checkpoint_restartPc,
    command_checkpoint_architecturalToken,command_checkpoint_memoryToken,command_failedSequence,
    command_recoveryGeneration}; // @[PackageRecoveryState.scala 195:57]
  wire  _legal_T_48 = _legal_T_46 == _legal_T_47; // @[PackageRecoveryState.scala 195:45]
  wire  _legal_T_49 = active & (sent | _T_46) & _legal_T_48; // @[PackageRecoveryState.scala 194:51]
  wire  _legal_T_50 = io_writeCompleted_bits_index == index; // @[PackageRecoveryState.scala 196:36]
  wire  _legal_T_51 = _legal_T_49 & _legal_T_50; // @[PackageRecoveryState.scala 195:64]
  wire  _legal_T_55 = io_writeCompleted_bits_data == image_legal_MPORT_data; // @[PackageRecoveryState.scala 197:35]
  wire  legal_3 = _legal_T_51 & _legal_T_55; // @[PackageRecoveryState.scala 196:46]
  wire [6:0] _index_T_1 = index + 7'h1; // @[PackageRecoveryState.scala 204:36]
  wire  _GEN_410 = index == 7'h5f | restoredPendingRebase; // @[PackageRecoveryState.scala 200:38 202:31 85:38]
  wire  _GEN_411 = index == 7'h5f & _io_checkpoint_valid_T; // @[PackageRecoveryState.scala 100:21 200:38 203:27]
  wire  _GEN_413 = ~legal_3 | _GEN_397; // @[PackageRecoveryState.scala 198:{19,27}]
  wire  _GEN_414 = ~legal_3 & _GEN_408; // @[PackageRecoveryState.scala 198:19 199:12]
  wire  _GEN_416 = ~legal_3 ? restoredPendingRebase : _GEN_410; // @[PackageRecoveryState.scala 198:19 85:38]
  wire  _GEN_417 = ~legal_3 ? 1'h0 : _GEN_411; // @[PackageRecoveryState.scala 198:19 100:21]
  wire  _GEN_422 = io_writeCompleted_valid ? _GEN_413 : _GEN_397; // @[PackageRecoveryState.scala 193:34]
  wire  _GEN_425 = io_writeCompleted_valid ? _GEN_416 : restoredPendingRebase; // @[PackageRecoveryState.scala 193:34 85:38]
  wire  _T_49 = io_rebase_ready & io_rebase_valid; // @[Decoupled.scala 51:35]
  wire [319:0] _legal_T_56 = {io_rebase_bits_command_checkpoint_sequence,io_rebase_bits_command_checkpoint_generation,
    io_rebase_bits_command_checkpoint_restartPc,io_rebase_bits_command_checkpoint_architecturalToken,
    io_rebase_bits_command_checkpoint_memoryToken,io_rebase_bits_command_failedSequence,
    io_rebase_bits_command_recoveryGeneration}; // @[PackageRecoveryState.scala 209:51]
  wire  _legal_T_60 = io_rebase_bits_retiredPc == command_checkpoint_restartPc; // @[PackageRecoveryState.scala 210:32]
  wire  _legal_T_61 = io_lock & _legal_T_56 == _legal_T_47 & _legal_T_60; // @[PackageRecoveryState.scala 209:77]
  wire  legal_4 = _legal_T_61 & io_rebase_bits_allCheckerTasksDrained; // @[PackageRecoveryState.scala 210:65]
  wire  _GEN_440 = ~legal_4 | _GEN_422; // @[PackageRecoveryState.scala 212:{19,27}]
  wire  _GEN_456 = ~legal_4 & _GEN_298; // @[PackageRecoveryState.scala 212:19 218:17]
  wire  _GEN_457 = ~legal_4 & _GEN_341; // @[PackageRecoveryState.scala 212:19 219:14]
  wire  _GEN_458 = ~legal_4 & _GEN_48; // @[PackageRecoveryState.scala 212:19 220:23]
  wire  _GEN_459 = ~legal_4 & _GEN_425; // @[PackageRecoveryState.scala 212:19 221:29]
  wire  _GEN_499 = _T_33 & ~reset; // @[PackageRecoveryState.scala 167:11]
  assign image_io_write_bits_data_MPORT_en = 1'h1;
  assign image_io_write_bits_data_MPORT_addr = _io_write_bits_data_T + _GEN_497;
  `ifndef RANDOMIZE_GARBAGE_ASSIGN
  assign image_io_write_bits_data_MPORT_data = image[image_io_write_bits_data_MPORT_addr]; // @[PackageRecoveryState.scala 68:18]
  `else
  assign image_io_write_bits_data_MPORT_data = image_io_write_bits_data_MPORT_addr >= 10'h240 ? _RAND_1[63:0] :
    image[image_io_write_bits_data_MPORT_addr]; // @[PackageRecoveryState.scala 68:18]
  `endif // RANDOMIZE_GARBAGE_ASSIGN
  assign image_legal_MPORT_en = io_writeCompleted_valid;
  assign image_legal_MPORT_addr = _io_write_bits_data_T + _GEN_497;
  `ifndef RANDOMIZE_GARBAGE_ASSIGN
  assign image_legal_MPORT_data = image[image_legal_MPORT_addr]; // @[PackageRecoveryState.scala 68:18]
  `else
  assign image_legal_MPORT_data = image_legal_MPORT_addr >= 10'h240 ? _RAND_2[63:0] : image[image_legal_MPORT_addr]; // @[PackageRecoveryState.scala 68:18]
  `endif // RANDOMIZE_GARBAGE_ASSIGN
  assign image_MPORT_data = io_word_bits_data;
  assign image_MPORT_addr = _T_5 + _GEN_488;
  assign image_MPORT_mask = 1'h1;
  assign image_MPORT_en = _T_3 & _GEN_254;
  assign io_allocate_ready = ~locked & ~capturing & ~_GEN_54; // @[PackageRecoveryState.scala 105:46]
  assign io_word_ready = capturing & _io_allocate_ready_T & captured < 7'h60; // @[PackageRecoveryState.scala 125:41]
  assign io_seal_ready = _io_word_ready_T_1 & captured == 7'h60; // @[PackageRecoveryState.scala 139:41]
  assign io_result_ready = _io_checkpoint_valid_T & ~failed & ~active; // @[PackageRecoveryState.scala 145:40]
  assign io_checkpoint_valid = safeValid & ~error; // @[PackageRecoveryState.scala 89:36]
  assign io_checkpoint_bits_sequence = 3'h5 == safeSlot ? header_5_sequence : _GEN_22; // @[PackageRecoveryState.scala 90:{22,22}]
  assign io_checkpoint_bits_generation = 3'h5 == safeSlot ? header_5_generation : _GEN_28; // @[PackageRecoveryState.scala 90:{22,22}]
  assign io_checkpoint_bits_restartPc = 3'h5 == safeSlot ? header_5_restartPc : _GEN_34; // @[PackageRecoveryState.scala 90:{22,22}]
  assign io_checkpoint_bits_architecturalToken = 3'h5 == safeSlot ? header_5_architecturalToken : _GEN_40; // @[PackageRecoveryState.scala 90:{22,22}]
  assign io_checkpoint_bits_memoryToken = 3'h5 == safeSlot ? header_5_memoryToken : _GEN_46; // @[PackageRecoveryState.scala 90:{22,22}]
  assign io_failure_valid = failed & ~failureReported & _io_checkpoint_valid_T; // @[PackageRecoveryState.scala 94:50]
  assign io_failure_bits_sequence = failureSequence; // @[PackageRecoveryState.scala 95:28]
  assign io_failure_bits_generation = generation; // @[PackageRecoveryState.scala 96:30]
  assign io_failure_bits_allocated = 1'h1; // @[PackageRecoveryState.scala 97:29]
  assign io_failure_bits_comparedMismatch = 1'h1; // @[PackageRecoveryState.scala 98:36]
  assign io_restore_ready = _io_result_ready_T_3 & ~restoredPendingRebase & _io_checkpoint_valid_T; // @[PackageRecoveryState.scala 173:57]
  assign io_write_valid = active & ~sent & _io_checkpoint_valid_T; // @[PackageRecoveryState.scala 174:37]
  assign io_write_bits_command_checkpoint_sequence = command_checkpoint_sequence; // @[PackageRecoveryState.scala 175:25]
  assign io_write_bits_command_checkpoint_generation = command_checkpoint_generation; // @[PackageRecoveryState.scala 175:25]
  assign io_write_bits_command_checkpoint_restartPc = command_checkpoint_restartPc; // @[PackageRecoveryState.scala 175:25]
  assign io_write_bits_command_checkpoint_architecturalToken = command_checkpoint_architecturalToken; // @[PackageRecoveryState.scala 175:25]
  assign io_write_bits_command_checkpoint_memoryToken = command_checkpoint_memoryToken; // @[PackageRecoveryState.scala 175:25]
  assign io_write_bits_command_failedSequence = command_failedSequence; // @[PackageRecoveryState.scala 175:25]
  assign io_write_bits_command_recoveryGeneration = command_recoveryGeneration; // @[PackageRecoveryState.scala 175:25]
  assign io_write_bits_index = index; // @[PackageRecoveryState.scala 176:23]
  assign io_write_bits_data = image_io_write_bits_data_MPORT_data; // @[PackageRecoveryState.scala 177:22]
  assign io_restored_valid = io_writeCompleted_valid & _GEN_417; // @[PackageRecoveryState.scala 100:21 193:34]
  assign io_restored_bits_command_checkpoint_sequence = command_checkpoint_sequence; // @[PackageRecoveryState.scala 101:28]
  assign io_restored_bits_command_checkpoint_generation = command_checkpoint_generation; // @[PackageRecoveryState.scala 101:28]
  assign io_restored_bits_command_checkpoint_restartPc = command_checkpoint_restartPc; // @[PackageRecoveryState.scala 101:28]
  assign io_restored_bits_command_checkpoint_architecturalToken = command_checkpoint_architecturalToken; // @[PackageRecoveryState.scala 101:28]
  assign io_restored_bits_command_checkpoint_memoryToken = command_checkpoint_memoryToken; // @[PackageRecoveryState.scala 101:28]
  assign io_restored_bits_command_failedSequence = command_failedSequence; // @[PackageRecoveryState.scala 101:28]
  assign io_restored_bits_command_recoveryGeneration = command_recoveryGeneration; // @[PackageRecoveryState.scala 101:28]
  assign io_restored_bits_retiredPc = 64'h0; // @[PackageRecoveryState.scala 102:30]
  assign io_restored_bits_allCheckerTasksDrained = 1'h0; // @[PackageRecoveryState.scala 103:43]
  assign io_rebase_ready = _io_result_ready_T_3 & restoredPendingRebase & _io_checkpoint_valid_T; // @[PackageRecoveryState.scala 207:55]
  assign io_protocolError = error; // @[PackageRecoveryState.scala 91:20]
  assign io_restoreActive = active; // @[PackageRecoveryState.scala 92:20]
  assign io_occupancy = _io_occupancy_T_2[1:0] + _io_occupancy_T_6[1:0]; // @[Bitwise.scala 51:90]
  always @(posedge clock) begin
    if (image_MPORT_en & image_MPORT_mask) begin
      image[image_MPORT_addr] <= image_MPORT_data; // @[PackageRecoveryState.scala 68:18]
    end
    if (reset) begin // @[PackageRecoveryState.scala 63:22]
      valid_0 <= 1'h0; // @[PackageRecoveryState.scala 63:22]
    end else if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 212:19]
        valid_0 <= _GEN_379;
      end else if (safeSlot != 3'h0) begin // @[PackageRecoveryState.scala 213:58]
        valid_0 <= 1'h0; // @[PackageRecoveryState.scala 213:69]
      end else begin
        valid_0 <= _GEN_379;
      end
    end else begin
      valid_0 <= _GEN_379;
    end
    if (reset) begin // @[PackageRecoveryState.scala 63:22]
      valid_1 <= 1'h0; // @[PackageRecoveryState.scala 63:22]
    end else if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 212:19]
        valid_1 <= _GEN_380;
      end else if (safeSlot != 3'h1) begin // @[PackageRecoveryState.scala 213:58]
        valid_1 <= 1'h0; // @[PackageRecoveryState.scala 213:69]
      end else begin
        valid_1 <= _GEN_380;
      end
    end else begin
      valid_1 <= _GEN_380;
    end
    if (reset) begin // @[PackageRecoveryState.scala 63:22]
      valid_2 <= 1'h0; // @[PackageRecoveryState.scala 63:22]
    end else if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 212:19]
        valid_2 <= _GEN_381;
      end else if (safeSlot != 3'h2) begin // @[PackageRecoveryState.scala 213:58]
        valid_2 <= 1'h0; // @[PackageRecoveryState.scala 213:69]
      end else begin
        valid_2 <= _GEN_381;
      end
    end else begin
      valid_2 <= _GEN_381;
    end
    if (reset) begin // @[PackageRecoveryState.scala 63:22]
      valid_3 <= 1'h0; // @[PackageRecoveryState.scala 63:22]
    end else if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 212:19]
        valid_3 <= _GEN_382;
      end else if (safeSlot != 3'h3) begin // @[PackageRecoveryState.scala 213:58]
        valid_3 <= 1'h0; // @[PackageRecoveryState.scala 213:69]
      end else begin
        valid_3 <= _GEN_382;
      end
    end else begin
      valid_3 <= _GEN_382;
    end
    if (reset) begin // @[PackageRecoveryState.scala 63:22]
      valid_4 <= 1'h0; // @[PackageRecoveryState.scala 63:22]
    end else if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 212:19]
        valid_4 <= _GEN_383;
      end else if (safeSlot != 3'h4) begin // @[PackageRecoveryState.scala 213:58]
        valid_4 <= 1'h0; // @[PackageRecoveryState.scala 213:69]
      end else begin
        valid_4 <= _GEN_383;
      end
    end else begin
      valid_4 <= _GEN_383;
    end
    if (reset) begin // @[PackageRecoveryState.scala 63:22]
      valid_5 <= 1'h0; // @[PackageRecoveryState.scala 63:22]
    end else if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 212:19]
        valid_5 <= _GEN_384;
      end else if (safeSlot != 3'h5) begin // @[PackageRecoveryState.scala 213:58]
        valid_5 <= 1'h0; // @[PackageRecoveryState.scala 213:69]
      end else begin
        valid_5 <= _GEN_384;
      end
    end else begin
      valid_5 <= _GEN_384;
    end
    if (reset) begin // @[PackageRecoveryState.scala 64:28]
      sealedImage_0 <= 1'h0; // @[PackageRecoveryState.scala 64:28]
    end else if (_T_8) begin // @[PackageRecoveryState.scala 140:23]
      if (_T_9 != _T_10) begin // @[PackageRecoveryState.scala 141:63]
        sealedImage_0 <= _GEN_208;
      end else begin
        sealedImage_0 <= _GEN_277;
      end
    end else begin
      sealedImage_0 <= _GEN_208;
    end
    if (reset) begin // @[PackageRecoveryState.scala 64:28]
      sealedImage_1 <= 1'h0; // @[PackageRecoveryState.scala 64:28]
    end else if (_T_8) begin // @[PackageRecoveryState.scala 140:23]
      if (_T_9 != _T_10) begin // @[PackageRecoveryState.scala 141:63]
        sealedImage_1 <= _GEN_209;
      end else begin
        sealedImage_1 <= _GEN_278;
      end
    end else begin
      sealedImage_1 <= _GEN_209;
    end
    if (reset) begin // @[PackageRecoveryState.scala 64:28]
      sealedImage_2 <= 1'h0; // @[PackageRecoveryState.scala 64:28]
    end else if (_T_8) begin // @[PackageRecoveryState.scala 140:23]
      if (_T_9 != _T_10) begin // @[PackageRecoveryState.scala 141:63]
        sealedImage_2 <= _GEN_210;
      end else begin
        sealedImage_2 <= _GEN_279;
      end
    end else begin
      sealedImage_2 <= _GEN_210;
    end
    if (reset) begin // @[PackageRecoveryState.scala 64:28]
      sealedImage_3 <= 1'h0; // @[PackageRecoveryState.scala 64:28]
    end else if (_T_8) begin // @[PackageRecoveryState.scala 140:23]
      if (_T_9 != _T_10) begin // @[PackageRecoveryState.scala 141:63]
        sealedImage_3 <= _GEN_211;
      end else begin
        sealedImage_3 <= _GEN_280;
      end
    end else begin
      sealedImage_3 <= _GEN_211;
    end
    if (reset) begin // @[PackageRecoveryState.scala 64:28]
      sealedImage_4 <= 1'h0; // @[PackageRecoveryState.scala 64:28]
    end else if (_T_8) begin // @[PackageRecoveryState.scala 140:23]
      if (_T_9 != _T_10) begin // @[PackageRecoveryState.scala 141:63]
        sealedImage_4 <= _GEN_212;
      end else begin
        sealedImage_4 <= _GEN_281;
      end
    end else begin
      sealedImage_4 <= _GEN_212;
    end
    if (reset) begin // @[PackageRecoveryState.scala 64:28]
      sealedImage_5 <= 1'h0; // @[PackageRecoveryState.scala 64:28]
    end else if (_T_8) begin // @[PackageRecoveryState.scala 140:23]
      if (_T_9 != _T_10) begin // @[PackageRecoveryState.scala 141:63]
        sealedImage_5 <= _GEN_213;
      end else begin
        sealedImage_5 <= _GEN_282;
      end
    end else begin
      sealedImage_5 <= _GEN_213;
    end
    if (reset) begin // @[PackageRecoveryState.scala 65:27]
      resultSeen_0 <= 1'h0; // @[PackageRecoveryState.scala 65:27]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 149:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 150:70]
        resultSeen_0 <= _GEN_214;
      end else begin
        resultSeen_0 <= _GEN_299;
      end
    end else begin
      resultSeen_0 <= _GEN_214;
    end
    if (reset) begin // @[PackageRecoveryState.scala 65:27]
      resultSeen_1 <= 1'h0; // @[PackageRecoveryState.scala 65:27]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 149:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 150:70]
        resultSeen_1 <= _GEN_215;
      end else begin
        resultSeen_1 <= _GEN_301;
      end
    end else begin
      resultSeen_1 <= _GEN_215;
    end
    if (reset) begin // @[PackageRecoveryState.scala 65:27]
      resultSeen_2 <= 1'h0; // @[PackageRecoveryState.scala 65:27]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 149:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 150:70]
        resultSeen_2 <= _GEN_216;
      end else begin
        resultSeen_2 <= _GEN_303;
      end
    end else begin
      resultSeen_2 <= _GEN_216;
    end
    if (reset) begin // @[PackageRecoveryState.scala 65:27]
      resultSeen_3 <= 1'h0; // @[PackageRecoveryState.scala 65:27]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 149:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 150:70]
        resultSeen_3 <= _GEN_217;
      end else begin
        resultSeen_3 <= _GEN_305;
      end
    end else begin
      resultSeen_3 <= _GEN_217;
    end
    if (reset) begin // @[PackageRecoveryState.scala 65:27]
      resultSeen_4 <= 1'h0; // @[PackageRecoveryState.scala 65:27]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 149:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 150:70]
        resultSeen_4 <= _GEN_218;
      end else begin
        resultSeen_4 <= _GEN_307;
      end
    end else begin
      resultSeen_4 <= _GEN_218;
    end
    if (reset) begin // @[PackageRecoveryState.scala 65:27]
      resultSeen_5 <= 1'h0; // @[PackageRecoveryState.scala 65:27]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 149:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 150:70]
        resultSeen_5 <= _GEN_219;
      end else begin
        resultSeen_5 <= _GEN_309;
      end
    end else begin
      resultSeen_5 <= _GEN_219;
    end
    if (reset) begin // @[PackageRecoveryState.scala 66:23]
      passed_0 <= 1'h0; // @[PackageRecoveryState.scala 66:23]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 149:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 150:70]
        passed_0 <= _GEN_220;
      end else if (resultMatch_0) begin // @[PackageRecoveryState.scala 153:33]
        passed_0 <= io_result_bits_passed; // @[PackageRecoveryState.scala 155:23]
      end else begin
        passed_0 <= _GEN_220;
      end
    end else begin
      passed_0 <= _GEN_220;
    end
    if (reset) begin // @[PackageRecoveryState.scala 66:23]
      passed_1 <= 1'h0; // @[PackageRecoveryState.scala 66:23]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 149:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 150:70]
        passed_1 <= _GEN_221;
      end else if (resultMatch_1) begin // @[PackageRecoveryState.scala 153:33]
        passed_1 <= io_result_bits_passed; // @[PackageRecoveryState.scala 155:23]
      end else begin
        passed_1 <= _GEN_221;
      end
    end else begin
      passed_1 <= _GEN_221;
    end
    if (reset) begin // @[PackageRecoveryState.scala 66:23]
      passed_2 <= 1'h0; // @[PackageRecoveryState.scala 66:23]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 149:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 150:70]
        passed_2 <= _GEN_222;
      end else if (resultMatch_2) begin // @[PackageRecoveryState.scala 153:33]
        passed_2 <= io_result_bits_passed; // @[PackageRecoveryState.scala 155:23]
      end else begin
        passed_2 <= _GEN_222;
      end
    end else begin
      passed_2 <= _GEN_222;
    end
    if (reset) begin // @[PackageRecoveryState.scala 66:23]
      passed_3 <= 1'h0; // @[PackageRecoveryState.scala 66:23]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 149:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 150:70]
        passed_3 <= _GEN_223;
      end else if (resultMatch_3) begin // @[PackageRecoveryState.scala 153:33]
        passed_3 <= io_result_bits_passed; // @[PackageRecoveryState.scala 155:23]
      end else begin
        passed_3 <= _GEN_223;
      end
    end else begin
      passed_3 <= _GEN_223;
    end
    if (reset) begin // @[PackageRecoveryState.scala 66:23]
      passed_4 <= 1'h0; // @[PackageRecoveryState.scala 66:23]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 149:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 150:70]
        passed_4 <= _GEN_224;
      end else if (resultMatch_4) begin // @[PackageRecoveryState.scala 153:33]
        passed_4 <= io_result_bits_passed; // @[PackageRecoveryState.scala 155:23]
      end else begin
        passed_4 <= _GEN_224;
      end
    end else begin
      passed_4 <= _GEN_224;
    end
    if (reset) begin // @[PackageRecoveryState.scala 66:23]
      passed_5 <= 1'h0; // @[PackageRecoveryState.scala 66:23]
    end else if (_T_12) begin // @[PackageRecoveryState.scala 149:25]
      if (_T_21 != 3'h1 | ~io_result_bits_compared) begin // @[PackageRecoveryState.scala 150:70]
        passed_5 <= _GEN_225;
      end else if (resultMatch_5) begin // @[PackageRecoveryState.scala 153:33]
        passed_5 <= io_result_bits_passed; // @[PackageRecoveryState.scala 155:23]
      end else begin
        passed_5 <= _GEN_225;
      end
    end else begin
      passed_5 <= _GEN_225;
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h0 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_0_sequence <= io_allocate_bits_sequence; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 212:19]
        header_0_generation <= _GEN_178;
      end else if (3'h0 == safeSlot) begin // @[PackageRecoveryState.scala 214:35]
        header_0_generation <= command_recoveryGeneration; // @[PackageRecoveryState.scala 214:35]
      end else begin
        header_0_generation <= _GEN_178;
      end
    end else begin
      header_0_generation <= _GEN_178;
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h0 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_0_restartPc <= io_allocate_bits_restartPc; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h0 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_0_architecturalToken <= io_allocate_bits_architecturalToken; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h0 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_0_memoryToken <= io_allocate_bits_memoryToken; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h1 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_1_sequence <= io_allocate_bits_sequence; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 212:19]
        header_1_generation <= _GEN_179;
      end else if (3'h1 == safeSlot) begin // @[PackageRecoveryState.scala 214:35]
        header_1_generation <= command_recoveryGeneration; // @[PackageRecoveryState.scala 214:35]
      end else begin
        header_1_generation <= _GEN_179;
      end
    end else begin
      header_1_generation <= _GEN_179;
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h1 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_1_restartPc <= io_allocate_bits_restartPc; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h1 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_1_architecturalToken <= io_allocate_bits_architecturalToken; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h1 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_1_memoryToken <= io_allocate_bits_memoryToken; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h2 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_2_sequence <= io_allocate_bits_sequence; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 212:19]
        header_2_generation <= _GEN_180;
      end else if (3'h2 == safeSlot) begin // @[PackageRecoveryState.scala 214:35]
        header_2_generation <= command_recoveryGeneration; // @[PackageRecoveryState.scala 214:35]
      end else begin
        header_2_generation <= _GEN_180;
      end
    end else begin
      header_2_generation <= _GEN_180;
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h2 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_2_restartPc <= io_allocate_bits_restartPc; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h2 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_2_architecturalToken <= io_allocate_bits_architecturalToken; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h2 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_2_memoryToken <= io_allocate_bits_memoryToken; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h3 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_3_sequence <= io_allocate_bits_sequence; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 212:19]
        header_3_generation <= _GEN_181;
      end else if (3'h3 == safeSlot) begin // @[PackageRecoveryState.scala 214:35]
        header_3_generation <= command_recoveryGeneration; // @[PackageRecoveryState.scala 214:35]
      end else begin
        header_3_generation <= _GEN_181;
      end
    end else begin
      header_3_generation <= _GEN_181;
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h3 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_3_restartPc <= io_allocate_bits_restartPc; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h3 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_3_architecturalToken <= io_allocate_bits_architecturalToken; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h3 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_3_memoryToken <= io_allocate_bits_memoryToken; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h4 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_4_sequence <= io_allocate_bits_sequence; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 212:19]
        header_4_generation <= _GEN_182;
      end else if (3'h4 == safeSlot) begin // @[PackageRecoveryState.scala 214:35]
        header_4_generation <= command_recoveryGeneration; // @[PackageRecoveryState.scala 214:35]
      end else begin
        header_4_generation <= _GEN_182;
      end
    end else begin
      header_4_generation <= _GEN_182;
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h4 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_4_restartPc <= io_allocate_bits_restartPc; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h4 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_4_architecturalToken <= io_allocate_bits_architecturalToken; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h4 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_4_memoryToken <= io_allocate_bits_memoryToken; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h5 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_5_sequence <= io_allocate_bits_sequence; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 212:19]
        header_5_generation <= _GEN_183;
      end else if (3'h5 == safeSlot) begin // @[PackageRecoveryState.scala 214:35]
        header_5_generation <= command_recoveryGeneration; // @[PackageRecoveryState.scala 214:35]
      end else begin
        header_5_generation <= _GEN_183;
      end
    end else begin
      header_5_generation <= _GEN_183;
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h5 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_5_restartPc <= io_allocate_bits_restartPc; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h5 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_5_architecturalToken <= io_allocate_bits_architecturalToken; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        if (3'h5 == allocateSlot) begin // @[PackageRecoveryState.scala 111:28]
          header_5_memoryToken <= io_allocate_bits_memoryToken; // @[PackageRecoveryState.scala 111:28]
        end
      end
    end
    if (reset) begin // @[PackageRecoveryState.scala 69:25]
      safeSlot <= 3'h0; // @[PackageRecoveryState.scala 69:25]
    end else if (_T_31 & _GEN_354 & _GEN_360) begin // @[PackageRecoveryState.scala 166:72]
      if (safeSlot == 3'h5) begin // @[PackageRecoveryState.scala 62:36]
        safeSlot <= 3'h0;
      end else begin
        safeSlot <= _successor_T_2;
      end
    end
    if (reset) begin // @[PackageRecoveryState.scala 70:29]
      allocateSlot <= 3'h0; // @[PackageRecoveryState.scala 70:29]
    end else if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 212:19]
        allocateSlot <= _GEN_227;
      end else if (safeSlot == 3'h5) begin // @[PackageRecoveryState.scala 62:36]
        allocateSlot <= 3'h0;
      end else begin
        allocateSlot <= _successor_T_2;
      end
    end else begin
      allocateSlot <= _GEN_227;
    end
    if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        captureSlot <= allocateSlot; // @[PackageRecoveryState.scala 116:19]
      end
    end
    if (reset) begin // @[PackageRecoveryState.scala 72:26]
      capturing <= 1'h0; // @[PackageRecoveryState.scala 72:26]
    end else if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      capturing <= _GEN_456;
    end else if (_T_8) begin // @[PackageRecoveryState.scala 140:23]
      capturing <= _GEN_290;
    end else if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      capturing <= _GEN_166;
    end
    if (reset) begin // @[PackageRecoveryState.scala 73:25]
      captured <= 7'h0; // @[PackageRecoveryState.scala 73:25]
    end else if (_T_3) begin // @[PackageRecoveryState.scala 126:23]
      if (~legal_1) begin // @[PackageRecoveryState.scala 134:19]
        captured <= _GEN_229;
      end else begin
        captured <= _captured_T_1; // @[PackageRecoveryState.scala 136:16]
      end
    end else begin
      captured <= _GEN_229;
    end
    if (reset) begin // @[PackageRecoveryState.scala 74:29]
      hasAllocated <= 1'h0; // @[PackageRecoveryState.scala 74:29]
    end else if (_T_1) begin // @[PackageRecoveryState.scala 106:27]
      if (!(~legal)) begin // @[PackageRecoveryState.scala 110:19]
        hasAllocated <= 1'h1; // @[PackageRecoveryState.scala 122:20]
      end
    end
    if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 212:19]
        lastSequence <= _GEN_231;
      end else begin
        lastSequence <= command_checkpoint_sequence; // @[PackageRecoveryState.scala 216:20]
      end
    end else begin
      lastSequence <= _GEN_231;
    end
    if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      if (~legal_4) begin // @[PackageRecoveryState.scala 212:19]
        generation <= _GEN_230;
      end else begin
        generation <= command_recoveryGeneration; // @[PackageRecoveryState.scala 215:18]
      end
    end else begin
      generation <= _GEN_230;
    end
    if (reset) begin // @[PackageRecoveryState.scala 77:23]
      failed <= 1'h0; // @[PackageRecoveryState.scala 77:23]
    end else if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      failed <= _GEN_457;
    end else if (_T_12) begin // @[PackageRecoveryState.scala 149:25]
      if (!(_T_21 != 3'h1 | ~io_result_bits_compared)) begin // @[PackageRecoveryState.scala 150:70]
        failed <= _GEN_311;
      end
    end
    if (_T_12) begin // @[PackageRecoveryState.scala 149:25]
      if (!(_T_21 != 3'h1 | ~io_result_bits_compared)) begin // @[PackageRecoveryState.scala 150:70]
        if (~io_result_bits_passed) begin // @[PackageRecoveryState.scala 158:39]
          failureSequence <= io_result_bits_sequence; // @[PackageRecoveryState.scala 160:27]
        end
      end
    end
    if (reset) begin // @[PackageRecoveryState.scala 79:32]
      failureReported <= 1'h0; // @[PackageRecoveryState.scala 79:32]
    end else if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      failureReported <= _GEN_458;
    end else begin
      failureReported <= _GEN_48;
    end
    if (reset) begin // @[PackageRecoveryState.scala 80:22]
      error <= 1'h0; // @[PackageRecoveryState.scala 80:22]
    end else if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      error <= _GEN_440;
    end else if (io_writeCompleted_valid) begin // @[PackageRecoveryState.scala 193:34]
      error <= _GEN_413;
    end else if (_T_44) begin // @[PackageRecoveryState.scala 178:26]
      error <= _GEN_386;
    end else begin
      error <= _GEN_328;
    end
    if (reset) begin // @[PackageRecoveryState.scala 81:23]
      active <= 1'h0; // @[PackageRecoveryState.scala 81:23]
    end else if (io_writeCompleted_valid) begin // @[PackageRecoveryState.scala 193:34]
      if (~legal_3) begin // @[PackageRecoveryState.scala 198:19]
        active <= _GEN_406;
      end else if (index == 7'h5f) begin // @[PackageRecoveryState.scala 200:38]
        active <= 1'h0; // @[PackageRecoveryState.scala 201:16]
      end else begin
        active <= _GEN_406;
      end
    end else begin
      active <= _GEN_406;
    end
    if (reset) begin // @[PackageRecoveryState.scala 82:21]
      sent <= 1'h0; // @[PackageRecoveryState.scala 82:21]
    end else if (io_writeCompleted_valid) begin // @[PackageRecoveryState.scala 193:34]
      sent <= _GEN_414;
    end else begin
      sent <= _GEN_408;
    end
    if (reset) begin // @[PackageRecoveryState.scala 83:22]
      index <= 7'h0; // @[PackageRecoveryState.scala 83:22]
    end else if (io_writeCompleted_valid) begin // @[PackageRecoveryState.scala 193:34]
      if (~legal_3) begin // @[PackageRecoveryState.scala 198:19]
        index <= _GEN_405;
      end else if (index == 7'h5f) begin // @[PackageRecoveryState.scala 200:38]
        index <= _GEN_405;
      end else begin
        index <= _index_T_1; // @[PackageRecoveryState.scala 204:27]
      end
    end else begin
      index <= _GEN_405;
    end
    if (_T_44) begin // @[PackageRecoveryState.scala 178:26]
      if (!(~legal_2)) begin // @[PackageRecoveryState.scala 185:19]
        command_checkpoint_sequence <= io_restore_bits_checkpoint_sequence; // @[PackageRecoveryState.scala 186:15]
      end
    end
    if (_T_44) begin // @[PackageRecoveryState.scala 178:26]
      if (!(~legal_2)) begin // @[PackageRecoveryState.scala 185:19]
        command_checkpoint_generation <= io_restore_bits_checkpoint_generation; // @[PackageRecoveryState.scala 186:15]
      end
    end
    if (_T_44) begin // @[PackageRecoveryState.scala 178:26]
      if (!(~legal_2)) begin // @[PackageRecoveryState.scala 185:19]
        command_checkpoint_restartPc <= io_restore_bits_checkpoint_restartPc; // @[PackageRecoveryState.scala 186:15]
      end
    end
    if (_T_44) begin // @[PackageRecoveryState.scala 178:26]
      if (!(~legal_2)) begin // @[PackageRecoveryState.scala 185:19]
        command_checkpoint_architecturalToken <= io_restore_bits_checkpoint_architecturalToken; // @[PackageRecoveryState.scala 186:15]
      end
    end
    if (_T_44) begin // @[PackageRecoveryState.scala 178:26]
      if (!(~legal_2)) begin // @[PackageRecoveryState.scala 185:19]
        command_checkpoint_memoryToken <= io_restore_bits_checkpoint_memoryToken; // @[PackageRecoveryState.scala 186:15]
      end
    end
    if (_T_44) begin // @[PackageRecoveryState.scala 178:26]
      if (!(~legal_2)) begin // @[PackageRecoveryState.scala 185:19]
        command_failedSequence <= io_restore_bits_failedSequence; // @[PackageRecoveryState.scala 186:15]
      end
    end
    if (_T_44) begin // @[PackageRecoveryState.scala 178:26]
      if (!(~legal_2)) begin // @[PackageRecoveryState.scala 185:19]
        command_recoveryGeneration <= io_restore_bits_recoveryGeneration; // @[PackageRecoveryState.scala 186:15]
      end
    end
    if (reset) begin // @[PackageRecoveryState.scala 85:38]
      restoredPendingRebase <= 1'h0; // @[PackageRecoveryState.scala 85:38]
    end else if (_T_49) begin // @[PackageRecoveryState.scala 208:25]
      restoredPendingRebase <= _GEN_459;
    end else if (io_writeCompleted_valid) begin // @[PackageRecoveryState.scala 193:34]
      if (!(~legal_3)) begin // @[PackageRecoveryState.scala 198:19]
        restoredPendingRebase <= _GEN_410;
      end
    end
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_33 & ~reset & ~(_GEN_366 == _T_35)) begin
          $fwrite(32'h80000002,
            "Assertion failed\n    at PackageRecoveryState.scala:167 assert(header(successor).sequence === header(safeSlot).sequence + 1.U)\n"
            ); // @[PackageRecoveryState.scala 167:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_33 & ~reset & ~(_GEN_366 == _T_35)) begin
          $fatal; // @[PackageRecoveryState.scala 167:11]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_499 & ~(_GEN_372 == _GEN_29)) begin
          $fwrite(32'h80000002,
            "Assertion failed\n    at PackageRecoveryState.scala:168 assert(header(successor).generation === header(safeSlot).generation)\n"
            ); // @[PackageRecoveryState.scala 168:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_499 & ~(_GEN_372 == _GEN_29)) begin
          $fatal; // @[PackageRecoveryState.scala 168:11]
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
