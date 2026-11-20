module Performance__GH_FIFO_3(
  input         clock,
  input         reset,
  input         io_enq_valid,
  output        io_enq_ready,
  input  [63:0] io_enq_bits,
  input         io_deq_ready,
  output        io_empty,
  output [63:0] io_deq_bits,
  output        io_status_threeslots,
  output        io_status_twoslots
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [63:0] _RAND_1;
  reg [63:0] _RAND_2;
  reg [63:0] _RAND_3;
  reg [63:0] _RAND_4;
  reg [63:0] _RAND_5;
  reg [63:0] _RAND_6;
  reg [63:0] _RAND_7;
  reg [63:0] _RAND_8;
  reg [63:0] _RAND_9;
  reg [63:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
`endif // RANDOMIZE_REG_INIT
  reg [63:0] memReg_0; // @[GH_FIFO.scala 67:42]
  reg [63:0] memReg_1; // @[GH_FIFO.scala 67:42]
  reg [63:0] memReg_2; // @[GH_FIFO.scala 67:42]
  reg [63:0] memReg_3; // @[GH_FIFO.scala 67:42]
  reg [63:0] memReg_4; // @[GH_FIFO.scala 67:42]
  reg [63:0] memReg_5; // @[GH_FIFO.scala 67:42]
  reg [63:0] memReg_6; // @[GH_FIFO.scala 67:42]
  reg [63:0] memReg_7; // @[GH_FIFO.scala 67:42]
  reg [63:0] memReg_8; // @[GH_FIFO.scala 67:42]
  reg [63:0] memReg_9; // @[GH_FIFO.scala 67:42]
  reg [63:0] memReg_10; // @[GH_FIFO.scala 67:42]
  reg [3:0] readPtr; // @[GH_FIFO.scala 46:42]
  wire [3:0] _nextVal_T_2 = readPtr + 4'h1; // @[GH_FIFO.scala 47:75]
  wire [3:0] nextRead = readPtr == 4'ha ? 4'h0 : _nextVal_T_2; // @[GH_FIFO.scala 47:38]
  reg  fullReg; // @[GH_FIFO.scala 78:42]
  wire  _T_12 = io_enq_valid & ~fullReg; // @[GH_FIFO.scala 103:24]
  reg  emptyReg; // @[GH_FIFO.scala 77:42]
  wire  _T_15 = io_deq_ready & ~emptyReg; // @[GH_FIFO.scala 103:54]
  wire  _T_4 = _T_12 & _T_15; // @[GH_FIFO.scala 83:36]
  wire  incrRead = ~(io_enq_valid & ~fullReg) & (io_deq_ready & ~emptyReg) | _T_4; // @[GH_FIFO.scala 103:69 106:32]
  reg [3:0] writePtr; // @[GH_FIFO.scala 46:42]
  wire [3:0] _nextVal_T_5 = writePtr + 4'h1; // @[GH_FIFO.scala 47:75]
  wire [3:0] nextWrite = writePtr == 4'ha ? 4'h0 : _nextVal_T_5; // @[GH_FIFO.scala 47:38]
  wire  incrWrite = _T_12 & ~_T_15 | _T_4; // @[GH_FIFO.scala 94:68 98:32]
  reg [3:0] num_contentReg; // @[GH_FIFO.scala 79:42]
  wire [63:0] _GEN_4 = 4'h0 == writePtr ? io_enq_bits : memReg_0; // @[GH_FIFO.scala 84:{32,32} 67:42]
  wire [63:0] _GEN_5 = 4'h1 == writePtr ? io_enq_bits : memReg_1; // @[GH_FIFO.scala 84:{32,32} 67:42]
  wire [63:0] _GEN_6 = 4'h2 == writePtr ? io_enq_bits : memReg_2; // @[GH_FIFO.scala 84:{32,32} 67:42]
  wire [63:0] _GEN_7 = 4'h3 == writePtr ? io_enq_bits : memReg_3; // @[GH_FIFO.scala 84:{32,32} 67:42]
  wire [63:0] _GEN_8 = 4'h4 == writePtr ? io_enq_bits : memReg_4; // @[GH_FIFO.scala 84:{32,32} 67:42]
  wire [63:0] _GEN_9 = 4'h5 == writePtr ? io_enq_bits : memReg_5; // @[GH_FIFO.scala 84:{32,32} 67:42]
  wire [63:0] _GEN_10 = 4'h6 == writePtr ? io_enq_bits : memReg_6; // @[GH_FIFO.scala 84:{32,32} 67:42]
  wire [63:0] _GEN_11 = 4'h7 == writePtr ? io_enq_bits : memReg_7; // @[GH_FIFO.scala 84:{32,32} 67:42]
  wire [63:0] _GEN_12 = 4'h8 == writePtr ? io_enq_bits : memReg_8; // @[GH_FIFO.scala 84:{32,32} 67:42]
  wire [63:0] _GEN_13 = 4'h9 == writePtr ? io_enq_bits : memReg_9; // @[GH_FIFO.scala 84:{32,32} 67:42]
  wire [63:0] _GEN_14 = 4'ha == writePtr ? io_enq_bits : memReg_10; // @[GH_FIFO.scala 84:{32,32} 67:42]
  wire [63:0] _GEN_15 = _T_12 & _T_15 ? _GEN_4 : memReg_0; // @[GH_FIFO.scala 67:42 83:68]
  wire [63:0] _GEN_16 = _T_12 & _T_15 ? _GEN_5 : memReg_1; // @[GH_FIFO.scala 67:42 83:68]
  wire [63:0] _GEN_17 = _T_12 & _T_15 ? _GEN_6 : memReg_2; // @[GH_FIFO.scala 67:42 83:68]
  wire [63:0] _GEN_18 = _T_12 & _T_15 ? _GEN_7 : memReg_3; // @[GH_FIFO.scala 67:42 83:68]
  wire [63:0] _GEN_19 = _T_12 & _T_15 ? _GEN_8 : memReg_4; // @[GH_FIFO.scala 67:42 83:68]
  wire [63:0] _GEN_20 = _T_12 & _T_15 ? _GEN_9 : memReg_5; // @[GH_FIFO.scala 67:42 83:68]
  wire [63:0] _GEN_21 = _T_12 & _T_15 ? _GEN_10 : memReg_6; // @[GH_FIFO.scala 67:42 83:68]
  wire [63:0] _GEN_22 = _T_12 & _T_15 ? _GEN_11 : memReg_7; // @[GH_FIFO.scala 67:42 83:68]
  wire [63:0] _GEN_23 = _T_12 & _T_15 ? _GEN_12 : memReg_8; // @[GH_FIFO.scala 67:42 83:68]
  wire [63:0] _GEN_24 = _T_12 & _T_15 ? _GEN_13 : memReg_9; // @[GH_FIFO.scala 67:42 83:68]
  wire [63:0] _GEN_25 = _T_12 & _T_15 ? _GEN_14 : memReg_10; // @[GH_FIFO.scala 67:42 83:68]
  wire  _GEN_26 = _T_12 & _T_15 ? 1'h0 : emptyReg; // @[GH_FIFO.scala 83:68 85:32 77:42]
  wire [3:0] _num_contentReg_T_1 = num_contentReg + 4'h1; // @[GH_FIFO.scala 99:50]
  wire  _GEN_54 = _T_12 & ~_T_15 ? 1'h0 : _GEN_26; // @[GH_FIFO.scala 94:68 96:32]
  wire [3:0] _num_contentReg_T_3 = num_contentReg - 4'h1; // @[GH_FIFO.scala 107:50]
  wire  _GEN_59 = ~(io_enq_valid & ~fullReg) & (io_deq_ready & ~emptyReg) ? nextRead == writePtr : _GEN_54; // @[GH_FIFO.scala 103:69 104:32]
  wire [3:0] _io_status_threeslots_T_1 = 4'hb - 4'h3; // @[GH_FIFO.scala 115:75]
  wire [3:0] _io_status_twoslots_T_1 = 4'hb - 4'h2; // @[GH_FIFO.scala 119:75]
  wire [63:0] _GEN_65 = 4'h1 == readPtr ? memReg_1 : memReg_0; // @[GH_FIFO.scala 123:{32,32}]
  wire [63:0] _GEN_66 = 4'h2 == readPtr ? memReg_2 : _GEN_65; // @[GH_FIFO.scala 123:{32,32}]
  wire [63:0] _GEN_67 = 4'h3 == readPtr ? memReg_3 : _GEN_66; // @[GH_FIFO.scala 123:{32,32}]
  wire [63:0] _GEN_68 = 4'h4 == readPtr ? memReg_4 : _GEN_67; // @[GH_FIFO.scala 123:{32,32}]
  wire [63:0] _GEN_69 = 4'h5 == readPtr ? memReg_5 : _GEN_68; // @[GH_FIFO.scala 123:{32,32}]
  wire [63:0] _GEN_70 = 4'h6 == readPtr ? memReg_6 : _GEN_69; // @[GH_FIFO.scala 123:{32,32}]
  wire [63:0] _GEN_71 = 4'h7 == readPtr ? memReg_7 : _GEN_70; // @[GH_FIFO.scala 123:{32,32}]
  wire [63:0] _GEN_72 = 4'h8 == readPtr ? memReg_8 : _GEN_71; // @[GH_FIFO.scala 123:{32,32}]
  wire [63:0] _GEN_73 = 4'h9 == readPtr ? memReg_9 : _GEN_72; // @[GH_FIFO.scala 123:{32,32}]
  assign io_enq_ready = ~fullReg; // @[GH_FIFO.scala 125:35]
  assign io_empty = emptyReg; // @[GH_FIFO.scala 126:32]
  assign io_deq_bits = 4'ha == readPtr ? memReg_10 : _GEN_73; // @[GH_FIFO.scala 123:{32,32}]
  assign io_status_threeslots = num_contentReg >= _io_status_threeslots_T_1; // @[GH_FIFO.scala 115:54]
  assign io_status_twoslots = num_contentReg >= _io_status_twoslots_T_1; // @[GH_FIFO.scala 119:54]
  always @(posedge clock) begin
    if (reset) begin // @[GH_FIFO.scala 67:42]
      memReg_0 <= 64'h0; // @[GH_FIFO.scala 67:42]
    end else if (_T_12 & ~_T_15) begin // @[GH_FIFO.scala 94:68]
      if (4'h0 == writePtr) begin // @[GH_FIFO.scala 95:32]
        memReg_0 <= io_enq_bits; // @[GH_FIFO.scala 95:32]
      end else begin
        memReg_0 <= _GEN_15;
      end
    end else begin
      memReg_0 <= _GEN_15;
    end
    if (reset) begin // @[GH_FIFO.scala 67:42]
      memReg_1 <= 64'h0; // @[GH_FIFO.scala 67:42]
    end else if (_T_12 & ~_T_15) begin // @[GH_FIFO.scala 94:68]
      if (4'h1 == writePtr) begin // @[GH_FIFO.scala 95:32]
        memReg_1 <= io_enq_bits; // @[GH_FIFO.scala 95:32]
      end else begin
        memReg_1 <= _GEN_16;
      end
    end else begin
      memReg_1 <= _GEN_16;
    end
    if (reset) begin // @[GH_FIFO.scala 67:42]
      memReg_2 <= 64'h0; // @[GH_FIFO.scala 67:42]
    end else if (_T_12 & ~_T_15) begin // @[GH_FIFO.scala 94:68]
      if (4'h2 == writePtr) begin // @[GH_FIFO.scala 95:32]
        memReg_2 <= io_enq_bits; // @[GH_FIFO.scala 95:32]
      end else begin
        memReg_2 <= _GEN_17;
      end
    end else begin
      memReg_2 <= _GEN_17;
    end
    if (reset) begin // @[GH_FIFO.scala 67:42]
      memReg_3 <= 64'h0; // @[GH_FIFO.scala 67:42]
    end else if (_T_12 & ~_T_15) begin // @[GH_FIFO.scala 94:68]
      if (4'h3 == writePtr) begin // @[GH_FIFO.scala 95:32]
        memReg_3 <= io_enq_bits; // @[GH_FIFO.scala 95:32]
      end else begin
        memReg_3 <= _GEN_18;
      end
    end else begin
      memReg_3 <= _GEN_18;
    end
    if (reset) begin // @[GH_FIFO.scala 67:42]
      memReg_4 <= 64'h0; // @[GH_FIFO.scala 67:42]
    end else if (_T_12 & ~_T_15) begin // @[GH_FIFO.scala 94:68]
      if (4'h4 == writePtr) begin // @[GH_FIFO.scala 95:32]
        memReg_4 <= io_enq_bits; // @[GH_FIFO.scala 95:32]
      end else begin
        memReg_4 <= _GEN_19;
      end
    end else begin
      memReg_4 <= _GEN_19;
    end
    if (reset) begin // @[GH_FIFO.scala 67:42]
      memReg_5 <= 64'h0; // @[GH_FIFO.scala 67:42]
    end else if (_T_12 & ~_T_15) begin // @[GH_FIFO.scala 94:68]
      if (4'h5 == writePtr) begin // @[GH_FIFO.scala 95:32]
        memReg_5 <= io_enq_bits; // @[GH_FIFO.scala 95:32]
      end else begin
        memReg_5 <= _GEN_20;
      end
    end else begin
      memReg_5 <= _GEN_20;
    end
    if (reset) begin // @[GH_FIFO.scala 67:42]
      memReg_6 <= 64'h0; // @[GH_FIFO.scala 67:42]
    end else if (_T_12 & ~_T_15) begin // @[GH_FIFO.scala 94:68]
      if (4'h6 == writePtr) begin // @[GH_FIFO.scala 95:32]
        memReg_6 <= io_enq_bits; // @[GH_FIFO.scala 95:32]
      end else begin
        memReg_6 <= _GEN_21;
      end
    end else begin
      memReg_6 <= _GEN_21;
    end
    if (reset) begin // @[GH_FIFO.scala 67:42]
      memReg_7 <= 64'h0; // @[GH_FIFO.scala 67:42]
    end else if (_T_12 & ~_T_15) begin // @[GH_FIFO.scala 94:68]
      if (4'h7 == writePtr) begin // @[GH_FIFO.scala 95:32]
        memReg_7 <= io_enq_bits; // @[GH_FIFO.scala 95:32]
      end else begin
        memReg_7 <= _GEN_22;
      end
    end else begin
      memReg_7 <= _GEN_22;
    end
    if (reset) begin // @[GH_FIFO.scala 67:42]
      memReg_8 <= 64'h0; // @[GH_FIFO.scala 67:42]
    end else if (_T_12 & ~_T_15) begin // @[GH_FIFO.scala 94:68]
      if (4'h8 == writePtr) begin // @[GH_FIFO.scala 95:32]
        memReg_8 <= io_enq_bits; // @[GH_FIFO.scala 95:32]
      end else begin
        memReg_8 <= _GEN_23;
      end
    end else begin
      memReg_8 <= _GEN_23;
    end
    if (reset) begin // @[GH_FIFO.scala 67:42]
      memReg_9 <= 64'h0; // @[GH_FIFO.scala 67:42]
    end else if (_T_12 & ~_T_15) begin // @[GH_FIFO.scala 94:68]
      if (4'h9 == writePtr) begin // @[GH_FIFO.scala 95:32]
        memReg_9 <= io_enq_bits; // @[GH_FIFO.scala 95:32]
      end else begin
        memReg_9 <= _GEN_24;
      end
    end else begin
      memReg_9 <= _GEN_24;
    end
    if (reset) begin // @[GH_FIFO.scala 67:42]
      memReg_10 <= 64'h0; // @[GH_FIFO.scala 67:42]
    end else if (_T_12 & ~_T_15) begin // @[GH_FIFO.scala 94:68]
      if (4'ha == writePtr) begin // @[GH_FIFO.scala 95:32]
        memReg_10 <= io_enq_bits; // @[GH_FIFO.scala 95:32]
      end else begin
        memReg_10 <= _GEN_25;
      end
    end else begin
      memReg_10 <= _GEN_25;
    end
    if (reset) begin // @[GH_FIFO.scala 46:42]
      readPtr <= 4'h0; // @[GH_FIFO.scala 46:42]
    end else if (incrRead) begin // @[GH_FIFO.scala 48:17]
      if (readPtr == 4'ha) begin // @[GH_FIFO.scala 47:38]
        readPtr <= 4'h0;
      end else begin
        readPtr <= _nextVal_T_2;
      end
    end
    if (reset) begin // @[GH_FIFO.scala 78:42]
      fullReg <= 1'h0; // @[GH_FIFO.scala 78:42]
    end else if (~(io_enq_valid & ~fullReg) & (io_deq_ready & ~emptyReg)) begin // @[GH_FIFO.scala 103:69]
      fullReg <= 1'h0; // @[GH_FIFO.scala 105:32]
    end else if (_T_12 & ~_T_15) begin // @[GH_FIFO.scala 94:68]
      fullReg <= nextWrite == readPtr; // @[GH_FIFO.scala 97:32]
    end else if (_T_12 & _T_15) begin // @[GH_FIFO.scala 83:68]
      fullReg <= 1'h0; // @[GH_FIFO.scala 86:32]
    end
    emptyReg <= reset | _GEN_59; // @[GH_FIFO.scala 77:{42,42}]
    if (reset) begin // @[GH_FIFO.scala 46:42]
      writePtr <= 4'h0; // @[GH_FIFO.scala 46:42]
    end else if (incrWrite) begin // @[GH_FIFO.scala 48:17]
      if (writePtr == 4'ha) begin // @[GH_FIFO.scala 47:38]
        writePtr <= 4'h0;
      end else begin
        writePtr <= _nextVal_T_5;
      end
    end
    if (reset) begin // @[GH_FIFO.scala 79:42]
      num_contentReg <= 4'h0; // @[GH_FIFO.scala 79:42]
    end else if (~(io_enq_valid & ~fullReg) & (io_deq_ready & ~emptyReg)) begin // @[GH_FIFO.scala 103:69]
      num_contentReg <= _num_contentReg_T_3; // @[GH_FIFO.scala 107:32]
    end else if (_T_12 & ~_T_15) begin // @[GH_FIFO.scala 94:68]
      num_contentReg <= _num_contentReg_T_1; // @[GH_FIFO.scala 99:32]
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
  _RAND_0 = {2{`RANDOM}};
  memReg_0 = _RAND_0[63:0];
  _RAND_1 = {2{`RANDOM}};
  memReg_1 = _RAND_1[63:0];
  _RAND_2 = {2{`RANDOM}};
  memReg_2 = _RAND_2[63:0];
  _RAND_3 = {2{`RANDOM}};
  memReg_3 = _RAND_3[63:0];
  _RAND_4 = {2{`RANDOM}};
  memReg_4 = _RAND_4[63:0];
  _RAND_5 = {2{`RANDOM}};
  memReg_5 = _RAND_5[63:0];
  _RAND_6 = {2{`RANDOM}};
  memReg_6 = _RAND_6[63:0];
  _RAND_7 = {2{`RANDOM}};
  memReg_7 = _RAND_7[63:0];
  _RAND_8 = {2{`RANDOM}};
  memReg_8 = _RAND_8[63:0];
  _RAND_9 = {2{`RANDOM}};
  memReg_9 = _RAND_9[63:0];
  _RAND_10 = {2{`RANDOM}};
  memReg_10 = _RAND_10[63:0];
  _RAND_11 = {1{`RANDOM}};
  readPtr = _RAND_11[3:0];
  _RAND_12 = {1{`RANDOM}};
  fullReg = _RAND_12[0:0];
  _RAND_13 = {1{`RANDOM}};
  emptyReg = _RAND_13[0:0];
  _RAND_14 = {1{`RANDOM}};
  writePtr = _RAND_14[3:0];
  _RAND_15 = {1{`RANDOM}};
  num_contentReg = _RAND_15[3:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule

module Performance__GH_MemFIFO_1(
  input          clock,
  input          reset,
  input          io_enq_valid,
  output         io_enq_ready,
  input  [129:0] io_enq_bits,
  input          io_deq_ready,
  output         io_empty,
  output [129:0] io_deq_bits,
  output         io_status_twoslots,
  output         io_high_watermark,
  input          io_deq_read,
  output         io_deq_read_valid
);
`ifdef RANDOMIZE_MEM_INIT
  reg [159:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  reg [159:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
`endif // RANDOMIZE_REG_INIT
  reg [129:0] mem [0:254]; // @[GH_FIFO.scala 151:46]
  wire  mem_io_deq_bits_MPORT_en; // @[GH_FIFO.scala 151:46 208:{43,43} 151:46]
  wire [7:0] mem_io_deq_bits_MPORT_addr; // @[GH_FIFO.scala 151:46 208:43]
  reg [129:0] mem_io_deq_bits_MPORT_data; // @[GH_FIFO.scala 151:46]
  wire [129:0] mem_MPORT_data; // @[GH_FIFO.scala 151:46 168:31]
  wire [7:0] mem_MPORT_addr; // @[GH_FIFO.scala 151:46 168:31]
  wire  mem_MPORT_mask; // @[GH_FIFO.scala 151:46 168:31]
  wire  mem_MPORT_en; // @[GH_FIFO.scala 151:46 168:18]
  wire [129:0] mem_MPORT_1_data; // @[GH_FIFO.scala 151:46 179:31]
  wire [7:0] mem_MPORT_1_addr; // @[GH_FIFO.scala 151:46 179:31]
  wire  mem_MPORT_1_mask; // @[GH_FIFO.scala 151:46 179:31]
  wire  mem_MPORT_1_en; // @[GH_FIFO.scala 151:46 179:18]
  reg [7:0] readPtr; // @[GH_FIFO.scala 143:42]
  wire [7:0] _nextVal_T_2 = readPtr + 8'h1; // @[GH_FIFO.scala 144:75]
  wire [7:0] nextRead = readPtr == 8'hfe ? 8'h0 : _nextVal_T_2; // @[GH_FIFO.scala 144:38]
  reg  fullReg; // @[GH_FIFO.scala 159:42]
  wire  enq_fire = io_enq_valid & ~fullReg; // @[GH_FIFO.scala 164:48]
  reg  emptyReg; // @[GH_FIFO.scala 158:42]
  wire  _deq_fire_T = ~emptyReg; // @[GH_FIFO.scala 165:51]
  wire  deq_fire = io_deq_ready & ~emptyReg; // @[GH_FIFO.scala 165:48]
  wire  _T = enq_fire & deq_fire; // @[GH_FIFO.scala 168:18]
  wire  incrRead = ~enq_fire & deq_fire | _T; // @[GH_FIFO.scala 188:32 191:32]
  reg [7:0] writePtr; // @[GH_FIFO.scala 143:42]
  wire [7:0] _nextVal_T_5 = writePtr + 8'h1; // @[GH_FIFO.scala 144:75]
  wire [7:0] nextWrite = writePtr == 8'hfe ? 8'h0 : _nextVal_T_5; // @[GH_FIFO.scala 144:38]
  wire  incrWrite = enq_fire & ~deq_fire | _T; // @[GH_FIFO.scala 179:31 183:32]
  reg [7:0] num_contentReg; // @[GH_FIFO.scala 160:42]
  wire  deq_read_fire = io_deq_read & _deq_fire_T; // @[GH_FIFO.scala 166:47]
  wire  _GEN_7 = enq_fire & deq_fire ? 1'h0 : emptyReg; // @[GH_FIFO.scala 168:31 170:32 158:42]
  wire [7:0] _num_contentReg_T_1 = num_contentReg + 8'h1; // @[GH_FIFO.scala 184:50]
  wire  _GEN_17 = enq_fire & ~deq_fire ? 1'h0 : _GEN_7; // @[GH_FIFO.scala 179:31 181:32]
  wire [7:0] _num_contentReg_T_3 = num_contentReg - 8'h1; // @[GH_FIFO.scala 192:50]
  wire  _GEN_22 = ~enq_fire & deq_fire ? nextRead == writePtr : _GEN_17; // @[GH_FIFO.scala 188:32 189:32]
  wire [7:0] _io_status_twoslots_T_1 = 8'hff - 8'h2; // @[GH_FIFO.scala 204:75]
  reg  deq_read_valid_reg; // @[GH_FIFO.scala 211:41]
  wire [7:0] _io_high_watermark_T_1 = 8'hff - 8'h14; // @[GH_FIFO.scala 221:75]
  assign mem_io_deq_bits_MPORT_en = io_deq_read; // @[GH_FIFO.scala 208:{43,43} 151:46]
  assign mem_io_deq_bits_MPORT_addr = readPtr; // @[GH_FIFO.scala 208:43]
  assign mem_MPORT_data = io_enq_bits; // @[GH_FIFO.scala 168:31]
  assign mem_MPORT_addr = writePtr; // @[GH_FIFO.scala 168:31]
  assign mem_MPORT_mask = 1'h1; // @[GH_FIFO.scala 168:31]
  assign mem_MPORT_en = enq_fire & deq_fire; // @[GH_FIFO.scala 168:18]
  assign mem_MPORT_1_data = io_enq_bits; // @[GH_FIFO.scala 179:31]
  assign mem_MPORT_1_addr = writePtr; // @[GH_FIFO.scala 179:31]
  assign mem_MPORT_1_mask = 1'h1; // @[GH_FIFO.scala 179:31]
  assign mem_MPORT_1_en = enq_fire & ~deq_fire; // @[GH_FIFO.scala 179:18]
  assign io_enq_ready = ~fullReg; // @[GH_FIFO.scala 214:35]
  assign io_empty = emptyReg; // @[GH_FIFO.scala 215:32]
  assign io_deq_bits = mem_io_deq_bits_MPORT_data; // @[GH_FIFO.scala 208:32]
  assign io_status_twoslots = num_contentReg >= _io_status_twoslots_T_1; // @[GH_FIFO.scala 204:54]
  assign io_high_watermark = num_contentReg >= _io_high_watermark_T_1; // @[GH_FIFO.scala 221:54]
  assign io_deq_read_valid = deq_read_valid_reg; // @[GH_FIFO.scala 212:32]
  always @(posedge clock) begin
    if (mem_io_deq_bits_MPORT_en) begin
      mem_io_deq_bits_MPORT_data <= mem[mem_io_deq_bits_MPORT_addr]; // @[GH_FIFO.scala 151:46]
    end
    if (mem_MPORT_en & mem_MPORT_mask) begin
      mem[mem_MPORT_addr] <= mem_MPORT_data; // @[GH_FIFO.scala 151:46]
    end
    if (mem_MPORT_1_en & mem_MPORT_1_mask) begin
      mem[mem_MPORT_1_addr] <= mem_MPORT_1_data; // @[GH_FIFO.scala 151:46]
    end
    if (reset) begin // @[GH_FIFO.scala 143:42]
      readPtr <= 8'h0; // @[GH_FIFO.scala 143:42]
    end else if (incrRead) begin // @[GH_FIFO.scala 145:17]
      if (readPtr == 8'hfe) begin // @[GH_FIFO.scala 144:38]
        readPtr <= 8'h0;
      end else begin
        readPtr <= _nextVal_T_2;
      end
    end
    if (reset) begin // @[GH_FIFO.scala 159:42]
      fullReg <= 1'h0; // @[GH_FIFO.scala 159:42]
    end else if (~enq_fire & deq_fire) begin // @[GH_FIFO.scala 188:32]
      fullReg <= 1'h0; // @[GH_FIFO.scala 190:32]
    end else if (enq_fire & ~deq_fire) begin // @[GH_FIFO.scala 179:31]
      fullReg <= nextWrite == readPtr; // @[GH_FIFO.scala 182:32]
    end else if (enq_fire & deq_fire) begin // @[GH_FIFO.scala 168:31]
      fullReg <= 1'h0; // @[GH_FIFO.scala 171:32]
    end
    emptyReg <= reset | _GEN_22; // @[GH_FIFO.scala 158:{42,42}]
    if (reset) begin // @[GH_FIFO.scala 143:42]
      writePtr <= 8'h0; // @[GH_FIFO.scala 143:42]
    end else if (incrWrite) begin // @[GH_FIFO.scala 145:17]
      if (writePtr == 8'hfe) begin // @[GH_FIFO.scala 144:38]
        writePtr <= 8'h0;
      end else begin
        writePtr <= _nextVal_T_5;
      end
    end
    if (reset) begin // @[GH_FIFO.scala 160:42]
      num_contentReg <= 8'h0; // @[GH_FIFO.scala 160:42]
    end else if (~enq_fire & deq_fire) begin // @[GH_FIFO.scala 188:32]
      num_contentReg <= _num_contentReg_T_3; // @[GH_FIFO.scala 192:32]
    end else if (enq_fire & ~deq_fire) begin // @[GH_FIFO.scala 179:31]
      num_contentReg <= _num_contentReg_T_1; // @[GH_FIFO.scala 184:32]
    end
    if (reset) begin // @[GH_FIFO.scala 211:41]
      deq_read_valid_reg <= 1'h0; // @[GH_FIFO.scala 211:41]
    end else begin
      deq_read_valid_reg <= deq_read_fire; // @[GH_FIFO.scala 211:41]
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
  _RAND_0 = {5{`RANDOM}};
  for (initvar = 0; initvar < 255; initvar = initvar+1)
    mem[initvar] = _RAND_0[129:0];
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {5{`RANDOM}};
  mem_io_deq_bits_MPORT_data = _RAND_1[129:0];
  _RAND_2 = {1{`RANDOM}};
  readPtr = _RAND_2[7:0];
  _RAND_3 = {1{`RANDOM}};
  fullReg = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  emptyReg = _RAND_4[0:0];
  _RAND_5 = {1{`RANDOM}};
  writePtr = _RAND_5[7:0];
  _RAND_6 = {1{`RANDOM}};
  num_contentReg = _RAND_6[7:0];
  _RAND_7 = {1{`RANDOM}};
  deq_read_valid_reg = _RAND_7[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule

module Performance__R_LSL(
  input         clock,
  input         reset,
  input         io_m_ld_valid_0,
  input         io_m_ld_valid_1,
  input         io_m_st_valid_0,
  input         io_m_st_valid_1,
  input  [63:0] io_m_ldst_data_0,
  input  [63:0] io_m_ldst_data_1,
  input  [63:0] io_m_ldst_addr_0,
  input  [63:0] io_m_ldst_addr_1,
  input         io_m_csr_valid_0,
  input         io_m_csr_valid_1,
  input  [63:0] io_m_csr_data_0,
  input  [63:0] io_m_csr_data_1,
  input         io_m_rocc_valid_0,
  input         io_m_rocc_valid_1,
  input  [63:0] io_m_rocc_data_0,
  input  [63:0] io_m_rocc_data_1,
  output        io_cdc_ready_mem,
  output        io_cdc_ready_csr,
  output        io_cdc_ready_rocc,
  output        io_req_ready,
  input         io_req_valid,
  input  [39:0] io_req_addr,
  input  [7:0]  io_req_tag,
  input  [1:0]  io_req_cmd,
  input  [1:0]  io_req_size,
  input         io_req_kill,
  input         io_req_valid_csr,
  output        io_req_ready_csr,
  input         io_req_valid_rocc,
  output        io_req_ready_rocc,
  output        io_resp_valid,
  output [7:0]  io_resp_tag,
  output [1:0]  io_resp_size,
  output [63:0] io_resp_data,
  output        io_resp_has_data,
  output [39:0] io_resp_addr,
  output        io_resp_cacheable,
  output        io_resp_mismatch,
  output        io_resp_replay,
  output        io_quiescent,
  output        io_near_full,
  output [63:0] io_resp_data_csr,
  output [63:0] io_resp_data_rocc,
  output        io_if_empty,
  output        io_lsl_highwatermark,
  output        io_ingress_overflow,
  output        io_st_deq,
  output        io_ld_deq
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [159:0] _RAND_2;
  reg [159:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [159:0] _RAND_6;
  reg [159:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [159:0] _RAND_19;
  reg [31:0] _RAND_20;
  reg [31:0] _RAND_21;
  reg [63:0] _RAND_22;
  reg [63:0] _RAND_23;
  reg [31:0] _RAND_24;
  reg [31:0] _RAND_25;
  reg [63:0] _RAND_26;
  reg [63:0] _RAND_27;
  reg [31:0] _RAND_28;
  reg [31:0] _RAND_29;
  reg [63:0] _RAND_30;
  reg [63:0] _RAND_31;
  reg [31:0] _RAND_32;
  reg [31:0] _RAND_33;
  reg [63:0] _RAND_34;
  reg [63:0] _RAND_35;
`endif // RANDOMIZE_REG_INIT
  wire  u_channel_0_clock; // @[R_LSL.scala 71:83]
  wire  u_channel_0_reset; // @[R_LSL.scala 71:83]
  wire  u_channel_0_io_enq_valid; // @[R_LSL.scala 71:83]
  wire  u_channel_0_io_enq_ready; // @[R_LSL.scala 71:83]
  wire [129:0] u_channel_0_io_enq_bits; // @[R_LSL.scala 71:83]
  wire  u_channel_0_io_deq_ready; // @[R_LSL.scala 71:83]
  wire  u_channel_0_io_empty; // @[R_LSL.scala 71:83]
  wire [129:0] u_channel_0_io_deq_bits; // @[R_LSL.scala 71:83]
  wire  u_channel_0_io_status_twoslots; // @[R_LSL.scala 71:83]
  wire  u_channel_0_io_high_watermark; // @[R_LSL.scala 71:83]
  wire  u_channel_0_io_deq_read; // @[R_LSL.scala 71:83]
  wire  u_channel_0_io_deq_read_valid; // @[R_LSL.scala 71:83]
  wire  u_channel_1_clock; // @[R_LSL.scala 71:83]
  wire  u_channel_1_reset; // @[R_LSL.scala 71:83]
  wire  u_channel_1_io_enq_valid; // @[R_LSL.scala 71:83]
  wire  u_channel_1_io_enq_ready; // @[R_LSL.scala 71:83]
  wire [129:0] u_channel_1_io_enq_bits; // @[R_LSL.scala 71:83]
  wire  u_channel_1_io_deq_ready; // @[R_LSL.scala 71:83]
  wire  u_channel_1_io_empty; // @[R_LSL.scala 71:83]
  wire [129:0] u_channel_1_io_deq_bits; // @[R_LSL.scala 71:83]
  wire  u_channel_1_io_status_twoslots; // @[R_LSL.scala 71:83]
  wire  u_channel_1_io_high_watermark; // @[R_LSL.scala 71:83]
  wire  u_channel_1_io_deq_read; // @[R_LSL.scala 71:83]
  wire  u_channel_1_io_deq_read_valid; // @[R_LSL.scala 71:83]
  wire  u_channel_csr_0_clock; // @[R_LSL.scala 72:83]
  wire  u_channel_csr_0_reset; // @[R_LSL.scala 72:83]
  wire  u_channel_csr_0_io_enq_valid; // @[R_LSL.scala 72:83]
  wire  u_channel_csr_0_io_enq_ready; // @[R_LSL.scala 72:83]
  wire [63:0] u_channel_csr_0_io_enq_bits; // @[R_LSL.scala 72:83]
  wire  u_channel_csr_0_io_deq_ready; // @[R_LSL.scala 72:83]
  wire  u_channel_csr_0_io_empty; // @[R_LSL.scala 72:83]
  wire [63:0] u_channel_csr_0_io_deq_bits; // @[R_LSL.scala 72:83]
  wire  u_channel_csr_0_io_status_threeslots; // @[R_LSL.scala 72:83]
  wire  u_channel_csr_0_io_status_twoslots; // @[R_LSL.scala 72:83]
  wire  u_channel_csr_1_clock; // @[R_LSL.scala 72:83]
  wire  u_channel_csr_1_reset; // @[R_LSL.scala 72:83]
  wire  u_channel_csr_1_io_enq_valid; // @[R_LSL.scala 72:83]
  wire  u_channel_csr_1_io_enq_ready; // @[R_LSL.scala 72:83]
  wire [63:0] u_channel_csr_1_io_enq_bits; // @[R_LSL.scala 72:83]
  wire  u_channel_csr_1_io_deq_ready; // @[R_LSL.scala 72:83]
  wire  u_channel_csr_1_io_empty; // @[R_LSL.scala 72:83]
  wire [63:0] u_channel_csr_1_io_deq_bits; // @[R_LSL.scala 72:83]
  wire  u_channel_csr_1_io_status_threeslots; // @[R_LSL.scala 72:83]
  wire  u_channel_csr_1_io_status_twoslots; // @[R_LSL.scala 72:83]
  wire  u_channel_rocc_0_clock; // @[R_LSL.scala 73:83]
  wire  u_channel_rocc_0_reset; // @[R_LSL.scala 73:83]
  wire  u_channel_rocc_0_io_enq_valid; // @[R_LSL.scala 73:83]
  wire  u_channel_rocc_0_io_enq_ready; // @[R_LSL.scala 73:83]
  wire [63:0] u_channel_rocc_0_io_enq_bits; // @[R_LSL.scala 73:83]
  wire  u_channel_rocc_0_io_deq_ready; // @[R_LSL.scala 73:83]
  wire  u_channel_rocc_0_io_empty; // @[R_LSL.scala 73:83]
  wire [63:0] u_channel_rocc_0_io_deq_bits; // @[R_LSL.scala 73:83]
  wire  u_channel_rocc_0_io_status_threeslots; // @[R_LSL.scala 73:83]
  wire  u_channel_rocc_0_io_status_twoslots; // @[R_LSL.scala 73:83]
  wire  u_channel_rocc_1_clock; // @[R_LSL.scala 73:83]
  wire  u_channel_rocc_1_reset; // @[R_LSL.scala 73:83]
  wire  u_channel_rocc_1_io_enq_valid; // @[R_LSL.scala 73:83]
  wire  u_channel_rocc_1_io_enq_ready; // @[R_LSL.scala 73:83]
  wire [63:0] u_channel_rocc_1_io_enq_bits; // @[R_LSL.scala 73:83]
  wire  u_channel_rocc_1_io_deq_ready; // @[R_LSL.scala 73:83]
  wire  u_channel_rocc_1_io_empty; // @[R_LSL.scala 73:83]
  wire [63:0] u_channel_rocc_1_io_deq_bits; // @[R_LSL.scala 73:83]
  wire  u_channel_rocc_1_io_status_threeslots; // @[R_LSL.scala 73:83]
  wire  u_channel_rocc_1_io_status_twoslots; // @[R_LSL.scala 73:83]
  reg [1:0] lsl_enq_ptr; // @[R_LSL.scala 75:55]
  reg [1:0] lsl_deq_ptr; // @[R_LSL.scala 76:55]
  reg [129:0] enq_data_0; // @[R_LSL.scala 82:40]
  reg [129:0] enq_data_1; // @[R_LSL.scala 82:40]
  reg  enq_valid_0; // @[R_LSL.scala 83:40]
  reg  enq_valid_1; // @[R_LSL.scala 83:40]
  wire [129:0] _enq_data_0_T = {io_m_st_valid_0,io_m_ld_valid_0,io_m_ldst_data_0,io_m_ldst_addr_0}; // @[Cat.scala 33:92]
  wire [129:0] _enq_data_1_T = {io_m_st_valid_1,io_m_ld_valid_1,io_m_ldst_data_1,io_m_ldst_addr_1}; // @[Cat.scala 33:92]
  wire [1:0] numEnq = enq_valid_0 + enq_valid_1; // @[Bitwise.scala 51:90]
  wire [1:0] _lsl_enq_ptr_T_1 = lsl_enq_ptr + numEnq; // @[R_LSL.scala 93:36]
  wire [1:0] _lsl_enq_ptr_T_6 = _lsl_enq_ptr_T_1 - 2'h2; // @[R_LSL.scala 93:99]
  wire [2:0] _enq_offset_T = {{1'd0}, lsl_enq_ptr}; // @[R_LSL.scala 97:53]
  wire [1:0] _enq_offset_T_6 = _enq_offset_T[1:0] - 2'h2; // @[R_LSL.scala 97:106]
  wire [1:0] enq_offset_0 = _enq_offset_T[1:0] >= 2'h2 ? _enq_offset_T_6 : _enq_offset_T[1:0]; // @[R_LSL.scala 97:40]
  wire [1:0] _GEN_1 = {{1'd0}, enq_valid_0}; // @[R_LSL.scala 97:53]
  wire [1:0] _enq_offset_T_10 = lsl_enq_ptr + _GEN_1; // @[R_LSL.scala 97:53]
  wire [1:0] _enq_offset_T_15 = _enq_offset_T_10 - 2'h2; // @[R_LSL.scala 97:106]
  wire [1:0] enq_offset_1 = _enq_offset_T_10 >= 2'h2 ? _enq_offset_T_15 : _enq_offset_T_10; // @[R_LSL.scala 97:40]
  wire  enq_OH_0 = enq_offset_0 == 2'h0 & enq_valid_0; // @[R_LSL.scala 100:100]
  wire  enq_OH_1 = enq_offset_1 == 2'h0 & enq_valid_1; // @[R_LSL.scala 100:100]
  wire [129:0] _wdata_T = enq_OH_0 ? enq_data_0 : 130'h0; // @[Mux.scala 27:73]
  wire [129:0] _wdata_T_1 = enq_OH_1 ? enq_data_1 : 130'h0; // @[Mux.scala 27:73]
  wire  _lsl_enq_overflow_0_T = ~u_channel_0_io_enq_ready; // @[R_LSL.scala 105:52]
  wire  lsl_enq_overflow_0 = u_channel_0_io_enq_valid & _lsl_enq_overflow_0_T; // @[R_LSL.scala 104:78]
  wire  enq_OH_0_1 = enq_offset_0 == 2'h1 & enq_valid_0; // @[R_LSL.scala 100:100]
  wire  enq_OH_1_1 = enq_offset_1 == 2'h1 & enq_valid_1; // @[R_LSL.scala 100:100]
  wire [129:0] _wdata_T_3 = enq_OH_0_1 ? enq_data_0 : 130'h0; // @[Mux.scala 27:73]
  wire [129:0] _wdata_T_4 = enq_OH_1_1 ? enq_data_1 : 130'h0; // @[Mux.scala 27:73]
  wire  _lsl_enq_overflow_1_T = ~u_channel_1_io_enq_ready; // @[R_LSL.scala 105:52]
  wire  lsl_enq_overflow_1 = u_channel_1_io_enq_valid & _lsl_enq_overflow_1_T; // @[R_LSL.scala 104:78]
  reg [129:0] lsl_head_payload_0; // @[R_LSL.scala 114:40]
  reg [129:0] lsl_head_payload_1; // @[R_LSL.scala 114:40]
  reg  lsl_head_valid_0; // @[R_LSL.scala 115:40]
  reg  lsl_head_valid_1; // @[R_LSL.scala 115:40]
  reg  lsl_prefetch_pending_0; // @[R_LSL.scala 116:40]
  reg  lsl_prefetch_pending_1; // @[R_LSL.scala 116:40]
  reg  req_valid_reg; // @[R_LSL.scala 119:40]
  reg  resp_valid_reg; // @[R_LSL.scala 120:40]
  reg  resp_kill_reg; // @[R_LSL.scala 121:40]
  reg  resp_mismatch_reg; // @[R_LSL.scala 122:40]
  reg [7:0] resp_tag; // @[R_LSL.scala 123:40]
  reg [1:0] cmd; // @[R_LSL.scala 124:40]
  reg [1:0] req_size_reg; // @[R_LSL.scala 125:40]
  reg [129:0] resp_packet_reg; // @[R_LSL.scala 127:40]
  wire  lsl_empty_0 = u_channel_0_io_empty; // @[R_LSL.scala 113:41 205:48]
  wire  lsl_nonempty_0 = ~lsl_empty_0; // @[R_LSL.scala 131:60]
  wire  lsl_empty_1 = u_channel_1_io_empty; // @[R_LSL.scala 113:41 205:48]
  wire  lsl_nonempty_1 = ~lsl_empty_1; // @[R_LSL.scala 131:60]
  wire  _GEN_2 = lsl_deq_ptr[0] ? lsl_empty_1 : lsl_empty_0; // @[R_LSL.scala 132:{37,37}]
  wire [1:0] _lsl_deq_bank_T_2 = {lsl_nonempty_1,lsl_nonempty_0}; // @[R_LSL.scala 133:66]
  wire  _lsl_deq_bank_T_5 = _lsl_deq_bank_T_2[0] ? 1'h0 : 1'h1; // @[Mux.scala 47:70]
  wire [1:0] lsl_deq_bank = ~_GEN_2 ? lsl_deq_ptr : {{1'd0}, _lsl_deq_bank_T_5}; // @[R_LSL.scala 132:36]
  wire  _selected_head_T = lsl_deq_bank == 2'h0; // @[R_LSL.scala 141:104]
  wire  _selected_head_T_1 = lsl_deq_bank == 2'h1; // @[R_LSL.scala 141:104]
  wire [129:0] _selected_head_T_2 = _selected_head_T ? lsl_head_payload_0 : 130'h0; // @[Mux.scala 27:73]
  wire [129:0] _selected_head_T_3 = _selected_head_T_1 ? lsl_head_payload_1 : 130'h0; // @[Mux.scala 27:73]
  wire [129:0] _selected_head_T_4 = _selected_head_T_2 | _selected_head_T_3; // @[Mux.scala 27:73]
  wire [129:0] selected_head = _selected_head_T_2 | _selected_head_T_3; // @[Mux.scala 27:73]
  wire  lsl_head_available = lsl_nonempty_0 | lsl_nonempty_1; // @[R_LSL.scala 145:53]
  wire  selected_head_is_load = _selected_head_T_4[128]; // @[R_LSL.scala 143:46]
  wire  selected_head_is_store = _selected_head_T_4[129]; // @[R_LSL.scala 142:46]
  wire  _lsl_req_type_match_T = selected_head_is_load | selected_head_is_store; // @[R_LSL.scala 151:38]
  wire  _lsl_req_type_match_T_4 = 2'h2 == io_req_cmd ? selected_head_is_store : 2'h1 == io_req_cmd &
    selected_head_is_load; // @[Mux.scala 81:58]
  wire  lsl_req_type_match = 2'h3 == io_req_cmd ? _lsl_req_type_match_T : _lsl_req_type_match_T_4; // @[Mux.scala 81:58]
  wire [39:0] selected_head_addr = _selected_head_T_4[39:0]; // @[R_LSL.scala 144:46]
  wire  lsl_req_addr_match = selected_head_addr == io_req_addr; // @[R_LSL.scala 153:51]
  wire  _GEN_4 = lsl_deq_bank[0] ? lsl_head_valid_1 : lsl_head_valid_0; // @[R_LSL.scala 158:{30,30}]
  wire  selected_head_valid = lsl_deq_bank[0] ? lsl_head_valid_1 : lsl_head_valid_0; // @[R_LSL.scala 158:{30,30}]
  wire  _lsl_response_ready_T = lsl_head_available & _GEN_4; // @[R_LSL.scala 162:51]
  wire  _lsl_response_ready_T_1 = ~io_req_kill; // @[R_LSL.scala 164:33]
  wire  lsl_response_ready = _lsl_response_ready_T & _lsl_response_ready_T_1; // @[R_LSL.scala 163:53]
  wire  _lsl_req_match_T = lsl_response_ready & lsl_req_type_match; // @[R_LSL.scala 165:51]
  wire  lsl_req_match = _lsl_req_match_T & lsl_req_addr_match; // @[R_LSL.scala 166:52]
  wire  lsl_response_fire = io_req_valid & lsl_response_ready; // @[R_LSL.scala 168:45]
  wire  lsl_deq_fire = lsl_response_fire & lsl_req_match; // @[R_LSL.scala 169:50]
  wire  _lsl_prefetch_0_T_3 = ~lsl_prefetch_pending_0; // @[R_LSL.scala 175:24]
  wire  _lsl_prefetch_1_T_3 = ~lsl_prefetch_pending_1; // @[R_LSL.scala 175:24]
  wire  deq_valid_0 = _selected_head_T & lsl_deq_fire; // @[R_LSL.scala 200:72]
  wire  deq_valid_1 = _selected_head_T_1 & lsl_deq_fire; // @[R_LSL.scala 200:72]
  wire  _T_1 = deq_valid_0 | deq_valid_1; // @[R_LSL.scala 210:26]
  wire [1:0] _lsl_deq_ptr_T_1 = lsl_deq_bank + 2'h1; // @[R_LSL.scala 211:37]
  wire [1:0] _lsl_deq_ptr_T_6 = _lsl_deq_ptr_T_1 - 2'h2; // @[R_LSL.scala 211:95]
  wire  lsl_prefetch_response_0 = u_channel_0_io_deq_read_valid; // @[R_LSL.scala 118:41 204:48]
  wire  lsl_prefetch_0 = lsl_nonempty_0 & ~lsl_head_valid_0 & _lsl_prefetch_0_T_3; // @[R_LSL.scala 174:60]
  wire  _GEN_6 = lsl_prefetch_0 | lsl_prefetch_pending_0; // @[R_LSL.scala 224:34 225:31 116:40]
  wire [129:0] deq_data_0 = u_channel_0_io_deq_bits; // @[R_LSL.scala 111:41 203:48]
  wire  _GEN_8 = lsl_prefetch_pending_0 & lsl_prefetch_response_0 | lsl_head_valid_0; // @[R_LSL.scala 218:70 222:25 115:40]
  wire  lsl_prefetch_response_1 = u_channel_1_io_deq_read_valid; // @[R_LSL.scala 118:41 204:48]
  wire  lsl_prefetch_1 = lsl_nonempty_1 & ~lsl_head_valid_1 & _lsl_prefetch_1_T_3; // @[R_LSL.scala 174:60]
  wire  _GEN_13 = lsl_prefetch_1 | lsl_prefetch_pending_1; // @[R_LSL.scala 224:34 225:31 116:40]
  wire [129:0] deq_data_1 = u_channel_1_io_deq_bits; // @[R_LSL.scala 111:41 203:48]
  wire  _GEN_15 = lsl_prefetch_pending_1 & lsl_prefetch_response_1 | lsl_head_valid_1; // @[R_LSL.scala 218:70 222:25 115:40]
  wire [129:0] out_packet = resp_packet_reg; // @[R_LSL.scala 128:{41,41}]
  wire  _io_resp_replay_T = ~resp_valid_reg; // @[R_LSL.scala 252:50]
  wire  _io_quiescent_T_1 = ~(lsl_head_valid_0 | lsl_head_valid_1); // @[R_LSL.scala 258:33]
  wire  _io_quiescent_T_2 = io_if_empty & _io_quiescent_T_1; // @[R_LSL.scala 257:45]
  wire  _io_quiescent_T_4 = ~(lsl_prefetch_pending_0 | lsl_prefetch_pending_1); // @[R_LSL.scala 259:33]
  wire  _io_quiescent_T_5 = _io_quiescent_T_2 & _io_quiescent_T_4; // @[R_LSL.scala 258:61]
  wire  _io_quiescent_T_6 = ~req_valid_reg; // @[R_LSL.scala 260:33]
  wire  _io_quiescent_T_7 = _io_quiescent_T_5 & _io_quiescent_T_6; // @[R_LSL.scala 259:67]
  wire  _io_quiescent_T_10 = ~io_req_valid; // @[R_LSL.scala 261:33]
  wire  _io_quiescent_T_11 = _io_quiescent_T_7 & _io_resp_replay_T & _io_quiescent_T_10; // @[R_LSL.scala 260:67]
  wire  _io_quiescent_T_14 = ~io_req_valid_rocc; // @[R_LSL.scala 262:33]
  reg [1:0] csr_enq_ptr; // @[R_LSL.scala 271:55]
  reg [1:0] csr_deq_ptr; // @[R_LSL.scala 272:55]
  reg [63:0] csr_enq_data_0; // @[R_LSL.scala 274:44]
  reg [63:0] csr_enq_data_1; // @[R_LSL.scala 274:44]
  reg  csr_enq_valid_0; // @[R_LSL.scala 275:44]
  reg  csr_enq_valid_1; // @[R_LSL.scala 275:44]
  wire [1:0] csr_numEnq = csr_enq_valid_0 + csr_enq_valid_1; // @[Bitwise.scala 51:90]
  wire [1:0] _csr_enq_ptr_T_1 = csr_enq_ptr + csr_numEnq; // @[R_LSL.scala 285:36]
  wire [1:0] _csr_enq_ptr_T_6 = _csr_enq_ptr_T_1 - 2'h2; // @[R_LSL.scala 285:107]
  wire [2:0] _csr_enq_offset_T = {{1'd0}, csr_enq_ptr}; // @[R_LSL.scala 289:61]
  wire [1:0] _csr_enq_offset_T_6 = _csr_enq_offset_T[1:0] - 2'h2; // @[R_LSL.scala 289:114]
  wire [1:0] csr_enq_offset_0 = _csr_enq_offset_T[1:0] >= 2'h2 ? _csr_enq_offset_T_6 : _csr_enq_offset_T[1:0]; // @[R_LSL.scala 289:48]
  wire [1:0] _GEN_3 = {{1'd0}, csr_enq_valid_0}; // @[R_LSL.scala 289:61]
  wire [1:0] _csr_enq_offset_T_10 = csr_enq_ptr + _GEN_3; // @[R_LSL.scala 289:61]
  wire [1:0] _csr_enq_offset_T_15 = _csr_enq_offset_T_10 - 2'h2; // @[R_LSL.scala 289:114]
  wire [1:0] csr_enq_offset_1 = _csr_enq_offset_T_10 >= 2'h2 ? _csr_enq_offset_T_15 : _csr_enq_offset_T_10; // @[R_LSL.scala 289:48]
  wire  csr_enq_OH_0 = csr_enq_offset_0 == 2'h0 & csr_enq_valid_0; // @[R_LSL.scala 292:108]
  wire  csr_enq_OH_1 = csr_enq_offset_1 == 2'h0 & csr_enq_valid_1; // @[R_LSL.scala 292:108]
  wire [63:0] _csr_wdata_T = csr_enq_OH_0 ? csr_enq_data_0 : 64'h0; // @[Mux.scala 27:73]
  wire [63:0] _csr_wdata_T_1 = csr_enq_OH_1 ? csr_enq_data_1 : 64'h0; // @[Mux.scala 27:73]
  wire  _csr_enq_overflow_0_T = ~u_channel_csr_0_io_enq_ready; // @[R_LSL.scala 297:38]
  wire  csr_enq_overflow_0 = u_channel_csr_0_io_enq_valid & _csr_enq_overflow_0_T; // @[R_LSL.scala 296:68]
  wire  csr_enq_OH_0_1 = csr_enq_offset_0 == 2'h1 & csr_enq_valid_0; // @[R_LSL.scala 292:108]
  wire  csr_enq_OH_1_1 = csr_enq_offset_1 == 2'h1 & csr_enq_valid_1; // @[R_LSL.scala 292:108]
  wire [63:0] _csr_wdata_T_3 = csr_enq_OH_0_1 ? csr_enq_data_0 : 64'h0; // @[Mux.scala 27:73]
  wire [63:0] _csr_wdata_T_4 = csr_enq_OH_1_1 ? csr_enq_data_1 : 64'h0; // @[Mux.scala 27:73]
  wire  _csr_enq_overflow_1_T = ~u_channel_csr_1_io_enq_ready; // @[R_LSL.scala 297:38]
  wire  csr_enq_overflow_1 = u_channel_csr_1_io_enq_valid & _csr_enq_overflow_1_T; // @[R_LSL.scala 296:68]
  reg [63:0] csr_deq_data_0; // @[R_LSL.scala 303:44]
  reg [63:0] csr_deq_data_1; // @[R_LSL.scala 303:44]
  wire  csr_lsl_empty_1 = u_channel_csr_1_io_empty; // @[R_LSL.scala 305:45 320:52]
  wire  csr_lsl_empty_0 = u_channel_csr_0_io_empty; // @[R_LSL.scala 305:45 320:52]
  wire  _GEN_23 = csr_deq_ptr[0] ? csr_lsl_empty_1 : csr_lsl_empty_0; // @[R_LSL.scala 310:{41,41}]
  wire  csr_nonempty_1 = ~csr_lsl_empty_1; // @[R_LSL.scala 309:68]
  wire  csr_nonempty_0 = ~csr_lsl_empty_0; // @[R_LSL.scala 309:68]
  wire [1:0] _csr_deq_bank_T_2 = {csr_nonempty_1,csr_nonempty_0}; // @[R_LSL.scala 311:69]
  wire  _csr_deq_bank_T_5 = _csr_deq_bank_T_2[0] ? 1'h0 : 1'h1; // @[Mux.scala 47:70]
  wire [1:0] csr_deq_bank = ~_GEN_23 ? csr_deq_ptr : {{1'd0}, _csr_deq_bank_T_5}; // @[R_LSL.scala 310:40]
  wire  csr_deq_valid_0 = csr_deq_bank == 2'h0 & io_req_valid_csr & ~u_channel_csr_0_io_empty; // @[R_LSL.scala 317:92]
  wire [63:0] _csr_out_packet_T = csr_deq_valid_0 ? csr_deq_data_0 : 64'h0; // @[Mux.scala 27:73]
  wire  csr_deq_valid_1 = csr_deq_bank == 2'h1 & io_req_valid_csr & ~u_channel_csr_1_io_empty; // @[R_LSL.scala 317:92]
  wire [63:0] _csr_out_packet_T_1 = csr_deq_valid_1 ? csr_deq_data_1 : 64'h0; // @[Mux.scala 27:73]
  wire [1:0] _csr_deq_ptr_T_1 = csr_deq_bank + 2'h1; // @[R_LSL.scala 326:37]
  wire [1:0] _csr_deq_ptr_T_6 = _csr_deq_ptr_T_1 - 2'h2; // @[R_LSL.scala 326:95]
  reg [1:0] rocc_enq_ptr; // @[R_LSL.scala 333:56]
  reg [1:0] rocc_deq_ptr; // @[R_LSL.scala 334:56]
  reg [63:0] rocc_enq_data_0; // @[R_LSL.scala 335:45]
  reg [63:0] rocc_enq_data_1; // @[R_LSL.scala 335:45]
  reg  rocc_enq_valid_0; // @[R_LSL.scala 336:45]
  reg  rocc_enq_valid_1; // @[R_LSL.scala 336:45]
  wire [1:0] rocc_numEnq = rocc_enq_valid_0 + rocc_enq_valid_1; // @[Bitwise.scala 51:90]
  wire [1:0] _rocc_enq_ptr_T_1 = rocc_enq_ptr + rocc_numEnq; // @[R_LSL.scala 346:38]
  wire [1:0] _rocc_enq_ptr_T_6 = _rocc_enq_ptr_T_1 - 2'h2; // @[R_LSL.scala 346:112]
  wire [2:0] _rocc_enq_offset_T = {{1'd0}, rocc_enq_ptr}; // @[R_LSL.scala 350:64]
  wire [1:0] _rocc_enq_offset_T_6 = _rocc_enq_offset_T[1:0] - 2'h2; // @[R_LSL.scala 350:118]
  wire [1:0] rocc_enq_offset_0 = _rocc_enq_offset_T[1:0] >= 2'h2 ? _rocc_enq_offset_T_6 : _rocc_enq_offset_T[1:0]; // @[R_LSL.scala 350:50]
  wire [1:0] _GEN_22 = {{1'd0}, rocc_enq_valid_0}; // @[R_LSL.scala 350:64]
  wire [1:0] _rocc_enq_offset_T_10 = rocc_enq_ptr + _GEN_22; // @[R_LSL.scala 350:64]
  wire [1:0] _rocc_enq_offset_T_15 = _rocc_enq_offset_T_10 - 2'h2; // @[R_LSL.scala 350:118]
  wire [1:0] rocc_enq_offset_1 = _rocc_enq_offset_T_10 >= 2'h2 ? _rocc_enq_offset_T_15 : _rocc_enq_offset_T_10; // @[R_LSL.scala 350:50]
  wire  rocc_enq_OH_0 = rocc_enq_offset_0 == 2'h0 & rocc_enq_valid_0; // @[R_LSL.scala 353:110]
  wire  rocc_enq_OH_1 = rocc_enq_offset_1 == 2'h0 & rocc_enq_valid_1; // @[R_LSL.scala 353:110]
  wire [63:0] _rocc_wdata_T = rocc_enq_OH_0 ? rocc_enq_data_0 : 64'h0; // @[Mux.scala 27:73]
  wire [63:0] _rocc_wdata_T_1 = rocc_enq_OH_1 ? rocc_enq_data_1 : 64'h0; // @[Mux.scala 27:73]
  wire  _rocc_enq_overflow_0_T = ~u_channel_rocc_0_io_enq_ready; // @[R_LSL.scala 358:39]
  wire  rocc_enq_overflow_0 = u_channel_rocc_0_io_enq_valid & _rocc_enq_overflow_0_T; // @[R_LSL.scala 357:70]
  wire  rocc_enq_OH_0_1 = rocc_enq_offset_0 == 2'h1 & rocc_enq_valid_0; // @[R_LSL.scala 353:110]
  wire  rocc_enq_OH_1_1 = rocc_enq_offset_1 == 2'h1 & rocc_enq_valid_1; // @[R_LSL.scala 353:110]
  wire [63:0] _rocc_wdata_T_3 = rocc_enq_OH_0_1 ? rocc_enq_data_0 : 64'h0; // @[Mux.scala 27:73]
  wire [63:0] _rocc_wdata_T_4 = rocc_enq_OH_1_1 ? rocc_enq_data_1 : 64'h0; // @[Mux.scala 27:73]
  wire  _rocc_enq_overflow_1_T = ~u_channel_rocc_1_io_enq_ready; // @[R_LSL.scala 358:39]
  wire  rocc_enq_overflow_1 = u_channel_rocc_1_io_enq_valid & _rocc_enq_overflow_1_T; // @[R_LSL.scala 357:70]
  reg [63:0] rocc_deq_data_0; // @[R_LSL.scala 364:45]
  reg [63:0] rocc_deq_data_1; // @[R_LSL.scala 364:45]
  wire  rocc_lsl_empty_1 = u_channel_rocc_1_io_empty; // @[R_LSL.scala 366:46 378:53]
  wire  rocc_lsl_empty_0 = u_channel_rocc_0_io_empty; // @[R_LSL.scala 366:46 378:53]
  wire  _GEN_27 = rocc_deq_ptr[0] ? rocc_lsl_empty_1 : rocc_lsl_empty_0; // @[R_LSL.scala 371:{42,42}]
  wire  rocc_nonempty_1 = ~rocc_lsl_empty_1; // @[R_LSL.scala 370:70]
  wire  rocc_nonempty_0 = ~rocc_lsl_empty_0; // @[R_LSL.scala 370:70]
  wire [1:0] _rocc_deq_bank_T_2 = {rocc_nonempty_1,rocc_nonempty_0}; // @[R_LSL.scala 372:71]
  wire  _rocc_deq_bank_T_5 = _rocc_deq_bank_T_2[0] ? 1'h0 : 1'h1; // @[Mux.scala 47:70]
  wire [1:0] rocc_deq_bank = ~_GEN_27 ? rocc_deq_ptr : {{1'd0}, _rocc_deq_bank_T_5}; // @[R_LSL.scala 371:41]
  wire  rocc_deq_valid_0 = rocc_deq_bank == 2'h0 & io_req_valid_rocc & ~u_channel_rocc_0_io_empty; // @[R_LSL.scala 375:95]
  wire [63:0] _rocc_out_packet_T = rocc_deq_valid_0 ? rocc_deq_data_0 : 64'h0; // @[Mux.scala 27:73]
  wire  rocc_deq_valid_1 = rocc_deq_bank == 2'h1 & io_req_valid_rocc & ~u_channel_rocc_1_io_empty; // @[R_LSL.scala 375:95]
  wire [63:0] _rocc_out_packet_T_1 = rocc_deq_valid_1 ? rocc_deq_data_1 : 64'h0; // @[Mux.scala 27:73]
  wire [1:0] _rocc_deq_ptr_T_1 = rocc_deq_bank + 2'h1; // @[R_LSL.scala 384:39]
  wire [1:0] _rocc_deq_ptr_T_6 = _rocc_deq_ptr_T_1 - 2'h2; // @[R_LSL.scala 384:98]
  wire  lsl_nearly_full_0 = u_channel_0_io_status_twoslots; // @[R_LSL.scala 129:41 206:48]
  wire  lsl_nearly_full_1 = u_channel_1_io_status_twoslots; // @[R_LSL.scala 129:41 206:48]
  wire  _io_cdc_ready_mem_T = lsl_nearly_full_0 | lsl_nearly_full_1; // @[R_LSL.scala 392:58]
  wire  csr_nearly_full_0 = u_channel_csr_0_io_status_twoslots; // @[R_LSL.scala 307:45 321:52]
  wire  csr_nearly_full_1 = u_channel_csr_1_io_status_twoslots; // @[R_LSL.scala 307:45 321:52]
  wire  _io_cdc_ready_csr_T = csr_nearly_full_0 | csr_nearly_full_1; // @[R_LSL.scala 393:58]
  wire  rocc_nearly_full_0 = u_channel_rocc_0_io_status_twoslots; // @[R_LSL.scala 368:46 379:53]
  wire  rocc_nearly_full_1 = u_channel_rocc_1_io_status_twoslots; // @[R_LSL.scala 368:46 379:53]
  wire  _io_cdc_ready_rocc_T = rocc_nearly_full_0 | rocc_nearly_full_1; // @[R_LSL.scala 394:59]
  wire  lsl_highwatermark_0 = u_channel_0_io_high_watermark; // @[R_LSL.scala 130:41 207:48]
  wire  lsl_highwatermark_1 = u_channel_1_io_high_watermark; // @[R_LSL.scala 130:41 207:48]
  wire  csr_highwatermark_0 = u_channel_csr_0_io_status_threeslots; // @[R_LSL.scala 308:45 322:52]
  wire  csr_highwatermark_1 = u_channel_csr_1_io_status_threeslots; // @[R_LSL.scala 308:45 322:52]
  wire  rocc_highwatermark_0 = u_channel_rocc_0_io_status_threeslots; // @[R_LSL.scala 369:46 380:53]
  wire  rocc_highwatermark_1 = u_channel_rocc_1_io_status_threeslots; // @[R_LSL.scala 369:46 380:53]
  wire  _io_ingress_overflow_T_1 = csr_enq_overflow_0 | csr_enq_overflow_1; // @[R_LSL.scala 402:58]
  wire  _io_ingress_overflow_T_2 = lsl_enq_overflow_0 | lsl_enq_overflow_1 | _io_ingress_overflow_T_1; // @[R_LSL.scala 401:62]
  wire  _io_ingress_overflow_T_3 = rocc_enq_overflow_0 | rocc_enq_overflow_1; // @[R_LSL.scala 403:59]
  wire [63:0] csr_out_packet = _csr_out_packet_T | _csr_out_packet_T_1; // @[Mux.scala 27:73]
  Performance__GH_MemFIFO_1 u_channel_0 ( // @[R_LSL.scala 71:83]
    .clock(u_channel_0_clock),
    .reset(u_channel_0_reset),
    .io_enq_valid(u_channel_0_io_enq_valid),
    .io_enq_ready(u_channel_0_io_enq_ready),
    .io_enq_bits(u_channel_0_io_enq_bits),
    .io_deq_ready(u_channel_0_io_deq_ready),
    .io_empty(u_channel_0_io_empty),
    .io_deq_bits(u_channel_0_io_deq_bits),
    .io_status_twoslots(u_channel_0_io_status_twoslots),
    .io_high_watermark(u_channel_0_io_high_watermark),
    .io_deq_read(u_channel_0_io_deq_read),
    .io_deq_read_valid(u_channel_0_io_deq_read_valid)
  );
  Performance__GH_MemFIFO_1 u_channel_1 ( // @[R_LSL.scala 71:83]
    .clock(u_channel_1_clock),
    .reset(u_channel_1_reset),
    .io_enq_valid(u_channel_1_io_enq_valid),
    .io_enq_ready(u_channel_1_io_enq_ready),
    .io_enq_bits(u_channel_1_io_enq_bits),
    .io_deq_ready(u_channel_1_io_deq_ready),
    .io_empty(u_channel_1_io_empty),
    .io_deq_bits(u_channel_1_io_deq_bits),
    .io_status_twoslots(u_channel_1_io_status_twoslots),
    .io_high_watermark(u_channel_1_io_high_watermark),
    .io_deq_read(u_channel_1_io_deq_read),
    .io_deq_read_valid(u_channel_1_io_deq_read_valid)
  );
  Performance__GH_FIFO_3 u_channel_csr_0 ( // @[R_LSL.scala 72:83]
    .clock(u_channel_csr_0_clock),
    .reset(u_channel_csr_0_reset),
    .io_enq_valid(u_channel_csr_0_io_enq_valid),
    .io_enq_ready(u_channel_csr_0_io_enq_ready),
    .io_enq_bits(u_channel_csr_0_io_enq_bits),
    .io_deq_ready(u_channel_csr_0_io_deq_ready),
    .io_empty(u_channel_csr_0_io_empty),
    .io_deq_bits(u_channel_csr_0_io_deq_bits),
    .io_status_threeslots(u_channel_csr_0_io_status_threeslots),
    .io_status_twoslots(u_channel_csr_0_io_status_twoslots)
  );
  Performance__GH_FIFO_3 u_channel_csr_1 ( // @[R_LSL.scala 72:83]
    .clock(u_channel_csr_1_clock),
    .reset(u_channel_csr_1_reset),
    .io_enq_valid(u_channel_csr_1_io_enq_valid),
    .io_enq_ready(u_channel_csr_1_io_enq_ready),
    .io_enq_bits(u_channel_csr_1_io_enq_bits),
    .io_deq_ready(u_channel_csr_1_io_deq_ready),
    .io_empty(u_channel_csr_1_io_empty),
    .io_deq_bits(u_channel_csr_1_io_deq_bits),
    .io_status_threeslots(u_channel_csr_1_io_status_threeslots),
    .io_status_twoslots(u_channel_csr_1_io_status_twoslots)
  );
  Performance__GH_FIFO_3 u_channel_rocc_0 ( // @[R_LSL.scala 73:83]
    .clock(u_channel_rocc_0_clock),
    .reset(u_channel_rocc_0_reset),
    .io_enq_valid(u_channel_rocc_0_io_enq_valid),
    .io_enq_ready(u_channel_rocc_0_io_enq_ready),
    .io_enq_bits(u_channel_rocc_0_io_enq_bits),
    .io_deq_ready(u_channel_rocc_0_io_deq_ready),
    .io_empty(u_channel_rocc_0_io_empty),
    .io_deq_bits(u_channel_rocc_0_io_deq_bits),
    .io_status_threeslots(u_channel_rocc_0_io_status_threeslots),
    .io_status_twoslots(u_channel_rocc_0_io_status_twoslots)
  );
  Performance__GH_FIFO_3 u_channel_rocc_1 ( // @[R_LSL.scala 73:83]
    .clock(u_channel_rocc_1_clock),
    .reset(u_channel_rocc_1_reset),
    .io_enq_valid(u_channel_rocc_1_io_enq_valid),
    .io_enq_ready(u_channel_rocc_1_io_enq_ready),
    .io_enq_bits(u_channel_rocc_1_io_enq_bits),
    .io_deq_ready(u_channel_rocc_1_io_deq_ready),
    .io_empty(u_channel_rocc_1_io_empty),
    .io_deq_bits(u_channel_rocc_1_io_deq_bits),
    .io_status_threeslots(u_channel_rocc_1_io_status_threeslots),
    .io_status_twoslots(u_channel_rocc_1_io_status_twoslots)
  );
  assign io_cdc_ready_mem = ~(lsl_nearly_full_0 | lsl_nearly_full_1); // @[R_LSL.scala 392:33]
  assign io_cdc_ready_csr = ~(csr_nearly_full_0 | csr_nearly_full_1); // @[R_LSL.scala 393:33]
  assign io_cdc_ready_rocc = ~(rocc_nearly_full_0 | rocc_nearly_full_1); // @[R_LSL.scala 394:33]
  assign io_req_ready = lsl_response_ready; // @[R_LSL.scala 240:30]
  assign io_req_ready_csr = csr_nonempty_0 | csr_nonempty_1; // @[R_LSL.scala 398:54]
  assign io_req_ready_rocc = rocc_nonempty_0 | rocc_nonempty_1; // @[R_LSL.scala 387:56]
  assign io_resp_valid = resp_valid_reg; // @[R_LSL.scala 241:30]
  assign io_resp_tag = resp_tag; // @[R_LSL.scala 242:30]
  assign io_resp_size = resp_valid_reg ? req_size_reg : 2'h0; // @[R_LSL.scala 244:36]
  assign io_resp_data = resp_valid_reg ? out_packet[127:64] : 64'h0; // @[R_LSL.scala 245:36]
  assign io_resp_has_data = resp_valid_reg & cmd[0]; // @[R_LSL.scala 251:54]
  assign io_resp_addr = resp_valid_reg ? out_packet[39:0] : 40'h0; // @[R_LSL.scala 248:36]
  assign io_resp_cacheable = resp_valid_reg & out_packet[63]; // @[R_LSL.scala 249:36]
  assign io_resp_mismatch = resp_mismatch_reg; // @[R_LSL.scala 250:30]
  assign io_resp_replay = req_valid_reg & ~resp_valid_reg & ~resp_kill_reg; // @[R_LSL.scala 252:66]
  assign io_quiescent = _io_quiescent_T_11 & ~io_req_valid_csr & _io_quiescent_T_14; // @[R_LSL.scala 261:68]
  assign io_near_full = _io_cdc_ready_mem_T | _io_cdc_ready_csr_T | _io_cdc_ready_rocc_T; // @[R_LSL.scala 397:88]
  assign io_resp_data_csr = _csr_out_packet_T | _csr_out_packet_T_1; // @[Mux.scala 27:73]
  assign io_resp_data_rocc = _rocc_out_packet_T | _rocc_out_packet_T_1; // @[Mux.scala 27:73]
  assign io_if_empty = csr_lsl_empty_0 & csr_lsl_empty_1 & (lsl_empty_0 & lsl_empty_1) & (rocc_lsl_empty_0 &
    rocc_lsl_empty_1); // @[R_LSL.scala 399:80]
  assign io_lsl_highwatermark = lsl_highwatermark_0 | lsl_highwatermark_1 | (csr_highwatermark_0 | csr_highwatermark_1)
     | (rocc_highwatermark_0 | rocc_highwatermark_1); // @[R_LSL.scala 400:92]
  assign io_ingress_overflow = _io_ingress_overflow_T_2 | _io_ingress_overflow_T_3; // @[R_LSL.scala 402:62]
  assign io_st_deq = _T_1 & io_req_cmd == 2'h2; // @[R_LSL.scala 265:36]
  assign io_ld_deq = _T_1 & io_req_cmd == 2'h1; // @[R_LSL.scala 264:36]
  assign u_channel_0_clock = clock;
  assign u_channel_0_reset = reset;
  assign u_channel_0_io_enq_valid = enq_OH_0 | enq_OH_1; // @[R_LSL.scala 102:67]
  assign u_channel_0_io_enq_bits = _wdata_T | _wdata_T_1; // @[Mux.scala 27:73]
  assign u_channel_0_io_deq_ready = deq_valid_0; // @[R_LSL.scala 201:48]
  assign u_channel_0_io_deq_read = lsl_prefetch_0; // @[R_LSL.scala 202:48]
  assign u_channel_1_clock = clock;
  assign u_channel_1_reset = reset;
  assign u_channel_1_io_enq_valid = enq_OH_0_1 | enq_OH_1_1; // @[R_LSL.scala 102:67]
  assign u_channel_1_io_enq_bits = _wdata_T_3 | _wdata_T_4; // @[Mux.scala 27:73]
  assign u_channel_1_io_deq_ready = deq_valid_1; // @[R_LSL.scala 201:48]
  assign u_channel_1_io_deq_read = lsl_prefetch_1; // @[R_LSL.scala 202:48]
  assign u_channel_csr_0_clock = clock;
  assign u_channel_csr_0_reset = reset;
  assign u_channel_csr_0_io_enq_valid = csr_enq_OH_0 | csr_enq_OH_1; // @[R_LSL.scala 294:57]
  assign u_channel_csr_0_io_enq_bits = _csr_wdata_T | _csr_wdata_T_1; // @[Mux.scala 27:73]
  assign u_channel_csr_0_io_deq_ready = csr_deq_valid_0; // @[R_LSL.scala 318:52]
  assign u_channel_csr_1_clock = clock;
  assign u_channel_csr_1_reset = reset;
  assign u_channel_csr_1_io_enq_valid = csr_enq_OH_0_1 | csr_enq_OH_1_1; // @[R_LSL.scala 294:57]
  assign u_channel_csr_1_io_enq_bits = _csr_wdata_T_3 | _csr_wdata_T_4; // @[Mux.scala 27:73]
  assign u_channel_csr_1_io_deq_ready = csr_deq_valid_1; // @[R_LSL.scala 318:52]
  assign u_channel_rocc_0_clock = clock;
  assign u_channel_rocc_0_reset = reset;
  assign u_channel_rocc_0_io_enq_valid = rocc_enq_OH_0 | rocc_enq_OH_1; // @[R_LSL.scala 355:59]
  assign u_channel_rocc_0_io_enq_bits = _rocc_wdata_T | _rocc_wdata_T_1; // @[Mux.scala 27:73]
  assign u_channel_rocc_0_io_deq_ready = rocc_deq_bank == 2'h0 & io_req_valid_rocc & ~u_channel_rocc_0_io_empty; // @[R_LSL.scala 375:95]
  assign u_channel_rocc_1_clock = clock;
  assign u_channel_rocc_1_reset = reset;
  assign u_channel_rocc_1_io_enq_valid = rocc_enq_OH_0_1 | rocc_enq_OH_1_1; // @[R_LSL.scala 355:59]
  assign u_channel_rocc_1_io_enq_bits = _rocc_wdata_T_3 | _rocc_wdata_T_4; // @[Mux.scala 27:73]
  assign u_channel_rocc_1_io_deq_ready = rocc_deq_bank == 2'h1 & io_req_valid_rocc & ~u_channel_rocc_1_io_empty; // @[R_LSL.scala 375:95]
  always @(posedge clock) begin
    if (reset) begin // @[R_LSL.scala 75:55]
      lsl_enq_ptr <= 2'h0; // @[R_LSL.scala 75:55]
    end else if (enq_valid_0 | enq_valid_1) begin // @[R_LSL.scala 92:30]
      if (_lsl_enq_ptr_T_1 >= 2'h2) begin // @[R_LSL.scala 93:23]
        lsl_enq_ptr <= _lsl_enq_ptr_T_6;
      end else begin
        lsl_enq_ptr <= _lsl_enq_ptr_T_1;
      end
    end
    if (reset) begin // @[R_LSL.scala 76:55]
      lsl_deq_ptr <= 2'h0; // @[R_LSL.scala 76:55]
    end else if (deq_valid_0 | deq_valid_1) begin // @[R_LSL.scala 210:30]
      if (_lsl_deq_ptr_T_1 >= 2'h2) begin // @[R_LSL.scala 211:23]
        lsl_deq_ptr <= _lsl_deq_ptr_T_6;
      end else begin
        lsl_deq_ptr <= _lsl_deq_ptr_T_1;
      end
    end
    if (reset) begin // @[R_LSL.scala 82:40]
      enq_data_0 <= 130'h0; // @[R_LSL.scala 82:40]
    end else begin
      enq_data_0 <= _enq_data_0_T; // @[R_LSL.scala 87:18]
    end
    if (reset) begin // @[R_LSL.scala 82:40]
      enq_data_1 <= 130'h0; // @[R_LSL.scala 82:40]
    end else begin
      enq_data_1 <= _enq_data_1_T; // @[R_LSL.scala 87:18]
    end
    if (reset) begin // @[R_LSL.scala 83:40]
      enq_valid_0 <= 1'h0; // @[R_LSL.scala 83:40]
    end else begin
      enq_valid_0 <= io_m_st_valid_0 | io_m_ld_valid_0; // @[R_LSL.scala 88:18]
    end
    if (reset) begin // @[R_LSL.scala 83:40]
      enq_valid_1 <= 1'h0; // @[R_LSL.scala 83:40]
    end else begin
      enq_valid_1 <= io_m_st_valid_1 | io_m_ld_valid_1; // @[R_LSL.scala 88:18]
    end
    if (reset) begin // @[R_LSL.scala 114:40]
      lsl_head_payload_0 <= 130'h0; // @[R_LSL.scala 114:40]
    end else if (!(deq_valid_0)) begin // @[R_LSL.scala 215:25]
      if (lsl_prefetch_pending_0 & lsl_prefetch_response_0) begin // @[R_LSL.scala 218:70]
        lsl_head_payload_0 <= deq_data_0; // @[R_LSL.scala 221:27]
      end
    end
    if (reset) begin // @[R_LSL.scala 114:40]
      lsl_head_payload_1 <= 130'h0; // @[R_LSL.scala 114:40]
    end else if (!(deq_valid_1)) begin // @[R_LSL.scala 215:25]
      if (lsl_prefetch_pending_1 & lsl_prefetch_response_1) begin // @[R_LSL.scala 218:70]
        lsl_head_payload_1 <= deq_data_1; // @[R_LSL.scala 221:27]
      end
    end
    if (reset) begin // @[R_LSL.scala 115:40]
      lsl_head_valid_0 <= 1'h0; // @[R_LSL.scala 115:40]
    end else if (deq_valid_0) begin // @[R_LSL.scala 215:25]
      lsl_head_valid_0 <= 1'h0; // @[R_LSL.scala 216:25]
    end else begin
      lsl_head_valid_0 <= _GEN_8;
    end
    if (reset) begin // @[R_LSL.scala 115:40]
      lsl_head_valid_1 <= 1'h0; // @[R_LSL.scala 115:40]
    end else if (deq_valid_1) begin // @[R_LSL.scala 215:25]
      lsl_head_valid_1 <= 1'h0; // @[R_LSL.scala 216:25]
    end else begin
      lsl_head_valid_1 <= _GEN_15;
    end
    if (reset) begin // @[R_LSL.scala 116:40]
      lsl_prefetch_pending_0 <= 1'h0; // @[R_LSL.scala 116:40]
    end else if (deq_valid_0) begin // @[R_LSL.scala 215:25]
      lsl_prefetch_pending_0 <= 1'h0; // @[R_LSL.scala 217:31]
    end else if (lsl_prefetch_pending_0 & lsl_prefetch_response_0) begin // @[R_LSL.scala 218:70]
      lsl_prefetch_pending_0 <= 1'h0; // @[R_LSL.scala 223:31]
    end else begin
      lsl_prefetch_pending_0 <= _GEN_6;
    end
    if (reset) begin // @[R_LSL.scala 116:40]
      lsl_prefetch_pending_1 <= 1'h0; // @[R_LSL.scala 116:40]
    end else if (deq_valid_1) begin // @[R_LSL.scala 215:25]
      lsl_prefetch_pending_1 <= 1'h0; // @[R_LSL.scala 217:31]
    end else if (lsl_prefetch_pending_1 & lsl_prefetch_response_1) begin // @[R_LSL.scala 218:70]
      lsl_prefetch_pending_1 <= 1'h0; // @[R_LSL.scala 223:31]
    end else begin
      lsl_prefetch_pending_1 <= _GEN_13;
    end
    if (reset) begin // @[R_LSL.scala 119:40]
      req_valid_reg <= 1'h0; // @[R_LSL.scala 119:40]
    end else begin
      req_valid_reg <= io_req_valid; // @[R_LSL.scala 230:30]
    end
    if (reset) begin // @[R_LSL.scala 120:40]
      resp_valid_reg <= 1'h0; // @[R_LSL.scala 120:40]
    end else begin
      resp_valid_reg <= lsl_response_fire; // @[R_LSL.scala 231:30]
    end
    if (reset) begin // @[R_LSL.scala 121:40]
      resp_kill_reg <= 1'h0; // @[R_LSL.scala 121:40]
    end else begin
      resp_kill_reg <= io_req_kill; // @[R_LSL.scala 229:30]
    end
    if (reset) begin // @[R_LSL.scala 122:40]
      resp_mismatch_reg <= 1'h0; // @[R_LSL.scala 122:40]
    end else begin
      resp_mismatch_reg <= lsl_response_fire & ~lsl_req_match; // @[R_LSL.scala 232:30]
    end
    if (reset) begin // @[R_LSL.scala 123:40]
      resp_tag <= 8'h0; // @[R_LSL.scala 123:40]
    end else begin
      resp_tag <= io_req_tag; // @[R_LSL.scala 236:30]
    end
    if (reset) begin // @[R_LSL.scala 124:40]
      cmd <= 2'h0; // @[R_LSL.scala 124:40]
    end else begin
      cmd <= io_req_cmd; // @[R_LSL.scala 237:30]
    end
    if (reset) begin // @[R_LSL.scala 125:40]
      req_size_reg <= 2'h0; // @[R_LSL.scala 125:40]
    end else begin
      req_size_reg <= io_req_size; // @[R_LSL.scala 238:30]
    end
    if (reset) begin // @[R_LSL.scala 127:40]
      resp_packet_reg <= 130'h0; // @[R_LSL.scala 127:40]
    end else if (lsl_response_fire) begin // @[R_LSL.scala 233:28]
      resp_packet_reg <= _selected_head_T_4; // @[R_LSL.scala 234:30]
    end
    if (reset) begin // @[R_LSL.scala 271:55]
      csr_enq_ptr <= 2'h0; // @[R_LSL.scala 271:55]
    end else if (csr_enq_valid_0 | csr_enq_valid_1) begin // @[R_LSL.scala 284:34]
      if (_csr_enq_ptr_T_1 >= 2'h2) begin // @[R_LSL.scala 285:23]
        csr_enq_ptr <= _csr_enq_ptr_T_6;
      end else begin
        csr_enq_ptr <= _csr_enq_ptr_T_1;
      end
    end
    if (reset) begin // @[R_LSL.scala 272:55]
      csr_deq_ptr <= 2'h0; // @[R_LSL.scala 272:55]
    end else if (csr_deq_valid_0 | csr_deq_valid_1) begin // @[R_LSL.scala 325:34]
      if (_csr_deq_ptr_T_1 >= 2'h2) begin // @[R_LSL.scala 326:23]
        csr_deq_ptr <= _csr_deq_ptr_T_6;
      end else begin
        csr_deq_ptr <= _csr_deq_ptr_T_1;
      end
    end
    if (reset) begin // @[R_LSL.scala 274:44]
      csr_enq_data_0 <= 64'h0; // @[R_LSL.scala 274:44]
    end else begin
      csr_enq_data_0 <= io_m_csr_data_0; // @[R_LSL.scala 279:22]
    end
    if (reset) begin // @[R_LSL.scala 274:44]
      csr_enq_data_1 <= 64'h0; // @[R_LSL.scala 274:44]
    end else begin
      csr_enq_data_1 <= io_m_csr_data_1; // @[R_LSL.scala 279:22]
    end
    if (reset) begin // @[R_LSL.scala 275:44]
      csr_enq_valid_0 <= 1'h0; // @[R_LSL.scala 275:44]
    end else begin
      csr_enq_valid_0 <= io_m_csr_valid_0; // @[R_LSL.scala 280:22]
    end
    if (reset) begin // @[R_LSL.scala 275:44]
      csr_enq_valid_1 <= 1'h0; // @[R_LSL.scala 275:44]
    end else begin
      csr_enq_valid_1 <= io_m_csr_valid_1; // @[R_LSL.scala 280:22]
    end
    if (reset) begin // @[R_LSL.scala 303:44]
      csr_deq_data_0 <= 64'h0; // @[R_LSL.scala 303:44]
    end else begin
      csr_deq_data_0 <= u_channel_csr_0_io_deq_bits; // @[R_LSL.scala 319:52]
    end
    if (reset) begin // @[R_LSL.scala 303:44]
      csr_deq_data_1 <= 64'h0; // @[R_LSL.scala 303:44]
    end else begin
      csr_deq_data_1 <= u_channel_csr_1_io_deq_bits; // @[R_LSL.scala 319:52]
    end
    if (reset) begin // @[R_LSL.scala 333:56]
      rocc_enq_ptr <= 2'h0; // @[R_LSL.scala 333:56]
    end else if (rocc_enq_valid_0 | rocc_enq_valid_1) begin // @[R_LSL.scala 345:35]
      if (_rocc_enq_ptr_T_1 >= 2'h2) begin // @[R_LSL.scala 346:24]
        rocc_enq_ptr <= _rocc_enq_ptr_T_6;
      end else begin
        rocc_enq_ptr <= _rocc_enq_ptr_T_1;
      end
    end
    if (reset) begin // @[R_LSL.scala 334:56]
      rocc_deq_ptr <= 2'h0; // @[R_LSL.scala 334:56]
    end else if (rocc_deq_valid_0 | rocc_deq_valid_1) begin // @[R_LSL.scala 383:35]
      if (_rocc_deq_ptr_T_1 >= 2'h2) begin // @[R_LSL.scala 384:24]
        rocc_deq_ptr <= _rocc_deq_ptr_T_6;
      end else begin
        rocc_deq_ptr <= _rocc_deq_ptr_T_1;
      end
    end
    if (reset) begin // @[R_LSL.scala 335:45]
      rocc_enq_data_0 <= 64'h0; // @[R_LSL.scala 335:45]
    end else begin
      rocc_enq_data_0 <= io_m_rocc_data_0; // @[R_LSL.scala 340:23]
    end
    if (reset) begin // @[R_LSL.scala 335:45]
      rocc_enq_data_1 <= 64'h0; // @[R_LSL.scala 335:45]
    end else begin
      rocc_enq_data_1 <= io_m_rocc_data_1; // @[R_LSL.scala 340:23]
    end
    if (reset) begin // @[R_LSL.scala 336:45]
      rocc_enq_valid_0 <= 1'h0; // @[R_LSL.scala 336:45]
    end else begin
      rocc_enq_valid_0 <= io_m_rocc_valid_0; // @[R_LSL.scala 341:23]
    end
    if (reset) begin // @[R_LSL.scala 336:45]
      rocc_enq_valid_1 <= 1'h0; // @[R_LSL.scala 336:45]
    end else begin
      rocc_enq_valid_1 <= io_m_rocc_valid_1; // @[R_LSL.scala 341:23]
    end
    if (reset) begin // @[R_LSL.scala 364:45]
      rocc_deq_data_0 <= 64'h0; // @[R_LSL.scala 364:45]
    end else begin
      rocc_deq_data_0 <= u_channel_rocc_0_io_deq_bits; // @[R_LSL.scala 377:53]
    end
    if (reset) begin // @[R_LSL.scala 364:45]
      rocc_deq_data_1 <= 64'h0; // @[R_LSL.scala 364:45]
    end else begin
      rocc_deq_data_1 <= u_channel_rocc_1_io_deq_bits; // @[R_LSL.scala 377:53]
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
  lsl_enq_ptr = _RAND_0[1:0];
  _RAND_1 = {1{`RANDOM}};
  lsl_deq_ptr = _RAND_1[1:0];
  _RAND_2 = {5{`RANDOM}};
  enq_data_0 = _RAND_2[129:0];
  _RAND_3 = {5{`RANDOM}};
  enq_data_1 = _RAND_3[129:0];
  _RAND_4 = {1{`RANDOM}};
  enq_valid_0 = _RAND_4[0:0];
  _RAND_5 = {1{`RANDOM}};
  enq_valid_1 = _RAND_5[0:0];
  _RAND_6 = {5{`RANDOM}};
  lsl_head_payload_0 = _RAND_6[129:0];
  _RAND_7 = {5{`RANDOM}};
  lsl_head_payload_1 = _RAND_7[129:0];
  _RAND_8 = {1{`RANDOM}};
  lsl_head_valid_0 = _RAND_8[0:0];
  _RAND_9 = {1{`RANDOM}};
  lsl_head_valid_1 = _RAND_9[0:0];
  _RAND_10 = {1{`RANDOM}};
  lsl_prefetch_pending_0 = _RAND_10[0:0];
  _RAND_11 = {1{`RANDOM}};
  lsl_prefetch_pending_1 = _RAND_11[0:0];
  _RAND_12 = {1{`RANDOM}};
  req_valid_reg = _RAND_12[0:0];
  _RAND_13 = {1{`RANDOM}};
  resp_valid_reg = _RAND_13[0:0];
  _RAND_14 = {1{`RANDOM}};
  resp_kill_reg = _RAND_14[0:0];
  _RAND_15 = {1{`RANDOM}};
  resp_mismatch_reg = _RAND_15[0:0];
  _RAND_16 = {1{`RANDOM}};
  resp_tag = _RAND_16[7:0];
  _RAND_17 = {1{`RANDOM}};
  cmd = _RAND_17[1:0];
  _RAND_18 = {1{`RANDOM}};
  req_size_reg = _RAND_18[1:0];
  _RAND_19 = {5{`RANDOM}};
  resp_packet_reg = _RAND_19[129:0];
  _RAND_20 = {1{`RANDOM}};
  csr_enq_ptr = _RAND_20[1:0];
  _RAND_21 = {1{`RANDOM}};
  csr_deq_ptr = _RAND_21[1:0];
  _RAND_22 = {2{`RANDOM}};
  csr_enq_data_0 = _RAND_22[63:0];
  _RAND_23 = {2{`RANDOM}};
  csr_enq_data_1 = _RAND_23[63:0];
  _RAND_24 = {1{`RANDOM}};
  csr_enq_valid_0 = _RAND_24[0:0];
  _RAND_25 = {1{`RANDOM}};
  csr_enq_valid_1 = _RAND_25[0:0];
  _RAND_26 = {2{`RANDOM}};
  csr_deq_data_0 = _RAND_26[63:0];
  _RAND_27 = {2{`RANDOM}};
  csr_deq_data_1 = _RAND_27[63:0];
  _RAND_28 = {1{`RANDOM}};
  rocc_enq_ptr = _RAND_28[1:0];
  _RAND_29 = {1{`RANDOM}};
  rocc_deq_ptr = _RAND_29[1:0];
  _RAND_30 = {2{`RANDOM}};
  rocc_enq_data_0 = _RAND_30[63:0];
  _RAND_31 = {2{`RANDOM}};
  rocc_enq_data_1 = _RAND_31[63:0];
  _RAND_32 = {1{`RANDOM}};
  rocc_enq_valid_0 = _RAND_32[0:0];
  _RAND_33 = {1{`RANDOM}};
  rocc_enq_valid_1 = _RAND_33[0:0];
  _RAND_34 = {2{`RANDOM}};
  rocc_deq_data_0 = _RAND_34[63:0];
  _RAND_35 = {2{`RANDOM}};
  rocc_deq_data_1 = _RAND_35[63:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
