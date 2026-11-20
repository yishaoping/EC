module ShiftQueue_30(
  input   clock,
  input   reset,
  output  io_enq_ready,
  input   io_enq_valid,
  input   io_enq_bits,
  input   io_deq_ready,
  output  io_deq_valid,
  output  io_deq_bits
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
`endif // RANDOMIZE_REG_INIT
  reg  valid_0; // @[ShiftQueue.scala 21:30]
  reg  valid_1; // @[ShiftQueue.scala 21:30]
  reg  elts_0; // @[ShiftQueue.scala 22:25]
  reg  elts_1; // @[ShiftQueue.scala 22:25]
  wire  _wen_T = io_enq_ready & io_enq_valid; // @[Decoupled.scala 51:35]
  wire  _wen_T_3 = valid_1 | _wen_T; // @[ShiftQueue.scala 30:28]
  wire  _wen_T_7 = _wen_T & ~valid_0; // @[ShiftQueue.scala 31:45]
  wire  wen = io_deq_ready ? _wen_T_3 : _wen_T_7; // @[ShiftQueue.scala 29:10]
  wire  _valid_0_T_6 = _wen_T | valid_0; // @[ShiftQueue.scala 37:45]
  wire  _wen_T_10 = _wen_T & valid_1; // @[ShiftQueue.scala 30:45]
  wire  _wen_T_13 = _wen_T & valid_0; // @[ShiftQueue.scala 31:25]
  wire  _wen_T_15 = _wen_T & valid_0 & ~valid_1; // @[ShiftQueue.scala 31:45]
  wire  wen_1 = io_deq_ready ? _wen_T_10 : _wen_T_15; // @[ShiftQueue.scala 29:10]
  wire  _valid_1_T_6 = _wen_T_13 | valid_1; // @[ShiftQueue.scala 37:45]
  assign io_enq_ready = ~valid_1; // @[ShiftQueue.scala 40:19]
  assign io_deq_valid = valid_0; // @[ShiftQueue.scala 41:16]
  assign io_deq_bits = elts_0; // @[ShiftQueue.scala 42:15]
  always @(posedge clock) begin
    if (reset) begin // @[ShiftQueue.scala 21:30]
      valid_0 <= 1'h0; // @[ShiftQueue.scala 21:30]
    end else if (io_deq_ready) begin // @[ShiftQueue.scala 35:10]
      valid_0 <= _wen_T_3;
    end else begin
      valid_0 <= _valid_0_T_6;
    end
    if (reset) begin // @[ShiftQueue.scala 21:30]
      valid_1 <= 1'h0; // @[ShiftQueue.scala 21:30]
    end else if (io_deq_ready) begin // @[ShiftQueue.scala 35:10]
      valid_1 <= _wen_T_10;
    end else begin
      valid_1 <= _valid_1_T_6;
    end
    if (wen) begin // @[ShiftQueue.scala 32:16]
      if (valid_1) begin // @[ShiftQueue.scala 27:57]
        elts_0 <= elts_1;
      end else begin
        elts_0 <= io_enq_bits;
      end
    end
    if (wen_1) begin // @[ShiftQueue.scala 32:16]
      elts_1 <= io_enq_bits; // @[ShiftQueue.scala 32:26]
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
  valid_0 = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  valid_1 = _RAND_1[0:0];
  _RAND_2 = {1{`RANDOM}};
  elts_0 = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  elts_1 = _RAND_3[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule