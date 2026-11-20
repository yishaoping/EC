module AppliedEffectResultMemory(
  input         clock,
  input         reset,
  input  [7:0]  io_readSet_0,
  input  [7:0]  io_readSet_1,
  input         io_readWay_0,
  input         io_readWay_1,
  output [63:0] io_readData_0,
  output [63:0] io_readData_1,
  input         io_writeEnable,
  input  [7:0]  io_writeSet,
  input         io_writeWay,
  input  [63:0] io_writeData
);
`ifdef RANDOMIZE_MEM_INIT
  reg [63:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
  reg [63:0] payload [0:511]; // @[AppliedEffectResultMemory.scala 22:20]
  wire  payload_io_readData_0_MPORT_en; // @[AppliedEffectResultMemory.scala 22:20]
  wire [8:0] payload_io_readData_0_MPORT_addr; // @[AppliedEffectResultMemory.scala 22:20]
  wire [63:0] payload_io_readData_0_MPORT_data; // @[AppliedEffectResultMemory.scala 22:20]
  wire  payload_io_readData_1_MPORT_en; // @[AppliedEffectResultMemory.scala 22:20]
  wire [8:0] payload_io_readData_1_MPORT_addr; // @[AppliedEffectResultMemory.scala 22:20]
  wire [63:0] payload_io_readData_1_MPORT_data; // @[AppliedEffectResultMemory.scala 22:20]
  wire [63:0] payload_MPORT_data; // @[AppliedEffectResultMemory.scala 22:20]
  wire [8:0] payload_MPORT_addr; // @[AppliedEffectResultMemory.scala 22:20]
  wire  payload_MPORT_mask; // @[AppliedEffectResultMemory.scala 22:20]
  wire  payload_MPORT_en; // @[AppliedEffectResultMemory.scala 22:20]
  assign payload_io_readData_0_MPORT_en = 1'h1;
  assign payload_io_readData_0_MPORT_addr = {io_readSet_0,io_readWay_0};
  assign payload_io_readData_0_MPORT_data = payload[payload_io_readData_0_MPORT_addr]; // @[AppliedEffectResultMemory.scala 22:20]
  assign payload_io_readData_1_MPORT_en = 1'h1;
  assign payload_io_readData_1_MPORT_addr = {io_readSet_1,io_readWay_1};
  assign payload_io_readData_1_MPORT_data = payload[payload_io_readData_1_MPORT_addr]; // @[AppliedEffectResultMemory.scala 22:20]
  assign payload_MPORT_data = io_writeData;
  assign payload_MPORT_addr = {io_writeSet,io_writeWay};
  assign payload_MPORT_mask = 1'h1;
  assign payload_MPORT_en = io_writeEnable;
  assign io_readData_0 = payload_io_readData_0_MPORT_data; // @[AppliedEffectResultMemory.scala 24:20]
  assign io_readData_1 = payload_io_readData_1_MPORT_data; // @[AppliedEffectResultMemory.scala 24:20]
  always @(posedge clock) begin
    if (payload_MPORT_en & payload_MPORT_mask) begin
      payload[payload_MPORT_addr] <= payload_MPORT_data; // @[AppliedEffectResultMemory.scala 22:20]
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
  for (initvar = 0; initvar < 512; initvar = initvar+1)
    payload[initvar] = _RAND_0[63:0];
`endif // RANDOMIZE_MEM_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
