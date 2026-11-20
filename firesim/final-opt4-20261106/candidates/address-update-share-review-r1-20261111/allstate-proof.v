// Unconditional arithmetic model of exact 9ae9a7fc -> 00847dc2 write block.
// Independent global reset clears validity while retaining payload.
module AllStateUpdateProof(
 input [63:0] value, delta,
 input valid, current, event_commit, retire, reset_stats, global_reset,
 output equivalent, global_reset_equivalent, allocation_equivalent, mutant_equivalent);
 wire effective_valid = !global_reset && valid;
 wire [64:0] wide_sum = {1'b0,value}+{1'b0,delta};
 wire [64:0] old_alloc_sum = {1'b0,(effective_valid?value:64'd0)}+{1'b0,delta};
 wire [63:0] old_update = current?old_alloc_sum[63:0]:((|delta)?wide_sum[63:0]:value);
 wire [63:0] new_data = current && !effective_valid?delta:wide_sum[63:0];
 wire [63:0] new_update = current || (|delta)?new_data:value;
 wire clear = reset_stats || (!event_commit && retire);
 wire [63:0] old_next = clear?64'd0:(event_commit?old_update:value);
 wire [63:0] new_next = clear?64'd0:(event_commit?new_update:value);
 wire [63:0] mutant_update = current || (|delta)?wide_sum[63:0]:value;
 wire [63:0] mutant_next = clear?64'd0:(event_commit?mutant_update:value);
 assign equivalent = old_next == new_next;
 assign global_reset_equivalent = !global_reset || old_next == new_next;
 assign allocation_equivalent = !current || old_update == new_update;
 assign mutant_equivalent = old_next == mutant_next;
endmodule
