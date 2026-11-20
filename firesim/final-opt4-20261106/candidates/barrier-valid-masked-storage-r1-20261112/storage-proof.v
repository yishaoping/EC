module BarrierStorageProof(
 input valid, initialized, resolve, event_here, reset,
 input [31:0] stored_seq, event_seq,
 input [63:0] stored_count, stored_request, current_cycle,
 output equivalent, output invalid_zero_invariant, output mutant_equivalent);
 wire [31:0] old_seq = initialized ? stored_seq : 32'b0;
 wire [63:0] old_count = valid ? stored_count : 64'b0;
 wire [63:0] old_request = valid ? stored_request : 64'b0;
 wire fresh = !valid || resolve;
 wire next_valid = !reset && (event_here || (valid && !resolve));
 wire next_initialized = !reset && (initialized || event_here);
 wire [31:0] write_seq = fresh ? event_seq : old_seq;
 wire [63:0] write_count = fresh ? 64'd1 : old_count + 64'd1;
 wire [63:0] write_request = fresh ? current_cycle : old_request + current_cycle;
 wire [31:0] physical_seq = event_here ? write_seq : stored_seq;
 wire [63:0] physical_count = event_here ? write_count : stored_count;
 wire [63:0] physical_request = event_here ? write_request : stored_request;
 wire [31:0] candidate_seq = next_initialized ? physical_seq : 32'b0;
 wire [63:0] candidate_count = next_valid ? physical_count : 64'b0;
 wire [63:0] candidate_request = next_valid ? physical_request : 64'b0;
 wire [31:0] reference_seq = reset ? 32'b0 :
     (event_here && fresh ? event_seq : old_seq);
 wire [63:0] reference_count = reset ? 64'b0 :
     (event_here ? write_count : (resolve ? 64'b0 : old_count));
 wire [63:0] reference_request = reset ? 64'b0 :
     (event_here ? write_request : (resolve ? 64'b0 : old_request));
 assign equivalent = candidate_seq == reference_seq &&
     candidate_count == reference_count && candidate_request == reference_request;
 assign invalid_zero_invariant = next_valid || (reference_count == 0 && reference_request == 0);
 // The tempting valid-only sequence mask is incorrect after resolution.
 wire [31:0] mutant_seq = next_valid ? physical_seq : 32'b0;
 assign mutant_equivalent = mutant_seq == reference_seq;
endmodule
