module AddressCurrentBucketMemory(
  input         clock,
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
module AsyncMemoryProbe(
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
  input         io_currentValid,
  input         io_retiringValid,
  input  [63:0] io_delta_0_0,
  input  [63:0] io_delta_0_1,
  input  [63:0] io_delta_0_2,
  input  [63:0] io_delta_0_3,
  input  [63:0] io_delta_1_0,
  input  [63:0] io_delta_1_1,
  input  [63:0] io_delta_1_2,
  input  [63:0] io_delta_1_3,
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
  output [63:0] io_retiring_1_3,
  output [63:0] io_next_0_0,
  output [63:0] io_next_0_1,
  output [63:0] io_next_0_2,
  output [63:0] io_next_0_3,
  output [63:0] io_next_1_0,
  output [63:0] io_next_1_1,
  output [63:0] io_next_1_2,
  output [63:0] io_next_1_3,
  output        io_overflow_0_0,
  output        io_overflow_0_1,
  output        io_overflow_0_2,
  output        io_overflow_0_3,
  output        io_overflow_1_0,
  output        io_overflow_1_1,
  output        io_overflow_1_2,
  output        io_overflow_1_3
);
  wire  m_clock; // @[EmitAsync.scala 53:15]
  wire [7:0] m_io_currentIndex; // @[EmitAsync.scala 53:15]
  wire [7:0] m_io_retiringIndex; // @[EmitAsync.scala 53:15]
  wire  m_io_writeEnable; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_writeData_0_0; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_writeData_0_1; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_writeData_0_2; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_writeData_0_3; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_writeData_1_0; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_writeData_1_1; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_writeData_1_2; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_writeData_1_3; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_current_0_0; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_current_0_1; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_current_0_2; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_current_0_3; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_current_1_0; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_current_1_1; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_current_1_2; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_current_1_3; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_retiring_0_0; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_retiring_0_1; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_retiring_0_2; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_retiring_0_3; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_retiring_1_0; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_retiring_1_1; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_retiring_1_2; // @[EmitAsync.scala 53:15]
  wire [63:0] m_io_retiring_1_3; // @[EmitAsync.scala 53:15]
  wire [63:0] _sum_T = io_currentValid ? m_io_current_0_0 : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  wire [64:0] sum = _sum_T + io_delta_0_0; // @[AddressCurrentBucketMemory.scala 28:24]
  wire [63:0] _sum_T_1 = io_currentValid ? m_io_current_0_1 : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  wire [64:0] sum_1 = _sum_T_1 + io_delta_0_1; // @[AddressCurrentBucketMemory.scala 28:24]
  wire [63:0] _sum_T_2 = io_currentValid ? m_io_current_0_2 : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  wire [64:0] sum_2 = _sum_T_2 + io_delta_0_2; // @[AddressCurrentBucketMemory.scala 28:24]
  wire [63:0] _sum_T_3 = io_currentValid ? m_io_current_0_3 : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  wire [64:0] sum_3 = _sum_T_3 + io_delta_0_3; // @[AddressCurrentBucketMemory.scala 28:24]
  wire [63:0] _sum_T_4 = io_currentValid ? m_io_current_1_0 : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  wire [64:0] sum_4 = _sum_T_4 + io_delta_1_0; // @[AddressCurrentBucketMemory.scala 28:24]
  wire [63:0] _sum_T_5 = io_currentValid ? m_io_current_1_1 : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  wire [64:0] sum_5 = _sum_T_5 + io_delta_1_1; // @[AddressCurrentBucketMemory.scala 28:24]
  wire [63:0] _sum_T_6 = io_currentValid ? m_io_current_1_2 : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  wire [64:0] sum_6 = _sum_T_6 + io_delta_1_2; // @[AddressCurrentBucketMemory.scala 28:24]
  wire [63:0] _sum_T_7 = io_currentValid ? m_io_current_1_3 : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  wire [64:0] sum_7 = _sum_T_7 + io_delta_1_3; // @[AddressCurrentBucketMemory.scala 28:24]
  AddressCurrentBucketMemory m ( // @[EmitAsync.scala 53:15]
    .clock(m_clock),
    .io_currentIndex(m_io_currentIndex),
    .io_retiringIndex(m_io_retiringIndex),
    .io_writeEnable(m_io_writeEnable),
    .io_writeData_0_0(m_io_writeData_0_0),
    .io_writeData_0_1(m_io_writeData_0_1),
    .io_writeData_0_2(m_io_writeData_0_2),
    .io_writeData_0_3(m_io_writeData_0_3),
    .io_writeData_1_0(m_io_writeData_1_0),
    .io_writeData_1_1(m_io_writeData_1_1),
    .io_writeData_1_2(m_io_writeData_1_2),
    .io_writeData_1_3(m_io_writeData_1_3),
    .io_current_0_0(m_io_current_0_0),
    .io_current_0_1(m_io_current_0_1),
    .io_current_0_2(m_io_current_0_2),
    .io_current_0_3(m_io_current_0_3),
    .io_current_1_0(m_io_current_1_0),
    .io_current_1_1(m_io_current_1_1),
    .io_current_1_2(m_io_current_1_2),
    .io_current_1_3(m_io_current_1_3),
    .io_retiring_0_0(m_io_retiring_0_0),
    .io_retiring_0_1(m_io_retiring_0_1),
    .io_retiring_0_2(m_io_retiring_0_2),
    .io_retiring_0_3(m_io_retiring_0_3),
    .io_retiring_1_0(m_io_retiring_1_0),
    .io_retiring_1_1(m_io_retiring_1_1),
    .io_retiring_1_2(m_io_retiring_1_2),
    .io_retiring_1_3(m_io_retiring_1_3)
  );
  assign io_current_0_0 = m_io_current_0_0; // @[EmitAsync.scala 58:21]
  assign io_current_0_1 = m_io_current_0_1; // @[EmitAsync.scala 58:21]
  assign io_current_0_2 = m_io_current_0_2; // @[EmitAsync.scala 58:21]
  assign io_current_0_3 = m_io_current_0_3; // @[EmitAsync.scala 58:21]
  assign io_current_1_0 = m_io_current_1_0; // @[EmitAsync.scala 58:21]
  assign io_current_1_1 = m_io_current_1_1; // @[EmitAsync.scala 58:21]
  assign io_current_1_2 = m_io_current_1_2; // @[EmitAsync.scala 58:21]
  assign io_current_1_3 = m_io_current_1_3; // @[EmitAsync.scala 58:21]
  assign io_retiring_0_0 = io_retiringValid ? m_io_retiring_0_0 : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  assign io_retiring_0_1 = io_retiringValid ? m_io_retiring_0_1 : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  assign io_retiring_0_2 = io_retiringValid ? m_io_retiring_0_2 : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  assign io_retiring_0_3 = io_retiringValid ? m_io_retiring_0_3 : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  assign io_retiring_1_0 = io_retiringValid ? m_io_retiring_1_0 : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  assign io_retiring_1_1 = io_retiringValid ? m_io_retiring_1_1 : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  assign io_retiring_1_2 = io_retiringValid ? m_io_retiring_1_2 : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  assign io_retiring_1_3 = io_retiringValid ? m_io_retiring_1_3 : 64'h0; // @[AddressCurrentBucketMemory.scala 26:49]
  assign io_next_0_0 = sum[63:0]; // @[EmitAsync.scala 60:23]
  assign io_next_0_1 = sum_1[63:0]; // @[EmitAsync.scala 60:23]
  assign io_next_0_2 = sum_2[63:0]; // @[EmitAsync.scala 60:23]
  assign io_next_0_3 = sum_3[63:0]; // @[EmitAsync.scala 60:23]
  assign io_next_1_0 = sum_4[63:0]; // @[EmitAsync.scala 60:23]
  assign io_next_1_1 = sum_5[63:0]; // @[EmitAsync.scala 60:23]
  assign io_next_1_2 = sum_6[63:0]; // @[EmitAsync.scala 60:23]
  assign io_next_1_3 = sum_7[63:0]; // @[EmitAsync.scala 60:23]
  assign io_overflow_0_0 = sum[64]; // @[EmitAsync.scala 60:53]
  assign io_overflow_0_1 = sum_1[64]; // @[EmitAsync.scala 60:53]
  assign io_overflow_0_2 = sum_2[64]; // @[EmitAsync.scala 60:53]
  assign io_overflow_0_3 = sum_3[64]; // @[EmitAsync.scala 60:53]
  assign io_overflow_1_0 = sum_4[64]; // @[EmitAsync.scala 60:53]
  assign io_overflow_1_1 = sum_5[64]; // @[EmitAsync.scala 60:53]
  assign io_overflow_1_2 = sum_6[64]; // @[EmitAsync.scala 60:53]
  assign io_overflow_1_3 = sum_7[64]; // @[EmitAsync.scala 60:53]
  assign m_clock = clock;
  assign m_io_currentIndex = io_currentIndex; // @[EmitAsync.scala 54:20]
  assign m_io_retiringIndex = io_retiringIndex; // @[EmitAsync.scala 54:57]
  assign m_io_writeEnable = io_writeEnable; // @[EmitAsync.scala 55:19]
  assign m_io_writeData_0_0 = io_writeData_0_0; // @[EmitAsync.scala 55:51]
  assign m_io_writeData_0_1 = io_writeData_0_1; // @[EmitAsync.scala 55:51]
  assign m_io_writeData_0_2 = io_writeData_0_2; // @[EmitAsync.scala 55:51]
  assign m_io_writeData_0_3 = io_writeData_0_3; // @[EmitAsync.scala 55:51]
  assign m_io_writeData_1_0 = io_writeData_1_0; // @[EmitAsync.scala 55:51]
  assign m_io_writeData_1_1 = io_writeData_1_1; // @[EmitAsync.scala 55:51]
  assign m_io_writeData_1_2 = io_writeData_1_2; // @[EmitAsync.scala 55:51]
  assign m_io_writeData_1_3 = io_writeData_1_3; // @[EmitAsync.scala 55:51]
endmodule
