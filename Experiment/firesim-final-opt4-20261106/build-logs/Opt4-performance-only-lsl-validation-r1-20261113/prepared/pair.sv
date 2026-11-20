module LSLPair(
  input clock,
  input reset,
  input io_m_ld_valid_0,
  input io_m_ld_valid_1,
  input io_m_st_valid_0,
  input io_m_st_valid_1,
  input [63:0] io_m_ldst_data_0,
  input [63:0] io_m_ldst_data_1,
  input [63:0] io_m_ldst_addr_0,
  input [63:0] io_m_ldst_addr_1,
  input io_m_csr_valid_0,
  input io_m_csr_valid_1,
  input [63:0] io_m_csr_data_0,
  input [63:0] io_m_csr_data_1,
  input io_m_rocc_valid_0,
  input io_m_rocc_valid_1,
  input [63:0] io_m_rocc_data_0,
  input [63:0] io_m_rocc_data_1,
  output io_cdc_ready_mem,
  output io_cdc_ready_csr,
  output io_cdc_ready_rocc,
  output io_req_ready,
  input io_req_valid,
  input [39:0] io_req_addr,
  input [7:0] io_req_tag,
  input [1:0] io_req_cmd,
  input [1:0] io_req_size,
  input io_req_kill,
  input io_req_valid_csr,
  output io_req_ready_csr,
  input io_req_valid_rocc,
  output io_req_ready_rocc,
  output io_resp_valid,
  output [7:0] io_resp_tag,
  output [1:0] io_resp_size,
  output [63:0] io_resp_data,
  output io_resp_has_data,
  output [39:0] io_resp_addr,
  output io_resp_cacheable,
  output io_resp_mismatch,
  output io_resp_replay,
  output io_quiescent,
  output io_near_full,
  output [63:0] io_resp_data_csr,
  output [63:0] io_resp_data_rocc,
  output io_if_empty,
  output io_lsl_highwatermark,
  output io_ingress_overflow,
  output io_st_deq,
  output io_ld_deq,
  output [23:0] mismatch
);
wire c_io_cdc_ready_mem;
wire c_io_cdc_ready_csr;
wire c_io_cdc_ready_rocc;
wire c_io_req_ready;
wire c_io_req_ready_csr;
wire c_io_req_ready_rocc;
wire c_io_resp_valid;
wire [7:0] c_io_resp_tag;
wire [1:0] c_io_resp_size;
wire [63:0] c_io_resp_data;
wire c_io_resp_has_data;
wire [39:0] c_io_resp_addr;
wire c_io_resp_cacheable;
wire c_io_resp_mismatch;
wire c_io_resp_replay;
wire c_io_quiescent;
wire c_io_near_full;
wire [63:0] c_io_resp_data_csr;
wire [63:0] c_io_resp_data_rocc;
wire c_io_if_empty;
wire c_io_lsl_highwatermark;
wire c_io_ingress_overflow;
wire c_io_st_deq;
wire c_io_ld_deq;
Frozen__R_LSL frozen(
.clock(clock),
.reset(reset),
.io_m_ld_valid_0(io_m_ld_valid_0),
.io_m_ld_valid_1(io_m_ld_valid_1),
.io_m_st_valid_0(io_m_st_valid_0),
.io_m_st_valid_1(io_m_st_valid_1),
.io_m_ldst_data_0(io_m_ldst_data_0),
.io_m_ldst_data_1(io_m_ldst_data_1),
.io_m_ldst_addr_0(io_m_ldst_addr_0),
.io_m_ldst_addr_1(io_m_ldst_addr_1),
.io_m_csr_valid_0(io_m_csr_valid_0),
.io_m_csr_valid_1(io_m_csr_valid_1),
.io_m_csr_data_0(io_m_csr_data_0),
.io_m_csr_data_1(io_m_csr_data_1),
.io_m_rocc_valid_0(io_m_rocc_valid_0),
.io_m_rocc_valid_1(io_m_rocc_valid_1),
.io_m_rocc_data_0(io_m_rocc_data_0),
.io_m_rocc_data_1(io_m_rocc_data_1),
.io_cdc_ready_mem(io_cdc_ready_mem),
.io_cdc_ready_csr(io_cdc_ready_csr),
.io_cdc_ready_rocc(io_cdc_ready_rocc),
.io_req_ready(io_req_ready),
.io_req_valid(io_req_valid),
.io_req_addr(io_req_addr),
.io_req_tag(io_req_tag),
.io_req_cmd(io_req_cmd),
.io_req_size(io_req_size),
.io_req_kill(io_req_kill),
.io_req_valid_csr(io_req_valid_csr),
.io_req_ready_csr(io_req_ready_csr),
.io_req_valid_rocc(io_req_valid_rocc),
.io_req_ready_rocc(io_req_ready_rocc),
.io_resp_valid(io_resp_valid),
.io_resp_tag(io_resp_tag),
.io_resp_size(io_resp_size),
.io_resp_data(io_resp_data),
.io_resp_has_data(io_resp_has_data),
.io_resp_addr(io_resp_addr),
.io_resp_cacheable(io_resp_cacheable),
.io_resp_mismatch(io_resp_mismatch),
.io_resp_replay(io_resp_replay),
.io_quiescent(io_quiescent),
.io_near_full(io_near_full),
.io_resp_data_csr(io_resp_data_csr),
.io_resp_data_rocc(io_resp_data_rocc),
.io_if_empty(io_if_empty),
.io_lsl_highwatermark(io_lsl_highwatermark),
.io_ingress_overflow(io_ingress_overflow),
.io_st_deq(io_st_deq),
.io_ld_deq(io_ld_deq)
);
Performance__R_LSL performance(
.clock(clock),
.reset(reset),
.io_m_ld_valid_0(io_m_ld_valid_0),
.io_m_ld_valid_1(io_m_ld_valid_1),
.io_m_st_valid_0(io_m_st_valid_0),
.io_m_st_valid_1(io_m_st_valid_1),
.io_m_ldst_data_0(io_m_ldst_data_0),
.io_m_ldst_data_1(io_m_ldst_data_1),
.io_m_ldst_addr_0(io_m_ldst_addr_0),
.io_m_ldst_addr_1(io_m_ldst_addr_1),
.io_m_csr_valid_0(io_m_csr_valid_0),
.io_m_csr_valid_1(io_m_csr_valid_1),
.io_m_csr_data_0(io_m_csr_data_0),
.io_m_csr_data_1(io_m_csr_data_1),
.io_m_rocc_valid_0(io_m_rocc_valid_0),
.io_m_rocc_valid_1(io_m_rocc_valid_1),
.io_m_rocc_data_0(io_m_rocc_data_0),
.io_m_rocc_data_1(io_m_rocc_data_1),
.io_cdc_ready_mem(c_io_cdc_ready_mem),
.io_cdc_ready_csr(c_io_cdc_ready_csr),
.io_cdc_ready_rocc(c_io_cdc_ready_rocc),
.io_req_ready(c_io_req_ready),
.io_req_valid(io_req_valid),
.io_req_addr(io_req_addr),
.io_req_tag(io_req_tag),
.io_req_cmd(io_req_cmd),
.io_req_size(io_req_size),
.io_req_kill(io_req_kill),
.io_req_valid_csr(io_req_valid_csr),
.io_req_ready_csr(c_io_req_ready_csr),
.io_req_valid_rocc(io_req_valid_rocc),
.io_req_ready_rocc(c_io_req_ready_rocc),
.io_resp_valid(c_io_resp_valid),
.io_resp_tag(c_io_resp_tag),
.io_resp_size(c_io_resp_size),
.io_resp_data(c_io_resp_data),
.io_resp_has_data(c_io_resp_has_data),
.io_resp_addr(c_io_resp_addr),
.io_resp_cacheable(c_io_resp_cacheable),
.io_resp_mismatch(c_io_resp_mismatch),
.io_resp_replay(c_io_resp_replay),
.io_quiescent(c_io_quiescent),
.io_near_full(c_io_near_full),
.io_resp_data_csr(c_io_resp_data_csr),
.io_resp_data_rocc(c_io_resp_data_rocc),
.io_if_empty(c_io_if_empty),
.io_lsl_highwatermark(c_io_lsl_highwatermark),
.io_ingress_overflow(c_io_ingress_overflow),
.io_st_deq(c_io_st_deq),
.io_ld_deq(c_io_ld_deq)
);
assign mismatch[0] = io_cdc_ready_mem != c_io_cdc_ready_mem;
assign mismatch[1] = io_cdc_ready_csr != c_io_cdc_ready_csr;
assign mismatch[2] = io_cdc_ready_rocc != c_io_cdc_ready_rocc;
assign mismatch[3] = io_req_ready != c_io_req_ready;
assign mismatch[4] = io_req_ready_csr != c_io_req_ready_csr;
assign mismatch[5] = io_req_ready_rocc != c_io_req_ready_rocc;
assign mismatch[6] = io_resp_valid != c_io_resp_valid;
assign mismatch[7] = io_resp_tag != c_io_resp_tag;
assign mismatch[8] = io_resp_size != c_io_resp_size;
assign mismatch[9] = io_resp_data != c_io_resp_data;
assign mismatch[10] = io_resp_has_data != c_io_resp_has_data;
assign mismatch[11] = io_resp_addr != c_io_resp_addr;
assign mismatch[12] = io_resp_cacheable != c_io_resp_cacheable;
assign mismatch[13] = io_resp_mismatch != c_io_resp_mismatch;
assign mismatch[14] = io_resp_replay != c_io_resp_replay;
assign mismatch[15] = io_quiescent != c_io_quiescent;
assign mismatch[16] = io_near_full != c_io_near_full;
assign mismatch[17] = io_resp_data_csr != c_io_resp_data_csr;
assign mismatch[18] = io_resp_data_rocc != c_io_resp_data_rocc;
assign mismatch[19] = io_if_empty != c_io_if_empty;
assign mismatch[20] = io_lsl_highwatermark != c_io_lsl_highwatermark;
assign mismatch[21] = io_ingress_overflow != c_io_ingress_overflow;
assign mismatch[22] = io_st_deq != c_io_st_deq;
assign mismatch[23] = io_ld_deq != c_io_ld_deq;
endmodule
