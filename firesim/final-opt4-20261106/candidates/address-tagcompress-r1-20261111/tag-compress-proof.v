module TagCompressProof(
  input [7:0] slot_idx,
  input valid,
  input [31:0] stored_seq,
  input reset,
  input commit,
  input [7:0] write_idx,
  input [31:0] write_seq,
  input [31:0] query_seq,
  output io_invariant_step_ok,
  output io_read_equivalent,
  output io_read_mutant_equivalent
);
  wire old_invariant = !valid || stored_seq[7:0] == slot_idx;
  wire write_invariant = !commit || write_seq[7:0] == write_idx;
  wire write_here = commit && write_idx == slot_idx;
  wire next_valid = reset ? 1'b0 : (write_here || valid);
  wire [31:0] next_seq = reset ? 32'b0 : (write_here ? write_seq : stored_seq);
  assign io_invariant_step_ok = !old_invariant || !write_invariant ||
    !next_valid || next_seq[7:0] == slot_idx;

  wire read_invariant = !valid || stored_seq[7:0] == query_seq[7:0];
  wire old_mismatch = valid && stored_seq != query_seq;
  wire compressed_mismatch = valid &&
    {stored_seq[31:8], query_seq[7:0]} != query_seq;
  wire mutant_mismatch = valid &&
    {stored_seq[31:8], (query_seq[7:0] ^ 8'h01)} != query_seq;
  assign io_read_equivalent = !read_invariant || old_mismatch == compressed_mismatch;
  assign io_read_mutant_equivalent = !read_invariant || old_mismatch == mutant_mismatch;
endmodule
