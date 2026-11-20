module Bank(
  input        clock,
  input        reset,
  input  [7:0] in,
  output [7:0] out
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [7:0] count;
  wire [8:0] _GEN_0 = reset ? 9'h0 : count + in;
  assign out = count ^ in;
  always @(posedge clock) begin
    count <= _GEN_0[7:0];
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
  count = _RAND_0[7:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Level0(
  input          clock,
  input          reset,
  input  [7:0]   in,
  output [127:0] out
);
  wire  b0_clock;
  wire  b0_reset;
  wire [7:0] b0_in;
  wire [7:0] b0_out;
  wire  b1_clock;
  wire  b1_reset;
  wire [7:0] b1_in;
  wire [7:0] b1_out;
  wire  b2_clock;
  wire  b2_reset;
  wire [7:0] b2_in;
  wire [7:0] b2_out;
  wire  b3_clock;
  wire  b3_reset;
  wire [7:0] b3_in;
  wire [7:0] b3_out;
  wire  b4_clock;
  wire  b4_reset;
  wire [7:0] b4_in;
  wire [7:0] b4_out;
  wire  b5_clock;
  wire  b5_reset;
  wire [7:0] b5_in;
  wire [7:0] b5_out;
  wire  b6_clock;
  wire  b6_reset;
  wire [7:0] b6_in;
  wire [7:0] b6_out;
  wire  b7_clock;
  wire  b7_reset;
  wire [7:0] b7_in;
  wire [7:0] b7_out;
  wire  b8_clock;
  wire  b8_reset;
  wire [7:0] b8_in;
  wire [7:0] b8_out;
  wire  b9_clock;
  wire  b9_reset;
  wire [7:0] b9_in;
  wire [7:0] b9_out;
  wire  b10_clock;
  wire  b10_reset;
  wire [7:0] b10_in;
  wire [7:0] b10_out;
  wire  b11_clock;
  wire  b11_reset;
  wire [7:0] b11_in;
  wire [7:0] b11_out;
  wire  b12_clock;
  wire  b12_reset;
  wire [7:0] b12_in;
  wire [7:0] b12_out;
  wire  b13_clock;
  wire  b13_reset;
  wire [7:0] b13_in;
  wire [7:0] b13_out;
  wire  b14_clock;
  wire  b14_reset;
  wire [7:0] b14_in;
  wire [7:0] b14_out;
  wire  b15_clock;
  wire  b15_reset;
  wire [7:0] b15_in;
  wire [7:0] b15_out;
  wire [79:0] _GEN_8 = {b0_out,b1_out,b2_out,b3_out,b4_out,b5_out,b6_out,b7_out,b8_out,b9_out};
  wire [119:0] _GEN_13 = {_GEN_8,b10_out,b11_out,b12_out,b13_out,b14_out};
  wire [8:0] _GEN_14 = {{1'd0}, in};
  wire [8:0] _GEN_15 = in + 8'h1;
  wire [8:0] _GEN_16 = in + 8'h2;
  wire [8:0] _GEN_17 = in + 8'h3;
  wire [8:0] _GEN_18 = in + 8'h4;
  wire [8:0] _GEN_19 = in + 8'h5;
  wire [8:0] _GEN_20 = in + 8'h6;
  wire [8:0] _GEN_21 = in + 8'h7;
  wire [8:0] _GEN_22 = in + 8'h8;
  wire [8:0] _GEN_23 = in + 8'h9;
  wire [8:0] _GEN_24 = in + 8'ha;
  wire [8:0] _GEN_25 = in + 8'hb;
  wire [8:0] _GEN_26 = in + 8'hc;
  wire [8:0] _GEN_27 = in + 8'hd;
  wire [8:0] _GEN_28 = in + 8'he;
  wire [8:0] _GEN_29 = in + 8'hf;
  Bank b0 (
    .clock(b0_clock),
    .reset(b0_reset),
    .in(b0_in),
    .out(b0_out)
  );
  Bank b1 (
    .clock(b1_clock),
    .reset(b1_reset),
    .in(b1_in),
    .out(b1_out)
  );
  Bank b2 (
    .clock(b2_clock),
    .reset(b2_reset),
    .in(b2_in),
    .out(b2_out)
  );
  Bank b3 (
    .clock(b3_clock),
    .reset(b3_reset),
    .in(b3_in),
    .out(b3_out)
  );
  Bank b4 (
    .clock(b4_clock),
    .reset(b4_reset),
    .in(b4_in),
    .out(b4_out)
  );
  Bank b5 (
    .clock(b5_clock),
    .reset(b5_reset),
    .in(b5_in),
    .out(b5_out)
  );
  Bank b6 (
    .clock(b6_clock),
    .reset(b6_reset),
    .in(b6_in),
    .out(b6_out)
  );
  Bank b7 (
    .clock(b7_clock),
    .reset(b7_reset),
    .in(b7_in),
    .out(b7_out)
  );
  Bank b8 (
    .clock(b8_clock),
    .reset(b8_reset),
    .in(b8_in),
    .out(b8_out)
  );
  Bank b9 (
    .clock(b9_clock),
    .reset(b9_reset),
    .in(b9_in),
    .out(b9_out)
  );
  Bank b10 (
    .clock(b10_clock),
    .reset(b10_reset),
    .in(b10_in),
    .out(b10_out)
  );
  Bank b11 (
    .clock(b11_clock),
    .reset(b11_reset),
    .in(b11_in),
    .out(b11_out)
  );
  Bank b12 (
    .clock(b12_clock),
    .reset(b12_reset),
    .in(b12_in),
    .out(b12_out)
  );
  Bank b13 (
    .clock(b13_clock),
    .reset(b13_reset),
    .in(b13_in),
    .out(b13_out)
  );
  Bank b14 (
    .clock(b14_clock),
    .reset(b14_reset),
    .in(b14_in),
    .out(b14_out)
  );
  Bank b15 (
    .clock(b15_clock),
    .reset(b15_reset),
    .in(b15_in),
    .out(b15_out)
  );
  assign out = {_GEN_13,b15_out};
  assign b0_clock = clock;
  assign b0_reset = reset;
  assign b0_in = _GEN_14[7:0];
  assign b1_clock = clock;
  assign b1_reset = reset;
  assign b1_in = _GEN_15[7:0];
  assign b2_clock = clock;
  assign b2_reset = reset;
  assign b2_in = _GEN_16[7:0];
  assign b3_clock = clock;
  assign b3_reset = reset;
  assign b3_in = _GEN_17[7:0];
  assign b4_clock = clock;
  assign b4_reset = reset;
  assign b4_in = _GEN_18[7:0];
  assign b5_clock = clock;
  assign b5_reset = reset;
  assign b5_in = _GEN_19[7:0];
  assign b6_clock = clock;
  assign b6_reset = reset;
  assign b6_in = _GEN_20[7:0];
  assign b7_clock = clock;
  assign b7_reset = reset;
  assign b7_in = _GEN_21[7:0];
  assign b8_clock = clock;
  assign b8_reset = reset;
  assign b8_in = _GEN_22[7:0];
  assign b9_clock = clock;
  assign b9_reset = reset;
  assign b9_in = _GEN_23[7:0];
  assign b10_clock = clock;
  assign b10_reset = reset;
  assign b10_in = _GEN_24[7:0];
  assign b11_clock = clock;
  assign b11_reset = reset;
  assign b11_in = _GEN_25[7:0];
  assign b12_clock = clock;
  assign b12_reset = reset;
  assign b12_in = _GEN_26[7:0];
  assign b13_clock = clock;
  assign b13_reset = reset;
  assign b13_in = _GEN_27[7:0];
  assign b14_clock = clock;
  assign b14_reset = reset;
  assign b14_in = _GEN_28[7:0];
  assign b15_clock = clock;
  assign b15_reset = reset;
  assign b15_in = _GEN_29[7:0];
endmodule
module Level1(
  input          clock,
  input          reset,
  input  [7:0]   in,
  output [255:0] out
);
  wire  b0_clock;
  wire  b0_reset;
  wire [7:0] b0_in;
  wire [127:0] b0_out;
  wire  b1_clock;
  wire  b1_reset;
  wire [7:0] b1_in;
  wire [127:0] b1_out;
  wire [8:0] _GEN_0 = {{1'd0}, in};
  wire [8:0] _GEN_1 = in + 8'h1;
  Level0 b0 (
    .clock(b0_clock),
    .reset(b0_reset),
    .in(b0_in),
    .out(b0_out)
  );
  Level0 b1 (
    .clock(b1_clock),
    .reset(b1_reset),
    .in(b1_in),
    .out(b1_out)
  );
  assign out = {b0_out,b1_out};
  assign b0_clock = clock;
  assign b0_reset = reset;
  assign b0_in = _GEN_0[7:0];
  assign b1_clock = clock;
  assign b1_reset = reset;
  assign b1_in = _GEN_1[7:0];
endmodule
module Top(
  input           clock,
  input           reset,
  input  [7:0]    in,
  output [1023:0] out
);
  wire  b0_clock;
  wire  b0_reset;
  wire [7:0] b0_in;
  wire [255:0] b0_out;
  wire  b1_clock;
  wire  b1_reset;
  wire [7:0] b1_in;
  wire [255:0] b1_out;
  wire  b2_clock;
  wire  b2_reset;
  wire [7:0] b2_in;
  wire [255:0] b2_out;
  wire  b3_clock;
  wire  b3_reset;
  wire [7:0] b3_in;
  wire [255:0] b3_out;
  wire [767:0] _GEN_1 = {b0_out,b1_out,b2_out};
  wire [8:0] _GEN_2 = {{1'd0}, in};
  wire [8:0] _GEN_3 = in + 8'h1;
  wire [8:0] _GEN_4 = in + 8'h2;
  wire [8:0] _GEN_5 = in + 8'h3;
  Level1 b0 (
    .clock(b0_clock),
    .reset(b0_reset),
    .in(b0_in),
    .out(b0_out)
  );
  Level1 b1 (
    .clock(b1_clock),
    .reset(b1_reset),
    .in(b1_in),
    .out(b1_out)
  );
  Level1 b2 (
    .clock(b2_clock),
    .reset(b2_reset),
    .in(b2_in),
    .out(b2_out)
  );
  Level1 b3 (
    .clock(b3_clock),
    .reset(b3_reset),
    .in(b3_in),
    .out(b3_out)
  );
  assign out = {_GEN_1,b3_out};
  assign b0_clock = clock;
  assign b0_reset = reset;
  assign b0_in = _GEN_2[7:0];
  assign b1_clock = clock;
  assign b1_reset = reset;
  assign b1_in = _GEN_3[7:0];
  assign b2_clock = clock;
  assign b2_reset = reset;
  assign b2_in = _GEN_4[7:0];
  assign b3_clock = clock;
  assign b3_reset = reset;
  assign b3_in = _GEN_5[7:0];
endmodule
module FAMETop(
  input           clock,
  input           reset,
  input  [7:0]    in,
  output [1023:0] out
);
  wire  b0_clock;
  wire  b0_reset;
  wire [7:0] b0_in;
  wire [1023:0] b0_out;
  wire [8:0] _GEN_0 = {{1'd0}, in};
  Top b0 (
    .clock(b0_clock),
    .reset(b0_reset),
    .in(b0_in),
    .out(b0_out)
  );
  assign out = b0_out;
  assign b0_clock = clock;
  assign b0_reset = reset;
  assign b0_in = _GEN_0[7:0];
endmodule
