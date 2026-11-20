module AsyncMemChiselModel(
  input         clock,
  input         reset,
  output        channels_reset_ready,
  input         channels_reset_valid,
  input         channels_reset_bits,
  output        channels_read_cmds_0_ready,
  input         channels_read_cmds_0_valid,
  input  [8:0]  channels_read_cmds_0_bits_addr,
  output        channels_read_cmds_1_ready,
  input         channels_read_cmds_1_valid,
  input  [8:0]  channels_read_cmds_1_bits_addr,
  output        channels_read_cmds_2_ready,
  input         channels_read_cmds_2_valid,
  input  [8:0]  channels_read_cmds_2_bits_addr,
  output        channels_read_cmds_3_ready,
  input         channels_read_cmds_3_valid,
  input  [8:0]  channels_read_cmds_3_bits_addr,
  input         channels_read_resps_0_ready,
  output        channels_read_resps_0_valid,
  output [63:0] channels_read_resps_0_bits,
  input         channels_read_resps_1_ready,
  output        channels_read_resps_1_valid,
  output [63:0] channels_read_resps_1_bits,
  input         channels_read_resps_2_ready,
  output        channels_read_resps_2_valid,
  output [63:0] channels_read_resps_2_bits,
  input         channels_read_resps_3_ready,
  output        channels_read_resps_3_valid,
  output [63:0] channels_read_resps_3_bits,
  output        channels_write_cmds_0_ready,
  input         channels_write_cmds_0_valid,
  input         channels_write_cmds_0_bits_en,
  input         channels_write_cmds_0_bits_mask,
  input  [8:0]  channels_write_cmds_0_bits_addr,
  input  [63:0] channels_write_cmds_0_bits_data,
  output        channels_write_cmds_1_ready,
  input         channels_write_cmds_1_valid,
  input         channels_write_cmds_1_bits_en,
  input         channels_write_cmds_1_bits_mask,
  input  [8:0]  channels_write_cmds_1_bits_addr,
  input  [63:0] channels_write_cmds_1_bits_data
);
`ifdef RANDOMIZE_MEM_INIT
  reg [63:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [63:0] _RAND_7;
  reg [63:0] _RAND_8;
  reg [63:0] _RAND_9;
  reg [63:0] _RAND_10;
  reg [63:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
`endif // RANDOMIZE_REG_INIT
  reg [63:0] data [0:511]; // @[AsyncMemModel.scala 62:17]
  wire  data_read_data_async_en; // @[AsyncMemModel.scala 62:17]
  wire [8:0] data_read_data_async_addr; // @[AsyncMemModel.scala 62:17]
  wire [63:0] data_read_data_async_data; // @[AsyncMemModel.scala 62:17]
  wire [63:0] data_MPORT_data; // @[AsyncMemModel.scala 62:17]
  wire [8:0] data_MPORT_addr; // @[AsyncMemModel.scala 62:17]
  wire  data_MPORT_mask; // @[AsyncMemModel.scala 62:17]
  wire  data_MPORT_en; // @[AsyncMemModel.scala 62:17]
  reg  target_reset_fired; // @[AsyncMemModel.scala 56:31]
  wire  target_reset_available = target_reset_fired | channels_reset_valid; // @[AsyncMemModel.scala 57:51]
  reg  target_reset_reg; // @[AsyncMemModel.scala 58:29]
  wire  target_reset_value = target_reset_fired ? target_reset_reg : channels_reset_bits; // @[AsyncMemModel.scala 59:31]
  reg [1:0] read_state_3; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_3 = read_state_3 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_3 = read_state_3 == 2'h0 & channels_read_cmds_3_valid; // @[AsyncMemModel.scala 77:96]
  reg [1:0] read_state_0; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T = read_state_0 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_0 = read_state_0 == 2'h0 & channels_read_cmds_0_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_1 = ~read_access_req_0; // @[AsyncMemModel.scala 80:96]
  reg [1:0] read_state_1; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_1 = read_state_1 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_1 = read_state_1 == 2'h0 & channels_read_cmds_1_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_2 = read_access_available_1 & ~read_access_req_1; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_2; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_2 = read_state_2 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_2 = read_state_2 == 2'h0 & channels_read_cmds_2_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_3 = read_access_available_2 & ~read_access_req_2; // @[AsyncMemModel.scala 80:93]
  wire  read_access_granted_3 = read_access_req_3 & read_access_available_3; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_2 = read_access_req_2 & read_access_available_2; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_1 = read_access_req_1 & read_access_available_1; // @[AsyncMemModel.scala 49:50]
  wire [8:0] _GEN_17 = read_access_granted_1 ? channels_read_cmds_1_bits_addr : channels_read_cmds_0_bits_addr; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_25 = read_access_granted_2 ? channels_read_cmds_2_bits_addr : _GEN_17; // @[AsyncMemModel.scala 121:{35,54}]
  reg [63:0] read_data; // @[AsyncMemModel.scala 68:26]
  wire  _T_49 = channels_write_cmds_1_ready & channels_write_cmds_1_valid; // @[Decoupled.scala 51:35]
  wire  _active_write_en_T_1 = channels_write_cmds_1_bits_en & channels_write_cmds_1_bits_mask; // @[RegfileModel.scala 25:19]
  wire  _T_45 = channels_write_cmds_0_ready & channels_write_cmds_0_valid; // @[Decoupled.scala 51:35]
  wire  _active_write_en_T = channels_write_cmds_0_bits_en & channels_write_cmds_0_bits_mask; // @[RegfileModel.scala 25:19]
  wire  _GEN_45 = _T_45 & _active_write_en_T; // @[AsyncMemModel.scala 142:19 150:40 153:23]
  wire  active_write_en = _T_49 ? _active_write_en_T_1 : _GEN_45; // @[AsyncMemModel.scala 150:40 153:23]
  wire  _T_1 = active_write_en & ~target_reset_value; // @[AsyncMemModel.scala 69:25]
  wire  _T_3 = ~reset; // @[AsyncMemModel.scala 69:51]
  reg [63:0] read_resp_data_0; // @[AsyncMemModel.scala 76:27]
  reg [63:0] read_resp_data_1; // @[AsyncMemModel.scala 76:27]
  reg [63:0] read_resp_data_2; // @[AsyncMemModel.scala 76:27]
  reg [63:0] read_resp_data_3; // @[AsyncMemModel.scala 76:27]
  wire  reads_done = read_state_0 != 2'h0 & read_state_1 != 2'h0 & read_state_2 != 2'h0 & read_state_3 != 2'h0; // @[AsyncMemModel.scala 84:87]
  wire  _outputs_responded_or_firing_T_1 = channels_read_resps_0_ready & channels_read_resps_0_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_5 = channels_read_resps_1_ready & channels_read_resps_1_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_9 = channels_read_resps_2_ready & channels_read_resps_2_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_13 = channels_read_resps_3_ready & channels_read_resps_3_valid; // @[Decoupled.scala 51:35]
  wire  outputs_responded_or_firing = (read_state_0 == 2'h3 | _outputs_responded_or_firing_T_1) & (read_state_1 == 2'h3
     | _outputs_responded_or_firing_T_5) & (read_state_2 == 2'h3 | _outputs_responded_or_firing_T_9) & (read_state_3 == 2'h3
     | _outputs_responded_or_firing_T_13); // @[AsyncMemModel.scala 93:34]
  reg  write_complete_0; // @[AsyncMemModel.scala 97:27]
  reg  write_complete_1; // @[AsyncMemModel.scala 97:27]
  wire  write_prereqs_met_0 = reads_done & target_reset_available; // @[AsyncMemModel.scala 100:91]
  wire  write_prereqs_met_1 = write_complete_0 & reads_done & target_reset_available; // @[AsyncMemModel.scala 100:91]
  wire  writes_done_or_finishing = (write_complete_0 | _T_45) & (write_complete_1 | _T_49); // @[AsyncMemModel.scala 104:40]
  wire  advance_cycle = outputs_responded_or_firing & writes_done_or_finishing; // @[AsyncMemModel.scala 107:51]
  wire  _T_8 = advance_cycle | reset; // @[AsyncMemModel.scala 111:23]
  wire  _T_9 = channels_reset_ready & channels_reset_valid; // @[Decoupled.scala 51:35]
  wire  _GEN_5 = _T_9 | target_reset_fired; // @[AsyncMemModel.scala 113:37 114:24 56:31]
  wire  _channels_read_resps_0_bits_T = read_state_0 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_0_valid_T_1 = read_state_0 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_1_bits_T = read_state_1 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_1_valid_T_1 = read_state_1 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_2_bits_T = read_state_2 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_2_valid_T_1 = read_state_2 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_3_bits_T = read_state_3 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_3_valid_T_1 = read_state_3 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _GEN_41 = _T_45 | write_complete_0; // @[AsyncMemModel.scala 147:47 148:25 97:27]
  wire  _GEN_46 = _T_49 | write_complete_1; // @[AsyncMemModel.scala 147:47 148:25 97:27]
  assign data_read_data_async_en = 1'h1;
  assign data_read_data_async_addr = read_access_granted_3 ? channels_read_cmds_3_bits_addr : _GEN_25;
  assign data_read_data_async_data = data[data_read_data_async_addr]; // @[AsyncMemModel.scala 62:17]
  assign data_MPORT_data = _T_49 ? channels_write_cmds_1_bits_data : channels_write_cmds_0_bits_data;
  assign data_MPORT_addr = _T_49 ? channels_write_cmds_1_bits_addr : channels_write_cmds_0_bits_addr;
  assign data_MPORT_mask = 1'h1;
  assign data_MPORT_en = _T_1 & _T_3;
  assign channels_reset_ready = ~target_reset_fired; // @[AsyncMemModel.scala 110:27]
  assign channels_read_cmds_0_ready = read_state_0 == 2'h0; // @[AsyncMemModel.scala 123:50]
  assign channels_read_cmds_1_ready = _read_access_req_T_1 & read_access_available_1; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_2_ready = _read_access_req_T_2 & read_access_available_2; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_3_ready = _read_access_req_T_3 & read_access_available_3; // @[AsyncMemModel.scala 123:60]
  assign channels_read_resps_0_valid = _channels_read_resps_0_bits_T | read_state_0 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_0_bits = read_state_0 == 2'h1 ? read_data : read_resp_data_0; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_1_valid = _channels_read_resps_1_bits_T | read_state_1 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_1_bits = read_state_1 == 2'h1 ? read_data : read_resp_data_1; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_2_valid = _channels_read_resps_2_bits_T | read_state_2 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_2_bits = read_state_2 == 2'h1 ? read_data : read_resp_data_2; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_3_valid = _channels_read_resps_3_bits_T | read_state_3 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_3_bits = read_state_3 == 2'h1 ? read_data : read_resp_data_3; // @[AsyncMemModel.scala 124:39]
  assign channels_write_cmds_0_ready = write_prereqs_met_0 & ~write_complete_0; // @[AsyncMemModel.scala 144:58]
  assign channels_write_cmds_1_ready = write_prereqs_met_1 & ~write_complete_1; // @[AsyncMemModel.scala 144:58]
  always @(posedge clock) begin
    if (data_MPORT_en & data_MPORT_mask) begin
      data[data_MPORT_addr] <= data_MPORT_data; // @[AsyncMemModel.scala 62:17]
    end
    if (advance_cycle | reset) begin // @[AsyncMemModel.scala 111:40]
      target_reset_fired <= 1'h0; // @[AsyncMemModel.scala 112:24]
    end else begin
      target_reset_fired <= _GEN_5;
    end
    if (!(advance_cycle | reset)) begin // @[AsyncMemModel.scala 111:40]
      if (_T_9) begin // @[AsyncMemModel.scala 113:37]
        target_reset_reg <= channels_reset_bits; // @[AsyncMemModel.scala 115:22]
      end
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_3 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_3 & read_access_granted_3) begin // @[AsyncMemModel.scala 129:69]
      read_state_3 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_3_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_13) begin // @[AsyncMemModel.scala 132:27]
        read_state_3 <= 2'h3;
      end else begin
        read_state_3 <= 2'h2;
      end
    end else if (_channels_read_resps_3_valid_T_1 & _outputs_responded_or_firing_T_13) begin // @[AsyncMemModel.scala 134:78]
      read_state_3 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_0 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T & read_access_req_0) begin // @[AsyncMemModel.scala 129:69]
      read_state_0 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_0_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_1) begin // @[AsyncMemModel.scala 132:27]
        read_state_0 <= 2'h3;
      end else begin
        read_state_0 <= 2'h2;
      end
    end else if (_channels_read_resps_0_valid_T_1 & _outputs_responded_or_firing_T_1) begin // @[AsyncMemModel.scala 134:78]
      read_state_0 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_1 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_1 & read_access_granted_1) begin // @[AsyncMemModel.scala 129:69]
      read_state_1 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_1_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_5) begin // @[AsyncMemModel.scala 132:27]
        read_state_1 <= 2'h3;
      end else begin
        read_state_1 <= 2'h2;
      end
    end else if (_channels_read_resps_1_valid_T_1 & _outputs_responded_or_firing_T_5) begin // @[AsyncMemModel.scala 134:78]
      read_state_1 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_2 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_2 & read_access_granted_2) begin // @[AsyncMemModel.scala 129:69]
      read_state_2 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_2_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_9) begin // @[AsyncMemModel.scala 132:27]
        read_state_2 <= 2'h3;
      end else begin
        read_state_2 <= 2'h2;
      end
    end else if (_channels_read_resps_2_valid_T_1 & _outputs_responded_or_firing_T_9) begin // @[AsyncMemModel.scala 134:78]
      read_state_2 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    read_data <= data_read_data_async_data; // @[AsyncMemModel.scala 68:26]
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T & read_access_req_0)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_0 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_0 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_1 & read_access_granted_1)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_1 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_1 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_2 & read_access_granted_2)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_2 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_2 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_3 & read_access_granted_3)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_3 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_3 <= read_data;
        end
      end
    end
    if (_T_8) begin // @[AsyncMemModel.scala 145:42]
      write_complete_0 <= 1'h0; // @[AsyncMemModel.scala 146:25]
    end else begin
      write_complete_0 <= _GEN_41;
    end
    if (_T_8) begin // @[AsyncMemModel.scala 145:42]
      write_complete_1 <= 1'h0; // @[AsyncMemModel.scala 146:25]
    end else begin
      write_complete_1 <= _GEN_46;
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
`ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{`RANDOM}};
  target_reset_fired = _RAND_1[0:0];
  _RAND_2 = {1{`RANDOM}};
  target_reset_reg = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  read_state_3 = _RAND_3[1:0];
  _RAND_4 = {1{`RANDOM}};
  read_state_0 = _RAND_4[1:0];
  _RAND_5 = {1{`RANDOM}};
  read_state_1 = _RAND_5[1:0];
  _RAND_6 = {1{`RANDOM}};
  read_state_2 = _RAND_6[1:0];
  _RAND_7 = {2{`RANDOM}};
  read_data = _RAND_7[63:0];
  _RAND_8 = {2{`RANDOM}};
  read_resp_data_0 = _RAND_8[63:0];
  _RAND_9 = {2{`RANDOM}};
  read_resp_data_1 = _RAND_9[63:0];
  _RAND_10 = {2{`RANDOM}};
  read_resp_data_2 = _RAND_10[63:0];
  _RAND_11 = {2{`RANDOM}};
  read_resp_data_3 = _RAND_11[63:0];
  _RAND_12 = {1{`RANDOM}};
  write_complete_0 = _RAND_12[0:0];
  _RAND_13 = {1{`RANDOM}};
  write_complete_1 = _RAND_13[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module AsyncMemChiselRTL(
  input         clock,
  input         reset,
  input  [8:0]  channels_read_cmds_0_addr,
  input  [8:0]  channels_read_cmds_1_addr,
  input  [8:0]  channels_read_cmds_2_addr,
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
module SpaceTimePair(
  input         clock,
  input         reset,
  input         io_targetClock,
  input         io_targetReset,
  output        io_model_reset_ready,
  input         io_model_reset_valid,
  input         io_model_reset_bits,
  output        io_model_read_cmds_0_ready,
  input         io_model_read_cmds_0_valid,
  input         io_model_read_cmds_0_bits_en,
  input  [8:0]  io_model_read_cmds_0_bits_addr,
  output        io_model_read_cmds_1_ready,
  input         io_model_read_cmds_1_valid,
  input         io_model_read_cmds_1_bits_en,
  input  [8:0]  io_model_read_cmds_1_bits_addr,
  output        io_model_read_cmds_2_ready,
  input         io_model_read_cmds_2_valid,
  input         io_model_read_cmds_2_bits_en,
  input  [8:0]  io_model_read_cmds_2_bits_addr,
  output        io_model_read_cmds_3_ready,
  input         io_model_read_cmds_3_valid,
  input         io_model_read_cmds_3_bits_en,
  input  [8:0]  io_model_read_cmds_3_bits_addr,
  input         io_model_read_resps_0_ready,
  output        io_model_read_resps_0_valid,
  output [63:0] io_model_read_resps_0_bits,
  input         io_model_read_resps_1_ready,
  output        io_model_read_resps_1_valid,
  output [63:0] io_model_read_resps_1_bits,
  input         io_model_read_resps_2_ready,
  output        io_model_read_resps_2_valid,
  output [63:0] io_model_read_resps_2_bits,
  input         io_model_read_resps_3_ready,
  output        io_model_read_resps_3_valid,
  output [63:0] io_model_read_resps_3_bits,
  output        io_model_write_cmds_0_ready,
  input         io_model_write_cmds_0_valid,
  input         io_model_write_cmds_0_bits_en,
  input         io_model_write_cmds_0_bits_mask,
  input  [8:0]  io_model_write_cmds_0_bits_addr,
  input  [63:0] io_model_write_cmds_0_bits_data,
  output        io_model_write_cmds_1_ready,
  input         io_model_write_cmds_1_valid,
  input         io_model_write_cmds_1_bits_en,
  input         io_model_write_cmds_1_bits_mask,
  input  [8:0]  io_model_write_cmds_1_bits_addr,
  input  [63:0] io_model_write_cmds_1_bits_data,
  input         io_reference_read_cmds_0_en,
  input  [8:0]  io_reference_read_cmds_0_addr,
  input         io_reference_read_cmds_1_en,
  input  [8:0]  io_reference_read_cmds_1_addr,
  input         io_reference_read_cmds_2_en,
  input  [8:0]  io_reference_read_cmds_2_addr,
  input         io_reference_read_cmds_3_en,
  input  [8:0]  io_reference_read_cmds_3_addr,
  output [63:0] io_reference_read_resps_0,
  output [63:0] io_reference_read_resps_1,
  output [63:0] io_reference_read_resps_2,
  output [63:0] io_reference_read_resps_3,
  input         io_reference_write_cmds_0_en,
  input         io_reference_write_cmds_0_mask,
  input  [8:0]  io_reference_write_cmds_0_addr,
  input  [63:0] io_reference_write_cmds_0_data,
  input         io_reference_write_cmds_1_en,
  input         io_reference_write_cmds_1_mask,
  input  [8:0]  io_reference_write_cmds_1_addr,
  input  [63:0] io_reference_write_cmds_1_data
);
  wire  host_clock; // @[Prototype.scala 17:20]
  wire  host_reset; // @[Prototype.scala 17:20]
  wire  host_channels_reset_ready; // @[Prototype.scala 17:20]
  wire  host_channels_reset_valid; // @[Prototype.scala 17:20]
  wire  host_channels_reset_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_0_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_0_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_0_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_1_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_1_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_1_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_2_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_2_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_2_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_3_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_3_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_3_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_0_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_0_valid; // @[Prototype.scala 17:20]
  wire [63:0] host_channels_read_resps_0_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_1_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_1_valid; // @[Prototype.scala 17:20]
  wire [63:0] host_channels_read_resps_1_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_2_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_2_valid; // @[Prototype.scala 17:20]
  wire [63:0] host_channels_read_resps_2_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_3_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_3_valid; // @[Prototype.scala 17:20]
  wire [63:0] host_channels_read_resps_3_bits; // @[Prototype.scala 17:20]
  wire  host_channels_write_cmds_0_ready; // @[Prototype.scala 17:20]
  wire  host_channels_write_cmds_0_valid; // @[Prototype.scala 17:20]
  wire  host_channels_write_cmds_0_bits_en; // @[Prototype.scala 17:20]
  wire  host_channels_write_cmds_0_bits_mask; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_write_cmds_0_bits_addr; // @[Prototype.scala 17:20]
  wire [63:0] host_channels_write_cmds_0_bits_data; // @[Prototype.scala 17:20]
  wire  host_channels_write_cmds_1_ready; // @[Prototype.scala 17:20]
  wire  host_channels_write_cmds_1_valid; // @[Prototype.scala 17:20]
  wire  host_channels_write_cmds_1_bits_en; // @[Prototype.scala 17:20]
  wire  host_channels_write_cmds_1_bits_mask; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_write_cmds_1_bits_addr; // @[Prototype.scala 17:20]
  wire [63:0] host_channels_write_cmds_1_bits_data; // @[Prototype.scala 17:20]
  wire  target_clock; // @[Prototype.scala 19:11]
  wire  target_reset; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_0_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_1_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_2_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_3_addr; // @[Prototype.scala 19:11]
  wire [63:0] target_channels_read_resps_0; // @[Prototype.scala 19:11]
  wire [63:0] target_channels_read_resps_1; // @[Prototype.scala 19:11]
  wire [63:0] target_channels_read_resps_2; // @[Prototype.scala 19:11]
  wire [63:0] target_channels_read_resps_3; // @[Prototype.scala 19:11]
  wire  target_channels_write_cmds_0_en; // @[Prototype.scala 19:11]
  wire  target_channels_write_cmds_0_mask; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_write_cmds_0_addr; // @[Prototype.scala 19:11]
  wire [63:0] target_channels_write_cmds_0_data; // @[Prototype.scala 19:11]
  wire  target_channels_write_cmds_1_en; // @[Prototype.scala 19:11]
  wire  target_channels_write_cmds_1_mask; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_write_cmds_1_addr; // @[Prototype.scala 19:11]
  wire [63:0] target_channels_write_cmds_1_data; // @[Prototype.scala 19:11]
  AsyncMemChiselModel host ( // @[Prototype.scala 17:20]
    .clock(host_clock),
    .reset(host_reset),
    .channels_reset_ready(host_channels_reset_ready),
    .channels_reset_valid(host_channels_reset_valid),
    .channels_reset_bits(host_channels_reset_bits),
    .channels_read_cmds_0_ready(host_channels_read_cmds_0_ready),
    .channels_read_cmds_0_valid(host_channels_read_cmds_0_valid),
    .channels_read_cmds_0_bits_addr(host_channels_read_cmds_0_bits_addr),
    .channels_read_cmds_1_ready(host_channels_read_cmds_1_ready),
    .channels_read_cmds_1_valid(host_channels_read_cmds_1_valid),
    .channels_read_cmds_1_bits_addr(host_channels_read_cmds_1_bits_addr),
    .channels_read_cmds_2_ready(host_channels_read_cmds_2_ready),
    .channels_read_cmds_2_valid(host_channels_read_cmds_2_valid),
    .channels_read_cmds_2_bits_addr(host_channels_read_cmds_2_bits_addr),
    .channels_read_cmds_3_ready(host_channels_read_cmds_3_ready),
    .channels_read_cmds_3_valid(host_channels_read_cmds_3_valid),
    .channels_read_cmds_3_bits_addr(host_channels_read_cmds_3_bits_addr),
    .channels_read_resps_0_ready(host_channels_read_resps_0_ready),
    .channels_read_resps_0_valid(host_channels_read_resps_0_valid),
    .channels_read_resps_0_bits(host_channels_read_resps_0_bits),
    .channels_read_resps_1_ready(host_channels_read_resps_1_ready),
    .channels_read_resps_1_valid(host_channels_read_resps_1_valid),
    .channels_read_resps_1_bits(host_channels_read_resps_1_bits),
    .channels_read_resps_2_ready(host_channels_read_resps_2_ready),
    .channels_read_resps_2_valid(host_channels_read_resps_2_valid),
    .channels_read_resps_2_bits(host_channels_read_resps_2_bits),
    .channels_read_resps_3_ready(host_channels_read_resps_3_ready),
    .channels_read_resps_3_valid(host_channels_read_resps_3_valid),
    .channels_read_resps_3_bits(host_channels_read_resps_3_bits),
    .channels_write_cmds_0_ready(host_channels_write_cmds_0_ready),
    .channels_write_cmds_0_valid(host_channels_write_cmds_0_valid),
    .channels_write_cmds_0_bits_en(host_channels_write_cmds_0_bits_en),
    .channels_write_cmds_0_bits_mask(host_channels_write_cmds_0_bits_mask),
    .channels_write_cmds_0_bits_addr(host_channels_write_cmds_0_bits_addr),
    .channels_write_cmds_0_bits_data(host_channels_write_cmds_0_bits_data),
    .channels_write_cmds_1_ready(host_channels_write_cmds_1_ready),
    .channels_write_cmds_1_valid(host_channels_write_cmds_1_valid),
    .channels_write_cmds_1_bits_en(host_channels_write_cmds_1_bits_en),
    .channels_write_cmds_1_bits_mask(host_channels_write_cmds_1_bits_mask),
    .channels_write_cmds_1_bits_addr(host_channels_write_cmds_1_bits_addr),
    .channels_write_cmds_1_bits_data(host_channels_write_cmds_1_bits_data)
  );
  AsyncMemChiselRTL target ( // @[Prototype.scala 19:11]
    .clock(target_clock),
    .reset(target_reset),
    .channels_read_cmds_0_addr(target_channels_read_cmds_0_addr),
    .channels_read_cmds_1_addr(target_channels_read_cmds_1_addr),
    .channels_read_cmds_2_addr(target_channels_read_cmds_2_addr),
    .channels_read_cmds_3_addr(target_channels_read_cmds_3_addr),
    .channels_read_resps_0(target_channels_read_resps_0),
    .channels_read_resps_1(target_channels_read_resps_1),
    .channels_read_resps_2(target_channels_read_resps_2),
    .channels_read_resps_3(target_channels_read_resps_3),
    .channels_write_cmds_0_en(target_channels_write_cmds_0_en),
    .channels_write_cmds_0_mask(target_channels_write_cmds_0_mask),
    .channels_write_cmds_0_addr(target_channels_write_cmds_0_addr),
    .channels_write_cmds_0_data(target_channels_write_cmds_0_data),
    .channels_write_cmds_1_en(target_channels_write_cmds_1_en),
    .channels_write_cmds_1_mask(target_channels_write_cmds_1_mask),
    .channels_write_cmds_1_addr(target_channels_write_cmds_1_addr),
    .channels_write_cmds_1_data(target_channels_write_cmds_1_data)
  );
  assign io_model_reset_ready = host_channels_reset_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_0_ready = host_channels_read_cmds_0_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_1_ready = host_channels_read_cmds_1_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_2_ready = host_channels_read_cmds_2_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_3_ready = host_channels_read_cmds_3_ready; // @[Prototype.scala 21:17]
  assign io_model_read_resps_0_valid = host_channels_read_resps_0_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_0_bits = host_channels_read_resps_0_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_1_valid = host_channels_read_resps_1_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_1_bits = host_channels_read_resps_1_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_2_valid = host_channels_read_resps_2_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_2_bits = host_channels_read_resps_2_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_3_valid = host_channels_read_resps_3_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_3_bits = host_channels_read_resps_3_bits; // @[Prototype.scala 21:17]
  assign io_model_write_cmds_0_ready = host_channels_write_cmds_0_ready; // @[Prototype.scala 21:17]
  assign io_model_write_cmds_1_ready = host_channels_write_cmds_1_ready; // @[Prototype.scala 21:17]
  assign io_reference_read_resps_0 = target_channels_read_resps_0; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_1 = target_channels_read_resps_1; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_2 = target_channels_read_resps_2; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_3 = target_channels_read_resps_3; // @[Prototype.scala 22:19]
  assign host_clock = clock;
  assign host_reset = reset;
  assign host_channels_reset_valid = io_model_reset_valid; // @[Prototype.scala 21:17]
  assign host_channels_reset_bits = io_model_reset_bits; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_0_valid = io_model_read_cmds_0_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_0_bits_addr = io_model_read_cmds_0_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_1_valid = io_model_read_cmds_1_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_1_bits_addr = io_model_read_cmds_1_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_2_valid = io_model_read_cmds_2_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_2_bits_addr = io_model_read_cmds_2_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_3_valid = io_model_read_cmds_3_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_3_bits_addr = io_model_read_cmds_3_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_0_ready = io_model_read_resps_0_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_1_ready = io_model_read_resps_1_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_2_ready = io_model_read_resps_2_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_3_ready = io_model_read_resps_3_ready; // @[Prototype.scala 21:17]
  assign host_channels_write_cmds_0_valid = io_model_write_cmds_0_valid; // @[Prototype.scala 21:17]
  assign host_channels_write_cmds_0_bits_en = io_model_write_cmds_0_bits_en; // @[Prototype.scala 21:17]
  assign host_channels_write_cmds_0_bits_mask = io_model_write_cmds_0_bits_mask; // @[Prototype.scala 21:17]
  assign host_channels_write_cmds_0_bits_addr = io_model_write_cmds_0_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_write_cmds_0_bits_data = io_model_write_cmds_0_bits_data; // @[Prototype.scala 21:17]
  assign host_channels_write_cmds_1_valid = io_model_write_cmds_1_valid; // @[Prototype.scala 21:17]
  assign host_channels_write_cmds_1_bits_en = io_model_write_cmds_1_bits_en; // @[Prototype.scala 21:17]
  assign host_channels_write_cmds_1_bits_mask = io_model_write_cmds_1_bits_mask; // @[Prototype.scala 21:17]
  assign host_channels_write_cmds_1_bits_addr = io_model_write_cmds_1_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_write_cmds_1_bits_data = io_model_write_cmds_1_bits_data; // @[Prototype.scala 21:17]
  assign target_clock = io_targetClock;
  assign target_reset = io_targetReset;
  assign target_channels_read_cmds_0_addr = io_reference_read_cmds_0_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_1_addr = io_reference_read_cmds_1_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_2_addr = io_reference_read_cmds_2_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_3_addr = io_reference_read_cmds_3_addr; // @[Prototype.scala 22:19]
  assign target_channels_write_cmds_0_en = io_reference_write_cmds_0_en; // @[Prototype.scala 22:19]
  assign target_channels_write_cmds_0_mask = io_reference_write_cmds_0_mask; // @[Prototype.scala 22:19]
  assign target_channels_write_cmds_0_addr = io_reference_write_cmds_0_addr; // @[Prototype.scala 22:19]
  assign target_channels_write_cmds_0_data = io_reference_write_cmds_0_data; // @[Prototype.scala 22:19]
  assign target_channels_write_cmds_1_en = io_reference_write_cmds_1_en; // @[Prototype.scala 22:19]
  assign target_channels_write_cmds_1_mask = io_reference_write_cmds_1_mask; // @[Prototype.scala 22:19]
  assign target_channels_write_cmds_1_addr = io_reference_write_cmds_1_addr; // @[Prototype.scala 22:19]
  assign target_channels_write_cmds_1_data = io_reference_write_cmds_1_data; // @[Prototype.scala 22:19]
endmodule
