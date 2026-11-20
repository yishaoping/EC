module AddressCurrentBucketMemory(
  input         clock,
  input         reset,
  input  [7:0]  io_currentIndex,
  input  [7:0]  io_retiringIndex,
  input         io_writeEnable,
  input  [63:0] io_writeData_0_0,
  input  [63:0] io_writeData_0_1,
  input  [63:0] io_writeData_0_2,
  input  [63:0] io_writeData_0_3,
  input  [63:0] io_writeData_1_0,
  input  [63:0] io_writeData_1_1,
  input  [63:0] io_writeData_1_2,
  input  [63:0] io_writeData_1_3,
  output [63:0] io_current_0_0,
  output [63:0] io_current_0_1,
  output [63:0] io_current_0_2,
  output [63:0] io_current_0_3,
  output [63:0] io_current_1_0,
  output [63:0] io_current_1_1,
  output [63:0] io_current_1_2,
  output [63:0] io_current_1_3,
  output [63:0] io_retiring_0_0,
  output [63:0] io_retiring_0_1,
  output [63:0] io_retiring_0_2,
  output [63:0] io_retiring_0_3,
  output [63:0] io_retiring_1_0,
  output [63:0] io_retiring_1_1,
  output [63:0] io_retiring_1_2,
  output [63:0] io_retiring_1_3
);
`ifdef RANDOMIZE_MEM_INIT
  reg [63:0] _RAND_0;
  reg [63:0] _RAND_1;
  reg [63:0] _RAND_2;
  reg [63:0] _RAND_3;
  reg [63:0] _RAND_4;
  reg [63:0] _RAND_5;
  reg [63:0] _RAND_6;
  reg [63:0] _RAND_7;
`endif // RANDOMIZE_MEM_INIT
  reg [63:0] payload_0_0 [0:255]; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_0_0_MPORT_en; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_0_0_MPORT_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_0_0_MPORT_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_0_0_MPORT_1_en; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_0_0_MPORT_1_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_0_0_MPORT_1_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_0_0_MPORT_2_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_0_0_MPORT_2_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_0_0_MPORT_2_mask; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_0_0_MPORT_2_en; // @[AddressCurrentBucketMemory.scala 19:20]
  reg [63:0] payload_0_1 [0:255]; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_0_1_MPORT_en; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_0_1_MPORT_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_0_1_MPORT_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_0_1_MPORT_1_en; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_0_1_MPORT_1_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_0_1_MPORT_1_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_0_1_MPORT_2_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_0_1_MPORT_2_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_0_1_MPORT_2_mask; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_0_1_MPORT_2_en; // @[AddressCurrentBucketMemory.scala 19:20]
  reg [63:0] payload_0_2 [0:255]; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_0_2_MPORT_en; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_0_2_MPORT_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_0_2_MPORT_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_0_2_MPORT_1_en; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_0_2_MPORT_1_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_0_2_MPORT_1_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_0_2_MPORT_2_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_0_2_MPORT_2_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_0_2_MPORT_2_mask; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_0_2_MPORT_2_en; // @[AddressCurrentBucketMemory.scala 19:20]
  reg [63:0] payload_0_3 [0:255]; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_0_3_MPORT_en; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_0_3_MPORT_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_0_3_MPORT_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_0_3_MPORT_1_en; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_0_3_MPORT_1_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_0_3_MPORT_1_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_0_3_MPORT_2_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_0_3_MPORT_2_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_0_3_MPORT_2_mask; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_0_3_MPORT_2_en; // @[AddressCurrentBucketMemory.scala 19:20]
  reg [63:0] payload_1_0 [0:255]; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_1_0_MPORT_en; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_1_0_MPORT_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_1_0_MPORT_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_1_0_MPORT_1_en; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_1_0_MPORT_1_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_1_0_MPORT_1_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_1_0_MPORT_2_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_1_0_MPORT_2_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_1_0_MPORT_2_mask; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_1_0_MPORT_2_en; // @[AddressCurrentBucketMemory.scala 19:20]
  reg [63:0] payload_1_1 [0:255]; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_1_1_MPORT_en; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_1_1_MPORT_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_1_1_MPORT_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_1_1_MPORT_1_en; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_1_1_MPORT_1_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_1_1_MPORT_1_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_1_1_MPORT_2_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_1_1_MPORT_2_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_1_1_MPORT_2_mask; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_1_1_MPORT_2_en; // @[AddressCurrentBucketMemory.scala 19:20]
  reg [63:0] payload_1_2 [0:255]; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_1_2_MPORT_en; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_1_2_MPORT_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_1_2_MPORT_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_1_2_MPORT_1_en; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_1_2_MPORT_1_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_1_2_MPORT_1_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_1_2_MPORT_2_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_1_2_MPORT_2_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_1_2_MPORT_2_mask; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_1_2_MPORT_2_en; // @[AddressCurrentBucketMemory.scala 19:20]
  reg [63:0] payload_1_3 [0:255]; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_1_3_MPORT_en; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_1_3_MPORT_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_1_3_MPORT_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_1_3_MPORT_1_en; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_1_3_MPORT_1_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_1_3_MPORT_1_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [63:0] payload_1_3_MPORT_2_data; // @[AddressCurrentBucketMemory.scala 19:20]
  wire [7:0] payload_1_3_MPORT_2_addr; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_1_3_MPORT_2_mask; // @[AddressCurrentBucketMemory.scala 19:20]
  wire  payload_1_3_MPORT_2_en; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_0_0_MPORT_en = 1'h1;
  assign payload_0_0_MPORT_addr = io_currentIndex;
  assign payload_0_0_MPORT_data = payload_0_0[payload_0_0_MPORT_addr]; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_0_0_MPORT_1_en = 1'h1;
  assign payload_0_0_MPORT_1_addr = io_retiringIndex;
  assign payload_0_0_MPORT_1_data = payload_0_0[payload_0_0_MPORT_1_addr]; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_0_0_MPORT_2_data = io_writeData_0_0;
  assign payload_0_0_MPORT_2_addr = io_currentIndex;
  assign payload_0_0_MPORT_2_mask = 1'h1;
  assign payload_0_0_MPORT_2_en = io_writeEnable;
  assign payload_0_1_MPORT_en = 1'h1;
  assign payload_0_1_MPORT_addr = io_currentIndex;
  assign payload_0_1_MPORT_data = payload_0_1[payload_0_1_MPORT_addr]; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_0_1_MPORT_1_en = 1'h1;
  assign payload_0_1_MPORT_1_addr = io_retiringIndex;
  assign payload_0_1_MPORT_1_data = payload_0_1[payload_0_1_MPORT_1_addr]; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_0_1_MPORT_2_data = io_writeData_0_1;
  assign payload_0_1_MPORT_2_addr = io_currentIndex;
  assign payload_0_1_MPORT_2_mask = 1'h1;
  assign payload_0_1_MPORT_2_en = io_writeEnable;
  assign payload_0_2_MPORT_en = 1'h1;
  assign payload_0_2_MPORT_addr = io_currentIndex;
  assign payload_0_2_MPORT_data = payload_0_2[payload_0_2_MPORT_addr]; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_0_2_MPORT_1_en = 1'h1;
  assign payload_0_2_MPORT_1_addr = io_retiringIndex;
  assign payload_0_2_MPORT_1_data = payload_0_2[payload_0_2_MPORT_1_addr]; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_0_2_MPORT_2_data = io_writeData_0_2;
  assign payload_0_2_MPORT_2_addr = io_currentIndex;
  assign payload_0_2_MPORT_2_mask = 1'h1;
  assign payload_0_2_MPORT_2_en = io_writeEnable;
  assign payload_0_3_MPORT_en = 1'h1;
  assign payload_0_3_MPORT_addr = io_currentIndex;
  assign payload_0_3_MPORT_data = payload_0_3[payload_0_3_MPORT_addr]; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_0_3_MPORT_1_en = 1'h1;
  assign payload_0_3_MPORT_1_addr = io_retiringIndex;
  assign payload_0_3_MPORT_1_data = payload_0_3[payload_0_3_MPORT_1_addr]; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_0_3_MPORT_2_data = io_writeData_0_3;
  assign payload_0_3_MPORT_2_addr = io_currentIndex;
  assign payload_0_3_MPORT_2_mask = 1'h1;
  assign payload_0_3_MPORT_2_en = io_writeEnable;
  assign payload_1_0_MPORT_en = 1'h1;
  assign payload_1_0_MPORT_addr = io_currentIndex;
  assign payload_1_0_MPORT_data = payload_1_0[payload_1_0_MPORT_addr]; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_1_0_MPORT_1_en = 1'h1;
  assign payload_1_0_MPORT_1_addr = io_retiringIndex;
  assign payload_1_0_MPORT_1_data = payload_1_0[payload_1_0_MPORT_1_addr]; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_1_0_MPORT_2_data = io_writeData_1_0;
  assign payload_1_0_MPORT_2_addr = io_currentIndex;
  assign payload_1_0_MPORT_2_mask = 1'h1;
  assign payload_1_0_MPORT_2_en = io_writeEnable;
  assign payload_1_1_MPORT_en = 1'h1;
  assign payload_1_1_MPORT_addr = io_currentIndex;
  assign payload_1_1_MPORT_data = payload_1_1[payload_1_1_MPORT_addr]; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_1_1_MPORT_1_en = 1'h1;
  assign payload_1_1_MPORT_1_addr = io_retiringIndex;
  assign payload_1_1_MPORT_1_data = payload_1_1[payload_1_1_MPORT_1_addr]; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_1_1_MPORT_2_data = io_writeData_1_1;
  assign payload_1_1_MPORT_2_addr = io_currentIndex;
  assign payload_1_1_MPORT_2_mask = 1'h1;
  assign payload_1_1_MPORT_2_en = io_writeEnable;
  assign payload_1_2_MPORT_en = 1'h1;
  assign payload_1_2_MPORT_addr = io_currentIndex;
  assign payload_1_2_MPORT_data = payload_1_2[payload_1_2_MPORT_addr]; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_1_2_MPORT_1_en = 1'h1;
  assign payload_1_2_MPORT_1_addr = io_retiringIndex;
  assign payload_1_2_MPORT_1_data = payload_1_2[payload_1_2_MPORT_1_addr]; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_1_2_MPORT_2_data = io_writeData_1_2;
  assign payload_1_2_MPORT_2_addr = io_currentIndex;
  assign payload_1_2_MPORT_2_mask = 1'h1;
  assign payload_1_2_MPORT_2_en = io_writeEnable;
  assign payload_1_3_MPORT_en = 1'h1;
  assign payload_1_3_MPORT_addr = io_currentIndex;
  assign payload_1_3_MPORT_data = payload_1_3[payload_1_3_MPORT_addr]; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_1_3_MPORT_1_en = 1'h1;
  assign payload_1_3_MPORT_1_addr = io_retiringIndex;
  assign payload_1_3_MPORT_1_data = payload_1_3[payload_1_3_MPORT_1_addr]; // @[AddressCurrentBucketMemory.scala 19:20]
  assign payload_1_3_MPORT_2_data = io_writeData_1_3;
  assign payload_1_3_MPORT_2_addr = io_currentIndex;
  assign payload_1_3_MPORT_2_mask = 1'h1;
  assign payload_1_3_MPORT_2_en = io_writeEnable;
  assign io_current_0_0 = payload_0_0_MPORT_data; // @[AddressCurrentBucketMemory.scala 20:14]
  assign io_current_0_1 = payload_0_1_MPORT_data; // @[AddressCurrentBucketMemory.scala 20:14]
  assign io_current_0_2 = payload_0_2_MPORT_data; // @[AddressCurrentBucketMemory.scala 20:14]
  assign io_current_0_3 = payload_0_3_MPORT_data; // @[AddressCurrentBucketMemory.scala 20:14]
  assign io_current_1_0 = payload_1_0_MPORT_data; // @[AddressCurrentBucketMemory.scala 20:14]
  assign io_current_1_1 = payload_1_1_MPORT_data; // @[AddressCurrentBucketMemory.scala 20:14]
  assign io_current_1_2 = payload_1_2_MPORT_data; // @[AddressCurrentBucketMemory.scala 20:14]
  assign io_current_1_3 = payload_1_3_MPORT_data; // @[AddressCurrentBucketMemory.scala 20:14]
  assign io_retiring_0_0 = payload_0_0_MPORT_1_data; // @[AddressCurrentBucketMemory.scala 21:15]
  assign io_retiring_0_1 = payload_0_1_MPORT_1_data; // @[AddressCurrentBucketMemory.scala 21:15]
  assign io_retiring_0_2 = payload_0_2_MPORT_1_data; // @[AddressCurrentBucketMemory.scala 21:15]
  assign io_retiring_0_3 = payload_0_3_MPORT_1_data; // @[AddressCurrentBucketMemory.scala 21:15]
  assign io_retiring_1_0 = payload_1_0_MPORT_1_data; // @[AddressCurrentBucketMemory.scala 21:15]
  assign io_retiring_1_1 = payload_1_1_MPORT_1_data; // @[AddressCurrentBucketMemory.scala 21:15]
  assign io_retiring_1_2 = payload_1_2_MPORT_1_data; // @[AddressCurrentBucketMemory.scala 21:15]
  assign io_retiring_1_3 = payload_1_3_MPORT_1_data; // @[AddressCurrentBucketMemory.scala 21:15]
  always @(posedge clock) begin
    if (payload_0_0_MPORT_2_en & payload_0_0_MPORT_2_mask) begin
      payload_0_0[payload_0_0_MPORT_2_addr] <= payload_0_0_MPORT_2_data; // @[AddressCurrentBucketMemory.scala 19:20]
    end
    if (payload_0_1_MPORT_2_en & payload_0_1_MPORT_2_mask) begin
      payload_0_1[payload_0_1_MPORT_2_addr] <= payload_0_1_MPORT_2_data; // @[AddressCurrentBucketMemory.scala 19:20]
    end
    if (payload_0_2_MPORT_2_en & payload_0_2_MPORT_2_mask) begin
      payload_0_2[payload_0_2_MPORT_2_addr] <= payload_0_2_MPORT_2_data; // @[AddressCurrentBucketMemory.scala 19:20]
    end
    if (payload_0_3_MPORT_2_en & payload_0_3_MPORT_2_mask) begin
      payload_0_3[payload_0_3_MPORT_2_addr] <= payload_0_3_MPORT_2_data; // @[AddressCurrentBucketMemory.scala 19:20]
    end
    if (payload_1_0_MPORT_2_en & payload_1_0_MPORT_2_mask) begin
      payload_1_0[payload_1_0_MPORT_2_addr] <= payload_1_0_MPORT_2_data; // @[AddressCurrentBucketMemory.scala 19:20]
    end
    if (payload_1_1_MPORT_2_en & payload_1_1_MPORT_2_mask) begin
      payload_1_1[payload_1_1_MPORT_2_addr] <= payload_1_1_MPORT_2_data; // @[AddressCurrentBucketMemory.scala 19:20]
    end
    if (payload_1_2_MPORT_2_en & payload_1_2_MPORT_2_mask) begin
      payload_1_2[payload_1_2_MPORT_2_addr] <= payload_1_2_MPORT_2_data; // @[AddressCurrentBucketMemory.scala 19:20]
    end
    if (payload_1_3_MPORT_2_en & payload_1_3_MPORT_2_mask) begin
      payload_1_3[payload_1_3_MPORT_2_addr] <= payload_1_3_MPORT_2_data; // @[AddressCurrentBucketMemory.scala 19:20]
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
  _RAND_0 = {2{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    payload_0_0[initvar] = _RAND_0[63:0];
  _RAND_1 = {2{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    payload_0_1[initvar] = _RAND_1[63:0];
  _RAND_2 = {2{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    payload_0_2[initvar] = _RAND_2[63:0];
  _RAND_3 = {2{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    payload_0_3[initvar] = _RAND_3[63:0];
  _RAND_4 = {2{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    payload_1_0[initvar] = _RAND_4[63:0];
  _RAND_5 = {2{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    payload_1_1[initvar] = _RAND_5[63:0];
  _RAND_6 = {2{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    payload_1_2[initvar] = _RAND_6[63:0];
  _RAND_7 = {2{`RANDOM}};
  for (initvar = 0; initvar < 256; initvar = initvar+1)
    payload_1_3[initvar] = _RAND_7[63:0];
`endif // RANDOMIZE_MEM_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
