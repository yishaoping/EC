module ReservationCandidate(
  input         clock,
  input         reset,
  input         io_write,
  input  [8:0]  io_index,
  input  [79:0] io_data,
  input  [8:0]  io_readIndex_0,
  input  [8:0]  io_readIndex_1,
  input  [8:0]  io_readIndex_2,
  input  [8:0]  io_readIndex_3,
  input  [8:0]  io_readIndex_4,
  output [79:0] io_result_0,
  output [79:0] io_result_1,
  output [79:0] io_result_2,
  output [79:0] io_result_3,
  output [79:0] io_result_4
);
`ifdef RANDOMIZE_MEM_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
`endif // RANDOMIZE_MEM_INIT
  reg [15:0] payload [0:511]; // @[Emit.scala 41:54]
  wire  payload_r_epoch_MPORT_en; // @[Emit.scala 41:54]
  wire [8:0] payload_r_epoch_MPORT_addr; // @[Emit.scala 41:54]
  wire [15:0] payload_r_epoch_MPORT_data; // @[Emit.scala 41:54]
  wire  payload_r_epoch_MPORT_1_en; // @[Emit.scala 41:54]
  wire [8:0] payload_r_epoch_MPORT_1_addr; // @[Emit.scala 41:54]
  wire [15:0] payload_r_epoch_MPORT_1_data; // @[Emit.scala 41:54]
  wire  payload_r_epoch_MPORT_2_en; // @[Emit.scala 41:54]
  wire [8:0] payload_r_epoch_MPORT_2_addr; // @[Emit.scala 41:54]
  wire [15:0] payload_r_epoch_MPORT_2_data; // @[Emit.scala 41:54]
  wire  payload_r_epoch_MPORT_3_en; // @[Emit.scala 41:54]
  wire [8:0] payload_r_epoch_MPORT_3_addr; // @[Emit.scala 41:54]
  wire [15:0] payload_r_epoch_MPORT_3_data; // @[Emit.scala 41:54]
  wire  payload_r_epoch_MPORT_4_en; // @[Emit.scala 41:54]
  wire [8:0] payload_r_epoch_MPORT_4_addr; // @[Emit.scala 41:54]
  wire [15:0] payload_r_epoch_MPORT_4_data; // @[Emit.scala 41:54]
  wire [15:0] payload_MPORT_data; // @[Emit.scala 41:54]
  wire [8:0] payload_MPORT_addr; // @[Emit.scala 41:54]
  wire  payload_MPORT_mask; // @[Emit.scala 41:54]
  wire  payload_MPORT_en; // @[Emit.scala 41:54]
  reg [31:0] payload_1 [0:511]; // @[Emit.scala 41:54]
  wire  payload_1_r_transaction_MPORT_en; // @[Emit.scala 41:54]
  wire [8:0] payload_1_r_transaction_MPORT_addr; // @[Emit.scala 41:54]
  wire [31:0] payload_1_r_transaction_MPORT_data; // @[Emit.scala 41:54]
  wire  payload_1_r_transaction_MPORT_1_en; // @[Emit.scala 41:54]
  wire [8:0] payload_1_r_transaction_MPORT_1_addr; // @[Emit.scala 41:54]
  wire [31:0] payload_1_r_transaction_MPORT_1_data; // @[Emit.scala 41:54]
  wire  payload_1_r_transaction_MPORT_2_en; // @[Emit.scala 41:54]
  wire [8:0] payload_1_r_transaction_MPORT_2_addr; // @[Emit.scala 41:54]
  wire [31:0] payload_1_r_transaction_MPORT_2_data; // @[Emit.scala 41:54]
  wire  payload_1_r_transaction_MPORT_3_en; // @[Emit.scala 41:54]
  wire [8:0] payload_1_r_transaction_MPORT_3_addr; // @[Emit.scala 41:54]
  wire [31:0] payload_1_r_transaction_MPORT_3_data; // @[Emit.scala 41:54]
  wire  payload_1_r_transaction_MPORT_4_en; // @[Emit.scala 41:54]
  wire [8:0] payload_1_r_transaction_MPORT_4_addr; // @[Emit.scala 41:54]
  wire [31:0] payload_1_r_transaction_MPORT_4_data; // @[Emit.scala 41:54]
  wire [31:0] payload_1_MPORT_1_data; // @[Emit.scala 41:54]
  wire [8:0] payload_1_MPORT_1_addr; // @[Emit.scala 41:54]
  wire  payload_1_MPORT_1_mask; // @[Emit.scala 41:54]
  wire  payload_1_MPORT_1_en; // @[Emit.scala 41:54]
  reg [7:0] payload_2 [0:511]; // @[Emit.scala 41:54]
  wire  payload_2_r_mshr_MPORT_en; // @[Emit.scala 41:54]
  wire [8:0] payload_2_r_mshr_MPORT_addr; // @[Emit.scala 41:54]
  wire [7:0] payload_2_r_mshr_MPORT_data; // @[Emit.scala 41:54]
  wire  payload_2_r_mshr_MPORT_1_en; // @[Emit.scala 41:54]
  wire [8:0] payload_2_r_mshr_MPORT_1_addr; // @[Emit.scala 41:54]
  wire [7:0] payload_2_r_mshr_MPORT_1_data; // @[Emit.scala 41:54]
  wire  payload_2_r_mshr_MPORT_2_en; // @[Emit.scala 41:54]
  wire [8:0] payload_2_r_mshr_MPORT_2_addr; // @[Emit.scala 41:54]
  wire [7:0] payload_2_r_mshr_MPORT_2_data; // @[Emit.scala 41:54]
  wire  payload_2_r_mshr_MPORT_3_en; // @[Emit.scala 41:54]
  wire [8:0] payload_2_r_mshr_MPORT_3_addr; // @[Emit.scala 41:54]
  wire [7:0] payload_2_r_mshr_MPORT_3_data; // @[Emit.scala 41:54]
  wire  payload_2_r_mshr_MPORT_4_en; // @[Emit.scala 41:54]
  wire [8:0] payload_2_r_mshr_MPORT_4_addr; // @[Emit.scala 41:54]
  wire [7:0] payload_2_r_mshr_MPORT_4_data; // @[Emit.scala 41:54]
  wire [7:0] payload_2_MPORT_2_data; // @[Emit.scala 41:54]
  wire [8:0] payload_2_MPORT_2_addr; // @[Emit.scala 41:54]
  wire  payload_2_MPORT_2_mask; // @[Emit.scala 41:54]
  wire  payload_2_MPORT_2_en; // @[Emit.scala 41:54]
  reg  payload_3 [0:511]; // @[Emit.scala 41:54]
  wire  payload_3_r_newOwner_MPORT_en; // @[Emit.scala 41:54]
  wire [8:0] payload_3_r_newOwner_MPORT_addr; // @[Emit.scala 41:54]
  wire  payload_3_r_newOwner_MPORT_data; // @[Emit.scala 41:54]
  wire  payload_3_r_newOwner_MPORT_1_en; // @[Emit.scala 41:54]
  wire [8:0] payload_3_r_newOwner_MPORT_1_addr; // @[Emit.scala 41:54]
  wire  payload_3_r_newOwner_MPORT_1_data; // @[Emit.scala 41:54]
  wire  payload_3_r_newOwner_MPORT_2_en; // @[Emit.scala 41:54]
  wire [8:0] payload_3_r_newOwner_MPORT_2_addr; // @[Emit.scala 41:54]
  wire  payload_3_r_newOwner_MPORT_2_data; // @[Emit.scala 41:54]
  wire  payload_3_r_newOwner_MPORT_3_en; // @[Emit.scala 41:54]
  wire [8:0] payload_3_r_newOwner_MPORT_3_addr; // @[Emit.scala 41:54]
  wire  payload_3_r_newOwner_MPORT_3_data; // @[Emit.scala 41:54]
  wire  payload_3_r_newOwner_MPORT_4_en; // @[Emit.scala 41:54]
  wire [8:0] payload_3_r_newOwner_MPORT_4_addr; // @[Emit.scala 41:54]
  wire  payload_3_r_newOwner_MPORT_4_data; // @[Emit.scala 41:54]
  wire  payload_3_MPORT_3_data; // @[Emit.scala 41:54]
  wire [8:0] payload_3_MPORT_3_addr; // @[Emit.scala 41:54]
  wire  payload_3_MPORT_3_mask; // @[Emit.scala 41:54]
  wire  payload_3_MPORT_3_en; // @[Emit.scala 41:54]
  reg [22:0] payload_4 [0:511]; // @[Emit.scala 41:54]
  wire  payload_4_r_tag_MPORT_en; // @[Emit.scala 41:54]
  wire [8:0] payload_4_r_tag_MPORT_addr; // @[Emit.scala 41:54]
  wire [22:0] payload_4_r_tag_MPORT_data; // @[Emit.scala 41:54]
  wire  payload_4_r_tag_MPORT_1_en; // @[Emit.scala 41:54]
  wire [8:0] payload_4_r_tag_MPORT_1_addr; // @[Emit.scala 41:54]
  wire [22:0] payload_4_r_tag_MPORT_1_data; // @[Emit.scala 41:54]
  wire  payload_4_r_tag_MPORT_2_en; // @[Emit.scala 41:54]
  wire [8:0] payload_4_r_tag_MPORT_2_addr; // @[Emit.scala 41:54]
  wire [22:0] payload_4_r_tag_MPORT_2_data; // @[Emit.scala 41:54]
  wire  payload_4_r_tag_MPORT_3_en; // @[Emit.scala 41:54]
  wire [8:0] payload_4_r_tag_MPORT_3_addr; // @[Emit.scala 41:54]
  wire [22:0] payload_4_r_tag_MPORT_3_data; // @[Emit.scala 41:54]
  wire  payload_4_r_tag_MPORT_4_en; // @[Emit.scala 41:54]
  wire [8:0] payload_4_r_tag_MPORT_4_addr; // @[Emit.scala 41:54]
  wire [22:0] payload_4_r_tag_MPORT_4_data; // @[Emit.scala 41:54]
  wire [22:0] payload_4_MPORT_4_data; // @[Emit.scala 41:54]
  wire [8:0] payload_4_MPORT_4_addr; // @[Emit.scala 41:54]
  wire  payload_4_MPORT_4_mask; // @[Emit.scala 41:54]
  wire  payload_4_MPORT_4_en; // @[Emit.scala 41:54]
  wire [7:0] set = io_index[8:1]; // @[Emit.scala 57:19]
  wire  way = io_index[0]; // @[Emit.scala 57:41]
  wire [7:0] s = io_readIndex_0[8:1]; // @[Emit.scala 66:26]
  wire  v = io_readIndex_0[0]; // @[Emit.scala 66:53]
  wire  r_newOwner = payload_3_r_newOwner_MPORT_data; // @[Emit.scala 66:67 70:15]
  wire [22:0] r_tag = payload_4_r_tag_MPORT_data; // @[Emit.scala 66:67 71:10]
  wire [23:0] io_result_0_lo = {r_newOwner,r_tag}; // @[Emit.scala 72:21]
  wire [15:0] r_epoch = payload_r_epoch_MPORT_data; // @[Emit.scala 66:67 67:12]
  wire [31:0] r_transaction = payload_1_r_transaction_MPORT_data; // @[Emit.scala 66:67 68:18]
  wire [7:0] r_mshr = payload_2_r_mshr_MPORT_data; // @[Emit.scala 66:67 69:11]
  wire [55:0] io_result_0_hi = {r_epoch,r_transaction,r_mshr}; // @[Emit.scala 72:21]
  wire [7:0] s_1 = io_readIndex_1[8:1]; // @[Emit.scala 66:26]
  wire  v_1 = io_readIndex_1[0]; // @[Emit.scala 66:53]
  wire  r_1_newOwner = payload_3_r_newOwner_MPORT_1_data; // @[Emit.scala 66:67 70:15]
  wire [22:0] r_1_tag = payload_4_r_tag_MPORT_1_data; // @[Emit.scala 66:67 71:10]
  wire [23:0] io_result_1_lo = {r_1_newOwner,r_1_tag}; // @[Emit.scala 72:21]
  wire [15:0] r_1_epoch = payload_r_epoch_MPORT_1_data; // @[Emit.scala 66:67 67:12]
  wire [31:0] r_1_transaction = payload_1_r_transaction_MPORT_1_data; // @[Emit.scala 66:67 68:18]
  wire [7:0] r_1_mshr = payload_2_r_mshr_MPORT_1_data; // @[Emit.scala 66:67 69:11]
  wire [55:0] io_result_1_hi = {r_1_epoch,r_1_transaction,r_1_mshr}; // @[Emit.scala 72:21]
  wire [7:0] s_2 = io_readIndex_2[8:1]; // @[Emit.scala 66:26]
  wire  v_2 = io_readIndex_2[0]; // @[Emit.scala 66:53]
  wire  r_2_newOwner = payload_3_r_newOwner_MPORT_2_data; // @[Emit.scala 66:67 70:15]
  wire [22:0] r_2_tag = payload_4_r_tag_MPORT_2_data; // @[Emit.scala 66:67 71:10]
  wire [23:0] io_result_2_lo = {r_2_newOwner,r_2_tag}; // @[Emit.scala 72:21]
  wire [15:0] r_2_epoch = payload_r_epoch_MPORT_2_data; // @[Emit.scala 66:67 67:12]
  wire [31:0] r_2_transaction = payload_1_r_transaction_MPORT_2_data; // @[Emit.scala 66:67 68:18]
  wire [7:0] r_2_mshr = payload_2_r_mshr_MPORT_2_data; // @[Emit.scala 66:67 69:11]
  wire [55:0] io_result_2_hi = {r_2_epoch,r_2_transaction,r_2_mshr}; // @[Emit.scala 72:21]
  wire [7:0] s_3 = io_readIndex_3[8:1]; // @[Emit.scala 66:26]
  wire  v_3 = io_readIndex_3[0]; // @[Emit.scala 66:53]
  wire  r_3_newOwner = payload_3_r_newOwner_MPORT_3_data; // @[Emit.scala 66:67 70:15]
  wire [22:0] r_3_tag = payload_4_r_tag_MPORT_3_data; // @[Emit.scala 66:67 71:10]
  wire [23:0] io_result_3_lo = {r_3_newOwner,r_3_tag}; // @[Emit.scala 72:21]
  wire [15:0] r_3_epoch = payload_r_epoch_MPORT_3_data; // @[Emit.scala 66:67 67:12]
  wire [31:0] r_3_transaction = payload_1_r_transaction_MPORT_3_data; // @[Emit.scala 66:67 68:18]
  wire [7:0] r_3_mshr = payload_2_r_mshr_MPORT_3_data; // @[Emit.scala 66:67 69:11]
  wire [55:0] io_result_3_hi = {r_3_epoch,r_3_transaction,r_3_mshr}; // @[Emit.scala 72:21]
  wire [7:0] s_4 = io_readIndex_4[8:1]; // @[Emit.scala 66:26]
  wire  v_4 = io_readIndex_4[0]; // @[Emit.scala 66:53]
  wire  r_4_newOwner = payload_3_r_newOwner_MPORT_4_data; // @[Emit.scala 66:67 70:15]
  wire [22:0] r_4_tag = payload_4_r_tag_MPORT_4_data; // @[Emit.scala 66:67 71:10]
  wire [23:0] io_result_4_lo = {r_4_newOwner,r_4_tag}; // @[Emit.scala 72:21]
  wire [15:0] r_4_epoch = payload_r_epoch_MPORT_4_data; // @[Emit.scala 66:67 67:12]
  wire [31:0] r_4_transaction = payload_1_r_transaction_MPORT_4_data; // @[Emit.scala 66:67 68:18]
  wire [7:0] r_4_mshr = payload_2_r_mshr_MPORT_4_data; // @[Emit.scala 66:67 69:11]
  wire [55:0] io_result_4_hi = {r_4_epoch,r_4_transaction,r_4_mshr}; // @[Emit.scala 72:21]
  assign payload_r_epoch_MPORT_en = 1'h1;
  assign payload_r_epoch_MPORT_addr = {s,v};
  assign payload_r_epoch_MPORT_data = payload[payload_r_epoch_MPORT_addr]; // @[Emit.scala 41:54]
  assign payload_r_epoch_MPORT_1_en = 1'h1;
  assign payload_r_epoch_MPORT_1_addr = {s_1,v_1};
  assign payload_r_epoch_MPORT_1_data = payload[payload_r_epoch_MPORT_1_addr]; // @[Emit.scala 41:54]
  assign payload_r_epoch_MPORT_2_en = 1'h1;
  assign payload_r_epoch_MPORT_2_addr = {s_2,v_2};
  assign payload_r_epoch_MPORT_2_data = payload[payload_r_epoch_MPORT_2_addr]; // @[Emit.scala 41:54]
  assign payload_r_epoch_MPORT_3_en = 1'h1;
  assign payload_r_epoch_MPORT_3_addr = {s_3,v_3};
  assign payload_r_epoch_MPORT_3_data = payload[payload_r_epoch_MPORT_3_addr]; // @[Emit.scala 41:54]
  assign payload_r_epoch_MPORT_4_en = 1'h1;
  assign payload_r_epoch_MPORT_4_addr = {s_4,v_4};
  assign payload_r_epoch_MPORT_4_data = payload[payload_r_epoch_MPORT_4_addr]; // @[Emit.scala 41:54]
  assign payload_MPORT_data = io_data[79:64];
  assign payload_MPORT_addr = {set,way};
  assign payload_MPORT_mask = 1'h1;
  assign payload_MPORT_en = io_write;
  assign payload_1_r_transaction_MPORT_en = 1'h1;
  assign payload_1_r_transaction_MPORT_addr = {s,v};
  assign payload_1_r_transaction_MPORT_data = payload_1[payload_1_r_transaction_MPORT_addr]; // @[Emit.scala 41:54]
  assign payload_1_r_transaction_MPORT_1_en = 1'h1;
  assign payload_1_r_transaction_MPORT_1_addr = {s_1,v_1};
  assign payload_1_r_transaction_MPORT_1_data = payload_1[payload_1_r_transaction_MPORT_1_addr]; // @[Emit.scala 41:54]
  assign payload_1_r_transaction_MPORT_2_en = 1'h1;
  assign payload_1_r_transaction_MPORT_2_addr = {s_2,v_2};
  assign payload_1_r_transaction_MPORT_2_data = payload_1[payload_1_r_transaction_MPORT_2_addr]; // @[Emit.scala 41:54]
  assign payload_1_r_transaction_MPORT_3_en = 1'h1;
  assign payload_1_r_transaction_MPORT_3_addr = {s_3,v_3};
  assign payload_1_r_transaction_MPORT_3_data = payload_1[payload_1_r_transaction_MPORT_3_addr]; // @[Emit.scala 41:54]
  assign payload_1_r_transaction_MPORT_4_en = 1'h1;
  assign payload_1_r_transaction_MPORT_4_addr = {s_4,v_4};
  assign payload_1_r_transaction_MPORT_4_data = payload_1[payload_1_r_transaction_MPORT_4_addr]; // @[Emit.scala 41:54]
  assign payload_1_MPORT_1_data = io_data[63:32];
  assign payload_1_MPORT_1_addr = {set,way};
  assign payload_1_MPORT_1_mask = 1'h1;
  assign payload_1_MPORT_1_en = io_write;
  assign payload_2_r_mshr_MPORT_en = 1'h1;
  assign payload_2_r_mshr_MPORT_addr = {s,v};
  assign payload_2_r_mshr_MPORT_data = payload_2[payload_2_r_mshr_MPORT_addr]; // @[Emit.scala 41:54]
  assign payload_2_r_mshr_MPORT_1_en = 1'h1;
  assign payload_2_r_mshr_MPORT_1_addr = {s_1,v_1};
  assign payload_2_r_mshr_MPORT_1_data = payload_2[payload_2_r_mshr_MPORT_1_addr]; // @[Emit.scala 41:54]
  assign payload_2_r_mshr_MPORT_2_en = 1'h1;
  assign payload_2_r_mshr_MPORT_2_addr = {s_2,v_2};
  assign payload_2_r_mshr_MPORT_2_data = payload_2[payload_2_r_mshr_MPORT_2_addr]; // @[Emit.scala 41:54]
  assign payload_2_r_mshr_MPORT_3_en = 1'h1;
  assign payload_2_r_mshr_MPORT_3_addr = {s_3,v_3};
  assign payload_2_r_mshr_MPORT_3_data = payload_2[payload_2_r_mshr_MPORT_3_addr]; // @[Emit.scala 41:54]
  assign payload_2_r_mshr_MPORT_4_en = 1'h1;
  assign payload_2_r_mshr_MPORT_4_addr = {s_4,v_4};
  assign payload_2_r_mshr_MPORT_4_data = payload_2[payload_2_r_mshr_MPORT_4_addr]; // @[Emit.scala 41:54]
  assign payload_2_MPORT_2_data = io_data[31:24];
  assign payload_2_MPORT_2_addr = {set,way};
  assign payload_2_MPORT_2_mask = 1'h1;
  assign payload_2_MPORT_2_en = io_write;
  assign payload_3_r_newOwner_MPORT_en = 1'h1;
  assign payload_3_r_newOwner_MPORT_addr = {s,v};
  assign payload_3_r_newOwner_MPORT_data = payload_3[payload_3_r_newOwner_MPORT_addr]; // @[Emit.scala 41:54]
  assign payload_3_r_newOwner_MPORT_1_en = 1'h1;
  assign payload_3_r_newOwner_MPORT_1_addr = {s_1,v_1};
  assign payload_3_r_newOwner_MPORT_1_data = payload_3[payload_3_r_newOwner_MPORT_1_addr]; // @[Emit.scala 41:54]
  assign payload_3_r_newOwner_MPORT_2_en = 1'h1;
  assign payload_3_r_newOwner_MPORT_2_addr = {s_2,v_2};
  assign payload_3_r_newOwner_MPORT_2_data = payload_3[payload_3_r_newOwner_MPORT_2_addr]; // @[Emit.scala 41:54]
  assign payload_3_r_newOwner_MPORT_3_en = 1'h1;
  assign payload_3_r_newOwner_MPORT_3_addr = {s_3,v_3};
  assign payload_3_r_newOwner_MPORT_3_data = payload_3[payload_3_r_newOwner_MPORT_3_addr]; // @[Emit.scala 41:54]
  assign payload_3_r_newOwner_MPORT_4_en = 1'h1;
  assign payload_3_r_newOwner_MPORT_4_addr = {s_4,v_4};
  assign payload_3_r_newOwner_MPORT_4_data = payload_3[payload_3_r_newOwner_MPORT_4_addr]; // @[Emit.scala 41:54]
  assign payload_3_MPORT_3_data = io_data[23];
  assign payload_3_MPORT_3_addr = {set,way};
  assign payload_3_MPORT_3_mask = 1'h1;
  assign payload_3_MPORT_3_en = io_write;
  assign payload_4_r_tag_MPORT_en = 1'h1;
  assign payload_4_r_tag_MPORT_addr = {s,v};
  assign payload_4_r_tag_MPORT_data = payload_4[payload_4_r_tag_MPORT_addr]; // @[Emit.scala 41:54]
  assign payload_4_r_tag_MPORT_1_en = 1'h1;
  assign payload_4_r_tag_MPORT_1_addr = {s_1,v_1};
  assign payload_4_r_tag_MPORT_1_data = payload_4[payload_4_r_tag_MPORT_1_addr]; // @[Emit.scala 41:54]
  assign payload_4_r_tag_MPORT_2_en = 1'h1;
  assign payload_4_r_tag_MPORT_2_addr = {s_2,v_2};
  assign payload_4_r_tag_MPORT_2_data = payload_4[payload_4_r_tag_MPORT_2_addr]; // @[Emit.scala 41:54]
  assign payload_4_r_tag_MPORT_3_en = 1'h1;
  assign payload_4_r_tag_MPORT_3_addr = {s_3,v_3};
  assign payload_4_r_tag_MPORT_3_data = payload_4[payload_4_r_tag_MPORT_3_addr]; // @[Emit.scala 41:54]
  assign payload_4_r_tag_MPORT_4_en = 1'h1;
  assign payload_4_r_tag_MPORT_4_addr = {s_4,v_4};
  assign payload_4_r_tag_MPORT_4_data = payload_4[payload_4_r_tag_MPORT_4_addr]; // @[Emit.scala 41:54]
  assign payload_4_MPORT_4_data = io_data[22:0];
  assign payload_4_MPORT_4_addr = {set,way};
  assign payload_4_MPORT_4_mask = 1'h1;
  assign payload_4_MPORT_4_en = io_write;
  assign io_result_0 = {io_result_0_hi,io_result_0_lo}; // @[Emit.scala 72:21]
  assign io_result_1 = {io_result_1_hi,io_result_1_lo}; // @[Emit.scala 72:21]
  assign io_result_2 = {io_result_2_hi,io_result_2_lo}; // @[Emit.scala 72:21]
  assign io_result_3 = {io_result_3_hi,io_result_3_lo}; // @[Emit.scala 72:21]
  assign io_result_4 = {io_result_4_hi,io_result_4_lo}; // @[Emit.scala 72:21]
  always @(posedge clock) begin
    if (payload_MPORT_en & payload_MPORT_mask) begin
      payload[payload_MPORT_addr] <= payload_MPORT_data; // @[Emit.scala 41:54]
    end
    if (payload_1_MPORT_1_en & payload_1_MPORT_1_mask) begin
      payload_1[payload_1_MPORT_1_addr] <= payload_1_MPORT_1_data; // @[Emit.scala 41:54]
    end
    if (payload_2_MPORT_2_en & payload_2_MPORT_2_mask) begin
      payload_2[payload_2_MPORT_2_addr] <= payload_2_MPORT_2_data; // @[Emit.scala 41:54]
    end
    if (payload_3_MPORT_3_en & payload_3_MPORT_3_mask) begin
      payload_3[payload_3_MPORT_3_addr] <= payload_3_MPORT_3_data; // @[Emit.scala 41:54]
    end
    if (payload_4_MPORT_4_en & payload_4_MPORT_4_mask) begin
      payload_4[payload_4_MPORT_4_addr] <= payload_4_MPORT_4_data; // @[Emit.scala 41:54]
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
`ifdef RANDOMIZE_MEM_INIT
  _RAND_0 = {1{`RANDOM}};
  for (initvar = 0; initvar < 512; initvar = initvar+1)
    payload[initvar] = _RAND_0[15:0];
  _RAND_1 = {1{`RANDOM}};
  for (initvar = 0; initvar < 512; initvar = initvar+1)
    payload_1[initvar] = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  for (initvar = 0; initvar < 512; initvar = initvar+1)
    payload_2[initvar] = _RAND_2[7:0];
  _RAND_3 = {1{`RANDOM}};
  for (initvar = 0; initvar < 512; initvar = initvar+1)
    payload_3[initvar] = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  for (initvar = 0; initvar < 512; initvar = initvar+1)
    payload_4[initvar] = _RAND_4[22:0];
`endif // RANDOMIZE_MEM_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
