module InstalledCandidate(
  input         clock,
  input         reset,
  input         io_write,
  input  [7:0]  io_set,
  input         io_way,
  input         io_data_valid,
  input  [15:0] io_data_writer,
  input  [31:0] io_data_generation,
  input  [31:0] io_data_contentSeq,
  input  [7:0]  io_readSet,
  input         io_readWay,
  output        io_result_valid,
  output [15:0] io_result_writer,
  output [31:0] io_result_generation,
  output [31:0] io_result_contentSeq
);
`ifdef RANDOMIZE_MEM_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
`endif // RANDOMIZE_MEM_INIT
  reg  installedImage_valid [0:511]; // @[Emit.scala 23:25]
  wire  installedImage_valid_io_result_MPORT_en; // @[Emit.scala 23:25]
  wire [8:0] installedImage_valid_io_result_MPORT_addr; // @[Emit.scala 23:25]
  wire  installedImage_valid_io_result_MPORT_data; // @[Emit.scala 23:25]
  wire  installedImage_valid_MPORT_data; // @[Emit.scala 23:25]
  wire [8:0] installedImage_valid_MPORT_addr; // @[Emit.scala 23:25]
  wire  installedImage_valid_MPORT_mask; // @[Emit.scala 23:25]
  wire  installedImage_valid_MPORT_en; // @[Emit.scala 23:25]
  reg [15:0] installedImage_writer [0:511]; // @[Emit.scala 23:25]
  wire  installedImage_writer_io_result_MPORT_en; // @[Emit.scala 23:25]
  wire [8:0] installedImage_writer_io_result_MPORT_addr; // @[Emit.scala 23:25]
  wire [15:0] installedImage_writer_io_result_MPORT_data; // @[Emit.scala 23:25]
  wire [15:0] installedImage_writer_MPORT_data; // @[Emit.scala 23:25]
  wire [8:0] installedImage_writer_MPORT_addr; // @[Emit.scala 23:25]
  wire  installedImage_writer_MPORT_mask; // @[Emit.scala 23:25]
  wire  installedImage_writer_MPORT_en; // @[Emit.scala 23:25]
  reg [31:0] installedImage_generation [0:511]; // @[Emit.scala 23:25]
  wire  installedImage_generation_io_result_MPORT_en; // @[Emit.scala 23:25]
  wire [8:0] installedImage_generation_io_result_MPORT_addr; // @[Emit.scala 23:25]
  wire [31:0] installedImage_generation_io_result_MPORT_data; // @[Emit.scala 23:25]
  wire [31:0] installedImage_generation_MPORT_data; // @[Emit.scala 23:25]
  wire [8:0] installedImage_generation_MPORT_addr; // @[Emit.scala 23:25]
  wire  installedImage_generation_MPORT_mask; // @[Emit.scala 23:25]
  wire  installedImage_generation_MPORT_en; // @[Emit.scala 23:25]
  reg [31:0] installedImage_contentSeq [0:511]; // @[Emit.scala 23:25]
  wire  installedImage_contentSeq_io_result_MPORT_en; // @[Emit.scala 23:25]
  wire [8:0] installedImage_contentSeq_io_result_MPORT_addr; // @[Emit.scala 23:25]
  wire [31:0] installedImage_contentSeq_io_result_MPORT_data; // @[Emit.scala 23:25]
  wire [31:0] installedImage_contentSeq_MPORT_data; // @[Emit.scala 23:25]
  wire [8:0] installedImage_contentSeq_MPORT_addr; // @[Emit.scala 23:25]
  wire  installedImage_contentSeq_MPORT_mask; // @[Emit.scala 23:25]
  wire  installedImage_contentSeq_MPORT_en; // @[Emit.scala 23:25]
  assign installedImage_valid_io_result_MPORT_en = 1'h1;
  assign installedImage_valid_io_result_MPORT_addr = {io_readSet,io_readWay};
  assign installedImage_valid_io_result_MPORT_data = installedImage_valid[installedImage_valid_io_result_MPORT_addr]; // @[Emit.scala 23:25]
  assign installedImage_valid_MPORT_data = io_data_valid;
  assign installedImage_valid_MPORT_addr = {io_set,io_way};
  assign installedImage_valid_MPORT_mask = 1'h1;
  assign installedImage_valid_MPORT_en = io_write;
  assign installedImage_writer_io_result_MPORT_en = 1'h1;
  assign installedImage_writer_io_result_MPORT_addr = {io_readSet,io_readWay};
  assign installedImage_writer_io_result_MPORT_data = installedImage_writer[installedImage_writer_io_result_MPORT_addr]; // @[Emit.scala 23:25]
  assign installedImage_writer_MPORT_data = io_data_writer;
  assign installedImage_writer_MPORT_addr = {io_set,io_way};
  assign installedImage_writer_MPORT_mask = 1'h1;
  assign installedImage_writer_MPORT_en = io_write;
  assign installedImage_generation_io_result_MPORT_en = 1'h1;
  assign installedImage_generation_io_result_MPORT_addr = {io_readSet,io_readWay};
  assign installedImage_generation_io_result_MPORT_data =
    installedImage_generation[installedImage_generation_io_result_MPORT_addr]; // @[Emit.scala 23:25]
  assign installedImage_generation_MPORT_data = io_data_generation;
  assign installedImage_generation_MPORT_addr = {io_set,io_way};
  assign installedImage_generation_MPORT_mask = 1'h1;
  assign installedImage_generation_MPORT_en = io_write;
  assign installedImage_contentSeq_io_result_MPORT_en = 1'h1;
  assign installedImage_contentSeq_io_result_MPORT_addr = {io_readSet,io_readWay};
  assign installedImage_contentSeq_io_result_MPORT_data =
    installedImage_contentSeq[installedImage_contentSeq_io_result_MPORT_addr]; // @[Emit.scala 23:25]
  assign installedImage_contentSeq_MPORT_data = io_data_contentSeq;
  assign installedImage_contentSeq_MPORT_addr = {io_set,io_way};
  assign installedImage_contentSeq_MPORT_mask = 1'h1;
  assign installedImage_contentSeq_MPORT_en = io_write;
  assign io_result_valid = installedImage_valid_io_result_MPORT_data; // @[Emit.scala 25:12]
  assign io_result_writer = installedImage_writer_io_result_MPORT_data; // @[Emit.scala 25:12]
  assign io_result_generation = installedImage_generation_io_result_MPORT_data; // @[Emit.scala 25:12]
  assign io_result_contentSeq = installedImage_contentSeq_io_result_MPORT_data; // @[Emit.scala 25:12]
  always @(posedge clock) begin
    if (installedImage_valid_MPORT_en & installedImage_valid_MPORT_mask) begin
      installedImage_valid[installedImage_valid_MPORT_addr] <= installedImage_valid_MPORT_data; // @[Emit.scala 23:25]
    end
    if (installedImage_writer_MPORT_en & installedImage_writer_MPORT_mask) begin
      installedImage_writer[installedImage_writer_MPORT_addr] <= installedImage_writer_MPORT_data; // @[Emit.scala 23:25]
    end
    if (installedImage_generation_MPORT_en & installedImage_generation_MPORT_mask) begin
      installedImage_generation[installedImage_generation_MPORT_addr] <= installedImage_generation_MPORT_data; // @[Emit.scala 23:25]
    end
    if (installedImage_contentSeq_MPORT_en & installedImage_contentSeq_MPORT_mask) begin
      installedImage_contentSeq[installedImage_contentSeq_MPORT_addr] <= installedImage_contentSeq_MPORT_data; // @[Emit.scala 23:25]
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
    installedImage_valid[initvar] = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  for (initvar = 0; initvar < 512; initvar = initvar+1)
    installedImage_writer[initvar] = _RAND_1[15:0];
  _RAND_2 = {1{`RANDOM}};
  for (initvar = 0; initvar < 512; initvar = initvar+1)
    installedImage_generation[initvar] = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  for (initvar = 0; initvar < 512; initvar = initvar+1)
    installedImage_contentSeq[initvar] = _RAND_3[31:0];
`endif // RANDOMIZE_MEM_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
