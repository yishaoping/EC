module GHBarrierBucketBank(
  input          clock,
  input          reset,
  output [160:0] io_observe_0,
  output [160:0] io_observe_1,
  output [160:0] io_observe_2,
  output [160:0] io_observe_3,
  output [160:0] io_observe_4,
  output [160:0] io_observe_5,
  output [160:0] io_observe_6,
  output [160:0] io_observe_7,
  input  [7:0]   io_base,
  input          io_resetStats,
  input          io_event_valid,
  input  [31:0]  io_event_bits,
  input  [31:0]  io_safeWatermark,
  input  [63:0]  io_currentCycle,
  output [66:0]  io_resolvedCount,
  output [66:0]  io_resolvedRequest,
  output         io_eventAvailable,
  output         io_countOverflow,
  output         io_cycleOverflow
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
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
  reg [63:0] _RAND_16;
  reg [63:0] _RAND_17;
  reg [63:0] _RAND_18;
  reg [63:0] _RAND_19;
  reg [63:0] _RAND_20;
  reg [63:0] _RAND_21;
  reg [63:0] _RAND_22;
  reg [63:0] _RAND_23;
  reg [63:0] _RAND_24;
  reg [63:0] _RAND_25;
  reg [63:0] _RAND_26;
  reg [63:0] _RAND_27;
  reg [63:0] _RAND_28;
  reg [63:0] _RAND_29;
  reg [63:0] _RAND_30;
  reg [63:0] _RAND_31;
`endif // RANDOMIZE_REG_INIT
  reg  buckets_valid_0; // @[BankProof.scala 28:24]
  reg  buckets_valid_1; // @[BankProof.scala 28:24]
  reg  buckets_valid_2; // @[BankProof.scala 28:24]
  reg  buckets_valid_3; // @[BankProof.scala 28:24]
  reg  buckets_valid_4; // @[BankProof.scala 28:24]
  reg  buckets_valid_5; // @[BankProof.scala 28:24]
  reg  buckets_valid_6; // @[BankProof.scala 28:24]
  reg  buckets_valid_7; // @[BankProof.scala 28:24]
  reg [31:0] buckets_seq_0; // @[BankProof.scala 28:24]
  reg [31:0] buckets_seq_1; // @[BankProof.scala 28:24]
  reg [31:0] buckets_seq_2; // @[BankProof.scala 28:24]
  reg [31:0] buckets_seq_3; // @[BankProof.scala 28:24]
  reg [31:0] buckets_seq_4; // @[BankProof.scala 28:24]
  reg [31:0] buckets_seq_5; // @[BankProof.scala 28:24]
  reg [31:0] buckets_seq_6; // @[BankProof.scala 28:24]
  reg [31:0] buckets_seq_7; // @[BankProof.scala 28:24]
  reg [63:0] buckets_count_0; // @[BankProof.scala 28:24]
  reg [63:0] buckets_count_1; // @[BankProof.scala 28:24]
  reg [63:0] buckets_count_2; // @[BankProof.scala 28:24]
  reg [63:0] buckets_count_3; // @[BankProof.scala 28:24]
  reg [63:0] buckets_count_4; // @[BankProof.scala 28:24]
  reg [63:0] buckets_count_5; // @[BankProof.scala 28:24]
  reg [63:0] buckets_count_6; // @[BankProof.scala 28:24]
  reg [63:0] buckets_count_7; // @[BankProof.scala 28:24]
  reg [63:0] buckets_requestCycleSum_0; // @[BankProof.scala 28:24]
  reg [63:0] buckets_requestCycleSum_1; // @[BankProof.scala 28:24]
  reg [63:0] buckets_requestCycleSum_2; // @[BankProof.scala 28:24]
  reg [63:0] buckets_requestCycleSum_3; // @[BankProof.scala 28:24]
  reg [63:0] buckets_requestCycleSum_4; // @[BankProof.scala 28:24]
  reg [63:0] buckets_requestCycleSum_5; // @[BankProof.scala 28:24]
  reg [63:0] buckets_requestCycleSum_6; // @[BankProof.scala 28:24]
  reg [63:0] buckets_requestCycleSum_7; // @[BankProof.scala 28:24]
  wire  eventNeedsBucket = io_event_valid & io_event_bits > io_safeWatermark; // @[BankProof.scala 33:41]
  wire [8:0] _key_T = {{1'd0}, io_base}; // @[BankProof.scala 35:24]
  wire [7:0] key = _key_T[7:0]; // @[BankProof.scala 35:24]
  wire  selected = io_event_bits[7:0] == key; // @[BankProof.scala 36:52]
  wire  resolving_0 = buckets_valid_0 & buckets_seq_0 <= io_safeWatermark; // @[BankProof.scala 37:38]
  wire  _canAccept_T_1 = ~buckets_valid_0 | resolving_0; // @[BankProof.scala 38:39]
  wire  canAccept = ~buckets_valid_0 | resolving_0 | buckets_seq_0 == io_event_bits; // @[BankProof.scala 38:55]
  wire  accepted = eventNeedsBucket & selected & canAccept; // @[BankProof.scala 39:49]
  wire  available_0 = selected & canAccept; // @[BankProof.scala 40:30]
  wire  _countOverflow_0_T_2 = accepted & buckets_valid_0 & ~resolving_0; // @[BankProof.scala 41:54]
  wire  _countOverflow_0_T_4 = buckets_count_0 == 64'hffffffffffffffff; // @[BankProof.scala 42:24]
  wire  countOverflow_0 = accepted & buckets_valid_0 & ~resolving_0 & _countOverflow_0_T_4; // @[BankProof.scala 41:71]
  wire [63:0] _cycleOverflow_0_T_5 = 64'hffffffffffffffff - io_currentCycle; // @[BankProof.scala 44:48]
  wire  _cycleOverflow_0_T_6 = buckets_requestCycleSum_0 > _cycleOverflow_0_T_5; // @[BankProof.scala 44:34]
  wire  cycleOverflow_0 = _countOverflow_0_T_2 & _cycleOverflow_0_T_6; // @[BankProof.scala 43:71]
  wire  _GEN_0 = resolving_0 ? 1'h0 : buckets_valid_0; // @[BankProof.scala 28:24 52:27 53:26]
  wire [63:0] _buckets_count_0_T_1 = buckets_count_0 + 64'h1; // @[BankProof.scala 65:48]
  wire [63:0] _buckets_requestCycleSum_0_T_1 = buckets_requestCycleSum_0 + io_currentCycle; // @[BankProof.scala 66:68]
  wire  _GEN_3 = _canAccept_T_1 | _GEN_0; // @[BankProof.scala 59:50 60:28]
  wire [7:0] key_1 = io_base + 8'h1; // @[BankProof.scala 35:24]
  wire  selected_1 = io_event_bits[7:0] == key_1; // @[BankProof.scala 36:52]
  wire  resolving_1 = buckets_valid_1 & buckets_seq_1 <= io_safeWatermark; // @[BankProof.scala 37:38]
  wire  _canAccept_T_4 = ~buckets_valid_1 | resolving_1; // @[BankProof.scala 38:39]
  wire  canAccept_1 = ~buckets_valid_1 | resolving_1 | buckets_seq_1 == io_event_bits; // @[BankProof.scala 38:55]
  wire  accepted_1 = eventNeedsBucket & selected_1 & canAccept_1; // @[BankProof.scala 39:49]
  wire  available_1 = selected_1 & canAccept_1; // @[BankProof.scala 40:30]
  wire  _countOverflow_1_T_2 = accepted_1 & buckets_valid_1 & ~resolving_1; // @[BankProof.scala 41:54]
  wire  _countOverflow_1_T_4 = buckets_count_1 == 64'hffffffffffffffff; // @[BankProof.scala 42:24]
  wire  countOverflow_1 = accepted_1 & buckets_valid_1 & ~resolving_1 & _countOverflow_1_T_4; // @[BankProof.scala 41:71]
  wire  _cycleOverflow_1_T_6 = buckets_requestCycleSum_1 > _cycleOverflow_0_T_5; // @[BankProof.scala 44:34]
  wire  cycleOverflow_1 = _countOverflow_1_T_2 & _cycleOverflow_1_T_6; // @[BankProof.scala 43:71]
  wire  _GEN_15 = resolving_1 ? 1'h0 : buckets_valid_1; // @[BankProof.scala 28:24 52:27 53:26]
  wire [63:0] _buckets_count_1_T_1 = buckets_count_1 + 64'h1; // @[BankProof.scala 65:48]
  wire [63:0] _buckets_requestCycleSum_1_T_1 = buckets_requestCycleSum_1 + io_currentCycle; // @[BankProof.scala 66:68]
  wire  _GEN_18 = _canAccept_T_4 | _GEN_15; // @[BankProof.scala 59:50 60:28]
  wire [7:0] key_2 = io_base + 8'h2; // @[BankProof.scala 35:24]
  wire  selected_2 = io_event_bits[7:0] == key_2; // @[BankProof.scala 36:52]
  wire  resolving_2 = buckets_valid_2 & buckets_seq_2 <= io_safeWatermark; // @[BankProof.scala 37:38]
  wire  _canAccept_T_7 = ~buckets_valid_2 | resolving_2; // @[BankProof.scala 38:39]
  wire  canAccept_2 = ~buckets_valid_2 | resolving_2 | buckets_seq_2 == io_event_bits; // @[BankProof.scala 38:55]
  wire  accepted_2 = eventNeedsBucket & selected_2 & canAccept_2; // @[BankProof.scala 39:49]
  wire  available_2 = selected_2 & canAccept_2; // @[BankProof.scala 40:30]
  wire  _countOverflow_2_T_2 = accepted_2 & buckets_valid_2 & ~resolving_2; // @[BankProof.scala 41:54]
  wire  _countOverflow_2_T_4 = buckets_count_2 == 64'hffffffffffffffff; // @[BankProof.scala 42:24]
  wire  countOverflow_2 = accepted_2 & buckets_valid_2 & ~resolving_2 & _countOverflow_2_T_4; // @[BankProof.scala 41:71]
  wire  _cycleOverflow_2_T_6 = buckets_requestCycleSum_2 > _cycleOverflow_0_T_5; // @[BankProof.scala 44:34]
  wire  cycleOverflow_2 = _countOverflow_2_T_2 & _cycleOverflow_2_T_6; // @[BankProof.scala 43:71]
  wire  _GEN_30 = resolving_2 ? 1'h0 : buckets_valid_2; // @[BankProof.scala 28:24 52:27 53:26]
  wire [63:0] _buckets_count_2_T_1 = buckets_count_2 + 64'h1; // @[BankProof.scala 65:48]
  wire [63:0] _buckets_requestCycleSum_2_T_1 = buckets_requestCycleSum_2 + io_currentCycle; // @[BankProof.scala 66:68]
  wire  _GEN_33 = _canAccept_T_7 | _GEN_30; // @[BankProof.scala 59:50 60:28]
  wire [7:0] key_3 = io_base + 8'h3; // @[BankProof.scala 35:24]
  wire  selected_3 = io_event_bits[7:0] == key_3; // @[BankProof.scala 36:52]
  wire  resolving_3 = buckets_valid_3 & buckets_seq_3 <= io_safeWatermark; // @[BankProof.scala 37:38]
  wire  _canAccept_T_10 = ~buckets_valid_3 | resolving_3; // @[BankProof.scala 38:39]
  wire  canAccept_3 = ~buckets_valid_3 | resolving_3 | buckets_seq_3 == io_event_bits; // @[BankProof.scala 38:55]
  wire  accepted_3 = eventNeedsBucket & selected_3 & canAccept_3; // @[BankProof.scala 39:49]
  wire  available_3 = selected_3 & canAccept_3; // @[BankProof.scala 40:30]
  wire  _countOverflow_3_T_2 = accepted_3 & buckets_valid_3 & ~resolving_3; // @[BankProof.scala 41:54]
  wire  _countOverflow_3_T_4 = buckets_count_3 == 64'hffffffffffffffff; // @[BankProof.scala 42:24]
  wire  countOverflow_3 = accepted_3 & buckets_valid_3 & ~resolving_3 & _countOverflow_3_T_4; // @[BankProof.scala 41:71]
  wire  _cycleOverflow_3_T_6 = buckets_requestCycleSum_3 > _cycleOverflow_0_T_5; // @[BankProof.scala 44:34]
  wire  cycleOverflow_3 = _countOverflow_3_T_2 & _cycleOverflow_3_T_6; // @[BankProof.scala 43:71]
  wire  _GEN_45 = resolving_3 ? 1'h0 : buckets_valid_3; // @[BankProof.scala 28:24 52:27 53:26]
  wire [63:0] _buckets_count_3_T_1 = buckets_count_3 + 64'h1; // @[BankProof.scala 65:48]
  wire [63:0] _buckets_requestCycleSum_3_T_1 = buckets_requestCycleSum_3 + io_currentCycle; // @[BankProof.scala 66:68]
  wire  _GEN_48 = _canAccept_T_10 | _GEN_45; // @[BankProof.scala 59:50 60:28]
  wire [7:0] key_4 = io_base + 8'h4; // @[BankProof.scala 35:24]
  wire  selected_4 = io_event_bits[7:0] == key_4; // @[BankProof.scala 36:52]
  wire  resolving_4 = buckets_valid_4 & buckets_seq_4 <= io_safeWatermark; // @[BankProof.scala 37:38]
  wire  _canAccept_T_13 = ~buckets_valid_4 | resolving_4; // @[BankProof.scala 38:39]
  wire  canAccept_4 = ~buckets_valid_4 | resolving_4 | buckets_seq_4 == io_event_bits; // @[BankProof.scala 38:55]
  wire  accepted_4 = eventNeedsBucket & selected_4 & canAccept_4; // @[BankProof.scala 39:49]
  wire  available_4 = selected_4 & canAccept_4; // @[BankProof.scala 40:30]
  wire  _countOverflow_4_T_2 = accepted_4 & buckets_valid_4 & ~resolving_4; // @[BankProof.scala 41:54]
  wire  _countOverflow_4_T_4 = buckets_count_4 == 64'hffffffffffffffff; // @[BankProof.scala 42:24]
  wire  countOverflow_4 = accepted_4 & buckets_valid_4 & ~resolving_4 & _countOverflow_4_T_4; // @[BankProof.scala 41:71]
  wire  _cycleOverflow_4_T_6 = buckets_requestCycleSum_4 > _cycleOverflow_0_T_5; // @[BankProof.scala 44:34]
  wire  cycleOverflow_4 = _countOverflow_4_T_2 & _cycleOverflow_4_T_6; // @[BankProof.scala 43:71]
  wire  _GEN_60 = resolving_4 ? 1'h0 : buckets_valid_4; // @[BankProof.scala 28:24 52:27 53:26]
  wire [63:0] _buckets_count_4_T_1 = buckets_count_4 + 64'h1; // @[BankProof.scala 65:48]
  wire [63:0] _buckets_requestCycleSum_4_T_1 = buckets_requestCycleSum_4 + io_currentCycle; // @[BankProof.scala 66:68]
  wire  _GEN_63 = _canAccept_T_13 | _GEN_60; // @[BankProof.scala 59:50 60:28]
  wire [7:0] key_5 = io_base + 8'h5; // @[BankProof.scala 35:24]
  wire  selected_5 = io_event_bits[7:0] == key_5; // @[BankProof.scala 36:52]
  wire  resolving_5 = buckets_valid_5 & buckets_seq_5 <= io_safeWatermark; // @[BankProof.scala 37:38]
  wire  _canAccept_T_16 = ~buckets_valid_5 | resolving_5; // @[BankProof.scala 38:39]
  wire  canAccept_5 = ~buckets_valid_5 | resolving_5 | buckets_seq_5 == io_event_bits; // @[BankProof.scala 38:55]
  wire  accepted_5 = eventNeedsBucket & selected_5 & canAccept_5; // @[BankProof.scala 39:49]
  wire  available_5 = selected_5 & canAccept_5; // @[BankProof.scala 40:30]
  wire  _countOverflow_5_T_2 = accepted_5 & buckets_valid_5 & ~resolving_5; // @[BankProof.scala 41:54]
  wire  _countOverflow_5_T_4 = buckets_count_5 == 64'hffffffffffffffff; // @[BankProof.scala 42:24]
  wire  countOverflow_5 = accepted_5 & buckets_valid_5 & ~resolving_5 & _countOverflow_5_T_4; // @[BankProof.scala 41:71]
  wire  _cycleOverflow_5_T_6 = buckets_requestCycleSum_5 > _cycleOverflow_0_T_5; // @[BankProof.scala 44:34]
  wire  cycleOverflow_5 = _countOverflow_5_T_2 & _cycleOverflow_5_T_6; // @[BankProof.scala 43:71]
  wire  _GEN_75 = resolving_5 ? 1'h0 : buckets_valid_5; // @[BankProof.scala 28:24 52:27 53:26]
  wire [63:0] _buckets_count_5_T_1 = buckets_count_5 + 64'h1; // @[BankProof.scala 65:48]
  wire [63:0] _buckets_requestCycleSum_5_T_1 = buckets_requestCycleSum_5 + io_currentCycle; // @[BankProof.scala 66:68]
  wire  _GEN_78 = _canAccept_T_16 | _GEN_75; // @[BankProof.scala 59:50 60:28]
  wire [7:0] key_6 = io_base + 8'h6; // @[BankProof.scala 35:24]
  wire  selected_6 = io_event_bits[7:0] == key_6; // @[BankProof.scala 36:52]
  wire  resolving_6 = buckets_valid_6 & buckets_seq_6 <= io_safeWatermark; // @[BankProof.scala 37:38]
  wire  _canAccept_T_19 = ~buckets_valid_6 | resolving_6; // @[BankProof.scala 38:39]
  wire  canAccept_6 = ~buckets_valid_6 | resolving_6 | buckets_seq_6 == io_event_bits; // @[BankProof.scala 38:55]
  wire  accepted_6 = eventNeedsBucket & selected_6 & canAccept_6; // @[BankProof.scala 39:49]
  wire  available_6 = selected_6 & canAccept_6; // @[BankProof.scala 40:30]
  wire  _countOverflow_6_T_2 = accepted_6 & buckets_valid_6 & ~resolving_6; // @[BankProof.scala 41:54]
  wire  _countOverflow_6_T_4 = buckets_count_6 == 64'hffffffffffffffff; // @[BankProof.scala 42:24]
  wire  countOverflow_6 = accepted_6 & buckets_valid_6 & ~resolving_6 & _countOverflow_6_T_4; // @[BankProof.scala 41:71]
  wire  _cycleOverflow_6_T_6 = buckets_requestCycleSum_6 > _cycleOverflow_0_T_5; // @[BankProof.scala 44:34]
  wire  cycleOverflow_6 = _countOverflow_6_T_2 & _cycleOverflow_6_T_6; // @[BankProof.scala 43:71]
  wire  _GEN_90 = resolving_6 ? 1'h0 : buckets_valid_6; // @[BankProof.scala 28:24 52:27 53:26]
  wire [63:0] _buckets_count_6_T_1 = buckets_count_6 + 64'h1; // @[BankProof.scala 65:48]
  wire [63:0] _buckets_requestCycleSum_6_T_1 = buckets_requestCycleSum_6 + io_currentCycle; // @[BankProof.scala 66:68]
  wire  _GEN_93 = _canAccept_T_19 | _GEN_90; // @[BankProof.scala 59:50 60:28]
  wire [7:0] key_7 = io_base + 8'h7; // @[BankProof.scala 35:24]
  wire  selected_7 = io_event_bits[7:0] == key_7; // @[BankProof.scala 36:52]
  wire  resolving_7 = buckets_valid_7 & buckets_seq_7 <= io_safeWatermark; // @[BankProof.scala 37:38]
  wire  _canAccept_T_22 = ~buckets_valid_7 | resolving_7; // @[BankProof.scala 38:39]
  wire  canAccept_7 = ~buckets_valid_7 | resolving_7 | buckets_seq_7 == io_event_bits; // @[BankProof.scala 38:55]
  wire  accepted_7 = eventNeedsBucket & selected_7 & canAccept_7; // @[BankProof.scala 39:49]
  wire  available_7 = selected_7 & canAccept_7; // @[BankProof.scala 40:30]
  wire  _countOverflow_7_T_2 = accepted_7 & buckets_valid_7 & ~resolving_7; // @[BankProof.scala 41:54]
  wire  _countOverflow_7_T_4 = buckets_count_7 == 64'hffffffffffffffff; // @[BankProof.scala 42:24]
  wire  countOverflow_7 = accepted_7 & buckets_valid_7 & ~resolving_7 & _countOverflow_7_T_4; // @[BankProof.scala 41:71]
  wire  _cycleOverflow_7_T_6 = buckets_requestCycleSum_7 > _cycleOverflow_0_T_5; // @[BankProof.scala 44:34]
  wire  cycleOverflow_7 = _countOverflow_7_T_2 & _cycleOverflow_7_T_6; // @[BankProof.scala 43:71]
  wire  _GEN_105 = resolving_7 ? 1'h0 : buckets_valid_7; // @[BankProof.scala 28:24 52:27 53:26]
  wire [63:0] _buckets_count_7_T_1 = buckets_count_7 + 64'h1; // @[BankProof.scala 65:48]
  wire [63:0] _buckets_requestCycleSum_7_T_1 = buckets_requestCycleSum_7 + io_currentCycle; // @[BankProof.scala 66:68]
  wire  _GEN_108 = _canAccept_T_22 | _GEN_105; // @[BankProof.scala 59:50 60:28]
  wire [63:0] _io_resolvedCount_T = resolving_0 ? buckets_count_0 : 64'h0; // @[BankProof.scala 80:8]
  wire [63:0] _io_resolvedCount_T_1 = resolving_1 ? buckets_count_1 : 64'h0; // @[BankProof.scala 80:8]
  wire [63:0] _io_resolvedCount_T_2 = resolving_2 ? buckets_count_2 : 64'h0; // @[BankProof.scala 80:8]
  wire [63:0] _io_resolvedCount_T_3 = resolving_3 ? buckets_count_3 : 64'h0; // @[BankProof.scala 80:8]
  wire [63:0] _io_resolvedCount_T_4 = resolving_4 ? buckets_count_4 : 64'h0; // @[BankProof.scala 80:8]
  wire [63:0] _io_resolvedCount_T_5 = resolving_5 ? buckets_count_5 : 64'h0; // @[BankProof.scala 80:8]
  wire [63:0] _io_resolvedCount_T_6 = resolving_6 ? buckets_count_6 : 64'h0; // @[BankProof.scala 80:8]
  wire [63:0] _io_resolvedCount_T_7 = resolving_7 ? buckets_count_7 : 64'h0; // @[BankProof.scala 80:8]
  wire [64:0] _io_resolvedCount_T_8 = _io_resolvedCount_T + _io_resolvedCount_T_1; // @[BankProof.scala 75:27]
  wire [64:0] _io_resolvedCount_T_9 = _io_resolvedCount_T_2 + _io_resolvedCount_T_3; // @[BankProof.scala 75:27]
  wire [64:0] _io_resolvedCount_T_10 = _io_resolvedCount_T_4 + _io_resolvedCount_T_5; // @[BankProof.scala 75:27]
  wire [64:0] _io_resolvedCount_T_11 = _io_resolvedCount_T_6 + _io_resolvedCount_T_7; // @[BankProof.scala 75:27]
  wire [65:0] _io_resolvedCount_T_12 = _io_resolvedCount_T_8 + _io_resolvedCount_T_9; // @[BankProof.scala 75:27]
  wire [65:0] _io_resolvedCount_T_13 = _io_resolvedCount_T_10 + _io_resolvedCount_T_11; // @[BankProof.scala 75:27]
  wire [63:0] _io_resolvedRequest_T = resolving_0 ? buckets_requestCycleSum_0 : 64'h0; // @[BankProof.scala 82:8]
  wire [63:0] _io_resolvedRequest_T_1 = resolving_1 ? buckets_requestCycleSum_1 : 64'h0; // @[BankProof.scala 82:8]
  wire [63:0] _io_resolvedRequest_T_2 = resolving_2 ? buckets_requestCycleSum_2 : 64'h0; // @[BankProof.scala 82:8]
  wire [63:0] _io_resolvedRequest_T_3 = resolving_3 ? buckets_requestCycleSum_3 : 64'h0; // @[BankProof.scala 82:8]
  wire [63:0] _io_resolvedRequest_T_4 = resolving_4 ? buckets_requestCycleSum_4 : 64'h0; // @[BankProof.scala 82:8]
  wire [63:0] _io_resolvedRequest_T_5 = resolving_5 ? buckets_requestCycleSum_5 : 64'h0; // @[BankProof.scala 82:8]
  wire [63:0] _io_resolvedRequest_T_6 = resolving_6 ? buckets_requestCycleSum_6 : 64'h0; // @[BankProof.scala 82:8]
  wire [63:0] _io_resolvedRequest_T_7 = resolving_7 ? buckets_requestCycleSum_7 : 64'h0; // @[BankProof.scala 82:8]
  wire [64:0] _io_resolvedRequest_T_8 = _io_resolvedRequest_T + _io_resolvedRequest_T_1; // @[BankProof.scala 75:27]
  wire [64:0] _io_resolvedRequest_T_9 = _io_resolvedRequest_T_2 + _io_resolvedRequest_T_3; // @[BankProof.scala 75:27]
  wire [64:0] _io_resolvedRequest_T_10 = _io_resolvedRequest_T_4 + _io_resolvedRequest_T_5; // @[BankProof.scala 75:27]
  wire [64:0] _io_resolvedRequest_T_11 = _io_resolvedRequest_T_6 + _io_resolvedRequest_T_7; // @[BankProof.scala 75:27]
  wire [65:0] _io_resolvedRequest_T_12 = _io_resolvedRequest_T_8 + _io_resolvedRequest_T_9; // @[BankProof.scala 75:27]
  wire [65:0] _io_resolvedRequest_T_13 = _io_resolvedRequest_T_10 + _io_resolvedRequest_T_11; // @[BankProof.scala 75:27]
  wire [7:0] _io_eventAvailable_T = {available_7,available_6,available_5,available_4,available_3,available_2,available_1
    ,available_0}; // @[BankProof.scala 83:34]
  wire [7:0] _io_countOverflow_T = {countOverflow_7,countOverflow_6,countOverflow_5,countOverflow_4,countOverflow_3,
    countOverflow_2,countOverflow_1,countOverflow_0}; // @[BankProof.scala 84:37]
  wire [7:0] _io_cycleOverflow_T = {cycleOverflow_7,cycleOverflow_6,cycleOverflow_5,cycleOverflow_4,cycleOverflow_3,
    cycleOverflow_2,cycleOverflow_1,cycleOverflow_0}; // @[BankProof.scala 85:37]
  wire [127:0] io_observe_0_lo = {buckets_count_0,buckets_requestCycleSum_0}; // @[Cat.scala 33:92]
  wire [32:0] io_observe_0_hi = {buckets_valid_0,buckets_seq_0}; // @[Cat.scala 33:92]
  wire [127:0] io_observe_1_lo = {buckets_count_1,buckets_requestCycleSum_1}; // @[Cat.scala 33:92]
  wire [32:0] io_observe_1_hi = {buckets_valid_1,buckets_seq_1}; // @[Cat.scala 33:92]
  wire [127:0] io_observe_2_lo = {buckets_count_2,buckets_requestCycleSum_2}; // @[Cat.scala 33:92]
  wire [32:0] io_observe_2_hi = {buckets_valid_2,buckets_seq_2}; // @[Cat.scala 33:92]
  wire [127:0] io_observe_3_lo = {buckets_count_3,buckets_requestCycleSum_3}; // @[Cat.scala 33:92]
  wire [32:0] io_observe_3_hi = {buckets_valid_3,buckets_seq_3}; // @[Cat.scala 33:92]
  wire [127:0] io_observe_4_lo = {buckets_count_4,buckets_requestCycleSum_4}; // @[Cat.scala 33:92]
  wire [32:0] io_observe_4_hi = {buckets_valid_4,buckets_seq_4}; // @[Cat.scala 33:92]
  wire [127:0] io_observe_5_lo = {buckets_count_5,buckets_requestCycleSum_5}; // @[Cat.scala 33:92]
  wire [32:0] io_observe_5_hi = {buckets_valid_5,buckets_seq_5}; // @[Cat.scala 33:92]
  wire [127:0] io_observe_6_lo = {buckets_count_6,buckets_requestCycleSum_6}; // @[Cat.scala 33:92]
  wire [32:0] io_observe_6_hi = {buckets_valid_6,buckets_seq_6}; // @[Cat.scala 33:92]
  wire [127:0] io_observe_7_lo = {buckets_count_7,buckets_requestCycleSum_7}; // @[Cat.scala 33:92]
  wire [32:0] io_observe_7_hi = {buckets_valid_7,buckets_seq_7}; // @[Cat.scala 33:92]
  assign io_observe_0 = {io_observe_0_hi,io_observe_0_lo}; // @[Cat.scala 33:92]
  assign io_observe_1 = {io_observe_1_hi,io_observe_1_lo}; // @[Cat.scala 33:92]
  assign io_observe_2 = {io_observe_2_hi,io_observe_2_lo}; // @[Cat.scala 33:92]
  assign io_observe_3 = {io_observe_3_hi,io_observe_3_lo}; // @[Cat.scala 33:92]
  assign io_observe_4 = {io_observe_4_hi,io_observe_4_lo}; // @[Cat.scala 33:92]
  assign io_observe_5 = {io_observe_5_hi,io_observe_5_lo}; // @[Cat.scala 33:92]
  assign io_observe_6 = {io_observe_6_hi,io_observe_6_lo}; // @[Cat.scala 33:92]
  assign io_observe_7 = {io_observe_7_hi,io_observe_7_lo}; // @[Cat.scala 33:92]
  assign io_resolvedCount = _io_resolvedCount_T_12 + _io_resolvedCount_T_13; // @[BankProof.scala 75:27]
  assign io_resolvedRequest = _io_resolvedRequest_T_12 + _io_resolvedRequest_T_13; // @[BankProof.scala 75:27]
  assign io_eventAvailable = |_io_eventAvailable_T; // @[BankProof.scala 83:41]
  assign io_countOverflow = |_io_countOverflow_T; // @[BankProof.scala 84:44]
  assign io_cycleOverflow = |_io_cycleOverflow_T; // @[BankProof.scala 85:44]
  always @(posedge clock) begin
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_valid_0 <= 1'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_valid_0 <= 1'h0; // @[BankProof.scala 47:24]
    end else if (accepted) begin // @[BankProof.scala 58:23]
      buckets_valid_0 <= _GEN_3;
    end else if (resolving_0) begin // @[BankProof.scala 52:27]
      buckets_valid_0 <= 1'h0; // @[BankProof.scala 53:26]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_valid_1 <= 1'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_valid_1 <= 1'h0; // @[BankProof.scala 47:24]
    end else if (accepted_1) begin // @[BankProof.scala 58:23]
      buckets_valid_1 <= _GEN_18;
    end else if (resolving_1) begin // @[BankProof.scala 52:27]
      buckets_valid_1 <= 1'h0; // @[BankProof.scala 53:26]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_valid_2 <= 1'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_valid_2 <= 1'h0; // @[BankProof.scala 47:24]
    end else if (accepted_2) begin // @[BankProof.scala 58:23]
      buckets_valid_2 <= _GEN_33;
    end else if (resolving_2) begin // @[BankProof.scala 52:27]
      buckets_valid_2 <= 1'h0; // @[BankProof.scala 53:26]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_valid_3 <= 1'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_valid_3 <= 1'h0; // @[BankProof.scala 47:24]
    end else if (accepted_3) begin // @[BankProof.scala 58:23]
      buckets_valid_3 <= _GEN_48;
    end else if (resolving_3) begin // @[BankProof.scala 52:27]
      buckets_valid_3 <= 1'h0; // @[BankProof.scala 53:26]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_valid_4 <= 1'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_valid_4 <= 1'h0; // @[BankProof.scala 47:24]
    end else if (accepted_4) begin // @[BankProof.scala 58:23]
      buckets_valid_4 <= _GEN_63;
    end else if (resolving_4) begin // @[BankProof.scala 52:27]
      buckets_valid_4 <= 1'h0; // @[BankProof.scala 53:26]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_valid_5 <= 1'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_valid_5 <= 1'h0; // @[BankProof.scala 47:24]
    end else if (accepted_5) begin // @[BankProof.scala 58:23]
      buckets_valid_5 <= _GEN_78;
    end else if (resolving_5) begin // @[BankProof.scala 52:27]
      buckets_valid_5 <= 1'h0; // @[BankProof.scala 53:26]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_valid_6 <= 1'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_valid_6 <= 1'h0; // @[BankProof.scala 47:24]
    end else if (accepted_6) begin // @[BankProof.scala 58:23]
      buckets_valid_6 <= _GEN_93;
    end else if (resolving_6) begin // @[BankProof.scala 52:27]
      buckets_valid_6 <= 1'h0; // @[BankProof.scala 53:26]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_valid_7 <= 1'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_valid_7 <= 1'h0; // @[BankProof.scala 47:24]
    end else if (accepted_7) begin // @[BankProof.scala 58:23]
      buckets_valid_7 <= _GEN_108;
    end else if (resolving_7) begin // @[BankProof.scala 52:27]
      buckets_valid_7 <= 1'h0; // @[BankProof.scala 53:26]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_seq_0 <= 32'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_seq_0 <= 32'h0; // @[BankProof.scala 48:22]
    end else if (accepted) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_1) begin // @[BankProof.scala 59:50]
        buckets_seq_0 <= io_event_bits; // @[BankProof.scala 61:26]
      end
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_seq_1 <= 32'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_seq_1 <= 32'h0; // @[BankProof.scala 48:22]
    end else if (accepted_1) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_4) begin // @[BankProof.scala 59:50]
        buckets_seq_1 <= io_event_bits; // @[BankProof.scala 61:26]
      end
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_seq_2 <= 32'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_seq_2 <= 32'h0; // @[BankProof.scala 48:22]
    end else if (accepted_2) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_7) begin // @[BankProof.scala 59:50]
        buckets_seq_2 <= io_event_bits; // @[BankProof.scala 61:26]
      end
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_seq_3 <= 32'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_seq_3 <= 32'h0; // @[BankProof.scala 48:22]
    end else if (accepted_3) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_10) begin // @[BankProof.scala 59:50]
        buckets_seq_3 <= io_event_bits; // @[BankProof.scala 61:26]
      end
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_seq_4 <= 32'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_seq_4 <= 32'h0; // @[BankProof.scala 48:22]
    end else if (accepted_4) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_13) begin // @[BankProof.scala 59:50]
        buckets_seq_4 <= io_event_bits; // @[BankProof.scala 61:26]
      end
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_seq_5 <= 32'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_seq_5 <= 32'h0; // @[BankProof.scala 48:22]
    end else if (accepted_5) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_16) begin // @[BankProof.scala 59:50]
        buckets_seq_5 <= io_event_bits; // @[BankProof.scala 61:26]
      end
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_seq_6 <= 32'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_seq_6 <= 32'h0; // @[BankProof.scala 48:22]
    end else if (accepted_6) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_19) begin // @[BankProof.scala 59:50]
        buckets_seq_6 <= io_event_bits; // @[BankProof.scala 61:26]
      end
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_seq_7 <= 32'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_seq_7 <= 32'h0; // @[BankProof.scala 48:22]
    end else if (accepted_7) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_22) begin // @[BankProof.scala 59:50]
        buckets_seq_7 <= io_event_bits; // @[BankProof.scala 61:26]
      end
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_count_0 <= 64'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_count_0 <= 64'h0; // @[BankProof.scala 49:24]
    end else if (accepted) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_1) begin // @[BankProof.scala 59:50]
        buckets_count_0 <= 64'h1; // @[BankProof.scala 62:28]
      end else begin
        buckets_count_0 <= _buckets_count_0_T_1; // @[BankProof.scala 65:28]
      end
    end else if (resolving_0) begin // @[BankProof.scala 52:27]
      buckets_count_0 <= 64'h0; // @[BankProof.scala 54:26]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_count_1 <= 64'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_count_1 <= 64'h0; // @[BankProof.scala 49:24]
    end else if (accepted_1) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_4) begin // @[BankProof.scala 59:50]
        buckets_count_1 <= 64'h1; // @[BankProof.scala 62:28]
      end else begin
        buckets_count_1 <= _buckets_count_1_T_1; // @[BankProof.scala 65:28]
      end
    end else if (resolving_1) begin // @[BankProof.scala 52:27]
      buckets_count_1 <= 64'h0; // @[BankProof.scala 54:26]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_count_2 <= 64'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_count_2 <= 64'h0; // @[BankProof.scala 49:24]
    end else if (accepted_2) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_7) begin // @[BankProof.scala 59:50]
        buckets_count_2 <= 64'h1; // @[BankProof.scala 62:28]
      end else begin
        buckets_count_2 <= _buckets_count_2_T_1; // @[BankProof.scala 65:28]
      end
    end else if (resolving_2) begin // @[BankProof.scala 52:27]
      buckets_count_2 <= 64'h0; // @[BankProof.scala 54:26]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_count_3 <= 64'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_count_3 <= 64'h0; // @[BankProof.scala 49:24]
    end else if (accepted_3) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_10) begin // @[BankProof.scala 59:50]
        buckets_count_3 <= 64'h1; // @[BankProof.scala 62:28]
      end else begin
        buckets_count_3 <= _buckets_count_3_T_1; // @[BankProof.scala 65:28]
      end
    end else if (resolving_3) begin // @[BankProof.scala 52:27]
      buckets_count_3 <= 64'h0; // @[BankProof.scala 54:26]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_count_4 <= 64'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_count_4 <= 64'h0; // @[BankProof.scala 49:24]
    end else if (accepted_4) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_13) begin // @[BankProof.scala 59:50]
        buckets_count_4 <= 64'h1; // @[BankProof.scala 62:28]
      end else begin
        buckets_count_4 <= _buckets_count_4_T_1; // @[BankProof.scala 65:28]
      end
    end else if (resolving_4) begin // @[BankProof.scala 52:27]
      buckets_count_4 <= 64'h0; // @[BankProof.scala 54:26]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_count_5 <= 64'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_count_5 <= 64'h0; // @[BankProof.scala 49:24]
    end else if (accepted_5) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_16) begin // @[BankProof.scala 59:50]
        buckets_count_5 <= 64'h1; // @[BankProof.scala 62:28]
      end else begin
        buckets_count_5 <= _buckets_count_5_T_1; // @[BankProof.scala 65:28]
      end
    end else if (resolving_5) begin // @[BankProof.scala 52:27]
      buckets_count_5 <= 64'h0; // @[BankProof.scala 54:26]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_count_6 <= 64'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_count_6 <= 64'h0; // @[BankProof.scala 49:24]
    end else if (accepted_6) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_19) begin // @[BankProof.scala 59:50]
        buckets_count_6 <= 64'h1; // @[BankProof.scala 62:28]
      end else begin
        buckets_count_6 <= _buckets_count_6_T_1; // @[BankProof.scala 65:28]
      end
    end else if (resolving_6) begin // @[BankProof.scala 52:27]
      buckets_count_6 <= 64'h0; // @[BankProof.scala 54:26]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_count_7 <= 64'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_count_7 <= 64'h0; // @[BankProof.scala 49:24]
    end else if (accepted_7) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_22) begin // @[BankProof.scala 59:50]
        buckets_count_7 <= 64'h1; // @[BankProof.scala 62:28]
      end else begin
        buckets_count_7 <= _buckets_count_7_T_1; // @[BankProof.scala 65:28]
      end
    end else if (resolving_7) begin // @[BankProof.scala 52:27]
      buckets_count_7 <= 64'h0; // @[BankProof.scala 54:26]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_requestCycleSum_0 <= 64'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_requestCycleSum_0 <= 64'h0; // @[BankProof.scala 50:34]
    end else if (accepted) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_1) begin // @[BankProof.scala 59:50]
        buckets_requestCycleSum_0 <= io_currentCycle; // @[BankProof.scala 63:38]
      end else begin
        buckets_requestCycleSum_0 <= _buckets_requestCycleSum_0_T_1; // @[BankProof.scala 66:38]
      end
    end else if (resolving_0) begin // @[BankProof.scala 52:27]
      buckets_requestCycleSum_0 <= 64'h0; // @[BankProof.scala 55:36]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_requestCycleSum_1 <= 64'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_requestCycleSum_1 <= 64'h0; // @[BankProof.scala 50:34]
    end else if (accepted_1) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_4) begin // @[BankProof.scala 59:50]
        buckets_requestCycleSum_1 <= io_currentCycle; // @[BankProof.scala 63:38]
      end else begin
        buckets_requestCycleSum_1 <= _buckets_requestCycleSum_1_T_1; // @[BankProof.scala 66:38]
      end
    end else if (resolving_1) begin // @[BankProof.scala 52:27]
      buckets_requestCycleSum_1 <= 64'h0; // @[BankProof.scala 55:36]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_requestCycleSum_2 <= 64'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_requestCycleSum_2 <= 64'h0; // @[BankProof.scala 50:34]
    end else if (accepted_2) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_7) begin // @[BankProof.scala 59:50]
        buckets_requestCycleSum_2 <= io_currentCycle; // @[BankProof.scala 63:38]
      end else begin
        buckets_requestCycleSum_2 <= _buckets_requestCycleSum_2_T_1; // @[BankProof.scala 66:38]
      end
    end else if (resolving_2) begin // @[BankProof.scala 52:27]
      buckets_requestCycleSum_2 <= 64'h0; // @[BankProof.scala 55:36]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_requestCycleSum_3 <= 64'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_requestCycleSum_3 <= 64'h0; // @[BankProof.scala 50:34]
    end else if (accepted_3) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_10) begin // @[BankProof.scala 59:50]
        buckets_requestCycleSum_3 <= io_currentCycle; // @[BankProof.scala 63:38]
      end else begin
        buckets_requestCycleSum_3 <= _buckets_requestCycleSum_3_T_1; // @[BankProof.scala 66:38]
      end
    end else if (resolving_3) begin // @[BankProof.scala 52:27]
      buckets_requestCycleSum_3 <= 64'h0; // @[BankProof.scala 55:36]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_requestCycleSum_4 <= 64'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_requestCycleSum_4 <= 64'h0; // @[BankProof.scala 50:34]
    end else if (accepted_4) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_13) begin // @[BankProof.scala 59:50]
        buckets_requestCycleSum_4 <= io_currentCycle; // @[BankProof.scala 63:38]
      end else begin
        buckets_requestCycleSum_4 <= _buckets_requestCycleSum_4_T_1; // @[BankProof.scala 66:38]
      end
    end else if (resolving_4) begin // @[BankProof.scala 52:27]
      buckets_requestCycleSum_4 <= 64'h0; // @[BankProof.scala 55:36]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_requestCycleSum_5 <= 64'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_requestCycleSum_5 <= 64'h0; // @[BankProof.scala 50:34]
    end else if (accepted_5) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_16) begin // @[BankProof.scala 59:50]
        buckets_requestCycleSum_5 <= io_currentCycle; // @[BankProof.scala 63:38]
      end else begin
        buckets_requestCycleSum_5 <= _buckets_requestCycleSum_5_T_1; // @[BankProof.scala 66:38]
      end
    end else if (resolving_5) begin // @[BankProof.scala 52:27]
      buckets_requestCycleSum_5 <= 64'h0; // @[BankProof.scala 55:36]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_requestCycleSum_6 <= 64'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_requestCycleSum_6 <= 64'h0; // @[BankProof.scala 50:34]
    end else if (accepted_6) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_19) begin // @[BankProof.scala 59:50]
        buckets_requestCycleSum_6 <= io_currentCycle; // @[BankProof.scala 63:38]
      end else begin
        buckets_requestCycleSum_6 <= _buckets_requestCycleSum_6_T_1; // @[BankProof.scala 66:38]
      end
    end else if (resolving_6) begin // @[BankProof.scala 52:27]
      buckets_requestCycleSum_6 <= 64'h0; // @[BankProof.scala 55:36]
    end
    if (reset) begin // @[BankProof.scala 28:24]
      buckets_requestCycleSum_7 <= 64'h0; // @[BankProof.scala 28:24]
    end else if (io_resetStats) begin // @[BankProof.scala 46:26]
      buckets_requestCycleSum_7 <= 64'h0; // @[BankProof.scala 50:34]
    end else if (accepted_7) begin // @[BankProof.scala 58:23]
      if (_canAccept_T_22) begin // @[BankProof.scala 59:50]
        buckets_requestCycleSum_7 <= io_currentCycle; // @[BankProof.scala 63:38]
      end else begin
        buckets_requestCycleSum_7 <= _buckets_requestCycleSum_7_T_1; // @[BankProof.scala 66:38]
      end
    end else if (resolving_7) begin // @[BankProof.scala 52:27]
      buckets_requestCycleSum_7 <= 64'h0; // @[BankProof.scala 55:36]
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
  buckets_valid_0 = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  buckets_valid_1 = _RAND_1[0:0];
  _RAND_2 = {1{`RANDOM}};
  buckets_valid_2 = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  buckets_valid_3 = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  buckets_valid_4 = _RAND_4[0:0];
  _RAND_5 = {1{`RANDOM}};
  buckets_valid_5 = _RAND_5[0:0];
  _RAND_6 = {1{`RANDOM}};
  buckets_valid_6 = _RAND_6[0:0];
  _RAND_7 = {1{`RANDOM}};
  buckets_valid_7 = _RAND_7[0:0];
  _RAND_8 = {1{`RANDOM}};
  buckets_seq_0 = _RAND_8[31:0];
  _RAND_9 = {1{`RANDOM}};
  buckets_seq_1 = _RAND_9[31:0];
  _RAND_10 = {1{`RANDOM}};
  buckets_seq_2 = _RAND_10[31:0];
  _RAND_11 = {1{`RANDOM}};
  buckets_seq_3 = _RAND_11[31:0];
  _RAND_12 = {1{`RANDOM}};
  buckets_seq_4 = _RAND_12[31:0];
  _RAND_13 = {1{`RANDOM}};
  buckets_seq_5 = _RAND_13[31:0];
  _RAND_14 = {1{`RANDOM}};
  buckets_seq_6 = _RAND_14[31:0];
  _RAND_15 = {1{`RANDOM}};
  buckets_seq_7 = _RAND_15[31:0];
  _RAND_16 = {2{`RANDOM}};
  buckets_count_0 = _RAND_16[63:0];
  _RAND_17 = {2{`RANDOM}};
  buckets_count_1 = _RAND_17[63:0];
  _RAND_18 = {2{`RANDOM}};
  buckets_count_2 = _RAND_18[63:0];
  _RAND_19 = {2{`RANDOM}};
  buckets_count_3 = _RAND_19[63:0];
  _RAND_20 = {2{`RANDOM}};
  buckets_count_4 = _RAND_20[63:0];
  _RAND_21 = {2{`RANDOM}};
  buckets_count_5 = _RAND_21[63:0];
  _RAND_22 = {2{`RANDOM}};
  buckets_count_6 = _RAND_22[63:0];
  _RAND_23 = {2{`RANDOM}};
  buckets_count_7 = _RAND_23[63:0];
  _RAND_24 = {2{`RANDOM}};
  buckets_requestCycleSum_0 = _RAND_24[63:0];
  _RAND_25 = {2{`RANDOM}};
  buckets_requestCycleSum_1 = _RAND_25[63:0];
  _RAND_26 = {2{`RANDOM}};
  buckets_requestCycleSum_2 = _RAND_26[63:0];
  _RAND_27 = {2{`RANDOM}};
  buckets_requestCycleSum_3 = _RAND_27[63:0];
  _RAND_28 = {2{`RANDOM}};
  buckets_requestCycleSum_4 = _RAND_28[63:0];
  _RAND_29 = {2{`RANDOM}};
  buckets_requestCycleSum_5 = _RAND_29[63:0];
  _RAND_30 = {2{`RANDOM}};
  buckets_requestCycleSum_6 = _RAND_30[63:0];
  _RAND_31 = {2{`RANDOM}};
  buckets_requestCycleSum_7 = _RAND_31[63:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module BarrierCandidate(
  input          clock,
  input          reset,
  input          io_resetStats,
  input          io_event_valid,
  input  [31:0]  io_event_bits,
  input  [31:0]  io_safeWatermark,
  input  [63:0]  io_currentCycle,
  input          io_fatalProtocolError,
  output [63:0]  io_seen,
  output [160:0] io_debugView_0,
  output [160:0] io_debugView_1,
  output [160:0] io_debugView_2,
  output [160:0] io_debugView_3,
  output [160:0] io_debugView_4,
  output [160:0] io_debugView_5,
  output [160:0] io_debugView_6,
  output [160:0] io_debugView_7,
  output [160:0] io_debugView_8,
  output [160:0] io_debugView_9,
  output [160:0] io_debugView_10,
  output [160:0] io_debugView_11,
  output [160:0] io_debugView_12,
  output [160:0] io_debugView_13,
  output [160:0] io_debugView_14,
  output [160:0] io_debugView_15,
  output [160:0] io_debugView_16,
  output [160:0] io_debugView_17,
  output [160:0] io_debugView_18,
  output [160:0] io_debugView_19,
  output [160:0] io_debugView_20,
  output [160:0] io_debugView_21,
  output [160:0] io_debugView_22,
  output [160:0] io_debugView_23,
  output [160:0] io_debugView_24,
  output [160:0] io_debugView_25,
  output [160:0] io_debugView_26,
  output [160:0] io_debugView_27,
  output [160:0] io_debugView_28,
  output [160:0] io_debugView_29,
  output [160:0] io_debugView_30,
  output [160:0] io_debugView_31,
  output [160:0] io_debugView_32,
  output [160:0] io_debugView_33,
  output [160:0] io_debugView_34,
  output [160:0] io_debugView_35,
  output [160:0] io_debugView_36,
  output [160:0] io_debugView_37,
  output [160:0] io_debugView_38,
  output [160:0] io_debugView_39,
  output [160:0] io_debugView_40,
  output [160:0] io_debugView_41,
  output [160:0] io_debugView_42,
  output [160:0] io_debugView_43,
  output [160:0] io_debugView_44,
  output [160:0] io_debugView_45,
  output [160:0] io_debugView_46,
  output [160:0] io_debugView_47,
  output [160:0] io_debugView_48,
  output [160:0] io_debugView_49,
  output [160:0] io_debugView_50,
  output [160:0] io_debugView_51,
  output [160:0] io_debugView_52,
  output [160:0] io_debugView_53,
  output [160:0] io_debugView_54,
  output [160:0] io_debugView_55,
  output [160:0] io_debugView_56,
  output [160:0] io_debugView_57,
  output [160:0] io_debugView_58,
  output [160:0] io_debugView_59,
  output [160:0] io_debugView_60,
  output [160:0] io_debugView_61,
  output [160:0] io_debugView_62,
  output [160:0] io_debugView_63,
  output [160:0] io_debugView_64,
  output [160:0] io_debugView_65,
  output [160:0] io_debugView_66,
  output [160:0] io_debugView_67,
  output [160:0] io_debugView_68,
  output [160:0] io_debugView_69,
  output [160:0] io_debugView_70,
  output [160:0] io_debugView_71,
  output [160:0] io_debugView_72,
  output [160:0] io_debugView_73,
  output [160:0] io_debugView_74,
  output [160:0] io_debugView_75,
  output [160:0] io_debugView_76,
  output [160:0] io_debugView_77,
  output [160:0] io_debugView_78,
  output [160:0] io_debugView_79,
  output [160:0] io_debugView_80,
  output [160:0] io_debugView_81,
  output [160:0] io_debugView_82,
  output [160:0] io_debugView_83,
  output [160:0] io_debugView_84,
  output [160:0] io_debugView_85,
  output [160:0] io_debugView_86,
  output [160:0] io_debugView_87,
  output [160:0] io_debugView_88,
  output [160:0] io_debugView_89,
  output [160:0] io_debugView_90,
  output [160:0] io_debugView_91,
  output [160:0] io_debugView_92,
  output [160:0] io_debugView_93,
  output [160:0] io_debugView_94,
  output [160:0] io_debugView_95,
  output [160:0] io_debugView_96,
  output [160:0] io_debugView_97,
  output [160:0] io_debugView_98,
  output [160:0] io_debugView_99,
  output [160:0] io_debugView_100,
  output [160:0] io_debugView_101,
  output [160:0] io_debugView_102,
  output [160:0] io_debugView_103,
  output [160:0] io_debugView_104,
  output [160:0] io_debugView_105,
  output [160:0] io_debugView_106,
  output [160:0] io_debugView_107,
  output [160:0] io_debugView_108,
  output [160:0] io_debugView_109,
  output [160:0] io_debugView_110,
  output [160:0] io_debugView_111,
  output [160:0] io_debugView_112,
  output [160:0] io_debugView_113,
  output [160:0] io_debugView_114,
  output [160:0] io_debugView_115,
  output [160:0] io_debugView_116,
  output [160:0] io_debugView_117,
  output [160:0] io_debugView_118,
  output [160:0] io_debugView_119,
  output [160:0] io_debugView_120,
  output [160:0] io_debugView_121,
  output [160:0] io_debugView_122,
  output [160:0] io_debugView_123,
  output [160:0] io_debugView_124,
  output [160:0] io_debugView_125,
  output [160:0] io_debugView_126,
  output [160:0] io_debugView_127,
  output [160:0] io_debugView_128,
  output [160:0] io_debugView_129,
  output [160:0] io_debugView_130,
  output [160:0] io_debugView_131,
  output [160:0] io_debugView_132,
  output [160:0] io_debugView_133,
  output [160:0] io_debugView_134,
  output [160:0] io_debugView_135,
  output [160:0] io_debugView_136,
  output [160:0] io_debugView_137,
  output [160:0] io_debugView_138,
  output [160:0] io_debugView_139,
  output [160:0] io_debugView_140,
  output [160:0] io_debugView_141,
  output [160:0] io_debugView_142,
  output [160:0] io_debugView_143,
  output [160:0] io_debugView_144,
  output [160:0] io_debugView_145,
  output [160:0] io_debugView_146,
  output [160:0] io_debugView_147,
  output [160:0] io_debugView_148,
  output [160:0] io_debugView_149,
  output [160:0] io_debugView_150,
  output [160:0] io_debugView_151,
  output [160:0] io_debugView_152,
  output [160:0] io_debugView_153,
  output [160:0] io_debugView_154,
  output [160:0] io_debugView_155,
  output [160:0] io_debugView_156,
  output [160:0] io_debugView_157,
  output [160:0] io_debugView_158,
  output [160:0] io_debugView_159,
  output [160:0] io_debugView_160,
  output [160:0] io_debugView_161,
  output [160:0] io_debugView_162,
  output [160:0] io_debugView_163,
  output [160:0] io_debugView_164,
  output [160:0] io_debugView_165,
  output [160:0] io_debugView_166,
  output [160:0] io_debugView_167,
  output [160:0] io_debugView_168,
  output [160:0] io_debugView_169,
  output [160:0] io_debugView_170,
  output [160:0] io_debugView_171,
  output [160:0] io_debugView_172,
  output [160:0] io_debugView_173,
  output [160:0] io_debugView_174,
  output [160:0] io_debugView_175,
  output [160:0] io_debugView_176,
  output [160:0] io_debugView_177,
  output [160:0] io_debugView_178,
  output [160:0] io_debugView_179,
  output [160:0] io_debugView_180,
  output [160:0] io_debugView_181,
  output [160:0] io_debugView_182,
  output [160:0] io_debugView_183,
  output [160:0] io_debugView_184,
  output [160:0] io_debugView_185,
  output [160:0] io_debugView_186,
  output [160:0] io_debugView_187,
  output [160:0] io_debugView_188,
  output [160:0] io_debugView_189,
  output [160:0] io_debugView_190,
  output [160:0] io_debugView_191,
  output [160:0] io_debugView_192,
  output [160:0] io_debugView_193,
  output [160:0] io_debugView_194,
  output [160:0] io_debugView_195,
  output [160:0] io_debugView_196,
  output [160:0] io_debugView_197,
  output [160:0] io_debugView_198,
  output [160:0] io_debugView_199,
  output [160:0] io_debugView_200,
  output [160:0] io_debugView_201,
  output [160:0] io_debugView_202,
  output [160:0] io_debugView_203,
  output [160:0] io_debugView_204,
  output [160:0] io_debugView_205,
  output [160:0] io_debugView_206,
  output [160:0] io_debugView_207,
  output [160:0] io_debugView_208,
  output [160:0] io_debugView_209,
  output [160:0] io_debugView_210,
  output [160:0] io_debugView_211,
  output [160:0] io_debugView_212,
  output [160:0] io_debugView_213,
  output [160:0] io_debugView_214,
  output [160:0] io_debugView_215,
  output [160:0] io_debugView_216,
  output [160:0] io_debugView_217,
  output [160:0] io_debugView_218,
  output [160:0] io_debugView_219,
  output [160:0] io_debugView_220,
  output [160:0] io_debugView_221,
  output [160:0] io_debugView_222,
  output [160:0] io_debugView_223,
  output [160:0] io_debugView_224,
  output [160:0] io_debugView_225,
  output [160:0] io_debugView_226,
  output [160:0] io_debugView_227,
  output [160:0] io_debugView_228,
  output [160:0] io_debugView_229,
  output [160:0] io_debugView_230,
  output [160:0] io_debugView_231,
  output [160:0] io_debugView_232,
  output [160:0] io_debugView_233,
  output [160:0] io_debugView_234,
  output [160:0] io_debugView_235,
  output [160:0] io_debugView_236,
  output [160:0] io_debugView_237,
  output [160:0] io_debugView_238,
  output [160:0] io_debugView_239,
  output [160:0] io_debugView_240,
  output [160:0] io_debugView_241,
  output [160:0] io_debugView_242,
  output [160:0] io_debugView_243,
  output [160:0] io_debugView_244,
  output [160:0] io_debugView_245,
  output [160:0] io_debugView_246,
  output [160:0] io_debugView_247,
  output [160:0] io_debugView_248,
  output [160:0] io_debugView_249,
  output [160:0] io_debugView_250,
  output [160:0] io_debugView_251,
  output [160:0] io_debugView_252,
  output [160:0] io_debugView_253,
  output [160:0] io_debugView_254,
  output [160:0] io_debugView_255,
  output [63:0]  io_resolved,
  output [63:0]  io_pending,
  output [63:0]  io_dropped,
  output [63:0]  io_requestCycleSum,
  output [63:0]  io_safeCycleSum,
  output [63:0]  io_statsValid
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [63:0] _RAND_1;
  reg [63:0] _RAND_2;
  reg [63:0] _RAND_3;
  reg [63:0] _RAND_4;
  reg [63:0] _RAND_5;
  reg [31:0] _RAND_6;
`endif // RANDOMIZE_REG_INIT
  wire  bucketBanks_0_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_0_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_0_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_0_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_0_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_0_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_0_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_0_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_0_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_0_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_0_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_0_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_0_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_0_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_0_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_0_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_0_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_0_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_0_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_0_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_0_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_1_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_1_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_1_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_1_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_1_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_1_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_1_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_1_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_1_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_1_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_1_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_1_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_1_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_1_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_1_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_1_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_1_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_1_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_1_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_1_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_1_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_2_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_2_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_2_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_2_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_2_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_2_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_2_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_2_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_2_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_2_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_2_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_2_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_2_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_2_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_2_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_2_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_2_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_2_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_2_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_2_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_2_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_3_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_3_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_3_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_3_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_3_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_3_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_3_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_3_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_3_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_3_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_3_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_3_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_3_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_3_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_3_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_3_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_3_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_3_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_3_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_3_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_3_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_4_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_4_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_4_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_4_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_4_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_4_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_4_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_4_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_4_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_4_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_4_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_4_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_4_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_4_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_4_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_4_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_4_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_4_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_4_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_4_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_4_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_5_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_5_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_5_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_5_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_5_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_5_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_5_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_5_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_5_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_5_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_5_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_5_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_5_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_5_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_5_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_5_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_5_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_5_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_5_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_5_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_5_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_6_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_6_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_6_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_6_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_6_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_6_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_6_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_6_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_6_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_6_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_6_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_6_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_6_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_6_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_6_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_6_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_6_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_6_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_6_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_6_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_6_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_7_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_7_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_7_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_7_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_7_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_7_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_7_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_7_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_7_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_7_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_7_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_7_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_7_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_7_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_7_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_7_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_7_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_7_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_7_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_7_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_7_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_8_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_8_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_8_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_8_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_8_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_8_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_8_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_8_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_8_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_8_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_8_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_8_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_8_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_8_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_8_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_8_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_8_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_8_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_8_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_8_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_8_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_9_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_9_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_9_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_9_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_9_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_9_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_9_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_9_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_9_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_9_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_9_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_9_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_9_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_9_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_9_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_9_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_9_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_9_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_9_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_9_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_9_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_10_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_10_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_10_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_10_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_10_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_10_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_10_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_10_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_10_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_10_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_10_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_10_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_10_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_10_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_10_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_10_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_10_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_10_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_10_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_10_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_10_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_11_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_11_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_11_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_11_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_11_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_11_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_11_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_11_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_11_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_11_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_11_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_11_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_11_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_11_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_11_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_11_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_11_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_11_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_11_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_11_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_11_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_12_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_12_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_12_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_12_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_12_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_12_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_12_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_12_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_12_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_12_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_12_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_12_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_12_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_12_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_12_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_12_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_12_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_12_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_12_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_12_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_12_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_13_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_13_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_13_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_13_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_13_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_13_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_13_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_13_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_13_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_13_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_13_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_13_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_13_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_13_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_13_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_13_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_13_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_13_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_13_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_13_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_13_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_14_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_14_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_14_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_14_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_14_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_14_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_14_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_14_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_14_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_14_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_14_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_14_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_14_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_14_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_14_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_14_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_14_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_14_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_14_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_14_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_14_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_15_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_15_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_15_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_15_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_15_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_15_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_15_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_15_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_15_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_15_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_15_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_15_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_15_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_15_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_15_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_15_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_15_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_15_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_15_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_15_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_15_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_16_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_16_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_16_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_16_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_16_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_16_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_16_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_16_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_16_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_16_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_16_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_16_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_16_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_16_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_16_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_16_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_16_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_16_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_16_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_16_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_16_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_17_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_17_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_17_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_17_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_17_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_17_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_17_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_17_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_17_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_17_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_17_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_17_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_17_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_17_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_17_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_17_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_17_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_17_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_17_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_17_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_17_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_18_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_18_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_18_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_18_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_18_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_18_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_18_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_18_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_18_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_18_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_18_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_18_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_18_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_18_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_18_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_18_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_18_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_18_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_18_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_18_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_18_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_19_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_19_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_19_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_19_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_19_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_19_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_19_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_19_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_19_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_19_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_19_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_19_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_19_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_19_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_19_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_19_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_19_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_19_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_19_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_19_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_19_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_20_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_20_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_20_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_20_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_20_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_20_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_20_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_20_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_20_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_20_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_20_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_20_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_20_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_20_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_20_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_20_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_20_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_20_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_20_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_20_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_20_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_21_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_21_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_21_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_21_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_21_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_21_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_21_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_21_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_21_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_21_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_21_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_21_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_21_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_21_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_21_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_21_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_21_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_21_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_21_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_21_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_21_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_22_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_22_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_22_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_22_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_22_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_22_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_22_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_22_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_22_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_22_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_22_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_22_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_22_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_22_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_22_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_22_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_22_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_22_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_22_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_22_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_22_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_23_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_23_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_23_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_23_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_23_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_23_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_23_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_23_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_23_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_23_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_23_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_23_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_23_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_23_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_23_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_23_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_23_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_23_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_23_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_23_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_23_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_24_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_24_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_24_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_24_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_24_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_24_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_24_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_24_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_24_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_24_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_24_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_24_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_24_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_24_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_24_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_24_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_24_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_24_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_24_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_24_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_24_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_25_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_25_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_25_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_25_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_25_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_25_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_25_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_25_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_25_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_25_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_25_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_25_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_25_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_25_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_25_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_25_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_25_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_25_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_25_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_25_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_25_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_26_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_26_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_26_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_26_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_26_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_26_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_26_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_26_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_26_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_26_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_26_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_26_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_26_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_26_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_26_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_26_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_26_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_26_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_26_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_26_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_26_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_27_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_27_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_27_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_27_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_27_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_27_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_27_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_27_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_27_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_27_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_27_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_27_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_27_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_27_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_27_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_27_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_27_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_27_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_27_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_27_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_27_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_28_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_28_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_28_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_28_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_28_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_28_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_28_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_28_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_28_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_28_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_28_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_28_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_28_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_28_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_28_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_28_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_28_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_28_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_28_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_28_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_28_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_29_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_29_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_29_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_29_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_29_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_29_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_29_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_29_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_29_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_29_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_29_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_29_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_29_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_29_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_29_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_29_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_29_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_29_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_29_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_29_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_29_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_30_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_30_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_30_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_30_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_30_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_30_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_30_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_30_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_30_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_30_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_30_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_30_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_30_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_30_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_30_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_30_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_30_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_30_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_30_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_30_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_30_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_31_clock; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_31_reset; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_31_io_observe_0; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_31_io_observe_1; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_31_io_observe_2; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_31_io_observe_3; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_31_io_observe_4; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_31_io_observe_5; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_31_io_observe_6; // @[CandidateProof.scala 53:22]
  wire [160:0] bucketBanks_31_io_observe_7; // @[CandidateProof.scala 53:22]
  wire [7:0] bucketBanks_31_io_base; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_31_io_resetStats; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_31_io_event_valid; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_31_io_event_bits; // @[CandidateProof.scala 53:22]
  wire [31:0] bucketBanks_31_io_safeWatermark; // @[CandidateProof.scala 53:22]
  wire [63:0] bucketBanks_31_io_currentCycle; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_31_io_resolvedCount; // @[CandidateProof.scala 53:22]
  wire [66:0] bucketBanks_31_io_resolvedRequest; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_31_io_eventAvailable; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_31_io_countOverflow; // @[CandidateProof.scala 53:22]
  wire  bucketBanks_31_io_cycleOverflow; // @[CandidateProof.scala 53:22]
  reg [63:0] seen; // @[CandidateProof.scala 62:21]
  reg [63:0] resolved; // @[CandidateProof.scala 63:25]
  reg [63:0] pending; // @[CandidateProof.scala 64:24]
  reg [63:0] dropped; // @[CandidateProof.scala 65:24]
  reg [63:0] requestCycleSum; // @[CandidateProof.scala 66:32]
  reg [63:0] safeCycleSum; // @[CandidateProof.scala 67:29]
  reg  statsValid; // @[CandidateProof.scala 68:27]
  wire [67:0] _resolvedBucketsWide_T = bucketBanks_0_io_resolvedCount + bucketBanks_1_io_resolvedCount; // @[CandidateProof.scala 78:29]
  wire [67:0] _resolvedBucketsWide_T_1 = bucketBanks_2_io_resolvedCount + bucketBanks_3_io_resolvedCount; // @[CandidateProof.scala 78:29]
  wire [67:0] _resolvedBucketsWide_T_2 = bucketBanks_4_io_resolvedCount + bucketBanks_5_io_resolvedCount; // @[CandidateProof.scala 78:29]
  wire [67:0] _resolvedBucketsWide_T_3 = bucketBanks_6_io_resolvedCount + bucketBanks_7_io_resolvedCount; // @[CandidateProof.scala 78:29]
  wire [67:0] _resolvedBucketsWide_T_4 = bucketBanks_8_io_resolvedCount + bucketBanks_9_io_resolvedCount; // @[CandidateProof.scala 78:29]
  wire [67:0] _resolvedBucketsWide_T_5 = bucketBanks_10_io_resolvedCount + bucketBanks_11_io_resolvedCount; // @[CandidateProof.scala 78:29]
  wire [67:0] _resolvedBucketsWide_T_6 = bucketBanks_12_io_resolvedCount + bucketBanks_13_io_resolvedCount; // @[CandidateProof.scala 78:29]
  wire [67:0] _resolvedBucketsWide_T_7 = bucketBanks_14_io_resolvedCount + bucketBanks_15_io_resolvedCount; // @[CandidateProof.scala 78:29]
  wire [67:0] _resolvedBucketsWide_T_8 = bucketBanks_16_io_resolvedCount + bucketBanks_17_io_resolvedCount; // @[CandidateProof.scala 78:29]
  wire [67:0] _resolvedBucketsWide_T_9 = bucketBanks_18_io_resolvedCount + bucketBanks_19_io_resolvedCount; // @[CandidateProof.scala 78:29]
  wire [67:0] _resolvedBucketsWide_T_10 = bucketBanks_20_io_resolvedCount + bucketBanks_21_io_resolvedCount; // @[CandidateProof.scala 78:29]
  wire [67:0] _resolvedBucketsWide_T_11 = bucketBanks_22_io_resolvedCount + bucketBanks_23_io_resolvedCount; // @[CandidateProof.scala 78:29]
  wire [67:0] _resolvedBucketsWide_T_12 = bucketBanks_24_io_resolvedCount + bucketBanks_25_io_resolvedCount; // @[CandidateProof.scala 78:29]
  wire [67:0] _resolvedBucketsWide_T_13 = bucketBanks_26_io_resolvedCount + bucketBanks_27_io_resolvedCount; // @[CandidateProof.scala 78:29]
  wire [67:0] _resolvedBucketsWide_T_14 = bucketBanks_28_io_resolvedCount + bucketBanks_29_io_resolvedCount; // @[CandidateProof.scala 78:29]
  wire [67:0] _resolvedBucketsWide_T_15 = bucketBanks_30_io_resolvedCount + bucketBanks_31_io_resolvedCount; // @[CandidateProof.scala 78:29]
  wire [68:0] _resolvedBucketsWide_T_16 = _resolvedBucketsWide_T + _resolvedBucketsWide_T_1; // @[CandidateProof.scala 78:29]
  wire [68:0] _resolvedBucketsWide_T_17 = _resolvedBucketsWide_T_2 + _resolvedBucketsWide_T_3; // @[CandidateProof.scala 78:29]
  wire [68:0] _resolvedBucketsWide_T_18 = _resolvedBucketsWide_T_4 + _resolvedBucketsWide_T_5; // @[CandidateProof.scala 78:29]
  wire [68:0] _resolvedBucketsWide_T_19 = _resolvedBucketsWide_T_6 + _resolvedBucketsWide_T_7; // @[CandidateProof.scala 78:29]
  wire [68:0] _resolvedBucketsWide_T_20 = _resolvedBucketsWide_T_8 + _resolvedBucketsWide_T_9; // @[CandidateProof.scala 78:29]
  wire [68:0] _resolvedBucketsWide_T_21 = _resolvedBucketsWide_T_10 + _resolvedBucketsWide_T_11; // @[CandidateProof.scala 78:29]
  wire [68:0] _resolvedBucketsWide_T_22 = _resolvedBucketsWide_T_12 + _resolvedBucketsWide_T_13; // @[CandidateProof.scala 78:29]
  wire [68:0] _resolvedBucketsWide_T_23 = _resolvedBucketsWide_T_14 + _resolvedBucketsWide_T_15; // @[CandidateProof.scala 78:29]
  wire [69:0] _resolvedBucketsWide_T_24 = _resolvedBucketsWide_T_16 + _resolvedBucketsWide_T_17; // @[CandidateProof.scala 78:29]
  wire [69:0] _resolvedBucketsWide_T_25 = _resolvedBucketsWide_T_18 + _resolvedBucketsWide_T_19; // @[CandidateProof.scala 78:29]
  wire [69:0] _resolvedBucketsWide_T_26 = _resolvedBucketsWide_T_20 + _resolvedBucketsWide_T_21; // @[CandidateProof.scala 78:29]
  wire [69:0] _resolvedBucketsWide_T_27 = _resolvedBucketsWide_T_22 + _resolvedBucketsWide_T_23; // @[CandidateProof.scala 78:29]
  wire [70:0] _resolvedBucketsWide_T_28 = _resolvedBucketsWide_T_24 + _resolvedBucketsWide_T_25; // @[CandidateProof.scala 78:29]
  wire [70:0] _resolvedBucketsWide_T_29 = _resolvedBucketsWide_T_26 + _resolvedBucketsWide_T_27; // @[CandidateProof.scala 78:29]
  wire [71:0] _resolvedBucketsWide_T_30 = _resolvedBucketsWide_T_28 + _resolvedBucketsWide_T_29; // @[CandidateProof.scala 78:29]
  wire [72:0] resolvedBucketsWide = {{1'd0}, _resolvedBucketsWide_T_30}; // @[CandidateProof.scala 82:20]
  wire [67:0] _requestBucketsWide_T = bucketBanks_0_io_resolvedRequest + bucketBanks_1_io_resolvedRequest; // @[CandidateProof.scala 78:29]
  wire [67:0] _requestBucketsWide_T_1 = bucketBanks_2_io_resolvedRequest + bucketBanks_3_io_resolvedRequest; // @[CandidateProof.scala 78:29]
  wire [67:0] _requestBucketsWide_T_2 = bucketBanks_4_io_resolvedRequest + bucketBanks_5_io_resolvedRequest; // @[CandidateProof.scala 78:29]
  wire [67:0] _requestBucketsWide_T_3 = bucketBanks_6_io_resolvedRequest + bucketBanks_7_io_resolvedRequest; // @[CandidateProof.scala 78:29]
  wire [67:0] _requestBucketsWide_T_4 = bucketBanks_8_io_resolvedRequest + bucketBanks_9_io_resolvedRequest; // @[CandidateProof.scala 78:29]
  wire [67:0] _requestBucketsWide_T_5 = bucketBanks_10_io_resolvedRequest + bucketBanks_11_io_resolvedRequest; // @[CandidateProof.scala 78:29]
  wire [67:0] _requestBucketsWide_T_6 = bucketBanks_12_io_resolvedRequest + bucketBanks_13_io_resolvedRequest; // @[CandidateProof.scala 78:29]
  wire [67:0] _requestBucketsWide_T_7 = bucketBanks_14_io_resolvedRequest + bucketBanks_15_io_resolvedRequest; // @[CandidateProof.scala 78:29]
  wire [67:0] _requestBucketsWide_T_8 = bucketBanks_16_io_resolvedRequest + bucketBanks_17_io_resolvedRequest; // @[CandidateProof.scala 78:29]
  wire [67:0] _requestBucketsWide_T_9 = bucketBanks_18_io_resolvedRequest + bucketBanks_19_io_resolvedRequest; // @[CandidateProof.scala 78:29]
  wire [67:0] _requestBucketsWide_T_10 = bucketBanks_20_io_resolvedRequest + bucketBanks_21_io_resolvedRequest; // @[CandidateProof.scala 78:29]
  wire [67:0] _requestBucketsWide_T_11 = bucketBanks_22_io_resolvedRequest + bucketBanks_23_io_resolvedRequest; // @[CandidateProof.scala 78:29]
  wire [67:0] _requestBucketsWide_T_12 = bucketBanks_24_io_resolvedRequest + bucketBanks_25_io_resolvedRequest; // @[CandidateProof.scala 78:29]
  wire [67:0] _requestBucketsWide_T_13 = bucketBanks_26_io_resolvedRequest + bucketBanks_27_io_resolvedRequest; // @[CandidateProof.scala 78:29]
  wire [67:0] _requestBucketsWide_T_14 = bucketBanks_28_io_resolvedRequest + bucketBanks_29_io_resolvedRequest; // @[CandidateProof.scala 78:29]
  wire [67:0] _requestBucketsWide_T_15 = bucketBanks_30_io_resolvedRequest + bucketBanks_31_io_resolvedRequest; // @[CandidateProof.scala 78:29]
  wire [68:0] _requestBucketsWide_T_16 = _requestBucketsWide_T + _requestBucketsWide_T_1; // @[CandidateProof.scala 78:29]
  wire [68:0] _requestBucketsWide_T_17 = _requestBucketsWide_T_2 + _requestBucketsWide_T_3; // @[CandidateProof.scala 78:29]
  wire [68:0] _requestBucketsWide_T_18 = _requestBucketsWide_T_4 + _requestBucketsWide_T_5; // @[CandidateProof.scala 78:29]
  wire [68:0] _requestBucketsWide_T_19 = _requestBucketsWide_T_6 + _requestBucketsWide_T_7; // @[CandidateProof.scala 78:29]
  wire [68:0] _requestBucketsWide_T_20 = _requestBucketsWide_T_8 + _requestBucketsWide_T_9; // @[CandidateProof.scala 78:29]
  wire [68:0] _requestBucketsWide_T_21 = _requestBucketsWide_T_10 + _requestBucketsWide_T_11; // @[CandidateProof.scala 78:29]
  wire [68:0] _requestBucketsWide_T_22 = _requestBucketsWide_T_12 + _requestBucketsWide_T_13; // @[CandidateProof.scala 78:29]
  wire [68:0] _requestBucketsWide_T_23 = _requestBucketsWide_T_14 + _requestBucketsWide_T_15; // @[CandidateProof.scala 78:29]
  wire [69:0] _requestBucketsWide_T_24 = _requestBucketsWide_T_16 + _requestBucketsWide_T_17; // @[CandidateProof.scala 78:29]
  wire [69:0] _requestBucketsWide_T_25 = _requestBucketsWide_T_18 + _requestBucketsWide_T_19; // @[CandidateProof.scala 78:29]
  wire [69:0] _requestBucketsWide_T_26 = _requestBucketsWide_T_20 + _requestBucketsWide_T_21; // @[CandidateProof.scala 78:29]
  wire [69:0] _requestBucketsWide_T_27 = _requestBucketsWide_T_22 + _requestBucketsWide_T_23; // @[CandidateProof.scala 78:29]
  wire [70:0] _requestBucketsWide_T_28 = _requestBucketsWide_T_24 + _requestBucketsWide_T_25; // @[CandidateProof.scala 78:29]
  wire [70:0] _requestBucketsWide_T_29 = _requestBucketsWide_T_26 + _requestBucketsWide_T_27; // @[CandidateProof.scala 78:29]
  wire [71:0] _requestBucketsWide_T_30 = _requestBucketsWide_T_28 + _requestBucketsWide_T_29; // @[CandidateProof.scala 78:29]
  wire [72:0] requestBucketsWide = {{1'd0}, _requestBucketsWide_T_30}; // @[CandidateProof.scala 82:20]
  wire [136:0] safeBucketsWide = io_currentCycle * resolvedBucketsWide; // @[CandidateProof.scala 88:41]
  wire  eventImmediate = io_event_valid & io_event_bits <= io_safeWatermark; // @[CandidateProof.scala 93:39]
  wire  eventNeedsBucket = io_event_valid & ~eventImmediate; // @[CandidateProof.scala 94:41]
  wire  _eventBucketAvailable_T_29 = bucketBanks_0_io_eventAvailable | bucketBanks_1_io_eventAvailable |
    bucketBanks_2_io_eventAvailable | bucketBanks_3_io_eventAvailable | bucketBanks_4_io_eventAvailable |
    bucketBanks_5_io_eventAvailable | bucketBanks_6_io_eventAvailable | bucketBanks_7_io_eventAvailable |
    bucketBanks_8_io_eventAvailable | bucketBanks_9_io_eventAvailable | bucketBanks_10_io_eventAvailable |
    bucketBanks_11_io_eventAvailable | bucketBanks_12_io_eventAvailable | bucketBanks_13_io_eventAvailable |
    bucketBanks_14_io_eventAvailable | bucketBanks_15_io_eventAvailable | bucketBanks_16_io_eventAvailable |
    bucketBanks_17_io_eventAvailable | bucketBanks_18_io_eventAvailable | bucketBanks_19_io_eventAvailable |
    bucketBanks_20_io_eventAvailable | bucketBanks_21_io_eventAvailable | bucketBanks_22_io_eventAvailable |
    bucketBanks_23_io_eventAvailable | bucketBanks_24_io_eventAvailable | bucketBanks_25_io_eventAvailable |
    bucketBanks_26_io_eventAvailable | bucketBanks_27_io_eventAvailable | bucketBanks_28_io_eventAvailable |
    bucketBanks_29_io_eventAvailable | bucketBanks_30_io_eventAvailable; // @[CandidateProof.scala 96:76]
  wire  eventBucketAvailable = _eventBucketAvailable_T_29 | bucketBanks_31_io_eventAvailable; // @[CandidateProof.scala 96:76]
  wire  eventAccepted = eventNeedsBucket & eventBucketAvailable; // @[CandidateProof.scala 97:40]
  wire  eventDropped = eventNeedsBucket & ~eventBucketAvailable; // @[CandidateProof.scala 98:39]
  wire [72:0] _resolvedThisCycleWide_T = eventImmediate ? 73'h1 : 73'h0; // @[CandidateProof.scala 101:8]
  wire [72:0] resolvedThisCycleWide = resolvedBucketsWide + _resolvedThisCycleWide_T; // @[CandidateProof.scala 100:51]
  wire [63:0] _requestThisCycleWide_T = eventImmediate ? io_currentCycle : 64'h0; // @[CandidateProof.scala 103:8]
  wire [72:0] _requestThisCycleWide_T_1 = {{9'd0}, _requestThisCycleWide_T}; // @[CandidateProof.scala 103:56]
  wire [72:0] requestThisCycleWide = requestBucketsWide + _requestThisCycleWide_T_1; // @[CandidateProof.scala 102:49]
  wire [136:0] _safeThisCycleWide_T_1 = {{73'd0}, _requestThisCycleWide_T}; // @[CandidateProof.scala 105:56]
  wire [136:0] safeThisCycleWide = safeBucketsWide + _safeThisCycleWide_T_1; // @[CandidateProof.scala 104:43]
  wire [72:0] _pendingBeforeResolve_T = {{9'd0}, pending}; // @[CandidateProof.scala 107:41]
  wire [72:0] _GEN_14 = {{72'd0}, eventAccepted}; // @[CandidateProof.scala 107:46]
  wire [72:0] pendingBeforeResolve = _pendingBeforeResolve_T + _GEN_14; // @[CandidateProof.scala 107:46]
  wire  pendingUnderflow = resolvedBucketsWide > pendingBeforeResolve; // @[CandidateProof.scala 108:46]
  wire [72:0] pendingNextWide = pendingBeforeResolve - resolvedBucketsWide; // @[CandidateProof.scala 109:46]
  wire  _bucketCountOverflow_T_29 = bucketBanks_0_io_countOverflow | bucketBanks_1_io_countOverflow |
    bucketBanks_2_io_countOverflow | bucketBanks_3_io_countOverflow | bucketBanks_4_io_countOverflow |
    bucketBanks_5_io_countOverflow | bucketBanks_6_io_countOverflow | bucketBanks_7_io_countOverflow |
    bucketBanks_8_io_countOverflow | bucketBanks_9_io_countOverflow | bucketBanks_10_io_countOverflow |
    bucketBanks_11_io_countOverflow | bucketBanks_12_io_countOverflow | bucketBanks_13_io_countOverflow |
    bucketBanks_14_io_countOverflow | bucketBanks_15_io_countOverflow | bucketBanks_16_io_countOverflow |
    bucketBanks_17_io_countOverflow | bucketBanks_18_io_countOverflow | bucketBanks_19_io_countOverflow |
    bucketBanks_20_io_countOverflow | bucketBanks_21_io_countOverflow | bucketBanks_22_io_countOverflow |
    bucketBanks_23_io_countOverflow | bucketBanks_24_io_countOverflow | bucketBanks_25_io_countOverflow |
    bucketBanks_26_io_countOverflow | bucketBanks_27_io_countOverflow | bucketBanks_28_io_countOverflow |
    bucketBanks_29_io_countOverflow | bucketBanks_30_io_countOverflow; // @[CandidateProof.scala 111:74]
  wire  bucketCountOverflow = _bucketCountOverflow_T_29 | bucketBanks_31_io_countOverflow; // @[CandidateProof.scala 111:74]
  wire  _bucketCycleOverflow_T_29 = bucketBanks_0_io_cycleOverflow | bucketBanks_1_io_cycleOverflow |
    bucketBanks_2_io_cycleOverflow | bucketBanks_3_io_cycleOverflow | bucketBanks_4_io_cycleOverflow |
    bucketBanks_5_io_cycleOverflow | bucketBanks_6_io_cycleOverflow | bucketBanks_7_io_cycleOverflow |
    bucketBanks_8_io_cycleOverflow | bucketBanks_9_io_cycleOverflow | bucketBanks_10_io_cycleOverflow |
    bucketBanks_11_io_cycleOverflow | bucketBanks_12_io_cycleOverflow | bucketBanks_13_io_cycleOverflow |
    bucketBanks_14_io_cycleOverflow | bucketBanks_15_io_cycleOverflow | bucketBanks_16_io_cycleOverflow |
    bucketBanks_17_io_cycleOverflow | bucketBanks_18_io_cycleOverflow | bucketBanks_19_io_cycleOverflow |
    bucketBanks_20_io_cycleOverflow | bucketBanks_21_io_cycleOverflow | bucketBanks_22_io_cycleOverflow |
    bucketBanks_23_io_cycleOverflow | bucketBanks_24_io_cycleOverflow | bucketBanks_25_io_cycleOverflow |
    bucketBanks_26_io_cycleOverflow | bucketBanks_27_io_cycleOverflow | bucketBanks_28_io_cycleOverflow |
    bucketBanks_29_io_cycleOverflow | bucketBanks_30_io_cycleOverflow; // @[CandidateProof.scala 112:74]
  wire  bucketCycleOverflow = _bucketCycleOverflow_T_29 | bucketBanks_31_io_cycleOverflow; // @[CandidateProof.scala 112:74]
  wire  _reductionOverflow_T_3 = |requestThisCycleWide[72:64]; // @[CandidateProof.scala 114:34]
  wire  _reductionOverflow_T_4 = |resolvedThisCycleWide[72:64] | _reductionOverflow_T_3; // @[CandidateProof.scala 113:61]
  wire  _reductionOverflow_T_9 = |pendingNextWide[72:64]; // @[CandidateProof.scala 115:29]
  wire  reductionOverflow = _reductionOverflow_T_4 | |safeThisCycleWide[136:64] | _reductionOverflow_T_9; // @[CandidateProof.scala 114:72]
  wire  _counterOverflow_T_5 = eventDropped & dropped == 64'hffffffffffffffff; // @[CandidateProof.scala 118:19]
  wire  _counterOverflow_T_6 = io_event_valid & seen == 64'hffffffffffffffff | _counterOverflow_T_5; // @[CandidateProof.scala 117:45]
  wire  _counterOverflow_T_7 = |resolvedThisCycleWide; // @[CandidateProof.scala 119:28]
  wire [63:0] _counterOverflow_T_11 = 64'hffffffffffffffff - resolvedThisCycleWide[63:0]; // @[CandidateProof.scala 120:30]
  wire  _counterOverflow_T_12 = resolved > _counterOverflow_T_11; // @[CandidateProof.scala 120:16]
  wire  _counterOverflow_T_13 = |resolvedThisCycleWide & _counterOverflow_T_12; // @[CandidateProof.scala 119:32]
  wire  _counterOverflow_T_14 = _counterOverflow_T_6 | _counterOverflow_T_13; // @[CandidateProof.scala 118:46]
  wire [63:0] _counterOverflow_T_19 = 64'hffffffffffffffff - requestThisCycleWide[63:0]; // @[CandidateProof.scala 122:37]
  wire  _counterOverflow_T_20 = requestCycleSum > _counterOverflow_T_19; // @[CandidateProof.scala 122:23]
  wire  _counterOverflow_T_21 = |requestThisCycleWide & _counterOverflow_T_20; // @[CandidateProof.scala 121:31]
  wire  _counterOverflow_T_22 = _counterOverflow_T_14 | _counterOverflow_T_21; // @[CandidateProof.scala 120:63]
  wire [63:0] _counterOverflow_T_27 = 64'hffffffffffffffff - safeThisCycleWide[63:0]; // @[CandidateProof.scala 124:34]
  wire  _counterOverflow_T_28 = safeCycleSum > _counterOverflow_T_27; // @[CandidateProof.scala 124:20]
  wire  _counterOverflow_T_29 = |safeThisCycleWide & _counterOverflow_T_28; // @[CandidateProof.scala 123:28]
  wire  counterOverflow = _counterOverflow_T_22 | _counterOverflow_T_29; // @[CandidateProof.scala 122:69]
  wire  _arithmeticError_T_1 = bucketCountOverflow | bucketCycleOverflow | reductionOverflow; // @[CandidateProof.scala 125:68]
  wire  arithmeticError = _arithmeticError_T_1 | counterOverflow | pendingUnderflow; // @[CandidateProof.scala 126:42]
  wire [63:0] _seen_T_1 = seen + 64'h1; // @[CandidateProof.scala 137:42]
  wire [63:0] _dropped_T_1 = dropped + 64'h1; // @[CandidateProof.scala 138:46]
  wire [63:0] _resolved_T_2 = resolved + resolvedThisCycleWide[63:0]; // @[CandidateProof.scala 140:28]
  wire [63:0] _requestCycleSum_T_2 = requestCycleSum + requestThisCycleWide[63:0]; // @[CandidateProof.scala 141:42]
  wire [63:0] _safeCycleSum_T_2 = safeCycleSum + safeThisCycleWide[63:0]; // @[CandidateProof.scala 142:36]
  wire  _GEN_6 = eventDropped | arithmeticError | io_fatalProtocolError ? 1'h0 : statsValid; // @[CandidateProof.scala 147:69 148:18 68:27]
  wire  _GEN_13 = io_resetStats | _GEN_6; // @[CandidateProof.scala 128:24 135:16]
  GHBarrierBucketBank bucketBanks_0 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_0_clock),
    .reset(bucketBanks_0_reset),
    .io_observe_0(bucketBanks_0_io_observe_0),
    .io_observe_1(bucketBanks_0_io_observe_1),
    .io_observe_2(bucketBanks_0_io_observe_2),
    .io_observe_3(bucketBanks_0_io_observe_3),
    .io_observe_4(bucketBanks_0_io_observe_4),
    .io_observe_5(bucketBanks_0_io_observe_5),
    .io_observe_6(bucketBanks_0_io_observe_6),
    .io_observe_7(bucketBanks_0_io_observe_7),
    .io_base(bucketBanks_0_io_base),
    .io_resetStats(bucketBanks_0_io_resetStats),
    .io_event_valid(bucketBanks_0_io_event_valid),
    .io_event_bits(bucketBanks_0_io_event_bits),
    .io_safeWatermark(bucketBanks_0_io_safeWatermark),
    .io_currentCycle(bucketBanks_0_io_currentCycle),
    .io_resolvedCount(bucketBanks_0_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_0_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_0_io_eventAvailable),
    .io_countOverflow(bucketBanks_0_io_countOverflow),
    .io_cycleOverflow(bucketBanks_0_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_1 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_1_clock),
    .reset(bucketBanks_1_reset),
    .io_observe_0(bucketBanks_1_io_observe_0),
    .io_observe_1(bucketBanks_1_io_observe_1),
    .io_observe_2(bucketBanks_1_io_observe_2),
    .io_observe_3(bucketBanks_1_io_observe_3),
    .io_observe_4(bucketBanks_1_io_observe_4),
    .io_observe_5(bucketBanks_1_io_observe_5),
    .io_observe_6(bucketBanks_1_io_observe_6),
    .io_observe_7(bucketBanks_1_io_observe_7),
    .io_base(bucketBanks_1_io_base),
    .io_resetStats(bucketBanks_1_io_resetStats),
    .io_event_valid(bucketBanks_1_io_event_valid),
    .io_event_bits(bucketBanks_1_io_event_bits),
    .io_safeWatermark(bucketBanks_1_io_safeWatermark),
    .io_currentCycle(bucketBanks_1_io_currentCycle),
    .io_resolvedCount(bucketBanks_1_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_1_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_1_io_eventAvailable),
    .io_countOverflow(bucketBanks_1_io_countOverflow),
    .io_cycleOverflow(bucketBanks_1_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_2 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_2_clock),
    .reset(bucketBanks_2_reset),
    .io_observe_0(bucketBanks_2_io_observe_0),
    .io_observe_1(bucketBanks_2_io_observe_1),
    .io_observe_2(bucketBanks_2_io_observe_2),
    .io_observe_3(bucketBanks_2_io_observe_3),
    .io_observe_4(bucketBanks_2_io_observe_4),
    .io_observe_5(bucketBanks_2_io_observe_5),
    .io_observe_6(bucketBanks_2_io_observe_6),
    .io_observe_7(bucketBanks_2_io_observe_7),
    .io_base(bucketBanks_2_io_base),
    .io_resetStats(bucketBanks_2_io_resetStats),
    .io_event_valid(bucketBanks_2_io_event_valid),
    .io_event_bits(bucketBanks_2_io_event_bits),
    .io_safeWatermark(bucketBanks_2_io_safeWatermark),
    .io_currentCycle(bucketBanks_2_io_currentCycle),
    .io_resolvedCount(bucketBanks_2_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_2_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_2_io_eventAvailable),
    .io_countOverflow(bucketBanks_2_io_countOverflow),
    .io_cycleOverflow(bucketBanks_2_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_3 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_3_clock),
    .reset(bucketBanks_3_reset),
    .io_observe_0(bucketBanks_3_io_observe_0),
    .io_observe_1(bucketBanks_3_io_observe_1),
    .io_observe_2(bucketBanks_3_io_observe_2),
    .io_observe_3(bucketBanks_3_io_observe_3),
    .io_observe_4(bucketBanks_3_io_observe_4),
    .io_observe_5(bucketBanks_3_io_observe_5),
    .io_observe_6(bucketBanks_3_io_observe_6),
    .io_observe_7(bucketBanks_3_io_observe_7),
    .io_base(bucketBanks_3_io_base),
    .io_resetStats(bucketBanks_3_io_resetStats),
    .io_event_valid(bucketBanks_3_io_event_valid),
    .io_event_bits(bucketBanks_3_io_event_bits),
    .io_safeWatermark(bucketBanks_3_io_safeWatermark),
    .io_currentCycle(bucketBanks_3_io_currentCycle),
    .io_resolvedCount(bucketBanks_3_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_3_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_3_io_eventAvailable),
    .io_countOverflow(bucketBanks_3_io_countOverflow),
    .io_cycleOverflow(bucketBanks_3_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_4 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_4_clock),
    .reset(bucketBanks_4_reset),
    .io_observe_0(bucketBanks_4_io_observe_0),
    .io_observe_1(bucketBanks_4_io_observe_1),
    .io_observe_2(bucketBanks_4_io_observe_2),
    .io_observe_3(bucketBanks_4_io_observe_3),
    .io_observe_4(bucketBanks_4_io_observe_4),
    .io_observe_5(bucketBanks_4_io_observe_5),
    .io_observe_6(bucketBanks_4_io_observe_6),
    .io_observe_7(bucketBanks_4_io_observe_7),
    .io_base(bucketBanks_4_io_base),
    .io_resetStats(bucketBanks_4_io_resetStats),
    .io_event_valid(bucketBanks_4_io_event_valid),
    .io_event_bits(bucketBanks_4_io_event_bits),
    .io_safeWatermark(bucketBanks_4_io_safeWatermark),
    .io_currentCycle(bucketBanks_4_io_currentCycle),
    .io_resolvedCount(bucketBanks_4_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_4_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_4_io_eventAvailable),
    .io_countOverflow(bucketBanks_4_io_countOverflow),
    .io_cycleOverflow(bucketBanks_4_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_5 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_5_clock),
    .reset(bucketBanks_5_reset),
    .io_observe_0(bucketBanks_5_io_observe_0),
    .io_observe_1(bucketBanks_5_io_observe_1),
    .io_observe_2(bucketBanks_5_io_observe_2),
    .io_observe_3(bucketBanks_5_io_observe_3),
    .io_observe_4(bucketBanks_5_io_observe_4),
    .io_observe_5(bucketBanks_5_io_observe_5),
    .io_observe_6(bucketBanks_5_io_observe_6),
    .io_observe_7(bucketBanks_5_io_observe_7),
    .io_base(bucketBanks_5_io_base),
    .io_resetStats(bucketBanks_5_io_resetStats),
    .io_event_valid(bucketBanks_5_io_event_valid),
    .io_event_bits(bucketBanks_5_io_event_bits),
    .io_safeWatermark(bucketBanks_5_io_safeWatermark),
    .io_currentCycle(bucketBanks_5_io_currentCycle),
    .io_resolvedCount(bucketBanks_5_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_5_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_5_io_eventAvailable),
    .io_countOverflow(bucketBanks_5_io_countOverflow),
    .io_cycleOverflow(bucketBanks_5_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_6 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_6_clock),
    .reset(bucketBanks_6_reset),
    .io_observe_0(bucketBanks_6_io_observe_0),
    .io_observe_1(bucketBanks_6_io_observe_1),
    .io_observe_2(bucketBanks_6_io_observe_2),
    .io_observe_3(bucketBanks_6_io_observe_3),
    .io_observe_4(bucketBanks_6_io_observe_4),
    .io_observe_5(bucketBanks_6_io_observe_5),
    .io_observe_6(bucketBanks_6_io_observe_6),
    .io_observe_7(bucketBanks_6_io_observe_7),
    .io_base(bucketBanks_6_io_base),
    .io_resetStats(bucketBanks_6_io_resetStats),
    .io_event_valid(bucketBanks_6_io_event_valid),
    .io_event_bits(bucketBanks_6_io_event_bits),
    .io_safeWatermark(bucketBanks_6_io_safeWatermark),
    .io_currentCycle(bucketBanks_6_io_currentCycle),
    .io_resolvedCount(bucketBanks_6_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_6_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_6_io_eventAvailable),
    .io_countOverflow(bucketBanks_6_io_countOverflow),
    .io_cycleOverflow(bucketBanks_6_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_7 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_7_clock),
    .reset(bucketBanks_7_reset),
    .io_observe_0(bucketBanks_7_io_observe_0),
    .io_observe_1(bucketBanks_7_io_observe_1),
    .io_observe_2(bucketBanks_7_io_observe_2),
    .io_observe_3(bucketBanks_7_io_observe_3),
    .io_observe_4(bucketBanks_7_io_observe_4),
    .io_observe_5(bucketBanks_7_io_observe_5),
    .io_observe_6(bucketBanks_7_io_observe_6),
    .io_observe_7(bucketBanks_7_io_observe_7),
    .io_base(bucketBanks_7_io_base),
    .io_resetStats(bucketBanks_7_io_resetStats),
    .io_event_valid(bucketBanks_7_io_event_valid),
    .io_event_bits(bucketBanks_7_io_event_bits),
    .io_safeWatermark(bucketBanks_7_io_safeWatermark),
    .io_currentCycle(bucketBanks_7_io_currentCycle),
    .io_resolvedCount(bucketBanks_7_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_7_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_7_io_eventAvailable),
    .io_countOverflow(bucketBanks_7_io_countOverflow),
    .io_cycleOverflow(bucketBanks_7_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_8 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_8_clock),
    .reset(bucketBanks_8_reset),
    .io_observe_0(bucketBanks_8_io_observe_0),
    .io_observe_1(bucketBanks_8_io_observe_1),
    .io_observe_2(bucketBanks_8_io_observe_2),
    .io_observe_3(bucketBanks_8_io_observe_3),
    .io_observe_4(bucketBanks_8_io_observe_4),
    .io_observe_5(bucketBanks_8_io_observe_5),
    .io_observe_6(bucketBanks_8_io_observe_6),
    .io_observe_7(bucketBanks_8_io_observe_7),
    .io_base(bucketBanks_8_io_base),
    .io_resetStats(bucketBanks_8_io_resetStats),
    .io_event_valid(bucketBanks_8_io_event_valid),
    .io_event_bits(bucketBanks_8_io_event_bits),
    .io_safeWatermark(bucketBanks_8_io_safeWatermark),
    .io_currentCycle(bucketBanks_8_io_currentCycle),
    .io_resolvedCount(bucketBanks_8_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_8_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_8_io_eventAvailable),
    .io_countOverflow(bucketBanks_8_io_countOverflow),
    .io_cycleOverflow(bucketBanks_8_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_9 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_9_clock),
    .reset(bucketBanks_9_reset),
    .io_observe_0(bucketBanks_9_io_observe_0),
    .io_observe_1(bucketBanks_9_io_observe_1),
    .io_observe_2(bucketBanks_9_io_observe_2),
    .io_observe_3(bucketBanks_9_io_observe_3),
    .io_observe_4(bucketBanks_9_io_observe_4),
    .io_observe_5(bucketBanks_9_io_observe_5),
    .io_observe_6(bucketBanks_9_io_observe_6),
    .io_observe_7(bucketBanks_9_io_observe_7),
    .io_base(bucketBanks_9_io_base),
    .io_resetStats(bucketBanks_9_io_resetStats),
    .io_event_valid(bucketBanks_9_io_event_valid),
    .io_event_bits(bucketBanks_9_io_event_bits),
    .io_safeWatermark(bucketBanks_9_io_safeWatermark),
    .io_currentCycle(bucketBanks_9_io_currentCycle),
    .io_resolvedCount(bucketBanks_9_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_9_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_9_io_eventAvailable),
    .io_countOverflow(bucketBanks_9_io_countOverflow),
    .io_cycleOverflow(bucketBanks_9_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_10 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_10_clock),
    .reset(bucketBanks_10_reset),
    .io_observe_0(bucketBanks_10_io_observe_0),
    .io_observe_1(bucketBanks_10_io_observe_1),
    .io_observe_2(bucketBanks_10_io_observe_2),
    .io_observe_3(bucketBanks_10_io_observe_3),
    .io_observe_4(bucketBanks_10_io_observe_4),
    .io_observe_5(bucketBanks_10_io_observe_5),
    .io_observe_6(bucketBanks_10_io_observe_6),
    .io_observe_7(bucketBanks_10_io_observe_7),
    .io_base(bucketBanks_10_io_base),
    .io_resetStats(bucketBanks_10_io_resetStats),
    .io_event_valid(bucketBanks_10_io_event_valid),
    .io_event_bits(bucketBanks_10_io_event_bits),
    .io_safeWatermark(bucketBanks_10_io_safeWatermark),
    .io_currentCycle(bucketBanks_10_io_currentCycle),
    .io_resolvedCount(bucketBanks_10_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_10_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_10_io_eventAvailable),
    .io_countOverflow(bucketBanks_10_io_countOverflow),
    .io_cycleOverflow(bucketBanks_10_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_11 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_11_clock),
    .reset(bucketBanks_11_reset),
    .io_observe_0(bucketBanks_11_io_observe_0),
    .io_observe_1(bucketBanks_11_io_observe_1),
    .io_observe_2(bucketBanks_11_io_observe_2),
    .io_observe_3(bucketBanks_11_io_observe_3),
    .io_observe_4(bucketBanks_11_io_observe_4),
    .io_observe_5(bucketBanks_11_io_observe_5),
    .io_observe_6(bucketBanks_11_io_observe_6),
    .io_observe_7(bucketBanks_11_io_observe_7),
    .io_base(bucketBanks_11_io_base),
    .io_resetStats(bucketBanks_11_io_resetStats),
    .io_event_valid(bucketBanks_11_io_event_valid),
    .io_event_bits(bucketBanks_11_io_event_bits),
    .io_safeWatermark(bucketBanks_11_io_safeWatermark),
    .io_currentCycle(bucketBanks_11_io_currentCycle),
    .io_resolvedCount(bucketBanks_11_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_11_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_11_io_eventAvailable),
    .io_countOverflow(bucketBanks_11_io_countOverflow),
    .io_cycleOverflow(bucketBanks_11_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_12 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_12_clock),
    .reset(bucketBanks_12_reset),
    .io_observe_0(bucketBanks_12_io_observe_0),
    .io_observe_1(bucketBanks_12_io_observe_1),
    .io_observe_2(bucketBanks_12_io_observe_2),
    .io_observe_3(bucketBanks_12_io_observe_3),
    .io_observe_4(bucketBanks_12_io_observe_4),
    .io_observe_5(bucketBanks_12_io_observe_5),
    .io_observe_6(bucketBanks_12_io_observe_6),
    .io_observe_7(bucketBanks_12_io_observe_7),
    .io_base(bucketBanks_12_io_base),
    .io_resetStats(bucketBanks_12_io_resetStats),
    .io_event_valid(bucketBanks_12_io_event_valid),
    .io_event_bits(bucketBanks_12_io_event_bits),
    .io_safeWatermark(bucketBanks_12_io_safeWatermark),
    .io_currentCycle(bucketBanks_12_io_currentCycle),
    .io_resolvedCount(bucketBanks_12_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_12_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_12_io_eventAvailable),
    .io_countOverflow(bucketBanks_12_io_countOverflow),
    .io_cycleOverflow(bucketBanks_12_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_13 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_13_clock),
    .reset(bucketBanks_13_reset),
    .io_observe_0(bucketBanks_13_io_observe_0),
    .io_observe_1(bucketBanks_13_io_observe_1),
    .io_observe_2(bucketBanks_13_io_observe_2),
    .io_observe_3(bucketBanks_13_io_observe_3),
    .io_observe_4(bucketBanks_13_io_observe_4),
    .io_observe_5(bucketBanks_13_io_observe_5),
    .io_observe_6(bucketBanks_13_io_observe_6),
    .io_observe_7(bucketBanks_13_io_observe_7),
    .io_base(bucketBanks_13_io_base),
    .io_resetStats(bucketBanks_13_io_resetStats),
    .io_event_valid(bucketBanks_13_io_event_valid),
    .io_event_bits(bucketBanks_13_io_event_bits),
    .io_safeWatermark(bucketBanks_13_io_safeWatermark),
    .io_currentCycle(bucketBanks_13_io_currentCycle),
    .io_resolvedCount(bucketBanks_13_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_13_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_13_io_eventAvailable),
    .io_countOverflow(bucketBanks_13_io_countOverflow),
    .io_cycleOverflow(bucketBanks_13_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_14 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_14_clock),
    .reset(bucketBanks_14_reset),
    .io_observe_0(bucketBanks_14_io_observe_0),
    .io_observe_1(bucketBanks_14_io_observe_1),
    .io_observe_2(bucketBanks_14_io_observe_2),
    .io_observe_3(bucketBanks_14_io_observe_3),
    .io_observe_4(bucketBanks_14_io_observe_4),
    .io_observe_5(bucketBanks_14_io_observe_5),
    .io_observe_6(bucketBanks_14_io_observe_6),
    .io_observe_7(bucketBanks_14_io_observe_7),
    .io_base(bucketBanks_14_io_base),
    .io_resetStats(bucketBanks_14_io_resetStats),
    .io_event_valid(bucketBanks_14_io_event_valid),
    .io_event_bits(bucketBanks_14_io_event_bits),
    .io_safeWatermark(bucketBanks_14_io_safeWatermark),
    .io_currentCycle(bucketBanks_14_io_currentCycle),
    .io_resolvedCount(bucketBanks_14_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_14_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_14_io_eventAvailable),
    .io_countOverflow(bucketBanks_14_io_countOverflow),
    .io_cycleOverflow(bucketBanks_14_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_15 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_15_clock),
    .reset(bucketBanks_15_reset),
    .io_observe_0(bucketBanks_15_io_observe_0),
    .io_observe_1(bucketBanks_15_io_observe_1),
    .io_observe_2(bucketBanks_15_io_observe_2),
    .io_observe_3(bucketBanks_15_io_observe_3),
    .io_observe_4(bucketBanks_15_io_observe_4),
    .io_observe_5(bucketBanks_15_io_observe_5),
    .io_observe_6(bucketBanks_15_io_observe_6),
    .io_observe_7(bucketBanks_15_io_observe_7),
    .io_base(bucketBanks_15_io_base),
    .io_resetStats(bucketBanks_15_io_resetStats),
    .io_event_valid(bucketBanks_15_io_event_valid),
    .io_event_bits(bucketBanks_15_io_event_bits),
    .io_safeWatermark(bucketBanks_15_io_safeWatermark),
    .io_currentCycle(bucketBanks_15_io_currentCycle),
    .io_resolvedCount(bucketBanks_15_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_15_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_15_io_eventAvailable),
    .io_countOverflow(bucketBanks_15_io_countOverflow),
    .io_cycleOverflow(bucketBanks_15_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_16 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_16_clock),
    .reset(bucketBanks_16_reset),
    .io_observe_0(bucketBanks_16_io_observe_0),
    .io_observe_1(bucketBanks_16_io_observe_1),
    .io_observe_2(bucketBanks_16_io_observe_2),
    .io_observe_3(bucketBanks_16_io_observe_3),
    .io_observe_4(bucketBanks_16_io_observe_4),
    .io_observe_5(bucketBanks_16_io_observe_5),
    .io_observe_6(bucketBanks_16_io_observe_6),
    .io_observe_7(bucketBanks_16_io_observe_7),
    .io_base(bucketBanks_16_io_base),
    .io_resetStats(bucketBanks_16_io_resetStats),
    .io_event_valid(bucketBanks_16_io_event_valid),
    .io_event_bits(bucketBanks_16_io_event_bits),
    .io_safeWatermark(bucketBanks_16_io_safeWatermark),
    .io_currentCycle(bucketBanks_16_io_currentCycle),
    .io_resolvedCount(bucketBanks_16_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_16_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_16_io_eventAvailable),
    .io_countOverflow(bucketBanks_16_io_countOverflow),
    .io_cycleOverflow(bucketBanks_16_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_17 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_17_clock),
    .reset(bucketBanks_17_reset),
    .io_observe_0(bucketBanks_17_io_observe_0),
    .io_observe_1(bucketBanks_17_io_observe_1),
    .io_observe_2(bucketBanks_17_io_observe_2),
    .io_observe_3(bucketBanks_17_io_observe_3),
    .io_observe_4(bucketBanks_17_io_observe_4),
    .io_observe_5(bucketBanks_17_io_observe_5),
    .io_observe_6(bucketBanks_17_io_observe_6),
    .io_observe_7(bucketBanks_17_io_observe_7),
    .io_base(bucketBanks_17_io_base),
    .io_resetStats(bucketBanks_17_io_resetStats),
    .io_event_valid(bucketBanks_17_io_event_valid),
    .io_event_bits(bucketBanks_17_io_event_bits),
    .io_safeWatermark(bucketBanks_17_io_safeWatermark),
    .io_currentCycle(bucketBanks_17_io_currentCycle),
    .io_resolvedCount(bucketBanks_17_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_17_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_17_io_eventAvailable),
    .io_countOverflow(bucketBanks_17_io_countOverflow),
    .io_cycleOverflow(bucketBanks_17_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_18 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_18_clock),
    .reset(bucketBanks_18_reset),
    .io_observe_0(bucketBanks_18_io_observe_0),
    .io_observe_1(bucketBanks_18_io_observe_1),
    .io_observe_2(bucketBanks_18_io_observe_2),
    .io_observe_3(bucketBanks_18_io_observe_3),
    .io_observe_4(bucketBanks_18_io_observe_4),
    .io_observe_5(bucketBanks_18_io_observe_5),
    .io_observe_6(bucketBanks_18_io_observe_6),
    .io_observe_7(bucketBanks_18_io_observe_7),
    .io_base(bucketBanks_18_io_base),
    .io_resetStats(bucketBanks_18_io_resetStats),
    .io_event_valid(bucketBanks_18_io_event_valid),
    .io_event_bits(bucketBanks_18_io_event_bits),
    .io_safeWatermark(bucketBanks_18_io_safeWatermark),
    .io_currentCycle(bucketBanks_18_io_currentCycle),
    .io_resolvedCount(bucketBanks_18_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_18_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_18_io_eventAvailable),
    .io_countOverflow(bucketBanks_18_io_countOverflow),
    .io_cycleOverflow(bucketBanks_18_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_19 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_19_clock),
    .reset(bucketBanks_19_reset),
    .io_observe_0(bucketBanks_19_io_observe_0),
    .io_observe_1(bucketBanks_19_io_observe_1),
    .io_observe_2(bucketBanks_19_io_observe_2),
    .io_observe_3(bucketBanks_19_io_observe_3),
    .io_observe_4(bucketBanks_19_io_observe_4),
    .io_observe_5(bucketBanks_19_io_observe_5),
    .io_observe_6(bucketBanks_19_io_observe_6),
    .io_observe_7(bucketBanks_19_io_observe_7),
    .io_base(bucketBanks_19_io_base),
    .io_resetStats(bucketBanks_19_io_resetStats),
    .io_event_valid(bucketBanks_19_io_event_valid),
    .io_event_bits(bucketBanks_19_io_event_bits),
    .io_safeWatermark(bucketBanks_19_io_safeWatermark),
    .io_currentCycle(bucketBanks_19_io_currentCycle),
    .io_resolvedCount(bucketBanks_19_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_19_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_19_io_eventAvailable),
    .io_countOverflow(bucketBanks_19_io_countOverflow),
    .io_cycleOverflow(bucketBanks_19_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_20 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_20_clock),
    .reset(bucketBanks_20_reset),
    .io_observe_0(bucketBanks_20_io_observe_0),
    .io_observe_1(bucketBanks_20_io_observe_1),
    .io_observe_2(bucketBanks_20_io_observe_2),
    .io_observe_3(bucketBanks_20_io_observe_3),
    .io_observe_4(bucketBanks_20_io_observe_4),
    .io_observe_5(bucketBanks_20_io_observe_5),
    .io_observe_6(bucketBanks_20_io_observe_6),
    .io_observe_7(bucketBanks_20_io_observe_7),
    .io_base(bucketBanks_20_io_base),
    .io_resetStats(bucketBanks_20_io_resetStats),
    .io_event_valid(bucketBanks_20_io_event_valid),
    .io_event_bits(bucketBanks_20_io_event_bits),
    .io_safeWatermark(bucketBanks_20_io_safeWatermark),
    .io_currentCycle(bucketBanks_20_io_currentCycle),
    .io_resolvedCount(bucketBanks_20_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_20_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_20_io_eventAvailable),
    .io_countOverflow(bucketBanks_20_io_countOverflow),
    .io_cycleOverflow(bucketBanks_20_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_21 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_21_clock),
    .reset(bucketBanks_21_reset),
    .io_observe_0(bucketBanks_21_io_observe_0),
    .io_observe_1(bucketBanks_21_io_observe_1),
    .io_observe_2(bucketBanks_21_io_observe_2),
    .io_observe_3(bucketBanks_21_io_observe_3),
    .io_observe_4(bucketBanks_21_io_observe_4),
    .io_observe_5(bucketBanks_21_io_observe_5),
    .io_observe_6(bucketBanks_21_io_observe_6),
    .io_observe_7(bucketBanks_21_io_observe_7),
    .io_base(bucketBanks_21_io_base),
    .io_resetStats(bucketBanks_21_io_resetStats),
    .io_event_valid(bucketBanks_21_io_event_valid),
    .io_event_bits(bucketBanks_21_io_event_bits),
    .io_safeWatermark(bucketBanks_21_io_safeWatermark),
    .io_currentCycle(bucketBanks_21_io_currentCycle),
    .io_resolvedCount(bucketBanks_21_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_21_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_21_io_eventAvailable),
    .io_countOverflow(bucketBanks_21_io_countOverflow),
    .io_cycleOverflow(bucketBanks_21_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_22 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_22_clock),
    .reset(bucketBanks_22_reset),
    .io_observe_0(bucketBanks_22_io_observe_0),
    .io_observe_1(bucketBanks_22_io_observe_1),
    .io_observe_2(bucketBanks_22_io_observe_2),
    .io_observe_3(bucketBanks_22_io_observe_3),
    .io_observe_4(bucketBanks_22_io_observe_4),
    .io_observe_5(bucketBanks_22_io_observe_5),
    .io_observe_6(bucketBanks_22_io_observe_6),
    .io_observe_7(bucketBanks_22_io_observe_7),
    .io_base(bucketBanks_22_io_base),
    .io_resetStats(bucketBanks_22_io_resetStats),
    .io_event_valid(bucketBanks_22_io_event_valid),
    .io_event_bits(bucketBanks_22_io_event_bits),
    .io_safeWatermark(bucketBanks_22_io_safeWatermark),
    .io_currentCycle(bucketBanks_22_io_currentCycle),
    .io_resolvedCount(bucketBanks_22_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_22_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_22_io_eventAvailable),
    .io_countOverflow(bucketBanks_22_io_countOverflow),
    .io_cycleOverflow(bucketBanks_22_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_23 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_23_clock),
    .reset(bucketBanks_23_reset),
    .io_observe_0(bucketBanks_23_io_observe_0),
    .io_observe_1(bucketBanks_23_io_observe_1),
    .io_observe_2(bucketBanks_23_io_observe_2),
    .io_observe_3(bucketBanks_23_io_observe_3),
    .io_observe_4(bucketBanks_23_io_observe_4),
    .io_observe_5(bucketBanks_23_io_observe_5),
    .io_observe_6(bucketBanks_23_io_observe_6),
    .io_observe_7(bucketBanks_23_io_observe_7),
    .io_base(bucketBanks_23_io_base),
    .io_resetStats(bucketBanks_23_io_resetStats),
    .io_event_valid(bucketBanks_23_io_event_valid),
    .io_event_bits(bucketBanks_23_io_event_bits),
    .io_safeWatermark(bucketBanks_23_io_safeWatermark),
    .io_currentCycle(bucketBanks_23_io_currentCycle),
    .io_resolvedCount(bucketBanks_23_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_23_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_23_io_eventAvailable),
    .io_countOverflow(bucketBanks_23_io_countOverflow),
    .io_cycleOverflow(bucketBanks_23_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_24 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_24_clock),
    .reset(bucketBanks_24_reset),
    .io_observe_0(bucketBanks_24_io_observe_0),
    .io_observe_1(bucketBanks_24_io_observe_1),
    .io_observe_2(bucketBanks_24_io_observe_2),
    .io_observe_3(bucketBanks_24_io_observe_3),
    .io_observe_4(bucketBanks_24_io_observe_4),
    .io_observe_5(bucketBanks_24_io_observe_5),
    .io_observe_6(bucketBanks_24_io_observe_6),
    .io_observe_7(bucketBanks_24_io_observe_7),
    .io_base(bucketBanks_24_io_base),
    .io_resetStats(bucketBanks_24_io_resetStats),
    .io_event_valid(bucketBanks_24_io_event_valid),
    .io_event_bits(bucketBanks_24_io_event_bits),
    .io_safeWatermark(bucketBanks_24_io_safeWatermark),
    .io_currentCycle(bucketBanks_24_io_currentCycle),
    .io_resolvedCount(bucketBanks_24_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_24_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_24_io_eventAvailable),
    .io_countOverflow(bucketBanks_24_io_countOverflow),
    .io_cycleOverflow(bucketBanks_24_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_25 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_25_clock),
    .reset(bucketBanks_25_reset),
    .io_observe_0(bucketBanks_25_io_observe_0),
    .io_observe_1(bucketBanks_25_io_observe_1),
    .io_observe_2(bucketBanks_25_io_observe_2),
    .io_observe_3(bucketBanks_25_io_observe_3),
    .io_observe_4(bucketBanks_25_io_observe_4),
    .io_observe_5(bucketBanks_25_io_observe_5),
    .io_observe_6(bucketBanks_25_io_observe_6),
    .io_observe_7(bucketBanks_25_io_observe_7),
    .io_base(bucketBanks_25_io_base),
    .io_resetStats(bucketBanks_25_io_resetStats),
    .io_event_valid(bucketBanks_25_io_event_valid),
    .io_event_bits(bucketBanks_25_io_event_bits),
    .io_safeWatermark(bucketBanks_25_io_safeWatermark),
    .io_currentCycle(bucketBanks_25_io_currentCycle),
    .io_resolvedCount(bucketBanks_25_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_25_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_25_io_eventAvailable),
    .io_countOverflow(bucketBanks_25_io_countOverflow),
    .io_cycleOverflow(bucketBanks_25_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_26 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_26_clock),
    .reset(bucketBanks_26_reset),
    .io_observe_0(bucketBanks_26_io_observe_0),
    .io_observe_1(bucketBanks_26_io_observe_1),
    .io_observe_2(bucketBanks_26_io_observe_2),
    .io_observe_3(bucketBanks_26_io_observe_3),
    .io_observe_4(bucketBanks_26_io_observe_4),
    .io_observe_5(bucketBanks_26_io_observe_5),
    .io_observe_6(bucketBanks_26_io_observe_6),
    .io_observe_7(bucketBanks_26_io_observe_7),
    .io_base(bucketBanks_26_io_base),
    .io_resetStats(bucketBanks_26_io_resetStats),
    .io_event_valid(bucketBanks_26_io_event_valid),
    .io_event_bits(bucketBanks_26_io_event_bits),
    .io_safeWatermark(bucketBanks_26_io_safeWatermark),
    .io_currentCycle(bucketBanks_26_io_currentCycle),
    .io_resolvedCount(bucketBanks_26_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_26_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_26_io_eventAvailable),
    .io_countOverflow(bucketBanks_26_io_countOverflow),
    .io_cycleOverflow(bucketBanks_26_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_27 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_27_clock),
    .reset(bucketBanks_27_reset),
    .io_observe_0(bucketBanks_27_io_observe_0),
    .io_observe_1(bucketBanks_27_io_observe_1),
    .io_observe_2(bucketBanks_27_io_observe_2),
    .io_observe_3(bucketBanks_27_io_observe_3),
    .io_observe_4(bucketBanks_27_io_observe_4),
    .io_observe_5(bucketBanks_27_io_observe_5),
    .io_observe_6(bucketBanks_27_io_observe_6),
    .io_observe_7(bucketBanks_27_io_observe_7),
    .io_base(bucketBanks_27_io_base),
    .io_resetStats(bucketBanks_27_io_resetStats),
    .io_event_valid(bucketBanks_27_io_event_valid),
    .io_event_bits(bucketBanks_27_io_event_bits),
    .io_safeWatermark(bucketBanks_27_io_safeWatermark),
    .io_currentCycle(bucketBanks_27_io_currentCycle),
    .io_resolvedCount(bucketBanks_27_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_27_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_27_io_eventAvailable),
    .io_countOverflow(bucketBanks_27_io_countOverflow),
    .io_cycleOverflow(bucketBanks_27_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_28 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_28_clock),
    .reset(bucketBanks_28_reset),
    .io_observe_0(bucketBanks_28_io_observe_0),
    .io_observe_1(bucketBanks_28_io_observe_1),
    .io_observe_2(bucketBanks_28_io_observe_2),
    .io_observe_3(bucketBanks_28_io_observe_3),
    .io_observe_4(bucketBanks_28_io_observe_4),
    .io_observe_5(bucketBanks_28_io_observe_5),
    .io_observe_6(bucketBanks_28_io_observe_6),
    .io_observe_7(bucketBanks_28_io_observe_7),
    .io_base(bucketBanks_28_io_base),
    .io_resetStats(bucketBanks_28_io_resetStats),
    .io_event_valid(bucketBanks_28_io_event_valid),
    .io_event_bits(bucketBanks_28_io_event_bits),
    .io_safeWatermark(bucketBanks_28_io_safeWatermark),
    .io_currentCycle(bucketBanks_28_io_currentCycle),
    .io_resolvedCount(bucketBanks_28_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_28_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_28_io_eventAvailable),
    .io_countOverflow(bucketBanks_28_io_countOverflow),
    .io_cycleOverflow(bucketBanks_28_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_29 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_29_clock),
    .reset(bucketBanks_29_reset),
    .io_observe_0(bucketBanks_29_io_observe_0),
    .io_observe_1(bucketBanks_29_io_observe_1),
    .io_observe_2(bucketBanks_29_io_observe_2),
    .io_observe_3(bucketBanks_29_io_observe_3),
    .io_observe_4(bucketBanks_29_io_observe_4),
    .io_observe_5(bucketBanks_29_io_observe_5),
    .io_observe_6(bucketBanks_29_io_observe_6),
    .io_observe_7(bucketBanks_29_io_observe_7),
    .io_base(bucketBanks_29_io_base),
    .io_resetStats(bucketBanks_29_io_resetStats),
    .io_event_valid(bucketBanks_29_io_event_valid),
    .io_event_bits(bucketBanks_29_io_event_bits),
    .io_safeWatermark(bucketBanks_29_io_safeWatermark),
    .io_currentCycle(bucketBanks_29_io_currentCycle),
    .io_resolvedCount(bucketBanks_29_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_29_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_29_io_eventAvailable),
    .io_countOverflow(bucketBanks_29_io_countOverflow),
    .io_cycleOverflow(bucketBanks_29_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_30 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_30_clock),
    .reset(bucketBanks_30_reset),
    .io_observe_0(bucketBanks_30_io_observe_0),
    .io_observe_1(bucketBanks_30_io_observe_1),
    .io_observe_2(bucketBanks_30_io_observe_2),
    .io_observe_3(bucketBanks_30_io_observe_3),
    .io_observe_4(bucketBanks_30_io_observe_4),
    .io_observe_5(bucketBanks_30_io_observe_5),
    .io_observe_6(bucketBanks_30_io_observe_6),
    .io_observe_7(bucketBanks_30_io_observe_7),
    .io_base(bucketBanks_30_io_base),
    .io_resetStats(bucketBanks_30_io_resetStats),
    .io_event_valid(bucketBanks_30_io_event_valid),
    .io_event_bits(bucketBanks_30_io_event_bits),
    .io_safeWatermark(bucketBanks_30_io_safeWatermark),
    .io_currentCycle(bucketBanks_30_io_currentCycle),
    .io_resolvedCount(bucketBanks_30_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_30_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_30_io_eventAvailable),
    .io_countOverflow(bucketBanks_30_io_countOverflow),
    .io_cycleOverflow(bucketBanks_30_io_cycleOverflow)
  );
  GHBarrierBucketBank bucketBanks_31 ( // @[CandidateProof.scala 53:22]
    .clock(bucketBanks_31_clock),
    .reset(bucketBanks_31_reset),
    .io_observe_0(bucketBanks_31_io_observe_0),
    .io_observe_1(bucketBanks_31_io_observe_1),
    .io_observe_2(bucketBanks_31_io_observe_2),
    .io_observe_3(bucketBanks_31_io_observe_3),
    .io_observe_4(bucketBanks_31_io_observe_4),
    .io_observe_5(bucketBanks_31_io_observe_5),
    .io_observe_6(bucketBanks_31_io_observe_6),
    .io_observe_7(bucketBanks_31_io_observe_7),
    .io_base(bucketBanks_31_io_base),
    .io_resetStats(bucketBanks_31_io_resetStats),
    .io_event_valid(bucketBanks_31_io_event_valid),
    .io_event_bits(bucketBanks_31_io_event_bits),
    .io_safeWatermark(bucketBanks_31_io_safeWatermark),
    .io_currentCycle(bucketBanks_31_io_currentCycle),
    .io_resolvedCount(bucketBanks_31_io_resolvedCount),
    .io_resolvedRequest(bucketBanks_31_io_resolvedRequest),
    .io_eventAvailable(bucketBanks_31_io_eventAvailable),
    .io_countOverflow(bucketBanks_31_io_countOverflow),
    .io_cycleOverflow(bucketBanks_31_io_cycleOverflow)
  );
  assign io_seen = seen; // @[CandidateProof.scala 152:11]
  assign io_debugView_0 = bucketBanks_0_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_1 = bucketBanks_0_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_2 = bucketBanks_0_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_3 = bucketBanks_0_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_4 = bucketBanks_0_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_5 = bucketBanks_0_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_6 = bucketBanks_0_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_7 = bucketBanks_0_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_8 = bucketBanks_1_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_9 = bucketBanks_1_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_10 = bucketBanks_1_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_11 = bucketBanks_1_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_12 = bucketBanks_1_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_13 = bucketBanks_1_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_14 = bucketBanks_1_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_15 = bucketBanks_1_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_16 = bucketBanks_2_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_17 = bucketBanks_2_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_18 = bucketBanks_2_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_19 = bucketBanks_2_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_20 = bucketBanks_2_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_21 = bucketBanks_2_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_22 = bucketBanks_2_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_23 = bucketBanks_2_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_24 = bucketBanks_3_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_25 = bucketBanks_3_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_26 = bucketBanks_3_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_27 = bucketBanks_3_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_28 = bucketBanks_3_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_29 = bucketBanks_3_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_30 = bucketBanks_3_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_31 = bucketBanks_3_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_32 = bucketBanks_4_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_33 = bucketBanks_4_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_34 = bucketBanks_4_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_35 = bucketBanks_4_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_36 = bucketBanks_4_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_37 = bucketBanks_4_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_38 = bucketBanks_4_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_39 = bucketBanks_4_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_40 = bucketBanks_5_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_41 = bucketBanks_5_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_42 = bucketBanks_5_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_43 = bucketBanks_5_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_44 = bucketBanks_5_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_45 = bucketBanks_5_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_46 = bucketBanks_5_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_47 = bucketBanks_5_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_48 = bucketBanks_6_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_49 = bucketBanks_6_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_50 = bucketBanks_6_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_51 = bucketBanks_6_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_52 = bucketBanks_6_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_53 = bucketBanks_6_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_54 = bucketBanks_6_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_55 = bucketBanks_6_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_56 = bucketBanks_7_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_57 = bucketBanks_7_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_58 = bucketBanks_7_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_59 = bucketBanks_7_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_60 = bucketBanks_7_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_61 = bucketBanks_7_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_62 = bucketBanks_7_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_63 = bucketBanks_7_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_64 = bucketBanks_8_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_65 = bucketBanks_8_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_66 = bucketBanks_8_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_67 = bucketBanks_8_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_68 = bucketBanks_8_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_69 = bucketBanks_8_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_70 = bucketBanks_8_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_71 = bucketBanks_8_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_72 = bucketBanks_9_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_73 = bucketBanks_9_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_74 = bucketBanks_9_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_75 = bucketBanks_9_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_76 = bucketBanks_9_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_77 = bucketBanks_9_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_78 = bucketBanks_9_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_79 = bucketBanks_9_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_80 = bucketBanks_10_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_81 = bucketBanks_10_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_82 = bucketBanks_10_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_83 = bucketBanks_10_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_84 = bucketBanks_10_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_85 = bucketBanks_10_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_86 = bucketBanks_10_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_87 = bucketBanks_10_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_88 = bucketBanks_11_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_89 = bucketBanks_11_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_90 = bucketBanks_11_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_91 = bucketBanks_11_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_92 = bucketBanks_11_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_93 = bucketBanks_11_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_94 = bucketBanks_11_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_95 = bucketBanks_11_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_96 = bucketBanks_12_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_97 = bucketBanks_12_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_98 = bucketBanks_12_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_99 = bucketBanks_12_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_100 = bucketBanks_12_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_101 = bucketBanks_12_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_102 = bucketBanks_12_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_103 = bucketBanks_12_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_104 = bucketBanks_13_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_105 = bucketBanks_13_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_106 = bucketBanks_13_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_107 = bucketBanks_13_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_108 = bucketBanks_13_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_109 = bucketBanks_13_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_110 = bucketBanks_13_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_111 = bucketBanks_13_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_112 = bucketBanks_14_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_113 = bucketBanks_14_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_114 = bucketBanks_14_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_115 = bucketBanks_14_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_116 = bucketBanks_14_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_117 = bucketBanks_14_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_118 = bucketBanks_14_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_119 = bucketBanks_14_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_120 = bucketBanks_15_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_121 = bucketBanks_15_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_122 = bucketBanks_15_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_123 = bucketBanks_15_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_124 = bucketBanks_15_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_125 = bucketBanks_15_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_126 = bucketBanks_15_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_127 = bucketBanks_15_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_128 = bucketBanks_16_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_129 = bucketBanks_16_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_130 = bucketBanks_16_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_131 = bucketBanks_16_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_132 = bucketBanks_16_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_133 = bucketBanks_16_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_134 = bucketBanks_16_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_135 = bucketBanks_16_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_136 = bucketBanks_17_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_137 = bucketBanks_17_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_138 = bucketBanks_17_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_139 = bucketBanks_17_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_140 = bucketBanks_17_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_141 = bucketBanks_17_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_142 = bucketBanks_17_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_143 = bucketBanks_17_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_144 = bucketBanks_18_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_145 = bucketBanks_18_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_146 = bucketBanks_18_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_147 = bucketBanks_18_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_148 = bucketBanks_18_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_149 = bucketBanks_18_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_150 = bucketBanks_18_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_151 = bucketBanks_18_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_152 = bucketBanks_19_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_153 = bucketBanks_19_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_154 = bucketBanks_19_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_155 = bucketBanks_19_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_156 = bucketBanks_19_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_157 = bucketBanks_19_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_158 = bucketBanks_19_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_159 = bucketBanks_19_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_160 = bucketBanks_20_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_161 = bucketBanks_20_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_162 = bucketBanks_20_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_163 = bucketBanks_20_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_164 = bucketBanks_20_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_165 = bucketBanks_20_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_166 = bucketBanks_20_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_167 = bucketBanks_20_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_168 = bucketBanks_21_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_169 = bucketBanks_21_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_170 = bucketBanks_21_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_171 = bucketBanks_21_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_172 = bucketBanks_21_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_173 = bucketBanks_21_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_174 = bucketBanks_21_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_175 = bucketBanks_21_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_176 = bucketBanks_22_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_177 = bucketBanks_22_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_178 = bucketBanks_22_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_179 = bucketBanks_22_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_180 = bucketBanks_22_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_181 = bucketBanks_22_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_182 = bucketBanks_22_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_183 = bucketBanks_22_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_184 = bucketBanks_23_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_185 = bucketBanks_23_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_186 = bucketBanks_23_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_187 = bucketBanks_23_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_188 = bucketBanks_23_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_189 = bucketBanks_23_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_190 = bucketBanks_23_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_191 = bucketBanks_23_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_192 = bucketBanks_24_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_193 = bucketBanks_24_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_194 = bucketBanks_24_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_195 = bucketBanks_24_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_196 = bucketBanks_24_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_197 = bucketBanks_24_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_198 = bucketBanks_24_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_199 = bucketBanks_24_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_200 = bucketBanks_25_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_201 = bucketBanks_25_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_202 = bucketBanks_25_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_203 = bucketBanks_25_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_204 = bucketBanks_25_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_205 = bucketBanks_25_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_206 = bucketBanks_25_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_207 = bucketBanks_25_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_208 = bucketBanks_26_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_209 = bucketBanks_26_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_210 = bucketBanks_26_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_211 = bucketBanks_26_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_212 = bucketBanks_26_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_213 = bucketBanks_26_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_214 = bucketBanks_26_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_215 = bucketBanks_26_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_216 = bucketBanks_27_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_217 = bucketBanks_27_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_218 = bucketBanks_27_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_219 = bucketBanks_27_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_220 = bucketBanks_27_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_221 = bucketBanks_27_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_222 = bucketBanks_27_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_223 = bucketBanks_27_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_224 = bucketBanks_28_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_225 = bucketBanks_28_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_226 = bucketBanks_28_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_227 = bucketBanks_28_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_228 = bucketBanks_28_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_229 = bucketBanks_28_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_230 = bucketBanks_28_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_231 = bucketBanks_28_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_232 = bucketBanks_29_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_233 = bucketBanks_29_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_234 = bucketBanks_29_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_235 = bucketBanks_29_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_236 = bucketBanks_29_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_237 = bucketBanks_29_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_238 = bucketBanks_29_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_239 = bucketBanks_29_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_240 = bucketBanks_30_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_241 = bucketBanks_30_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_242 = bucketBanks_30_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_243 = bucketBanks_30_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_244 = bucketBanks_30_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_245 = bucketBanks_30_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_246 = bucketBanks_30_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_247 = bucketBanks_30_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_debugView_248 = bucketBanks_31_io_observe_0; // @[CandidateProof.scala 159:45]
  assign io_debugView_249 = bucketBanks_31_io_observe_1; // @[CandidateProof.scala 159:45]
  assign io_debugView_250 = bucketBanks_31_io_observe_2; // @[CandidateProof.scala 159:45]
  assign io_debugView_251 = bucketBanks_31_io_observe_3; // @[CandidateProof.scala 159:45]
  assign io_debugView_252 = bucketBanks_31_io_observe_4; // @[CandidateProof.scala 159:45]
  assign io_debugView_253 = bucketBanks_31_io_observe_5; // @[CandidateProof.scala 159:45]
  assign io_debugView_254 = bucketBanks_31_io_observe_6; // @[CandidateProof.scala 159:45]
  assign io_debugView_255 = bucketBanks_31_io_observe_7; // @[CandidateProof.scala 159:45]
  assign io_resolved = resolved; // @[CandidateProof.scala 153:15]
  assign io_pending = pending; // @[CandidateProof.scala 154:14]
  assign io_dropped = dropped; // @[CandidateProof.scala 155:14]
  assign io_requestCycleSum = requestCycleSum; // @[CandidateProof.scala 156:22]
  assign io_safeCycleSum = safeCycleSum; // @[CandidateProof.scala 157:19]
  assign io_statsValid = {63'h0,statsValid}; // @[Cat.scala 33:92]
  assign bucketBanks_0_clock = clock;
  assign bucketBanks_0_reset = reset;
  assign bucketBanks_0_io_base = 8'h0; // @[CandidateProof.scala 54:18]
  assign bucketBanks_0_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_0_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_0_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_0_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_0_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_1_clock = clock;
  assign bucketBanks_1_reset = reset;
  assign bucketBanks_1_io_base = 8'h8; // @[CandidateProof.scala 54:18]
  assign bucketBanks_1_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_1_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_1_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_1_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_1_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_2_clock = clock;
  assign bucketBanks_2_reset = reset;
  assign bucketBanks_2_io_base = 8'h10; // @[CandidateProof.scala 54:18]
  assign bucketBanks_2_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_2_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_2_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_2_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_2_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_3_clock = clock;
  assign bucketBanks_3_reset = reset;
  assign bucketBanks_3_io_base = 8'h18; // @[CandidateProof.scala 54:18]
  assign bucketBanks_3_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_3_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_3_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_3_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_3_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_4_clock = clock;
  assign bucketBanks_4_reset = reset;
  assign bucketBanks_4_io_base = 8'h20; // @[CandidateProof.scala 54:18]
  assign bucketBanks_4_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_4_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_4_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_4_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_4_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_5_clock = clock;
  assign bucketBanks_5_reset = reset;
  assign bucketBanks_5_io_base = 8'h28; // @[CandidateProof.scala 54:18]
  assign bucketBanks_5_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_5_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_5_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_5_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_5_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_6_clock = clock;
  assign bucketBanks_6_reset = reset;
  assign bucketBanks_6_io_base = 8'h30; // @[CandidateProof.scala 54:18]
  assign bucketBanks_6_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_6_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_6_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_6_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_6_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_7_clock = clock;
  assign bucketBanks_7_reset = reset;
  assign bucketBanks_7_io_base = 8'h38; // @[CandidateProof.scala 54:18]
  assign bucketBanks_7_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_7_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_7_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_7_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_7_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_8_clock = clock;
  assign bucketBanks_8_reset = reset;
  assign bucketBanks_8_io_base = 8'h40; // @[CandidateProof.scala 54:18]
  assign bucketBanks_8_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_8_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_8_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_8_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_8_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_9_clock = clock;
  assign bucketBanks_9_reset = reset;
  assign bucketBanks_9_io_base = 8'h48; // @[CandidateProof.scala 54:18]
  assign bucketBanks_9_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_9_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_9_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_9_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_9_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_10_clock = clock;
  assign bucketBanks_10_reset = reset;
  assign bucketBanks_10_io_base = 8'h50; // @[CandidateProof.scala 54:18]
  assign bucketBanks_10_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_10_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_10_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_10_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_10_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_11_clock = clock;
  assign bucketBanks_11_reset = reset;
  assign bucketBanks_11_io_base = 8'h58; // @[CandidateProof.scala 54:18]
  assign bucketBanks_11_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_11_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_11_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_11_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_11_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_12_clock = clock;
  assign bucketBanks_12_reset = reset;
  assign bucketBanks_12_io_base = 8'h60; // @[CandidateProof.scala 54:18]
  assign bucketBanks_12_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_12_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_12_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_12_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_12_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_13_clock = clock;
  assign bucketBanks_13_reset = reset;
  assign bucketBanks_13_io_base = 8'h68; // @[CandidateProof.scala 54:18]
  assign bucketBanks_13_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_13_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_13_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_13_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_13_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_14_clock = clock;
  assign bucketBanks_14_reset = reset;
  assign bucketBanks_14_io_base = 8'h70; // @[CandidateProof.scala 54:18]
  assign bucketBanks_14_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_14_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_14_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_14_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_14_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_15_clock = clock;
  assign bucketBanks_15_reset = reset;
  assign bucketBanks_15_io_base = 8'h78; // @[CandidateProof.scala 54:18]
  assign bucketBanks_15_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_15_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_15_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_15_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_15_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_16_clock = clock;
  assign bucketBanks_16_reset = reset;
  assign bucketBanks_16_io_base = 8'h80; // @[CandidateProof.scala 54:18]
  assign bucketBanks_16_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_16_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_16_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_16_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_16_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_17_clock = clock;
  assign bucketBanks_17_reset = reset;
  assign bucketBanks_17_io_base = 8'h88; // @[CandidateProof.scala 54:18]
  assign bucketBanks_17_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_17_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_17_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_17_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_17_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_18_clock = clock;
  assign bucketBanks_18_reset = reset;
  assign bucketBanks_18_io_base = 8'h90; // @[CandidateProof.scala 54:18]
  assign bucketBanks_18_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_18_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_18_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_18_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_18_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_19_clock = clock;
  assign bucketBanks_19_reset = reset;
  assign bucketBanks_19_io_base = 8'h98; // @[CandidateProof.scala 54:18]
  assign bucketBanks_19_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_19_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_19_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_19_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_19_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_20_clock = clock;
  assign bucketBanks_20_reset = reset;
  assign bucketBanks_20_io_base = 8'ha0; // @[CandidateProof.scala 54:18]
  assign bucketBanks_20_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_20_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_20_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_20_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_20_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_21_clock = clock;
  assign bucketBanks_21_reset = reset;
  assign bucketBanks_21_io_base = 8'ha8; // @[CandidateProof.scala 54:18]
  assign bucketBanks_21_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_21_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_21_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_21_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_21_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_22_clock = clock;
  assign bucketBanks_22_reset = reset;
  assign bucketBanks_22_io_base = 8'hb0; // @[CandidateProof.scala 54:18]
  assign bucketBanks_22_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_22_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_22_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_22_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_22_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_23_clock = clock;
  assign bucketBanks_23_reset = reset;
  assign bucketBanks_23_io_base = 8'hb8; // @[CandidateProof.scala 54:18]
  assign bucketBanks_23_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_23_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_23_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_23_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_23_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_24_clock = clock;
  assign bucketBanks_24_reset = reset;
  assign bucketBanks_24_io_base = 8'hc0; // @[CandidateProof.scala 54:18]
  assign bucketBanks_24_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_24_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_24_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_24_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_24_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_25_clock = clock;
  assign bucketBanks_25_reset = reset;
  assign bucketBanks_25_io_base = 8'hc8; // @[CandidateProof.scala 54:18]
  assign bucketBanks_25_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_25_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_25_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_25_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_25_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_26_clock = clock;
  assign bucketBanks_26_reset = reset;
  assign bucketBanks_26_io_base = 8'hd0; // @[CandidateProof.scala 54:18]
  assign bucketBanks_26_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_26_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_26_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_26_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_26_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_27_clock = clock;
  assign bucketBanks_27_reset = reset;
  assign bucketBanks_27_io_base = 8'hd8; // @[CandidateProof.scala 54:18]
  assign bucketBanks_27_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_27_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_27_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_27_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_27_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_28_clock = clock;
  assign bucketBanks_28_reset = reset;
  assign bucketBanks_28_io_base = 8'he0; // @[CandidateProof.scala 54:18]
  assign bucketBanks_28_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_28_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_28_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_28_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_28_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_29_clock = clock;
  assign bucketBanks_29_reset = reset;
  assign bucketBanks_29_io_base = 8'he8; // @[CandidateProof.scala 54:18]
  assign bucketBanks_29_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_29_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_29_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_29_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_29_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_30_clock = clock;
  assign bucketBanks_30_reset = reset;
  assign bucketBanks_30_io_base = 8'hf0; // @[CandidateProof.scala 54:18]
  assign bucketBanks_30_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_30_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_30_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_30_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_30_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  assign bucketBanks_31_clock = clock;
  assign bucketBanks_31_reset = reset;
  assign bucketBanks_31_io_base = 8'hf8; // @[CandidateProof.scala 54:18]
  assign bucketBanks_31_io_resetStats = io_resetStats; // @[CandidateProof.scala 55:24]
  assign bucketBanks_31_io_event_valid = io_event_valid; // @[CandidateProof.scala 56:19]
  assign bucketBanks_31_io_event_bits = io_event_bits; // @[CandidateProof.scala 56:19]
  assign bucketBanks_31_io_safeWatermark = io_safeWatermark; // @[CandidateProof.scala 57:27]
  assign bucketBanks_31_io_currentCycle = io_currentCycle; // @[CandidateProof.scala 58:26]
  always @(posedge clock) begin
    if (reset) begin // @[CandidateProof.scala 62:21]
      seen <= 64'h0; // @[CandidateProof.scala 62:21]
    end else if (io_resetStats) begin // @[CandidateProof.scala 128:24]
      seen <= 64'h0; // @[CandidateProof.scala 129:10]
    end else if (io_event_valid) begin // @[CandidateProof.scala 137:27]
      seen <= _seen_T_1; // @[CandidateProof.scala 137:34]
    end
    if (reset) begin // @[CandidateProof.scala 63:25]
      resolved <= 64'h0; // @[CandidateProof.scala 63:25]
    end else if (io_resetStats) begin // @[CandidateProof.scala 128:24]
      resolved <= 64'h0; // @[CandidateProof.scala 130:14]
    end else if (_counterOverflow_T_7) begin // @[CandidateProof.scala 139:38]
      resolved <= _resolved_T_2; // @[CandidateProof.scala 140:16]
    end
    if (reset) begin // @[CandidateProof.scala 64:24]
      pending <= 64'h0; // @[CandidateProof.scala 64:24]
    end else if (io_resetStats) begin // @[CandidateProof.scala 128:24]
      pending <= 64'h0; // @[CandidateProof.scala 131:13]
    end else if (eventAccepted | |resolvedBucketsWide) begin // @[CandidateProof.scala 144:53]
      if (pendingUnderflow) begin // @[CandidateProof.scala 145:21]
        pending <= 64'h0;
      end else begin
        pending <= pendingNextWide[63:0];
      end
    end
    if (reset) begin // @[CandidateProof.scala 65:24]
      dropped <= 64'h0; // @[CandidateProof.scala 65:24]
    end else if (io_resetStats) begin // @[CandidateProof.scala 128:24]
      dropped <= 64'h0; // @[CandidateProof.scala 132:13]
    end else if (eventDropped) begin // @[CandidateProof.scala 138:25]
      dropped <= _dropped_T_1; // @[CandidateProof.scala 138:35]
    end
    if (reset) begin // @[CandidateProof.scala 66:32]
      requestCycleSum <= 64'h0; // @[CandidateProof.scala 66:32]
    end else if (io_resetStats) begin // @[CandidateProof.scala 128:24]
      requestCycleSum <= 64'h0; // @[CandidateProof.scala 133:21]
    end else if (_counterOverflow_T_7) begin // @[CandidateProof.scala 139:38]
      requestCycleSum <= _requestCycleSum_T_2; // @[CandidateProof.scala 141:23]
    end
    if (reset) begin // @[CandidateProof.scala 67:29]
      safeCycleSum <= 64'h0; // @[CandidateProof.scala 67:29]
    end else if (io_resetStats) begin // @[CandidateProof.scala 128:24]
      safeCycleSum <= 64'h0; // @[CandidateProof.scala 134:18]
    end else if (_counterOverflow_T_7) begin // @[CandidateProof.scala 139:38]
      safeCycleSum <= _safeCycleSum_T_2; // @[CandidateProof.scala 142:20]
    end
    statsValid <= reset | _GEN_13; // @[CandidateProof.scala 68:{27,27}]
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
  _RAND_0 = {2{`RANDOM}};
  seen = _RAND_0[63:0];
  _RAND_1 = {2{`RANDOM}};
  resolved = _RAND_1[63:0];
  _RAND_2 = {2{`RANDOM}};
  pending = _RAND_2[63:0];
  _RAND_3 = {2{`RANDOM}};
  dropped = _RAND_3[63:0];
  _RAND_4 = {2{`RANDOM}};
  requestCycleSum = _RAND_4[63:0];
  _RAND_5 = {2{`RANDOM}};
  safeCycleSum = _RAND_5[63:0];
  _RAND_6 = {1{`RANDOM}};
  statsValid = _RAND_6[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
