module PackageRecoveryMemory(
  input         clock,
  input         reset,
  input         io_lock,
  output        io_initialize_ready,
  input         io_initialize_valid,
  input  [31:0] io_initialize_bits_sequence,
  input  [31:0] io_initialize_bits_generation,
  input  [63:0] io_initialize_bits_restartPc,
  input  [63:0] io_initialize_bits_architecturalToken,
  input  [63:0] io_initialize_bits_memoryToken,
  output        io_log_ready,
  input         io_log_valid,
  input  [31:0] io_log_bits_sequence,
  input  [31:0] io_log_bits_generation,
  input  [63:0] io_log_bits_address,
  input  [63:0] io_log_bits_previousData,
  input  [7:0]  io_log_bits_mask,
  output [63:0] io_nextToken,
  output [6:0]  io_occupancy,
  output        io_release_ready,
  input         io_release_valid,
  input  [31:0] io_release_bits_sequence,
  input  [31:0] io_release_bits_generation,
  input  [63:0] io_release_bits_restartPc,
  input  [63:0] io_release_bits_architecturalToken,
  input  [63:0] io_release_bits_memoryToken,
  output        io_released_valid,
  output [31:0] io_released_bits_sequence,
  output [31:0] io_released_bits_generation,
  output [63:0] io_released_bits_restartPc,
  output [63:0] io_released_bits_architecturalToken,
  output [63:0] io_released_bits_memoryToken,
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
  output [63:0] io_write_bits_cursor,
  output [63:0] io_write_bits_address,
  output [63:0] io_write_bits_data,
  output [7:0]  io_write_bits_mask,
  input         io_writeCompleted_valid,
  input  [31:0] io_writeCompleted_bits_command_checkpoint_sequence,
  input  [31:0] io_writeCompleted_bits_command_checkpoint_generation,
  input  [63:0] io_writeCompleted_bits_command_checkpoint_restartPc,
  input  [63:0] io_writeCompleted_bits_command_checkpoint_architecturalToken,
  input  [63:0] io_writeCompleted_bits_command_checkpoint_memoryToken,
  input  [31:0] io_writeCompleted_bits_command_failedSequence,
  input  [31:0] io_writeCompleted_bits_command_recoveryGeneration,
  input  [63:0] io_writeCompleted_bits_cursor,
  input  [63:0] io_writeCompleted_bits_address,
  input  [63:0] io_writeCompleted_bits_data,
  input  [7:0]  io_writeCompleted_bits_mask,
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
  output        io_active
);
`ifdef RANDOMIZE_MEM_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [63:0] _RAND_2;
  reg [63:0] _RAND_3;
  reg [31:0] _RAND_4;
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [63:0] _RAND_11;
  reg [63:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [63:0] _RAND_15;
  reg [63:0] _RAND_16;
  reg [63:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [63:0] _RAND_20;
  reg [63:0] _RAND_21;
  reg [63:0] _RAND_22;
  reg [31:0] _RAND_23;
  reg [31:0] _RAND_24;
  reg [63:0] _RAND_25;
  reg [63:0] _RAND_26;
  reg [63:0] _RAND_27;
  reg [31:0] _RAND_28;
  reg [31:0] _RAND_29;
  reg [31:0] _RAND_30;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] journal_sequence [0:63]; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_sequence_front_en; // @[PackageRecoveryMemory.scala 66:20]
  wire [5:0] journal_sequence_front_addr; // @[PackageRecoveryMemory.scala 66:20]
  wire [31:0] journal_sequence_front_data; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_sequence_newest_en; // @[PackageRecoveryMemory.scala 66:20]
  wire [5:0] journal_sequence_newest_addr; // @[PackageRecoveryMemory.scala 66:20]
  wire [31:0] journal_sequence_newest_data; // @[PackageRecoveryMemory.scala 66:20]
  wire [31:0] journal_sequence_MPORT_data; // @[PackageRecoveryMemory.scala 66:20]
  wire [5:0] journal_sequence_MPORT_addr; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_sequence_MPORT_mask; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_sequence_MPORT_en; // @[PackageRecoveryMemory.scala 66:20]
  reg [31:0] journal_generation [0:63]; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_generation_front_en; // @[PackageRecoveryMemory.scala 66:20]
  wire [5:0] journal_generation_front_addr; // @[PackageRecoveryMemory.scala 66:20]
  wire [31:0] journal_generation_front_data; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_generation_newest_en; // @[PackageRecoveryMemory.scala 66:20]
  wire [5:0] journal_generation_newest_addr; // @[PackageRecoveryMemory.scala 66:20]
  wire [31:0] journal_generation_newest_data; // @[PackageRecoveryMemory.scala 66:20]
  wire [31:0] journal_generation_MPORT_data; // @[PackageRecoveryMemory.scala 66:20]
  wire [5:0] journal_generation_MPORT_addr; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_generation_MPORT_mask; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_generation_MPORT_en; // @[PackageRecoveryMemory.scala 66:20]
  reg [63:0] journal_address [0:63]; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_address_front_en; // @[PackageRecoveryMemory.scala 66:20]
  wire [5:0] journal_address_front_addr; // @[PackageRecoveryMemory.scala 66:20]
  wire [63:0] journal_address_front_data; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_address_newest_en; // @[PackageRecoveryMemory.scala 66:20]
  wire [5:0] journal_address_newest_addr; // @[PackageRecoveryMemory.scala 66:20]
  wire [63:0] journal_address_newest_data; // @[PackageRecoveryMemory.scala 66:20]
  wire [63:0] journal_address_MPORT_data; // @[PackageRecoveryMemory.scala 66:20]
  wire [5:0] journal_address_MPORT_addr; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_address_MPORT_mask; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_address_MPORT_en; // @[PackageRecoveryMemory.scala 66:20]
  reg [63:0] journal_previousData [0:63]; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_previousData_front_en; // @[PackageRecoveryMemory.scala 66:20]
  wire [5:0] journal_previousData_front_addr; // @[PackageRecoveryMemory.scala 66:20]
  wire [63:0] journal_previousData_front_data; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_previousData_newest_en; // @[PackageRecoveryMemory.scala 66:20]
  wire [5:0] journal_previousData_newest_addr; // @[PackageRecoveryMemory.scala 66:20]
  wire [63:0] journal_previousData_newest_data; // @[PackageRecoveryMemory.scala 66:20]
  wire [63:0] journal_previousData_MPORT_data; // @[PackageRecoveryMemory.scala 66:20]
  wire [5:0] journal_previousData_MPORT_addr; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_previousData_MPORT_mask; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_previousData_MPORT_en; // @[PackageRecoveryMemory.scala 66:20]
  reg [7:0] journal_mask [0:63]; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_mask_front_en; // @[PackageRecoveryMemory.scala 66:20]
  wire [5:0] journal_mask_front_addr; // @[PackageRecoveryMemory.scala 66:20]
  wire [7:0] journal_mask_front_data; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_mask_newest_en; // @[PackageRecoveryMemory.scala 66:20]
  wire [5:0] journal_mask_newest_addr; // @[PackageRecoveryMemory.scala 66:20]
  wire [7:0] journal_mask_newest_data; // @[PackageRecoveryMemory.scala 66:20]
  wire [7:0] journal_mask_MPORT_data; // @[PackageRecoveryMemory.scala 66:20]
  wire [5:0] journal_mask_MPORT_addr; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_mask_MPORT_mask; // @[PackageRecoveryMemory.scala 66:20]
  wire  journal_mask_MPORT_en; // @[PackageRecoveryMemory.scala 66:20]
  reg  seeded; // @[PackageRecoveryMemory.scala 54:23]
  reg  error; // @[PackageRecoveryMemory.scala 55:22]
  reg  releasing; // @[PackageRecoveryMemory.scala 56:26]
  reg  restoring; // @[PackageRecoveryMemory.scala 57:26]
  reg  pendingRebase; // @[PackageRecoveryMemory.scala 58:30]
  reg  sent; // @[PackageRecoveryMemory.scala 59:21]
  reg [63:0] head; // @[PackageRecoveryMemory.scala 60:21]
  reg [63:0] tail; // @[PackageRecoveryMemory.scala 61:21]
  reg [31:0] base_sequence; // @[PackageRecoveryMemory.scala 62:17]
  reg [31:0] base_generation; // @[PackageRecoveryMemory.scala 62:17]
  reg [63:0] base_restartPc; // @[PackageRecoveryMemory.scala 62:17]
  reg [63:0] base_architecturalToken; // @[PackageRecoveryMemory.scala 62:17]
  reg [63:0] base_memoryToken; // @[PackageRecoveryMemory.scala 62:17]
  reg [31:0] releaseTarget_sequence; // @[PackageRecoveryMemory.scala 63:26]
  reg [31:0] releaseTarget_generation; // @[PackageRecoveryMemory.scala 63:26]
  reg [63:0] releaseTarget_restartPc; // @[PackageRecoveryMemory.scala 63:26]
  reg [63:0] releaseTarget_architecturalToken; // @[PackageRecoveryMemory.scala 63:26]
  reg [63:0] releaseTarget_memoryToken; // @[PackageRecoveryMemory.scala 63:26]
  reg [31:0] command_checkpoint_sequence; // @[PackageRecoveryMemory.scala 64:20]
  reg [31:0] command_checkpoint_generation; // @[PackageRecoveryMemory.scala 64:20]
  reg [63:0] command_checkpoint_restartPc; // @[PackageRecoveryMemory.scala 64:20]
  reg [63:0] command_checkpoint_architecturalToken; // @[PackageRecoveryMemory.scala 64:20]
  reg [63:0] command_checkpoint_memoryToken; // @[PackageRecoveryMemory.scala 64:20]
  reg [31:0] command_failedSequence; // @[PackageRecoveryMemory.scala 64:20]
  reg [31:0] command_recoveryGeneration; // @[PackageRecoveryMemory.scala 64:20]
  reg [31:0] lastSequence; // @[PackageRecoveryMemory.scala 65:25]
  wire [63:0] _newest_T_1 = tail - 64'h1; // @[PackageRecoveryMemory.scala 69:34]
  wire  _idle_T_6 = ~error; // @[PackageRecoveryMemory.scala 70:70]
  wire  idle = seeded & ~releasing & ~restoring & ~pendingRebase & ~error; // @[PackageRecoveryMemory.scala 70:67]
  wire [63:0] _io_occupancy_T_1 = tail - head; // @[PackageRecoveryMemory.scala 73:24]
  wire  _io_log_ready_T_1 = idle & ~io_lock; // @[PackageRecoveryMemory.scala 77:24]
  wire  _io_log_ready_T_4 = ~io_restore_valid; // @[PackageRecoveryMemory.scala 77:60]
  wire  _io_log_ready_T_8 = _io_occupancy_T_1 < 64'h40; // @[PackageRecoveryMemory.scala 78:17]
  wire  _io_write_valid_T_4 = tail != head; // @[PackageRecoveryMemory.scala 82:58]
  wire  _io_write_valid_T_6 = journal_sequence_newest_data > command_checkpoint_sequence; // @[PackageRecoveryMemory.scala 83:21]
  wire  _io_write_valid_T_7 = restoring & ~sent & _idle_T_6 & tail != head & _io_write_valid_T_6; // @[PackageRecoveryMemory.scala 82:67]
  wire  _io_write_valid_T_8 = journal_generation_newest_data == command_checkpoint_generation; // @[PackageRecoveryMemory.scala 84:23]
  wire  _T = io_initialize_ready & io_initialize_valid; // @[Decoupled.scala 51:35]
  wire [31:0] _GEN_0 = _T ? io_initialize_bits_sequence : base_sequence; // @[PackageRecoveryMemory.scala 97:29 98:10 62:17]
  wire [31:0] _GEN_1 = _T ? io_initialize_bits_generation : base_generation; // @[PackageRecoveryMemory.scala 97:29 98:10 62:17]
  wire [63:0] _GEN_2 = _T ? io_initialize_bits_restartPc : base_restartPc; // @[PackageRecoveryMemory.scala 97:29 98:10 62:17]
  wire [63:0] _GEN_3 = _T ? io_initialize_bits_architecturalToken : base_architecturalToken; // @[PackageRecoveryMemory.scala 97:29 98:10 62:17]
  wire [63:0] _GEN_4 = _T ? io_initialize_bits_memoryToken : base_memoryToken; // @[PackageRecoveryMemory.scala 97:29 98:10 62:17]
  wire [63:0] _GEN_5 = _T ? io_initialize_bits_memoryToken : head; // @[PackageRecoveryMemory.scala 97:29 99:10 60:21]
  wire [63:0] _GEN_6 = _T ? io_initialize_bits_memoryToken : tail; // @[PackageRecoveryMemory.scala 100:10 61:21 97:29]
  wire [31:0] _GEN_7 = _T ? io_initialize_bits_sequence : lastSequence; // @[PackageRecoveryMemory.scala 101:18 65:25 97:29]
  wire  _GEN_8 = _T | seeded; // @[PackageRecoveryMemory.scala 102:12 54:23 97:29]
  wire  _T_1 = io_log_ready & io_log_valid; // @[Decoupled.scala 51:35]
  wire  _legal_T_1 = io_log_bits_sequence > base_sequence; // @[PackageRecoveryMemory.scala 106:28]
  wire  _legal_T_2 = io_log_bits_generation == base_generation & _legal_T_1; // @[PackageRecoveryMemory.scala 105:60]
  wire  _legal_T_6 = io_log_bits_address[2:0] == 3'h0; // @[PackageRecoveryMemory.scala 107:33]
  wire  _legal_T_7 = _legal_T_2 & io_log_bits_sequence >= lastSequence & _legal_T_6; // @[PackageRecoveryMemory.scala 106:84]
  wire  _legal_T_10 = tail != 64'hffffffffffffffff; // @[PackageRecoveryMemory.scala 108:12]
  wire  legal = _legal_T_7 & |io_log_bits_mask & _legal_T_10; // @[PackageRecoveryMemory.scala 107:65]
  wire [63:0] _tail_T_1 = tail + 64'h1; // @[PackageRecoveryMemory.scala 111:20]
  wire  _GEN_9 = ~legal | error; // @[PackageRecoveryMemory.scala 109:{19,27} 55:22]
  wire  _GEN_12 = ~legal ? 1'h0 : 1'h1; // @[PackageRecoveryMemory.scala 109:19 110:14 66:20]
  wire [63:0] _GEN_19 = ~legal ? _GEN_6 : _tail_T_1; // @[PackageRecoveryMemory.scala 109:19 111:12]
  wire [31:0] _GEN_20 = ~legal ? _GEN_7 : io_log_bits_sequence; // @[PackageRecoveryMemory.scala 109:19 112:20]
  wire  _GEN_21 = _T_1 ? _GEN_9 : error; // @[PackageRecoveryMemory.scala 104:22 55:22]
  wire [63:0] _GEN_31 = _T_1 ? _GEN_19 : _GEN_6; // @[PackageRecoveryMemory.scala 104:22]
  wire [31:0] _GEN_32 = _T_1 ? _GEN_20 : _GEN_7; // @[PackageRecoveryMemory.scala 104:22]
  wire  _T_4 = io_release_ready & io_release_valid; // @[Decoupled.scala 51:35]
  wire  _legal_T_14 = io_release_bits_memoryToken >= head; // @[PackageRecoveryMemory.scala 118:21]
  wire  _legal_T_15 = io_release_bits_generation == base_generation & io_release_bits_sequence >= base_sequence &
    _legal_T_14; // @[PackageRecoveryMemory.scala 117:81]
  wire  legal_1 = _legal_T_15 & io_release_bits_memoryToken <= tail; // @[PackageRecoveryMemory.scala 118:29]
  wire  _GEN_33 = ~legal_1 | _GEN_21; // @[PackageRecoveryMemory.scala 119:{19,27}]
  wire  _GEN_39 = ~legal_1 ? releasing : 1'h1; // @[PackageRecoveryMemory.scala 119:19 121:17 56:26]
  wire  _GEN_40 = _T_4 ? _GEN_33 : _GEN_21; // @[PackageRecoveryMemory.scala 115:26]
  wire  _GEN_46 = _T_4 ? _GEN_39 : releasing; // @[PackageRecoveryMemory.scala 115:26 56:26]
  wire  _T_10 = journal_generation_front_data != releaseTarget_generation; // @[PackageRecoveryMemory.scala 127:28]
  wire  _T_11 = journal_sequence_front_data > releaseTarget_sequence | _T_10; // @[PackageRecoveryMemory.scala 126:53]
  wire [63:0] _head_T_1 = head + 64'h1; // @[PackageRecoveryMemory.scala 128:35]
  wire  _GEN_47 = _T_11 | _GEN_40; // @[PackageRecoveryMemory.scala 127:{58,66}]
  wire  _T_16 = _io_write_valid_T_4 & (journal_sequence_front_data <= releaseTarget_sequence | _T_10); // @[PackageRecoveryMemory.scala 130:27]
  wire  _GEN_49 = _T_16 | _GEN_40; // @[PackageRecoveryMemory.scala 131:{59,67}]
  wire [31:0] _GEN_51 = _T_16 ? _GEN_1 : releaseTarget_generation; // @[PackageRecoveryMemory.scala 131:59 133:16]
  wire  _GEN_55 = _T_16 & _GEN_46; // @[PackageRecoveryMemory.scala 131:59 134:21]
  wire  _GEN_56 = _T_16 ? 1'h0 : 1'h1; // @[PackageRecoveryMemory.scala 131:59 90:21 135:29]
  wire  _GEN_57 = head != releaseTarget_memoryToken ? _GEN_47 : _GEN_49; // @[PackageRecoveryMemory.scala 125:47]
  wire [31:0] _GEN_60 = head != releaseTarget_memoryToken ? _GEN_1 : _GEN_51; // @[PackageRecoveryMemory.scala 125:47]
  wire  _GEN_65 = head != releaseTarget_memoryToken ? 1'h0 : _GEN_56; // @[PackageRecoveryMemory.scala 125:47 90:21]
  wire  _GEN_66 = releasing & _idle_T_6 ? _GEN_57 : _GEN_40; // @[PackageRecoveryMemory.scala 124:30]
  wire [31:0] _GEN_69 = releasing & _idle_T_6 ? _GEN_60 : _GEN_1; // @[PackageRecoveryMemory.scala 124:30]
  wire  _T_17 = io_restore_ready & io_restore_valid; // @[Decoupled.scala 51:35]
  wire [255:0] _legal_T_17 = {io_restore_bits_checkpoint_sequence,io_restore_bits_checkpoint_generation,
    io_restore_bits_checkpoint_restartPc,io_restore_bits_checkpoint_architecturalToken,
    io_restore_bits_checkpoint_memoryToken}; // @[PackageRecoveryMemory.scala 141:41]
  wire [255:0] _legal_T_18 = {base_sequence,base_generation,base_restartPc,base_architecturalToken,base_memoryToken}; // @[PackageRecoveryMemory.scala 141:57]
  wire  _legal_T_21 = io_restore_bits_failedSequence > io_restore_bits_checkpoint_sequence; // @[PackageRecoveryMemory.scala 142:24]
  wire  _legal_T_22 = io_lock & _legal_T_17 == _legal_T_18 & _legal_T_21; // @[PackageRecoveryMemory.scala 141:64]
  wire  _legal_T_23 = io_restore_bits_checkpoint_generation != 32'hffffffff; // @[PackageRecoveryMemory.scala 143:31]
  wire  _legal_T_24 = _legal_T_22 & _legal_T_23; // @[PackageRecoveryMemory.scala 142:48]
  wire [31:0] _legal_T_26 = io_restore_bits_checkpoint_generation + 32'h1; // @[PackageRecoveryMemory.scala 144:56]
  wire  _legal_T_27 = io_restore_bits_recoveryGeneration == _legal_T_26; // @[PackageRecoveryMemory.scala 144:28]
  wire  legal_2 = _legal_T_24 & _legal_T_27; // @[PackageRecoveryMemory.scala 143:49]
  wire  _GEN_75 = ~legal_2 | _GEN_66; // @[PackageRecoveryMemory.scala 145:{19,27}]
  wire  _GEN_83 = ~legal_2 ? restoring : 1'h1; // @[PackageRecoveryMemory.scala 145:19 147:17 57:26]
  wire  _GEN_84 = ~legal_2 & sent; // @[PackageRecoveryMemory.scala 145:19 148:12 59:21]
  wire  _GEN_85 = _T_17 ? _GEN_75 : _GEN_66; // @[PackageRecoveryMemory.scala 139:26]
  wire  _GEN_93 = _T_17 ? _GEN_83 : restoring; // @[PackageRecoveryMemory.scala 139:26 57:26]
  wire  _GEN_94 = _T_17 ? _GEN_84 : sent; // @[PackageRecoveryMemory.scala 139:26 59:21]
  wire  _T_22 = ~io_writeCompleted_valid; // @[PackageRecoveryMemory.scala 154:13]
  wire  _GEN_96 = ~io_writeCompleted_valid | pendingRebase; // @[PackageRecoveryMemory.scala 154:39 156:23 58:30]
  wire  _T_24 = journal_generation_newest_data != command_checkpoint_generation; // @[PackageRecoveryMemory.scala 160:27]
  wire  _T_25 = journal_sequence_newest_data <= command_checkpoint_sequence | _T_24; // @[PackageRecoveryMemory.scala 159:64]
  wire  _GEN_98 = _T_25 | _GEN_85; // @[PackageRecoveryMemory.scala 160:{62,70}]
  wire  _GEN_100 = tail == head ? _GEN_96 : pendingRebase; // @[PackageRecoveryMemory.scala 152:26 58:30]
  wire  _GEN_101 = tail == head & _T_22; // @[PackageRecoveryMemory.scala 152:26 92:21]
  wire  _GEN_102 = tail == head ? _GEN_85 : _GEN_98; // @[PackageRecoveryMemory.scala 152:26]
  wire  _GEN_104 = restoring & _idle_T_6 ? _GEN_100 : pendingRebase; // @[PackageRecoveryMemory.scala 151:30 58:30]
  wire  _GEN_106 = restoring & _idle_T_6 ? _GEN_102 : _GEN_85; // @[PackageRecoveryMemory.scala 151:30]
  wire  _T_26 = io_write_ready & io_write_valid; // @[Decoupled.scala 51:35]
  wire  _GEN_107 = _T_26 | _GEN_94; // @[PackageRecoveryMemory.scala 162:{24,31}]
  wire [7:0] _byteMask_T_2 = journal_mask_newest_data[7] ? 8'hff : 8'h0; // @[Bitwise.scala 77:12]
  wire [7:0] _byteMask_T_5 = journal_mask_newest_data[6] ? 8'hff : 8'h0; // @[Bitwise.scala 77:12]
  wire [7:0] _byteMask_T_8 = journal_mask_newest_data[5] ? 8'hff : 8'h0; // @[Bitwise.scala 77:12]
  wire [7:0] _byteMask_T_11 = journal_mask_newest_data[4] ? 8'hff : 8'h0; // @[Bitwise.scala 77:12]
  wire [7:0] _byteMask_T_14 = journal_mask_newest_data[3] ? 8'hff : 8'h0; // @[Bitwise.scala 77:12]
  wire [7:0] _byteMask_T_17 = journal_mask_newest_data[2] ? 8'hff : 8'h0; // @[Bitwise.scala 77:12]
  wire [7:0] _byteMask_T_20 = journal_mask_newest_data[1] ? 8'hff : 8'h0; // @[Bitwise.scala 77:12]
  wire [7:0] _byteMask_T_23 = journal_mask_newest_data[0] ? 8'hff : 8'h0; // @[Bitwise.scala 77:12]
  wire [63:0] byteMask = {_byteMask_T_2,_byteMask_T_5,_byteMask_T_8,_byteMask_T_11,_byteMask_T_14,_byteMask_T_17,
    _byteMask_T_20,_byteMask_T_23}; // @[Cat.scala 33:92]
  wire [319:0] _legal_T_33 = {io_writeCompleted_bits_command_checkpoint_sequence,
    io_writeCompleted_bits_command_checkpoint_generation,io_writeCompleted_bits_command_checkpoint_restartPc,
    io_writeCompleted_bits_command_checkpoint_architecturalToken,io_writeCompleted_bits_command_checkpoint_memoryToken,
    io_writeCompleted_bits_command_failedSequence,io_writeCompleted_bits_command_recoveryGeneration}; // @[PackageRecoveryMemory.scala 167:17]
  wire [319:0] _legal_T_34 = {command_checkpoint_sequence,command_checkpoint_generation,command_checkpoint_restartPc,
    command_checkpoint_architecturalToken,command_checkpoint_memoryToken,command_failedSequence,
    command_recoveryGeneration}; // @[PackageRecoveryMemory.scala 167:36]
  wire  _legal_T_35 = _legal_T_33 == _legal_T_34; // @[PackageRecoveryMemory.scala 167:24]
  wire  _legal_T_36 = restoring & _io_write_valid_T_4 & (sent | _T_26) & _legal_T_35; // @[PackageRecoveryMemory.scala 166:71]
  wire  _legal_T_41 = io_writeCompleted_bits_address == journal_address_newest_data; // @[PackageRecoveryMemory.scala 168:17]
  wire  _legal_T_42 = _legal_T_36 & io_writeCompleted_bits_cursor == _newest_T_1 & _legal_T_41; // @[PackageRecoveryMemory.scala 167:70]
  wire [63:0] _legal_T_45 = io_writeCompleted_bits_data & byteMask; // @[PackageRecoveryMemory.scala 169:15]
  wire [63:0] _legal_T_46 = journal_previousData_newest_data & byteMask; // @[PackageRecoveryMemory.scala 169:52]
  wire  _legal_T_47 = _legal_T_45 == _legal_T_46; // @[PackageRecoveryMemory.scala 169:27]
  wire  legal_3 = _legal_T_42 & io_writeCompleted_bits_mask == journal_mask_newest_data & _legal_T_47; // @[PackageRecoveryMemory.scala 168:62]
  wire  _GEN_108 = ~legal_3 | _GEN_106; // @[PackageRecoveryMemory.scala 170:{19,27}]
  wire  _GEN_110 = ~legal_3 & _GEN_107; // @[PackageRecoveryMemory.scala 170:19 172:12]
  wire  _GEN_111 = io_writeCompleted_valid ? _GEN_108 : _GEN_106; // @[PackageRecoveryMemory.scala 163:34]
  wire  _T_28 = io_rebase_ready & io_rebase_valid; // @[Decoupled.scala 51:35]
  wire [319:0] _legal_T_48 = {io_rebase_bits_command_checkpoint_sequence,io_rebase_bits_command_checkpoint_generation,
    io_rebase_bits_command_checkpoint_restartPc,io_rebase_bits_command_checkpoint_architecturalToken,
    io_rebase_bits_command_checkpoint_memoryToken,io_rebase_bits_command_failedSequence,
    io_rebase_bits_command_recoveryGeneration}; // @[PackageRecoveryMemory.scala 177:38]
  wire  _legal_T_52 = io_rebase_bits_retiredPc == command_checkpoint_restartPc; // @[PackageRecoveryMemory.scala 178:19]
  wire  _legal_T_53 = io_lock & _legal_T_48 == _legal_T_34 & _legal_T_52; // @[PackageRecoveryMemory.scala 177:64]
  wire  legal_4 = _legal_T_53 & io_rebase_bits_allCheckerTasksDrained; // @[PackageRecoveryMemory.scala 178:52]
  wire  _GEN_114 = ~legal_4 | _GEN_111; // @[PackageRecoveryMemory.scala 179:{19,27}]
  wire  _GEN_117 = ~legal_4 & _GEN_104; // @[PackageRecoveryMemory.scala 179:19 182:21]
  assign journal_sequence_front_en = 1'h1;
  assign journal_sequence_front_addr = head[5:0];
  assign journal_sequence_front_data = journal_sequence[journal_sequence_front_addr]; // @[PackageRecoveryMemory.scala 66:20]
  assign journal_sequence_newest_en = 1'h1;
  assign journal_sequence_newest_addr = _newest_T_1[5:0];
  assign journal_sequence_newest_data = journal_sequence[journal_sequence_newest_addr]; // @[PackageRecoveryMemory.scala 66:20]
  assign journal_sequence_MPORT_data = io_log_bits_sequence;
  assign journal_sequence_MPORT_addr = tail[5:0];
  assign journal_sequence_MPORT_mask = 1'h1;
  assign journal_sequence_MPORT_en = _T_1 & _GEN_12;
  assign journal_generation_front_en = 1'h1;
  assign journal_generation_front_addr = head[5:0];
  assign journal_generation_front_data = journal_generation[journal_generation_front_addr]; // @[PackageRecoveryMemory.scala 66:20]
  assign journal_generation_newest_en = 1'h1;
  assign journal_generation_newest_addr = _newest_T_1[5:0];
  assign journal_generation_newest_data = journal_generation[journal_generation_newest_addr]; // @[PackageRecoveryMemory.scala 66:20]
  assign journal_generation_MPORT_data = io_log_bits_generation;
  assign journal_generation_MPORT_addr = tail[5:0];
  assign journal_generation_MPORT_mask = 1'h1;
  assign journal_generation_MPORT_en = _T_1 & _GEN_12;
  assign journal_address_front_en = 1'h1;
  assign journal_address_front_addr = head[5:0];
  assign journal_address_front_data = journal_address[journal_address_front_addr]; // @[PackageRecoveryMemory.scala 66:20]
  assign journal_address_newest_en = 1'h1;
  assign journal_address_newest_addr = _newest_T_1[5:0];
  assign journal_address_newest_data = journal_address[journal_address_newest_addr]; // @[PackageRecoveryMemory.scala 66:20]
  assign journal_address_MPORT_data = io_log_bits_address;
  assign journal_address_MPORT_addr = tail[5:0];
  assign journal_address_MPORT_mask = 1'h1;
  assign journal_address_MPORT_en = _T_1 & _GEN_12;
  assign journal_previousData_front_en = 1'h1;
  assign journal_previousData_front_addr = head[5:0];
  assign journal_previousData_front_data = journal_previousData[journal_previousData_front_addr]; // @[PackageRecoveryMemory.scala 66:20]
  assign journal_previousData_newest_en = 1'h1;
  assign journal_previousData_newest_addr = _newest_T_1[5:0];
  assign journal_previousData_newest_data = journal_previousData[journal_previousData_newest_addr]; // @[PackageRecoveryMemory.scala 66:20]
  assign journal_previousData_MPORT_data = io_log_bits_previousData;
  assign journal_previousData_MPORT_addr = tail[5:0];
  assign journal_previousData_MPORT_mask = 1'h1;
  assign journal_previousData_MPORT_en = _T_1 & _GEN_12;
  assign journal_mask_front_en = 1'h1;
  assign journal_mask_front_addr = head[5:0];
  assign journal_mask_front_data = journal_mask[journal_mask_front_addr]; // @[PackageRecoveryMemory.scala 66:20]
  assign journal_mask_newest_en = 1'h1;
  assign journal_mask_newest_addr = _newest_T_1[5:0];
  assign journal_mask_newest_data = journal_mask[journal_mask_newest_addr]; // @[PackageRecoveryMemory.scala 66:20]
  assign journal_mask_MPORT_data = io_log_bits_mask;
  assign journal_mask_MPORT_addr = tail[5:0];
  assign journal_mask_MPORT_mask = 1'h1;
  assign journal_mask_MPORT_en = _T_1 & _GEN_12;
  assign io_initialize_ready = ~seeded & _idle_T_6; // @[PackageRecoveryMemory.scala 76:34]
  assign io_log_ready = idle & ~io_lock & ~io_release_valid & ~io_restore_valid & _io_log_ready_T_8; // @[PackageRecoveryMemory.scala 77:78]
  assign io_nextToken = tail; // @[PackageRecoveryMemory.scala 72:16]
  assign io_occupancy = _io_occupancy_T_1[6:0]; // @[PackageRecoveryMemory.scala 73:16]
  assign io_release_ready = _io_log_ready_T_1 & _io_log_ready_T_4; // @[PackageRecoveryMemory.scala 79:40]
  assign io_released_valid = releasing & _idle_T_6 & _GEN_65; // @[PackageRecoveryMemory.scala 124:30 90:21]
  assign io_released_bits_sequence = releaseTarget_sequence; // @[PackageRecoveryMemory.scala 91:20]
  assign io_released_bits_generation = releaseTarget_generation; // @[PackageRecoveryMemory.scala 91:20]
  assign io_released_bits_restartPc = releaseTarget_restartPc; // @[PackageRecoveryMemory.scala 91:20]
  assign io_released_bits_architecturalToken = releaseTarget_architecturalToken; // @[PackageRecoveryMemory.scala 91:20]
  assign io_released_bits_memoryToken = releaseTarget_memoryToken; // @[PackageRecoveryMemory.scala 91:20]
  assign io_restore_ready = seeded & ~releasing & ~restoring & ~pendingRebase & ~error; // @[PackageRecoveryMemory.scala 70:67]
  assign io_write_valid = _io_write_valid_T_7 & _io_write_valid_T_8; // @[PackageRecoveryMemory.scala 83:51]
  assign io_write_bits_command_checkpoint_sequence = command_checkpoint_sequence; // @[PackageRecoveryMemory.scala 85:25]
  assign io_write_bits_command_checkpoint_generation = command_checkpoint_generation; // @[PackageRecoveryMemory.scala 85:25]
  assign io_write_bits_command_checkpoint_restartPc = command_checkpoint_restartPc; // @[PackageRecoveryMemory.scala 85:25]
  assign io_write_bits_command_checkpoint_architecturalToken = command_checkpoint_architecturalToken; // @[PackageRecoveryMemory.scala 85:25]
  assign io_write_bits_command_checkpoint_memoryToken = command_checkpoint_memoryToken; // @[PackageRecoveryMemory.scala 85:25]
  assign io_write_bits_command_failedSequence = command_failedSequence; // @[PackageRecoveryMemory.scala 85:25]
  assign io_write_bits_command_recoveryGeneration = command_recoveryGeneration; // @[PackageRecoveryMemory.scala 85:25]
  assign io_write_bits_cursor = tail - 64'h1; // @[PackageRecoveryMemory.scala 86:32]
  assign io_write_bits_address = journal_address_newest_data; // @[PackageRecoveryMemory.scala 87:25]
  assign io_write_bits_data = journal_previousData_newest_data; // @[PackageRecoveryMemory.scala 88:22]
  assign io_write_bits_mask = journal_mask_newest_data; // @[PackageRecoveryMemory.scala 89:22]
  assign io_restored_valid = restoring & _idle_T_6 & _GEN_101; // @[PackageRecoveryMemory.scala 151:30 92:21]
  assign io_restored_bits_command_checkpoint_sequence = command_checkpoint_sequence; // @[PackageRecoveryMemory.scala 93:28]
  assign io_restored_bits_command_checkpoint_generation = command_checkpoint_generation; // @[PackageRecoveryMemory.scala 93:28]
  assign io_restored_bits_command_checkpoint_restartPc = command_checkpoint_restartPc; // @[PackageRecoveryMemory.scala 93:28]
  assign io_restored_bits_command_checkpoint_architecturalToken = command_checkpoint_architecturalToken; // @[PackageRecoveryMemory.scala 93:28]
  assign io_restored_bits_command_checkpoint_memoryToken = command_checkpoint_memoryToken; // @[PackageRecoveryMemory.scala 93:28]
  assign io_restored_bits_command_failedSequence = command_failedSequence; // @[PackageRecoveryMemory.scala 93:28]
  assign io_restored_bits_command_recoveryGeneration = command_recoveryGeneration; // @[PackageRecoveryMemory.scala 93:28]
  assign io_restored_bits_retiredPc = 64'h0; // @[PackageRecoveryMemory.scala 94:30]
  assign io_restored_bits_allCheckerTasksDrained = 1'h0; // @[PackageRecoveryMemory.scala 95:43]
  assign io_rebase_ready = pendingRebase & _idle_T_6; // @[PackageRecoveryMemory.scala 81:36]
  assign io_protocolError = error; // @[PackageRecoveryMemory.scala 74:20]
  assign io_active = releasing | restoring | pendingRebase; // @[PackageRecoveryMemory.scala 75:39]
  always @(posedge clock) begin
    if (journal_sequence_MPORT_en & journal_sequence_MPORT_mask) begin
      journal_sequence[journal_sequence_MPORT_addr] <= journal_sequence_MPORT_data; // @[PackageRecoveryMemory.scala 66:20]
    end
    if (journal_generation_MPORT_en & journal_generation_MPORT_mask) begin
      journal_generation[journal_generation_MPORT_addr] <= journal_generation_MPORT_data; // @[PackageRecoveryMemory.scala 66:20]
    end
    if (journal_address_MPORT_en & journal_address_MPORT_mask) begin
      journal_address[journal_address_MPORT_addr] <= journal_address_MPORT_data; // @[PackageRecoveryMemory.scala 66:20]
    end
    if (journal_previousData_MPORT_en & journal_previousData_MPORT_mask) begin
      journal_previousData[journal_previousData_MPORT_addr] <= journal_previousData_MPORT_data; // @[PackageRecoveryMemory.scala 66:20]
    end
    if (journal_mask_MPORT_en & journal_mask_MPORT_mask) begin
      journal_mask[journal_mask_MPORT_addr] <= journal_mask_MPORT_data; // @[PackageRecoveryMemory.scala 66:20]
    end
    if (reset) begin // @[PackageRecoveryMemory.scala 54:23]
      seeded <= 1'h0; // @[PackageRecoveryMemory.scala 54:23]
    end else begin
      seeded <= _GEN_8;
    end
    if (reset) begin // @[PackageRecoveryMemory.scala 55:22]
      error <= 1'h0; // @[PackageRecoveryMemory.scala 55:22]
    end else if (_T_28) begin // @[PackageRecoveryMemory.scala 175:25]
      error <= _GEN_114;
    end else if (io_writeCompleted_valid) begin // @[PackageRecoveryMemory.scala 163:34]
      error <= _GEN_108;
    end else if (restoring & _idle_T_6) begin // @[PackageRecoveryMemory.scala 151:30]
      error <= _GEN_102;
    end else begin
      error <= _GEN_85;
    end
    if (reset) begin // @[PackageRecoveryMemory.scala 56:26]
      releasing <= 1'h0; // @[PackageRecoveryMemory.scala 56:26]
    end else if (releasing & _idle_T_6) begin // @[PackageRecoveryMemory.scala 124:30]
      if (head != releaseTarget_memoryToken) begin // @[PackageRecoveryMemory.scala 125:47]
        releasing <= _GEN_46;
      end else begin
        releasing <= _GEN_55;
      end
    end else begin
      releasing <= _GEN_46;
    end
    if (reset) begin // @[PackageRecoveryMemory.scala 57:26]
      restoring <= 1'h0; // @[PackageRecoveryMemory.scala 57:26]
    end else if (restoring & _idle_T_6) begin // @[PackageRecoveryMemory.scala 151:30]
      if (tail == head) begin // @[PackageRecoveryMemory.scala 152:26]
        if (~io_writeCompleted_valid) begin // @[PackageRecoveryMemory.scala 154:39]
          restoring <= 1'h0; // @[PackageRecoveryMemory.scala 155:19]
        end else begin
          restoring <= _GEN_93;
        end
      end else begin
        restoring <= _GEN_93;
      end
    end else begin
      restoring <= _GEN_93;
    end
    if (reset) begin // @[PackageRecoveryMemory.scala 58:30]
      pendingRebase <= 1'h0; // @[PackageRecoveryMemory.scala 58:30]
    end else if (_T_28) begin // @[PackageRecoveryMemory.scala 175:25]
      pendingRebase <= _GEN_117;
    end else if (restoring & _idle_T_6) begin // @[PackageRecoveryMemory.scala 151:30]
      if (tail == head) begin // @[PackageRecoveryMemory.scala 152:26]
        pendingRebase <= _GEN_96;
      end
    end
    if (reset) begin // @[PackageRecoveryMemory.scala 59:21]
      sent <= 1'h0; // @[PackageRecoveryMemory.scala 59:21]
    end else if (io_writeCompleted_valid) begin // @[PackageRecoveryMemory.scala 163:34]
      sent <= _GEN_110;
    end else begin
      sent <= _GEN_107;
    end
    if (reset) begin // @[PackageRecoveryMemory.scala 60:21]
      head <= 64'h0; // @[PackageRecoveryMemory.scala 60:21]
    end else if (releasing & _idle_T_6) begin // @[PackageRecoveryMemory.scala 124:30]
      if (head != releaseTarget_memoryToken) begin // @[PackageRecoveryMemory.scala 125:47]
        if (_T_11) begin // @[PackageRecoveryMemory.scala 127:58]
          head <= _GEN_5;
        end else begin
          head <= _head_T_1; // @[PackageRecoveryMemory.scala 128:27]
        end
      end else begin
        head <= _GEN_5;
      end
    end else begin
      head <= _GEN_5;
    end
    if (reset) begin // @[PackageRecoveryMemory.scala 61:21]
      tail <= 64'h0; // @[PackageRecoveryMemory.scala 61:21]
    end else if (io_writeCompleted_valid) begin // @[PackageRecoveryMemory.scala 163:34]
      if (~legal_3) begin // @[PackageRecoveryMemory.scala 170:19]
        tail <= _GEN_31;
      end else begin
        tail <= _newest_T_1; // @[PackageRecoveryMemory.scala 171:12]
      end
    end else begin
      tail <= _GEN_31;
    end
    if (releasing & _idle_T_6) begin // @[PackageRecoveryMemory.scala 124:30]
      if (head != releaseTarget_memoryToken) begin // @[PackageRecoveryMemory.scala 125:47]
        base_sequence <= _GEN_0;
      end else if (_T_16) begin // @[PackageRecoveryMemory.scala 131:59]
        base_sequence <= _GEN_0;
      end else begin
        base_sequence <= releaseTarget_sequence; // @[PackageRecoveryMemory.scala 133:16]
      end
    end else begin
      base_sequence <= _GEN_0;
    end
    if (_T_28) begin // @[PackageRecoveryMemory.scala 175:25]
      if (~legal_4) begin // @[PackageRecoveryMemory.scala 179:19]
        base_generation <= _GEN_69;
      end else begin
        base_generation <= command_recoveryGeneration; // @[PackageRecoveryMemory.scala 180:23]
      end
    end else begin
      base_generation <= _GEN_69;
    end
    if (releasing & _idle_T_6) begin // @[PackageRecoveryMemory.scala 124:30]
      if (head != releaseTarget_memoryToken) begin // @[PackageRecoveryMemory.scala 125:47]
        base_restartPc <= _GEN_2;
      end else if (_T_16) begin // @[PackageRecoveryMemory.scala 131:59]
        base_restartPc <= _GEN_2;
      end else begin
        base_restartPc <= releaseTarget_restartPc; // @[PackageRecoveryMemory.scala 133:16]
      end
    end else begin
      base_restartPc <= _GEN_2;
    end
    if (releasing & _idle_T_6) begin // @[PackageRecoveryMemory.scala 124:30]
      if (head != releaseTarget_memoryToken) begin // @[PackageRecoveryMemory.scala 125:47]
        base_architecturalToken <= _GEN_3;
      end else if (_T_16) begin // @[PackageRecoveryMemory.scala 131:59]
        base_architecturalToken <= _GEN_3;
      end else begin
        base_architecturalToken <= releaseTarget_architecturalToken; // @[PackageRecoveryMemory.scala 133:16]
      end
    end else begin
      base_architecturalToken <= _GEN_3;
    end
    if (releasing & _idle_T_6) begin // @[PackageRecoveryMemory.scala 124:30]
      if (head != releaseTarget_memoryToken) begin // @[PackageRecoveryMemory.scala 125:47]
        base_memoryToken <= _GEN_4;
      end else if (_T_16) begin // @[PackageRecoveryMemory.scala 131:59]
        base_memoryToken <= _GEN_4;
      end else begin
        base_memoryToken <= releaseTarget_memoryToken; // @[PackageRecoveryMemory.scala 133:16]
      end
    end else begin
      base_memoryToken <= _GEN_4;
    end
    if (_T_4) begin // @[PackageRecoveryMemory.scala 115:26]
      if (!(~legal_1)) begin // @[PackageRecoveryMemory.scala 119:19]
        releaseTarget_sequence <= io_release_bits_sequence; // @[PackageRecoveryMemory.scala 120:21]
      end
    end
    if (_T_4) begin // @[PackageRecoveryMemory.scala 115:26]
      if (!(~legal_1)) begin // @[PackageRecoveryMemory.scala 119:19]
        releaseTarget_generation <= io_release_bits_generation; // @[PackageRecoveryMemory.scala 120:21]
      end
    end
    if (_T_4) begin // @[PackageRecoveryMemory.scala 115:26]
      if (!(~legal_1)) begin // @[PackageRecoveryMemory.scala 119:19]
        releaseTarget_restartPc <= io_release_bits_restartPc; // @[PackageRecoveryMemory.scala 120:21]
      end
    end
    if (_T_4) begin // @[PackageRecoveryMemory.scala 115:26]
      if (!(~legal_1)) begin // @[PackageRecoveryMemory.scala 119:19]
        releaseTarget_architecturalToken <= io_release_bits_architecturalToken; // @[PackageRecoveryMemory.scala 120:21]
      end
    end
    if (_T_4) begin // @[PackageRecoveryMemory.scala 115:26]
      if (!(~legal_1)) begin // @[PackageRecoveryMemory.scala 119:19]
        releaseTarget_memoryToken <= io_release_bits_memoryToken; // @[PackageRecoveryMemory.scala 120:21]
      end
    end
    if (_T_17) begin // @[PackageRecoveryMemory.scala 139:26]
      if (!(~legal_2)) begin // @[PackageRecoveryMemory.scala 145:19]
        command_checkpoint_sequence <= io_restore_bits_checkpoint_sequence; // @[PackageRecoveryMemory.scala 146:15]
      end
    end
    if (_T_17) begin // @[PackageRecoveryMemory.scala 139:26]
      if (!(~legal_2)) begin // @[PackageRecoveryMemory.scala 145:19]
        command_checkpoint_generation <= io_restore_bits_checkpoint_generation; // @[PackageRecoveryMemory.scala 146:15]
      end
    end
    if (_T_17) begin // @[PackageRecoveryMemory.scala 139:26]
      if (!(~legal_2)) begin // @[PackageRecoveryMemory.scala 145:19]
        command_checkpoint_restartPc <= io_restore_bits_checkpoint_restartPc; // @[PackageRecoveryMemory.scala 146:15]
      end
    end
    if (_T_17) begin // @[PackageRecoveryMemory.scala 139:26]
      if (!(~legal_2)) begin // @[PackageRecoveryMemory.scala 145:19]
        command_checkpoint_architecturalToken <= io_restore_bits_checkpoint_architecturalToken; // @[PackageRecoveryMemory.scala 146:15]
      end
    end
    if (_T_17) begin // @[PackageRecoveryMemory.scala 139:26]
      if (!(~legal_2)) begin // @[PackageRecoveryMemory.scala 145:19]
        command_checkpoint_memoryToken <= io_restore_bits_checkpoint_memoryToken; // @[PackageRecoveryMemory.scala 146:15]
      end
    end
    if (_T_17) begin // @[PackageRecoveryMemory.scala 139:26]
      if (!(~legal_2)) begin // @[PackageRecoveryMemory.scala 145:19]
        command_failedSequence <= io_restore_bits_failedSequence; // @[PackageRecoveryMemory.scala 146:15]
      end
    end
    if (_T_17) begin // @[PackageRecoveryMemory.scala 139:26]
      if (!(~legal_2)) begin // @[PackageRecoveryMemory.scala 145:19]
        command_recoveryGeneration <= io_restore_bits_recoveryGeneration; // @[PackageRecoveryMemory.scala 146:15]
      end
    end
    if (_T_28) begin // @[PackageRecoveryMemory.scala 175:25]
      if (~legal_4) begin // @[PackageRecoveryMemory.scala 179:19]
        lastSequence <= _GEN_32;
      end else begin
        lastSequence <= command_checkpoint_sequence; // @[PackageRecoveryMemory.scala 181:20]
      end
    end else begin
      lastSequence <= _GEN_32;
    end
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (~reset & ~(tail >= head & _io_occupancy_T_1 <= 64'h40)) begin
          $fwrite(32'h80000002,
            "Assertion failed\n    at PackageRecoveryMemory.scala:185 assert(tail >= head && tail - head <= entries.U)\n"
            ); // @[PackageRecoveryMemory.scala 185:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (~reset & ~(tail >= head & _io_occupancy_T_1 <= 64'h40)) begin
          $fatal; // @[PackageRecoveryMemory.scala 185:9]
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
`ifdef RANDOMIZE_MEM_INIT
  _RAND_0 = {1{`RANDOM}};
  for (initvar = 0; initvar < 64; initvar = initvar+1)
    journal_sequence[initvar] = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  for (initvar = 0; initvar < 64; initvar = initvar+1)
    journal_generation[initvar] = _RAND_1[31:0];
  _RAND_2 = {2{`RANDOM}};
  for (initvar = 0; initvar < 64; initvar = initvar+1)
    journal_address[initvar] = _RAND_2[63:0];
  _RAND_3 = {2{`RANDOM}};
  for (initvar = 0; initvar < 64; initvar = initvar+1)
    journal_previousData[initvar] = _RAND_3[63:0];
  _RAND_4 = {1{`RANDOM}};
  for (initvar = 0; initvar < 64; initvar = initvar+1)
    journal_mask[initvar] = _RAND_4[7:0];
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  _RAND_5 = {1{`RANDOM}};
  seeded = _RAND_5[0:0];
  _RAND_6 = {1{`RANDOM}};
  error = _RAND_6[0:0];
  _RAND_7 = {1{`RANDOM}};
  releasing = _RAND_7[0:0];
  _RAND_8 = {1{`RANDOM}};
  restoring = _RAND_8[0:0];
  _RAND_9 = {1{`RANDOM}};
  pendingRebase = _RAND_9[0:0];
  _RAND_10 = {1{`RANDOM}};
  sent = _RAND_10[0:0];
  _RAND_11 = {2{`RANDOM}};
  head = _RAND_11[63:0];
  _RAND_12 = {2{`RANDOM}};
  tail = _RAND_12[63:0];
  _RAND_13 = {1{`RANDOM}};
  base_sequence = _RAND_13[31:0];
  _RAND_14 = {1{`RANDOM}};
  base_generation = _RAND_14[31:0];
  _RAND_15 = {2{`RANDOM}};
  base_restartPc = _RAND_15[63:0];
  _RAND_16 = {2{`RANDOM}};
  base_architecturalToken = _RAND_16[63:0];
  _RAND_17 = {2{`RANDOM}};
  base_memoryToken = _RAND_17[63:0];
  _RAND_18 = {1{`RANDOM}};
  releaseTarget_sequence = _RAND_18[31:0];
  _RAND_19 = {1{`RANDOM}};
  releaseTarget_generation = _RAND_19[31:0];
  _RAND_20 = {2{`RANDOM}};
  releaseTarget_restartPc = _RAND_20[63:0];
  _RAND_21 = {2{`RANDOM}};
  releaseTarget_architecturalToken = _RAND_21[63:0];
  _RAND_22 = {2{`RANDOM}};
  releaseTarget_memoryToken = _RAND_22[63:0];
  _RAND_23 = {1{`RANDOM}};
  command_checkpoint_sequence = _RAND_23[31:0];
  _RAND_24 = {1{`RANDOM}};
  command_checkpoint_generation = _RAND_24[31:0];
  _RAND_25 = {2{`RANDOM}};
  command_checkpoint_restartPc = _RAND_25[63:0];
  _RAND_26 = {2{`RANDOM}};
  command_checkpoint_architecturalToken = _RAND_26[63:0];
  _RAND_27 = {2{`RANDOM}};
  command_checkpoint_memoryToken = _RAND_27[63:0];
  _RAND_28 = {1{`RANDOM}};
  command_failedSequence = _RAND_28[31:0];
  _RAND_29 = {1{`RANDOM}};
  command_recoveryGeneration = _RAND_29[31:0];
  _RAND_30 = {1{`RANDOM}};
  lastSequence = _RAND_30[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
