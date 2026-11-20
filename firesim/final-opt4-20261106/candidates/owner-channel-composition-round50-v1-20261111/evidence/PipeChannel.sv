module PipeChannel(
  input   clock,
  input   reset,
  output  io_in_ready,
  input   io_in_valid,
  input   io_in_bits,
  input   io_out_ready,
  output  io_out_valid,
  output  io_out_bits
);
  wire  tokens_clock; // @[Channel.scala 30:22]
  wire  tokens_reset; // @[Channel.scala 30:22]
  wire  tokens_io_enq_ready; // @[Channel.scala 30:22]
  wire  tokens_io_enq_valid; // @[Channel.scala 30:22]
  wire  tokens_io_enq_bits; // @[Channel.scala 30:22]
  wire  tokens_io_deq_ready; // @[Channel.scala 30:22]
  wire  tokens_io_deq_valid; // @[Channel.scala 30:22]
  wire  tokens_io_deq_bits; // @[Channel.scala 30:22]
  ShiftQueue_30 tokens ( // @[Channel.scala 30:22]
    .clock(tokens_clock),
    .reset(tokens_reset),
    .io_enq_ready(tokens_io_enq_ready),
    .io_enq_valid(tokens_io_enq_valid),
    .io_enq_bits(tokens_io_enq_bits),
    .io_deq_ready(tokens_io_deq_ready),
    .io_deq_valid(tokens_io_deq_valid),
    .io_deq_bits(tokens_io_deq_bits)
  );
  assign io_in_ready = tokens_io_enq_ready; // @[Channel.scala 31:17]
  assign io_out_valid = tokens_io_deq_valid; // @[Channel.scala 32:10]
  assign io_out_bits = tokens_io_deq_bits; // @[Channel.scala 32:10]
  assign tokens_clock = clock;
  assign tokens_reset = reset;
  assign tokens_io_enq_valid = io_in_valid; // @[Channel.scala 31:17]
  assign tokens_io_enq_bits = io_in_bits; // @[Channel.scala 31:17]
  assign tokens_io_deq_ready = io_out_ready; // @[Channel.scala 32:10]
endmodule