module AsyncMemChiselRTL(
  input         clock,
  input         reset,
  input         channels_read_cmds_0_en,
  input  [8:0]  channels_read_cmds_0_addr,
  input         channels_read_cmds_1_en,
  input  [8:0]  channels_read_cmds_1_addr,
  input         channels_read_cmds_2_en,
  input  [8:0]  channels_read_cmds_2_addr,
  input         channels_read_cmds_3_en,
  input  [8:0]  channels_read_cmds_3_addr,
  output [63:0] channels_read_resps_0,
  output [63:0] channels_read_resps_1,
  output [63:0] channels_read_resps_2,
  output [63:0] channels_read_resps_3,
  input         channels_write_cmds_0_en,
  input         channels_write_cmds_0_mask,
  input  [8:0]  channels_write_cmds_0_addr,
  input  [63:0] channels_write_cmds_0_data,
  input         channels_write_cmds_1_en,
  input         channels_write_cmds_1_mask,
  input  [8:0]  channels_write_cmds_1_addr,
  input  [63:0] channels_write_cmds_1_data
);
`ifdef RANDOMIZE_MEM_INIT
  reg [63:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
  reg [63:0] data [0:511]; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_0_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_0_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [63:0] data_channels_read_resps_0_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_1_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_1_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [63:0] data_channels_read_resps_1_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_2_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_2_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [63:0] data_channels_read_resps_2_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_3_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_3_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [63:0] data_channels_read_resps_3_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire [63:0] data_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire  data_MPORT_mask; // @[AsyncMemModel.scala 16:17]
  wire  data_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [63:0] data_MPORT_1_data; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_MPORT_1_addr; // @[AsyncMemModel.scala 16:17]
  wire  data_MPORT_1_mask; // @[AsyncMemModel.scala 16:17]
  wire  data_MPORT_1_en; // @[AsyncMemModel.scala 16:17]
  wire  _collision_detected_T = channels_write_cmds_1_en & channels_write_cmds_1_mask; // @[RegfileModel.scala 25:19]
  wire  _collision_detected_T_1 = channels_write_cmds_0_en & channels_write_cmds_0_mask; // @[RegfileModel.scala 25:19]
  wire  collision_detected = _collision_detected_T & _collision_detected_T_1 & channels_write_cmds_1_addr ==
    channels_write_cmds_0_addr; // @[AsyncMemModel.scala 24:62]
  wire  _T_2 = ~reset; // @[AsyncMemModel.scala 29:31]
  wire  _T_3 = _collision_detected_T_1 & ~reset; // @[AsyncMemModel.scala 29:28]
  wire  _T_4 = ~collision_detected; // @[AsyncMemModel.scala 29:48]
  assign data_channels_read_resps_0_MPORT_en = 1'h1;
  assign data_channels_read_resps_0_MPORT_addr = channels_read_cmds_0_addr;
  assign data_channels_read_resps_0_MPORT_data = data[data_channels_read_resps_0_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_1_MPORT_en = 1'h1;
  assign data_channels_read_resps_1_MPORT_addr = channels_read_cmds_1_addr;
  assign data_channels_read_resps_1_MPORT_data = data[data_channels_read_resps_1_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_2_MPORT_en = 1'h1;
  assign data_channels_read_resps_2_MPORT_addr = channels_read_cmds_2_addr;
  assign data_channels_read_resps_2_MPORT_data = data[data_channels_read_resps_2_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_3_MPORT_en = 1'h1;
  assign data_channels_read_resps_3_MPORT_addr = channels_read_cmds_3_addr;
  assign data_channels_read_resps_3_MPORT_data = data[data_channels_read_resps_3_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_MPORT_data = channels_write_cmds_0_data;
  assign data_MPORT_addr = channels_write_cmds_0_addr;
  assign data_MPORT_mask = 1'h1;
  assign data_MPORT_en = _T_3 & _T_4;
  assign data_MPORT_1_data = channels_write_cmds_1_data;
  assign data_MPORT_1_addr = channels_write_cmds_1_addr;
  assign data_MPORT_1_mask = 1'h1;
  assign data_MPORT_1_en = _collision_detected_T & _T_2;
  assign channels_read_resps_0 = data_channels_read_resps_0_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_1 = data_channels_read_resps_1_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_2 = data_channels_read_resps_2_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_3 = data_channels_read_resps_3_MPORT_data; // @[AsyncMemModel.scala 19:28]
  always @(posedge clock) begin
    if (data_MPORT_en & data_MPORT_mask) begin
      data[data_MPORT_addr] <= data_MPORT_data; // @[AsyncMemModel.scala 16:17]
    end
    if (data_MPORT_1_en & data_MPORT_1_mask) begin
      data[data_MPORT_1_addr] <= data_MPORT_1_data; // @[AsyncMemModel.scala 16:17]
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
    data[initvar] = _RAND_0[63:0];
`endif // RANDOMIZE_MEM_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
